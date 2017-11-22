#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "header.h"

int main() {
  int var = NUMBER;
  void * handle = dlopen("libtest.so",RTLD_LAZY);
  int (*fun3)() = dlsym(handle, "fun4"); 
  int (*fun4)() = dlsym(handle, "fun3"); 
  printf("Output is %d\n", var);
  printf("Fun1: %d\n", fun1());
  printf("Fun3: %d\n", fun3());
  printf("Fun4: %d\n", fun4());
  printf("Fun2: %d\n", fun2());
  dlclose(handle);
  return 0;
}
