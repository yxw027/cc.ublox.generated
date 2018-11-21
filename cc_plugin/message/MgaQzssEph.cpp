#include "MgaQzssEph.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaQzssEph.h"
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

static QVariantMap createProps_type()
{
    using Field = ublox::message::MgaQzssEphFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaQzssEphFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_svid()
{
    using Field = ublox::message::MgaQzssEphFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaQzssEphFields<>::Reserved1;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

static QVariantMap createProps_fitInterval()
{
    using Field = ublox::message::MgaQzssEphFields<>::FitInterval;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_uraIndex()
{
    using Field = ublox::message::MgaQzssEphFields<>::UraIndex;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_svHealth()
{
    using Field = ublox::message::MgaQzssEphFields<>::SvHealth;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_tgd()
{
    using Field = ublox::message::MgaQzssEphFields<>::Tgd;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_iodc()
{
    using Field = ublox::message::MgaQzssEphFields<>::Iodc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_toc()
{
    using Field = ublox::message::MgaQzssEphFields<>::Toc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::MgaQzssEphFields<>::Reserved2;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

static QVariantMap createProps_af2()
{
    using Field = ublox::message::MgaQzssEphFields<>::Af2;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_af1()
{
    using Field = ublox::message::MgaQzssEphFields<>::Af1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_af0()
{
    using Field = ublox::message::MgaQzssEphFields<>::Af0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_crs()
{
    using Field = ublox::message::MgaQzssEphFields<>::Crs;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_deltaN()
{
    using Field = ublox::message::MgaQzssEphFields<>::DeltaN;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_m0()
{
    using Field = ublox::message::MgaQzssEphFields<>::M0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cuc()
{
    using Field = ublox::message::MgaQzssEphFields<>::Cuc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cus()
{
    using Field = ublox::message::MgaQzssEphFields<>::Cus;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_e()
{
    using Field = ublox::message::MgaQzssEphFields<>::E;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_sqrtA()
{
    using Field = ublox::message::MgaQzssEphFields<>::SqrtA;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_toe()
{
    using Field = ublox::message::MgaQzssEphFields<>::Toe;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cic()
{
    using Field = ublox::message::MgaQzssEphFields<>::Cic;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omega0()
{
    using Field = ublox::message::MgaQzssEphFields<>::Omega0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cis()
{
    using Field = ublox::message::MgaQzssEphFields<>::Cis;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_crc()
{
    using Field = ublox::message::MgaQzssEphFields<>::Crc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_i0()
{
    using Field = ublox::message::MgaQzssEphFields<>::I0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omega()
{
    using Field = ublox::message::MgaQzssEphFields<>::Omega;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omegaDot()
{
    using Field = ublox::message::MgaQzssEphFields<>::OmegaDot;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_idot()
{
    using Field = ublox::message::MgaQzssEphFields<>::Idot;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::MgaQzssEphFields<>::Reserved3;
    return cc_plugin::field::createProps_res2(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_type());
    props.append(createProps_version());
    props.append(createProps_svid());
    props.append(createProps_reserved1());
    props.append(createProps_fitInterval());
    props.append(createProps_uraIndex());
    props.append(createProps_svHealth());
    props.append(createProps_tgd());
    props.append(createProps_iodc());
    props.append(createProps_toc());
    props.append(createProps_reserved2());
    props.append(createProps_af2());
    props.append(createProps_af1());
    props.append(createProps_af0());
    props.append(createProps_crs());
    props.append(createProps_deltaN());
    props.append(createProps_m0());
    props.append(createProps_cuc());
    props.append(createProps_cus());
    props.append(createProps_e());
    props.append(createProps_sqrtA());
    props.append(createProps_toe());
    props.append(createProps_cic());
    props.append(createProps_omega0());
    props.append(createProps_cis());
    props.append(createProps_crc());
    props.append(createProps_i0());
    props.append(createProps_omega());
    props.append(createProps_omegaDot());
    props.append(createProps_idot());
    props.append(createProps_reserved3());
    return props;
}

} // namespace

class MgaQzssEphImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaQzssEph<ublox::cc_plugin::Message>,
        MgaQzssEphImpl
    >
{
public:
    MgaQzssEphImpl() = default;
    MgaQzssEphImpl(const MgaQzssEphImpl&) = delete;
    MgaQzssEphImpl(MgaQzssEphImpl&&) = delete;
    virtual ~MgaQzssEphImpl() = default;
    MgaQzssEphImpl& operator=(const MgaQzssEphImpl&) = default;
    MgaQzssEphImpl& operator=(MgaQzssEphImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaQzssEph::MgaQzssEph() : m_pImpl(new MgaQzssEphImpl) {}
MgaQzssEph::~MgaQzssEph() = default;

MgaQzssEph& MgaQzssEph::operator=(const MgaQzssEph& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaQzssEph& MgaQzssEph::operator=(MgaQzssEph&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaQzssEph::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaQzssEph::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaQzssEph::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaQzssEph::resetImpl()
{
    m_pImpl->reset();
}

bool MgaQzssEph::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaQzssEph*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaQzssEph::MsgIdParamType MgaQzssEph::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaQzssEph::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaQzssEph::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaQzssEph::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaQzssEph::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaQzssEph::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

