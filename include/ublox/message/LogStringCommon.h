// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::LogString message and its fields.

#pragma once

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::LogString message.
/// @see ublox::message::LogStringFields
struct LogStringFieldsCommon
{
    /// @brief Scope for all the common definitions of the
    ///     @ref ublox::message::LogStringFields::Bytes field.
    struct BytesCommon
    {
        /// @brief Name of the @ref ublox::message::LogStringFields::Bytes field.
        static const char* name()
        {
            return "bytes";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::LogString message.
/// @see ublox::message::LogString
struct LogStringCommon
{
    /// @brief Name of the @ref ublox::message::LogString message.
    static const char* name()
    {
        return "LOG-STRING";
    }
    
};

} // namespace message

} // namespace ublox


