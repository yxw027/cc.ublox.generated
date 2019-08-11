#include "MonHw2.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MonHw2.h"
#include "cc_plugin/field/Res3.h"
#include "cc_plugin/field/Res4.h"
#include "cc_plugin/field/Res8.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_ofsI()
{
    using Field = ublox::message::MonHw2Fields<>::OfsI;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_magI()
{
    using Field = ublox::message::MonHw2Fields<>::MagI;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_ofsQ()
{
    using Field = ublox::message::MonHw2Fields<>::OfsQ;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_magQ()
{
    using Field = ublox::message::MonHw2Fields<>::MagQ;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cfgSource()
{
    using Field = ublox::message::MonHw2Fields<>::CfgSource;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("FlashImage", 102)
            .add("OTP", 111)
            .add("ConfigPins", 112)
            .add("ROM", 114)
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MonHw2Fields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

static QVariantMap createProps_lowLevCfg()
{
    using Field = ublox::message::MonHw2Fields<>::LowLevCfg;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::MonHw2Fields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res8(Field::name());
    return props;
    
}

static QVariantMap createProps_postStatus()
{
    using Field = ublox::message::MonHw2Fields<>::PostStatus;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::MonHw2Fields<>::Reserved3;
    auto props = cc_plugin::field::createProps_res4(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_ofsI());
    props.append(createProps_magI());
    props.append(createProps_ofsQ());
    props.append(createProps_magQ());
    props.append(createProps_cfgSource());
    props.append(createProps_reserved1());
    props.append(createProps_lowLevCfg());
    props.append(createProps_reserved2());
    props.append(createProps_postStatus());
    props.append(createProps_reserved3());
    return props;
}

} // namespace

class MonHw2Impl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MonHw2<ublox::cc_plugin::Message>,
        MonHw2Impl
    >
{
public:
    MonHw2Impl() = default;
    MonHw2Impl(const MonHw2Impl&) = delete;
    MonHw2Impl(MonHw2Impl&&) = delete;
    virtual ~MonHw2Impl() = default;
    MonHw2Impl& operator=(const MonHw2Impl&) = default;
    MonHw2Impl& operator=(MonHw2Impl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MonHw2::MonHw2() : m_pImpl(new MonHw2Impl) {}
MonHw2::~MonHw2() = default;

MonHw2& MonHw2::operator=(const MonHw2& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MonHw2& MonHw2::operator=(MonHw2&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MonHw2::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MonHw2::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MonHw2::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MonHw2::resetImpl()
{
    m_pImpl->reset();
}

bool MonHw2::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MonHw2*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MonHw2::MsgIdParamType MonHw2::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MonHw2::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MonHw2::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MonHw2::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MonHw2::lengthImpl() const
{
    return m_pImpl->length();
}

bool MonHw2::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


