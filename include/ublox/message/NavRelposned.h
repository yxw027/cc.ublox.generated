// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains definition of <b>"NAV-RELPOSNED"</b> message and its fields.

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
#include "ublox/field/Itow.h"
#include "ublox/field/Res1.h"
#include "ublox/message/NavRelposnedCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref NavRelposned.
/// @tparam TOpt Extra options
/// @see @ref NavRelposned
/// @headerfile "ublox/message/NavRelposned.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct NavRelposnedFields
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
            return ublox::message::NavRelposnedFieldsCommon::VersionCommon::name();
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
            return ublox::message::NavRelposnedFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"refStationId"</b> field.
    struct RefStationId : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t,
            comms::option::def::ValidNumValueRange<0, 4095>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::RefStationIdCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"iTOW"</b> field.
    using Itow =
        ublox::field::Itow<
            TOpt
        >;
    
    /// @brief Definition of <b>"relPosN"</b> field.
    struct RelPosN : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int32_t,
            comms::option::def::UnitsCentimeters
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::RelPosNCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"relPosE"</b> field.
    struct RelPosE : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int32_t,
            comms::option::def::UnitsCentimeters
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::RelPosECommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"relPosD"</b> field.
    struct RelPosD : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int32_t,
            comms::option::def::UnitsCentimeters
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::RelPosDCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"relPosHPN"</b> field.
    struct RelPosHPN : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int8_t,
            comms::option::def::ScalingRatio<1, 10>,
            comms::option::def::UnitsMillimeters,
            comms::option::def::ValidNumValueRange<-99, 99>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::RelPosHPNCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"relPosHPE"</b> field.
    struct RelPosHPE : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int8_t,
            comms::option::def::ScalingRatio<1, 10>,
            comms::option::def::UnitsMillimeters,
            comms::option::def::ValidNumValueRange<-99, 99>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::RelPosHPECommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"relPosHPD"</b> field.
    struct RelPosHPD : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int8_t,
            comms::option::def::ScalingRatio<1, 10>,
            comms::option::def::UnitsMillimeters,
            comms::option::def::ValidNumValueRange<-99, 99>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::RelPosHPDCommon::name();
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
            return ublox::message::NavRelposnedFieldsCommon::Reserved2Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"accN"</b> field.
    struct AccN : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::ScalingRatio<1, 10>,
            comms::option::def::UnitsMillimeters
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::AccNCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"accE"</b> field.
    struct AccE : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::ScalingRatio<1, 10>,
            comms::option::def::UnitsMillimeters
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::AccECommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"accD"</b> field.
    struct AccD : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::ScalingRatio<1, 10>,
            comms::option::def::UnitsMillimeters
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::AccDCommon::name();
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
            ///      @li @b BitIdx_gnssFixOK, @b getBitValue_gnssFixOK() and @b setBitValue_gnssFixOK().
            ///      @li @b BitIdx_diffSoln, @b getBitValue_diffSoln() and @b setBitValue_diffSoln().
            ///      @li @b BitIdx_relPosValid, @b getBitValue_relPosValid() and @b setBitValue_relPosValid().
            COMMS_BITMASK_BITS_SEQ(
                gnssFixOK,
                diffSoln,
                relPosValid
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::BitsLowCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::BitsLowCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief Definition of <b>"carrSoln"</b> field.
        /// @see @ref ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::CarrSolnVal
        class CarrSoln : public
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::CarrSolnVal,
                comms::option::def::FixedBitLength<2U>,
                comms::option::def::ValidNumValueRange<0, 2>
            >
        {
            using Base = 
                comms::field::EnumValue<
                    ublox::field::FieldBase<>,
                    ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::CarrSolnVal,
                    comms::option::def::FixedBitLength<2U>,
                    comms::option::def::ValidNumValueRange<0, 2>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;
        
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::CarrSolnCommon::name();
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                return ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::CarrSolnCommon::valueName(val);
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
                comms::option::def::FixedBitLength<27U>,
                comms::option::def::BitmaskReservedBits<0x7FFFFF8UL, 0x0U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    ublox::field::FieldBase<>,
                    comms::option::def::FixedBitLength<27U>,
                    comms::option::def::BitmaskReservedBits<0x7FFFFF8UL, 0x0U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_isMoving, @b getBitValue_isMoving() and @b setBitValue_isMoving().
            ///      @li @b BitIdx_refPosMiss, @b getBitValue_refPosMiss() and @b setBitValue_refPosMiss().
            ///      @li @b BitIdx_refObsMiss, @b getBitValue_refObsMiss() and @b setBitValue_refObsMiss().
            COMMS_BITMASK_BITS_SEQ(
                isMoving,
                refPosMiss,
                refObsMiss
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::BitsHighCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::NavRelposnedFieldsCommon::FlagsMembersCommon::BitsHighCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               BitsLow,
               CarrSoln,
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
        ///     @li @b Field_carrSoln @b field_carrSoln() -
        ///         for FlagsMembers::CarrSoln member field.
        ///     @li @b Field_bitsHigh @b field_bitsHigh() -
        ///         for FlagsMembers::BitsHigh member field.
        COMMS_FIELD_MEMBERS_NAMES(
            bitsLow,
            carrSoln,
            bitsHigh
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::NavRelposnedFieldsCommon::FlagsCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version,
        Reserved1,
        RefStationId,
        Itow,
        RelPosN,
        RelPosE,
        RelPosD,
        RelPosHPN,
        RelPosHPE,
        RelPosHPD,
        Reserved2,
        AccN,
        AccE,
        AccD,
        Flags
    >;
};

/// @brief Definition of <b>"NAV-RELPOSNED"</b> message class.
/// @details
///     See @ref NavRelposnedFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/NavRelposned.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class NavRelposned : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::NavRelposned,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_NavRelposned>,
        comms::option::def::FieldsImpl<typename NavRelposnedFields<TOpt>::All>,
        comms::option::def::MsgType<NavRelposned<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::NavRelposned,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_NavRelposned>,
            comms::option::def::FieldsImpl<typename NavRelposnedFields<TOpt>::All>,
            comms::option::def::MsgType<NavRelposned<TMsgBase, TOpt> >,
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
    ///         for @ref NavRelposnedFields::Version field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() fuction
    ///         for @ref NavRelposnedFields::Reserved1 field.
    ///     @li @b Field_refStationId type and @b field_refStationId() fuction
    ///         for @ref NavRelposnedFields::RefStationId field.
    ///     @li @b Field_itow type and @b field_itow() fuction
    ///         for @ref NavRelposnedFields::Itow field.
    ///     @li @b Field_relPosN type and @b field_relPosN() fuction
    ///         for @ref NavRelposnedFields::RelPosN field.
    ///     @li @b Field_relPosE type and @b field_relPosE() fuction
    ///         for @ref NavRelposnedFields::RelPosE field.
    ///     @li @b Field_relPosD type and @b field_relPosD() fuction
    ///         for @ref NavRelposnedFields::RelPosD field.
    ///     @li @b Field_relPosHPN type and @b field_relPosHPN() fuction
    ///         for @ref NavRelposnedFields::RelPosHPN field.
    ///     @li @b Field_relPosHPE type and @b field_relPosHPE() fuction
    ///         for @ref NavRelposnedFields::RelPosHPE field.
    ///     @li @b Field_relPosHPD type and @b field_relPosHPD() fuction
    ///         for @ref NavRelposnedFields::RelPosHPD field.
    ///     @li @b Field_reserved2 type and @b field_reserved2() fuction
    ///         for @ref NavRelposnedFields::Reserved2 field.
    ///     @li @b Field_accN type and @b field_accN() fuction
    ///         for @ref NavRelposnedFields::AccN field.
    ///     @li @b Field_accE type and @b field_accE() fuction
    ///         for @ref NavRelposnedFields::AccE field.
    ///     @li @b Field_accD type and @b field_accD() fuction
    ///         for @ref NavRelposnedFields::AccD field.
    ///     @li @b Field_flags type and @b field_flags() fuction
    ///         for @ref NavRelposnedFields::Flags field.
    COMMS_MSG_FIELDS_NAMES(
        version,
        reserved1,
        refStationId,
        itow,
        relPosN,
        relPosE,
        relPosD,
        relPosHPN,
        relPosHPE,
        relPosHPD,
        reserved2,
        accN,
        accE,
        accD,
        flags
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 40U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 40U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::NavRelposnedCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


