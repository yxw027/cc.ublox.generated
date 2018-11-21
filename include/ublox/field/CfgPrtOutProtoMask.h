/// @file
/// @brief Contains definition of <b>"cfgPrtOutProtoMask"</b> field.

#pragma once

#include "comms/field/BitmaskValue.h"
#include "comms/options.h"
#include "ublox/DefaultOptions.h"
#include "ublox/field/FieldBase.h"

namespace ublox
{

namespace field
{

/// @brief Definition of <b>"cfgPrtOutProtoMask"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = ublox::DefaultOptions, typename... TExtraOpts>
class CfgPrtOutProtoMask : public
    comms::field::BitmaskValue<
        ublox::field::FieldBase<>,
        TExtraOpts...,
        comms::option::FixedLength<2U>,
        comms::option::BitmaskReservedBits<0xFFDCU, 0x0U>
    >
{
    using Base = 
        comms::field::BitmaskValue<
            ublox::field::FieldBase<>,
            TExtraOpts...,
            comms::option::FixedLength<2U>,
            comms::option::BitmaskReservedBits<0xFFDCU, 0x0U>
        >;
public:
    /// @brief Provide names for internal bits.
    /// @details See definition of @b COMMS_BITMASK_BITS macro
    ///     related to @b comms::field::BitmaskValue class from COMMS library
    ///     for details.
    ///
    ///      The generated enum values:
    ///      @li @b BitIdx_outUbx.
    ///      @li @b BitIdx_outNmea.
    ///      @li @b BitIdx_outRtcm3.
    COMMS_BITMASK_BITS(
        outUbx=0,
        outNmea=1,
        outRtcm3=5
    );
    
    /// @brief Generates independent access functions for internal bits.
    /// @details See definition of @b COMMS_BITMASK_BITS_ACCESS macro
    ///     related to @b comms::field::BitmaskValue class from COMMS library
    ///     for details.
    ///
    ///     The generated access functions are:
    ///      @li @b getBitValue_outUbx() and @b setBitValue_outUbx().
    ///      @li @b getBitValue_outNmea() and @b setBitValue_outNmea().
    ///      @li @b getBitValue_outRtcm3() and @b setBitValue_outRtcm3().
    COMMS_BITMASK_BITS_ACCESS(
        outUbx,
        outNmea,
        outRtcm3
    );
    
    /// @brief Name of the field.
    static const char* name()
    {
        return "cfgPrtOutProtoMask";
    }
    
};

} // namespace field

} // namespace ublox

