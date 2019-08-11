#include "NavSvin.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavSvin.h"
#include "cc_plugin/field/Itow.h"
#include "cc_plugin/field/Res1.h"
#include "cc_plugin/field/Res2.h"
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
    using Field = ublox::message::NavSvinFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::NavSvinFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

static QVariantMap createProps_itow()
{
    using Field = ublox::message::NavSvinFields<>::Itow;
    auto props = cc_plugin::field::createProps_itow(Field::name());
    return props;
    
}

static QVariantMap createProps_dur()
{
    using Field = ublox::message::NavSvinFields<>::Dur;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_meanX()
{
    using Field = ublox::message::NavSvinFields<>::MeanX;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_meanY()
{
    using Field = ublox::message::NavSvinFields<>::MeanY;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_meanZ()
{
    using Field = ublox::message::NavSvinFields<>::MeanZ;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_meanXHP()
{
    using Field = ublox::message::NavSvinFields<>::MeanXHP;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

static QVariantMap createProps_meanYHP()
{
    using Field = ublox::message::NavSvinFields<>::MeanYHP;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

static QVariantMap createProps_meanZHP()
{
    using Field = ublox::message::NavSvinFields<>::MeanZHP;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::NavSvinFields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_meanAcc()
{
    using Field = ublox::message::NavSvinFields<>::MeanAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(1U)
            .asMap();
    
}

static QVariantMap createProps_obs()
{
    using Field = ublox::message::NavSvinFields<>::Obs;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_valid()
{
    using Field = ublox::message::NavSvinFields<>::Valid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_active()
{
    using Field = ublox::message::NavSvinFields<>::Active;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::NavSvinFields<>::Reserved3;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_itow());
    props.append(createProps_dur());
    props.append(createProps_meanX());
    props.append(createProps_meanY());
    props.append(createProps_meanZ());
    props.append(createProps_meanXHP());
    props.append(createProps_meanYHP());
    props.append(createProps_meanZHP());
    props.append(createProps_reserved2());
    props.append(createProps_meanAcc());
    props.append(createProps_obs());
    props.append(createProps_valid());
    props.append(createProps_active());
    props.append(createProps_reserved3());
    return props;
}

} // namespace

class NavSvinImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavSvin<ublox::cc_plugin::Message>,
        NavSvinImpl
    >
{
public:
    NavSvinImpl() = default;
    NavSvinImpl(const NavSvinImpl&) = delete;
    NavSvinImpl(NavSvinImpl&&) = delete;
    virtual ~NavSvinImpl() = default;
    NavSvinImpl& operator=(const NavSvinImpl&) = default;
    NavSvinImpl& operator=(NavSvinImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavSvin::NavSvin() : m_pImpl(new NavSvinImpl) {}
NavSvin::~NavSvin() = default;

NavSvin& NavSvin::operator=(const NavSvin& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavSvin& NavSvin::operator=(NavSvin&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavSvin::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavSvin::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavSvin::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavSvin::resetImpl()
{
    m_pImpl->reset();
}

bool NavSvin::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavSvin*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavSvin::MsgIdParamType NavSvin::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavSvin::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavSvin::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavSvin::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavSvin::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavSvin::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


