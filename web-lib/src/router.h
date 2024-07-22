#pragma once

#include <string>
#include <functional>
#include <vector>
#include <crow.h>
#include "request.h"

namespace weblib {

class Router
{
protected:
  using Handler = std::function<void(weblib::Request)>;

public:
  virtual void Get(std::string&& url, std::vector<Handler> handlers) = 0;
  virtual void Post(std::string&& url, std::vector<Handler> handlers) = 0;
  virtual void Delete(std::string&& url, std::vector<Handler> handlers) = 0;
  virtual void Put(std::string&& url, std::vector<Handler> handlers) = 0;
};

class RouterCrow : public Router {
public:
  RouterCrow(crow::SimpleApp& app);
  void Get(std::string&& url, std::vector<Handler> handlers) override;
  void Post(std::string&& url, std::vector<Handler> handlers) override;
  void Delete(std::string&& url, std::vector<Handler> handlers) override;
  void Put(std::string&& url, std::vector<Handler> handlers) override;

private:
  crow::SimpleApp& crow_core_;
};

} // namespace weblib