// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains definition of <b>"AID-ALP (Status)"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include "comms/MessageBase.h"
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/FieldBase.h"
#include "ublox/message/AidAlpStatusCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref AidAlpStatus.
/// @tparam TOpt Extra options
/// @see @ref AidAlpStatus
/// @headerfile "ublox/message/AidAlpStatus.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct AidAlpStatusFields
{
    /// @brief Definition of <b>"status"</b> field.
    /// @see @ref ublox::message::AidAlpStatusFieldsCommon::StatusVal
    class Status : public
        comms::field::EnumValue<
            ublox::field::FieldBase<>,
            ublox::message::AidAlpStatusFieldsCommon::StatusVal,
            comms::option::def::FailOnInvalid<>,
            comms::option::def::ValidNumValueRange<0, 1>
        >
    {
        using Base = 
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::AidAlpStatusFieldsCommon::StatusVal,
                comms::option::def::FailOnInvalid<>,
                comms::option::def::ValidNumValueRange<0, 1>
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;
    
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::AidAlpStatusFieldsCommon::StatusCommon::name();
        }
        
        /// @brief Retrieve name of the enum value
        static const char* valueName(ValueType val)
        {
            return ublox::message::AidAlpStatusFieldsCommon::StatusCommon::valueName(val);
        }
        
        /// @brief Retrieve name of the @b current value
        const char* valueName() const
        {
            return valueName(Base::value());
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Status
    >;
};

/// @brief Definition of <b>"AID-ALP (Status)"</b> message class.
/// @details
///     See @ref AidAlpStatusFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/AidAlpStatus.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class AidAlpStatus : public
    comms::MessageBase<
        TMsgBase,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_AidAlp>,
        comms::option::def::FieldsImpl<typename AidAlpStatusFields<TOpt>::All>,
        comms::option::def::MsgType<AidAlpStatus<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_AidAlp>,
            comms::option::def::FieldsImpl<typename AidAlpStatusFields<TOpt>::All>,
            comms::option::def::MsgType<AidAlpStatus<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_status type and @b field_status() fuction
    ///         for @ref AidAlpStatusFields::Status field.
    COMMS_MSG_FIELDS_NAMES(
        status
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 1U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 1U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::AidAlpStatusCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


