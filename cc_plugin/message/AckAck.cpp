#include "AckAck.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/AckAck.h"
#include "cc_plugin/field/MsgId.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_msgId()
{
    using Field = ublox::message::AckAckFields<>::MsgId;
    return cc_plugin::field::createProps_msgId(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_msgId());
    return props;
}

} // namespace

class AckAckImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::AckAck<ublox::cc_plugin::Message>,
        AckAckImpl
    >
{
public:
    AckAckImpl() = default;
    AckAckImpl(const AckAckImpl&) = delete;
    AckAckImpl(AckAckImpl&&) = delete;
    virtual ~AckAckImpl() = default;
    AckAckImpl& operator=(const AckAckImpl&) = default;
    AckAckImpl& operator=(AckAckImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

AckAck::AckAck() : m_pImpl(new AckAckImpl) {}
AckAck::~AckAck() = default;

AckAck& AckAck::operator=(const AckAck& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

AckAck& AckAck::operator=(AckAck&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* AckAck::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& AckAck::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void AckAck::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void AckAck::resetImpl()
{
    m_pImpl->reset();
}

bool AckAck::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const AckAck*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

AckAck::MsgIdParamType AckAck::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus AckAck::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus AckAck::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool AckAck::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t AckAck::lengthImpl() const
{
    return m_pImpl->length();
}

bool AckAck::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

