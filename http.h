
#ifndef _HTTP_H
#define _HTTP_H

#include "strings.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SEND_404                                                               \
  send(conn, H_HTTP_404, strlen(H_HTTP_404), 0);                               \
  send(conn, M_HTTP_404, strlen(M_HTTP_404), 0)
#define SEND_400                                                               \
  send(conn, H_HTTP_400, strlen(H_HTTP_400), 0);                               \
  send(conn, M_HTTP_400, strlen(M_HTTP_400), 0)
#define SEND_500                                                               \
  send(conn, H_HTTP_500, strlen(H_HTTP_500), 0);                               \
  send(conn, M_HTTP_500, strlen(M_HTTP_500), 0)

typedef struct Server {
  int socket;
  int port;
} Server;

void init_server(Server *server, int port);

#endif // !_HTTP_H
