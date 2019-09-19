#include "RxmMeasx.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/RxmMeasx.h"
#include "cc_plugin/field/GnssId.h"
#include "cc_plugin/field/Res2.h"
#include "cc_plugin/field/Res3.h"
#include "cc_plugin/field/Res4.h"
#include "cc_plugin/field/Res8.h"

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
    using Field = ublox::message::RxmMeasxFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::RxmMeasxFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

static QVariantMap createProps_gpsTOW()
{
    using Field = ublox::message::RxmMeasxFields<>::GpsTOW;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_gloTOW()
{
    using Field = ublox::message::RxmMeasxFields<>::GloTOW;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_bdsTOW()
{
    using Field = ublox::message::RxmMeasxFields<>::BdsTOW;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::RxmMeasxFields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res4(Field::name());
    return props;
    
}

static QVariantMap createProps_qzssTOW()
{
    using Field = ublox::message::RxmMeasxFields<>::QzssTOW;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_gpsTOWacc()
{
    using Field = ublox::message::RxmMeasxFields<>::GpsTOWacc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(2U)
            .asMap();
    
}

static QVariantMap createProps_gloTOWacc()
{
    using Field = ublox::message::RxmMeasxFields<>::GloTOWacc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(2U)
            .asMap();
    
}

static QVariantMap createProps_bdsTOWacc()
{
    using Field = ublox::message::RxmMeasxFields<>::BdsTOWacc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(2U)
            .asMap();
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::RxmMeasxFields<>::Reserved3;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_qzssTOWacc()
{
    using Field = ublox::message::RxmMeasxFields<>::QzssTOWacc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .scaledDecimals(2U)
            .asMap();
    
}

static QVariantMap createProps_numSV()
{
    using Field = ublox::message::RxmMeasxFields<>::NumSV;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

struct FlagsMembers
{
    static QVariantMap createProps_towSet()
    {
        using Field = ublox::message::RxmMeasxFields<>::FlagsMembers::TowSet;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("No", 0)
                .add("Yes", 1)
                .add("Yes2", 2)
                .asMap();
        
    }
    
    static QVariantMap createProps_reserved()
    {
        using Field = ublox::message::RxmMeasxFields<>::FlagsMembers::Reserved;
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
    using Field = ublox::message::RxmMeasxFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(FlagsMembers::createProps_towSet())
            .add(FlagsMembers::createProps_reserved())
            .asMap();
    
}

static QVariantMap createProps_reserved4()
{
    using Field = ublox::message::RxmMeasxFields<>::Reserved4;
    auto props = cc_plugin::field::createProps_res8(Field::name());
    return props;
    
}

struct ListMembers
{
    struct ElementMembers
    {
        static QVariantMap createProps_gnssId()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::GnssId;
            auto props = cc_plugin::field::createProps_gnssId(Field::name());
            return props;
            
        }
        
        static QVariantMap createProps_svid()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::Svid;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_cNo()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::CNo;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_mpathIndic()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::MpathIndic;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add("Not measured", 0)
                    .add("Low", 1)
                    .add("Medium", 2)
                    .add("High", 3)
                    .asMap();
            
        }
        
        static QVariantMap createProps_dopplerMS()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::DopplerMS;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(2U)
                    .asMap();
            
        }
        
        static QVariantMap createProps_dopplerHz()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::DopplerHz;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(2U)
                    .asMap();
            
        }
        
        static QVariantMap createProps_wholeChips()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::WholeChips;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_fracChips()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::FracChips;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_codePhase()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::CodePhase;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(9U)
                    .asMap();
            
        }
        
        static QVariantMap createProps_intCodePhase()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::IntCodePhase;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_pseuRangeRMSErr()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::PseuRangeRMSErr;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_reserved5()
        {
            using Field = ublox::message::RxmMeasxFields<>::ListMembers::ElementMembers::Reserved5;
            auto props = cc_plugin::field::createProps_res2(Field::name());
            return props;
            
        }
        
    };
    
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::RxmMeasxFields<>::ListMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ElementMembers::createProps_gnssId())
                .add(ElementMembers::createProps_svid())
                .add(ElementMembers::createProps_cNo())
                .add(ElementMembers::createProps_mpathIndic())
                .add(ElementMembers::createProps_dopplerMS())
                .add(ElementMembers::createProps_dopplerHz())
                .add(ElementMembers::createProps_wholeChips())
                .add(ElementMembers::createProps_fracChips())
                .add(ElementMembers::createProps_codePhase())
                .add(ElementMembers::createProps_intCodePhase())
                .add(ElementMembers::createProps_pseuRangeRMSErr())
                .add(ElementMembers::createProps_reserved5())
                .asMap();
        
    }
    
};

static QVariantMap createProps_list()
{
    using Field = ublox::message::RxmMeasxFields<>::List;
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
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_gpsTOW());
    props.append(createProps_gloTOW());
    props.append(createProps_bdsTOW());
    props.append(createProps_reserved2());
    props.append(createProps_qzssTOW());
    props.append(createProps_gpsTOWacc());
    props.append(createProps_gloTOWacc());
    props.append(createProps_bdsTOWacc());
    props.append(createProps_reserved3());
    props.append(createProps_qzssTOWacc());
    props.append(createProps_numSV());
    props.append(createProps_flags());
    props.append(createProps_reserved4());
    props.append(createProps_list());
    return props;
}

} // namespace

class RxmMeasxImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::RxmMeasx<ublox::cc_plugin::Message>,
        RxmMeasxImpl
    >
{
public:
    RxmMeasxImpl() = default;
    RxmMeasxImpl(const RxmMeasxImpl&) = delete;
    RxmMeasxImpl(RxmMeasxImpl&&) = delete;
    virtual ~RxmMeasxImpl() = default;
    RxmMeasxImpl& operator=(const RxmMeasxImpl&) = default;
    RxmMeasxImpl& operator=(RxmMeasxImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

RxmMeasx::RxmMeasx() : m_pImpl(new RxmMeasxImpl) {}
RxmMeasx::~RxmMeasx() = default;

RxmMeasx& RxmMeasx::operator=(const RxmMeasx& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

RxmMeasx& RxmMeasx::operator=(RxmMeasx&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* RxmMeasx::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& RxmMeasx::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void RxmMeasx::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void RxmMeasx::resetImpl()
{
    m_pImpl->reset();
}

bool RxmMeasx::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const RxmMeasx*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

RxmMeasx::MsgIdParamType RxmMeasx::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus RxmMeasx::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus RxmMeasx::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool RxmMeasx::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t RxmMeasx::lengthImpl() const
{
    return m_pImpl->length();
}

bool RxmMeasx::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


