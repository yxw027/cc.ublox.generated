#include "NavVelecefPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavVelecefPoll.h"
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

class NavVelecefPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavVelecefPoll<ublox::cc_plugin::Message>,
        NavVelecefPollImpl
    >
{
public:
    NavVelecefPollImpl() = default;
    NavVelecefPollImpl(const NavVelecefPollImpl&) = delete;
    NavVelecefPollImpl(NavVelecefPollImpl&&) = delete;
    virtual ~NavVelecefPollImpl() = default;
    NavVelecefPollImpl& operator=(const NavVelecefPollImpl&) = default;
    NavVelecefPollImpl& operator=(NavVelecefPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavVelecefPoll::NavVelecefPoll() : m_pImpl(new NavVelecefPollImpl) {}
NavVelecefPoll::~NavVelecefPoll() = default;

NavVelecefPoll& NavVelecefPoll::operator=(const NavVelecefPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavVelecefPoll& NavVelecefPoll::operator=(NavVelecefPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavVelecefPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavVelecefPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavVelecefPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavVelecefPoll::resetImpl()
{
    m_pImpl->reset();
}

bool NavVelecefPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavVelecefPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavVelecefPoll::MsgIdParamType NavVelecefPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavVelecefPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavVelecefPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavVelecefPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavVelecefPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavVelecefPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

