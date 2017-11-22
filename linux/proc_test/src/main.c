#include <stdio.h>
#include <unistd.h>

int main() {
  int res = system("ls -l /");
  printf("PID: %d\n", (int) getpid());
  printf("PPID: %d\n", (int) getppid());
  return res;
}
