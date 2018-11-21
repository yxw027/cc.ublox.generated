#include "CfgAntPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgAntPoll.h"
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

class CfgAntPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgAntPoll<ublox::cc_plugin::Message>,
        CfgAntPollImpl
    >
{
public:
    CfgAntPollImpl() = default;
    CfgAntPollImpl(const CfgAntPollImpl&) = delete;
    CfgAntPollImpl(CfgAntPollImpl&&) = delete;
    virtual ~CfgAntPollImpl() = default;
    CfgAntPollImpl& operator=(const CfgAntPollImpl&) = default;
    CfgAntPollImpl& operator=(CfgAntPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgAntPoll::CfgAntPoll() : m_pImpl(new CfgAntPollImpl) {}
CfgAntPoll::~CfgAntPoll() = default;

CfgAntPoll& CfgAntPoll::operator=(const CfgAntPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgAntPoll& CfgAntPoll::operator=(CfgAntPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgAntPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgAntPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgAntPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgAntPoll::resetImpl()
{
    m_pImpl->reset();
}

bool CfgAntPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgAntPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgAntPoll::MsgIdParamType CfgAntPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgAntPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgAntPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgAntPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgAntPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgAntPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

