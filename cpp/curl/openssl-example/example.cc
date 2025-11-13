#include <curl/curl.h>

// This callback function is called by libcurl as soon as there is data received
static size_t write_callback(void* contents, size_t size, size_t nmemb,
                             void* userp) {
  size_t total_size = size * nmemb;
  fwrite(contents, size, nmemb, stdout);
  return total_size;
}

int main(void) {
  CURL* curl;
  CURLcode res;

  // Initialize libcurl
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if (curl) {
    // Set the URL
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");

    // Set the write callback function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    // Optionally verify SSL certs (enabled here)
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

    // Perform the request
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK)
      fprintf(stderr, "\ncurl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    // Cleanup
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  return 0;
}
