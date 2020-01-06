// Generated by commsdsl2comms v3.3.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::NavHpposllh message and its fields.

#pragma once

#include <cstdint>
#include "ublox/field/HMSLCommon.h"
#include "ublox/field/HeightCommon.h"
#include "ublox/field/ItowCommon.h"
#include "ublox/field/LatCommon.h"
#include "ublox/field/LonCommon.h"
#include "ublox/field/Res3Common.h"

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::NavHpposllh message.
/// @see ublox::message::NavHpposllhFields
struct NavHpposllhFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavHpposllhFields::Version field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::NavHpposllhFields::Version field.
        static const char* name()
        {
            return "version";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::Reserved1 field.
    struct Reserved1Common : public ublox::field::Res3Common
    {
        /// @brief Name of the @ref ublox::message::NavHpposllhFields::Reserved1 field.
        static const char* name()
        {
            return "reserved1";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::Itow field.
    using ItowCommon = ublox::field::ItowCommon;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::Lon field.
    using LonCommon = ublox::field::LonCommon;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::Lat field.
    using LatCommon = ublox::field::LatCommon;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::Height field.
    using HeightCommon = ublox::field::HeightCommon;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::HMSL field.
    using HMSLCommon = ublox::field::HMSLCommon;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::LonHp field.
    struct LonHpCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavHpposllhFields::LonHp field.
        using ValueType = std::int8_t;
    
        /// @brief Name of the @ref ublox::message::NavHpposllhFields::LonHp field.
        static const char* name()
        {
            return "lonHp";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::LatHp field.
    struct LatHpCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavHpposllhFields::LatHp field.
        using ValueType = std::int8_t;
    
        /// @brief Name of the @ref ublox::message::NavHpposllhFields::LatHp field.
        static const char* name()
        {
            return "latHp";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::HeigthHp field.
    struct HeigthHpCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavHpposllhFields::HeigthHp field.
        using ValueType = std::int8_t;
    
        /// @brief Name of the @ref ublox::message::NavHpposllhFields::HeigthHp field.
        static const char* name()
        {
            return "heigthHp";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::HMSLHp field.
    struct HMSLHpCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavHpposllhFields::HMSLHp field.
        using ValueType = std::int8_t;
    
        /// @brief Name of the @ref ublox::message::NavHpposllhFields::HMSLHp field.
        static const char* name()
        {
            return "hMSLHp";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::HAcc field.
    struct HAccCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavHpposllhFields::HAcc field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::NavHpposllhFields::HAcc field.
        static const char* name()
        {
            return "hAcc";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::NavHpposllhFields::VAcc field.
    struct VAccCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::NavHpposllhFields::VAcc field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::NavHpposllhFields::VAcc field.
        static const char* name()
        {
            return "vAcc";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::NavHpposllh message.
/// @see ublox::message::NavHpposllh
struct NavHpposllhCommon
{
    /// @brief Name of the @ref ublox::message::NavHpposllh message.
    static const char* name()
    {
        return "NAV-HPPOSLLH";
    }
    
};

} // namespace message

} // namespace ublox


