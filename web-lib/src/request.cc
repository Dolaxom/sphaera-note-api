#include "request.h"

namespace weblib {

void Request::SetMethod(HttpMethod method) {
  method_ = method;
}

void Request::SetUrl(const std::string& url) {
  url_ = url;
}

void Request::SetRawUrl(const std::string& url) {
  raw_url_ = url;
}

void Request::SetBody(const std::string& body) {
  body_ = body;
}

void Request::AddHeader(std::string key, std::string value) {
  headers_[key] = value;
}

HttpMethod Request::GetMethod() const {
  return method_;
}

std::string Request::GetUrl() const {
  return url_;
}

std::string Request::GetRawUrl() const {
  return raw_url_;
}

std::string Request::GetBody() const {
  return body_;
}

std::pair<std::string, bool> Request::GetHeader(const std::string& key) const {
  auto it = headers_.find(key);
  if (it == headers_.end()) {
    return {{}, false};
  }

  return {it->second, true};
}

std::unordered_map<std::string, std::string> Request::GetHeaders() const {
  return headers_;
}

[[maybe_unused]] Request CreateFromCrow(const crow::request& crow_req) {
  Request req;
  HttpMethod method;

  static std::unordered_map<crow::HTTPMethod, weblib::HttpMethod> relations {
    {crow::HTTPMethod::GET, weblib::HttpMethod::GET},
    {crow::HTTPMethod::POST, weblib::HttpMethod::POST},
    {crow::HTTPMethod::DELETE, weblib::HttpMethod::DELETE},
    {crow::HTTPMethod::PUT, weblib::HttpMethod::PUT}
  };

  req.SetMethod(relations.at(crow_req.method));
  req.SetRawUrl(crow_req.raw_url);
  req.SetUrl(crow_req.url);
  req.SetBody(crow_req.body);
  for (const auto& header : crow_req.headers) {
    req.AddHeader(header.first, header.second);
  }

  return req;
}

} // namespace weblib 
