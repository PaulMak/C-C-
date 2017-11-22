#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

int main(int argc, char ** argv) {
  if(argc != 2)
    exit(1);
  bool menu = true;
  bool process_killed = false;
  pid_t process_id = (pid_t) atoi(argv[1]);
  while (menu) {
    char input, ignore;
    printf("a -SIGUSR1\n"
        "b - SIGTERM\n"
        "c - exit\n\n");
    scanf("%c", &input);
    switch(input) {
      case 'a' :
        kill(process_id, SIGUSR1);
        break;
      case 'b' :
		if(!process_killed) {
			process_killed = true;
			kill(process_id,SIGTERM);
		}
        break;
      case 'c' :
        menu = false;
        if(!process_killed) {
			process_killed = true;
			kill(process_id,SIGTERM);
		}
        break;
      default:
        printf("try again!\n");
    }
    scanf("%c", &ignore);
  }
  printf("Goodbye!\n");
  return 0;
}


