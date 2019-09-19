#include "MonPatch.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/MonPatch.h"
namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_version()
{
    using Field = ublox::message::MonPatchFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_nEntries()
{
    using Field = ublox::message::MonPatchFields<>::NEntries;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

struct ListMembers
{
    struct ElementMembers
    {
        struct PatchInfoMembers
        {
            static QVariantMap createProps_bits()
            {
                using Field = ublox::message::MonPatchFields<>::ListMembers::ElementMembers::PatchInfoMembers::Bits;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add(0U, "activated")
                        .asMap();
                
            }
            
            static QVariantMap createProps_location()
            {
                using Field = ublox::message::MonPatchFields<>::ListMembers::ElementMembers::PatchInfoMembers::Location;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .add("eFuse", 0)
                        .add("ROM", 1)
                        .add("BBR", 2)
                        .add("FileSystem", 3)
                        .asMap();
                
            }
            
            static QVariantMap createProps_res4()
            {
                using Field = ublox::message::MonPatchFields<>::ListMembers::ElementMembers::PatchInfoMembers::Res4;
                return
                    cc::property::field::ForField<Field>()
                        .name(Field::name())
                        .serialisedHidden()
                        .hidden()
                        .asMap();
                
            }
            
        };
        
        static QVariantMap createProps_patchInfo()
        {
            using Field = ublox::message::MonPatchFields<>::ListMembers::ElementMembers::PatchInfo;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .add(PatchInfoMembers::createProps_bits())
                    .add(PatchInfoMembers::createProps_location())
                    .add(PatchInfoMembers::createProps_res4())
                    .asMap();
            
        }
        
        static QVariantMap createProps_comparatorNumber()
        {
            using Field = ublox::message::MonPatchFields<>::ListMembers::ElementMembers::ComparatorNumber;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_patchAddress()
        {
            using Field = ublox::message::MonPatchFields<>::ListMembers::ElementMembers::PatchAddress;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
        static QVariantMap createProps_patchData()
        {
            using Field = ublox::message::MonPatchFields<>::ListMembers::ElementMembers::PatchData;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
    };
    
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::MonPatchFields<>::ListMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ElementMembers::createProps_patchInfo())
                .add(ElementMembers::createProps_comparatorNumber())
                .add(ElementMembers::createProps_patchAddress())
                .add(ElementMembers::createProps_patchData())
                .asMap();
        
    }
    
};

static QVariantMap createProps_list()
{
    using Field = ublox::message::MonPatchFields<>::List;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ListMembers::createProps_element())
            .serialisedHidden()
            .appendIndexToElementName()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_nEntries());
    props.append(createProps_list());
    return props;
}

} // namespace

class MonPatchImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::MonPatch<ublox::cc_plugin::Message>,
        MonPatchImpl
    >
{
public:
    MonPatchImpl() = default;
    MonPatchImpl(const MonPatchImpl&) = delete;
    MonPatchImpl(MonPatchImpl&&) = delete;
    virtual ~MonPatchImpl() = default;
    MonPatchImpl& operator=(const MonPatchImpl&) = default;
    MonPatchImpl& operator=(MonPatchImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

MonPatch::MonPatch() : m_pImpl(new MonPatchImpl) {}
MonPatch::~MonPatch() = default;

MonPatch& MonPatch::operator=(const MonPatch& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

MonPatch& MonPatch::operator=(MonPatch&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* MonPatch::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& MonPatch::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void MonPatch::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void MonPatch::resetImpl()
{
    m_pImpl->reset();
}

bool MonPatch::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const MonPatch*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

MonPatch::MsgIdParamType MonPatch::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus MonPatch::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus MonPatch::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool MonPatch::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t MonPatch::lengthImpl() const
{
    return m_pImpl->length();
}

bool MonPatch::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


