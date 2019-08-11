#include "CfgDgnss.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgDgnss.h"
#include "cc_plugin/field/Res3.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_dgnssMode()
{
    using Field = ublox::message::CfgDgnssFields<>::DgnssMode;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("Float", 2)
            .add("Fixed", 3)
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::CfgDgnssFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_dgnssMode());
    props.append(createProps_reserved1());
    return props;
}

} // namespace

class CfgDgnssImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgDgnss<ublox::cc_plugin::Message>,
        CfgDgnssImpl
    >
{
public:
    CfgDgnssImpl() = default;
    CfgDgnssImpl(const CfgDgnssImpl&) = delete;
    CfgDgnssImpl(CfgDgnssImpl&&) = delete;
    virtual ~CfgDgnssImpl() = default;
    CfgDgnssImpl& operator=(const CfgDgnssImpl&) = default;
    CfgDgnssImpl& operator=(CfgDgnssImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgDgnss::CfgDgnss() : m_pImpl(new CfgDgnssImpl) {}
CfgDgnss::~CfgDgnss() = default;

CfgDgnss& CfgDgnss::operator=(const CfgDgnss& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgDgnss& CfgDgnss::operator=(CfgDgnss&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgDgnss::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgDgnss::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgDgnss::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgDgnss::resetImpl()
{
    m_pImpl->reset();
}

bool CfgDgnss::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgDgnss*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgDgnss::MsgIdParamType CfgDgnss::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgDgnss::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgDgnss::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgDgnss::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgDgnss::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgDgnss::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


