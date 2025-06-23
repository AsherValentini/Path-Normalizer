#pragma once

#include <vector>
#include <string>
#include <sstream>

class PathNormalizer {

public:
  std::vector<std::string> normalizePaths(const std::vector<std::string>& paths) {
    std::vector<std::string> normalizedPaths;
    for (const auto& s : paths) {
      normalizedPaths.push_back(normalizePath(s, '/'));
    }

    return normalizedPaths;
  }

private:
  std::string normalizePath(const std::string& path, char deliminator) {

    std::istringstream ss(path);
    std::string token;

    std::vector<std::string> normalizedTokens;

    while (getline(ss, token, deliminator)) {

      if (token.empty() || token == ".")
        continue;
      if (!token.empty() && token == "..") {
        normalizedTokens.pop_back();
      } else {
        normalizedTokens.push_back(token);
      }
    }

    return joinTokens(normalizedTokens, '/');
  }

  std::string joinTokens(const std::vector<std::string> tokens, char deliminator) {

    std::ostringstream oss;

    for (int i = 0; i < tokens.size(); ++i) {
      oss << tokens[i];
      if (i + 1 < tokens.size()) {
        oss << deliminator;
      }
    }
    return oss.str();
  }
};