#include "CfgOdo.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgOdo.h"
#include "cc_plugin/field/Res2.h"
#include "cc_plugin/field/Res3.h"
#include "cc_plugin/field/Res6.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_version()
{
    using Field = ublox::message::CfgOdoFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::CfgOdoFields<>::Reserved1;
    return cc_plugin::field::createProps_res3(Field::name());
    
}

static QVariantMap createProps_flags()
{
    using Field = ublox::message::CfgOdoFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "useODO")
            .add(1U, "useCOG")
            .add(2U, "outLPVel")
            .add(3U, "outLPCog")
            .asMap();
    
}

struct OdoCfgMembers
{
    static QVariantMap createProps_profile()
    {
        using Field = ublox::message::CfgOdoFields<>::OdoCfgMembers::Profile;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("Running", 0)
                .add("Cycling", 1)
                .add("Swimming", 2)
                .add("Car", 3)
                .add("Custom", 4)
                .asMap();
        
    }
    
    static QVariantMap createProps_reserved()
    {
        using Field = ublox::message::CfgOdoFields<>::OdoCfgMembers::Reserved;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .hidden()
                .asMap();
        
    }
    
};

static QVariantMap createProps_odoCfg()
{
    using Field = ublox::message::CfgOdoFields<>::OdoCfg;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(OdoCfgMembers::createProps_profile())
            .add(OdoCfgMembers::createProps_reserved())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::CfgOdoFields<>::Reserved2;
    return cc_plugin::field::createProps_res6(Field::name());
    
}

static QVariantMap createProps_cogMaxSpeed()
{
    using Field = ublox::message::CfgOdoFields<>::CogMaxSpeed;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

static QVariantMap createProps_cogMaxPosAcc()
{
    using Field = ublox::message::CfgOdoFields<>::CogMaxPosAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::CfgOdoFields<>::Reserved3;
    return cc_plugin::field::createProps_res2(Field::name());
    
}

static QVariantMap createProps_velLpGain()
{
    using Field = ublox::message::CfgOdoFields<>::VelLpGain;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cogLpGain()
{
    using Field = ublox::message::CfgOdoFields<>::CogLpGain;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved4()
{
    using Field = ublox::message::CfgOdoFields<>::Reserved4;
    return cc_plugin::field::createProps_res2(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_flags());
    props.append(createProps_odoCfg());
    props.append(createProps_reserved2());
    props.append(createProps_cogMaxSpeed());
    props.append(createProps_cogMaxPosAcc());
    props.append(createProps_reserved3());
    props.append(createProps_velLpGain());
    props.append(createProps_cogLpGain());
    props.append(createProps_reserved4());
    return props;
}

} // namespace

class CfgOdoImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgOdo<ublox::cc_plugin::Message>,
        CfgOdoImpl
    >
{
public:
    CfgOdoImpl() = default;
    CfgOdoImpl(const CfgOdoImpl&) = delete;
    CfgOdoImpl(CfgOdoImpl&&) = delete;
    virtual ~CfgOdoImpl() = default;
    CfgOdoImpl& operator=(const CfgOdoImpl&) = default;
    CfgOdoImpl& operator=(CfgOdoImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgOdo::CfgOdo() : m_pImpl(new CfgOdoImpl) {}
CfgOdo::~CfgOdo() = default;

CfgOdo& CfgOdo::operator=(const CfgOdo& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgOdo& CfgOdo::operator=(CfgOdo&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgOdo::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgOdo::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgOdo::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgOdo::resetImpl()
{
    m_pImpl->reset();
}

bool CfgOdo::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgOdo*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgOdo::MsgIdParamType CfgOdo::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgOdo::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgOdo::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgOdo::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgOdo::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgOdo::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

