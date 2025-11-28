#include <archive.h>
#include <archive_entry.h>

#include <iostream>
#include <string>

// Create a tar.gz containing one text file
bool create_archive(const std::string& archive_name,
                    const std::string& file_name,
                    const std::string& text_content) {
  struct archive* a;
  struct archive_entry* entry;
  int r;

  a = archive_write_new();
  archive_write_add_filter_gzip(a);            // Add gzip compression
  archive_write_set_format_pax_restricted(a);  // Set tar format
  archive_write_open_filename(a, archive_name.c_str());

  entry = archive_entry_new();
  archive_entry_set_pathname(entry, file_name.c_str());
  archive_entry_set_size(entry, text_content.size());
  archive_entry_set_filetype(entry, AE_IFREG);
  archive_entry_set_perm(entry, 0644);
  archive_write_header(a, entry);

  // Write the file content into the archive
  r = archive_write_data(a, text_content.data(), text_content.size());
  if (r < 0) {
    std::cerr << "Write failed: " << archive_error_string(a) << std::endl;
    return false;
  }

  archive_entry_free(entry);
  archive_write_close(a);
  archive_write_free(a);

  return true;
}

bool read_archive(const std::string& archive_name) {
  struct archive* a;
  struct archive_entry* entry;
  int r;

  a = archive_read_new();
  archive_read_support_format_all(a);
  archive_read_support_filter_all(a);

  if ((r = archive_read_open_filename(a, archive_name.c_str(), 10240))) {
    std::cerr << "Failed to open archive: " << archive_error_string(a)
              << std::endl;
    return false;
  }

  while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
    std::string filename = archive_entry_pathname(entry);
    std::cout << "Reading file: " << filename << std::endl;

    const void* buff;
    size_t size;
    la_int64_t offset;
    std::string content;

    while (true) {
      r = archive_read_data_block(a, &buff, &size, &offset);
      if (r == ARCHIVE_EOF) break;
      if (r < ARCHIVE_OK) {
        std::cerr << "Error reading block: " << archive_error_string(a)
                  << std::endl;
        return false;
      }
      content.append((const char*)buff, size);
    }

    std::cout << "File content:\n" << content << std::endl;
  }

  archive_read_close(a);
  archive_read_free(a);

  return true;
}

int main() {
  const std::string archive_name = "sample.tar.gz";
  const std::string file_name = "hello.txt";
  const std::string text = "Hello, libarchive!\nThis is a test file.";

  if (!create_archive(archive_name, file_name, text)) {
    std::cerr << "Failed to create archive" << std::endl;
    return 1;
  }

  if (!read_archive(archive_name)) {
    std::cerr << "Failed to read archive" << std::endl;
    return 1;
  }
  return 0;
}
