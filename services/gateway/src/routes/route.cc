#include "route.h"

void test(const weblib::Request& req) {

}

GatewayServer::GatewayServer(uint16 port) : weblib::CrowServer{port} {
  
}

void GatewayServer::Start() {
  GetRouter()->Get("/test", {test});

  RunCrowServer();
}