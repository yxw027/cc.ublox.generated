#include "MgaIniClkd.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MgaIniClkd.h"
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
    using Field = ublox::message::MgaIniClkdFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_version()
{
    using Field = ublox::message::MgaIniClkdFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::MgaIniClkdFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res2(Field::name());
    return props;
    
}

static QVariantMap createProps_clkD()
{
    using Field = ublox::message::MgaIniClkdFields<>::ClkD;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_clkDAcc()
{
    using Field = ublox::message::MgaIniClkdFields<>::ClkDAcc;
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
    props.append(createProps_clkD());
    props.append(createProps_clkDAcc());
    return props;
}

} // namespace

class MgaIniClkdImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MgaIniClkd<ublox::cc_plugin::Message>,
        MgaIniClkdImpl
    >
{
public:
    MgaIniClkdImpl() = default;
    MgaIniClkdImpl(const MgaIniClkdImpl&) = delete;
    MgaIniClkdImpl(MgaIniClkdImpl&&) = delete;
    virtual ~MgaIniClkdImpl() = default;
    MgaIniClkdImpl& operator=(const MgaIniClkdImpl&) = default;
    MgaIniClkdImpl& operator=(MgaIniClkdImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MgaIniClkd::MgaIniClkd() : m_pImpl(new MgaIniClkdImpl) {}
MgaIniClkd::~MgaIniClkd() = default;

MgaIniClkd& MgaIniClkd::operator=(const MgaIniClkd& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MgaIniClkd& MgaIniClkd::operator=(MgaIniClkd&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MgaIniClkd::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MgaIniClkd::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MgaIniClkd::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MgaIniClkd::resetImpl()
{
    m_pImpl->reset();
}

bool MgaIniClkd::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MgaIniClkd*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MgaIniClkd::MsgIdParamType MgaIniClkd::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MgaIniClkd::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MgaIniClkd::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MgaIniClkd::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MgaIniClkd::lengthImpl() const
{
    return m_pImpl->length();
}

bool MgaIniClkd::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


