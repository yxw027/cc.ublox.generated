#include "MgaGpsEph.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaGpsEph.h"
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
    using Field = ublox::message::MgaGpsEphFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaGpsEphFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_svid()
{
    using Field = ublox::message::MgaGpsEphFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaGpsEphFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_fitInterval()
{
    using Field = ublox::message::MgaGpsEphFields<>::FitInterval;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_uraIndex()
{
    using Field = ublox::message::MgaGpsEphFields<>::UraIndex;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_svHealth()
{
    using Field = ublox::message::MgaGpsEphFields<>::SvHealth;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_tgd()
{
    using Field = ublox::message::MgaGpsEphFields<>::Tgd;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_iodc()
{
    using Field = ublox::message::MgaGpsEphFields<>::Iodc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_toc()
{
    using Field = ublox::message::MgaGpsEphFields<>::Toc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::MgaGpsEphFields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_af2()
{
    using Field = ublox::message::MgaGpsEphFields<>::Af2;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_af1()
{
    using Field = ublox::message::MgaGpsEphFields<>::Af1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_af0()
{
    using Field = ublox::message::MgaGpsEphFields<>::Af0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_crs()
{
    using Field = ublox::message::MgaGpsEphFields<>::Crs;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_deltaN()
{
    using Field = ublox::message::MgaGpsEphFields<>::DeltaN;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_m0()
{
    using Field = ublox::message::MgaGpsEphFields<>::M0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cuc()
{
    using Field = ublox::message::MgaGpsEphFields<>::Cuc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cus()
{
    using Field = ublox::message::MgaGpsEphFields<>::Cus;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_e()
{
    using Field = ublox::message::MgaGpsEphFields<>::E;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_sqrtA()
{
    using Field = ublox::message::MgaGpsEphFields<>::SqrtA;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_toe()
{
    using Field = ublox::message::MgaGpsEphFields<>::Toe;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cic()
{
    using Field = ublox::message::MgaGpsEphFields<>::Cic;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omega0()
{
    using Field = ublox::message::MgaGpsEphFields<>::Omega0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cis()
{
    using Field = ublox::message::MgaGpsEphFields<>::Cis;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_crc()
{
    using Field = ublox::message::MgaGpsEphFields<>::Crc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_i0()
{
    using Field = ublox::message::MgaGpsEphFields<>::I0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omega()
{
    using Field = ublox::message::MgaGpsEphFields<>::Omega;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omegaDot()
{
    using Field = ublox::message::MgaGpsEphFields<>::OmegaDot;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_idot()
{
    using Field = ublox::message::MgaGpsEphFields<>::Idot;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::MgaGpsEphFields<>::Reserved3;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
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

class MgaGpsEphImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaGpsEph<ublox::cc_plugin::Message>,
        MgaGpsEphImpl
    >
{
public:
    MgaGpsEphImpl() = default;
    MgaGpsEphImpl(const MgaGpsEphImpl&) = delete;
    MgaGpsEphImpl(MgaGpsEphImpl&&) = delete;
    virtual ~MgaGpsEphImpl() = default;
    MgaGpsEphImpl& operator=(const MgaGpsEphImpl&) = default;
    MgaGpsEphImpl& operator=(MgaGpsEphImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaGpsEph::MgaGpsEph() : m_pImpl(new MgaGpsEphImpl) {}
MgaGpsEph::~MgaGpsEph() = default;

MgaGpsEph& MgaGpsEph::operator=(const MgaGpsEph& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaGpsEph& MgaGpsEph::operator=(MgaGpsEph&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaGpsEph::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaGpsEph::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaGpsEph::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaGpsEph::resetImpl()
{
    m_pImpl->reset();
}

bool MgaGpsEph::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaGpsEph*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaGpsEph::MsgIdParamType MgaGpsEph::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaGpsEph::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaGpsEph::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaGpsEph::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaGpsEph::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaGpsEph::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


