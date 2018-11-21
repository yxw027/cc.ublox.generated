#include "AidEphPollSv.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/AidEphPollSv.h"
namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_svid()
{
    using Field = ublox::message::AidEphPollSvFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_svid());
    return props;
}

} // namespace

class AidEphPollSvImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::AidEphPollSv<ublox::cc_plugin::Message>,
        AidEphPollSvImpl
    >
{
public:
    AidEphPollSvImpl() = default;
    AidEphPollSvImpl(const AidEphPollSvImpl&) = delete;
    AidEphPollSvImpl(AidEphPollSvImpl&&) = delete;
    virtual ~AidEphPollSvImpl() = default;
    AidEphPollSvImpl& operator=(const AidEphPollSvImpl&) = default;
    AidEphPollSvImpl& operator=(AidEphPollSvImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

AidEphPollSv::AidEphPollSv() : m_pImpl(new AidEphPollSvImpl) {}
AidEphPollSv::~AidEphPollSv() = default;

AidEphPollSv& AidEphPollSv::operator=(const AidEphPollSv& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

AidEphPollSv& AidEphPollSv::operator=(AidEphPollSv&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* AidEphPollSv::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& AidEphPollSv::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void AidEphPollSv::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void AidEphPollSv::resetImpl()
{
    m_pImpl->reset();
}

bool AidEphPollSv::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const AidEphPollSv*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

AidEphPollSv::MsgIdParamType AidEphPollSv::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus AidEphPollSv::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus AidEphPollSv::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool AidEphPollSv::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t AidEphPollSv::lengthImpl() const
{
    return m_pImpl->length();
}

bool AidEphPollSv::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

