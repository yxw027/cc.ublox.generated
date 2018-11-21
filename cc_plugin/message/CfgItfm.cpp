#include "CfgItfm.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgItfm.h"
namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

struct ConfigMembers
{
    static QVariantMap createProps_bbThreshold()
    {
        using Field = ublox::message::CfgItfmFields<>::ConfigMembers::BbThreshold;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .asMap();
        
    }
    
    static QVariantMap createProps_cwThreshold()
    {
        using Field = ublox::message::CfgItfmFields<>::ConfigMembers::CwThreshold;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .asMap();
        
    }
    
    static QVariantMap createProps_algorithmBits()
    {
        using Field = ublox::message::CfgItfmFields<>::ConfigMembers::AlgorithmBits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .asMap();
        
    }
    
    static QVariantMap createProps_bits()
    {
        using Field = ublox::message::CfgItfmFields<>::ConfigMembers::Bits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "enable")
                .asMap();
        
    }
    
};

static QVariantMap createProps_config()
{
    using Field = ublox::message::CfgItfmFields<>::Config;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ConfigMembers::createProps_bbThreshold())
            .add(ConfigMembers::createProps_cwThreshold())
            .add(ConfigMembers::createProps_algorithmBits())
            .add(ConfigMembers::createProps_bits())
            .asMap();
    
}

struct Config2Members
{
    static QVariantMap createProps_generalBits()
    {
        using Field = ublox::message::CfgItfmFields<>::Config2Members::GeneralBits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .asMap();
        
    }
    
    static QVariantMap createProps_antSetting()
    {
        using Field = ublox::message::CfgItfmFields<>::Config2Members::AntSetting;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("Unknown", 0)
                .add("Passive", 1)
                .add("Active", 2)
                .asMap();
        
    }
    
    static QVariantMap createProps_bitsHigh()
    {
        using Field = ublox::message::CfgItfmFields<>::Config2Members::BitsHigh;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "enable2")
                .asMap();
        
    }
    
};

static QVariantMap createProps_config2()
{
    using Field = ublox::message::CfgItfmFields<>::Config2;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(Config2Members::createProps_generalBits())
            .add(Config2Members::createProps_antSetting())
            .add(Config2Members::createProps_bitsHigh())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_config());
    props.append(createProps_config2());
    return props;
}

} // namespace

class CfgItfmImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgItfm<ublox::cc_plugin::Message>,
        CfgItfmImpl
    >
{
public:
    CfgItfmImpl() = default;
    CfgItfmImpl(const CfgItfmImpl&) = delete;
    CfgItfmImpl(CfgItfmImpl&&) = delete;
    virtual ~CfgItfmImpl() = default;
    CfgItfmImpl& operator=(const CfgItfmImpl&) = default;
    CfgItfmImpl& operator=(CfgItfmImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgItfm::CfgItfm() : m_pImpl(new CfgItfmImpl) {}
CfgItfm::~CfgItfm() = default;

CfgItfm& CfgItfm::operator=(const CfgItfm& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgItfm& CfgItfm::operator=(CfgItfm&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgItfm::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgItfm::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgItfm::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgItfm::resetImpl()
{
    m_pImpl->reset();
}

bool CfgItfm::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgItfm*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgItfm::MsgIdParamType CfgItfm::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgItfm::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgItfm::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgItfm::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgItfm::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgItfm::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

