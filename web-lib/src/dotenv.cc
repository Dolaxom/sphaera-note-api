#include "dotenv.h"

#include <fstream>

namespace weblib {

EnvParser &EnvParser::Instance() {
  static EnvParser parser;
  return parser;
}

void EnvParser::Parse(const std::filesystem::path& path, std::error_code& ec) {
  std::ifstream file{path};

  if (!file.is_open()) {
    ec = std::error_code(Errors::failed_open_file, std::generic_category());
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::string key, value;
    bool separator = false;
    for (char ch : line) {
      if (ch == '#') [[unlikely]] {
        break;
      } else if (!separator && ch == '=') {
        separator = true;
        continue;
      } else if (std::isspace(ch)) {
        continue;
      }

      if (!separator) {
        key.push_back(ch);
        continue;
      }
      value.push_back(ch);
    }

    if (!value.empty()) {
      storage_[key] = value;
    }
  }
}

std::string_view EnvParser::Value(const std::string& key) {
  std::string key_uppercase = key;
  for (char& ch : key_uppercase) {
    ch = std::toupper(ch);
  }

  if (auto it = storage_.find(key_uppercase); it != storage_.end()) {
    return it->second;
  }

  return "";
}

} // weblib
