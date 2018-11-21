#include "MgaGloTimeoffset.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaGloTimeoffset.h"
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
    using Field = ublox::message::MgaGloTimeoffsetFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaGloTimeoffsetFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_n()
{
    using Field = ublox::message::MgaGloTimeoffsetFields<>::N;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_tauC()
{
    using Field = ublox::message::MgaGloTimeoffsetFields<>::TauC;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_tauGps()
{
    using Field = ublox::message::MgaGloTimeoffsetFields<>::TauGps;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_b1()
{
    using Field = ublox::message::MgaGloTimeoffsetFields<>::B1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_b2()
{
    using Field = ublox::message::MgaGloTimeoffsetFields<>::B2;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaGloTimeoffsetFields<>::Reserved1;
    return cc_plugin::field::createProps_res4(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_type());
    props.append(createProps_version());
    props.append(createProps_n());
    props.append(createProps_tauC());
    props.append(createProps_tauGps());
    props.append(createProps_b1());
    props.append(createProps_b2());
    props.append(createProps_reserved1());
    return props;
}

} // namespace

class MgaGloTimeoffsetImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaGloTimeoffset<ublox::cc_plugin::Message>,
        MgaGloTimeoffsetImpl
    >
{
public:
    MgaGloTimeoffsetImpl() = default;
    MgaGloTimeoffsetImpl(const MgaGloTimeoffsetImpl&) = delete;
    MgaGloTimeoffsetImpl(MgaGloTimeoffsetImpl&&) = delete;
    virtual ~MgaGloTimeoffsetImpl() = default;
    MgaGloTimeoffsetImpl& operator=(const MgaGloTimeoffsetImpl&) = default;
    MgaGloTimeoffsetImpl& operator=(MgaGloTimeoffsetImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaGloTimeoffset::MgaGloTimeoffset() : m_pImpl(new MgaGloTimeoffsetImpl) {}
MgaGloTimeoffset::~MgaGloTimeoffset() = default;

MgaGloTimeoffset& MgaGloTimeoffset::operator=(const MgaGloTimeoffset& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaGloTimeoffset& MgaGloTimeoffset::operator=(MgaGloTimeoffset&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaGloTimeoffset::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaGloTimeoffset::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaGloTimeoffset::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaGloTimeoffset::resetImpl()
{
    m_pImpl->reset();
}

bool MgaGloTimeoffset::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaGloTimeoffset*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaGloTimeoffset::MsgIdParamType MgaGloTimeoffset::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaGloTimeoffset::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaGloTimeoffset::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaGloTimeoffset::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaGloTimeoffset::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaGloTimeoffset::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

