// Generated by commsdsl2comms v3.3.2

#include "MonRxbuf.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MonRxbuf.h"
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
        using Field = ublox::message::MonRxbufFields<>::PendingMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

static QVariantMap createProps_pending()
{
    using Field = ublox::message::MonRxbufFields<>::Pending;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(PendingMembers::createProps_element())
            .serialisedHidden()
            .appendIndexToElementName()
            .asMap();
    
}

struct UsageMembers
{
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::MonRxbufFields<>::UsageMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

static QVariantMap createProps_usage()
{
    using Field = ublox::message::MonRxbufFields<>::Usage;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(UsageMembers::createProps_element())
            .serialisedHidden()
            .appendIndexToElementName()
            .asMap();
    
}

struct PeakUsageMembers
{
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::MonRxbufFields<>::PeakUsageMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

static QVariantMap createProps_peakUsage()
{
    using Field = ublox::message::MonRxbufFields<>::PeakUsage;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(PeakUsageMembers::createProps_element())
            .serialisedHidden()
            .appendIndexToElementName()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_pending());
    props.append(createProps_usage());
    props.append(createProps_peakUsage());
    return props;
}

} // namespace

class MonRxbufImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MonRxbuf<ublox::cc_plugin::Message>,
        MonRxbufImpl
    >
{
public:
    MonRxbufImpl() = default;
    MonRxbufImpl(const MonRxbufImpl&) = delete;
    MonRxbufImpl(MonRxbufImpl&&) = delete;
    virtual ~MonRxbufImpl() = default;
    MonRxbufImpl& operator=(const MonRxbufImpl&) = default;
    MonRxbufImpl& operator=(MonRxbufImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MonRxbuf::MonRxbuf() : m_pImpl(new MonRxbufImpl) {}
MonRxbuf::~MonRxbuf() = default;

MonRxbuf& MonRxbuf::operator=(const MonRxbuf& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MonRxbuf& MonRxbuf::operator=(MonRxbuf&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MonRxbuf::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MonRxbuf::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MonRxbuf::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MonRxbuf::resetImpl()
{
    m_pImpl->reset();
}

bool MonRxbuf::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MonRxbuf*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MonRxbuf::MsgIdParamType MonRxbuf::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MonRxbuf::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MonRxbuf::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MonRxbuf::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MonRxbuf::lengthImpl() const
{
    return m_pImpl->length();
}

bool MonRxbuf::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


