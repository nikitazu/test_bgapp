#include <stdio.h>
#include <unistd.h>

int counter_val = 0;
int counter_max = 60;

int main() {
  while (counter_val < counter_max) {
    printf("c = %d\n", counter_val);
    fflush(stdout);
    counter_val += 1;
    sleep(1);
  }
  return 0;
}

