// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::NavTimeglo message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>
#include "ublox/field/ItowCommon.h"

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::NavTimeglo message.
/// @see ublox::message::NavTimegloFields
struct NavTimegloFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegloFields::Itow field.
    using ItowCommon = ublox::field::ItowCommon;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegloFields::TOD field.
    struct TODCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegloFields::TOD field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegloFields::TOD field.
        static const char* name()
        {
            return "TOD";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegloFields::FTOD field.
    struct FTODCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegloFields::FTOD field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegloFields::FTOD field.
        static const char* name()
        {
            return "fTOD";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegloFields::Nt field.
    struct NtCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegloFields::Nt field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegloFields::Nt field.
        static const char* name()
        {
            return "Nt";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegloFields::N4 field.
    struct N4Common
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegloFields::N4 field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegloFields::N4 field.
        static const char* name()
        {
            return "N4";
        }
        
    };
    
    /// @brief Common functions for
    ///     @ref ublox::message::NavTimegloFields::Valid field.
    struct ValidCommon
    {
        /// @brief Name of the @ref ublox::message::NavTimegloFields::Valid field.
        static const char* name()
        {
            return "valid";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref ublox::message::NavTimegloFields::Valid field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "todValid",
                "dateValid"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavTimegloFields::TAcc field.
    struct TAccCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavTimegloFields::TAcc field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::NavTimegloFields::TAcc field.
        static const char* name()
        {
            return "tAcc";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::NavTimeglo message.
/// @see ublox::message::NavTimeglo
struct NavTimegloCommon
{
    /// @brief Name of the @ref ublox::message::NavTimeglo message.
    static const char* name()
    {
        return "NAV-TIMEGLO";
    }
    
};

} // namespace message

} // namespace ublox


