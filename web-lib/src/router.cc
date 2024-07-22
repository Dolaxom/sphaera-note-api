#include "router.h"

namespace weblib {

RouterCrow::RouterCrow(crow::SimpleApp& app) : crow_core_{app} {

}

void RouterCrow::Get(std::string&& url, std::vector<Handler> handlers) {
  crow_core_.route_dynamic(std::move(url)).methods(crow::HTTPMethod::GET)([](const crow::request& crow_req){

    return crow::response("Get");

  });
}

void RouterCrow::Post(std::string&& url, std::vector<Handler> handlers) {
  crow_core_.route_dynamic(std::move(url)).methods(crow::HTTPMethod::POST)([](const crow::request& crow_req){

    return crow::response("Post");

  });
}

void RouterCrow::Delete(std::string&& url, std::vector<Handler> handlers) {
  crow_core_.route_dynamic(std::move(url)).methods(crow::HTTPMethod::DELETE)([](const crow::request& crow_req){

    return crow::response("Delete");

  });
}

void RouterCrow::Put(std::string&& url, std::vector<Handler> handlers) {
  crow_core_.route_dynamic(std::move(url)).methods(crow::HTTPMethod::PUT)([](const crow::request& crow_req){

    return crow::response("Put");

  });
}

} // namespace weblib
