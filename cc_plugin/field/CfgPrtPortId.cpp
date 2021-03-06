// Generated by commsdsl2comms v3.3.2

#include "CfgPrtPortId.h"

#include "comms_champion/property/field.h"
#include "ublox/field/CfgPrtPortId.h"


namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_cfgPrtPortId(const char* name, bool serHidden)
{
    static_cast<void>(serHidden);
    using Field = ublox::field::CfgPrtPortId<>;
    return
        cc::property::field::ForField<Field>()
            .name(name)
            .serialisedHidden(serHidden)
            .add("DDC", 0)
            .add("UART", 1)
            .add("USB", 3)
            .add("SPI", 4)
            .asMap();
    
}

} // namespace field

} // namespace cc_plugin

} // namespace ublox


