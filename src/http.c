#include "http.h"

const char *H_HTTP_404 = "HTTP/1.0 404 Not Found\r\n\r\n";
const char *M_HTTP_404 = "<h1>404 Not Found</h1>";

const char *H_HTTP_400 = "HTTP/1.0 400 Bad Request\r\n\r\n";
const char *M_HTTP_400 = "<h1>400 Bad Request</h1>";

const char *H_HTTP_500 = "HTTP/1.0 500 Internal Server Error\r\n\r\n";
const char *M_HTTP_500 = "<h1>500 Internal Server Error</h1>";

const char *inital_line = "HTTP/1.0 200 OK \r\n\r\n";
const char *response = "<h1>Hello World!</h1>";

void init_server(Server *server, int port) {
  uint32_t bind_addr = INADDR_LOOPBACK;

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  server_address.sin_addr.s_addr = htonl(bind_addr);

  struct sockaddr *bindptr = (struct sockaddr *)&server_address;

  if (bind(server_fd, bindptr, sizeof(server_address)) < 0 ||
      listen(server_fd, 10) < 0) {
    abort();
  }
  server->port = port;
  server->socket = server_fd;
}
