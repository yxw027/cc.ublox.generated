#include "NavStatus.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavStatus.h"
#include "cc_plugin/field/GpsFix.h"
#include "cc_plugin/field/Itow.h"

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
    using Field = ublox::message::NavStatusFields<>::Itow;
    auto props = cc_plugin::field::createProps_itow(Field::name());
    return props;
    
}

static QVariantMap createProps_gpsFix()
{
    using Field = ublox::message::NavStatusFields<>::GpsFix;
    auto props = cc_plugin::field::createProps_gpsFix(Field::name());
    return props;
    
}

static QVariantMap createProps_flags()
{
    using Field = ublox::message::NavStatusFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "gpsFixOk")
            .add(1U, "diffSoln")
            .add(2U, "wknSet")
            .add(3U, "towSet")
            .asMap();
    
}

struct FixStatMembers
{
    static QVariantMap createProps_bits()
    {
        using Field = ublox::message::NavStatusFields<>::FixStatMembers::Bits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "diffCorr")
                .asMap();
        
    }
    
    static QVariantMap createProps_mapMatching()
    {
        using Field = ublox::message::NavStatusFields<>::FixStatMembers::MapMatching;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("none", 0)
                .add("not used", 1)
                .add("used", 2)
                .add("used + dead reckon", 3)
                .asMap();
        
    }
    
};

static QVariantMap createProps_fixStat()
{
    using Field = ublox::message::NavStatusFields<>::FixStat;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(FixStatMembers::createProps_bits())
            .add(FixStatMembers::createProps_mapMatching())
            .asMap();
    
}

struct Flags2Members
{
    static QVariantMap createProps_psmState()
    {
        using Field = ublox::message::NavStatusFields<>::Flags2Members::PsmState;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("ACQUISITION", 0)
                .add("TRAKING", 1)
                .add("POWER OPTIMIZED TRACKING", 2)
                .add("INACTIVE", 3)
                .asMap();
        
    }
    
    static QVariantMap createProps_res1()
    {
        using Field = ublox::message::NavStatusFields<>::Flags2Members::Res1;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .hidden()
                .asMap();
        
    }
    
    static QVariantMap createProps_spoofDetState()
    {
        using Field = ublox::message::NavStatusFields<>::Flags2Members::SpoofDetState;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("Unknown", 0)
                .add("No spoofing", 1)
                .add("Spoofing", 2)
                .add("Multiple spoofing", 3)
                .asMap();
        
    }
    
    static QVariantMap createProps_res2()
    {
        using Field = ublox::message::NavStatusFields<>::Flags2Members::Res2;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .hidden()
                .asMap();
        
    }
    
};

static QVariantMap createProps_flags2()
{
    using Field = ublox::message::NavStatusFields<>::Flags2;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(Flags2Members::createProps_psmState())
            .add(Flags2Members::createProps_res1())
            .add(Flags2Members::createProps_spoofDetState())
            .add(Flags2Members::createProps_res2())
            .asMap();
    
}

static QVariantMap createProps_ttff()
{
    using Field = ublox::message::NavStatusFields<>::Ttff;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_msss()
{
    using Field = ublox::message::NavStatusFields<>::Msss;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_itow());
    props.append(createProps_gpsFix());
    props.append(createProps_flags());
    props.append(createProps_fixStat());
    props.append(createProps_flags2());
    props.append(createProps_ttff());
    props.append(createProps_msss());
    return props;
}

} // namespace

class NavStatusImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavStatus<ublox::cc_plugin::Message>,
        NavStatusImpl
    >
{
public:
    NavStatusImpl() = default;
    NavStatusImpl(const NavStatusImpl&) = delete;
    NavStatusImpl(NavStatusImpl&&) = delete;
    virtual ~NavStatusImpl() = default;
    NavStatusImpl& operator=(const NavStatusImpl&) = default;
    NavStatusImpl& operator=(NavStatusImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavStatus::NavStatus() : m_pImpl(new NavStatusImpl) {}
NavStatus::~NavStatus() = default;

NavStatus& NavStatus::operator=(const NavStatus& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavStatus& NavStatus::operator=(NavStatus&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavStatus::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavStatus::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavStatus::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavStatus::resetImpl()
{
    m_pImpl->reset();
}

bool NavStatus::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavStatus*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavStatus::MsgIdParamType NavStatus::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavStatus::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavStatus::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavStatus::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavStatus::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavStatus::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


