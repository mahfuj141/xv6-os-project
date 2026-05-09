#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  int pid1, pid2, pid3;

  printf("=== Priority Scheduler Test ===\n");

  pid1 = fork();
  if(pid1 == 0) {
    setpriority(15);
    printf("Child 1 (priority=15, LOW): running\n");
    exit(0);
  }

  pid2 = fork();
  if(pid2 == 0) {
    setpriority(2);
    printf("Child 2 (priority=2, HIGH): running\n");
    exit(0);
  }

  pid3 = fork();
  if(pid3 == 0) {
    setpriority(8);
    printf("Child 3 (priority=8, MED): running\n");
    exit(0);
  }

  wait(0); wait(0); wait(0);
  printf("Expected order: Child 2 -> Child 3 -> Child 1\n");
  printf("Priority test complete.\n");
  exit(0);
}
