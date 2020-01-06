// Generated by commsdsl2comms v3.3.0

/// @file
/// @brief Contains definition of <b>"sec"</b> field.

#pragma once

#include <cstdint>
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/SecCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace field
{

/// @brief Definition of <b>"sec"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = ublox::options::DefaultOptions, typename... TExtraOpts>
struct Sec : public
    comms::field::IntValue<
        ublox::field::FieldBase<>,
        std::uint8_t,
        TExtraOpts...,
        comms::option::def::UnitsSeconds,
        comms::option::def::ValidNumValueRange<0, 60>
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return ublox::field::SecCommon::name();
    }
    
};

} // namespace field

} // namespace ublox


