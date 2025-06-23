#include <iostream>
#include <memory>
#include "path_normalizer.hpp"

int main() {

  auto norm = std::make_unique<PathNormalizer>();

  std::vector<std::string> paths{"/usr/bin/../bin/./scripts/../",
                                 "/home/./user/../user2/docs/../pics/"};

  auto normalizedPath = norm->normalizePaths(paths);

  for (auto& path : normalizedPath) {
    std::cout << path << std::endl;
  }
  return 0;
}

