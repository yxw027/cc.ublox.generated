// Generated by commsdsl2comms v3.3.2

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

class NavVelecefImpl;
class NavVelecef : public ublox::cc_plugin::Message
{
public:
    NavVelecef();
    NavVelecef(const NavVelecef&) = delete;
    NavVelecef(NavVelecef&&) = delete;
    virtual ~NavVelecef();
    NavVelecef& operator=(const NavVelecef& other);
    NavVelecef& operator=(NavVelecef&&);

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
    std::unique_ptr<NavVelecefImpl> m_pImpl;
};

} // namespace message

} // namespace cc_plugin

} // namespace ublox



