#pragma once

#include <memory>

#include "router.h"
#include "types.h"

namespace weblib {

class BaseServer {
public:
  BaseServer(uint16 port);

  virtual void Start() = 0;

  std::shared_ptr<Router> GetRouter();

protected:
  uint16 port_;
  std::shared_ptr<Router> router_;
};

class CrowServer : public BaseServer {
public:
  CrowServer(uint16 port);

  virtual void Start() = 0;
  virtual void RunCrowServer();

private:
  crow::SimpleApp crow_;
};

} // namespace weblib
