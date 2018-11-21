#include "NavPvt.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavPvt.h"
#include "cc_plugin/field/Day.h"
#include "cc_plugin/field/Dop.h"
#include "cc_plugin/field/GpsFix.h"
#include "cc_plugin/field/HAcc.h"
#include "cc_plugin/field/HMSL.h"
#include "cc_plugin/field/Heading.h"
#include "cc_plugin/field/HeadingAcc.h"
#include "cc_plugin/field/Height.h"
#include "cc_plugin/field/Hour.h"
#include "cc_plugin/field/Itow.h"
#include "cc_plugin/field/Lat.h"
#include "cc_plugin/field/Lon.h"
#include "cc_plugin/field/Min.h"
#include "cc_plugin/field/Month.h"
#include "cc_plugin/field/Res2.h"
#include "cc_plugin/field/Res4.h"
#include "cc_plugin/field/Sec.h"
#include "cc_plugin/field/VAcc.h"
#include "cc_plugin/field/Vel.h"
#include "cc_plugin/field/Year.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_itow()
{
    using Field = ublox::message::NavPvtFields<>::Itow;
    return cc_plugin::field::createProps_itow(Field::name());
    
}

static QVariantMap createProps_year()
{
    using Field = ublox::message::NavPvtFields<>::Year;
    return cc_plugin::field::createProps_year(Field::name());
    
}

static QVariantMap createProps_month()
{
    using Field = ublox::message::NavPvtFields<>::Month;
    return cc_plugin::field::createProps_month(Field::name());
    
}

static QVariantMap createProps_day()
{
    using Field = ublox::message::NavPvtFields<>::Day;
    return cc_plugin::field::createProps_day(Field::name());
    
}

static QVariantMap createProps_hour()
{
    using Field = ublox::message::NavPvtFields<>::Hour;
    return cc_plugin::field::createProps_hour(Field::name());
    
}

static QVariantMap createProps_min()
{
    using Field = ublox::message::NavPvtFields<>::Min;
    return cc_plugin::field::createProps_min(Field::name());
    
}

static QVariantMap createProps_sec()
{
    using Field = ublox::message::NavPvtFields<>::Sec;
    return cc_plugin::field::createProps_sec(Field::name());
    
}

static QVariantMap createProps_valid()
{
    using Field = ublox::message::NavPvtFields<>::Valid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "validDate")
            .add(1U, "validTime")
            .add(2U, "fullyResolved")
            .asMap();
    
}

static QVariantMap createProps_tAcc()
{
    using Field = ublox::message::NavPvtFields<>::TAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_nano()
{
    using Field = ublox::message::NavPvtFields<>::Nano;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_fixType()
{
    using Field = ublox::message::NavPvtFields<>::FixType;
    return cc_plugin::field::createProps_gpsFix(Field::name());
    
}

struct FlagsMembers
{
    static QVariantMap createProps_lowBits()
    {
        using Field = ublox::message::NavPvtFields<>::FlagsMembers::LowBits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "gnssFixOK")
                .add(1U, "diffSoln")
                .asMap();
        
    }
    
    static QVariantMap createProps_psmState()
    {
        using Field = ublox::message::NavPvtFields<>::FlagsMembers::PsmState;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("N/A", 0)
                .add("ENABLED", 1)
                .add("ACQUISITION", 2)
                .add("TRACKING", 3)
                .add("POWER OPTIMIZED TRACKING", 4)
                .add("INACTIVE", 5)
                .asMap();
        
    }
    
    static QVariantMap createProps_midBits()
    {
        using Field = ublox::message::NavPvtFields<>::FlagsMembers::MidBits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "headVehValid")
                .asMap();
        
    }
    
    static QVariantMap createProps_carrSoln()
    {
        using Field = ublox::message::NavPvtFields<>::FlagsMembers::CarrSoln;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("No carrier", 0)
                .add("Float solution", 1)
                .add("Fixed solution", 2)
                .asMap();
        
    }
    
};

static QVariantMap createProps_flags()
{
    using Field = ublox::message::NavPvtFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(FlagsMembers::createProps_lowBits())
            .add(FlagsMembers::createProps_psmState())
            .add(FlagsMembers::createProps_midBits())
            .add(FlagsMembers::createProps_carrSoln())
            .asMap();
    
}

static QVariantMap createProps_flags2()
{
    using Field = ublox::message::NavPvtFields<>::Flags2;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(5U, "confirmedAvai")
            .add(6U, "confirmedDate")
            .add(7U, "confirmedTime")
            .asMap();
    
}

