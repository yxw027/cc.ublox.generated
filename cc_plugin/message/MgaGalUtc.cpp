#include "MgaGalUtc.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaGalUtc.h"
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
    using Field = ublox::message::MgaGalUtcFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaGalUtcFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaGalUtcFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_a0()
{
    using Field = ublox::message::MgaGalUtcFields<>::A0;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_a1()
{
    using Field = ublox::message::MgaGalUtcFields<>::A1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_dtLS()
{
    using Field = ublox::message::MgaGalUtcFields<>::DtLS;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_tot()
{
    using Field = ublox::message::MgaGalUtcFields<>::Tot;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_wnt()
{
    using Field = ublox::message::MgaGalUtcFields<>::Wnt;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_wnLSF()
{
    using Field = ublox::message::MgaGalUtcFields<>::WnLSF;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_dN()
{
    using Field = ublox::message::MgaGalUtcFields<>::DN;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_dTLSF()
{
    using Field = ublox::message::MgaGalUtcFields<>::DTLSF;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::MgaGalUtcFields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_type());
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_a0());
    props.append(createProps_a1());
    props.append(createProps_dtLS());
    props.append(createProps_tot());
    props.append(createProps_wnt());
    props.append(createProps_wnLSF());
    props.append(createProps_dN());
    props.append(createProps_dTLSF());
    props.append(createProps_reserved2());
    return props;
}

} // namespace

class MgaGalUtcImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaGalUtc<ublox::cc_plugin::Message>,
        MgaGalUtcImpl
    >
{
public:
    MgaGalUtcImpl() = default;
    MgaGalUtcImpl(const MgaGalUtcImpl&) = delete;
    MgaGalUtcImpl(MgaGalUtcImpl&&) = delete;
    virtual ~MgaGalUtcImpl() = default;
    MgaGalUtcImpl& operator=(const MgaGalUtcImpl&) = default;
    MgaGalUtcImpl& operator=(MgaGalUtcImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaGalUtc::MgaGalUtc() : m_pImpl(new MgaGalUtcImpl) {}
MgaGalUtc::~MgaGalUtc() = default;

MgaGalUtc& MgaGalUtc::operator=(const MgaGalUtc& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaGalUtc& MgaGalUtc::operator=(MgaGalUtc&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaGalUtc::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaGalUtc::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaGalUtc::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaGalUtc::resetImpl()
{
    m_pImpl->reset();
}

bool MgaGalUtc::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaGalUtc*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaGalUtc::MsgIdParamType MgaGalUtc::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaGalUtc::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaGalUtc::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaGalUtc::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaGalUtc::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaGalUtc::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


