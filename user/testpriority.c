#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  printf("=== Priority Scheduler Test ===\n");

  int pid1 = fork();
  if(pid1 == 0){
    setpriority(15);
    volatile int i; for(i=0;i<50000000;i++); // busy wait
    printf("Child 1 (priority=15, LOW): running\n");
    exit(0);
  }

  int pid2 = fork();
  if(pid2 == 0){
    setpriority(2);
    volatile int i; for(i=0;i<50000000;i++);
    printf("Child 2 (priority=2, HIGH): running\n");
    exit(0);
  }

  int pid3 = fork();
  if(pid3 == 0){
    setpriority(8);
    volatile int i; for(i=0;i<50000000;i++);
    printf("Child 3 (priority=8, MED): running\n");
    exit(0);
  }

  wait(0); wait(0); wait(0);
  printf("Expected order: Child 2 -> Child 3 -> Child 1\n");
  printf("Priority test complete.\n");
  exit(0);
}
