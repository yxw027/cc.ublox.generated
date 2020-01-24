// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains definition of <b>"CFG-NMEA"</b> message and its fields.

#pragma once

#include <tuple>
#include "comms/MessageBase.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/CfgNmeaFilter.h"
#include "ublox/field/CfgNmeaFlags.h"
#include "ublox/field/CfgNmeaNumSV.h"
#include "ublox/field/CfgNmeaVersion.h"
#include "ublox/field/FieldBase.h"
#include "ublox/message/CfgNmeaCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref CfgNmea.
/// @tparam TOpt Extra options
/// @see @ref CfgNmea
/// @headerfile "ublox/message/CfgNmea.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct CfgNmeaFields
{
    /// @brief Definition of <b>"filter"</b> field.
    struct Filter : public
        ublox::field::CfgNmeaFilter<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgNmeaFieldsCommon::FilterCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"nmeaVersion"</b> field.
    struct NmeaVersion : public
        ublox::field::CfgNmeaVersion<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgNmeaFieldsCommon::NmeaVersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"numSV"</b> field.
    struct NumSV : public
        ublox::field::CfgNmeaNumSV<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgNmeaFieldsCommon::NumSVCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"flags"</b> field.
    struct Flags : public
        ublox::field::CfgNmeaFlags<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgNmeaFieldsCommon::FlagsCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Filter,
        NmeaVersion,
        NumSV,
        Flags
    >;
};

/// @brief Definition of <b>"CFG-NMEA"</b> message class.
/// @details
///     See @ref CfgNmeaFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/CfgNmea.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class CfgNmea : public
    comms::MessageBase<
        TMsgBase,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_CfgNmea>,
        comms::option::def::FieldsImpl<typename CfgNmeaFields<TOpt>::All>,
        comms::option::def::MsgType<CfgNmea<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_CfgNmea>,
            comms::option::def::FieldsImpl<typename CfgNmeaFields<TOpt>::All>,
            comms::option::def::MsgType<CfgNmea<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_filter type and @b field_filter() fuction
    ///         for @ref CfgNmeaFields::Filter field.
    ///     @li @b Field_nmeaVersion type and @b field_nmeaVersion() fuction
    ///         for @ref CfgNmeaFields::NmeaVersion field.
    ///     @li @b Field_numSV type and @b field_numSV() fuction
    ///         for @ref CfgNmeaFields::NumSV field.
    ///     @li @b Field_flags type and @b field_flags() fuction
    ///         for @ref CfgNmeaFields::Flags field.
    COMMS_MSG_FIELDS_NAMES(
        filter,
        nmeaVersion,
        numSV,
        flags
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 4U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 4U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::CfgNmeaCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


