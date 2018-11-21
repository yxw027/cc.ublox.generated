#include "CfgDatStandard.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgDatStandard.h"
#include "cc_plugin/field/CfgDatDatumNum.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_datumNum()
{
    using Field = ublox::message::CfgDatStandardFields<>::DatumNum;
    return cc_plugin::field::createProps_cfgDatDatumNum(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_datumNum());
    return props;
}

} // namespace

class CfgDatStandardImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgDatStandard<ublox::cc_plugin::Message>,
        CfgDatStandardImpl
    >
{
public:
    CfgDatStandardImpl() = default;
    CfgDatStandardImpl(const CfgDatStandardImpl&) = delete;
    CfgDatStandardImpl(CfgDatStandardImpl&&) = delete;
    virtual ~CfgDatStandardImpl() = default;
    CfgDatStandardImpl& operator=(const CfgDatStandardImpl&) = default;
    CfgDatStandardImpl& operator=(CfgDatStandardImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgDatStandard::CfgDatStandard() : m_pImpl(new CfgDatStandardImpl) {}
CfgDatStandard::~CfgDatStandard() = default;

CfgDatStandard& CfgDatStandard::operator=(const CfgDatStandard& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgDatStandard& CfgDatStandard::operator=(CfgDatStandard&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgDatStandard::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgDatStandard::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgDatStandard::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgDatStandard::resetImpl()
{
    m_pImpl->reset();
}

bool CfgDatStandard::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgDatStandard*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgDatStandard::MsgIdParamType CfgDatStandard::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgDatStandard::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgDatStandard::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgDatStandard::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgDatStandard::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgDatStandard::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

