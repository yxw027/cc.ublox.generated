#include "GnssId.h"

#include "comms_champion/property/field.h"
#include "ublox/field/GnssId.h"


namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_gnssId(const char* name, bool serHidden)
{
    static_cast<void>(serHidden);
    using Field = ublox::field::GnssId<>;
    return
        cc::property::field::ForField<Field>()
            .name(name)
            .serialisedHidden(serHidden)
            .add("GPS", 0)
            .add("SBAS", 1)
            .add("Galileo", 2)
            .add("BeiDou", 3)
            .add("IMES", 4)
            .add("QZSS", 5)
            .add("GLONASS", 6)
            .asMap();
    
}

} // namespace field

} // namespace cc_plugin

} // namespace ublox

