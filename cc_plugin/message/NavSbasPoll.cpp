// Generated by commsdsl2comms v3.3.1

#include "NavSbasPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavSbasPoll.h"
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

class NavSbasPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavSbasPoll<ublox::cc_plugin::Message>,
        NavSbasPollImpl
    >
{
public:
    NavSbasPollImpl() = default;
    NavSbasPollImpl(const NavSbasPollImpl&) = delete;
    NavSbasPollImpl(NavSbasPollImpl&&) = delete;
    virtual ~NavSbasPollImpl() = default;
    NavSbasPollImpl& operator=(const NavSbasPollImpl&) = default;
    NavSbasPollImpl& operator=(NavSbasPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavSbasPoll::NavSbasPoll() : m_pImpl(new NavSbasPollImpl) {}
NavSbasPoll::~NavSbasPoll() = default;

NavSbasPoll& NavSbasPoll::operator=(const NavSbasPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavSbasPoll& NavSbasPoll::operator=(NavSbasPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavSbasPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavSbasPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavSbasPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavSbasPoll::resetImpl()
{
    m_pImpl->reset();
}

bool NavSbasPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavSbasPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavSbasPoll::MsgIdParamType NavSbasPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavSbasPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavSbasPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavSbasPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavSbasPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavSbasPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


