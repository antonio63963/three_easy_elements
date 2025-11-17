#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  int x = 100;
  printf("X = %d, (pid: %d)\n", x, getpid());
  x += 12;
  fflush(stdout); // сброс буфера printf(копия х) будет х = 100
  int rc = fork();
  x+=100;
  if (rc < 0)
  {
    fprintf(stderr, "Fork Error, quit...");
    exit(1);
  }
  else if (rc == 0)
  {
    x += 10;
    printf("CHild:::X+10 = %d, (pid: %d)\n", x, getpid());
  }
  else
  {
    int rc_wait = wait(NULL);
    printf("Parent:::X wait: %d, (pid: %d)\n", x, getpid());
  }
  return 0;
}