#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  printf("hello world ()(pid: %d)\n", (int)getpid());
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "Fork Error, quit...");
    exit(1);
  }
  else if (rc == 0)
  { // new process
    //закрываю stdout в консоль и сразу открваю файл где записывать! 
    close(STDOUT_FILENO);
    open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    char *myArgs[3];
    myArgs[0] = strdup("wc");
    myArgs[1] = strdup("p4.c");
    myArgs[2] = NULL;

    execvp(myArgs[0], myArgs);
  }
  else
  {
    int rc_wait = wait(NULL);
    printf("hello, I am parent of %d, (rc_wait: %d), (pid: %d)\n", rc, rc_wait, getpid());
  }

  return 0;
}