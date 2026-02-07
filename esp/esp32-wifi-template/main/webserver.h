#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "esp_http_server.h"

httpd_handle_t webserver_start(void);

void webserver_handle_disconnect(void);

httpd_handle_t* webserver_get(void);

#endif /* end of include guard: WEBSERVER_H */
