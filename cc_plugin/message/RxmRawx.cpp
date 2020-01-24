// Generated by commsdsl2comms v3.3.1

#include "RxmRawx.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/RxmRawx.h"
#include "cc_plugin/field/GnssId.h"
#include "cc_plugin/field/Res1.h"
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

static QVariantMap createProps_rcvTow()
{
    using Field = ublox::message::RxmRawxFields<>::RcvTow;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_week()
{
    using Field = ublox::message::RxmRawxFields<>::Week;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_leapS()
{
    using Field = ublox::message::RxmRawxFields<>::LeapS;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_numMeas()
{
    using Field = ublox::message::RxmRawxFields<>::NumMeas;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_recStat()
{
    using Field = ublox::message::RxmRawxFields<>::RecStat;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "leapSec")
            .add(1U, "clkReset")
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::RxmRawxFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::RxmRawxFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

struct ListMembers
{
    struct ElementMembers
    {
        static QVariantMap createProps_prMes()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::PrMes;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_cpMes()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::CpMes;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_doMes()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::DoMes;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_gnssId()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::GnssId;
            auto props = cc_plugin::field::createProps_gnssId(Field::name());
            return props;
            
        }
        
        static QVariantMap createProps_svid()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::Svid;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_reserved2()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::Reserved2;
            auto props = cc_plugin::field::createProps_res1(Field::name());
            return props;
            
        }
        
        static QVariantMap createProps_freqId()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::FreqId;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_locktime()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::Locktime;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_cno()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::Cno;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_prStdev()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::PrStdev;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_cpStdev()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::CpStdev;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(3U)
                    .asMap();
            
        }
        
        static QVariantMap createProps_doStdev()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::DoStdev;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_trkStat()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::TrkStat;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add(0U, "prValid")
                    .add(1U, "cpValid")
                    .add(2U, "halfCyc")
                    .add(3U, "subHalfCyc")
                    .asMap();
            
        }
        
        static QVariantMap createProps_reserved3()
        {
            using Field = ublox::message::RxmRawxFields<>::ListMembers::ElementMembers::Reserved3;
            auto props = cc_plugin::field::createProps_res1(Field::name());
            return props;
            
        }
        
    };
    
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::RxmRawxFields<>::ListMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ElementMembers::createProps_prMes())
                .add(ElementMembers::createProps_cpMes())
                .add(ElementMembers::createProps_doMes())
                .add(ElementMembers::createProps_gnssId())
                .add(ElementMembers::createProps_svid())
                .add(ElementMembers::createProps_reserved2())
                .add(ElementMembers::createProps_freqId())
                .add(ElementMembers::createProps_locktime())
                .add(ElementMembers::createProps_cno())
                .add(ElementMembers::createProps_prStdev())
                .add(ElementMembers::createProps_cpStdev())
                .add(ElementMembers::createProps_doStdev())
                .add(ElementMembers::createProps_trkStat())
                .add(ElementMembers::createProps_reserved3())
                .asMap();
        
    }
    
};

static QVariantMap createProps_list()
{
    using Field = ublox::message::RxmRawxFields<>::List;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ListMembers::createProps_element())
            .serialisedHidden()
            .appendIndexToElementName()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_rcvTow());
    props.append(createProps_week());
    props.append(createProps_leapS());
    props.append(createProps_numMeas());
    props.append(createProps_recStat());
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_list());
    return props;
}

} // namespace

class RxmRawxImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::RxmRawx<ublox::cc_plugin::Message>,
        RxmRawxImpl
    >
{
public:
    RxmRawxImpl() = default;
    RxmRawxImpl(const RxmRawxImpl&) = delete;
    RxmRawxImpl(RxmRawxImpl&&) = delete;
    virtual ~RxmRawxImpl() = default;
    RxmRawxImpl& operator=(const RxmRawxImpl&) = default;
    RxmRawxImpl& operator=(RxmRawxImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

RxmRawx::RxmRawx() : m_pImpl(new RxmRawxImpl) {}
RxmRawx::~RxmRawx() = default;

RxmRawx& RxmRawx::operator=(const RxmRawx& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

RxmRawx& RxmRawx::operator=(RxmRawx&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* RxmRawx::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& RxmRawx::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void RxmRawx::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void RxmRawx::resetImpl()
{
    m_pImpl->reset();
}

bool RxmRawx::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const RxmRawx*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

RxmRawx::MsgIdParamType RxmRawx::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus RxmRawx::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus RxmRawx::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool RxmRawx::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t RxmRawx::lengthImpl() const
{
    return m_pImpl->length();
}

bool RxmRawx::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


