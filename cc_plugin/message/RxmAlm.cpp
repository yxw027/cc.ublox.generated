#include "RxmAlm.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/RxmAlm.h"
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
    using Field = ublox::message::RxmAlmFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_week()
{
    using Field = ublox::message::RxmAlmFields<>::Week;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

struct DwrdMembers
{
    struct ListMembers
    {
        static QVariantMap createProps_element()
        {
            using Field = ublox::message::RxmAlmFields<>::DwrdMembers::ListMembers::Element;
            return
                cc::property::field::ForField<Field>()
                    .name(Field::name())
                    .asMap();
            
        }
        
    };
    
    static QVariantMap createProps_list()
    {
        using Field = ublox::message::RxmAlmFields<>::DwrdMembers::List;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ListMembers::createProps_element())
                .serialisedHidden()
                .appendIndexToElementName()
                .asMap();
        
    }
    
};

static QVariantMap createProps_dwrd()
{
    using Field = ublox::message::RxmAlmFields<>::Dwrd;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .uncheckable()
            .field(DwrdMembers::createProps_list())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_svid());
    props.append(createProps_week());
    props.append(createProps_dwrd());
    return props;
}

} // namespace

class RxmAlmImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::RxmAlm<ublox::cc_plugin::Message>,
        RxmAlmImpl
    >
{
public:
    RxmAlmImpl() = default;
    RxmAlmImpl(const RxmAlmImpl&) = delete;
    RxmAlmImpl(RxmAlmImpl&&) = delete;
    virtual ~RxmAlmImpl() = default;
    RxmAlmImpl& operator=(const RxmAlmImpl&) = default;
    RxmAlmImpl& operator=(RxmAlmImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

RxmAlm::RxmAlm() : m_pImpl(new RxmAlmImpl) {}
RxmAlm::~RxmAlm() = default;

RxmAlm& RxmAlm::operator=(const RxmAlm& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

RxmAlm& RxmAlm::operator=(RxmAlm&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* RxmAlm::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& RxmAlm::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void RxmAlm::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void RxmAlm::resetImpl()
{
    m_pImpl->reset();
}

bool RxmAlm::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const RxmAlm*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

RxmAlm::MsgIdParamType RxmAlm::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus RxmAlm::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus RxmAlm::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool RxmAlm::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t RxmAlm::lengthImpl() const
{
    return m_pImpl->length();
}

bool RxmAlm::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox


