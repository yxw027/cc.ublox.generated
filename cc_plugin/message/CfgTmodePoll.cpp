// Generated by commsdsl2comms v3.3.2

#include "CfgTmodePoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgTmodePoll.h"
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

class CfgTmodePollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgTmodePoll<ublox::cc_plugin::Message>,
        CfgTmodePollImpl
    >
{
public:
    CfgTmodePollImpl() = default;
    CfgTmodePollImpl(const CfgTmodePollImpl&) = delete;
    CfgTmodePollImpl(CfgTmodePollImpl&&) = delete;
    virtual ~CfgTmodePollImpl() = default;
    CfgTmodePollImpl& operator=(const CfgTmodePollImpl&) = default;
    CfgTmodePollImpl& operator=(CfgTmodePollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgTmodePoll::CfgTmodePoll() : m_pImpl(new CfgTmodePollImpl) {}
CfgTmodePoll::~CfgTmodePoll() = default;

CfgTmodePoll& CfgTmodePoll::operator=(const CfgTmodePoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgTmodePoll& CfgTmodePoll::operator=(CfgTmodePoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgTmodePoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgTmodePoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgTmodePoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgTmodePoll::resetImpl()
{
    m_pImpl->reset();
}

bool CfgTmodePoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgTmodePoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgTmodePoll::MsgIdParamType CfgTmodePoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgTmodePoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgTmodePoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgTmodePoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgTmodePoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgTmodePoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


