// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::MonVer message and its fields.

#pragma once

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::MonVer message.
/// @see ublox::message::MonVerFields
struct MonVerFieldsCommon
{
    /// @brief Scope for all the common definitions of the
    ///     @ref ublox::message::MonVerFields::SwVersion field.
    struct SwVersionCommon
    {
        /// @brief Name of the @ref ublox::message::MonVerFields::SwVersion field.
        static const char* name()
        {
            return "swVersion";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the
    ///     @ref ublox::message::MonVerFields::HwVersion field.
    struct HwVersionCommon
    {
        /// @brief Name of the @ref ublox::message::MonVerFields::HwVersion field.
        static const char* name()
        {
            return "hwVersion";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref ublox::message::MonVerFields::List list.
    struct ListMembersCommon
    {
        /// @brief Scope for all the common definitions of the
        ///     @ref ublox::message::MonVerFields::ListMembers::Extension field.
        struct ExtensionCommon
        {
            /// @brief Name of the @ref ublox::message::MonVerFields::ListMembers::Extension field.
            static const char* name()
            {
                return "extension";
            }
            
        };
        
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref ublox::message::MonVerFields::List field.
    struct ListCommon
    {
        /// @brief Name of the @ref ublox::message::MonVerFields::List field.
        static const char* name()
        {
            return "list";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::MonVer message.
/// @see ublox::message::MonVer
struct MonVerCommon
{
    /// @brief Name of the @ref ublox::message::MonVer message.
    static const char* name()
    {
        return "MON-VER";
    }
    
};

} // namespace message

} // namespace ublox


