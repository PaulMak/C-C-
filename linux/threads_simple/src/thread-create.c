#include <pthread.h>
#include <stdio.h>

#define N 3

typedef struct data_st {
  char ch;
  int cnt;
} data;

void * thread_fun(void * var) {
  data * _data = (data *) var;
  int result = _data->cnt;
  int i;
  for (i=0; i < _data->cnt; ++i)
    fputc(_data->ch,stderr);
  return (void*) result;
}

void * thread_fun2(void * unused) {
  fputc('M',stderr);
  return NULL;
}

int main() {
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
  pthread_t thread_another;
  pthread_create(&thread_another, &attr, thread_fun2, NULL);
  pthread_attr_destroy(&attr);
  int res[N];
  pthread_t thread_id[N];
  data data_thread[] ={ {'I',100}, {'O', 10}, {'G', 20} };
  int i;
  for(i = 0; i < N; ++i) {
    pthread_create(&thread_id[i], NULL, thread_fun, &data_thread[i]);
  }
  fputc('\n',stderr);
  for(i = 0; i < N; ++i) {
    pthread_join(thread_id[i], (void*) &res[i]);
  }
  for(i = 0; i < N; ++i) {
    printf("\n%d %d\n", i, res[i]);
  }
  return 0;
}
