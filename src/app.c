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
int makeCounterThread(pthread_t *tid, struct runCounter_args *args);
int checkThread(int ptresult, char prefix);

int main() {
  int ptresult = 0;
  pthread_t tid[2];

  struct runCounter_args args1 = {
    .prefix = 'a'
  , .val = 0
  };

  struct runCounter_args args2 = {
    .prefix = 'b'
  , .val = 1
  };

  ptresult = makeCounterThread(&tid[0], &args1);
  if (checkThread(ptresult, args1.prefix) != 0) {
    return 1;
  }

  ptresult = makeCounterThread(&tid[1], &args2);
  if (checkThread(ptresult, args2.prefix) != 0) {
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

int makeCounterThread(pthread_t *tid, struct runCounter_args *args) {
  return pthread_create(
    tid
  , NULL
  , ((void * (*)(void *))&runCounter)
  , args
  );
}

int checkThread(int ptresult, char prefix) {
  if (ptresult != 0) {
    printf("ERROR: failed to create a working thread '%c' [%s]\n", prefix, strerror(ptresult));
  }
  return ptresult;
}

