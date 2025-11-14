#include <zip.h>

#include <cstring>
#include <iostream>
#include <vector>

int main() {
  int errorp;

  // Create a new zip archive
  zip_t* archive = zip_open("example.zip", ZIP_CREATE | ZIP_TRUNCATE, &errorp);
  if (!archive) {
    std::cerr << "Failed to create archive, error code: " << errorp
              << std::endl;
    return 1;
  }

  // Data to write into the archive
  const char* filename = "hello.txt";
  const char* content = "Hello from libzip!\n";

  // Add a file into the zip
  zip_source_t* source =
      zip_source_buffer(archive, content, strlen(content), 0);
  if (source == nullptr) {
    std::cerr << "Failed to create source buffer: " << zip_strerror(archive)
              << std::endl;
    zip_close(archive);
    return 1;
  }

  if (zip_file_add(archive, filename, source, ZIP_FL_OVERWRITE) < 0) {
    std::cerr << "Failed to add file: " << zip_strerror(archive) << std::endl;
    zip_source_free(source);
    zip_close(archive);
    return 1;
  }

  // Close the archive (writes to disk)
  if (zip_close(archive) != 0) {
    std::cerr << "Failed to close archive" << std::endl;
    return 1;
  }
  std::cout << "Created example.zip with hello.txt inside.\n";

  // Open the archive for reading
  archive = zip_open("example.zip", 0, &errorp);
  if (!archive) {
    std::cerr << "Failed to open archive for reading\n";
    return 1;
  }

  struct zip_stat st;
  zip_stat_init(&st);
  if (zip_stat(archive, filename, 0, &st) == 0) {
    zip_file_t* zf = zip_fopen(archive, filename, 0);
    if (zf) {
      std::vector<char> buffer(st.size);
      zip_fread(zf, buffer.data(), buffer.size());
      zip_fclose(zf);

      std::cout << filename
                << " contents: " << std::string(buffer.begin(), buffer.end());
    } else {
      std::cerr << "Could not open file inside zip\n";
    }
  } else {
    std::cerr << "Could not stat file inside zip\n";
  }

  zip_close(archive);
  return 0;
}
