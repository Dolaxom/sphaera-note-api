#include "routes/route.h"
#include "dotenv.h"

#include <iostream>

int main() {
  std::error_code ec;
  weblib::EnvParser::Instance().Parse(".env", ec);
  if (ec) {
    std::exit(1);
  }
  auto test = weblib::EnvParser::Instance().Value("todo");
  std::cout << test << std::endl;

  GatewayServer server{8080};

  server.Start();
}
