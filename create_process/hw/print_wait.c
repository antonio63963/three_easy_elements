#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  
  int rc = fork();
  if(rc< 0) {
    perror("OOOPs!!! Failed fork...");
  }else if(rc == 0) {
    printf("Hello\n");
  }else {
    wait(NULL);
    printf("Goodbye\n");
  }
  

  return 0;
}