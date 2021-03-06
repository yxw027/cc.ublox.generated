// Generated by commsdsl2comms v3.3.2

#include "CfgTp.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgTp.h"
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

static QVariantMap createProps_interval()
{
    using Field = ublox::message::CfgTpFields<>::Interval;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_length()
{
    using Field = ublox::message::CfgTpFields<>::Length;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_status()
{
    using Field = ublox::message::CfgTpFields<>::Status;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("Negative", -1)
            .add("Off", 0)
            .add("Positive", 1)
            .asMap();
    
}

static QVariantMap createProps_timeRef()
{
    using Field = ublox::message::CfgTpFields<>::TimeRef;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("UTC", 0)
            .add("GPS", 1)
            .add("Local", 2)
            .asMap();
    
}

static QVariantMap createProps_flags()
{
    using Field = ublox::message::CfgTpFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "syncMode")
            .asMap();
    
}

static QVariantMap createProps_res()
{
    using Field = ublox::message::CfgTpFields<>::Res;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_antennaCableDelay()
{
    using Field = ublox::message::CfgTpFields<>::AntennaCableDelay;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_rfGroupDelay()
{
    using Field = ublox::message::CfgTpFields<>::RfGroupDelay;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_userDelay()
{
    using Field = ublox::message::CfgTpFields<>::UserDelay;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_interval());
    props.append(createProps_length());
    props.append(createProps_status());
    props.append(createProps_timeRef());
    props.append(createProps_flags());
    props.append(createProps_res());
    props.append(createProps_antennaCableDelay());
    props.append(createProps_rfGroupDelay());
    props.append(createProps_userDelay());
    return props;
}

} // namespace

class CfgTpImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgTp<ublox::cc_plugin::Message>,
        CfgTpImpl
    >
{
public:
    CfgTpImpl() = default;
    CfgTpImpl(const CfgTpImpl&) = delete;
    CfgTpImpl(CfgTpImpl&&) = delete;
    virtual ~CfgTpImpl() = default;
    CfgTpImpl& operator=(const CfgTpImpl&) = default;
    CfgTpImpl& operator=(CfgTpImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgTp::CfgTp() : m_pImpl(new CfgTpImpl) {}
CfgTp::~CfgTp() = default;

CfgTp& CfgTp::operator=(const CfgTp& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgTp& CfgTp::operator=(CfgTp&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgTp::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgTp::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgTp::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgTp::resetImpl()
{
    m_pImpl->reset();
}

bool CfgTp::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgTp*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgTp::MsgIdParamType CfgTp::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgTp::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgTp::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgTp::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgTp::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgTp::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


