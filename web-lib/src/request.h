/**
 * @file request.h
 * @brief Custom request type.
 *
 * Структура данных для хранения и обработки запросов от клиентов.
 */

#pragma once

#include <string>
#include <unordered_map>
#include <crow.h>

namespace weblib {

enum class HttpMethod {
  GET = 0,
  POST,
  DELETE,
  PUT
};

class Request {
public:
  using string = std::string;

  void SetMethod(HttpMethod method);
  void SetUrl(const string& url);
  void SetRawUrl(const string& url);
  void SetBody(const string& body);
  void AddHeader(string key, string value);

  HttpMethod GetMethod() const;
  string GetUrl() const;
  string GetRawUrl() const;
  string GetBody() const;
  std::pair<string, bool> GetHeader(const string& key) const;
  std::unordered_map<string, string> GetHeaders() const;

private:
  HttpMethod method_;
  string raw_url_; 
  string url_; // without ?query_params
  std::unordered_map<string, string> headers_;
  string body_;

  string remote_ip_address_; // TODO
};

[[maybe_unused]] Request CreateFromCrow(const crow::request& crow_req);

} // namespace weblib
