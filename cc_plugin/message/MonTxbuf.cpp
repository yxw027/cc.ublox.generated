#include "MonTxbuf.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MonTxbuf.h"
#include "cc_plugin/field/Res1.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

struct PendingMembers
{
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::MonTxbufFields<>::PendingMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

static QVariantMap createProps_pending()
{
    using Field = ublox::message::MonTxbufFields<>::Pending;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(PendingMembers::createProps_element())
            .serialisedHidden()
            .asMap();
    
}

struct UsageMembers
{
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::MonTxbufFields<>::UsageMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

static QVariantMap createProps_usage()
{
    using Field = ublox::message::MonTxbufFields<>::Usage;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(UsageMembers::createProps_element())
            .serialisedHidden()
            .asMap();
    
}

struct PeakUsageMembers
{
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::MonTxbufFields<>::PeakUsageMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

static QVariantMap createProps_peakUsage()
{
    using Field = ublox::message::MonTxbufFields<>::PeakUsage;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(PeakUsageMembers::createProps_element())
            .serialisedHidden()
            .asMap();
    
}

static QVariantMap createProps_tUsage()
{
    using Field = ublox::message::MonTxbufFields<>::TUsage;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_tPeakusage()
{
    using Field = ublox::message::MonTxbufFields<>::TPeakusage;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

struct ErrorsMembers
{
    static QVariantMap createProps_limit()
    {
        using Field = ublox::message::MonTxbufFields<>::ErrorsMembers::Limit;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .asMap();
        
    }
    
    static QVariantMap createProps_bits()
    {
        using Field = ublox::message::MonTxbufFields<>::ErrorsMembers::Bits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "mem")
                .add(1U, "alloc")
                .asMap();
        
    }
    
};

static QVariantMap createProps_errors()
{
    using Field = ublox::message::MonTxbufFields<>::Errors;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ErrorsMembers::createProps_limit())
            .add(ErrorsMembers::createProps_bits())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MonTxbufFields<>::Reserved1;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_pending());
    props.append(createProps_usage());
    props.append(createProps_peakUsage());
    props.append(createProps_tUsage());
    props.append(createProps_tPeakusage());
    props.append(createProps_errors());
    props.append(createProps_reserved1());
    return props;
}

} // namespace

class MonTxbufImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MonTxbuf<ublox::cc_plugin::Message>,
        MonTxbufImpl
    >
{
public:
    MonTxbufImpl() = default;
    MonTxbufImpl(const MonTxbufImpl&) = delete;
    MonTxbufImpl(MonTxbufImpl&&) = delete;
    virtual ~MonTxbufImpl() = default;
    MonTxbufImpl& operator=(const MonTxbufImpl&) = default;
    MonTxbufImpl& operator=(MonTxbufImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MonTxbuf::MonTxbuf() : m_pImpl(new MonTxbufImpl) {}
MonTxbuf::~MonTxbuf() = default;

MonTxbuf& MonTxbuf::operator=(const MonTxbuf& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MonTxbuf& MonTxbuf::operator=(MonTxbuf&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MonTxbuf::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MonTxbuf::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MonTxbuf::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MonTxbuf::resetImpl()
{
    m_pImpl->reset();
}

bool MonTxbuf::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MonTxbuf*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MonTxbuf::MsgIdParamType MonTxbuf::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MonTxbuf::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MonTxbuf::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MonTxbuf::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MonTxbuf::lengthImpl() const
{
    return m_pImpl->length();
}

bool MonTxbuf::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

