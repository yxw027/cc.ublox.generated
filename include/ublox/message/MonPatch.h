// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains definition of <b>"MON-PATCH"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
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
#include "ublox/message/MonPatchCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref MonPatch.
/// @tparam TOpt Extra options
/// @see @ref MonPatch
/// @headerfile "ublox/message/MonPatch.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct MonPatchFields
{
    /// @brief Definition of <b>"version"</b> field.
    struct Version : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t,
            comms::option::def::DefaultNumValue<1>,
            comms::option::def::ValidNumValue<1>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonPatchFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"nEntries"</b> field.
    struct NEntries : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonPatchFieldsCommon::NEntriesCommon::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of ///     @ref List list.
    struct ListMembers
    {
        /// @brief Scope for all the member fields of @ref Element bundle.
        struct ElementMembers
        {
            /// @brief Scope for all the member fields of @ref PatchInfo bitfield.
            struct PatchInfoMembers
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
                    ///      @li @b BitIdx_activated, @b getBitValue_activated() and @b setBitValue_activated().
                    COMMS_BITMASK_BITS_SEQ(
                        activated
                    );
                    
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoMembersCommon::BitsCommon::name();
                    }
                    
                    /// @brief Retrieve name of the bit.
                    static const char* bitName(BitIdx idx)
                    {
                        return
                            ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoMembersCommon::BitsCommon::bitName(
                                static_cast<std::size_t>(idx));
                    }
                    
                };
                
                /// @brief Definition of <b>"location"</b> field.
                /// @see @ref ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoMembersCommon::LocationVal
                class Location : public
                    comms::field::EnumValue<
                        ublox::field::FieldBase<>,
                        ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoMembersCommon::LocationVal,
                        comms::option::def::FixedBitLength<2U>,
                        comms::option::def::ValidNumValueRange<0, 3>
                    >
                {
                    using Base = 
                        comms::field::EnumValue<
                            ublox::field::FieldBase<>,
                            ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoMembersCommon::LocationVal,
                            comms::option::def::FixedBitLength<2U>,
                            comms::option::def::ValidNumValueRange<0, 3>
                        >;
                public:
                    /// @brief Re-definition of the value type.
                    using ValueType = typename Base::ValueType;
                
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoMembersCommon::LocationCommon::name();
                    }
                    
                    /// @brief Retrieve name of the enum value
                    static const char* valueName(ValueType val)
                    {
                        return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoMembersCommon::LocationCommon::valueName(val);
                    }
                    
                    /// @brief Retrieve name of the @b current value
                    const char* valueName() const
                    {
                        return valueName(Base::value());
                    }
                    
                };
                
                /// @brief Definition of <b>"res4"</b> field.
                /// @details
                ///     Reserved field with 4 bytes length
                struct Res4 : public
                    comms::field::IntValue<
                        ublox::field::FieldBase<>,
                        std::uint32_t,
                        comms::option::def::FixedBitLength<29U>,
                        comms::option::def::ValidNumValue<0>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoMembersCommon::Res4Common::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Bits,
                       Location,
                       Res4
                    >;
            };
            
            /// @brief Definition of <b>"patchInfo"</b> field.
            class PatchInfo : public
                comms::field::Bitfield<
                    ublox::field::FieldBase<>,
                    typename PatchInfoMembers::All
                >
            {
                using Base = 
                    comms::field::Bitfield<
                        ublox::field::FieldBase<>,
                        typename PatchInfoMembers::All
                    >;
            public:
                /// @brief Allow access to internal fields.
                /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
                ///     related to @b comms::field::Bitfield class from COMMS library
                ///     for details.
                ///
                ///     The generated access functions are:
                ///     @li @b Field_bits @b field_bits() -
                ///         for PatchInfoMembers::Bits member field.
                ///     @li @b Field_location @b field_location() -
                ///         for PatchInfoMembers::Location member field.
                ///     @li @b Field_res4 @b field_res4() -
                ///         for PatchInfoMembers::Res4 member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    bits,
                    location,
                    res4
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchInfoCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"comparatorNumber"</b> field.
            struct ComparatorNumber : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::uint32_t
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::ComparatorNumberCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"patchAddress"</b> field.
            struct PatchAddress : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::uint32_t
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchAddressCommon::name();
                }
                
            };
            
            /// @brief Definition of <b>"patchData"</b> field.
            struct PatchData : public
                comms::field::IntValue<
                    ublox::field::FieldBase<>,
                    std::uint32_t
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementMembersCommon::PatchDataCommon::name();
                }
                
            };
            
            /// @brief All members bundled in @b std::tuple.
            using All =
                std::tuple<
                   PatchInfo,
                   ComparatorNumber,
                   PatchAddress,
                   PatchData
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
            ///     @li @b Field_patchInfo @b field_patchInfo() -
            ///         for ElementMembers::PatchInfo member field.
            ///     @li @b Field_comparatorNumber @b field_comparatorNumber() -
            ///         for ElementMembers::ComparatorNumber member field.
            ///     @li @b Field_patchAddress @b field_patchAddress() -
            ///         for ElementMembers::PatchAddress member field.
            ///     @li @b Field_patchData @b field_patchData() -
            ///         for ElementMembers::PatchData member field.
            COMMS_FIELD_MEMBERS_NAMES(
                patchInfo,
                comparatorNumber,
                patchAddress,
                patchData
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return ublox::message::MonPatchFieldsCommon::ListMembersCommon::ElementCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"list"</b> field.
    struct List : public
        comms::field::ArrayList<
            ublox::field::FieldBase<>,
            typename ListMembers::Element,
            typename TOpt::message::MonPatchFields::List,
            comms::option::def::SequenceSizeForcingEnabled
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MonPatchFieldsCommon::ListCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version,
        NEntries,
        List
    >;
};

/// @brief Definition of <b>"MON-PATCH"</b> message class.
/// @details
///     See @ref MonPatchFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/MonPatch.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class MonPatch : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::MonPatch,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_MonPatch>,
        comms::option::def::FieldsImpl<typename MonPatchFields<TOpt>::All>,
        comms::option::def::MsgType<MonPatch<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::MonPatch,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_MonPatch>,
            comms::option::def::FieldsImpl<typename MonPatchFields<TOpt>::All>,
            comms::option::def::MsgType<MonPatch<TMsgBase, TOpt> >,
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
    ///         for @ref MonPatchFields::Version field.
    ///     @li @b Field_nEntries type and @b field_nEntries() fuction
    ///         for @ref MonPatchFields::NEntries field.
    ///     @li @b Field_list type and @b field_list() fuction
    ///         for @ref MonPatchFields::List field.
    COMMS_MSG_FIELDS_NAMES(
        version,
        nEntries,
        list
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 4U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::MonPatchCommon::name();
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
            static_cast<std::size_t>(field_nEntries().value()));
        
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
            auto expectedValue = static_cast<std::size_t>(field_nEntries().value());
            auto realValue = field_list().value().size();
            if (expectedValue != realValue) {
                using PrefixValueType = typename std::decay<decltype(field_nEntries().value())>::type;
                field_nEntries().value() = static_cast<PrefixValueType>(realValue);
                updated = true;
            }
        } while (false);
        
        return updated;
        
    }
    
};

} // namespace message

} // namespace ublox


