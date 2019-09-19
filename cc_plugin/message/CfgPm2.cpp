#include "CfgPm2.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgPm2.h"
#include "cc_plugin/field/CfgPm2Flags.h"
#include "cc_plugin/field/Res1.h"
#include "cc_plugin/field/Res4.h"

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
    using Field = ublox::message::CfgPm2Fields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::CfgPm2Fields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_maxStartupStateDur()
{
    using Field = ublox::message::CfgPm2Fields<>::MaxStartupStateDur;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::CfgPm2Fields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_flags()
{
    using Field = ublox::message::CfgPm2Fields<>::Flags;
    auto props = cc_plugin::field::createProps_cfgPm2Flags(Field::name());
    return props;
    
}

static QVariantMap createProps_updatePeriod()
{
    using Field = ublox::message::CfgPm2Fields<>::UpdatePeriod;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_searchPeriod()
{
    using Field = ublox::message::CfgPm2Fields<>::SearchPeriod;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_gridOffset()
{
    using Field = ublox::message::CfgPm2Fields<>::GridOffset;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_onTime()
{
    using Field = ublox::message::CfgPm2Fields<>::OnTime;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_minAcqTime()
{
    using Field = ublox::message::CfgPm2Fields<>::MinAcqTime;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

struct Reserved3Members
{
    static QVariantMap createProps_reserved3()
    {
        using Field = ublox::message::CfgPm2Fields<>::Reserved3Members::Reserved3;
        auto props = cc_plugin::field::createProps_res4(Field::name());
        return props;
        
    }
    
};

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::CfgPm2Fields<>::Reserved3;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(Reserved3Members::createProps_reserved3())
            .serialisedHidden()
            .appendIndexToElementName()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_maxStartupStateDur());
    props.append(createProps_reserved2());
    props.append(createProps_flags());
    props.append(createProps_updatePeriod());
    props.append(createProps_searchPeriod());
    props.append(createProps_gridOffset());
    props.append(createProps_onTime());
    props.append(createProps_minAcqTime());
    props.append(createProps_reserved3());
    return props;
}

} // namespace

class CfgPm2Impl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgPm2<ublox::cc_plugin::Message>,
        CfgPm2Impl
    >
{
public:
    CfgPm2Impl() = default;
    CfgPm2Impl(const CfgPm2Impl&) = delete;
    CfgPm2Impl(CfgPm2Impl&&) = delete;
    virtual ~CfgPm2Impl() = default;
    CfgPm2Impl& operator=(const CfgPm2Impl&) = default;
    CfgPm2Impl& operator=(CfgPm2Impl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgPm2::CfgPm2() : m_pImpl(new CfgPm2Impl) {}
CfgPm2::~CfgPm2() = default;

CfgPm2& CfgPm2::operator=(const CfgPm2& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgPm2& CfgPm2::operator=(CfgPm2&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgPm2::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgPm2::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgPm2::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgPm2::resetImpl()
{
    m_pImpl->reset();
}

bool CfgPm2::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgPm2*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgPm2::MsgIdParamType CfgPm2::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgPm2::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgPm2::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgPm2::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgPm2::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgPm2::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