static QVariantMap createProps_numSV()
{
    using Field = ublox::message::NavPvtFields<>::NumSV;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_lon()
{
    using Field = ublox::message::NavPvtFields<>::Lon;
    return cc_plugin::field::createProps_lon(Field::name());
    
}

static QVariantMap createProps_lat()
{
    using Field = ublox::message::NavPvtFields<>::Lat;
    return cc_plugin::field::createProps_lat(Field::name());
    
}

static QVariantMap createProps_height()
{
    using Field = ublox::message::NavPvtFields<>::Height;
    return cc_plugin::field::createProps_height(Field::name());
    
}

static QVariantMap createProps_hMSL()
{
    using Field = ublox::message::NavPvtFields<>::HMSL;
    return cc_plugin::field::createProps_hMSL(Field::name());
    
}

static QVariantMap createProps_hAcc()
{
    using Field = ublox::message::NavPvtFields<>::HAcc;
    return cc_plugin::field::createProps_hAcc(Field::name());
    
}

static QVariantMap createProps_vAcc()
{
    using Field = ublox::message::NavPvtFields<>::VAcc;
    return cc_plugin::field::createProps_vAcc(Field::name());
    
}

static QVariantMap createProps_velN()
{
    using Field = ublox::message::NavPvtFields<>::VelN;
    return cc_plugin::field::createProps_vel(Field::name());
    
}

static QVariantMap createProps_velE()
{
    using Field = ublox::message::NavPvtFields<>::VelE;
    return cc_plugin::field::createProps_vel(Field::name());
    
}

static QVariantMap createProps_velD()
{
    using Field = ublox::message::NavPvtFields<>::VelD;
    return cc_plugin::field::createProps_vel(Field::name());
    
}

static QVariantMap createProps_gSpeed()
{
    using Field = ublox::message::NavPvtFields<>::GSpeed;
    return cc_plugin::field::createProps_vel(Field::name());
    
}

static QVariantMap createProps_heading()
{
    using Field = ublox::message::NavPvtFields<>::Heading;
    return cc_plugin::field::createProps_heading(Field::name());
    
}

static QVariantMap createProps_sAcc()
{
    using Field = ublox::message::NavPvtFields<>::SAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_headingAcc()
{
    using Field = ublox::message::NavPvtFields<>::HeadingAcc;
    return cc_plugin::field::createProps_headingAcc(Field::name());
    
}

static QVariantMap createProps_pDop()
{
    using Field = ublox::message::NavPvtFields<>::PDop;
    return cc_plugin::field::createProps_dop(Field::name());
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::NavPvtFields<>::Reserved2;
    return cc_plugin::field::createProps_res2(Field::name());
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::NavPvtFields<>::Reserved3;
    return cc_plugin::field::createProps_res4(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_itow());
    props.append(createProps_year());
    props.append(createProps_month());
    props.append(createProps_day());
    props.append(createProps_hour());
    props.append(createProps_min());
    props.append(createProps_sec());
    props.append(createProps_valid());
    props.append(createProps_tAcc());
    props.append(createProps_nano());
    props.append(createProps_fixType());
    props.append(createProps_flags());
    props.append(createProps_flags2());
    props.append(createProps_numSV());
    props.append(createProps_lon());
    props.append(createProps_lat());
    props.append(createProps_height());
    props.append(createProps_hMSL());
    props.append(createProps_hAcc());
    props.append(createProps_vAcc());
    props.append(createProps_velN());
    props.append(createProps_velE());
    props.append(createProps_velD());
    props.append(createProps_gSpeed());
    props.append(createProps_heading());
    props.append(createProps_sAcc());
    props.append(createProps_headingAcc());
    props.append(createProps_pDop());
    props.append(createProps_reserved2());
    props.append(createProps_reserved3());
    return props;
}

} // namespace

class NavPvtImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavPvt<ublox::cc_plugin::Message>,
        NavPvtImpl
    >
{
public:
    NavPvtImpl() = default;
    NavPvtImpl(const NavPvtImpl&) = delete;
    NavPvtImpl(NavPvtImpl&&) = delete;
    virtual ~NavPvtImpl() = default;
    NavPvtImpl& operator=(const NavPvtImpl&) = default;
    NavPvtImpl& operator=(NavPvtImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavPvt::NavPvt() : m_pImpl(new NavPvtImpl) {}
NavPvt::~NavPvt() = default;

NavPvt& NavPvt::operator=(const NavPvt& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavPvt& NavPvt::operator=(NavPvt&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavPvt::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavPvt::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavPvt::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavPvt::resetImpl()
{
    m_pImpl->reset();
}

bool NavPvt::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavPvt*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavPvt::MsgIdParamType NavPvt::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavPvt::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavPvt::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavPvt::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavPvt::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavPvt::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

