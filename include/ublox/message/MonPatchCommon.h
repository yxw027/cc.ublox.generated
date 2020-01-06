// Generated by commsdsl2comms v3.3.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::MonPatch message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::MonPatch message.
/// @see ublox::message::MonPatchFields
struct MonPatchFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::MonPatchFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MonPatchFields::Version field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref ublox::message::MonPatchFields::Version field.
        static const char* name()
        {
            return "version";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MonPatchFields::NEntries field.
    struct NEntriesCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MonPatchFields::NEntries field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref ublox::message::MonPatchFields::NEntries field.
        static const char* name()
        {
            return "nEntries";
        }
        
    };
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref ublox::message::MonPatchFields::List list.
    struct ListMembersCommon
    {
        /// @brief Scope for all the common definitions of the member fields of
        ///     @ref ublox::message::MonPatchFields::ListMembers::Element field.
        struct ElementMembersCommon
        {
            /// @brief Scope for all the common definitions of the member fields of
            ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfo field.
            struct PatchInfoMembersCommon
            {
                /// @brief Common functions for
                ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Bits field.
                struct BitsCommon
                {
                    /// @brief Name of the @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Bits field.
                    static const char* name()
                    {
                        return "";
                    }
                    
                    /// @brief Retrieve name of the bit of
                    ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Bits field.
                    static const char* bitName(std::size_t idx)
                    {
                        static const char* Map[] = {
                            "activated"
                        };
                    
                        static const std::size_t MapSize = std::extent<decltype(Map)>::value;
                        if (MapSize <= idx) {
                            return nullptr;
                        }
                    
                        return Map[idx];
                    }
                    
                };
                
                /// @brief Common types and functions for
                ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Location field.
                struct LocationCommon
                {
                    /// @brief Values enumerator for
                    ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Location field.
                    enum class ValueType : std::uint8_t
                    {
                        eFuse = 0, ///< value @b eFuse
                        ROM = 1, ///< value @b ROM
                        BBR = 2, ///< value @b BBR
                        FileSystem = 3, ///< value @b FileSystem
                        
                        // --- Extra values generated for convenience ---
                        firstValue = 0, ///< First defined value.
                        lastValue = 3, ///< Last defined value.
                        valuesLimit = 4, ///< Upper limit for defined values.
                        
                    };
                    
                    /// @brief Name of the @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Location field.
                    static const char* name()
                    {
                        return "location";
                    }
                    
                    /// @brief Retrieve name of the enum value
                    static const char* valueName(ValueType val)
                    {
                        static const char* Map[] = {
                            "eFuse",
                            "ROM",
                            "BBR",
                            "FileSystem"
                        };
                        static const std::size_t MapSize = std::extent<decltype(Map)>::value;
                        
                        if (MapSize <= static_cast<std::size_t>(val)) {
                            return nullptr;
                        }
                        
                        return Map[static_cast<std::size_t>(val)];
                    }
                    
                };
                
                /// @brief Values enumerator for
                ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Location field.
                using LocationVal = LocationCommon::ValueType;
                
                /// @brief Common types and functions for
                ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Res4 field.
                struct Res4Common
                {
                    /// @brief Re-definition of the value type used by
                    ///     ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Res4 field.
                    using ValueType = std::uint32_t;
                
                    /// @brief Name of the @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfoMembers::Res4 field.
                    static const char* name()
                    {
                        return "res4";
                    }
                    
                };
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfo field.
            struct PatchInfoCommon
            {
                /// @brief Name of the @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchInfo field.
                static const char* name()
                {
                    return "patchInfo";
                }
                
            };
            
            
            /// @brief Common types and functions for
            ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::ComparatorNumber field.
            struct ComparatorNumberCommon
            {
                /// @brief Re-definition of the value type used by
                ///     ublox::message::MonPatchFields::ListMembers::ElementMembers::ComparatorNumber field.
                using ValueType = std::uint32_t;
            
                /// @brief Name of the @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::ComparatorNumber field.
                static const char* name()
                {
                    return "comparatorNumber";
                }
                
            };
            
            /// @brief Common types and functions for
            ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchAddress field.
            struct PatchAddressCommon
            {
                /// @brief Re-definition of the value type used by
                ///     ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchAddress field.
                using ValueType = std::uint32_t;
            
                /// @brief Name of the @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchAddress field.
                static const char* name()
                {
                    return "patchAddress";
                }
                
            };
            
            /// @brief Common types and functions for
            ///     @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchData field.
            struct PatchDataCommon
            {
                /// @brief Re-definition of the value type used by
                ///     ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchData field.
                using ValueType = std::uint32_t;
            
                /// @brief Name of the @ref ublox::message::MonPatchFields::ListMembers::ElementMembers::PatchData field.
                static const char* name()
                {
                    return "patchData";
                }
                
            };
            
        };
        
        /// @brief Scope for all the common definitions of the
        ///     @ref ublox::message::MonPatchFields::ListMembers::Element field.
        struct ElementCommon
        {
            /// @brief Name of the @ref ublox::message::MonPatchFields::ListMembers::Element field.
            static const char* name()
            {
                return "";
            }
            
        };
        
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref ublox::message::MonPatchFields::List field.
    struct ListCommon
    {
        /// @brief Name of the @ref ublox::message::MonPatchFields::List field.
        static const char* name()
        {
            return "list";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::MonPatch message.
/// @see ublox::message::MonPatch
struct MonPatchCommon
{
    /// @brief Name of the @ref ublox::message::MonPatch message.
    static const char* name()
    {
        return "MON-PATCH";
    }
    
};

} // namespace message

} // namespace ublox


