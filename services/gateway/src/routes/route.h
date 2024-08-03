#include "server.h"

class GatewayServer final : public weblib::CrowServer {
public:
  explicit GatewayServer(uint16 port);

  void Start() override;
};
