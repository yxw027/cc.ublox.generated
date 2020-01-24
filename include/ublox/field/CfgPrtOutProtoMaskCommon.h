// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::field::CfgPrtOutProtoMask field.

#pragma once

#include <type_traits>

namespace ublox
{

namespace field
{

/// @brief Common functions for
///     @ref ublox::field::CfgPrtOutProtoMask field.
struct CfgPrtOutProtoMaskCommon
{
    /// @brief Name of the @ref ublox::field::CfgPrtOutProtoMask field.
    static const char* name()
    {
        return "cfgPrtOutProtoMask";
    }
    
    /// @brief Retrieve name of the bit of
    ///     @ref ublox::field::CfgPrtOutProtoMask field.
    static const char* bitName(std::size_t idx)
    {
        static const char* Map[] = {
            "outUbx",
            "outNmea",
            nullptr,
            nullptr,
            nullptr,
            "outRtcm3"
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


