#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/keyvalq_struct.h>
#include <event2/util.h>

#include <iostream>
#include <string>

void generic_request_handler(evhttp_request* req, void* arg);

int main(void) {
  event_base* base = event_base_new();
  if (!base) {
    std::cerr << "fail to create event_base" << std::endl;
    return 1;
  }

  evhttp* http = evhttp_new(base);
  if (!http) {
    std::cerr << "fail to create evhttp" << std::endl;
    return 1;
  }

  evhttp_set_gencb(http, generic_request_handler, nullptr);

  // Bind the HTTP server to an address and port
  unsigned short port = 9100;
  std::string http_addr = "0.0.0.0";
  evhttp_bound_socket* handle =
      evhttp_bind_socket_with_handle(http, http_addr.c_str(), port);
  if (!handle) {
    std::cerr << "fail to bind address: " << http_addr << ":" << port
              << std::endl;
    return 1;
  }

  printf("Libevent HTTP server listening on http://%s:%d\n", http_addr.c_str(),
         port);
  printf("Press Ctrl+C to stop.\n");

  // Start the event loop (this will block until event_base_dispatch() is
  // interrupted)
  event_base_dispatch(base);

  // Cleanup resources
  evhttp_free(http);
  event_base_free(base);

  printf("Server stopped.\n");
  return 0;
}

void generic_request_handler(evhttp_request* req, void* arg) {
  // Get the URI from the request
  const char* uri = evhttp_request_get_uri(req);
  printf("Received request for URI: %s\n", uri);

  // Get the request method (e.g., GET, POST)
  const char* cmdtype;
  switch (evhttp_request_get_command(req)) {
    case EVHTTP_REQ_GET:
      cmdtype = "GET";
      break;
    case EVHTTP_REQ_POST:
      cmdtype = "POST";
      break;
    case EVHTTP_REQ_HEAD:
      cmdtype = "HEAD";
      break;
    case EVHTTP_REQ_PUT:
      cmdtype = "PUT";
      break;
    case EVHTTP_REQ_DELETE:
      cmdtype = "DELETE";
      break;
    case EVHTTP_REQ_OPTIONS:
      cmdtype = "OPTIONS";
      break;
    case EVHTTP_REQ_TRACE:
      cmdtype = "TRACE";
      break;
    case EVHTTP_REQ_CONNECT:
      cmdtype = "CONNECT";
      break;
    case EVHTTP_REQ_PATCH:
      cmdtype = "PATCH";
      break;
    default:
      cmdtype = "UNKNOWN";
      break;
  }
  printf("Request method: %s\n", cmdtype);

  // Create a buffer for the response body
  evbuffer* evb = evbuffer_new();
  if (!evb) {
    fprintf(stderr, "Failed to create response buffer\n");
    evhttp_send_error(req, HTTP_INTERNAL, "Internal Server Error");
    return;
  }

  // Add content to the response buffer
  evbuffer_add_printf(evb, "Hello from libevent HTTP server!\n");
  evbuffer_add_printf(evb, "You requested: %s\n", uri);
  evbuffer_add_printf(evb, "Method: %s\n", cmdtype);

  // Set the Content-Type header
  evhttp_add_header(evhttp_request_get_output_headers(req), "Content-Type",
                    "text/plain");

  // Send the response with a 200 OK status
  evhttp_send_reply(req, HTTP_OK, "OK", evb);

  // Free the response buffer
  evbuffer_free(evb);
}
