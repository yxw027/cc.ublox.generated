#include "RxmRlmShort.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/RxmRlmShort.h"
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

static QVariantMap createProps_version()
{
    using Field = ublox::message::RxmRlmShortFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_type()
{
    using Field = ublox::message::RxmRlmShortFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_svid()
{
    using Field = ublox::message::RxmRlmShortFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::RxmRlmShortFields<>::Reserved1;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

static QVariantMap createProps_beacon()
{
    using Field = ublox::message::RxmRlmShortFields<>::Beacon;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_message()
{
    using Field = ublox::message::RxmRlmShortFields<>::Message;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_params()
{
    using Field = ublox::message::RxmRlmShortFields<>::Params;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::RxmRlmShortFields<>::Reserved2;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_type());
    props.append(createProps_svid());
    props.append(createProps_reserved1());
    props.append(createProps_beacon());
    props.append(createProps_message());
    props.append(createProps_params());
    props.append(createProps_reserved2());
    return props;
}

} // namespace

class RxmRlmShortImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::RxmRlmShort<ublox::cc_plugin::Message>,
        RxmRlmShortImpl
    >
{
public:
    RxmRlmShortImpl() = default;
    RxmRlmShortImpl(const RxmRlmShortImpl&) = delete;
    RxmRlmShortImpl(RxmRlmShortImpl&&) = delete;
    virtual ~RxmRlmShortImpl() = default;
    RxmRlmShortImpl& operator=(const RxmRlmShortImpl&) = default;
    RxmRlmShortImpl& operator=(RxmRlmShortImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

RxmRlmShort::RxmRlmShort() : m_pImpl(new RxmRlmShortImpl) {}
RxmRlmShort::~RxmRlmShort() = default;

RxmRlmShort& RxmRlmShort::operator=(const RxmRlmShort& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

RxmRlmShort& RxmRlmShort::operator=(RxmRlmShort&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* RxmRlmShort::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& RxmRlmShort::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void RxmRlmShort::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void RxmRlmShort::resetImpl()
{
    m_pImpl->reset();
}

bool RxmRlmShort::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const RxmRlmShort*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

RxmRlmShort::MsgIdParamType RxmRlmShort::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus RxmRlmShort::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus RxmRlmShort::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool RxmRlmShort::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t RxmRlmShort::lengthImpl() const
{
    return m_pImpl->length();
}

bool RxmRlmShort::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

