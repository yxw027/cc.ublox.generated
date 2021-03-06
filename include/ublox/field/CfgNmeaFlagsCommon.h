// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::field::CfgNmeaFlags field.

#pragma once

#include <type_traits>

namespace ublox
{

namespace field
{

/// @brief Common functions for
///     @ref ublox::field::CfgNmeaFlags field.
struct CfgNmeaFlagsCommon
{
    /// @brief Name of the @ref ublox::field::CfgNmeaFlags field.
    static const char* name()
    {
        return "cfgNmeaFlags";
    }
    
    /// @brief Retrieve name of the bit of
    ///     @ref ublox::field::CfgNmeaFlags field.
    static const char* bitName(std::size_t idx)
    {
        static const char* Map[] = {
            "compat",
            "consider",
            "limit82",
            "highPrec"
        };
    
        static const std::size_t MapSize = std::extent<decltype(Map)>::value;
        if (MapSize <= idx) {
            return nullptr;
        }
    
        return Map[idx];
    }
    
};

} // namespace field

} // namespace ublox


