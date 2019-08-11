#include "CfgNavx5V3.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgNavx5V3.h"
#include "cc_plugin/field/CfgNavx5AopCfg.h"
#include "cc_plugin/field/CfgNavx5AopOrbMaxErr.h"
#include "cc_plugin/field/CfgNavx5Mask1.h"
#include "cc_plugin/field/CfgNavx5Mask2.h"
#include "cc_plugin/field/CfgNavx5SigAttenCompMode.h"
#include "cc_plugin/field/Res1.h"
#include "cc_plugin/field/Res2.h"
#include "cc_plugin/field/Res3.h"
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

static QVariantMap createProps_version()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_mask1()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Mask1;
    auto props = cc_plugin::field::createProps_cfgNavx5Mask1(Field::name());
    return props;
    
}

static QVariantMap createProps_mask2()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Mask2;
    auto props = cc_plugin::field::createProps_cfgNavx5Mask2(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_minSVs()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::MinSVs;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_maxSVs()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::MaxSVs;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_minCNO()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::MinCNO;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_iniFix3D()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::IniFix3D;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved3;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_ackAiding()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::AckAiding;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_wknRollover()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::WknRollover;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_sigAttenCompMode()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::SigAttenCompMode;
    auto props = cc_plugin::field::createProps_cfgNavx5SigAttenCompMode(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved4()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved4;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved5()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved5;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved6()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved6;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_usePPP()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::UsePPP;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_aopCfg()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::AopCfg;
    auto props = cc_plugin::field::createProps_cfgNavx5AopCfg(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved7()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved7;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_aopOrbMaxErr()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::AopOrbMaxErr;
    auto props = cc_plugin::field::createProps_cfgNavx5AopOrbMaxErr(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved8()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved8;
    auto props = cc_plugin::field::createProps_res4(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved9()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved9;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

static QVariantMap createProps_useAdr()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::UseAdr;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved10()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved10;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved11()
{
    using Field = ublox::message::CfgNavx5V3Fields<>::Reserved11;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_mask1());
    props.append(createProps_mask2());
    props.append(createProps_reserved1());
    props.append(createProps_minSVs());
    props.append(createProps_maxSVs());
    props.append(createProps_minCNO());
    props.append(createProps_reserved2());
    props.append(createProps_iniFix3D());
    props.append(createProps_reserved3());
    props.append(createProps_ackAiding());
    props.append(createProps_wknRollover());
    props.append(createProps_sigAttenCompMode());
    props.append(createProps_reserved4());
    props.append(createProps_reserved5());
    props.append(createProps_reserved6());
    props.append(createProps_usePPP());
    props.append(createProps_aopCfg());
    props.append(createProps_reserved7());
    props.append(createProps_aopOrbMaxErr());
    props.append(createProps_reserved8());
    props.append(createProps_reserved9());
    props.append(createProps_useAdr());
    props.append(createProps_reserved10());
    props.append(createProps_reserved11());
    return props;
}

} // namespace

class CfgNavx5V3Impl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgNavx5V3<ublox::cc_plugin::Message>,
        CfgNavx5V3Impl
    >
{
public:
    CfgNavx5V3Impl() = default;
    CfgNavx5V3Impl(const CfgNavx5V3Impl&) = delete;
    CfgNavx5V3Impl(CfgNavx5V3Impl&&) = delete;
    virtual ~CfgNavx5V3Impl() = default;
    CfgNavx5V3Impl& operator=(const CfgNavx5V3Impl&) = default;
    CfgNavx5V3Impl& operator=(CfgNavx5V3Impl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgNavx5V3::CfgNavx5V3() : m_pImpl(new CfgNavx5V3Impl) {}
CfgNavx5V3::~CfgNavx5V3() = default;

CfgNavx5V3& CfgNavx5V3::operator=(const CfgNavx5V3& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgNavx5V3& CfgNavx5V3::operator=(CfgNavx5V3&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgNavx5V3::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgNavx5V3::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgNavx5V3::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgNavx5V3::resetImpl()
{
    m_pImpl->reset();
}

bool CfgNavx5V3::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgNavx5V3*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgNavx5V3::MsgIdParamType CfgNavx5V3::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgNavx5V3::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgNavx5V3::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgNavx5V3::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgNavx5V3::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgNavx5V3::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


