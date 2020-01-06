// Generated by commsdsl2comms v3.3.0

#include "NavHpposllh.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavHpposllh.h"
#include "cc_plugin/field/HMSL.h"
#include "cc_plugin/field/Height.h"
#include "cc_plugin/field/Itow.h"
#include "cc_plugin/field/Lat.h"
#include "cc_plugin/field/Lon.h"
#include "cc_plugin/field/Res3.h"

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
    using Field = ublox::message::NavHpposllhFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::NavHpposllhFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

static QVariantMap createProps_itow()
{
    using Field = ublox::message::NavHpposllhFields<>::Itow;
    auto props = cc_plugin::field::createProps_itow(Field::name());
    return props;
    
}

static QVariantMap createProps_lon()
{
    using Field = ublox::message::NavHpposllhFields<>::Lon;
    auto props = cc_plugin::field::createProps_lon(Field::name());
    return props;
    
}

static QVariantMap createProps_lat()
{
    using Field = ublox::message::NavHpposllhFields<>::Lat;
    auto props = cc_plugin::field::createProps_lat(Field::name());
    return props;
    
}

static QVariantMap createProps_height()
{
    using Field = ublox::message::NavHpposllhFields<>::Height;
    auto props = cc_plugin::field::createProps_height(Field::name());
    return props;
    
}

static QVariantMap createProps_hMSL()
{
    using Field = ublox::message::NavHpposllhFields<>::HMSL;
    auto props = cc_plugin::field::createProps_hMSL(Field::name());
    return props;
    
}

static QVariantMap createProps_lonHp()
{
    using Field = ublox::message::NavHpposllhFields<>::LonHp;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(9U)
            .asMap();
    
}

static QVariantMap createProps_latHp()
{
    using Field = ublox::message::NavHpposllhFields<>::LatHp;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(9U)
            .asMap();
    
}

static QVariantMap createProps_heigthHp()
{
    using Field = ublox::message::NavHpposllhFields<>::HeigthHp;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

static QVariantMap createProps_hMSLHp()
{
    using Field = ublox::message::NavHpposllhFields<>::HMSLHp;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

static QVariantMap createProps_hAcc()
{
    using Field = ublox::message::NavHpposllhFields<>::HAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

static QVariantMap createProps_vAcc()
{
    using Field = ublox::message::NavHpposllhFields<>::VAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_itow());
    props.append(createProps_lon());
    props.append(createProps_lat());
    props.append(createProps_height());
    props.append(createProps_hMSL());
    props.append(createProps_lonHp());
    props.append(createProps_latHp());
    props.append(createProps_heigthHp());
    props.append(createProps_hMSLHp());
    props.append(createProps_hAcc());
    props.append(createProps_vAcc());
    return props;
}

} // namespace

class NavHpposllhImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavHpposllh<ublox::cc_plugin::Message>,
        NavHpposllhImpl
    >
{
public:
    NavHpposllhImpl() = default;
    NavHpposllhImpl(const NavHpposllhImpl&) = delete;
    NavHpposllhImpl(NavHpposllhImpl&&) = delete;
    virtual ~NavHpposllhImpl() = default;
    NavHpposllhImpl& operator=(const NavHpposllhImpl&) = default;
    NavHpposllhImpl& operator=(NavHpposllhImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavHpposllh::NavHpposllh() : m_pImpl(new NavHpposllhImpl) {}
NavHpposllh::~NavHpposllh() = default;

NavHpposllh& NavHpposllh::operator=(const NavHpposllh& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavHpposllh& NavHpposllh::operator=(NavHpposllh&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavHpposllh::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavHpposllh::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavHpposllh::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavHpposllh::resetImpl()
{
    m_pImpl->reset();
}

bool NavHpposllh::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavHpposllh*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavHpposllh::MsgIdParamType NavHpposllh::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavHpposllh::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavHpposllh::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavHpposllh::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavHpposllh::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavHpposllh::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


