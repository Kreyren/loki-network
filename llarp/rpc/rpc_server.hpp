#pragma once

#include <string_view>
#include <lokimq/lokimq.h>
#include <lokimq/address.h>

namespace llarp
{
  struct AbstractRouter;
}

namespace llarp::rpc
{
  using LMQ_ptr = std::shared_ptr<lokimq::LokiMQ>;

  struct RpcServer
  {
    explicit RpcServer(LMQ_ptr, AbstractRouter*);
    ~RpcServer() = default;
    void
    AsyncServeRPC(lokimq::address addr);

   private:
    LMQ_ptr m_LMQ;
    AbstractRouter* const m_Router;
  };
}  // namespace llarp::rpc
