#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "../include/http.h"
#include "../include/routes.h"
// #include "Response.h"

int main() {
  // initiate HTTP_Server
  Server http_server;
  init_server(&http_server, 8080);

  struct Route *route = init_route("/", "index.html");
  add_route(route, "/about", "about.html");

  inorder(route);

  int client_socket;

  while (1) {
    char client_msg[4096] = "";

    client_socket = accept(http_server.socket, NULL, NULL);

    read(client_socket, client_msg, 4095);
    printf("%s\n", client_msg);

    char *method = "";
    char *url_route = "";

    char *client_http_header = strtok(client_msg, "\n");

    printf("\n\n%s\n\n", client_http_header);

    char *header_token = strtok(client_http_header, " ");

    int header_parse_counter = 0;

    while (header_token != NULL) {

      switch (header_parse_counter) {
      case 0:
        method = header_token;
      case 1:
        url_route = header_token;
      }
      header_token = strtok(NULL, " ");
      header_parse_counter++;
    }

    printf("The method is %s\n", method);
    printf("The route is %s\n", url_route);

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
