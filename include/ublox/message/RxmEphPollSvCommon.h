// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::RxmEphPollSv message and its fields.

#pragma once

#include <cstdint>

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::RxmEphPollSv message.
/// @see ublox::message::RxmEphPollSvFields
struct RxmEphPollSvFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::RxmEphPollSvFields::Svid field.
    struct SvidCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::RxmEphPollSvFields::Svid field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::RxmEphPollSvFields::Svid field.
        static const char* name()
        {
            return "svid";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::RxmEphPollSv message.
/// @see ublox::message::RxmEphPollSv
struct RxmEphPollSvCommon
{
    /// @brief Name of the @ref ublox::message::RxmEphPollSv message.
    static const char* name()
    {
        return "RXM-EPH (Poll SV)";
    }
    
};

} // namespace message

} // namespace ublox


