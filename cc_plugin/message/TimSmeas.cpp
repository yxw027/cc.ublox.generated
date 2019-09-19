#include "TimSmeas.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/TimSmeas.h"
#include "cc_plugin/field/Itow.h"
#include "cc_plugin/field/Res2.h"
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
    using Field = ublox::message::TimSmeasFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_numMeas()
{
    using Field = ublox::message::TimSmeasFields<>::NumMeas;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::TimSmeasFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_itow()
{
    using Field = ublox::message::TimSmeasFields<>::Itow;
    auto props = cc_plugin::field::createProps_itow(Field::name());
    return props;
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::TimSmeasFields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res4(Field::name());
    return props;
    
}

struct ListMembers
{
    struct ElementMembers
    {
        static QVariantMap createProps_sourceId()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::SourceId;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_flags()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::Flags;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add(0U, "freqValid")
                    .add(1U, "phaseValid")
                    .asMap();
            
        }
        
        static QVariantMap createProps_phaseOffsetFrac()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::PhaseOffsetFrac;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(8U)
                    .asMap();
            
        }
        
        static QVariantMap createProps_phaseUncFrac()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::PhaseUncFrac;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(8U)
                    .asMap();
            
        }
        
        static QVariantMap createProps_phaseOffset()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::PhaseOffset;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_phaseUnc()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::PhaseUnc;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_reserved3()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::Reserved3;
            auto props = cc_plugin::field::createProps_res4(Field::name());
            return props;
            
        }
        
        static QVariantMap createProps_freqOffset()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::FreqOffset;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(8U)
                    .asMap();
            
        }
        
        static QVariantMap createProps_freqUnc()
        {
            using Field = ublox::message::TimSmeasFields<>::ListMembers::ElementMembers::FreqUnc;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .scaledDecimals(8U)
                    .asMap();
            
        }
        
    };
    
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::TimSmeasFields<>::ListMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ElementMembers::createProps_sourceId())
                .add(ElementMembers::createProps_flags())
                .add(ElementMembers::createProps_phaseOffsetFrac())
                .add(ElementMembers::createProps_phaseUncFrac())
                .add(ElementMembers::createProps_phaseOffset())
                .add(ElementMembers::createProps_phaseUnc())
                .add(ElementMembers::createProps_reserved3())
                .add(ElementMembers::createProps_freqOffset())
                .add(ElementMembers::createProps_freqUnc())
                .asMap();
        
    }
    
};

static QVariantMap createProps_list()
{
    using Field = ublox::message::TimSmeasFields<>::List;
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
    props.append(createProps_numMeas());
    props.append(createProps_reserved1());
    props.append(createProps_itow());
    props.append(createProps_reserved2());
    props.append(createProps_list());
    return props;
}

} // namespace

class TimSmeasImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::TimSmeas<ublox::cc_plugin::Message>,
        TimSmeasImpl
    >
{
public:
    TimSmeasImpl() = default;
    TimSmeasImpl(const TimSmeasImpl&) = delete;
    TimSmeasImpl(TimSmeasImpl&&) = delete;
    virtual ~TimSmeasImpl() = default;
    TimSmeasImpl& operator=(const TimSmeasImpl&) = default;
    TimSmeasImpl& operator=(TimSmeasImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

TimSmeas::TimSmeas() : m_pImpl(new TimSmeasImpl) {}
TimSmeas::~TimSmeas() = default;

TimSmeas& TimSmeas::operator=(const TimSmeas& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

TimSmeas& TimSmeas::operator=(TimSmeas&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* TimSmeas::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& TimSmeas::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void TimSmeas::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void TimSmeas::resetImpl()
{
    m_pImpl->reset();
}

bool TimSmeas::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const TimSmeas*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

TimSmeas::MsgIdParamType TimSmeas::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus TimSmeas::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus TimSmeas::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool TimSmeas::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t TimSmeas::lengthImpl() const
{
    return m_pImpl->length();
}

bool TimSmeas::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


