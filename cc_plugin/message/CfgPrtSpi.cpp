#include "CfgPrtSpi.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgPrtSpi.h"
#include "cc_plugin/field/CfgPrtFlags.h"
#include "cc_plugin/field/CfgPrtInProtoMask.h"
#include "cc_plugin/field/CfgPrtOutProtoMask.h"
#include "cc_plugin/field/CfgPrtTxReady.h"
#include "cc_plugin/field/Res1.h"
#include "cc_plugin/field/Res2.h"
#include "cc_plugin/field/Res4.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_portId()
{
    using Field = ublox::message::CfgPrtSpiFields<>::PortId;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::CfgPrtSpiFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_txReady()
{
    using Field = ublox::message::CfgPrtSpiFields<>::TxReady;
    auto props = cc_plugin::field::createProps_cfgPrtTxReady(Field::name());
    return props;
    
}

struct ModeMembers
{
    static QVariantMap createProps_reservedLow()
    {
        using Field = ublox::message::CfgPrtSpiFields<>::ModeMembers::ReservedLow;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .hidden()
                .asMap();
        
    }
    
    static QVariantMap createProps_spiMode()
    {
        using Field = ublox::message::CfgPrtSpiFields<>::ModeMembers::SpiMode;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("Mode 0: CPOL = 0, CPHA = 0", 0)
                .add("Mode 1: CPOL = 0, CPHA = 1", 1)
                .add("Mode 2: CPOL = 1, CPHA = 0", 2)
                .add("Mode 3: CPOL = 1, CPHA = 1", 3)
                .asMap();
        
    }
    
    static QVariantMap createProps_bits()
    {
        using Field = ublox::message::CfgPrtSpiFields<>::ModeMembers::Bits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(3U, "flowControl")
                .asMap();
        
    }
    
    static QVariantMap createProps_ffCnt()
    {
        using Field = ublox::message::CfgPrtSpiFields<>::ModeMembers::FfCnt;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .asMap();
        
    }
    
    static QVariantMap createProps_reservedHigh()
    {
        using Field = ublox::message::CfgPrtSpiFields<>::ModeMembers::ReservedHigh;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .hidden()
                .asMap();
        
    }
    
};

static QVariantMap createProps_mode()
{
    using Field = ublox::message::CfgPrtSpiFields<>::Mode;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ModeMembers::createProps_reservedLow())
            .add(ModeMembers::createProps_spiMode())
            .add(ModeMembers::createProps_bits())
            .add(ModeMembers::createProps_ffCnt())
            .add(ModeMembers::createProps_reservedHigh())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::CfgPrtSpiFields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res4(Field::name());
    return props;
    
}

static QVariantMap createProps_inProtoMask()
{
    using Field = ublox::message::CfgPrtSpiFields<>::InProtoMask;
    auto props = cc_plugin::field::createProps_cfgPrtInProtoMask(Field::name());
    return props;
    
}

static QVariantMap createProps_outProtoMask()
{
    using Field = ublox::message::CfgPrtSpiFields<>::OutProtoMask;
    auto props = cc_plugin::field::createProps_cfgPrtOutProtoMask(Field::name());
    return props;
    
}

static QVariantMap createProps_cfgPrtFlags()
{
    using Field = ublox::message::CfgPrtSpiFields<>::CfgPrtFlags;
    auto props = cc_plugin::field::createProps_cfgPrtFlags(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::CfgPrtSpiFields<>::Reserved3;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_portId());
    props.append(createProps_reserved1());
    props.append(createProps_txReady());
    props.append(createProps_mode());
    props.append(createProps_reserved2());
    props.append(createProps_inProtoMask());
    props.append(createProps_outProtoMask());
    props.append(createProps_cfgPrtFlags());
    props.append(createProps_reserved3());
    return props;
}

} // namespace

class CfgPrtSpiImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgPrtSpi<ublox::cc_plugin::Message>,
        CfgPrtSpiImpl
    >
{
public:
    CfgPrtSpiImpl() = default;
    CfgPrtSpiImpl(const CfgPrtSpiImpl&) = delete;
    CfgPrtSpiImpl(CfgPrtSpiImpl&&) = delete;
    virtual ~CfgPrtSpiImpl() = default;
    CfgPrtSpiImpl& operator=(const CfgPrtSpiImpl&) = default;
    CfgPrtSpiImpl& operator=(CfgPrtSpiImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgPrtSpi::CfgPrtSpi() : m_pImpl(new CfgPrtSpiImpl) {}
CfgPrtSpi::~CfgPrtSpi() = default;

CfgPrtSpi& CfgPrtSpi::operator=(const CfgPrtSpi& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgPrtSpi& CfgPrtSpi::operator=(CfgPrtSpi&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgPrtSpi::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgPrtSpi::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgPrtSpi::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgPrtSpi::resetImpl()
{
    m_pImpl->reset();
}

bool CfgPrtSpi::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgPrtSpi*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgPrtSpi::MsgIdParamType CfgPrtSpi::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgPrtSpi::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgPrtSpi::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgPrtSpi::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgPrtSpi::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgPrtSpi::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


