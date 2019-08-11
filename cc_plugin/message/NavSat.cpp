#include "NavSat.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavSat.h"
#include "cc_plugin/field/GnssId.h"
#include "cc_plugin/field/Itow.h"
#include "cc_plugin/field/Res2.h"

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
    using Field = ublox::message::NavSatFields<>::Itow;
    auto props = cc_plugin::field::createProps_itow(Field::name());
    return props;
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::NavSatFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_numSvs()
{
    using Field = ublox::message::NavSatFields<>::NumSvs;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::NavSatFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

struct ListMembers
{
    struct ElementMembers
    {
        static QVariantMap createProps_gnssId()
        {
            using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::GnssId;
            auto props = cc_plugin::field::createProps_gnssId(Field::name());
            return props;
            
        }
        
        static QVariantMap createProps_svid()
        {
            using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::Svid;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_cno()
        {
            using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::Cno;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_elev()
        {
            using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::Elev;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_azim()
        {
            using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::Azim;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_prRes()
        {
            using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::PrRes;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(1U)
                    .asMap();
            
        }
        
        struct FlagsMembers
        {
            static QVariantMap createProps_qualityInd()
            {
                using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::FlagsMembers::QualityInd;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add("no signal", 0)
                        .add("searching", 1)
                        .add("signal acquired", 2)
                        .add("detected but unsable", 3)
                        .add("code locked", 4)
                        .add("code and carrier locked", 5)
                        .add("code and carrier locked", 6)
                        .add("code and carrier locked", 7)
                        .asMap();
                
            }
            
            static QVariantMap createProps_bitsLow()
            {
                using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::FlagsMembers::BitsLow;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add(0U, "svUsed")
                        .asMap();
                
            }
            
            static QVariantMap createProps_health()
            {
                using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::FlagsMembers::Health;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add("Unknown", 0)
                        .add("Healthy", 1)
                        .add("Unhealthy", 2)
                        .asMap();
                
            }
            
            static QVariantMap createProps_bitsMid()
            {
                using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::FlagsMembers::BitsMid;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add(0U, "diffCorr")
                        .add(1U, "smoothed")
                        .asMap();
                
            }
            
            static QVariantMap createProps_orbitSource()
            {
                using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::FlagsMembers::OrbitSource;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add("No orbit", 0)
                        .add("Ephemeris", 1)
                        .add("Almanac", 2)
                        .add("AssistNow Offline", 3)
                        .add("AssistNow Autonomous", 4)
                        .asMap();
                
            }
            
            static QVariantMap createProps_bitsHigh()
            {
                using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::FlagsMembers::BitsHigh;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add(0U, "ephAvail")
                        .add(1U, "almAvail")
                        .add(2U, "anoAvail")
                        .add(3U, "aopAvail")
                        .add(5U, "sbasCorrUsed")
                        .add(6U, "rtcmCorrUsed")
                        .add(9U, "prCorrUsed")
                        .add(10U, "crCorrUsed")
                        .add(11U, "doCorrUsed")
                        .asMap();
                
            }
            
        };
        
        static QVariantMap createProps_flags()
        {
            using Field = ublox::message::NavSatFields<>::ListMembers::ElementMembers::Flags;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add(FlagsMembers::createProps_qualityInd())
                    .add(FlagsMembers::createProps_bitsLow())
                    .add(FlagsMembers::createProps_health())
                    .add(FlagsMembers::createProps_bitsMid())
                    .add(FlagsMembers::createProps_orbitSource())
                    .add(FlagsMembers::createProps_bitsHigh())
                    .asMap();
            
        }
        
    };
    
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::NavSatFields<>::ListMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ElementMembers::createProps_gnssId())
                .add(ElementMembers::createProps_svid())
                .add(ElementMembers::createProps_cno())
                .add(ElementMembers::createProps_elev())
                .add(ElementMembers::createProps_azim())
                .add(ElementMembers::createProps_prRes())
                .add(ElementMembers::createProps_flags())
                .asMap();
        
    }
    
};

static QVariantMap createProps_list()
{
    using Field = ublox::message::NavSatFields<>::List;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ListMembers::createProps_element())
            .serialisedHidden()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_itow());
    props.append(createProps_version());
    props.append(createProps_numSvs());
    props.append(createProps_reserved1());
    props.append(createProps_list());
    return props;
}

} // namespace

class NavSatImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavSat<ublox::cc_plugin::Message>,
        NavSatImpl
    >
{
public:
    NavSatImpl() = default;
    NavSatImpl(const NavSatImpl&) = delete;
    NavSatImpl(NavSatImpl&&) = delete;
    virtual ~NavSatImpl() = default;
    NavSatImpl& operator=(const NavSatImpl&) = default;
    NavSatImpl& operator=(NavSatImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavSat::NavSat() : m_pImpl(new NavSatImpl) {}
NavSat::~NavSat() = default;

NavSat& NavSat::operator=(const NavSat& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavSat& NavSat::operator=(NavSat&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavSat::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavSat::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavSat::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavSat::resetImpl()
{
    m_pImpl->reset();
}

bool NavSat::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavSat*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavSat::MsgIdParamType NavSat::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavSat::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavSat::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavSat::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavSat::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavSat::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


