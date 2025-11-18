#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
  int fd[2];

  if (pipe(fd) == -1)
  {
    perror("Failure...");
    exit(1);
  }

  int pid1 = fork();
  int pid2 = fork();

  if (pid1 < 0)
  {
    perror("PID1 err");
    exit(1);
  }
  else if (pid1 == 0)
  {
    close(fd[0]);
    const char *msg = "SOmeSTRING...";
    write(fd[1], msg, strlen(msg) + 1);
    close(fd[1]);
  }

  if(pid2 < 0) {
    perror("PID2 error");
    exit(1);
  }else if(pid2 == 0) {
    char buf[100];
    close(fd[1]);
    size_t size = read(fd[0], buf, 100);
    if(size > 0) {
      
      buf[size] = '\0';
      printf("%s\n", buf);
      close(fd[0]);
    }else {
      printf("FILe не  записан!");
      exit(1);
    }
    
  }else  {
    close(fd[0]);
    close(fd[1]);
  }

  return 0;
}