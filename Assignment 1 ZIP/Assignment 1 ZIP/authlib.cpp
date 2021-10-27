#include <iostream>
#include <string>

void authenticated(std::string u) {
  std::cout << "User " << u << " successfully authenticated." << std::endl;
}

void rejected(std::string u) {
  std::cout << "Failed to authenticate user " << u << std::endl;
}

