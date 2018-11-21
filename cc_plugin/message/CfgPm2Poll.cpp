#include "CfgPm2Poll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgPm2Poll.h"
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

class CfgPm2PollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgPm2Poll<ublox::cc_plugin::Message>,
        CfgPm2PollImpl
    >
{
public:
    CfgPm2PollImpl() = default;
    CfgPm2PollImpl(const CfgPm2PollImpl&) = delete;
    CfgPm2PollImpl(CfgPm2PollImpl&&) = delete;
    virtual ~CfgPm2PollImpl() = default;
    CfgPm2PollImpl& operator=(const CfgPm2PollImpl&) = default;
    CfgPm2PollImpl& operator=(CfgPm2PollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgPm2Poll::CfgPm2Poll() : m_pImpl(new CfgPm2PollImpl) {}
CfgPm2Poll::~CfgPm2Poll() = default;

CfgPm2Poll& CfgPm2Poll::operator=(const CfgPm2Poll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgPm2Poll& CfgPm2Poll::operator=(CfgPm2Poll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgPm2Poll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgPm2Poll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgPm2Poll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgPm2Poll::resetImpl()
{
    m_pImpl->reset();
}

bool CfgPm2Poll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgPm2Poll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgPm2Poll::MsgIdParamType CfgPm2Poll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgPm2Poll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgPm2Poll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgPm2Poll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgPm2Poll::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgPm2Poll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

