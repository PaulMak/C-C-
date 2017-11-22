#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t cnt = 0;

void handler (int signal_number) {
  ++cnt;
  printf("SIGUSR1 was raised %d times\n",cnt);
}

int main() {
  struct sigaction sa;
  memset(&sa, 0, sizeof (sa));
  sa.sa_handler = &handler;
  sigaction(SIGUSR1, &sa, NULL);
  while(1) {
    sleep(100);
  }
  return 0;
}
