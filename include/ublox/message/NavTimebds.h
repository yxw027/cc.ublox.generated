// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains definition of <b>"NAV-TIMEBDS"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/Itow.h"
#include "ublox/message/NavTimebdsCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref NavTimebds.
/// @tparam TOpt Extra options
/// @see @ref NavTimebds
/// @headerfile "ublox/message/NavTimebds.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct NavTimebdsFields
{
    /// @brief Definition of <b>"iTOW"</b> field.
    using Itow =
        ublox::field::Itow<
            TOpt
        >;
    
    /// @brief Definition of <b>"SOW"</b> field.
    struct SOW : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsSeconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavTimebdsFieldsCommon::SOWCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"fSOW"</b> field.
    struct FSOW : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int32_t,
            comms::option::def::UnitsNanoseconds,
            comms::option::def::ValidNumValueRange<-500000000L, 500000000L>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavTimebdsFieldsCommon::FSOWCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"week"</b> field.
    struct Week : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::UnitsWeeks
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavTimebdsFieldsCommon::WeekCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"leapS"</b> field.
    struct LeapS : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int8_t,
            comms::option::def::UnitsSeconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavTimebdsFieldsCommon::LeapSCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"valid"</b> field.
    class Valid : public
        comms::field::BitmaskValue<
            ublox::field::FieldBase<>,
            comms::option::def::FixedLength<1U>,
            comms::option::def::BitmaskReservedBits<0xF8U, 0x0U>
        >
    {
        using Base = 
            comms::field::BitmaskValue<
                ublox::field::FieldBase<>,
                comms::option::def::FixedLength<1U>,
                comms::option::def::BitmaskReservedBits<0xF8U, 0x0U>
            >;
    public:
        /// @brief Provides names and generates access functions for internal bits.
        /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
        ///     related to @b comms::field::BitmaskValue class from COMMS library
        ///     for details.
        ///
        ///      The generated enum values and functions are:
        ///      @li @b BitIdx_sowValid, @b getBitValue_sowValid() and @b setBitValue_sowValid().
        ///      @li @b BitIdx_weekValid, @b getBitValue_weekValid() and @b setBitValue_weekValid().
        ///      @li @b BitIdx_leapSValid, @b getBitValue_leapSValid() and @b setBitValue_leapSValid().
        COMMS_BITMASK_BITS_SEQ(
            sowValid,
            weekValid,
            leapSValid
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavTimebdsFieldsCommon::ValidCommon::name();
        }
        
        /// @brief Retrieve name of the bit.
        static const char* bitName(BitIdx idx)
        {
            return
                ublox::message::NavTimebdsFieldsCommon::ValidCommon::bitName(
                    static_cast<std::size_t>(idx));
        }
        
    };
    
    /// @brief Definition of <b>"tAcc"</b> field.
    struct TAcc : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsNanoseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavTimebdsFieldsCommon::TAccCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Itow,
        SOW,
        FSOW,
        Week,
        LeapS,
        Valid,
        TAcc
    >;
};

/// @brief Definition of <b>"NAV-TIMEBDS"</b> message class.
/// @details
///     See @ref NavTimebdsFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/NavTimebds.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class NavTimebds : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::NavTimebds,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_NavTimebds>,
        comms::option::def::FieldsImpl<typename NavTimebdsFields<TOpt>::All>,
        comms::option::def::MsgType<NavTimebds<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::NavTimebds,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_NavTimebds>,
            comms::option::def::FieldsImpl<typename NavTimebdsFields<TOpt>::All>,
            comms::option::def::MsgType<NavTimebds<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_itow type and @b field_itow() fuction
    ///         for @ref NavTimebdsFields::Itow field.
    ///     @li @b Field_sOW type and @b field_sOW() fuction
    ///         for @ref NavTimebdsFields::SOW field.
    ///     @li @b Field_fSOW type and @b field_fSOW() fuction
    ///         for @ref NavTimebdsFields::FSOW field.
    ///     @li @b Field_week type and @b field_week() fuction
    ///         for @ref NavTimebdsFields::Week field.
    ///     @li @b Field_leapS type and @b field_leapS() fuction
    ///         for @ref NavTimebdsFields::LeapS field.
    ///     @li @b Field_valid type and @b field_valid() fuction
    ///         for @ref NavTimebdsFields::Valid field.
    ///     @li @b Field_tAcc type and @b field_tAcc() fuction
    ///         for @ref NavTimebdsFields::TAcc field.
    COMMS_MSG_FIELDS_NAMES(
        itow,
        sOW,
        fSOW,
        week,
        leapS,
        valid,
        tAcc
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 20U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 20U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::NavTimebdsCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


