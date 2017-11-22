#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem_;
int data;


void * fun(void * unused) {
  while(1) {
    sem_wait(&sem_);
    pthread_mutex_lock(&mutex);
    printf("Data received: %d\n", data);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

int main() {
  int i = 0;
  sem_init(&sem_,0,0);
  pthread_t thread;
  pthread_create(&thread, NULL, fun, NULL);
  while(1) {
    pthread_mutex_lock(&mutex);
    data = i++;
    sem_post(&sem_);
    pthread_mutex_unlock(&mutex);
    sleep(1);
  }
  return 0;
}

