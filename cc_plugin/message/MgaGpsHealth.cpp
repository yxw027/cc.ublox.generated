#include "MgaGpsHealth.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaGpsHealth.h"
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
    using Field = ublox::message::MgaGpsHealthFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaGpsHealthFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaGpsHealthFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_healthCode()
{
    using Field = ublox::message::MgaGpsHealthFields<>::HealthCode;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::MgaGpsHealthFields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res4(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_type());
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_healthCode());
    props.append(createProps_reserved2());
    return props;
}

} // namespace

class MgaGpsHealthImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaGpsHealth<ublox::cc_plugin::Message>,
        MgaGpsHealthImpl
    >
{
public:
    MgaGpsHealthImpl() = default;
    MgaGpsHealthImpl(const MgaGpsHealthImpl&) = delete;
    MgaGpsHealthImpl(MgaGpsHealthImpl&&) = delete;
    virtual ~MgaGpsHealthImpl() = default;
    MgaGpsHealthImpl& operator=(const MgaGpsHealthImpl&) = default;
    MgaGpsHealthImpl& operator=(MgaGpsHealthImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaGpsHealth::MgaGpsHealth() : m_pImpl(new MgaGpsHealthImpl) {}
MgaGpsHealth::~MgaGpsHealth() = default;

MgaGpsHealth& MgaGpsHealth::operator=(const MgaGpsHealth& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaGpsHealth& MgaGpsHealth::operator=(MgaGpsHealth&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaGpsHealth::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaGpsHealth::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaGpsHealth::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaGpsHealth::resetImpl()
{
    m_pImpl->reset();
}

bool MgaGpsHealth::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaGpsHealth*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaGpsHealth::MsgIdParamType MgaGpsHealth::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaGpsHealth::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaGpsHealth::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaGpsHealth::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaGpsHealth::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaGpsHealth::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


