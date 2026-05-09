#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  printf("Read count before: %d\n", getreadcount());
  char buf[4];
  read(0, buf, 1);
  read(0, buf, 1);
  printf("Read count after: %d\n", getreadcount());
  exit(0);
}
