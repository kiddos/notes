#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

int main() {
  // This is the V4 UUID generator.
  boost::uuids::random_generator generator;

  boost::uuids::uuid uuid = generator();

  std::cout << "Generated UUID: " << uuid << std::endl;

  std::cout << "UUID Version: " << uuid.version() << " (4 is random)"
            << std::endl;
  std::cout << "UUID Variant: " << uuid.variant() << " (2 is RFC 4122)"
            << std::endl;

  return 0;
}
