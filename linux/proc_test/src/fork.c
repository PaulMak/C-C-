#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  pid_t child_pid;

  printf("The main program process ID: %d\n", (int) getpid());
  child_pid = fork();
  if (child_pid != 0) {
    printf("this is the parent process, ID %d\n"
        "the child's proccess ID %d\n", (int) getpid(), (int) child_pid);
  } else {
    printf("This is the child process, ID %d\n", (int) getpid());
  }
return 0;
}
