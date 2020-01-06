// Generated by commsdsl2comms v3.3.0

/// @file
/// @brief Contains definition of <b>"LOG-FINDTIME"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/Day.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/Hour.h"
#include "ublox/field/Min.h"
#include "ublox/field/Month.h"
#include "ublox/field/Res1.h"
#include "ublox/field/Res2.h"
#include "ublox/field/Sec.h"
#include "ublox/field/Year.h"
#include "ublox/message/LogFindtimeCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref LogFindtime.
/// @tparam TOpt Extra options
/// @see @ref LogFindtime
/// @headerfile "ublox/message/LogFindtime.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct LogFindtimeFields
{
    /// @brief Definition of <b>"version"</b> field.
    struct Version : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::ValidNumValue<0>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"type"</b> field.
    struct Type : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::FailOnInvalid<>,
            comms::option::def::ValidNumValue<0>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeFieldsCommon::TypeCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"reserved1"</b> field.
    struct Reserved1 : public
        ublox::field::Res2<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"year"</b> field.
    using Year =
        ublox::field::Year<
            TOpt
        >;
    
    /// @brief Definition of <b>"month"</b> field.
    using Month =
        ublox::field::Month<
            TOpt
        >;
    
    /// @brief Definition of <b>"day"</b> field.
    using Day =
        ublox::field::Day<
            TOpt
        >;
    
    /// @brief Definition of <b>"hour"</b> field.
    using Hour =
        ublox::field::Hour<
            TOpt
        >;
    
    /// @brief Definition of <b>"minute"</b> field.
    struct Minute : public
        ublox::field::Min<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeFieldsCommon::MinuteCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"second"</b> field.
    struct Second : public
        ublox::field::Sec<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeFieldsCommon::SecondCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"reserved2"</b> field.
    struct Reserved2 : public
        ublox::field::Res1<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeFieldsCommon::Reserved2Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version,
        Type,
        Reserved1,
        Year,
        Month,
        Day,
        Hour,
        Minute,
        Second,
        Reserved2
    >;
};

/// @brief Definition of <b>"LOG-FINDTIME"</b> message class.
/// @details
///     See @ref LogFindtimeFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/LogFindtime.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class LogFindtime : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::LogFindtime,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_LogFindtime>,
        comms::option::def::FieldsImpl<typename LogFindtimeFields<TOpt>::All>,
        comms::option::def::MsgType<LogFindtime<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::LogFindtime,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_LogFindtime>,
            comms::option::def::FieldsImpl<typename LogFindtimeFields<TOpt>::All>,
            comms::option::def::MsgType<LogFindtime<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_version type and @b field_version() fuction
    ///         for @ref LogFindtimeFields::Version field.
    ///     @li @b Field_type type and @b field_type() fuction
    ///         for @ref LogFindtimeFields::Type field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() fuction
    ///         for @ref LogFindtimeFields::Reserved1 field.
    ///     @li @b Field_year type and @b field_year() fuction
    ///         for @ref LogFindtimeFields::Year field.
    ///     @li @b Field_month type and @b field_month() fuction
    ///         for @ref LogFindtimeFields::Month field.
    ///     @li @b Field_day type and @b field_day() fuction
    ///         for @ref LogFindtimeFields::Day field.
    ///     @li @b Field_hour type and @b field_hour() fuction
    ///         for @ref LogFindtimeFields::Hour field.
    ///     @li @b Field_minute type and @b field_minute() fuction
    ///         for @ref LogFindtimeFields::Minute field.
    ///     @li @b Field_second type and @b field_second() fuction
    ///         for @ref LogFindtimeFields::Second field.
    ///     @li @b Field_reserved2 type and @b field_reserved2() fuction
    ///         for @ref LogFindtimeFields::Reserved2 field.
    COMMS_MSG_FIELDS_NAMES(
        version,
        type,
        reserved1,
        year,
        month,
        day,
        hour,
        minute,
        second,
        reserved2
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 12U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 12U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::LogFindtimeCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


