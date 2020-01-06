// Generated by commsdsl2comms v3.3.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::field::Lon field.

#pragma once

#include <cstdint>

namespace ublox
{

namespace field
{

/// @brief Common types and functions for
///     @ref ublox::field::Lon field.
struct LonCommon
{
    /// @brief Re-definition of the value type used by
    ///     ublox::field::Lon field.
    using ValueType = std::int32_t;

    /// @brief Name of the @ref ublox::field::Lon field.
    static const char* name()
    {
        return "lon";
    }
    
};

} // namespace field

} // namespace ublox


