#include "MgaBdsAlm.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaBdsAlm.h"
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

static QVariantMap createProps_type()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_svid()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Reserved1;
    return cc_plugin::field::createProps_res1(Field::name());
    
}

static QVariantMap createProps_wna()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Wna;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_toa()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Toa;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_deltaI()
{
    using Field = ublox::message::MgaBdsAlmFields<>::DeltaI;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_sqrtA()
{
    using Field = ublox::message::MgaBdsAlmFields<>::SqrtA;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_e()
{
    using Field = ublox::message::MgaBdsAlmFields<>::E;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omega()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Omega;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_m0()
{
    using Field = ublox::message::MgaBdsAlmFields<>::M0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omega0()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Omega0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_omegaDot()
{
    using Field = ublox::message::MgaBdsAlmFields<>::OmegaDot;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_a0()
{
    using Field = ublox::message::MgaBdsAlmFields<>::A0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_a1()
{
    using Field = ublox::message::MgaBdsAlmFields<>::A1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::MgaBdsAlmFields<>::Reserved2;
    return cc_plugin::field::createProps_res4(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_type());
    props.append(createProps_version());
    props.append(createProps_svid());
    props.append(createProps_reserved1());
    props.append(createProps_wna());
    props.append(createProps_toa());
    props.append(createProps_deltaI());
    props.append(createProps_sqrtA());
    props.append(createProps_e());
    props.append(createProps_omega());
    props.append(createProps_m0());
    props.append(createProps_omega0());
    props.append(createProps_omegaDot());
    props.append(createProps_a0());
    props.append(createProps_a1());
    props.append(createProps_reserved2());
    return props;
}

} // namespace

class MgaBdsAlmImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaBdsAlm<ublox::cc_plugin::Message>,
        MgaBdsAlmImpl
    >
{
public:
    MgaBdsAlmImpl() = default;
    MgaBdsAlmImpl(const MgaBdsAlmImpl&) = delete;
    MgaBdsAlmImpl(MgaBdsAlmImpl&&) = delete;
    virtual ~MgaBdsAlmImpl() = default;
    MgaBdsAlmImpl& operator=(const MgaBdsAlmImpl&) = default;
    MgaBdsAlmImpl& operator=(MgaBdsAlmImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaBdsAlm::MgaBdsAlm() : m_pImpl(new MgaBdsAlmImpl) {}
MgaBdsAlm::~MgaBdsAlm() = default;

MgaBdsAlm& MgaBdsAlm::operator=(const MgaBdsAlm& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaBdsAlm& MgaBdsAlm::operator=(MgaBdsAlm&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaBdsAlm::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaBdsAlm::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaBdsAlm::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaBdsAlm::resetImpl()
{
    m_pImpl->reset();
}

bool MgaBdsAlm::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaBdsAlm*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaBdsAlm::MsgIdParamType MgaBdsAlm::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaBdsAlm::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaBdsAlm::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaBdsAlm::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaBdsAlm::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaBdsAlm::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

