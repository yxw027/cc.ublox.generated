#include "TimVcocalExt.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/TimVcocalExt.h"
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

static QVariantMap createProps_type()
{
    using Field = ublox::message::TimVcocalExtFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::TimVcocalExtFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_oscId()
{
    using Field = ublox::message::TimVcocalExtFields<>::OscId;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("Internal", 0)
            .add("External", 1)
            .asMap();
    
}

static QVariantMap createProps_srcId()
{
    using Field = ublox::message::TimVcocalExtFields<>::SrcId;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("Internal", 0)
            .add("GNSS", 1)
            .add("EXTINT0", 2)
            .add("EXTINT1", 3)
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::TimVcocalExtFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_raw0()
{
    using Field = ublox::message::TimVcocalExtFields<>::Raw0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_raw1()
{
    using Field = ublox::message::TimVcocalExtFields<>::Raw1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_maxStepSize()
{
    using Field = ublox::message::TimVcocalExtFields<>::MaxStepSize;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_type());
    props.append(createProps_version());
    props.append(createProps_oscId());
    props.append(createProps_srcId());
    props.append(createProps_reserved1());
    props.append(createProps_raw0());
    props.append(createProps_raw1());
    props.append(createProps_maxStepSize());
    return props;
}

} // namespace

class TimVcocalExtImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::TimVcocalExt<ublox::cc_plugin::Message>,
        TimVcocalExtImpl
    >
{
public:
    TimVcocalExtImpl() = default;
    TimVcocalExtImpl(const TimVcocalExtImpl&) = delete;
    TimVcocalExtImpl(TimVcocalExtImpl&&) = delete;
    virtual ~TimVcocalExtImpl() = default;
    TimVcocalExtImpl& operator=(const TimVcocalExtImpl&) = default;
    TimVcocalExtImpl& operator=(TimVcocalExtImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

TimVcocalExt::TimVcocalExt() : m_pImpl(new TimVcocalExtImpl) {}
TimVcocalExt::~TimVcocalExt() = default;

TimVcocalExt& TimVcocalExt::operator=(const TimVcocalExt& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

TimVcocalExt& TimVcocalExt::operator=(TimVcocalExt&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* TimVcocalExt::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& TimVcocalExt::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void TimVcocalExt::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void TimVcocalExt::resetImpl()
{
    m_pImpl->reset();
}

bool TimVcocalExt::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const TimVcocalExt*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

TimVcocalExt::MsgIdParamType TimVcocalExt::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus TimVcocalExt::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus TimVcocalExt::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool TimVcocalExt::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t TimVcocalExt::lengthImpl() const
{
    return m_pImpl->length();
}

bool TimVcocalExt::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


