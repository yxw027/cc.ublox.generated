#include "LogCreate.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/LogCreate.h"
#include "cc_plugin/field/Res1.h"

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
    using Field = ublox::message::LogCreateFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_logCfg()
{
    using Field = ublox::message::LogCreateFields<>::LogCfg;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "logCfg")
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::LogCreateFields<>::Reserved1;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

static QVariantMap createProps_logSize()
{
    using Field = ublox::message::LogCreateFields<>::LogSize;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("Maximum", 0)
            .add("Minimum", 1)
            .add("UserDefined", 2)
            .asMap();
    
}

static QVariantMap createProps_userDefinedSize()
{
    using Field = ublox::message::LogCreateFields<>::UserDefinedSize;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_logCfg());
    props.append(createProps_reserved1());
    props.append(createProps_logSize());
    props.append(createProps_userDefinedSize());
    return props;
}

} // namespace

class LogCreateImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::LogCreate<ublox::cc_plugin::Message>,
        LogCreateImpl
    >
{
public:
    LogCreateImpl() = default;
    LogCreateImpl(const LogCreateImpl&) = delete;
    LogCreateImpl(LogCreateImpl&&) = delete;
    virtual ~LogCreateImpl() = default;
    LogCreateImpl& operator=(const LogCreateImpl&) = default;
    LogCreateImpl& operator=(LogCreateImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

LogCreate::LogCreate() : m_pImpl(new LogCreateImpl) {}
LogCreate::~LogCreate() = default;

LogCreate& LogCreate::operator=(const LogCreate& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

LogCreate& LogCreate::operator=(LogCreate&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* LogCreate::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& LogCreate::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void LogCreate::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void LogCreate::resetImpl()
{
    m_pImpl->reset();
}

bool LogCreate::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const LogCreate*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

LogCreate::MsgIdParamType LogCreate::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus LogCreate::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus LogCreate::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool LogCreate::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t LogCreate::lengthImpl() const
{
    return m_pImpl->length();
}

bool LogCreate::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

