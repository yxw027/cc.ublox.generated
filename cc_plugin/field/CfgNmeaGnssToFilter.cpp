#include "CfgNmeaGnssToFilter.h"

#include "comms_champion/property/field.h"
#include "ublox/field/CfgNmeaGnssToFilter.h"


namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_cfgNmeaGnssToFilter(const char* name, bool serHidden)
{
    static_cast<void>(serHidden);
    using Field = ublox::field::CfgNmeaGnssToFilter<>;
    return
        cc::property::field::ForField<Field>()
            .name(name)
            .serialisedHidden(serHidden)
            .add(0U, "gps")
            .add(1U, "sbas")
            .add(4U, "qzss")
            .add(5U, "glonass")
            .add(6U, "beidou")
            .asMap();
    
}

} // namespace field

} // namespace cc_plugin

} // namespace ublox

