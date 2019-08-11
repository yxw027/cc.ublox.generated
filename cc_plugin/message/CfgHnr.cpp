#include "CfgHnr.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/CfgHnr.h"
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

static QVariantMap createProps_highNavRate()
{
    using Field = ublox::message::CfgHnrFields<>::HighNavRate;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::CfgHnrFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_highNavRate());
    props.append(createProps_reserved1());
    return props;
}

} // namespace

class CfgHnrImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::CfgHnr<ublox::cc_plugin::Message>,
        CfgHnrImpl
    >
{
public:
    CfgHnrImpl() = default;
    CfgHnrImpl(const CfgHnrImpl&) = delete;
    CfgHnrImpl(CfgHnrImpl&&) = delete;
    virtual ~CfgHnrImpl() = default;
    CfgHnrImpl& operator=(const CfgHnrImpl&) = default;
    CfgHnrImpl& operator=(CfgHnrImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

CfgHnr::CfgHnr() : m_pImpl(new CfgHnrImpl) {}
CfgHnr::~CfgHnr() = default;

CfgHnr& CfgHnr::operator=(const CfgHnr& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

CfgHnr& CfgHnr::operator=(CfgHnr&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* CfgHnr::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& CfgHnr::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void CfgHnr::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void CfgHnr::resetImpl()
{
    m_pImpl->reset();
}

bool CfgHnr::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const CfgHnr*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

CfgHnr::MsgIdParamType CfgHnr::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus CfgHnr::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus CfgHnr::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool CfgHnr::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t CfgHnr::lengthImpl() const
{
    return m_pImpl->length();
}

bool CfgHnr::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


