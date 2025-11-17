#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  const char *path = "/bin/ls";
  char *const ar[] = {"ls", "-l", NULL};

  printf("Start Parent...");

  int rc = fork();
  if (rc < 0)
  {
    perror("OOPS... failed fork....");
    exit(1);
  }
  else if (rc == 0)
  {
    execv(path, ar);
  }
  else
  {
    printf("Finish Parent...");
  }

  return 0;
}