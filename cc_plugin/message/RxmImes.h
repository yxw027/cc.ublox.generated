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

class RxmImesImpl;
class RxmImes : public ublox::cc_plugin::Message
{
public:
    RxmImes();
    RxmImes(const RxmImes&) = delete;
    RxmImes(RxmImes&&) = delete;
    virtual ~RxmImes();
    RxmImes& operator=(const RxmImes& other);
    RxmImes& operator=(RxmImes&&);

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
    std::unique_ptr<RxmImesImpl> m_pImpl;
};

} // namespace message

} // namespace cc_plugin

} // namespace ublox


