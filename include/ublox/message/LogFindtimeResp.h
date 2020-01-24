// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains definition of <b>"LOG-FINDTIME (Response)"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/Res2.h"
#include "ublox/message/LogFindtimeRespCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref LogFindtimeResp.
/// @tparam TOpt Extra options
/// @see @ref LogFindtimeResp
/// @headerfile "ublox/message/LogFindtimeResp.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct LogFindtimeRespFields
{
    /// @brief Definition of <b>"version"</b> field.
    struct Version : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::DefaultNumValue<1>,
            comms::option::def::ValidNumValue<1>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeRespFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"type"</b> field.
    struct Type : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::FailOnInvalid<>,
            comms::option::def::DefaultNumValue<1>,
            comms::option::def::ValidNumValue<1>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeRespFieldsCommon::TypeCommon::name();
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
            return ublox::message::LogFindtimeRespFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"entryNumber"</b> field.
    struct EntryNumber : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogFindtimeRespFieldsCommon::EntryNumberCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version,
        Type,
        Reserved1,
        EntryNumber
    >;
};

/// @brief Definition of <b>"LOG-FINDTIME (Response)"</b> message class.
/// @details
///     See @ref LogFindtimeRespFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/LogFindtimeResp.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class LogFindtimeResp : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::LogFindtimeResp,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_LogFindtime>,
        comms::option::def::FieldsImpl<typename LogFindtimeRespFields<TOpt>::All>,
        comms::option::def::MsgType<LogFindtimeResp<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::LogFindtimeResp,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_LogFindtime>,
            comms::option::def::FieldsImpl<typename LogFindtimeRespFields<TOpt>::All>,
            comms::option::def::MsgType<LogFindtimeResp<TMsgBase, TOpt> >,
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
    ///         for @ref LogFindtimeRespFields::Version field.
    ///     @li @b Field_type type and @b field_type() fuction
    ///         for @ref LogFindtimeRespFields::Type field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() fuction
    ///         for @ref LogFindtimeRespFields::Reserved1 field.
    ///     @li @b Field_entryNumber type and @b field_entryNumber() fuction
    ///         for @ref LogFindtimeRespFields::EntryNumber field.
    COMMS_MSG_FIELDS_NAMES(
        version,
        type,
        reserved1,
        entryNumber
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 8U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 8U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::LogFindtimeRespCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


