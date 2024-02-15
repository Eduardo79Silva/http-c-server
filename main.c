#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "http.h"
// #include "Routes.h"
// #include "Response.h"

int main() {
  // initiate HTTP_Server
  Server http_server;
  init_server(&http_server, 8080);

  int client_socket;

  while (1) {
    char client_msg[4096] = "";

    client_socket = accept(http_server.socket, NULL, NULL);

    read(client_socket, client_msg, 4095);
    printf("%s\n", client_msg);
    FILE *html_data;
    html_data = fopen("index.html", "r");

    char response_data[1024];
    fgets(response_data, 1024, html_data);

    char http_header[4096] = "HTTP/1.1 200 OK\r\n\r\n";

    strcat(http_header, response_data);
    strcat(http_header, "\r\n\r\n");

    send(client_socket, http_header, sizeof(http_header), 0);
    close(client_socket);
  }
  return 0;
}
