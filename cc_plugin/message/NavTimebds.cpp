// Generated by commsdsl2comms v3.3.2

#include "NavTimebds.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/NavTimebds.h"
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
    using Field = ublox::message::NavTimebdsFields<>::Itow;
    auto props = cc_plugin::field::createProps_itow(Field::name());
    return props;
    
}

static QVariantMap createProps_sOW()
{
    using Field = ublox::message::NavTimebdsFields<>::SOW;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_fSOW()
{
    using Field = ublox::message::NavTimebdsFields<>::FSOW;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_week()
{
    using Field = ublox::message::NavTimebdsFields<>::Week;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_leapS()
{
    using Field = ublox::message::NavTimebdsFields<>::LeapS;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_valid()
{
    using Field = ublox::message::NavTimebdsFields<>::Valid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "sowValid")
            .add(1U, "weekValid")
            .add(2U, "leapSValid")
            .asMap();
    
}

static QVariantMap createProps_tAcc()
{
    using Field = ublox::message::NavTimebdsFields<>::TAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_itow());
    props.append(createProps_sOW());
    props.append(createProps_fSOW());
    props.append(createProps_week());
    props.append(createProps_leapS());
    props.append(createProps_valid());
    props.append(createProps_tAcc());
    return props;
}

} // namespace

class NavTimebdsImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::NavTimebds<ublox::cc_plugin::Message>,
        NavTimebdsImpl
    >
{
public:
    NavTimebdsImpl() = default;
    NavTimebdsImpl(const NavTimebdsImpl&) = delete;
    NavTimebdsImpl(NavTimebdsImpl&&) = delete;
    virtual ~NavTimebdsImpl() = default;
    NavTimebdsImpl& operator=(const NavTimebdsImpl&) = default;
    NavTimebdsImpl& operator=(NavTimebdsImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

NavTimebds::NavTimebds() : m_pImpl(new NavTimebdsImpl) {}
NavTimebds::~NavTimebds() = default;

NavTimebds& NavTimebds::operator=(const NavTimebds& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

NavTimebds& NavTimebds::operator=(NavTimebds&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* NavTimebds::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& NavTimebds::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void NavTimebds::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void NavTimebds::resetImpl()
{
    m_pImpl->reset();
}

bool NavTimebds::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const NavTimebds*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

NavTimebds::MsgIdParamType NavTimebds::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus NavTimebds::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus NavTimebds::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool NavTimebds::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t NavTimebds::lengthImpl() const
{
    return m_pImpl->length();
}

bool NavTimebds::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


