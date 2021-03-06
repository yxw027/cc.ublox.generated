// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains definition of <b>"TIM-TM2"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include "comms/MessageBase.h"
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/FieldBase.h"
#include "ublox/message/TimTm2Common.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref TimTm2.
/// @tparam TOpt Extra options
/// @see @ref TimTm2
/// @headerfile "ublox/message/TimTm2.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct TimTm2Fields
{
    /// @brief Definition of <b>"ch"</b> field.
    struct Ch : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::ChCommon::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of @ref Flags bitfield.
    struct FlagsMembers
    {
        /// @brief Definition of <b>""</b> field.
        class BitsLow : public
            comms::field::BitmaskValue<
                ublox::field::FieldBase<>,
                comms::option::def::FixedBitLength<3U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    ublox::field::FieldBase<>,
                    comms::option::def::FixedBitLength<3U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_mode, @b getBitValue_mode() and @b setBitValue_mode().
            ///      @li @b BitIdx_run, @b getBitValue_run() and @b setBitValue_run().
            ///      @li @b BitIdx_newFallingEdge, @b getBitValue_newFallingEdge() and @b setBitValue_newFallingEdge().
            COMMS_BITMASK_BITS_SEQ(
                mode,
                run,
                newFallingEdge
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::BitsLowCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::BitsLowCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief Definition of <b>"timeBase"</b> field.
        /// @see @ref ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::TimeBaseVal
        class TimeBase : public
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::TimeBaseVal,
                comms::option::def::FixedBitLength<2U>,
                comms::option::def::ValidNumValueRange<0, 2>
            >
        {
            using Base = 
                comms::field::EnumValue<
                    ublox::field::FieldBase<>,
                    ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::TimeBaseVal,
                    comms::option::def::FixedBitLength<2U>,
                    comms::option::def::ValidNumValueRange<0, 2>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;
        
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::TimeBaseCommon::name();
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                return ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::TimeBaseCommon::valueName(val);
            }
            
            /// @brief Retrieve name of the @b current value
            const char* valueName() const
            {
                return valueName(Base::value());
            }
            
        };
        
        /// @brief Definition of <b>""</b> field.
        class BitsHigh : public
            comms::field::BitmaskValue<
                ublox::field::FieldBase<>,
                comms::option::def::FixedBitLength<3U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    ublox::field::FieldBase<>,
                    comms::option::def::FixedBitLength<3U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_utc, @b getBitValue_utc() and @b setBitValue_utc().
            ///      @li @b BitIdx_time, @b getBitValue_time() and @b setBitValue_time().
            ///      @li @b BitIdx_newRisingEdge, @b getBitValue_newRisingEdge() and @b setBitValue_newRisingEdge().
            COMMS_BITMASK_BITS_SEQ(
                utc,
                time,
                newRisingEdge
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::BitsHighCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::TimTm2FieldsCommon::FlagsMembersCommon::BitsHighCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               BitsLow,
               TimeBase,
               BitsHigh
            >;
    };
    
    /// @brief Definition of <b>"flags"</b> field.
    class Flags : public
        comms::field::Bitfield<
            ublox::field::FieldBase<>,
            typename FlagsMembers::All
        >
    {
        using Base = 
            comms::field::Bitfield<
                ublox::field::FieldBase<>,
                typename FlagsMembers::All
            >;
    public:
        /// @brief Allow access to internal fields.
        /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
        ///     related to @b comms::field::Bitfield class from COMMS library
        ///     for details.
        ///
        ///     The generated access functions are:
        ///     @li @b Field_bitsLow @b field_bitsLow() -
        ///         for FlagsMembers::BitsLow member field.
        ///     @li @b Field_timeBase @b field_timeBase() -
        ///         for FlagsMembers::TimeBase member field.
        ///     @li @b Field_bitsHigh @b field_bitsHigh() -
        ///         for FlagsMembers::BitsHigh member field.
        COMMS_FIELD_MEMBERS_NAMES(
            bitsLow,
            timeBase,
            bitsHigh
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::FlagsCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"count"</b> field.
    struct Count : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::CountCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"wnR"</b> field.
    struct WnR : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::WnRCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"wnF"</b> field.
    struct WnF : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::WnFCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"towMsR"</b> field.
    struct TowMsR : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsMilliseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::TowMsRCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"towSubMsR"</b> field.
    struct TowSubMsR : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsNanoseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::TowSubMsRCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"towMsF"</b> field.
    struct TowMsF : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsMilliseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::TowMsFCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"towSubMsF"</b> field.
    struct TowSubMsF : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsNanoseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::TowSubMsFCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"accEst"</b> field.
    struct AccEst : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsNanoseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::TimTm2FieldsCommon::AccEstCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Ch,
        Flags,
        Count,
        WnR,
        WnF,
        TowMsR,
        TowSubMsR,
        TowMsF,
        TowSubMsF,
        AccEst
    >;
};

/// @brief Definition of <b>"TIM-TM2"</b> message class.
/// @details
///     See @ref TimTm2Fields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/TimTm2.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class TimTm2 : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::TimTm2,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_TimTm2>,
        comms::option::def::FieldsImpl<typename TimTm2Fields<TOpt>::All>,
        comms::option::def::MsgType<TimTm2<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::TimTm2,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_TimTm2>,
            comms::option::def::FieldsImpl<typename TimTm2Fields<TOpt>::All>,
            comms::option::def::MsgType<TimTm2<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_ch type and @b field_ch() fuction
    ///         for @ref TimTm2Fields::Ch field.
    ///     @li @b Field_flags type and @b field_flags() fuction
    ///         for @ref TimTm2Fields::Flags field.
    ///     @li @b Field_count type and @b field_count() fuction
    ///         for @ref TimTm2Fields::Count field.
    ///     @li @b Field_wnR type and @b field_wnR() fuction
    ///         for @ref TimTm2Fields::WnR field.
    ///     @li @b Field_wnF type and @b field_wnF() fuction
    ///         for @ref TimTm2Fields::WnF field.
    ///     @li @b Field_towMsR type and @b field_towMsR() fuction
    ///         for @ref TimTm2Fields::TowMsR field.
    ///     @li @b Field_towSubMsR type and @b field_towSubMsR() fuction
    ///         for @ref TimTm2Fields::TowSubMsR field.
    ///     @li @b Field_towMsF type and @b field_towMsF() fuction
    ///         for @ref TimTm2Fields::TowMsF field.
    ///     @li @b Field_towSubMsF type and @b field_towSubMsF() fuction
    ///         for @ref TimTm2Fields::TowSubMsF field.
    ///     @li @b Field_accEst type and @b field_accEst() fuction
    ///         for @ref TimTm2Fields::AccEst field.
    COMMS_MSG_FIELDS_NAMES(
        ch,
        flags,
        count,
        wnR,
        wnF,
        towMsR,
        towSubMsR,
        towMsF,
        towSubMsF,
        accEst
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 28U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 28U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::TimTm2Common::name();
    }
    
    
};

} // namespace message

} // namespace ublox


