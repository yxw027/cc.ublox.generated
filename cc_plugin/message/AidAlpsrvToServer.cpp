#include "AidAlpsrvToServer.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/AidAlpsrvToServer.h"
namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_idSize()
{
    using Field = ublox::message::AidAlpsrvToServerFields<>::IdSize;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_type()
{
    using Field = ublox::message::AidAlpsrvToServerFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_ofs()
{
    using Field = ublox::message::AidAlpsrvToServerFields<>::Ofs;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_size()
{
    using Field = ublox::message::AidAlpsrvToServerFields<>::Size;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_fileId()
{
    using Field = ublox::message::AidAlpsrvToServerFields<>::FileId;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

struct DataMembers
{
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::AidAlpsrvToServerFields<>::DataMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

static QVariantMap createProps_data()
{
    using Field = ublox::message::AidAlpsrvToServerFields<>::Data;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(DataMembers::createProps_element())
            .serialisedHidden()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_idSize());
    props.append(createProps_type());
    props.append(createProps_ofs());
    props.append(createProps_size());
    props.append(createProps_fileId());
    props.append(createProps_data());
    return props;
}

} // namespace

class AidAlpsrvToServerImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::AidAlpsrvToServer<ublox::cc_plugin::Message>,
        AidAlpsrvToServerImpl
    >
{
public:
    AidAlpsrvToServerImpl() = default;
    AidAlpsrvToServerImpl(const AidAlpsrvToServerImpl&) = delete;
    AidAlpsrvToServerImpl(AidAlpsrvToServerImpl&&) = delete;
    virtual ~AidAlpsrvToServerImpl() = default;
    AidAlpsrvToServerImpl& operator=(const AidAlpsrvToServerImpl&) = default;
    AidAlpsrvToServerImpl& operator=(AidAlpsrvToServerImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

AidAlpsrvToServer::AidAlpsrvToServer() : m_pImpl(new AidAlpsrvToServerImpl) {}
AidAlpsrvToServer::~AidAlpsrvToServer() = default;

AidAlpsrvToServer& AidAlpsrvToServer::operator=(const AidAlpsrvToServer& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

AidAlpsrvToServer& AidAlpsrvToServer::operator=(AidAlpsrvToServer&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* AidAlpsrvToServer::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& AidAlpsrvToServer::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void AidAlpsrvToServer::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void AidAlpsrvToServer::resetImpl()
{
    m_pImpl->reset();
}

bool AidAlpsrvToServer::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const AidAlpsrvToServer*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

AidAlpsrvToServer::MsgIdParamType AidAlpsrvToServer::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus AidAlpsrvToServer::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus AidAlpsrvToServer::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool AidAlpsrvToServer::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t AidAlpsrvToServer::lengthImpl() const
{
    return m_pImpl->length();
}

bool AidAlpsrvToServer::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

