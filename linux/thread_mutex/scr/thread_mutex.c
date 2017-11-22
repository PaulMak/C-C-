#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * fun(void * data) {
  char ch = *(char*) data;
  while(1) {
    pthread_mutex_lock(&mutex);
    fputc(ch,stderr);
    pthread_mutex_unlock(&mutex);
    sleep(1);
  }
  return NULL;
}

int main() {
  pthread_t thread_1, thread_2;
  char ch1 = 'X';
  char ch2 = 'O';
  pthread_create(&thread_1, NULL, fun, &ch1);
  pthread_create(&thread_2, NULL, fun, &ch2);
  while(1);
  return 0;
}
