// Generated by commsdsl2comms v3.3.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::CfgDatStandard message and its fields.

#pragma once

#include "ublox/field/CfgDatDatumNumCommon.h"

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::CfgDatStandard message.
/// @see ublox::message::CfgDatStandardFields
struct CfgDatStandardFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::CfgDatStandardFields::DatumNum field.
    struct DatumNumCommon : public ublox::field::CfgDatDatumNumCommon
    {
        /// @brief Name of the @ref ublox::message::CfgDatStandardFields::DatumNum field.
        static const char* name()
        {
            return "datumNum";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::CfgDatStandard message.
/// @see ublox::message::CfgDatStandard
struct CfgDatStandardCommon
{
    /// @brief Name of the @ref ublox::message::CfgDatStandard message.
    static const char* name()
    {
        return "CFG-DAT (Standard)";
    }
    
};

} // namespace message

} // namespace ublox


