#include "server.h"

namespace weblib {

BaseServer::BaseServer(uint16 port) : port_{port} {

}

std::shared_ptr<Router> BaseServer::GetRouter() {
  return router_;
}

CrowServer::CrowServer(uint16 port) : BaseServer{port} {
  router_ = std::make_shared<RouterCrow>(crow_);
}

void CrowServer::RunCrowServer() {
  crow_.port(port_).run();
}

} // namespace weblib
