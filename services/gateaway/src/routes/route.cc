#include "route.h"

void aboba(weblib::Request req) {

}

GatewayServer::GatewayServer(uint16 port) : weblib::CrowServer{port} {
  
}

void GatewayServer::Start() {
  GetRouter()->Get("/test", {aboba});

  RunCrowServer();
}