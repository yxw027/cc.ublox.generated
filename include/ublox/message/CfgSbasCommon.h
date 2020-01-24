// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::CfgSbas message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::CfgSbas message.
/// @see ublox::message::CfgSbasFields
struct CfgSbasFieldsCommon
{
    /// @brief Common functions for
    ///     @ref ublox::message::CfgSbasFields::Mode field.
    struct ModeCommon
    {
        /// @brief Name of the @ref ublox::message::CfgSbasFields::Mode field.
        static const char* name()
        {
            return "mode";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref ublox::message::CfgSbasFields::Mode field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "enabled",
                "test"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
    /// @brief Common functions for
    ///     @ref ublox::message::CfgSbasFields::Usage field.
    struct UsageCommon
    {
        /// @brief Name of the @ref ublox::message::CfgSbasFields::Usage field.
        static const char* name()
        {
            return "usage";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref ublox::message::CfgSbasFields::Usage field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "range",
                "diffCorr",
                "integrity"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgSbasFields::MaxSBAS field.
    struct MaxSBASCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::CfgSbasFields::MaxSBAS field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::CfgSbasFields::MaxSBAS field.
        static const char* name()
        {
            return "maxSBAS";
        }
        
    };
    
    /// @brief Common functions for
    ///     @ref ublox::message::CfgSbasFields::Scanmode2 field.
    struct Scanmode2Common
    {
        /// @brief Name of the @ref ublox::message::CfgSbasFields::Scanmode2 field.
        static const char* name()
        {
            return "scanmode2";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref ublox::message::CfgSbasFields::Scanmode2 field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "PRN152",
                "PRN153",
                "PRN154",
                "PRN155",
                "PRN156",
                "PRN157",
                "PRN158"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
    /// @brief Common functions for
    ///     @ref ublox::message::CfgSbasFields::Scanmode1 field.
    struct Scanmode1Common
    {
        /// @brief Name of the @ref ublox::message::CfgSbasFields::Scanmode1 field.
        static const char* name()
        {
            return "scanmode1";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref ublox::message::CfgSbasFields::Scanmode1 field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "PRN120",
                "PRN121",
                "PRN122",
                "PRN123",
                "PRN124",
                "PRN125",
                "PRN126",
                "PRN127",
                "PRN128",
                "PRN129",
                "PRN130",
                "PRN131",
                "PRN132",
                "PRN133",
                "PRN134",
                "PRN135",
                "PRN136",
                "PRN137",
                "PRN138",
                "PRN139",
                "PRN140",
                "PRN141",
                "PRN142",
                "PRN143",
                "PRN144",
                "PRN145",
                "PRN146",
                "PRN147",
                "PRN148",
                "PRN149",
                "PRN150",
                "PRN151"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::CfgSbas message.
/// @see ublox::message::CfgSbas
struct CfgSbasCommon
{
    /// @brief Name of the @ref ublox::message::CfgSbas message.
    static const char* name()
    {
        return "CFG-SBAS";
    }
    
};

} // namespace message

} // namespace ublox


