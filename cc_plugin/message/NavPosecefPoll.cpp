// Generated by commsdsl2comms v3.3.2

#include "NavPosecefPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavPosecefPoll.h"
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

class NavPosecefPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavPosecefPoll<ublox::cc_plugin::Message>,
        NavPosecefPollImpl
    >
{
public:
    NavPosecefPollImpl() = default;
    NavPosecefPollImpl(const NavPosecefPollImpl&) = delete;
    NavPosecefPollImpl(NavPosecefPollImpl&&) = delete;
    virtual ~NavPosecefPollImpl() = default;
    NavPosecefPollImpl& operator=(const NavPosecefPollImpl&) = default;
    NavPosecefPollImpl& operator=(NavPosecefPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavPosecefPoll::NavPosecefPoll() : m_pImpl(new NavPosecefPollImpl) {}
NavPosecefPoll::~NavPosecefPoll() = default;

NavPosecefPoll& NavPosecefPoll::operator=(const NavPosecefPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavPosecefPoll& NavPosecefPoll::operator=(NavPosecefPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavPosecefPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavPosecefPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavPosecefPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavPosecefPoll::resetImpl()
{
    m_pImpl->reset();
}

bool NavPosecefPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavPosecefPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavPosecefPoll::MsgIdParamType NavPosecefPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavPosecefPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavPosecefPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavPosecefPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavPosecefPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavPosecefPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


