#include "MgaIniFreq.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaIniFreq.h"
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

static QVariantMap createProps_type()
{
    using Field = ublox::message::MgaIniFreqFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaIniFreqFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaIniFreqFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

struct FlagsMembers
{
    static QVariantMap createProps_source()
    {
        using Field = ublox::message::MgaIniFreqFields<>::FlagsMembers::Source;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("EXTINT0", 0)
                .add("EXTINT1", 1)
                .asMap();
        
    }
    
    static QVariantMap createProps_bits()
    {
        using Field = ublox::message::MgaIniFreqFields<>::FlagsMembers::Bits;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "fall")
                .asMap();
        
    }
    
};

static QVariantMap createProps_flags()
{
    using Field = ublox::message::MgaIniFreqFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(FlagsMembers::createProps_source())
            .add(FlagsMembers::createProps_bits())
            .asMap();
    
}

static QVariantMap createProps_freq()
{
    using Field = ublox::message::MgaIniFreqFields<>::Freq;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_freqAcc()
{
    using Field = ublox::message::MgaIniFreqFields<>::FreqAcc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_type());
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_flags());
    props.append(createProps_freq());
    props.append(createProps_freqAcc());
    return props;
}

} // namespace

class MgaIniFreqImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaIniFreq<ublox::cc_plugin::Message>,
        MgaIniFreqImpl
    >
{
public:
    MgaIniFreqImpl() = default;
    MgaIniFreqImpl(const MgaIniFreqImpl&) = delete;
    MgaIniFreqImpl(MgaIniFreqImpl&&) = delete;
    virtual ~MgaIniFreqImpl() = default;
    MgaIniFreqImpl& operator=(const MgaIniFreqImpl&) = default;
    MgaIniFreqImpl& operator=(MgaIniFreqImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaIniFreq::MgaIniFreq() : m_pImpl(new MgaIniFreqImpl) {}
MgaIniFreq::~MgaIniFreq() = default;

MgaIniFreq& MgaIniFreq::operator=(const MgaIniFreq& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaIniFreq& MgaIniFreq::operator=(MgaIniFreq&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaIniFreq::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaIniFreq::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaIniFreq::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaIniFreq::resetImpl()
{
    m_pImpl->reset();
}

bool MgaIniFreq::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaIniFreq*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaIniFreq::MsgIdParamType MgaIniFreq::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaIniFreq::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaIniFreq::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaIniFreq::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaIniFreq::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaIniFreq::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


