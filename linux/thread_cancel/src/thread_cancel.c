#include <pthread.h>
#include <stdio.h>

void * fun_1(void * data) {
  pthread_t thread_id = *(pthread_t*) data;
  sleep(3);
  fputc('X',stderr);
  pthread_cancel(thread_id);
  fputc('X',stderr);
  return NULL;
}

void * fun_2(void * unused) {
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
  int i;
  for(i = 0; i < 10; ++i) {
    sleep(1);
    (i == 5) ? pthread_testcancel() : fputc('O',stderr);
  }
  return NULL;
}

int main() {
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
  pthread_t thread_1, thread_2;
  pthread_create(&thread_2,&attr, fun_2, NULL);
  fputc('U',stderr);
  pthread_create(&thread_1,&attr, fun_1, &thread_2);
  pthread_attr_destroy(&attr);
  sleep(15);
  printf("END\n");
  return 0;
}


