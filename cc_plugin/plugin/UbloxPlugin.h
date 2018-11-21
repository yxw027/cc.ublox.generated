#pragma once

#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include "comms_champion/Plugin.h"

namespace ublox
{

namespace cc_plugin
{

namespace plugin
{

class UbloxPlugin : public comms_champion::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ublox" FILE "UbloxPlugin.json")
    Q_INTERFACES(comms_champion::Plugin)

public:
    UbloxPlugin();
    virtual ~UbloxPlugin();
};

} // namespace plugin

} // namespace cc_plugin

} // namespace ublox

