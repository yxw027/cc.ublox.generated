// Generated by commsdsl2comms v3.3.1

/// @file
/// @brief Contains definition of <b>"CFG-DOSC"</b> message and its fields.

#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <utility>
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/Bundle.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/Res1.h"
#include "ublox/field/Res2.h"
#include "ublox/field/Res3.h"
#include "ublox/message/CfgDoscCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref CfgDosc.
/// @tparam TOpt Extra options
/// @see @ref CfgDosc
/// @headerfile "ublox/message/CfgDosc.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct CfgDoscFields
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
            return ublox::message::CfgDoscFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"numOsc"</b> field.
    struct NumOsc : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgDoscFieldsCommon::NumOscCommon::name();
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
            return ublox::message::CfgDoscFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of ///     @ref List list.
    struct ListMembers
    {
        /// @brief Scope for all the member fields of @ref Element bundle.
        struct ElementMembers
        {
            /// @brief Definition of <b>"oscId"</b> field.
            /// @see @ref ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::OscIdVal
            class OscId : public
                comms::field::EnumValue<
                    ublox::field::FieldBase<>,
                    ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::OscIdVal,
                    comms::option::def::ValidNumValueRange<0, 1>
                >
            {
                using Base = 
                    comms::field::EnumValue<
                        ublox::field::FieldBase<>,
                        ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::OscIdVal,
                        comms::option::def::ValidNumValueRange<0, 1>
                    >;
            public:
                /// @brief Re-definition of the value type.
                using ValueType = typename Base::ValueType;
            
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::OscIdCommon::name();
                }
                
                /// @brief Retrieve name of the enum value
                static const char* valueName(ValueType val)
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::OscIdCommon::valueName(val);
                }
                
                /// @brief Retrieve name of the @b current value
                const char* valueName() const
                {
                    return valueName(Base::value());
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
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::Reserved2Common::name();
                }
                
            };
            
            /// @brief Scope for all the member fields of @ref Flags bitfield.
            struct FlagsMembers
            {
                /// @brief Definition of <b>""</b> field.
                class Bits : public
                    comms::field::BitmaskValue<
                        ublox::field::FieldBase<>,
                        comms::option::def::FixedBitLength<1U>
                    >
                {
                    using Base = 
                        comms::field::BitmaskValue<
                            ublox::field::FieldBase<>,
                            comms::option::def::FixedBitLength<1U>
                        >;
                public:
                    /// @brief Provides names and generates access functions for internal bits.
                    /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
                    ///     related to @b comms::field::BitmaskValue class from COMMS library
                    ///     for details.
                    ///
                    ///      The generated enum values and functions are:
                    ///      @li @b BitIdx_isCalibrated, @b getBitValue_isCalibrated() and @b setBitValue_isCalibrated().
                    COMMS_BITMASK_BITS_SEQ(
                        isCalibrated
                    );
                    
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsMembersCommon::BitsCommon::name();
                    }
                    
                    /// @brief Retrieve name of the bit.
                    static const char* bitName(BitIdx idx)
                    {
                        return
                            ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsMembersCommon::BitsCommon::bitName(
                                static_cast<std::size_t>(idx));
                    }
                    
                };
                
                /// @brief Definition of <b>"controlIf"</b> field.
                /// @see @ref ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsMembersCommon::ControlIfVal
                class ControlIf : public
                    comms::field::EnumValue<
                        ublox::field::FieldBase<>,
                        ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsMembersCommon::ControlIfVal,
                        comms::option::def::FixedBitLength<4U>,
                        comms::option::def::ValidNumValueRange<0, 2>,
                        comms::option::def::ValidNumValueRange<13, 15>
                    >
                {
                    using Base = 
                        comms::field::EnumValue<
                            ublox::field::FieldBase<>,
                            ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsMembersCommon::ControlIfVal,
                            comms::option::def::FixedBitLength<4U>,
                            comms::option::def::ValidNumValueRange<0, 2>,
                            comms::option::def::ValidNumValueRange<13, 15>
                        >;
                public:
                    /// @brief Re-definition of the value type.
                    using ValueType = typename Base::ValueType;
                
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsMembersCommon::ControlIfCommon::name();
                    }
                    
                    /// @brief Retrieve name of the enum value
                    static const char* valueName(ValueType val)
                    {
                        return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsMembersCommon::ControlIfCommon::valueName(val);
                    }
                    
                    /// @brief Retrieve name of the @b current value
                    const char* valueName() const
                    {
                        return valueName(Base::value());
                    }
                    
                };
                
                /// @brief Definition of <b>"reserved"</b> field.
                /// @details
                ///     Reserved field with 2 bytes length
                struct Reserved : public
                    comms::field::IntValue<
                        ublox::field::FieldBase<>,
                        std::uint16_t,
                        comms::option::def::FixedBitLength<11U>,
                        comms::option::def::ValidNumValue<0>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsMembersCommon::ReservedCommon::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Bits,
                       ControlIf,
                       Reserved
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
                ///     @li @b Field_bits @b field_bits() -
                ///         for FlagsMembers::Bits member field.
                ///     @li @b Field_controlIf @b field_controlIf() -
                ///         for FlagsMembers::ControlIf member field.
                ///     @li @b Field_reserved @b field_reserved() -
                ///         for FlagsMembers::Reserved member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    bits,
                    controlIf,
                    reserved
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FlagsCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"freq"</b> field.
            struct Freq : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::uint32_t,
                    comms::option::def::ScalingRatio<1, 4>,
                    comms::option::def::UnitsHertz
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::FreqCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"phaseOffset"</b> field.
            struct PhaseOffset : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::int32_t
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::PhaseOffsetCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"withTemp"</b> field.
            struct WithTemp : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::uint32_t,
                    comms::option::def::ScalingRatio<1, 256>
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::WithTempCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"withAge"</b> field.
            struct WithAge : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::uint32_t,
                    comms::option::def::ScalingRatio<1, 256>
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::WithAgeCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"timeToTemp"</b> field.
            struct TimeToTemp : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::uint16_t,
                    comms::option::def::UnitsSeconds
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::TimeToTempCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"reserved3"</b> field.
            struct Reserved3 : public
                ublox::field::Res2<
                    TOpt
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::Reserved3Common::name();
                }
                
            };
            
            /// @brief Definition of <b>"gainVco"</b> field.
            struct GainVco : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::int32_t,
                    comms::option::def::ScalingRatio<1, 65536L>
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::GainVcoCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"gainUncertainty"</b> field.
            struct GainUncertainty : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::uint8_t,
                    comms::option::def::ScalingRatio<1, 256>
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::GainUncertaintyCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"reserved4"</b> field.
            struct Reserved4 : public
                ublox::field::Res3<
                    TOpt
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementMembersCommon::Reserved4Common::name();
                }
                
            };
            
            /// @brief All members bundled in @b std::tuple.
            using All =
                std::tuple<
                   OscId,
                   Reserved2,
                   Flags,
                   Freq,
                   PhaseOffset,
                   WithTemp,
                   WithAge,
                   TimeToTemp,
                   Reserved3,
                   GainVco,
                   GainUncertainty,
                   Reserved4
                >;
        };
        
        /// @brief Definition of <b>""</b> field.
        class Element : public
            comms::field::Bundle<
                ublox::field::FieldBase<>,
                typename ElementMembers::All
            >
        {
            using Base = 
                comms::field::Bundle<
                    ublox::field::FieldBase<>,
                    typename ElementMembers::All
                >;
        public:
            /// @brief Allow access to internal fields.
            /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
            ///     related to @b comms::field::Bundle class from COMMS library
            ///     for details.
            ///
            ///     The generated access functions are:
            ///     @li @b Field_oscId @b field_oscId() -
            ///         for ElementMembers::OscId member field.
            ///     @li @b Field_reserved2 @b field_reserved2() -
            ///         for ElementMembers::Reserved2 member field.
            ///     @li @b Field_flags @b field_flags() -
            ///         for ElementMembers::Flags member field.
            ///     @li @b Field_freq @b field_freq() -
            ///         for ElementMembers::Freq member field.
            ///     @li @b Field_phaseOffset @b field_phaseOffset() -
            ///         for ElementMembers::PhaseOffset member field.
            ///     @li @b Field_withTemp @b field_withTemp() -
            ///         for ElementMembers::WithTemp member field.
            ///     @li @b Field_withAge @b field_withAge() -
            ///         for ElementMembers::WithAge member field.
            ///     @li @b Field_timeToTemp @b field_timeToTemp() -
            ///         for ElementMembers::TimeToTemp member field.
            ///     @li @b Field_reserved3 @b field_reserved3() -
            ///         for ElementMembers::Reserved3 member field.
            ///     @li @b Field_gainVco @b field_gainVco() -
            ///         for ElementMembers::GainVco member field.
            ///     @li @b Field_gainUncertainty @b field_gainUncertainty() -
            ///         for ElementMembers::GainUncertainty member field.
            ///     @li @b Field_reserved4 @b field_reserved4() -
            ///         for ElementMembers::Reserved4 member field.
            COMMS_FIELD_MEMBERS_NAMES(
                oscId,
                reserved2,
                flags,
                freq,
                phaseOffset,
                withTemp,
                withAge,
                timeToTemp,
                reserved3,
                gainVco,
                gainUncertainty,
                reserved4
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::CfgDoscFieldsCommon::ListMembersCommon::ElementCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"list"</b> field.
    struct List : public
        comms::field::ArrayList<
            ublox::field::FieldBase<>,
            typename ListMembers::Element,
            typename TOpt::message::CfgDoscFields::List,
            comms::option::def::SequenceSizeForcingEnabled
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgDoscFieldsCommon::ListCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version,
        NumOsc,
        Reserved1,
        List
    >;
};

/// @brief Definition of <b>"CFG-DOSC"</b> message class.
/// @details
///     See @ref CfgDoscFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/CfgDosc.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class CfgDosc : public
    comms::MessageBase<
        TMsgBase,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_CfgDosc>,
        comms::option::def::FieldsImpl<typename CfgDoscFields<TOpt>::All>,
        comms::option::def::MsgType<CfgDosc<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_CfgDosc>,
            comms::option::def::FieldsImpl<typename CfgDoscFields<TOpt>::All>,
            comms::option::def::MsgType<CfgDosc<TMsgBase, TOpt> >,
            comms::option::def::HasName,
            comms::option::def::HasCustomRefresh
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_version type and @b field_version() fuction
    ///         for @ref CfgDoscFields::Version field.
    ///     @li @b Field_numOsc type and @b field_numOsc() fuction
    ///         for @ref CfgDoscFields::NumOsc field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() fuction
    ///         for @ref CfgDoscFields::Reserved1 field.
    ///     @li @b Field_list type and @b field_list() fuction
    ///         for @ref CfgDoscFields::List field.
    COMMS_MSG_FIELDS_NAMES(
        version,
        numOsc,
        reserved1,
        list
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 4U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::CfgDoscCommon::name();
    }
    
    /// @brief Custom read functionality.
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        auto es = Base::template doReadUntilAndUpdateLen<FieldIdx_list>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        field_list().forceReadElemCount(
            static_cast<std::size_t>(field_numOsc().value()));
        
        es = Base::template doReadFrom<FieldIdx_list>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        return comms::ErrorStatus::Success;
    }
    
    /// @brief Custom refresh functionality.
    bool doRefresh()
    {
        bool updated = Base::doRefresh();
        updated = refresh_list() || updated;
        return updated;
    }
    
    
private:
    bool refresh_list()
    {
        bool updated = false;
        do {
            auto expectedValue = static_cast<std::size_t>(field_numOsc().value());
            auto realValue = field_list().value().size();
            if (expectedValue != realValue) {
                using PrefixValueType = typename std::decay<decltype(field_numOsc().value())>::type;
                field_numOsc().value() = static_cast<PrefixValueType>(realValue);
                updated = true;
            }
        } while (false);
        
        return updated;
        
    }
    
};

} // namespace message

} // namespace ublox


