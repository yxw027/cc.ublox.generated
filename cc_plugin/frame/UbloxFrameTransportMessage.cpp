#include "UbloxFrameTransportMessage.h"

#include "comms_champion/property/field.h"
#include "cc_plugin/field/MsgId.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace frame
{

namespace
{

struct SyncLayer
{
    static QVariantMap createProps_sync()
    {
        using Field = ublox::frame::UbloxFrameLayers<>::SyncMembers::Sync;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

struct IdLayer
{
    static QVariantMap createProps_msgId()
    {
        using Field = ublox::frame::UbloxFrameLayers<>::IdMembers::MsgId;
        return cc_plugin::field::createProps_msgId(Field::name());
        
    }
    
};

struct LengthLayer
{
    static QVariantMap createProps_lENGTH()
    {
        using Field = ublox::frame::UbloxFrameLayers<>::LengthMembers::LENGTH;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

struct PayloadLayer
{
    static QVariantMap createProps_payload()
    {
        return cc::property::field::ArrayList().name("Payload").asMap();
    }
    
};

struct ChecksumLayer
{
    static QVariantMap createProps_checksum()
    {
        using Field = ublox::frame::UbloxFrameLayers<>::ChecksumMembers::Checksum;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};


QVariantList createProps()
{
     QVariantList props;
     props.append(SyncLayer::createProps_sync());
     props.append(IdLayer::createProps_msgId());
     props.append(LengthLayer::createProps_lENGTH());
     props.append(PayloadLayer::createProps_payload());
     props.append(ChecksumLayer::createProps_checksum());
     return props;
}

} // namespace

const QVariantList& UbloxFrameTransportMessage::fieldsPropertiesImpl() const
{
    static const QVariantList Props = createProps();
    return Props;
}

comms::ErrorStatus UbloxFrameTransportMessage::readImpl(ReadIterator& iter, std::size_t len)
{
    len -= 2U;
    auto es = doReadUntilAndUpdateLen<4U>(iter, len);
    if (es == comms::ErrorStatus::Success) {
        len += 2U;
        es = doReadFrom<4U>(iter, len);
    }

    return es;
}

} // namespace frame

} // namespace cc_plugin

} // namespace ublox

