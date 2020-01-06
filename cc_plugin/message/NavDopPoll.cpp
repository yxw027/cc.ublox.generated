// Generated by commsdsl2comms v3.3.0

#include "NavDopPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavDopPoll.h"
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

class NavDopPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavDopPoll<ublox::cc_plugin::Message>,
        NavDopPollImpl
    >
{
public:
    NavDopPollImpl() = default;
    NavDopPollImpl(const NavDopPollImpl&) = delete;
    NavDopPollImpl(NavDopPollImpl&&) = delete;
    virtual ~NavDopPollImpl() = default;
    NavDopPollImpl& operator=(const NavDopPollImpl&) = default;
    NavDopPollImpl& operator=(NavDopPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavDopPoll::NavDopPoll() : m_pImpl(new NavDopPollImpl) {}
NavDopPoll::~NavDopPoll() = default;

NavDopPoll& NavDopPoll::operator=(const NavDopPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavDopPoll& NavDopPoll::operator=(NavDopPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavDopPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavDopPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavDopPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavDopPoll::resetImpl()
{
    m_pImpl->reset();
}

bool NavDopPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavDopPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavDopPoll::MsgIdParamType NavDopPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavDopPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavDopPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavDopPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavDopPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavDopPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


