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

class CfgPmPollImpl;
class CfgPmPoll : public ublox::cc_plugin::Message
{
public:
    CfgPmPoll();
    CfgPmPoll(const CfgPmPoll&) = delete;
    CfgPmPoll(CfgPmPoll&&) = delete;
    virtual ~CfgPmPoll();
    CfgPmPoll& operator=(const CfgPmPoll& other);
    CfgPmPoll& operator=(CfgPmPoll&&);

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
    std::unique_ptr<CfgPmPollImpl> m_pImpl;
};

} // namespace message

} // namespace cc_plugin

} // namespace ublox


