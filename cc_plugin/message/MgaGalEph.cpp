#include "MgaGalEph.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaGalEph.h"
#include "cc_plugin/field/Res1.h"
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

static QVariantMap createProps_type()
{
    using Field = ublox::message::MgaGalEphFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaGalEphFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_svid()
{
    using Field = ublox::message::MgaGalEphFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaGalEphFields<>::Reserved1;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

static QVariantMap createProps_iodNav()
{
    using Field = ublox::message::MgaGalEphFields<>::IodNav;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_deltaN()
{
    using Field = ublox::message::MgaGalEphFields<>::DeltaN;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_m0()
{
    using Field = ublox::message::MgaGalEphFields<>::M0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_e()
{
    using Field = ublox::message::MgaGalEphFields<>::E;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_sqrtA()
{
    using Field = ublox::message::MgaGalEphFields<>::SqrtA;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omega0()
{
    using Field = ublox::message::MgaGalEphFields<>::Omega0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_i0()
{
    using Field = ublox::message::MgaGalEphFields<>::I0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omega()
{
    using Field = ublox::message::MgaGalEphFields<>::Omega;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omegaDot()
{
    using Field = ublox::message::MgaGalEphFields<>::OmegaDot;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_iDot()
{
    using Field = ublox::message::MgaGalEphFields<>::IDot;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cuc()
{
    using Field = ublox::message::MgaGalEphFields<>::Cuc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cus()
{
    using Field = ublox::message::MgaGalEphFields<>::Cus;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_crc()
{
    using Field = ublox::message::MgaGalEphFields<>::Crc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_crs()
{
    using Field = ublox::message::MgaGalEphFields<>::Crs;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cic()
{
    using Field = ublox::message::MgaGalEphFields<>::Cic;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_cis()
{
    using Field = ublox::message::MgaGalEphFields<>::Cis;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_toe()
{
    using Field = ublox::message::MgaGalEphFields<>::Toe;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_af0()
{
    using Field = ublox::message::MgaGalEphFields<>::Af0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_af1()
{
    using Field = ublox::message::MgaGalEphFields<>::Af1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_af2()
{
    using Field = ublox::message::MgaGalEphFields<>::Af2;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_sisaIndexE1E5b()
{
    using Field = ublox::message::MgaGalEphFields<>::SisaIndexE1E5b;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_toc()
{
    using Field = ublox::message::MgaGalEphFields<>::Toc;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_bgdE1E5b()
{
    using Field = ublox::message::MgaGalEphFields<>::BgdE1E5b;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::MgaGalEphFields<>::Reserved2;
    return cc_plugin::field::createProps_res2(Field::name());
    
}

static QVariantMap createProps_healthE1B()
{
    using Field = ublox::message::MgaGalEphFields<>::HealthE1B;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_dataValidityE1B()
{
    using Field = ublox::message::MgaGalEphFields<>::DataValidityE1B;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_healthE5b()
{
    using Field = ublox::message::MgaGalEphFields<>::HealthE5b;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_dataValidityE5b()
{
    using Field = ublox::message::MgaGalEphFields<>::DataValidityE5b;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved3()
{
    using Field = ublox::message::MgaGalEphFields<>::Reserved3;
    return cc_plugin::field::createProps_res4(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_type());
    props.append(createProps_version());
    props.append(createProps_svid());
    props.append(createProps_reserved1());
    props.append(createProps_iodNav());
    props.append(createProps_deltaN());
    props.append(createProps_m0());
    props.append(createProps_e());
    props.append(createProps_sqrtA());
    props.append(createProps_omega0());
    props.append(createProps_i0());
    props.append(createProps_omega());
    props.append(createProps_omegaDot());
    props.append(createProps_iDot());
    props.append(createProps_cuc());
    props.append(createProps_cus());
    props.append(createProps_crc());
    props.append(createProps_crs());
    props.append(createProps_cic());
    props.append(createProps_cis());
    props.append(createProps_toe());
    props.append(createProps_af0());
    props.append(createProps_af1());
    props.append(createProps_af2());
    props.append(createProps_sisaIndexE1E5b());
    props.append(createProps_toc());
    props.append(createProps_bgdE1E5b());
    props.append(createProps_reserved2());
    props.append(createProps_healthE1B());
    props.append(createProps_dataValidityE1B());
    props.append(createProps_healthE5b());
    props.append(createProps_dataValidityE5b());
    props.append(createProps_reserved3());
    return props;
}

} // namespace

class MgaGalEphImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaGalEph<ublox::cc_plugin::Message>,
        MgaGalEphImpl
    >
{
public:
    MgaGalEphImpl() = default;
    MgaGalEphImpl(const MgaGalEphImpl&) = delete;
    MgaGalEphImpl(MgaGalEphImpl&&) = delete;
    virtual ~MgaGalEphImpl() = default;
    MgaGalEphImpl& operator=(const MgaGalEphImpl&) = default;
    MgaGalEphImpl& operator=(MgaGalEphImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaGalEph::MgaGalEph() : m_pImpl(new MgaGalEphImpl) {}
MgaGalEph::~MgaGalEph() = default;

MgaGalEph& MgaGalEph::operator=(const MgaGalEph& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaGalEph& MgaGalEph::operator=(MgaGalEph&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaGalEph::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaGalEph::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaGalEph::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaGalEph::resetImpl()
{
    m_pImpl->reset();
}

bool MgaGalEph::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaGalEph*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaGalEph::MsgIdParamType MgaGalEph::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaGalEph::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaGalEph::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaGalEph::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaGalEph::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaGalEph::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

