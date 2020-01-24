// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains definition of <b>"MON-HW"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/Res1.h"
#include "ublox/field/Res2.h"
#include "ublox/message/MonHwCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref MonHw.
/// @tparam TOpt Extra options
/// @see @ref MonHw
/// @headerfile "ublox/message/MonHw.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct MonHwFields
{
    /// @brief Definition of <b>"pinSel"</b> field.
    struct PinSel : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::PinSelCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"pinBank"</b> field.
    struct PinBank : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::PinBankCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"pinDir"</b> field.
    struct PinDir : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::PinDirCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"pinVal"</b> field.
    struct PinVal : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::PinValCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"noisePerMS"</b> field.
    struct NoisePerMS : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::NoisePerMSCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"agcCnt"</b> field.
    struct AgcCnt : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::AgcCntCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"aStatus"</b> field.
    /// @see @ref ublox::message::MonHwFieldsCommon::AStatusVal
    class AStatus : public
        comms::field::EnumValue<
            ublox::field::FieldBase<>,
            ublox::message::MonHwFieldsCommon::AStatusVal,
            comms::option::def::ValidNumValueRange<0, 4>
        >
    {
        using Base = 
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::MonHwFieldsCommon::AStatusVal,
                comms::option::def::ValidNumValueRange<0, 4>
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;
    
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::AStatusCommon::name();
        }
        
        /// @brief Retrieve name of the enum value
        static const char* valueName(ValueType val)
        {
            return ublox::message::MonHwFieldsCommon::AStatusCommon::valueName(val);
        }
        
        /// @brief Retrieve name of the @b current value
        const char* valueName() const
        {
            return valueName(Base::value());
        }
        
    };
    
    /// @brief Definition of <b>"aPower"</b> field.
    /// @see @ref ublox::message::MonHwFieldsCommon::APowerVal
    class APower : public
        comms::field::EnumValue<
            ublox::field::FieldBase<>,
            ublox::message::MonHwFieldsCommon::APowerVal,
            comms::option::def::ValidNumValueRange<0, 2>
        >
    {
        using Base = 
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::MonHwFieldsCommon::APowerVal,
                comms::option::def::ValidNumValueRange<0, 2>
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;
    
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::APowerCommon::name();
        }
        
        /// @brief Retrieve name of the enum value
        static const char* valueName(ValueType val)
        {
            return ublox::message::MonHwFieldsCommon::APowerCommon::valueName(val);
        }
        
        /// @brief Retrieve name of the @b current value
        const char* valueName() const
        {
            return valueName(Base::value());
        }
        
    };
    
    /// @brief Scope for all the member fields of @ref Flags bitfield.
    struct FlagsMembers
    {
        /// @brief Definition of <b>""</b> field.
        class BitsLow : public
            comms::field::BitmaskValue<
                ublox::field::FieldBase<>,
                comms::option::def::FixedBitLength<2U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    ublox::field::FieldBase<>,
                    comms::option::def::FixedBitLength<2U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_rtcCalib, @b getBitValue_rtcCalib() and @b setBitValue_rtcCalib().
            ///      @li @b BitIdx_safeBoot, @b getBitValue_safeBoot() and @b setBitValue_safeBoot().
            COMMS_BITMASK_BITS_SEQ(
                rtcCalib,
                safeBoot
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::MonHwFieldsCommon::FlagsMembersCommon::BitsLowCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::MonHwFieldsCommon::FlagsMembersCommon::BitsLowCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief Definition of <b>"jammingState"</b> field.
        /// @see @ref ublox::message::MonHwFieldsCommon::FlagsMembersCommon::JammingStateVal
        class JammingState : public
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::MonHwFieldsCommon::FlagsMembersCommon::JammingStateVal,
                comms::option::def::FixedBitLength<2U>,
                comms::option::def::ValidNumValueRange<0, 3>
            >
        {
            using Base = 
                comms::field::EnumValue<
                    ublox::field::FieldBase<>,
                    ublox::message::MonHwFieldsCommon::FlagsMembersCommon::JammingStateVal,
                    comms::option::def::FixedBitLength<2U>,
                    comms::option::def::ValidNumValueRange<0, 3>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;
        
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::MonHwFieldsCommon::FlagsMembersCommon::JammingStateCommon::name();
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                return ublox::message::MonHwFieldsCommon::FlagsMembersCommon::JammingStateCommon::valueName(val);
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
            ///      @li @b BitIdx_xtalAbsent, @b getBitValue_xtalAbsent() and @b setBitValue_xtalAbsent().
            COMMS_BITMASK_BITS_SEQ(
                xtalAbsent
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::MonHwFieldsCommon::FlagsMembersCommon::BitsHighCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    ublox::message::MonHwFieldsCommon::FlagsMembersCommon::BitsHighCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               BitsLow,
               JammingState,
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
        ///     @li @b Field_jammingState @b field_jammingState() -
        ///         for FlagsMembers::JammingState member field.
        ///     @li @b Field_bitsHigh @b field_bitsHigh() -
        ///         for FlagsMembers::BitsHigh member field.
        COMMS_FIELD_MEMBERS_NAMES(
            bitsLow,
            jammingState,
            bitsHigh
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::FlagsCommon::name();
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
            return ublox::message::MonHwFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"usedMask"</b> field.
    struct UsedMask : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::UsedMaskCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"VP"</b> field.
    struct VP : public
        comms::field::ArrayList<
            ublox::field::FieldBase<>,
            std::uint8_t,
            typename TOpt::message::MonHwFields::VP,
            comms::option::def::SequenceFixedSize<17U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::VPCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"jamInd"</b> field.
    struct JamInd : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::JamIndCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"reserved2"</b> field.
    struct Reserved2 : public
        ublox::field::Res2<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::Reserved2Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"pinIrq"</b> field.
    struct PinIrq : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::PinIrqCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"pullH"</b> field.
    struct PullH : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::PullHCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"pullL"</b> field.
    struct PullL : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonHwFieldsCommon::PullLCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        PinSel,
        PinBank,
        PinDir,
        PinVal,
        NoisePerMS,
        AgcCnt,
        AStatus,
        APower,
        Flags,
        Reserved1,
        UsedMask,
        VP,
        JamInd,
        Reserved2,
        PinIrq,
        PullH,
        PullL
    >;
};

/// @brief Definition of <b>"MON-HW"</b> message class.
/// @details
///     See @ref MonHwFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/MonHw.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class MonHw : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::MonHw,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_MonHw>,
        comms::option::def::FieldsImpl<typename MonHwFields<TOpt>::All>,
        comms::option::def::MsgType<MonHw<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::MonHw,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_MonHw>,
            comms::option::def::FieldsImpl<typename MonHwFields<TOpt>::All>,
            comms::option::def::MsgType<MonHw<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_pinSel type and @b field_pinSel() fuction
    ///         for @ref MonHwFields::PinSel field.
    ///     @li @b Field_pinBank type and @b field_pinBank() fuction
    ///         for @ref MonHwFields::PinBank field.
    ///     @li @b Field_pinDir type and @b field_pinDir() fuction
    ///         for @ref MonHwFields::PinDir field.
    ///     @li @b Field_pinVal type and @b field_pinVal() fuction
    ///         for @ref MonHwFields::PinVal field.
    ///     @li @b Field_noisePerMS type and @b field_noisePerMS() fuction
    ///         for @ref MonHwFields::NoisePerMS field.
    ///     @li @b Field_agcCnt type and @b field_agcCnt() fuction
    ///         for @ref MonHwFields::AgcCnt field.
    ///     @li @b Field_aStatus type and @b field_aStatus() fuction
    ///         for @ref MonHwFields::AStatus field.
    ///     @li @b Field_aPower type and @b field_aPower() fuction
    ///         for @ref MonHwFields::APower field.
    ///     @li @b Field_flags type and @b field_flags() fuction
    ///         for @ref MonHwFields::Flags field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() fuction
    ///         for @ref MonHwFields::Reserved1 field.
    ///     @li @b Field_usedMask type and @b field_usedMask() fuction
    ///         for @ref MonHwFields::UsedMask field.
    ///     @li @b Field_vP type and @b field_vP() fuction
    ///         for @ref MonHwFields::VP field.
    ///     @li @b Field_jamInd type and @b field_jamInd() fuction
    ///         for @ref MonHwFields::JamInd field.
    ///     @li @b Field_reserved2 type and @b field_reserved2() fuction
    ///         for @ref MonHwFields::Reserved2 field.
    ///     @li @b Field_pinIrq type and @b field_pinIrq() fuction
    ///         for @ref MonHwFields::PinIrq field.
    ///     @li @b Field_pullH type and @b field_pullH() fuction
    ///         for @ref MonHwFields::PullH field.
    ///     @li @b Field_pullL type and @b field_pullL() fuction
    ///         for @ref MonHwFields::PullL field.
    COMMS_MSG_FIELDS_NAMES(
        pinSel,
        pinBank,
        pinDir,
        pinVal,
        noisePerMS,
        agcCnt,
        aStatus,
        aPower,
        flags,
        reserved1,
        usedMask,
        vP,
        jamInd,
        reserved2,
        pinIrq,
        pullH,
        pullL
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 60U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 60U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::MonHwCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


