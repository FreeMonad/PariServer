#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCK_PATH "pari_socket"

int main(void)
{
  int s, t, len;
  struct sockaddr_un remote;
  char str[1024];

  if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  printf("Trying to connect...\n");

  remote.sun_family = AF_UNIX;
  strcpy(remote.sun_path, SOCK_PATH);
  len = strlen(remote.sun_path) + sizeof(remote.sun_family);
  if (connect(s, (struct sockaddr *)&remote, len) == -1) {
    perror("connect");
    exit(1);
  }

  printf("Connected.\n");

  while(printf("(gp)> "), fgets(str, sizeof(str), stdin), !feof(stdin)) {
    if (send(s, str, 1024, 0) == -1) {
      perror("send");
      exit(1);
    }

    if ((t=recv(s, str, sizeof(str), 0)) > 0) {
      str[t] = '\0';
      printf("? %s\n",str);
    } else {
      if (t < 0) perror("recv");
      else printf("Server closed connection\n");
      exit(1);
    }
  }

  close(s);

  return 0;
}
