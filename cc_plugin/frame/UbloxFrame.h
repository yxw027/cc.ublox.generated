// Generated by commsdsl2comms v3.3.2

#pragma once

#include "ublox/frame/UbloxFrame.h"
#include "cc_plugin/Message.h"
#include "cc_plugin/input/AllMessages.h"

namespace ublox
{

namespace cc_plugin
{

namespace frame
{

using UbloxFrame =
    ublox::frame::UbloxFrame<
        ublox::cc_plugin::Message,
        ublox::cc_plugin::input::AllMessages
    >;

} // namespace frame

} // namespace cc_plugin

} // namespace ublox


