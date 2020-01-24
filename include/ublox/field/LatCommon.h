// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::field::Lat field.

#pragma once

#include <cstdint>

namespace ublox
{

namespace field
{

/// @brief Common types and functions for
///     @ref ublox::field::Lat field.
struct LatCommon
{
    /// @brief Re-definition of the value type used by
    ///     ublox::field::Lat field.
    using ValueType = std::int32_t;

    /// @brief Name of the @ref ublox::field::Lat field.
    static const char* name()
    {
        return "lat";
    }
    
};

} // namespace field

} // namespace ublox


