#include <CLI/CLI.hpp>
#include <string>

int main(int argc, char* argv[]) {
  CLI::App app{"App description"};
  argv = app.ensure_utf8(argv);

  std::string filename = "default";
  app.add_option("-f,--file", filename, "A help string");
  CLI11_PARSE(app, argc, argv);

  std::cout << "filename=" << filename << std::endl;
  return 0;
}
