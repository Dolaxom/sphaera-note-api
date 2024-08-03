/**
 * @file dotenv.h
 * @brief .env file singleton parser.
 *
 * Парсит .env файл в мапу.
 */

#pragma once

#include <unordered_map>
#include <system_error>
#include <string_view>
#include <filesystem>

namespace weblib {

class EnvParser {
public:
  static EnvParser& Instance();

  void Parse(const std::filesystem::path& path, std::error_code& ec);
  std::string_view Value(const std::string& key);

private:
  EnvParser() = default;
  std::unordered_map<std::string, std::string> storage_;
};

enum Errors {
  failed_open_file = 1
};

} // namespace weblib
