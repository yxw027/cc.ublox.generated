#include "HnrPvt.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/HnrPvt.h"
#include "cc_plugin/field/Day.h"
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
    using Field = ublox::message::HnrPvtFields<>::Itow;
    return cc_plugin::field::createProps_itow(Field::name());
    
}

static QVariantMap createProps_year()
{
    using Field = ublox::message::HnrPvtFields<>::Year;
    return cc_plugin::field::createProps_year(Field::name());
    
}

static QVariantMap createProps_month()
{
    using Field = ublox::message::HnrPvtFields<>::Month;
    return cc_plugin::field::createProps_month(Field::name());
    
}

static QVariantMap createProps_day()
{
    using Field = ublox::message::HnrPvtFields<>::Day;
    return cc_plugin::field::createProps_day(Field::name());
    
}

static QVariantMap createProps_hour()
{
    using Field = ublox::message::HnrPvtFields<>::Hour;
    return cc_plugin::field::createProps_hour(Field::name());
    
}

static QVariantMap createProps_min()
{
    using Field = ublox::message::HnrPvtFields<>::Min;
    return cc_plugin::field::createProps_min(Field::name());
    
}

static QVariantMap createProps_sec()
{
    using Field = ublox::message::HnrPvtFields<>::Sec;
    return cc_plugin::field::createProps_sec(Field::name());
    
}

static QVariantMap createProps_valid()
{
    using Field = ublox::message::HnrPvtFields<>::Valid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "validDate")
            .add(1U, "validTime")
            .add(2U, "fullyResolved")
            .asMap();
    
}

static QVariantMap createProps_nano()
{
    using Field = ublox::message::HnrPvtFields<>::Nano;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_fixType()
{
    using Field = ublox::message::HnrPvtFields<>::FixType;
    return cc_plugin::field::createProps_gpsFix(Field::name());
    
}

static QVariantMap createProps_flags()
{
    using Field = ublox::message::HnrPvtFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "GPSfixOK")
            .add(1U, "DiffSoln")
            .add(2U, "WKNSET")
            .add(3U, "TOWSET")
            .add(4U, "headVehValid")
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::HnrPvtFields<>::Reserved1;
    return cc_plugin::field::createProps_res2(Field::name());
    
}

static QVariantMap createProps_lon()
{
    using Field = ublox::message::HnrPvtFields<>::Lon;
    return cc_plugin::field::createProps_lon(Field::name());
    
}

static QVariantMap createProps_lat()
{
    using Field = ublox::message::HnrPvtFields<>::Lat;
    return cc_plugin::field::createProps_lat(Field::name());
    
}

static QVariantMap createProps_height()
{
    using Field = ublox::message::HnrPvtFields<>::Height;
    return cc_plugin::field::createProps_height(Field::name());
    
}

static QVariantMap createProps_hMSL()
{
    using Field = ublox::message::HnrPvtFields<>::HMSL;
    return cc_plugin::field::createProps_hMSL(Field::name());
    
}

static QVariantMap createProps_gSpeed()
{
    using Field = ublox::message::HnrPvtFields<>::GSpeed;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_speed()
{
    using Field = ublox::message::HnrPvtFields<>::Speed;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_headMot()
{
    using Field = ublox::message::HnrPvtFields<>::HeadMot;
    return cc_plugin::field::createProps_heading(Field::name());
    
}

static QVariantMap createProps_headVeh()
{
    using Field = ublox::message::HnrPvtFields<>::HeadVeh;
    return cc_plugin::field::createProps_heading(Field::name());
    
}

static QVariantMap createProps_hAcc()
{
    using Field = ublox::message::HnrPvtFields<>::HAcc;
    return cc_plugin::field::createProps_hAcc(Field::name());
    
}

static QVariantMap createProps_vAcc()
{
    using Field = ublox::message::HnrPvtFields<>::VAcc;
    return cc_plugin::field::createProps_vAcc(Field::name());
    
}

static QVariantMap createProps_sAcc()
{
    using Field = ublox::message::HnrPvtFields<>::SAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_headAcc()
{
    using Field = ublox::message::HnrPvtFields<>::HeadAcc;
    return cc_plugin::field::createProps_headingAcc(Field::name());
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::HnrPvtFields<>::Reserved2;
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
    props.append(createProps_nano());
    props.append(createProps_fixType());
    props.append(createProps_flags());
    props.append(createProps_reserved1());
    props.append(createProps_lon());
    props.append(createProps_lat());
    props.append(createProps_height());
    props.append(createProps_hMSL());
    props.append(createProps_gSpeed());
    props.append(createProps_speed());
    props.append(createProps_headMot());
    props.append(createProps_headVeh());
    props.append(createProps_hAcc());
    props.append(createProps_vAcc());
    props.append(createProps_sAcc());
    props.append(createProps_headAcc());
    props.append(createProps_reserved2());
    return props;
}

} // namespace

class HnrPvtImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::HnrPvt<ublox::cc_plugin::Message>,
        HnrPvtImpl
    >
{
public:
    HnrPvtImpl() = default;
    HnrPvtImpl(const HnrPvtImpl&) = delete;
    HnrPvtImpl(HnrPvtImpl&&) = delete;
    virtual ~HnrPvtImpl() = default;
    HnrPvtImpl& operator=(const HnrPvtImpl&) = default;
    HnrPvtImpl& operator=(HnrPvtImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

HnrPvt::HnrPvt() : m_pImpl(new HnrPvtImpl) {}
HnrPvt::~HnrPvt() = default;

HnrPvt& HnrPvt::operator=(const HnrPvt& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

HnrPvt& HnrPvt::operator=(HnrPvt&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* HnrPvt::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& HnrPvt::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void HnrPvt::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void HnrPvt::resetImpl()
{
    m_pImpl->reset();
}

bool HnrPvt::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const HnrPvt*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

HnrPvt::MsgIdParamType HnrPvt::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus HnrPvt::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus HnrPvt::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool HnrPvt::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t HnrPvt::lengthImpl() const
{
    return m_pImpl->length();
}

bool HnrPvt::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

