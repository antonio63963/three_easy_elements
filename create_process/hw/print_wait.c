#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int rc = fork();
  if (rc < 0)
  {
    perror("OOOPs!!! Failed fork...");
  }
  else if (rc == 0)
  {
    printf("Hello, (pid: %d)\n", getpid());
    pid_t chP = wait(NULL);
    printf("CHP: %d\n", chP);
  }
  else
  {
    pid_t wPid = wait(NULL);
    printf("Goodbye (wPid: %d), (pid: %d)\n", wPid, getpid());
  }

  return 0;
}