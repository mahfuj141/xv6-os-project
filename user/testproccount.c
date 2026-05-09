#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  int before, after;
  int pid;

  printf("=== getproccount System Call Test ===\n");

  before = getproccount();
  printf("Active processes before fork: %d\n", before);

  pid = fork();
  if(pid == 0) {
    printf("Inside child — active processes: %d\n", getproccount());
    exit(0);
  }

  wait(0);

  after = getproccount();
  printf("Active processes after child exits: %d\n", after);
  printf("Back to baseline: %s\n", (after == before) ? "YES" : "NO");

  exit(0);
}
