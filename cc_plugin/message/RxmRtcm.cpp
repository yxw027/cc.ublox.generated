#include "RxmRtcm.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/RxmRtcm.h"
#include "cc_plugin/field/Res2.h"

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
    using Field = ublox::message::RxmRtcmFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_flags()
{
    using Field = ublox::message::RxmRtcmFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "crcFailed")
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::RxmRtcmFields<>::Reserved1;
    return cc_plugin::field::createProps_res2(Field::name());
    
}

static QVariantMap createProps_refStation()
{
    using Field = ublox::message::RxmRtcmFields<>::RefStation;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_msgType()
{
    using Field = ublox::message::RxmRtcmFields<>::MsgType;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_flags());
    props.append(createProps_reserved1());
    props.append(createProps_refStation());
    props.append(createProps_msgType());
    return props;
}

} // namespace

class RxmRtcmImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::RxmRtcm<ublox::cc_plugin::Message>,
        RxmRtcmImpl
    >
{
public:
    RxmRtcmImpl() = default;
    RxmRtcmImpl(const RxmRtcmImpl&) = delete;
    RxmRtcmImpl(RxmRtcmImpl&&) = delete;
    virtual ~RxmRtcmImpl() = default;
    RxmRtcmImpl& operator=(const RxmRtcmImpl&) = default;
    RxmRtcmImpl& operator=(RxmRtcmImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

RxmRtcm::RxmRtcm() : m_pImpl(new RxmRtcmImpl) {}
RxmRtcm::~RxmRtcm() = default;

RxmRtcm& RxmRtcm::operator=(const RxmRtcm& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

RxmRtcm& RxmRtcm::operator=(RxmRtcm&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* RxmRtcm::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& RxmRtcm::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void RxmRtcm::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void RxmRtcm::resetImpl()
{
    m_pImpl->reset();
}

bool RxmRtcm::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const RxmRtcm*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

RxmRtcm::MsgIdParamType RxmRtcm::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus RxmRtcm::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus RxmRtcm::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool RxmRtcm::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t RxmRtcm::lengthImpl() const
{
    return m_pImpl->length();
}

bool RxmRtcm::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

