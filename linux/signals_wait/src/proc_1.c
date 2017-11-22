#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handler(int sig_num) {
  printf("User input received\n");
  exit(0);
}

int main() {
  struct sigaction sa;
  memset(&sa, 0, sizeof (sa));
  sa.sa_handler = &handler;
  sigaction(SIGUSR1, &sa, NULL);
  while (1) sleep(100);
  return 0;
}

