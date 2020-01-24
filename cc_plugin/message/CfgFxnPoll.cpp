// Generated by commsdsl2comms v3.3.1

#include "CfgFxnPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgFxnPoll.h"
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

class CfgFxnPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgFxnPoll<ublox::cc_plugin::Message>,
        CfgFxnPollImpl
    >
{
public:
    CfgFxnPollImpl() = default;
    CfgFxnPollImpl(const CfgFxnPollImpl&) = delete;
    CfgFxnPollImpl(CfgFxnPollImpl&&) = delete;
    virtual ~CfgFxnPollImpl() = default;
    CfgFxnPollImpl& operator=(const CfgFxnPollImpl&) = default;
    CfgFxnPollImpl& operator=(CfgFxnPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgFxnPoll::CfgFxnPoll() : m_pImpl(new CfgFxnPollImpl) {}
CfgFxnPoll::~CfgFxnPoll() = default;

CfgFxnPoll& CfgFxnPoll::operator=(const CfgFxnPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgFxnPoll& CfgFxnPoll::operator=(CfgFxnPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgFxnPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgFxnPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgFxnPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgFxnPoll::resetImpl()
{
    m_pImpl->reset();
}

bool CfgFxnPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgFxnPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgFxnPoll::MsgIdParamType CfgFxnPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgFxnPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgFxnPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgFxnPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgFxnPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgFxnPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


