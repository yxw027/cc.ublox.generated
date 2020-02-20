// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::field::HMSL field.

#pragma once

#include <cstdint>

namespace ublox
{

namespace field
{

/// @brief Common types and functions for
///     @ref ublox::field::HMSL field.
struct HMSLCommon
{
    /// @brief Re-definition of the value type used by
    ///     ublox::field::HMSL field.
    using ValueType = std::int32_t;

    /// @brief Name of the @ref ublox::field::HMSL field.
    static const char* name()
    {
        return "hMSL";
    }
    
};

} // namespace field

} // namespace ublox

