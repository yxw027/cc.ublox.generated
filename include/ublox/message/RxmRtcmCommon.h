// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::RxmRtcm message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>
#include "ublox/field/Res2Common.h"

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::RxmRtcm message.
/// @see ublox::message::RxmRtcmFields
struct RxmRtcmFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::RxmRtcmFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::RxmRtcmFields::Version field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::RxmRtcmFields::Version field.
        static const char* name()
        {
            return "version";
        }
        
    };
    
    /// @brief Common functions for
    ///     @ref ublox::message::RxmRtcmFields::Flags field.
    struct FlagsCommon
    {
        /// @brief Name of the @ref ublox::message::RxmRtcmFields::Flags field.
        static const char* name()
        {
            return "flags";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref ublox::message::RxmRtcmFields::Flags field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "crcFailed"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::RxmRtcmFields::Reserved1 field.
    struct Reserved1Common : public ublox::field::Res2Common
    {
        /// @brief Name of the @ref ublox::message::RxmRtcmFields::Reserved1 field.
        static const char* name()
        {
            return "reserved1";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::RxmRtcmFields::RefStation field.
    struct RefStationCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::RxmRtcmFields::RefStation field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref ublox::message::RxmRtcmFields::RefStation field.
        static const char* name()
        {
            return "refStation";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::RxmRtcmFields::MsgType field.
    struct MsgTypeCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::RxmRtcmFields::MsgType field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref ublox::message::RxmRtcmFields::MsgType field.
        static const char* name()
        {
            return "msgType";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::RxmRtcm message.
/// @see ublox::message::RxmRtcm
struct RxmRtcmCommon
{
    /// @brief Name of the @ref ublox::message::RxmRtcm message.
    static const char* name()
    {
        return "RXM-RTCM";
    }
    
};

} // namespace message

} // namespace ublox

