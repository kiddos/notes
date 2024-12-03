#ifndef REQUEST_H
#define REQUEST_H

#include <curl/curl.h>
#include <string>
#include <unordered_map>

class Request {
 public:
  Request();
  ~Request();

  std::string get(const std::string& url);
  std::string post(const std::string& url,
                   const std::string& data,
                   const std::unordered_map<std::string, std::string>& headers);

 private:
  CURL* curl_;
  std::string response_;
};


#endif /* end of include guard: REQUEST_H */
