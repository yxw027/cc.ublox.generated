#include "GeofenceState.h"

#include "comms_champion/property/field.h"
#include "ublox/field/GeofenceState.h"


namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_geofenceState(const char* name, bool serHidden)
{
    static_cast<void>(serHidden);
    using Field = ublox::field::GeofenceState<>;
    return
        cc::property::field::ForField<Field>()
            .name(name)
            .serialisedHidden(serHidden)
            .add("Unknown", 0)
            .add("Inside", 1)
            .add("Outside", 2)
            .asMap();
    
}

} // namespace field

} // namespace cc_plugin

} // namespace ublox

