// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::CfgTp message and its fields.

#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <type_traits>
#include <utility>
#include "ublox/field/Res1Common.h"

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::CfgTp message.
/// @see ublox::message::CfgTpFields
struct CfgTpFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgTpFields::Interval field.
    struct IntervalCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::CfgTpFields::Interval field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::CfgTpFields::Interval field.
        static const char* name()
        {
            return "interval";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgTpFields::Length field.
    struct LengthCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::CfgTpFields::Length field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::CfgTpFields::Length field.
        static const char* name()
        {
            return "length";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgTpFields::Status field.
    struct StatusCommon
    {
        /// @brief Values enumerator for
        ///     @ref ublox::message::CfgTpFields::Status field.
        enum class ValueType : std::int8_t
        {
            Negative = -1, ///< value @b Negative
            Off = 0, ///< value @b Off
            Positive = 1, ///< value @b Positive
            
            // --- Extra values generated for convenience ---
            FirstValue = -1, ///< First defined value.
            LastValue = 1, ///< Last defined value.
            ValuesLimit = 2, ///< Upper limit for defined values.
            
        };
        
        /// @brief Name of the @ref ublox::message::CfgTpFields::Status field.
        static const char* name()
        {
            return "status";
        }
        
        /// @brief Retrieve name of the enum value
        static const char* valueName(ValueType val)
        {
            using NameInfo = std::pair<ValueType, const char*>;
            static const NameInfo Map[] = {
                std::make_pair(ValueType::Negative, "Negative"),
                std::make_pair(ValueType::Off, "Off"),
                std::make_pair(ValueType::Positive, "Positive")
            };
            
            auto iter = std::lower_bound(
                std::begin(Map), std::end(Map), val,
                [](const NameInfo& info, ValueType v) -> bool
                {
                    return info.first < v;
                });
            
            if ((iter == std::end(Map)) || (iter->first != val)) {
                return nullptr;
            }
            
            return iter->second;
        }
        
    };
    
    /// @brief Values enumerator for
    ///     @ref ublox::message::CfgTpFields::Status field.
    using StatusVal = StatusCommon::ValueType;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgTpFields::TimeRef field.
    struct TimeRefCommon
    {
        /// @brief Values enumerator for
        ///     @ref ublox::message::CfgTpFields::TimeRef field.
        enum class ValueType : std::uint8_t
        {
            UTC = 0, ///< value @b UTC
            GPS = 1, ///< value @b GPS
            Local = 2, ///< value @b Local
            
            // --- Extra values generated for convenience ---
            FirstValue = 0, ///< First defined value.
            LastValue = 2, ///< Last defined value.
            ValuesLimit = 3, ///< Upper limit for defined values.
            
        };
        
        /// @brief Name of the @ref ublox::message::CfgTpFields::TimeRef field.
        static const char* name()
        {
            return "timeRef";
        }
        
        /// @brief Retrieve name of the enum value
        static const char* valueName(ValueType val)
        {
            static const char* Map[] = {
                "UTC",
                "GPS",
                "Local"
            };
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            
            if (MapSize <= static_cast<std::size_t>(val)) {
                return nullptr;
            }
            
            return Map[static_cast<std::size_t>(val)];
        }
        
    };
    
    /// @brief Values enumerator for
    ///     @ref ublox::message::CfgTpFields::TimeRef field.
    using TimeRefVal = TimeRefCommon::ValueType;
    
    /// @brief Common functions for
    ///     @ref ublox::message::CfgTpFields::Flags field.
    struct FlagsCommon
    {
        /// @brief Name of the @ref ublox::message::CfgTpFields::Flags field.
        static const char* name()
        {
            return "flags";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref ublox::message::CfgTpFields::Flags field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "syncMode"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgTpFields::Res field.
    struct ResCommon : public ublox::field::Res1Common
    {
        /// @brief Name of the @ref ublox::message::CfgTpFields::Res field.
        static const char* name()
        {
            return "res";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgTpFields::AntennaCableDelay field.
    struct AntennaCableDelayCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::CfgTpFields::AntennaCableDelay field.
        using ValueType = std::int16_t;
    
        /// @brief Name of the @ref ublox::message::CfgTpFields::AntennaCableDelay field.
        static const char* name()
        {
            return "antennaCableDelay";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgTpFields::RfGroupDelay field.
    struct RfGroupDelayCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::CfgTpFields::RfGroupDelay field.
        using ValueType = std::int16_t;
    
        /// @brief Name of the @ref ublox::message::CfgTpFields::RfGroupDelay field.
        static const char* name()
        {
            return "rfGroupDelay";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgTpFields::UserDelay field.
    struct UserDelayCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::CfgTpFields::UserDelay field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::CfgTpFields::UserDelay field.
        static const char* name()
        {
            return "userDelay";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::CfgTp message.
/// @see ublox::message::CfgTp
struct CfgTpCommon
{
    /// @brief Name of the @ref ublox::message::CfgTp message.
    static const char* name()
    {
        return "CFG-TP";
    }
    
};

} // namespace message

} // namespace ublox


