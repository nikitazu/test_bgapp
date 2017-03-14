#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int counter_max = 60;

struct runCounter_args {
  char prefix;
  int val;
};

void runCounter(struct runCounter_args *args);

int main() {
  pthread_t tid[2];
  struct runCounter_args args1 = {
    .prefix = 'a'
  , .val = 0
  };

  struct runCounter_args args2 = {
    .prefix = 'b'
  , .val = 1
  };

  int ptresult = pthread_create(&tid[0], NULL, ((void * (*)(void *))&runCounter), &args1);
  if (ptresult != 0) {
    printf("ERROR: failed to create a working thread 'a' [%s]\n", strerror(ptresult));
    return 1;
  }

  ptresult = pthread_create(&tid[1], NULL, ((void * (*)(void *))&runCounter), &args2);
  if (ptresult != 0) {
    printf("ERROR: failed to create a working thread 'b' [%s]\n", strerror(ptresult));
    return 1;
  }

  sleep(61);
  return 0;
}


void runCounter(struct runCounter_args *args) {
  while (args->val < counter_max) {
    printf("%c: c = %d\n", args->prefix, args->val);
    fflush(stdout);
    args->val += 1;
    sleep(1);
  }
}

