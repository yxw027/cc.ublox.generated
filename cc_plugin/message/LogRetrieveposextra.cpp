#include "LogRetrieveposextra.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/LogRetrieveposextra.h"
#include "cc_plugin/field/Day.h"
#include "cc_plugin/field/Hour.h"
#include "cc_plugin/field/Min.h"
#include "cc_plugin/field/Month.h"
#include "cc_plugin/field/Res1.h"
#include "cc_plugin/field/Res3.h"
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

static QVariantMap createProps_entryIndex()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::EntryIndex;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Reserved1;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

static QVariantMap createProps_year()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Year;
    return cc_plugin::field::createProps_year(Field::name());
    
}

static QVariantMap createProps_month()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Month;
    return cc_plugin::field::createProps_month(Field::name());
    
}

static QVariantMap createProps_day()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Day;
    return cc_plugin::field::createProps_day(Field::name());
    
}

static QVariantMap createProps_hour()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Hour;
    return cc_plugin::field::createProps_hour(Field::name());
    
}

static QVariantMap createProps_minute()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Minute;
    return cc_plugin::field::createProps_min(Field::name());
    
}

static QVariantMap createProps_second()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Second;
    return cc_plugin::field::createProps_sec(Field::name());
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Reserved2;
    return cc_plugin::field::createProps_res3(Field::name());
    
}

static QVariantMap createProps_distance()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Distance;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

struct Reserved3Members
{
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::LogRetrieveposextraFields<>::Reserved3Members::Element;
        return cc_plugin::field::createProps_res1(Field::name());
        
    }
    
};

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::LogRetrieveposextraFields<>::Reserved3;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(Reserved3Members::createProps_element())
            .serialisedHidden()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_entryIndex());
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_year());
    props.append(createProps_month());
    props.append(createProps_day());
    props.append(createProps_hour());
    props.append(createProps_minute());
    props.append(createProps_second());
    props.append(createProps_reserved2());
    props.append(createProps_distance());
    props.append(createProps_reserved3());
    return props;
}

} // namespace

class LogRetrieveposextraImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::LogRetrieveposextra<ublox::cc_plugin::Message>,
        LogRetrieveposextraImpl
    >
{
public:
    LogRetrieveposextraImpl() = default;
    LogRetrieveposextraImpl(const LogRetrieveposextraImpl&) = delete;
    LogRetrieveposextraImpl(LogRetrieveposextraImpl&&) = delete;
    virtual ~LogRetrieveposextraImpl() = default;
    LogRetrieveposextraImpl& operator=(const LogRetrieveposextraImpl&) = default;
    LogRetrieveposextraImpl& operator=(LogRetrieveposextraImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

LogRetrieveposextra::LogRetrieveposextra() : m_pImpl(new LogRetrieveposextraImpl) {}
LogRetrieveposextra::~LogRetrieveposextra() = default;

LogRetrieveposextra& LogRetrieveposextra::operator=(const LogRetrieveposextra& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

LogRetrieveposextra& LogRetrieveposextra::operator=(LogRetrieveposextra&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* LogRetrieveposextra::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& LogRetrieveposextra::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void LogRetrieveposextra::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void LogRetrieveposextra::resetImpl()
{
    m_pImpl->reset();
}

bool LogRetrieveposextra::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const LogRetrieveposextra*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

LogRetrieveposextra::MsgIdParamType LogRetrieveposextra::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus LogRetrieveposextra::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus LogRetrieveposextra::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool LogRetrieveposextra::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t LogRetrieveposextra::lengthImpl() const
{
    return m_pImpl->length();
}

bool LogRetrieveposextra::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

