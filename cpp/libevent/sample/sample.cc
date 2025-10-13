#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/keyvalq_struct.h>
#include <event2/util.h>
#include <json/json.h>
#include <signal.h>

#include <iostream>
#include <string>

void generic_request_handler(evhttp_request* req, void* arg);

void signal_cb(evutil_socket_t sig, short events, void* arg);

void post_request_handler(evhttp_request* req);

int main(void) {
  event_base* base = event_base_new();
  if (!base) {
    std::cerr << "fail to create event_base" << std::endl;
    return 1;
  }

  event* signal_event =
      event_new(base, SIGINT, EV_SIGNAL | EV_PERSIST, signal_cb, (void*)base);
  if (!signal_event) {
    std::cerr << "fail to create signal event" << std::endl;
    event_base_free(base);
    return 1;
  }

  if (event_add(signal_event, nullptr) < 0) {
    std::cerr << "fail to add signal event" << std::endl;
    event_free(signal_event);
    event_base_free(base);
    return 1;
  }

  evhttp* http = evhttp_new(base);
  if (!http) {
    std::cerr << "fail to create evhttp" << std::endl;
    return 1;
  }

  evhttp_set_gencb(http, generic_request_handler, nullptr);

  // Bind the HTTP server to an address and port
  unsigned short port = 10101;
  std::string http_addr = "0.0.0.0";
  evhttp_bound_socket* handle =
      evhttp_bind_socket_with_handle(http, http_addr.c_str(), port);
  if (!handle) {
    std::cerr << "fail to bind address: " << http_addr << ":" << port
              << std::endl;
    return 1;
  }

  std::cout << "Libevent HTTP server listening on http://" << http_addr << ":"
            << port << std::endl;
  std::cout << "Press Ctrl+C to stop.\n";

  // Start the event loop
  event_base_dispatch(base);

  evhttp_free(http);
  event_base_free(base);

  std::cout << "Server stopped." << std::endl;
  return 0;
}

void generic_request_handler(evhttp_request* req, void*) {
  const char* uri = evhttp_request_get_uri(req);
  std::cout << "Received request for URI:" << uri << std::endl;

  evhttp_cmd_type method = evhttp_request_get_command(req);

  std::string cmdtype;
  switch (method) {
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
  std::cout << "Request method: " << cmdtype << std::endl;

  if (method == EVHTTP_REQ_POST) {
    post_request_handler(req);
  }

  evbuffer* evb = evbuffer_new();
  if (!evb) {
    std::cerr << "Failed to create response buffer" << std::endl;
    evhttp_send_error(req, HTTP_INTERNAL, "Internal Server Error");
    return;
  }

  // set content
  evbuffer_add_printf(evb, "Hello from libevent HTTP server!\n");
  evbuffer_add_printf(evb, "You requested: %s\n", uri);
  evbuffer_add_printf(evb, "Method: %s\n", cmdtype.c_str());

  evhttp_add_header(evhttp_request_get_output_headers(req), "Content-Type",
                    "text/plain");

  evhttp_send_reply(req, HTTP_OK, "OK", evb);

  evbuffer_free(evb);
}

void signal_cb(evutil_socket_t sig, short, void* arg) {
  event_base* base = (event_base*)arg;
  if (base) {
    std::cout << "\nCaught signal " << sig << " stopping the event loop..."
              << std::endl;
    event_base_loopbreak(base);
  }
}

void post_request_handler(evhttp_request* req) {
  evbuffer* input_buffer = evhttp_request_get_input_buffer(req);
  size_t datasize = evbuffer_get_length(input_buffer);
  if (datasize > 0) {
    std::string content(datasize, '\0');
    evbuffer_copyout(input_buffer, &content[0], datasize);

    Json::Value value;
    Json::CharReaderBuilder reader_builder;
    std::unique_ptr<Json::CharReader> reader(reader_builder.newCharReader());
    JSONCPP_STRING err;
    if (!reader->parse(content.c_str(), content.c_str() + datasize, &value,
                       &err)) {
      std::cerr << "error: " << err << std::endl;
      return;
    }

    Json::StreamWriterBuilder writer_builder;
    std::string json = Json::writeString(writer_builder, value);
    std::cout << "JSON content: " << json << std::endl;
  } else {
    std::cout << "Received POST request with no body content." << std::endl;
  }
}
