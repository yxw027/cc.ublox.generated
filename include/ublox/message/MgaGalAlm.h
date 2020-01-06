// Generated by commsdsl2comms v3.3.0

/// @file
/// @brief Contains definition of <b>"MGA-GAL-ALM"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/Res1.h"
#include "ublox/field/Res4.h"
#include "ublox/message/MgaGalAlmCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref MgaGalAlm.
/// @tparam TOpt Extra options
/// @see @ref MgaGalAlm
/// @headerfile "ublox/message/MgaGalAlm.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct MgaGalAlmFields
{
    /// @brief Definition of <b>"type"</b> field.
    struct Type : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::FailOnInvalid<>,
            comms::option::def::DefaultNumValue<2>,
            comms::option::def::ValidNumValue<2>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::TypeCommon::name();
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
            return ublox::message::MgaGalAlmFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"svid"</b> field.
    struct Svid : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::SvidCommon::name();
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
            return ublox::message::MgaGalAlmFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"ioda"</b> field.
    struct Ioda : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::IodaCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"almWNa"</b> field.
    struct AlmWNa : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::AlmWNaCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"toa"</b> field.
    struct Toa : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t,
            comms::option::def::ScalingRatio<600, 1>,
            comms::option::def::UnitsSeconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::ToaCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"deltaSqrtA"</b> field.
    struct DeltaSqrtA : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::ScalingRatio<1, 512>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::DeltaSqrtACommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"e"</b> field.
    struct E : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint16_t,
            comms::option::def::ScalingRatio<1, 65536L>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::ECommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"deltaI"</b> field.
    struct DeltaI : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::ScalingRatio<1, 16384>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::DeltaICommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"omega0"</b> field.
    struct Omega0 : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::ScalingRatio<1, 32768L>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::Omega0Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"omegaDot"</b> field.
    struct OmegaDot : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::ScalingRatio<1, 0x200000000LL>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::OmegaDotCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"omega"</b> field.
    struct Omega : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::ScalingRatio<1, 32768L>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::OmegaCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"m0"</b> field.
    struct M0 : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::ScalingRatio<1, 32768L>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::M0Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"af0"</b> field.
    struct Af0 : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::ScalingRatio<1, 524288L>,
            comms::option::def::UnitsSeconds
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::Af0Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"af1"</b> field.
    struct Af1 : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::int16_t,
            comms::option::def::ScalingRatio<1, 0x4000000000LL>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::Af1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"healthE1B"</b> field.
    struct HealthE1B : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::HealthE1BCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"healthE5b"</b> field.
    struct HealthE5b : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::HealthE5bCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"reserved2"</b> field.
    struct Reserved2 : public
        ublox::field::Res4<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::MgaGalAlmFieldsCommon::Reserved2Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Type,
        Version,
        Svid,
        Reserved1,
        Ioda,
        AlmWNa,
        Toa,
        DeltaSqrtA,
        E,
        DeltaI,
        Omega0,
        OmegaDot,
        Omega,
        M0,
        Af0,
        Af1,
        HealthE1B,
        HealthE5b,
        Reserved2
    >;
};

/// @brief Definition of <b>"MGA-GAL-ALM"</b> message class.
/// @details
///     See @ref MgaGalAlmFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/MgaGalAlm.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class MgaGalAlm : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::MgaGalAlm,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_MgaGal>,
        comms::option::def::FieldsImpl<typename MgaGalAlmFields<TOpt>::All>,
        comms::option::def::MsgType<MgaGalAlm<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::MgaGalAlm,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_MgaGal>,
            comms::option::def::FieldsImpl<typename MgaGalAlmFields<TOpt>::All>,
            comms::option::def::MsgType<MgaGalAlm<TMsgBase, TOpt> >,
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
    ///         for @ref MgaGalAlmFields::Type field.
    ///     @li @b Field_version type and @b field_version() fuction
    ///         for @ref MgaGalAlmFields::Version field.
    ///     @li @b Field_svid type and @b field_svid() fuction
    ///         for @ref MgaGalAlmFields::Svid field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() fuction
    ///         for @ref MgaGalAlmFields::Reserved1 field.
    ///     @li @b Field_ioda type and @b field_ioda() fuction
    ///         for @ref MgaGalAlmFields::Ioda field.
    ///     @li @b Field_almWNa type and @b field_almWNa() fuction
    ///         for @ref MgaGalAlmFields::AlmWNa field.
    ///     @li @b Field_toa type and @b field_toa() fuction
    ///         for @ref MgaGalAlmFields::Toa field.
    ///     @li @b Field_deltaSqrtA type and @b field_deltaSqrtA() fuction
    ///         for @ref MgaGalAlmFields::DeltaSqrtA field.
    ///     @li @b Field_e type and @b field_e() fuction
    ///         for @ref MgaGalAlmFields::E field.
    ///     @li @b Field_deltaI type and @b field_deltaI() fuction
    ///         for @ref MgaGalAlmFields::DeltaI field.
    ///     @li @b Field_omega0 type and @b field_omega0() fuction
    ///         for @ref MgaGalAlmFields::Omega0 field.
    ///     @li @b Field_omegaDot type and @b field_omegaDot() fuction
    ///         for @ref MgaGalAlmFields::OmegaDot field.
    ///     @li @b Field_omega type and @b field_omega() fuction
    ///         for @ref MgaGalAlmFields::Omega field.
    ///     @li @b Field_m0 type and @b field_m0() fuction
    ///         for @ref MgaGalAlmFields::M0 field.
    ///     @li @b Field_af0 type and @b field_af0() fuction
    ///         for @ref MgaGalAlmFields::Af0 field.
    ///     @li @b Field_af1 type and @b field_af1() fuction
    ///         for @ref MgaGalAlmFields::Af1 field.
    ///     @li @b Field_healthE1B type and @b field_healthE1B() fuction
    ///         for @ref MgaGalAlmFields::HealthE1B field.
    ///     @li @b Field_healthE5b type and @b field_healthE5b() fuction
    ///         for @ref MgaGalAlmFields::HealthE5b field.
    ///     @li @b Field_reserved2 type and @b field_reserved2() fuction
    ///         for @ref MgaGalAlmFields::Reserved2 field.
    COMMS_MSG_FIELDS_NAMES(
        type,
        version,
        svid,
        reserved1,
        ioda,
        almWNa,
        toa,
        deltaSqrtA,
        e,
        deltaI,
        omega0,
        omegaDot,
        omega,
        m0,
        af0,
        af1,
        healthE1B,
        healthE5b,
        reserved2
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 32U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 32U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::MgaGalAlmCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox


