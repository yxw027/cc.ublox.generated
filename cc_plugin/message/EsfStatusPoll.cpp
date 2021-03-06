// Generated by commsdsl2comms v3.3.2

#include "EsfStatusPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/EsfStatusPoll.h"
namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

QVariantList createProps()
{
    QVariantList props;
    return props;
}

} // namespace

class EsfStatusPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::EsfStatusPoll<ublox::cc_plugin::Message>,
        EsfStatusPollImpl
    >
{
public:
    EsfStatusPollImpl() = default;
    EsfStatusPollImpl(const EsfStatusPollImpl&) = delete;
    EsfStatusPollImpl(EsfStatusPollImpl&&) = delete;
    virtual ~EsfStatusPollImpl() = default;
    EsfStatusPollImpl& operator=(const EsfStatusPollImpl&) = default;
    EsfStatusPollImpl& operator=(EsfStatusPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

EsfStatusPoll::EsfStatusPoll() : m_pImpl(new EsfStatusPollImpl) {}
EsfStatusPoll::~EsfStatusPoll() = default;

EsfStatusPoll& EsfStatusPoll::operator=(const EsfStatusPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

EsfStatusPoll& EsfStatusPoll::operator=(EsfStatusPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* EsfStatusPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& EsfStatusPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void EsfStatusPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void EsfStatusPoll::resetImpl()
{
    m_pImpl->reset();
}

bool EsfStatusPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const EsfStatusPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

EsfStatusPoll::MsgIdParamType EsfStatusPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus EsfStatusPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus EsfStatusPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool EsfStatusPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t EsfStatusPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool EsfStatusPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


