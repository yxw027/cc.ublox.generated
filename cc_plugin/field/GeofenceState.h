#pragma once

#include <QtCore/QVariantMap>

namespace ublox
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_geofenceState(const char* name, bool serHidden = false);

} // namespace field

} // namespace cc_plugin

} // namespace ublox

