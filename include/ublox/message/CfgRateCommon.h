// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::CfgRate message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::CfgRate message.
/// @see ublox::message::CfgRateFields
struct CfgRateFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgRateFields::MeasRate field.
    struct MeasRateCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::CfgRateFields::MeasRate field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref ublox::message::CfgRateFields::MeasRate field.
        static const char* name()
        {
            return "measRate";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgRateFields::NavRate field.
    struct NavRateCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::CfgRateFields::NavRate field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref ublox::message::CfgRateFields::NavRate field.
        static const char* name()
        {
            return "navRate";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgRateFields::TimeRef field.
    struct TimeRefCommon
    {
        /// @brief Values enumerator for
        ///     @ref ublox::message::CfgRateFields::TimeRef field.
        enum class ValueType : std::uint16_t
        {
            UTC = 0, ///< value @b UTC
            GPS = 1, ///< value @b GPS
            GLONASS = 2, ///< value @b GLONASS
            BeiDou = 3, ///< value @b BeiDou
            Galileo = 4, ///< value @b Galileo
            
            // --- Extra values generated for convenience ---
            FirstValue = 0, ///< First defined value.
            LastValue = 4, ///< Last defined value.
            ValuesLimit = 5, ///< Upper limit for defined values.
            
        };
        
        /// @brief Name of the @ref ublox::message::CfgRateFields::TimeRef field.
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
                "GLONASS",
                "BeiDou",
                "Galileo"
            };
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            
            if (MapSize <= static_cast<std::size_t>(val)) {
                return nullptr;
            }
            
            return Map[static_cast<std::size_t>(val)];
        }
        
    };
    
    /// @brief Values enumerator for
    ///     @ref ublox::message::CfgRateFields::TimeRef field.
    using TimeRefVal = TimeRefCommon::ValueType;
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::CfgRate message.
/// @see ublox::message::CfgRate
struct CfgRateCommon
{
    /// @brief Name of the @ref ublox::message::CfgRate message.
    static const char* name()
    {
        return "CFG-RATE";
    }
    
};

} // namespace message

} // namespace ublox


