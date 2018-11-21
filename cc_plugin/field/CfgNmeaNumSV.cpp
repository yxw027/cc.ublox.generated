#include "CfgNmeaNumSV.h"

#include "comms_champion/property/field.h"
#include "ublox/field/CfgNmeaNumSV.h"


namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_cfgNmeaNumSV(const char* name, bool serHidden)
{
    static_cast<void>(serHidden);
    using Field = ublox::field::CfgNmeaNumSV<>;
    return
        cc::property::field::ForField<Field>()
            .name(name)
            .serialisedHidden(serHidden)
            .asMap();
    
}

} // namespace field

} // namespace cc_plugin

} // namespace ublox

