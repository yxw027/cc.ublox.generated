#include "AidEph.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/AidEph.h"
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
    using Field = ublox::message::AidEphFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_how()
{
    using Field = ublox::message::AidEphFields<>::How;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

struct SfdMembers
{
    struct ListsMembers
    {
        struct Sf1dMembers
        {
            static QVariantMap createProps_element()
            {
                using Field = ublox::message::AidEphFields<>::SfdMembers::ListsMembers::Sf1dMembers::Element;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .asMap();
                
            }
            
        };
        
        static QVariantMap createProps_sf1d()
        {
            using Field = ublox::message::AidEphFields<>::SfdMembers::ListsMembers::Sf1d;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add(Sf1dMembers::createProps_element())
                    .serialisedHidden()
                    .asMap();
            
        }
        
        struct Sf2dMembers
        {
            static QVariantMap createProps_element()
            {
                using Field = ublox::message::AidEphFields<>::SfdMembers::ListsMembers::Sf2dMembers::Element;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .asMap();
                
            }
            
        };
        
        static QVariantMap createProps_sf2d()
        {
            using Field = ublox::message::AidEphFields<>::SfdMembers::ListsMembers::Sf2d;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add(Sf2dMembers::createProps_element())
                    .serialisedHidden()
                    .asMap();
            
        }
        
        struct Sf3dMembers
        {
            static QVariantMap createProps_element()
            {
                using Field = ublox::message::AidEphFields<>::SfdMembers::ListsMembers::Sf3dMembers::Element;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .asMap();
                
            }
            
        };
        
        static QVariantMap createProps_sf3d()
        {
            using Field = ublox::message::AidEphFields<>::SfdMembers::ListsMembers::Sf3d;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add(Sf3dMembers::createProps_element())
                    .serialisedHidden()
                    .asMap();
            
        }
        
    };
    
    static QVariantMap createProps_lists()
    {
        using Field = ublox::message::AidEphFields<>::SfdMembers::Lists;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ListsMembers::createProps_sf1d())
                .add(ListsMembers::createProps_sf2d())
                .add(ListsMembers::createProps_sf3d())
                .asMap();
        
    }
    
};

static QVariantMap createProps_sfd()
{
    using Field = ublox::message::AidEphFields<>::Sfd;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .uncheckable()
            .field(SfdMembers::createProps_lists())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_svid());
    props.append(createProps_how());
    props.append(createProps_sfd());
    return props;
}

} // namespace

class AidEphImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::AidEph<ublox::cc_plugin::Message>,
        AidEphImpl
    >
{
public:
    AidEphImpl() = default;
    AidEphImpl(const AidEphImpl&) = delete;
    AidEphImpl(AidEphImpl&&) = delete;
    virtual ~AidEphImpl() = default;
    AidEphImpl& operator=(const AidEphImpl&) = default;
    AidEphImpl& operator=(AidEphImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

AidEph::AidEph() : m_pImpl(new AidEphImpl) {}
AidEph::~AidEph() = default;

AidEph& AidEph::operator=(const AidEph& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

AidEph& AidEph::operator=(AidEph&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* AidEph::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& AidEph::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void AidEph::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void AidEph::resetImpl()
{
    m_pImpl->reset();
}

bool AidEph::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const AidEph*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

AidEph::MsgIdParamType AidEph::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus AidEph::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus AidEph::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool AidEph::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t AidEph::lengthImpl() const
{
    return m_pImpl->length();
}

bool AidEph::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

