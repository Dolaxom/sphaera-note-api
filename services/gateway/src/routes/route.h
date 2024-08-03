#include "server.h"

class GatewayServer : public weblib::CrowServer {
public:
  GatewayServer(uint16 port);

  void Start() override;
};
