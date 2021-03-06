// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains definition of <b>"CFG-PM"</b> message and its fields.

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
#include "ublox/message/CfgPmCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref CfgPm.
/// @tparam TOpt Extra options
/// @see @ref CfgPm
/// @headerfile "ublox/message/CfgPm.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct CfgPmFields
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
            return ublox::message::CfgPmFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"res1"</b> field.
    using Res1 =
        ublox::field::Res1<
            TOpt
        >;
    
    /// @brief Definition of <b>"res2"</b> field.
    struct Res2 : public
        ublox::field::Res1<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPmFieldsCommon::Res2Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"res3"</b> field.
    struct Res3 : public
        ublox::field::Res1<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPmFieldsCommon::Res3Common::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of @ref Flags bitfield.
    struct FlagsMembers
    {
        /// @brief Definition of <b>"res1"</b> field.
        /// @details
        ///     Reserved field with 1 byte length
        struct Res1 : public
            comms::field::IntValue<
                ublox::field::FieldBase<>,
                std::uint8_t,
                comms::option::def::FixedBitLength<2U>,
                comms::option::def::ValidNumValue<0>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::Res1Common::name();
            }
            
        };
        
        /// @brief Definition of <b>"internal"</b> field.
        struct Internal : public
            comms::field::IntValue<
                ublox::field::FieldBase<>,
                std::uint8_t,
                comms::option::def::FixedBitLength<2U>,
                comms::option::def::DefaultNumValue<1>,
                comms::option::def::ValidNumValue<1>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::InternalCommon::name();
            }
            
        };
        
        /// @brief Definition of <b>"bitsMid"</b> field.
        class BitsMid : public
            comms::field::BitmaskValue<
                ublox::field::FieldBase<>,
                comms::option::def::FixedBitLength<4U>,
                comms::option::def::BitmaskReservedBits<0x8U, 0x0U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    ublox::field::FieldBase<>,
                    comms::option::def::FixedBitLength<4U>,
                    comms::option::def::BitmaskReservedBits<0x8U, 0x0U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_extintSelect, @b getBitValue_extintSelect() and @b setBitValue_extintSelect().
            ///      @li @b BitIdx_extintWake, @b getBitValue_extintWake() and @b setBitValue_extintWake().
            ///      @li @b BitIdx_extintBackup, @b getBitValue_extintBackup() and @b setBitValue_extintBackup().
            COMMS_BITMASK_BITS_SEQ(
                extintSelect,
                extintWake,
                extintBackup
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::BitsMidCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::BitsMidCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief Definition of <b>"limitPeakCurr"</b> field.
        /// @see @ref ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::LimitPeakCurrVal
        class LimitPeakCurr : public
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::LimitPeakCurrVal,
                comms::option::def::FixedBitLength<2U>,
                comms::option::def::ValidNumValueRange<0, 1>
            >
        {
            using Base = 
                comms::field::EnumValue<
                    ublox::field::FieldBase<>,
                    ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::LimitPeakCurrVal,
                    comms::option::def::FixedBitLength<2U>,
                    comms::option::def::ValidNumValueRange<0, 1>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;
        
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::LimitPeakCurrCommon::name();
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                return ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::LimitPeakCurrCommon::valueName(val);
            }
            
            /// @brief Retrieve name of the @b current value
            const char* valueName() const
            {
                return valueName(Base::value());
            }
            
        };
        
        /// @brief Definition of <b>"bitsHigh"</b> field.
        class BitsHigh : public
            comms::field::BitmaskValue<
                ublox::field::FieldBase<>,
                comms::option::def::FixedBitLength<22U>,
                comms::option::def::BitmaskReservedBits<0x3FFFF8UL, 0x0U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    ublox::field::FieldBase<>,
                    comms::option::def::FixedBitLength<22U>,
                    comms::option::def::BitmaskReservedBits<0x3FFFF8UL, 0x0U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_WaitTimeFix, @b getBitValue_WaitTimeFix() and @b setBitValue_WaitTimeFix().
            ///      @li @b BitIdx_updateRTC, @b getBitValue_updateRTC() and @b setBitValue_updateRTC().
            ///      @li @b BitIdx_updateEPH, @b getBitValue_updateEPH() and @b setBitValue_updateEPH().
            COMMS_BITMASK_BITS_SEQ(
                WaitTimeFix,
                updateRTC,
                updateEPH
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::BitsHighCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::CfgPmFieldsCommon::FlagsMembersCommon::BitsHighCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               Res1,
               Internal,
               BitsMid,
               LimitPeakCurr,
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
        ///     @li @b Field_res1 @b field_res1() -
        ///         for FlagsMembers::Res1 member field.
        ///     @li @b Field_internal @b field_internal() -
        ///         for FlagsMembers::Internal member field.
        ///     @li @b Field_bitsMid @b field_bitsMid() -
        ///         for FlagsMembers::BitsMid member field.
        ///     @li @b Field_limitPeakCurr @b field_limitPeakCurr() -
        ///         for FlagsMembers::LimitPeakCurr member field.
        ///     @li @b Field_bitsHigh @b field_bitsHigh() -
        ///         for FlagsMembers::BitsHigh member field.
        COMMS_FIELD_MEMBERS_NAMES(
            res1,
            internal,
            bitsMid,
            limitPeakCurr,
            bitsHigh
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPmFieldsCommon::FlagsCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"updatePeriod"</b> field.
    struct UpdatePeriod : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsMilliseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPmFieldsCommon::UpdatePeriodCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"searchPeriod"</b> field.
    struct SearchPeriod : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsMilliseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPmFieldsCommon::SearchPeriodCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"gridOffset"</b> field.
    struct GridOffset : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::UnitsMilliseconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPmFieldsCommon::GridOffsetCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"onTime"</b> field.
    struct OnTime : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t,
            comms::option::def::UnitsSeconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPmFieldsCommon::OnTimeCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"minAcqTime"</b> field.
    struct MinAcqTime : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t,
            comms::option::def::UnitsSeconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPmFieldsCommon::MinAcqTimeCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version,
        Res1,
        Res2,
        Res3,
        Flags,
        UpdatePeriod,
        SearchPeriod,
        GridOffset,
        OnTime,
        MinAcqTime
    >;
};

/// @brief Definition of <b>"CFG-PM"</b> message class.
/// @details
///     See @ref CfgPmFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/CfgPm.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class CfgPm : public
    comms::MessageBase<
        TMsgBase,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_CfgPm>,
        comms::option::def::FieldsImpl<typename CfgPmFields<TOpt>::All>,
        comms::option::def::MsgType<CfgPm<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_CfgPm>,
            comms::option::def::FieldsImpl<typename CfgPmFields<TOpt>::All>,
            comms::option::def::MsgType<CfgPm<TMsgBase, TOpt> >,
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
    ///         for @ref CfgPmFields::Version field.
    ///     @li @b Field_res1 type and @b field_res1() fuction
    ///         for @ref CfgPmFields::Res1 field.
    ///     @li @b Field_res2 type and @b field_res2() fuction
    ///         for @ref CfgPmFields::Res2 field.
    ///     @li @b Field_res3 type and @b field_res3() fuction
    ///         for @ref CfgPmFields::Res3 field.
    ///     @li @b Field_flags type and @b field_flags() fuction
    ///         for @ref CfgPmFields::Flags field.
    ///     @li @b Field_updatePeriod type and @b field_updatePeriod() fuction
    ///         for @ref CfgPmFields::UpdatePeriod field.
    ///     @li @b Field_searchPeriod type and @b field_searchPeriod() fuction
    ///         for @ref CfgPmFields::SearchPeriod field.
    ///     @li @b Field_gridOffset type and @b field_gridOffset() fuction
    ///         for @ref CfgPmFields::GridOffset field.
    ///     @li @b Field_onTime type and @b field_onTime() fuction
    ///         for @ref CfgPmFields::OnTime field.
    ///     @li @b Field_minAcqTime type and @b field_minAcqTime() fuction
    ///         for @ref CfgPmFields::MinAcqTime field.
    COMMS_MSG_FIELDS_NAMES(
        version,
        res1,
        res2,
        res3,
        flags,
        updatePeriod,
        searchPeriod,
        gridOffset,
        onTime,
        minAcqTime
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 24U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 24U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::CfgPmCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


