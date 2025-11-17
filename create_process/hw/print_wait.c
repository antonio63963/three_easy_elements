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
    int status;
    pid_t chP = waitpid(rc, &status, 0);
    printf("CHP: %d\n", chP);
  }
  else
  {
    int status;
    pid_t wPid = waitpid(rc, &status, 0);
    printf("Goodbye (wPid: %d), (pid: %d)\n", wPid, getpid());
  }

  return 0;
}