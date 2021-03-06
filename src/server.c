#include <server.h>

server screate(int port) {
  server s = {0};
  int opt = 1;

  struct sockaddr_in addr = {.sin_family = AF_INET,
                             .sin_addr.s_addr = htonl(INADDR_ANY),
                             .sin_port = htons(port)};

  /* Creating a socket for ipv4 */
  if ((s.sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    logerror("Socket creation failed with error:\n\t %s", strerror(errno));

    exit(EXIT_FAILURE);
  }

  /* Setting socket options */
  if (setsockopt(s.sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
                 sizeof(int)) == -1) {
    logerror("Cannot set socket options:\n\t REUSEADDR:%s", strerror(errno));

    exit(EXIT_FAILURE);
  }

  socklen_t socklen = sizeof(addr);

  /* Binding socket to address */
  if (bind(s.sockfd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
    logerror("Cannot bind socket to address:\n\t %s", strerror(errno));

    exit(EXIT_FAILURE);
  }

  /* Listening to port */
  if (listen(s.sockfd, 5) != 0) {
    logerror("Cannot listen on port:\n\t %s", strerror(errno));

    exit(EXIT_FAILURE);
  }

  /* Server Information */
  char *servername = "\n"
                     "      ___________ __________ _    ________   \n"
                     "     / ____/ ___// ____/ __ \\ |  / / ____/   \n"
                     "    / /    \\__ \\/ __/ / /_/ / | / / __/      \n"
                     "   / /___ ___/ / /___/ _, _/| |/ / /___      \n"
                     "   \\____//____/_____/_/ |_| |___/_____/      \n"
                     "\n";

  fprintf(stdout, "\n%s\n", servername);
  loginfo("Server listening on port: %d", port);

  return s;
}

int saccept(server s) {
  struct sockaddr_in addr = {0};
  socklen_t socklen = sizeof(addr);

  return accept(s.sockfd, (struct sockaddr *)&addr, &socklen);
}

void sclose(server s) { close(s.sockfd); }
