// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::NavTimegal message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>
#include "ublox/field/ItowCommon.h"

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::NavTimegal message.
/// @see ublox::message::NavTimegalFields
struct NavTimegalFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegalFields::Itow field.
    using ItowCommon = ublox::field::ItowCommon;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegalFields::GalTow field.
    struct GalTowCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegalFields::GalTow field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegalFields::GalTow field.
        static const char* name()
        {
            return "galTow";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegalFields::FGalTow field.
    struct FGalTowCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegalFields::FGalTow field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegalFields::FGalTow field.
        static const char* name()
        {
            return "fGalTow";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegalFields::GalWno field.
    struct GalWnoCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegalFields::GalWno field.
        using ValueType = std::int16_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegalFields::GalWno field.
        static const char* name()
        {
            return "galWno";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegalFields::LeapS field.
    struct LeapSCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegalFields::LeapS field.
        using ValueType = std::int8_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegalFields::LeapS field.
        static const char* name()
        {
            return "leapS";
        }
        
    };
    
    /// @brief Common functions for
    ///     @ref ublox::message::NavTimegalFields::Valid field.
    struct ValidCommon
    {
        /// @brief Name of the @ref ublox::message::NavTimegalFields::Valid field.
        static const char* name()
        {
            return "valid";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref ublox::message::NavTimegalFields::Valid field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "galTowValid",
                "galWnoValid",
                "leapSValid"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegalFields::TAcc field.
    struct TAccCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegalFields::TAcc field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegalFields::TAcc field.
        static const char* name()
        {
            return "tAcc";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::NavTimegal message.
/// @see ublox::message::NavTimegal
struct NavTimegalCommon
{
    /// @brief Name of the @ref ublox::message::NavTimegal message.
    static const char* name()
    {
        return "NAV-TIMEGAL";
    }
    
};

} // namespace message

} // namespace ublox


