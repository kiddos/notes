#include "request.h"

#include <iostream>

static size_t write_callback(void* contents, size_t size, size_t nmemb,
                             std::string* output) {
  size_t totalSize = size * nmemb;
  output->append((char*)contents, totalSize);
  return totalSize;
}

Request::Request() : curl_(curl_easy_init()) {
  if (curl_) {
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response_);
  }
}

Request::~Request() {
  if (curl_) {
    curl_easy_cleanup(curl_);
  }
}

std::string Request::get(const std::string& url) {
  if (curl_) {
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_, CURLOPT_POST, 0L);
    curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, nullptr);

    auto res = curl_easy_perform(curl_);
    if (res == CURLE_OK) {
      return response_;
    }
    std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res)
              << std::endl;
  }
  return "";
}

std::string Request::post(
    const std::string& url, const std::string& data,
    const std::unordered_map<std::string, std::string>& headers) {
  if (curl_) {
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_, CURLOPT_POST, 1L);
    struct curl_slist* slist = nullptr;
    for (auto& [key, value] : headers) {
      std::string h = key + ": " + value;
      slist = curl_slist_append(slist, h.c_str());
    }
    curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, slist);
    curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, data.c_str());

    auto res = curl_easy_perform(curl_);
    if (res == CURLE_OK) {
      return response_;
    }
    std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res)
              << std::endl;
  }
  return "";
}
