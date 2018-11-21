#include "AidEphPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/AidEphPoll.h"
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

class AidEphPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::AidEphPoll<ublox::cc_plugin::Message>,
        AidEphPollImpl
    >
{
public:
    AidEphPollImpl() = default;
    AidEphPollImpl(const AidEphPollImpl&) = delete;
    AidEphPollImpl(AidEphPollImpl&&) = delete;
    virtual ~AidEphPollImpl() = default;
    AidEphPollImpl& operator=(const AidEphPollImpl&) = default;
    AidEphPollImpl& operator=(AidEphPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

AidEphPoll::AidEphPoll() : m_pImpl(new AidEphPollImpl) {}
AidEphPoll::~AidEphPoll() = default;

AidEphPoll& AidEphPoll::operator=(const AidEphPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

AidEphPoll& AidEphPoll::operator=(AidEphPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* AidEphPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& AidEphPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void AidEphPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void AidEphPoll::resetImpl()
{
    m_pImpl->reset();
}

bool AidEphPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const AidEphPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

AidEphPoll::MsgIdParamType AidEphPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus AidEphPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus AidEphPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool AidEphPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t AidEphPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool AidEphPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

