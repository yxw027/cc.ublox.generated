#include "CfgCfg.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgCfg.h"
#include "cc_plugin/field/CfgCfgMask.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_clearMask()
{
    using Field = ublox::message::CfgCfgFields<>::ClearMask;
    return cc_plugin::field::createProps_cfgCfgMask(Field::name());
    
}

static QVariantMap createProps_saveMask()
{
    using Field = ublox::message::CfgCfgFields<>::SaveMask;
    return cc_plugin::field::createProps_cfgCfgMask(Field::name());
    
}

static QVariantMap createProps_loadMask()
{
    using Field = ublox::message::CfgCfgFields<>::LoadMask;
    return cc_plugin::field::createProps_cfgCfgMask(Field::name());
    
}

struct DeviceMaskMembers
{
    static QVariantMap createProps_deviceMask()
    {
        using Field = ublox::message::CfgCfgFields<>::DeviceMaskMembers::DeviceMask;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(0U, "devBBR")
                .add(1U, "devFlash")
                .add(2U, "devEEPROM")
                .add(4U, "devSpiFlash")
                .asMap();
        
    }
    
};

static QVariantMap createProps_deviceMask()
{
    using Field = ublox::message::CfgCfgFields<>::DeviceMask;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .field(DeviceMaskMembers::createProps_deviceMask())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_clearMask());
    props.append(createProps_saveMask());
    props.append(createProps_loadMask());
    props.append(createProps_deviceMask());
    return props;
}

} // namespace

class CfgCfgImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgCfg<ublox::cc_plugin::Message>,
        CfgCfgImpl
    >
{
public:
    CfgCfgImpl() = default;
    CfgCfgImpl(const CfgCfgImpl&) = delete;
    CfgCfgImpl(CfgCfgImpl&&) = delete;
    virtual ~CfgCfgImpl() = default;
    CfgCfgImpl& operator=(const CfgCfgImpl&) = default;
    CfgCfgImpl& operator=(CfgCfgImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgCfg::CfgCfg() : m_pImpl(new CfgCfgImpl) {}
CfgCfg::~CfgCfg() = default;

CfgCfg& CfgCfg::operator=(const CfgCfg& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgCfg& CfgCfg::operator=(CfgCfg&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgCfg::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgCfg::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgCfg::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgCfg::resetImpl()
{
    m_pImpl->reset();
}

bool CfgCfg::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgCfg*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgCfg::MsgIdParamType CfgCfg::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgCfg::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgCfg::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgCfg::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgCfg::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgCfg::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

