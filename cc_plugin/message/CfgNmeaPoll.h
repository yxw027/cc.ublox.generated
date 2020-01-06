// Generated by commsdsl2comms v3.3.0

#pragma once

#include <memory>
#include <QtCore/QVariantList>
#include "cc_plugin/Message.h"

namespace ublox
{

namespace cc_plugin
{

namespace message
{

class CfgNmeaPollImpl;
class CfgNmeaPoll : public ublox::cc_plugin::Message
{
public:
    CfgNmeaPoll();
    CfgNmeaPoll(const CfgNmeaPoll&) = delete;
    CfgNmeaPoll(CfgNmeaPoll&&) = delete;
    virtual ~CfgNmeaPoll();
    CfgNmeaPoll& operator=(const CfgNmeaPoll& other);
    CfgNmeaPoll& operator=(CfgNmeaPoll&&);

protected:
    virtual const char* nameImpl() const override;
    virtual const QVariantList& fieldsPropertiesImpl() const override;
    virtual void dispatchImpl(comms_champion::MessageHandler& handler) override;
    virtual void resetImpl() override;
    virtual bool assignImpl(const comms_champion::Message& other) override;
    virtual MsgIdParamType getIdImpl() const override;
    virtual comms::ErrorStatus readImpl(ReadIterator& iter, std::size_t len) override;
    virtual comms::ErrorStatus writeImpl(WriteIterator& iter, std::size_t len) const override;
    virtual bool validImpl() const override;
    virtual std::size_t lengthImpl() const override;
    virtual bool refreshImpl() override;

private:
    std::unique_ptr<CfgNmeaPollImpl> m_pImpl;
};

} // namespace message

} // namespace cc_plugin

} // namespace ublox



