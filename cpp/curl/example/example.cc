#include <iostream>
#include <curl/curl.h>
#include <unordered_map>

static size_t write_callback(void* contents, size_t size, size_t nmemb,
                             std::string* output) {
  size_t total_size = size * nmemb;
  output->append((char*)contents, total_size);
  return total_size;
}

std::string http_get(CURL* curl, const std::string& url) {
  std::string response;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_POST, 0L);
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, nullptr);

  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    std::cerr << "http get request failed" << std::endl;
  }
  return response;
}

std::string http_post(
    CURL* curl, const std::string& url, const std::string& data,
    const std::unordered_map<std::string, std::string>& headers) {
  std::string response;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_POST, 1L);

  struct curl_slist* slist = nullptr;
  for (auto& [key, value] : headers) {
    std::string h = key + ": " + value;
    slist = curl_slist_append(slist, h.c_str());
  }
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    std::cerr << "http post request failed" << std::endl;
  }
  return response;
}

int main(void) {
  CURL* curl = curl_easy_init();
  if (!curl) {
    std::cerr << "fail to init curl" << std::endl;
    return 1;
  }

  std::string url = "https://jsonplaceholder.typicode.com/posts/1";
  std::string response = http_get(curl, url);
  std::cout << response << std::endl;

  std::string data = R"({"title": "foo", "body": "bar", "userId": 1})";
  std::unordered_map<std::string, std::string> headers = {
      {"Content-Type", "application/json"}};
  url = "https://jsonplaceholder.typicode.com/posts";
  response = http_post(curl, url, data, headers);
  std::cout << response << std::endl;

  curl_easy_cleanup(curl);
  return 0;
}
