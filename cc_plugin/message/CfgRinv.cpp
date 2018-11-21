#include "CfgRinv.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgRinv.h"
namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_flags()
{
    using Field = ublox::message::CfgRinvFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "dump")
            .add(1U, "binary")
            .asMap();
    
}

static QVariantMap createProps_data()
{
    using Field = ublox::message::CfgRinvFields<>::Data;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_flags());
    props.append(createProps_data());
    return props;
}

} // namespace

class CfgRinvImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgRinv<ublox::cc_plugin::Message>,
        CfgRinvImpl
    >
{
public:
    CfgRinvImpl() = default;
    CfgRinvImpl(const CfgRinvImpl&) = delete;
    CfgRinvImpl(CfgRinvImpl&&) = delete;
    virtual ~CfgRinvImpl() = default;
    CfgRinvImpl& operator=(const CfgRinvImpl&) = default;
    CfgRinvImpl& operator=(CfgRinvImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgRinv::CfgRinv() : m_pImpl(new CfgRinvImpl) {}
CfgRinv::~CfgRinv() = default;

CfgRinv& CfgRinv::operator=(const CfgRinv& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgRinv& CfgRinv::operator=(CfgRinv&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgRinv::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgRinv::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgRinv::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgRinv::resetImpl()
{
    m_pImpl->reset();
}

bool CfgRinv::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgRinv*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgRinv::MsgIdParamType CfgRinv::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgRinv::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgRinv::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgRinv::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgRinv::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgRinv::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

