#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int spawn (char * prog, char ** arg_list) {
  pid_t child_id;
  child_id = fork();
  if (child_id !=0 ) {
    printf("this is the parent process\n");
  } else {
    execvp(prog, arg_list);
    fprintf(stderr, "error during executing the program");
    abort();
  }
  return 0;
}

int main() {
  char * arg_list[] = {
    "ls", "-l", "/", NULL};
  spawn("ls", arg_list);
  return 0;
}


