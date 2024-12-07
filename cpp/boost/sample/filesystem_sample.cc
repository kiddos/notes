#include <boost/filesystem.hpp>
#include <iostream>

int main() {
  namespace fs = boost::filesystem;
  fs::path dir_path("_deps");
  fs::path file_path("CMakeCache.txt");  // Replace with an actual file path

  if (fs::exists(dir_path)) {
    std::cout << dir_path << " exists.\n";

    if (fs::is_directory(dir_path)) {
      std::cout << dir_path << " is a directory. Contents:\n";

      for (const auto& entry : fs::directory_iterator(dir_path)) {
        std::cout << " - " << entry.path().string() << '\n';
      }
    }
  } else {
    std::cout << dir_path << " does not exist.\n";
  }

  if (fs::exists(file_path)) {
    std::cout << file_path << " exists.\n";

    std::cout << "File size: " << fs::file_size(file_path) << " bytes\n";

    std::time_t t = fs::last_write_time(file_path);
    std::cout << "Last modified: " << std::asctime(std::localtime(&t));
  } else {
    std::cout << file_path << " does not exist.\n";
  }

  fs::path new_dir("test-folder");
  if (!fs::exists(new_dir)) {
    if (fs::create_directory(new_dir)) {
      std::cout << "Directory created: " << new_dir.string() << '\n';
    }
  }
  return 0;
}
