#include "LogFindtimeResp.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/LogFindtimeResp.h"
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

static QVariantMap createProps_version()
{
    using Field = ublox::message::LogFindtimeRespFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_type()
{
    using Field = ublox::message::LogFindtimeRespFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::LogFindtimeRespFields<>::Reserved1;
    return cc_plugin::field::createProps_res2(Field::name());
    
}

static QVariantMap createProps_entryNumber()
{
    using Field = ublox::message::LogFindtimeRespFields<>::EntryNumber;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_type());
    props.append(createProps_reserved1());
    props.append(createProps_entryNumber());
    return props;
}

} // namespace

class LogFindtimeRespImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::LogFindtimeResp<ublox::cc_plugin::Message>,
        LogFindtimeRespImpl
    >
{
public:
    LogFindtimeRespImpl() = default;
    LogFindtimeRespImpl(const LogFindtimeRespImpl&) = delete;
    LogFindtimeRespImpl(LogFindtimeRespImpl&&) = delete;
    virtual ~LogFindtimeRespImpl() = default;
    LogFindtimeRespImpl& operator=(const LogFindtimeRespImpl&) = default;
    LogFindtimeRespImpl& operator=(LogFindtimeRespImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

LogFindtimeResp::LogFindtimeResp() : m_pImpl(new LogFindtimeRespImpl) {}
LogFindtimeResp::~LogFindtimeResp() = default;

LogFindtimeResp& LogFindtimeResp::operator=(const LogFindtimeResp& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

LogFindtimeResp& LogFindtimeResp::operator=(LogFindtimeResp&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* LogFindtimeResp::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& LogFindtimeResp::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void LogFindtimeResp::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void LogFindtimeResp::resetImpl()
{
    m_pImpl->reset();
}

bool LogFindtimeResp::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const LogFindtimeResp*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

LogFindtimeResp::MsgIdParamType LogFindtimeResp::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus LogFindtimeResp::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus LogFindtimeResp::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool LogFindtimeResp::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t LogFindtimeResp::lengthImpl() const
{
    return m_pImpl->length();
}

bool LogFindtimeResp::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

