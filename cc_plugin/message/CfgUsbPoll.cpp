#include "CfgUsbPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgUsbPoll.h"
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

class CfgUsbPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgUsbPoll<ublox::cc_plugin::Message>,
        CfgUsbPollImpl
    >
{
public:
    CfgUsbPollImpl() = default;
    CfgUsbPollImpl(const CfgUsbPollImpl&) = delete;
    CfgUsbPollImpl(CfgUsbPollImpl&&) = delete;
    virtual ~CfgUsbPollImpl() = default;
    CfgUsbPollImpl& operator=(const CfgUsbPollImpl&) = default;
    CfgUsbPollImpl& operator=(CfgUsbPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgUsbPoll::CfgUsbPoll() : m_pImpl(new CfgUsbPollImpl) {}
CfgUsbPoll::~CfgUsbPoll() = default;

CfgUsbPoll& CfgUsbPoll::operator=(const CfgUsbPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgUsbPoll& CfgUsbPoll::operator=(CfgUsbPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgUsbPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgUsbPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgUsbPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgUsbPoll::resetImpl()
{
    m_pImpl->reset();
}

bool CfgUsbPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgUsbPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgUsbPoll::MsgIdParamType CfgUsbPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgUsbPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgUsbPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgUsbPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgUsbPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgUsbPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

