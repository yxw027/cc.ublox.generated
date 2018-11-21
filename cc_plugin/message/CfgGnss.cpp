#include "CfgGnss.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgGnss.h"
#include "cc_plugin/field/GnssId.h"
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

static QVariantMap createProps_msgVer()
{
    using Field = ublox::message::CfgGnssFields<>::MsgVer;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_numTrkChHw()
{
    using Field = ublox::message::CfgGnssFields<>::NumTrkChHw;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_numTrkChUse()
{
    using Field = ublox::message::CfgGnssFields<>::NumTrkChUse;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_numConfigBlocks()
{
    using Field = ublox::message::CfgGnssFields<>::NumConfigBlocks;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

struct ListMembers
{
    struct ElementMembers
    {
        static QVariantMap createProps_gnssId()
        {
            using Field = ublox::message::CfgGnssFields<>::ListMembers::ElementMembers::GnssId;
            return cc_plugin::field::createProps_gnssId(Field::name());
            
        }
        
        static QVariantMap createProps_resTrkCh()
        {
            using Field = ublox::message::CfgGnssFields<>::ListMembers::ElementMembers::ResTrkCh;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_maxTrkCh()
        {
            using Field = ublox::message::CfgGnssFields<>::ListMembers::ElementMembers::MaxTrkCh;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_reserved1()
        {
            using Field = ublox::message::CfgGnssFields<>::ListMembers::ElementMembers::Reserved1;
            return cc_plugin::field::createProps_res1(Field::name());
            
        }
        
        struct FlagsMembers
        {
            static QVariantMap createProps_bitsLow()
            {
                using Field = ublox::message::CfgGnssFields<>::ListMembers::ElementMembers::FlagsMembers::BitsLow;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add(0U, "enable")
                        .asMap();
                
            }
            
            static QVariantMap createProps_sigCfgMask()
            {
                using Field = ublox::message::CfgGnssFields<>::ListMembers::ElementMembers::FlagsMembers::SigCfgMask;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .asMap();
                
            }
            
            static QVariantMap createProps_reserved()
            {
                using Field = ublox::message::CfgGnssFields<>::ListMembers::ElementMembers::FlagsMembers::Reserved;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .hidden()
                        .asMap();
                
            }
            
        };
        
        static QVariantMap createProps_flags()
        {
            using Field = ublox::message::CfgGnssFields<>::ListMembers::ElementMembers::Flags;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add(FlagsMembers::createProps_bitsLow())
                    .add(FlagsMembers::createProps_sigCfgMask())
                    .add(FlagsMembers::createProps_reserved())
                    .asMap();
            
        }
        
    };
    
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::CfgGnssFields<>::ListMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ElementMembers::createProps_gnssId())
                .add(ElementMembers::createProps_resTrkCh())
                .add(ElementMembers::createProps_maxTrkCh())
                .add(ElementMembers::createProps_reserved1())
                .add(ElementMembers::createProps_flags())
                .asMap();
        
    }
    
};

static QVariantMap createProps_list()
{
    using Field = ublox::message::CfgGnssFields<>::List;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ListMembers::createProps_element())
            .serialisedHidden()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_msgVer());
    props.append(createProps_numTrkChHw());
    props.append(createProps_numTrkChUse());
    props.append(createProps_numConfigBlocks());
    props.append(createProps_list());
    return props;
}

} // namespace

class CfgGnssImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgGnss<ublox::cc_plugin::Message>,
        CfgGnssImpl
    >
{
public:
    CfgGnssImpl() = default;
    CfgGnssImpl(const CfgGnssImpl&) = delete;
    CfgGnssImpl(CfgGnssImpl&&) = delete;
    virtual ~CfgGnssImpl() = default;
    CfgGnssImpl& operator=(const CfgGnssImpl&) = default;
    CfgGnssImpl& operator=(CfgGnssImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgGnss::CfgGnss() : m_pImpl(new CfgGnssImpl) {}
CfgGnss::~CfgGnss() = default;

CfgGnss& CfgGnss::operator=(const CfgGnss& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgGnss& CfgGnss::operator=(CfgGnss&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgGnss::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgGnss::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgGnss::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgGnss::resetImpl()
{
    m_pImpl->reset();
}

bool CfgGnss::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgGnss*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgGnss::MsgIdParamType CfgGnss::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgGnss::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgGnss::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgGnss::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgGnss::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgGnss::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

