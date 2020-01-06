// Generated by commsdsl2comms v3.3.0

#include "MsgId.h"

#include "comms_champion/property/field.h"
#include "ublox/field/MsgId.h"


namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_msgId(const char* name, bool serHidden)
{
    static_cast<void>(serHidden);
    using Field = ublox::field::MsgId<>;
    return
        cc::property::field::ForField<Field>()
            .name(name)
            .serialisedHidden(serHidden)
            .add("NAV-POSECEF", 257)
            .add("NAV-POSLLH", 258)
            .add("NAV-STATUS", 259)
            .add("NAV-DOP", 260)
            .add("NAV-ATT", 261)
            .add("NAV-SOL", 262)
            .add("NAV-PVT", 263)
            .add("NAV-ODO", 265)
            .add("NAV-RESETODO", 272)
            .add("NAV-VELECEF", 273)
            .add("NAV-VELNED", 274)
            .add("NAV-HPPOSECEF", 275)
            .add("NAV-HPPOSLLH", 276)
            .add("NAV-TIMEGPS", 288)
            .add("NAV-TIMEUTC", 289)
            .add("NAV-CLOCK", 290)
            .add("NAV-TIMEGLO", 291)
            .add("NAV-TIMEBDS", 292)
            .add("NAV-TIMEGAL", 293)
            .add("NAV-MsgId_NAV_TIMELS", 294)
            .add("NAV-SVINFO", 304)
            .add("NAV-DGPS", 305)
            .add("NAV-SBAS", 306)
            .add("NAV-ORB", 308)
            .add("NAV-SAT", 309)
            .add("NAV-GEOFENCE", 313)
            .add("NAV-SVIN", 315)
            .add("NAV-RELPOSNED", 316)
            .add("NAV-EKFSTATUS", 320)
            .add("NAV-AOPSTATUS", 352)
            .add("NAV-EOE", 353)
            .add("RXM-RAW", 528)
            .add("RXM-SFRB", 529)
            .add("RXM-SFRBX", 531)
            .add("RXM-MEASX", 532)
            .add("RXM-RAWX", 533)
            .add("RXM-SVSI", 544)
            .add("RXM-ALM", 560)
            .add("RXM-EPH", 561)
            .add("RXM-RTCM", 562)
            .add("RXM-PMREQ", 577)
            .add("RXM-RLM", 601)
            .add("RXM-IMES", 609)
            .add("INF-ERROR", 1024)
            .add("INF-WARNING", 1025)
            .add("INF-NOTICE", 1026)
            .add("INF-TEST", 1027)
            .add("INF-DEBUG", 1028)
            .add("ACK-NAK", 1280)
            .add("ACK-ACK", 1281)
            .add("CFG-PRT", 1536)
            .add("CFG-MSG", 1537)
            .add("CFG-INF", 1538)
            .add("CFG-RST", 1540)
            .add("CFG-DAT", 1542)
            .add("CFG-TP", 1543)
            .add("CFG-RATE", 1544)
            .add("CFG-CFG", 1545)
            .add("CFG-FXN", 1550)
            .add("CFG-RXM", 1553)
            .add("CFG-EKF", 1554)
            .add("CFG-ANT", 1555)
            .add("CFG-SBAS", 1558)
            .add("CFG-NMEA", 1559)
            .add("CFG-USB", 1563)
            .add("CFG-TMODE", 1565)
            .add("CFG-ODO", 1566)
            .add("CFG-NVS", 1570)
            .add("CFG-NAVX5", 1571)
            .add("CFG-NAV5", 1572)
            .add("CFG-ESFGWT", 1577)
            .add("CFG-TP5", 1585)
            .add("CFG-PM", 1586)
            .add("CFG-RINV", 1588)
            .add("CFG-ITFM", 1593)
            .add("CFG-PM2", 1595)
            .add("CFG-TMODE2", 1597)
            .add("CFG-GNSS", 1598)
            .add("CFG-LOGFILTER", 1607)
            .add("CFG-TXSLOT", 1619)
            .add("CFG-PWR", 1623)
            .add("CFG-HNR", 1628)
            .add("CFG-ESRC", 1632)
            .add("CFG-DOSC", 1633)
            .add("CFG-SMGR", 1634)
            .add("CFG-GEOFENCE", 1641)
            .add("CFG-DGNSS", 1648)
            .add("CFG-TMODE3", 1649)
            .add("CFG-FIXSEED", 1668)
            .add("CFG-DYNSEED", 1669)
            .add("CFG-PMS", 1670)
            .add("UPD-SOS", 2324)
            .add("MON-IO", 2562)
            .add("MON-VER", 2564)
            .add("MON-MSGPP", 2566)
            .add("MON-RXBUF", 2567)
            .add("MON-TXBUF", 2568)
            .add("MON-HW", 2569)
            .add("MON-HW2", 2571)
            .add("MON-RXR", 2593)
            .add("MON-PATCH", 2599)
            .add("MON-GNSS", 2600)
            .add("MON-SMGR", 2606)
            .add("AID-REQ", 2816)
            .add("AID-INI", 2817)
            .add("AID-HUI", 2818)
            .add("AID-DATA", 2832)
            .add("AID-ALM", 2864)
            .add("AID-EPH", 2865)
            .add("AID-ALPSRV", 2866)
            .add("AID-AOP", 2867)
            .add("AID-ALP", 2896)
            .add("TIM-TP", 3329)
            .add("TIM-TM2", 3331)
            .add("TIM-VRFY", 3332)
            .add("TIM-SVIN", 3334)
            .add("TIM-DOSC", 3345)
            .add("TIM-TOS", 3346)
            .add("TIM-SMEAS", 3347)
            .add("TIM-VCOCAL", 3349)
            .add("TIM-FCHG", 3350)
            .add("TIM-HOC", 3351)
            .add("ESF-MEAS", 4098)
            .add("ESF-RAW", 4099)
            .add("ESF-STATUS", 4112)
            .add("ESF-INS", 4117)
            .add("MGA-GPS", 4864)
            .add("MGA-GAL", 4866)
            .add("MGA-BDS", 4867)
            .add("MGA-QZSS", 4869)
            .add("MGA-GLO", 4870)
            .add("MGA-ANO", 4896)
            .add("MGA-FLASH", 4897)
            .add("MGA-INI", 4928)
            .add("MGA-ACK", 4960)
            .add("MGA-DBD", 4992)
            .add("LOG-ERASE", 8451)
            .add("LOG-STRING", 8452)
            .add("LOG-CREATE", 8455)
            .add("LOG-INFO", 8456)
            .add("LOG-RETRIEVE", 8457)
            .add("LOG-RETRIEVEPOS", 8459)
            .add("LOG-RETRIEVESTRING", 8461)
            .add("LOG-FINDTIME", 8462)
            .add("LOG-RETRIEVEPOSEXTRA", 8463)
            .add("SEC-SIGN", 9985)
            .add("SEC-UNIQID", 9987)
            .add("HNR-PVT", 10240)
            .asMap();
    
}

} // namespace field

} // namespace cc_plugin

} // namespace ublox


