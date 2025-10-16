#include <boost/program_options.hpp>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  namespace po = boost::program_options;
  po::options_description desc("Allowed options");
  desc.add_options()("help,h", "Display this help message") // Flag for help
      ("input,i", po::value<std::string>(), "Input file")   // Input file
      ("output,o", po::value<std::string>(), "Output file") // Output file
      ("verbose,v", po::value<int>()->default_value(0),
       "Verbosity level (0 to 5)"); // Verbosity level with a default value
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm); // Parse arguments
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << std::endl; // Display help message
    return 0;
  }

  if (vm.count("input")) {
    std::cout << "Input file: " << vm["input"].as<std::string>() << std::endl;
  } else {
    std::cerr << "Input file is required!" << std::endl;
    return 1;
  }

  if (vm.count("output")) {
    std::cout << "Output file: " << vm["output"].as<std::string>() << std::endl;
  }

  int verbosity = vm["verbose"].as<int>();
  std::cout << "Verbosity level: " << verbosity << std::endl;
  return 0;
}
