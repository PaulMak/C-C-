#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int child_status;

int main(int argc, char ** argv) {
  if(argc != 2)
    exit(1);
  char * input[3];
  input[0] = "./proc_2";
  input[1] = argv[1];
  input[2] = NULL;
  pid_t child_process = fork();
  if(child_process > 0) {
    printf("This is parent process\n");
  } else {
    execvp("./proc_2", input);
  }
  printf("After creating process\n");
  wait (&child_status);
  if (WIFEXITED(child_status)) 
    printf("Exit code of child status: %d\n", WEXITSTATUS(child_status));
  else
    printf("Child process ended abnormally\n");
  return 0;
}
