#include "NavTimeutcPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavTimeutcPoll.h"
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

class NavTimeutcPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavTimeutcPoll<ublox::cc_plugin::Message>,
        NavTimeutcPollImpl
    >
{
public:
    NavTimeutcPollImpl() = default;
    NavTimeutcPollImpl(const NavTimeutcPollImpl&) = delete;
    NavTimeutcPollImpl(NavTimeutcPollImpl&&) = delete;
    virtual ~NavTimeutcPollImpl() = default;
    NavTimeutcPollImpl& operator=(const NavTimeutcPollImpl&) = default;
    NavTimeutcPollImpl& operator=(NavTimeutcPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavTimeutcPoll::NavTimeutcPoll() : m_pImpl(new NavTimeutcPollImpl) {}
NavTimeutcPoll::~NavTimeutcPoll() = default;

NavTimeutcPoll& NavTimeutcPoll::operator=(const NavTimeutcPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavTimeutcPoll& NavTimeutcPoll::operator=(NavTimeutcPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavTimeutcPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavTimeutcPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavTimeutcPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavTimeutcPoll::resetImpl()
{
    m_pImpl->reset();
}

bool NavTimeutcPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavTimeutcPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavTimeutcPoll::MsgIdParamType NavTimeutcPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavTimeutcPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavTimeutcPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavTimeutcPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavTimeutcPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavTimeutcPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

