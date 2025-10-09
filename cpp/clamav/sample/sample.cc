#include <clamav.h>

#include <CLI/CLI.hpp>
#include <cstdlib>
#include <iostream>

class ClamAV {
 public:
  ClamAV(const std::string& dbdir) { init(dbdir); }

  ~ClamAV() {
    if (engine_) {
      cl_engine_free(engine_);
    }
  }

  bool init(const std::string& dbdir) {
    cl_error_t ret = CL_SUCCESS;
    if ((ret = cl_init(CL_INIT_DEFAULT)) != CL_SUCCESS) {
      std::cerr << "cl_init() failed: " << cl_strerror(ret) << std::endl;
      return false;
    }

    engine_ = cl_engine_new();
    if (!engine_) {
      std::cerr << "Failed to create engine" << std::endl;
      return false;
    }

    unsigned int sigs = 0;
    ret = cl_load(dbdir.c_str(), engine_, &sigs, CL_DB_STDOPT);
    if (ret != CL_SUCCESS) {
      std::cerr << "cl_load() failed: " << cl_strerror(ret) << std::endl;
      cl_engine_free(engine_);
      return false;
    }
    std::cout << "Loaded " << sigs << " signatures." << std::endl;

    ret = cl_engine_compile(engine_);
    if (ret != CL_SUCCESS) {
      std::cerr << "cl_engine_compile() failed " << cl_strerror(ret)
                << std::endl;
      cl_engine_free(engine_);
      return false;
    }

    return true;
  }

  void Scan(const std::string& path) {
    const char* virname;
    cl_scan_options options;
    options.general = CL_SCAN_GENERAL_ALLMATCHES;
    options.parse = ~0;  // enable all parse
    options.heuristic = CL_SCAN_GENERAL_HEURISTIC_PRECEDENCE;
    options.mail = 0;
    options.dev = 0;
    auto ret = cl_scanfile(path.c_str(), &virname, NULL, engine_, &options);

    if (ret == CL_VIRUS) {
      std::cout << "Virus detected: " << virname << std::endl;
    } else if (ret == CL_CLEAN) {
      std::cout << "File is clean." << std::endl;
    } else {
      std::cout << "Error scanning file: " << cl_strerror(ret) << std::endl;
    }
  }

 private:
  cl_engine* engine_;
};

int main(int argc, char* argv[]) {
  CLI::App app{"clamav sample scanner"};
  argv = app.ensure_utf8(argv);

  std::string db = "./share/clamav";
  std::string certs_dir = "./etc/certs";
  std::string file;
  app.add_option("--db", db, "signature database");
  app.add_option("--certs_dir", certs_dir, "certs dir");
  app.add_option("--file", file, "file to scan");
  CLI11_PARSE(app, argc, argv);

  std::string env = "CVD_CERTS_DIR=" + certs_dir;
  putenv(const_cast<char*>(env.c_str()));
  ClamAV clam(db);

  clam.Scan(file);

  return 0;
}
