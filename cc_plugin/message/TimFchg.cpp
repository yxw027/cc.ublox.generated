// Generated by commsdsl2comms v3.3.1

#include "TimFchg.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/TimFchg.h"
#include "cc_plugin/field/Itow.h"
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
    using Field = ublox::message::TimFchgFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::TimFchgFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

static QVariantMap createProps_itow()
{
    using Field = ublox::message::TimFchgFields<>::Itow;
    auto props = cc_plugin::field::createProps_itow(Field::name());
    return props;
    
}

static QVariantMap createProps_intDeltaFreq()
{
    using Field = ublox::message::TimFchgFields<>::IntDeltaFreq;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(8U)
            .asMap();
    
}

static QVariantMap createProps_intDeltaFreqUnc()
{
    using Field = ublox::message::TimFchgFields<>::IntDeltaFreqUnc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(8U)
            .asMap();
    
}

static QVariantMap createProps_intRaw()
{
    using Field = ublox::message::TimFchgFields<>::IntRaw;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_extDeltaFreq()
{
    using Field = ublox::message::TimFchgFields<>::ExtDeltaFreq;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(8U)
            .asMap();
    
}

static QVariantMap createProps_extDeltaFreqUnc()
{
    using Field = ublox::message::TimFchgFields<>::ExtDeltaFreqUnc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(8U)
            .asMap();
    
}

static QVariantMap createProps_extRaw()
{
    using Field = ublox::message::TimFchgFields<>::ExtRaw;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_itow());
    props.append(createProps_intDeltaFreq());
    props.append(createProps_intDeltaFreqUnc());
    props.append(createProps_intRaw());
    props.append(createProps_extDeltaFreq());
    props.append(createProps_extDeltaFreqUnc());
    props.append(createProps_extRaw());
    return props;
}

} // namespace

class TimFchgImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::TimFchg<ublox::cc_plugin::Message>,
        TimFchgImpl
    >
{
public:
    TimFchgImpl() = default;
    TimFchgImpl(const TimFchgImpl&) = delete;
    TimFchgImpl(TimFchgImpl&&) = delete;
    virtual ~TimFchgImpl() = default;
    TimFchgImpl& operator=(const TimFchgImpl&) = default;
    TimFchgImpl& operator=(TimFchgImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

TimFchg::TimFchg() : m_pImpl(new TimFchgImpl) {}
TimFchg::~TimFchg() = default;

TimFchg& TimFchg::operator=(const TimFchg& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

TimFchg& TimFchg::operator=(TimFchg&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* TimFchg::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& TimFchg::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void TimFchg::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void TimFchg::resetImpl()
{
    m_pImpl->reset();
}

bool TimFchg::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const TimFchg*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

TimFchg::MsgIdParamType TimFchg::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus TimFchg::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus TimFchg::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool TimFchg::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t TimFchg::lengthImpl() const
{
    return m_pImpl->length();
}

bool TimFchg::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


