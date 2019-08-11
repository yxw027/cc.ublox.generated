#include "TimTos.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/TimTos.h"
#include "cc_plugin/field/Day.h"
#include "cc_plugin/field/GnssId.h"
#include "cc_plugin/field/Hour.h"
#include "cc_plugin/field/Min.h"
#include "cc_plugin/field/Month.h"
#include "cc_plugin/field/Res2.h"
#include "cc_plugin/field/Sec.h"
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

static QVariantMap createProps_version()
{
    using Field = ublox::message::TimTosFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_gnssId()
{
    using Field = ublox::message::TimTosFields<>::GnssId;
    auto props = cc_plugin::field::createProps_gnssId(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::TimTosFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

struct FlagsMembers
{
    static QVariantMap createProps_bitsLow()
    {
        using Field = ublox::message::TimTosFields<>::FlagsMembers::BitsLow;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "leapNow")
                .add(1U, "leapSoon")
                .add(2U, "leapPositive")
                .add(3U, "timeInLimit")
                .add(4U, "intOscInLimit")
                .add(5U, "extOscInLimit")
                .add(6U, "gnssTimeValid")
                .add(7U, "UTCTimeValid")
                .asMap();
        
    }
    
    static QVariantMap createProps_discSrc()
    {
        using Field = ublox::message::TimTosFields<>::FlagsMembers::DiscSrc;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("Internal", 0)
                .add("GNSS", 1)
                .add("EXTINT0", 2)
                .add("EXTINT1", 3)
                .add("HostInternal", 4)
                .add("HostExternal", 5)
                .asMap();
        
    }
    
    static QVariantMap createProps_bitsHigh()
    {
        using Field = ublox::message::TimTosFields<>::FlagsMembers::BitsHigh;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "raim")
                .add(1U, "cohPulse")
                .add(2U, "lockedPulse")
                .asMap();
        
    }
    
};

static QVariantMap createProps_flags()
{
    using Field = ublox::message::TimTosFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(FlagsMembers::createProps_bitsLow())
            .add(FlagsMembers::createProps_discSrc())
            .add(FlagsMembers::createProps_bitsHigh())
            .asMap();
    
}

static QVariantMap createProps_year()
{
    using Field = ublox::message::TimTosFields<>::Year;
    auto props = cc_plugin::field::createProps_year(Field::name());
    return props;
    
}

static QVariantMap createProps_month()
{
    using Field = ublox::message::TimTosFields<>::Month;
    auto props = cc_plugin::field::createProps_month(Field::name());
    return props;
    
}

static QVariantMap createProps_day()
{
    using Field = ublox::message::TimTosFields<>::Day;
    auto props = cc_plugin::field::createProps_day(Field::name());
    return props;
    
}

static QVariantMap createProps_hour()
{
    using Field = ublox::message::TimTosFields<>::Hour;
    auto props = cc_plugin::field::createProps_hour(Field::name());
    return props;
    
}

static QVariantMap createProps_min()
{
    using Field = ublox::message::TimTosFields<>::Min;
    auto props = cc_plugin::field::createProps_min(Field::name());
    return props;
    
}

static QVariantMap createProps_sec()
{
    using Field = ublox::message::TimTosFields<>::Sec;
    auto props = cc_plugin::field::createProps_sec(Field::name());
    return props;
    
}

static QVariantMap createProps_utcStandard()
{
    using Field = ublox::message::TimTosFields<>::UtcStandard;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("Unknown", 0)
            .add("USNO", 3)
            .add("SU", 6)
            .add("NTSC", 7)
            .asMap();
    
}

static QVariantMap createProps_utcOffset()
{
    using Field = ublox::message::TimTosFields<>::UtcOffset;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_utcUncertainty()
{
    using Field = ublox::message::TimTosFields<>::UtcUncertainty;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_week()
{
    using Field = ublox::message::TimTosFields<>::Week;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_tOW()
{
    using Field = ublox::message::TimTosFields<>::TOW;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_gnssOffset()
{
    using Field = ublox::message::TimTosFields<>::GnssOffset;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_gnssUncertainy()
{
    using Field = ublox::message::TimTosFields<>::GnssUncertainy;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_intOscOffset()
{
    using Field = ublox::message::TimTosFields<>::IntOscOffset;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(8U)
            .asMap();
    
}

static QVariantMap createProps_intOscUncertainty()
{
    using Field = ublox::message::TimTosFields<>::IntOscUncertainty;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(8U)
            .asMap();
    
}

static QVariantMap createProps_extOscOffset()
{
    using Field = ublox::message::TimTosFields<>::ExtOscOffset;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(8U)
            .asMap();
    
}

static QVariantMap createProps_extOscUncertainty()
{
    using Field = ublox::message::TimTosFields<>::ExtOscUncertainty;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(8U)
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_gnssId());
    props.append(createProps_reserved1());
    props.append(createProps_flags());
    props.append(createProps_year());
    props.append(createProps_month());
    props.append(createProps_day());
    props.append(createProps_hour());
    props.append(createProps_min());
    props.append(createProps_sec());
    props.append(createProps_utcStandard());
    props.append(createProps_utcOffset());
    props.append(createProps_utcUncertainty());
    props.append(createProps_week());
    props.append(createProps_tOW());
    props.append(createProps_gnssOffset());
    props.append(createProps_gnssUncertainy());
    props.append(createProps_intOscOffset());
    props.append(createProps_intOscUncertainty());
    props.append(createProps_extOscOffset());
    props.append(createProps_extOscUncertainty());
    return props;
}

} // namespace

class TimTosImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::TimTos<ublox::cc_plugin::Message>,
        TimTosImpl
    >
{
public:
    TimTosImpl() = default;
    TimTosImpl(const TimTosImpl&) = delete;
    TimTosImpl(TimTosImpl&&) = delete;
    virtual ~TimTosImpl() = default;
    TimTosImpl& operator=(const TimTosImpl&) = default;
    TimTosImpl& operator=(TimTosImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

TimTos::TimTos() : m_pImpl(new TimTosImpl) {}
TimTos::~TimTos() = default;

TimTos& TimTos::operator=(const TimTos& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

TimTos& TimTos::operator=(TimTos&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* TimTos::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& TimTos::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void TimTos::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void TimTos::resetImpl()
{
    m_pImpl->reset();
}

bool TimTos::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const TimTos*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

TimTos::MsgIdParamType TimTos::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus TimTos::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus TimTos::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool TimTos::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t TimTos::lengthImpl() const
{
    return m_pImpl->length();
}

bool TimTos::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


