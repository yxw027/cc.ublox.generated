// Generated by commsdsl2comms v3.3.2

#include "EsfInsPoll.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/EsfInsPoll.h"
namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

QVariantList createProps()
{
    QVariantList props;
    return props;
}

} // namespace

class EsfInsPollImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::EsfInsPoll<ublox::cc_plugin::Message>,
        EsfInsPollImpl
    >
{
public:
    EsfInsPollImpl() = default;
    EsfInsPollImpl(const EsfInsPollImpl&) = delete;
    EsfInsPollImpl(EsfInsPollImpl&&) = delete;
    virtual ~EsfInsPollImpl() = default;
    EsfInsPollImpl& operator=(const EsfInsPollImpl&) = default;
    EsfInsPollImpl& operator=(EsfInsPollImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

EsfInsPoll::EsfInsPoll() : m_pImpl(new EsfInsPollImpl) {}
EsfInsPoll::~EsfInsPoll() = default;

EsfInsPoll& EsfInsPoll::operator=(const EsfInsPoll& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

EsfInsPoll& EsfInsPoll::operator=(EsfInsPoll&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* EsfInsPoll::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& EsfInsPoll::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void EsfInsPoll::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void EsfInsPoll::resetImpl()
{
    m_pImpl->reset();
}

bool EsfInsPoll::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const EsfInsPoll*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

EsfInsPoll::MsgIdParamType EsfInsPoll::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus EsfInsPoll::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus EsfInsPoll::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool EsfInsPoll::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t EsfInsPoll::lengthImpl() const
{
    return m_pImpl->length();
}

bool EsfInsPoll::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


