// Generated by commsdsl2comms v3.3.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::TimFchg message and its fields.

#pragma once

#include <cstdint>
#include "ublox/field/ItowCommon.h"
#include "ublox/field/Res3Common.h"

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::TimFchg message.
/// @see ublox::message::TimFchgFields
struct TimFchgFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::TimFchgFields::Version field.
        using ValueType = std::int8_t;
    
        /// @brief Name of the @ref ublox::message::TimFchgFields::Version field.
        static const char* name()
        {
            return "version";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::Reserved1 field.
    struct Reserved1Common : public ublox::field::Res3Common
    {
        /// @brief Name of the @ref ublox::message::TimFchgFields::Reserved1 field.
        static const char* name()
        {
            return "reserved1";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::Itow field.
    using ItowCommon = ublox::field::ItowCommon;
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::IntDeltaFreq field.
    struct IntDeltaFreqCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::TimFchgFields::IntDeltaFreq field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::TimFchgFields::IntDeltaFreq field.
        static const char* name()
        {
            return "intDeltaFreq";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::IntDeltaFreqUnc field.
    struct IntDeltaFreqUncCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::TimFchgFields::IntDeltaFreqUnc field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::TimFchgFields::IntDeltaFreqUnc field.
        static const char* name()
        {
            return "intDeltaFreqUnc";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::IntRaw field.
    struct IntRawCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::TimFchgFields::IntRaw field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::TimFchgFields::IntRaw field.
        static const char* name()
        {
            return "intRaw";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::ExtDeltaFreq field.
    struct ExtDeltaFreqCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::TimFchgFields::ExtDeltaFreq field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::TimFchgFields::ExtDeltaFreq field.
        static const char* name()
        {
            return "extDeltaFreq";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::ExtDeltaFreqUnc field.
    struct ExtDeltaFreqUncCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::TimFchgFields::ExtDeltaFreqUnc field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::TimFchgFields::ExtDeltaFreqUnc field.
        static const char* name()
        {
            return "extDeltaFreqUnc";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::TimFchgFields::ExtRaw field.
    struct ExtRawCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::TimFchgFields::ExtRaw field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::TimFchgFields::ExtRaw field.
        static const char* name()
        {
            return "extRaw";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::TimFchg message.
/// @see ublox::message::TimFchg
struct TimFchgCommon
{
    /// @brief Name of the @ref ublox::message::TimFchg message.
    static const char* name()
    {
        return "TIM-FCHG";
    }
    
};

} // namespace message

} // namespace ublox


