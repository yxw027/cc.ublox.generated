// Generated by commsdsl2comms v3.3.2

/// @file
/// @brief Contains definition of <b>"cfgDatD"</b> field.

#pragma once

#include "comms/field/FloatValue.h"
#include "comms/options.h"
#include "ublox/field/CfgDatDCommon.h"
#include "ublox/field/FieldBase.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace field
{

/// @brief Definition of <b>"cfgDatD"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = ublox::options::DefaultOptions, typename... TExtraOpts>
class CfgDatD : public
    comms::field::FloatValue<
        ublox::field::FieldBase<>,
        float,
        TExtraOpts...,
        comms::option::def::UnitsMeters,
        comms::option::def::InvalidByDefault
    >
{
    using Base = 
        comms::field::FloatValue<
            ublox::field::FieldBase<>,
            float,
            TExtraOpts...,
            comms::option::def::UnitsMeters,
            comms::option::def::InvalidByDefault
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;

    /// @brief Name of the field.
    static const char* name()
    {
        return ublox::field::CfgDatDCommon::name();
    }
    
    /// @brief Custom validity check
    bool valid() const
    {
        if (Base::valid()) {
            return true;
        }
    
        if ((static_cast<ValueType>(-500.000000) <= Base::value()) &&
            (Base::value() <= static_cast<ValueType>(500.000000))) {
            return true;
        }
        
        return false;
    }
    
};

} // namespace field

} // namespace ublox


