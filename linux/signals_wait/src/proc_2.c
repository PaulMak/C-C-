#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char ** argv) {
  if(argc != 2)
    exit(1);
  pid_t process_id = atoi(argv[1]);
  kill (process_id, SIGUSR1);
  return 3;
}
