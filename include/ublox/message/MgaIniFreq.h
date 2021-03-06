// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains definition of <b>"MGA-BDS-FREQ"</b> message and its fields.

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
#include "ublox/field/Res1.h"
#include "ublox/message/MgaIniFreqCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref MgaIniFreq.
/// @tparam TOpt Extra options
/// @see @ref MgaIniFreq
/// @headerfile "ublox/message/MgaIniFreq.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct MgaIniFreqFields
{
    /// @brief Definition of <b>"type"</b> field.
    struct Type : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::FailOnInvalid<>,
            comms::option::def::DefaultNumValue<33>,
            comms::option::def::ValidNumValue<33>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaIniFreqFieldsCommon::TypeCommon::name();
        }
        
    };
    
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
            return ublox::message::MgaIniFreqFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"reserved1"</b> field.
    struct Reserved1 : public
        ublox::field::Res1<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaIniFreqFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of @ref Flags bitfield.
    struct FlagsMembers
    {
        /// @brief Definition of <b>"source"</b> field.
        /// @see @ref ublox::message::MgaIniFreqFieldsCommon::FlagsMembersCommon::SourceVal
        class Source : public
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::MgaIniFreqFieldsCommon::FlagsMembersCommon::SourceVal,
                comms::option::def::FixedBitLength<4U>,
                comms::option::def::ValidNumValueRange<0, 1>
            >
        {
            using Base = 
                comms::field::EnumValue<
                    ublox::field::FieldBase<>,
                    ublox::message::MgaIniFreqFieldsCommon::FlagsMembersCommon::SourceVal,
                    comms::option::def::FixedBitLength<4U>,
                    comms::option::def::ValidNumValueRange<0, 1>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;
        
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::MgaIniFreqFieldsCommon::FlagsMembersCommon::SourceCommon::name();
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                return ublox::message::MgaIniFreqFieldsCommon::FlagsMembersCommon::SourceCommon::valueName(val);
            }
            
            /// @brief Retrieve name of the @b current value
            const char* valueName() const
            {
                return valueName(Base::value());
            }
            
        };
        
        /// @brief Definition of <b>""</b> field.
        class Bits : public
            comms::field::BitmaskValue<
                ublox::field::FieldBase<>,
                comms::option::def::FixedBitLength<4U>,
                comms::option::def::BitmaskReservedBits<0xEU, 0x0U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    ublox::field::FieldBase<>,
                    comms::option::def::FixedBitLength<4U>,
                    comms::option::def::BitmaskReservedBits<0xEU, 0x0U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_fall, @b getBitValue_fall() and @b setBitValue_fall().
            COMMS_BITMASK_BITS_SEQ(
                fall
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::MgaIniFreqFieldsCommon::FlagsMembersCommon::BitsCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::MgaIniFreqFieldsCommon::FlagsMembersCommon::BitsCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               Source,
               Bits
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
        ///     @li @b Field_source @b field_source() -
        ///         for FlagsMembers::Source member field.
        ///     @li @b Field_bits @b field_bits() -
        ///         for FlagsMembers::Bits member field.
        COMMS_FIELD_MEMBERS_NAMES(
            source,
            bits
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaIniFreqFieldsCommon::FlagsCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"freq"</b> field.
    struct Freq : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int32_t,
            comms::option::def::ScalingRatio<1, 100>,
            comms::option::def::UnitsHertz
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaIniFreqFieldsCommon::FreqCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"freqAcc"</b> field.
    struct FreqAcc : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaIniFreqFieldsCommon::FreqAccCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Type,
        Version,
        Reserved1,
        Flags,
        Freq,
        FreqAcc
    >;
};

/// @brief Definition of <b>"MGA-BDS-FREQ"</b> message class.
/// @details
///     See @ref MgaIniFreqFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/MgaIniFreq.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class MgaIniFreq : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::MgaIniFreq,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_MgaIni>,
        comms::option::def::FieldsImpl<typename MgaIniFreqFields<TOpt>::All>,
        comms::option::def::MsgType<MgaIniFreq<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::MgaIniFreq,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_MgaIni>,
            comms::option::def::FieldsImpl<typename MgaIniFreqFields<TOpt>::All>,
            comms::option::def::MsgType<MgaIniFreq<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_type type and @b field_type() fuction
    ///         for @ref MgaIniFreqFields::Type field.
    ///     @li @b Field_version type and @b field_version() fuction
    ///         for @ref MgaIniFreqFields::Version field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() fuction
    ///         for @ref MgaIniFreqFields::Reserved1 field.
    ///     @li @b Field_flags type and @b field_flags() fuction
    ///         for @ref MgaIniFreqFields::Flags field.
    ///     @li @b Field_freq type and @b field_freq() fuction
    ///         for @ref MgaIniFreqFields::Freq field.
    ///     @li @b Field_freqAcc type and @b field_freqAcc() fuction
    ///         for @ref MgaIniFreqFields::FreqAcc field.
    COMMS_MSG_FIELDS_NAMES(
        type,
        version,
        reserved1,
        flags,
        freq,
        freqAcc
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 12U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 12U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::MgaIniFreqCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


