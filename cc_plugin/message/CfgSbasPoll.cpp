#include "CfgSbasPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgSbasPoll.h"
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

class CfgSbasPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgSbasPoll<ublox::cc_plugin::Message>,
        CfgSbasPollImpl
    >
{
public:
    CfgSbasPollImpl() = default;
    CfgSbasPollImpl(const CfgSbasPollImpl&) = delete;
    CfgSbasPollImpl(CfgSbasPollImpl&&) = delete;
    virtual ~CfgSbasPollImpl() = default;
    CfgSbasPollImpl& operator=(const CfgSbasPollImpl&) = default;
    CfgSbasPollImpl& operator=(CfgSbasPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgSbasPoll::CfgSbasPoll() : m_pImpl(new CfgSbasPollImpl) {}
CfgSbasPoll::~CfgSbasPoll() = default;

CfgSbasPoll& CfgSbasPoll::operator=(const CfgSbasPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgSbasPoll& CfgSbasPoll::operator=(CfgSbasPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgSbasPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgSbasPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgSbasPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgSbasPoll::resetImpl()
{
    m_pImpl->reset();
}

bool CfgSbasPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgSbasPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgSbasPoll::MsgIdParamType CfgSbasPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgSbasPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgSbasPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgSbasPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgSbasPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgSbasPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

