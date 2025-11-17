#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

  int pid = fork();
  if(pid < 0) {
    perror("OOpss!!!");
    exit(1);
  }else if(pid == 0) {
    printf("Ща вырублю!\n");
    fflush(stdout);
    close(STDOUT_FILENO);
    printf("HOOOHOHO!!!\n");
  }else {
    int status;
    int wPid = waitpid(pid, &status, 0);
    printf("Parent: (pid: %d)\n", wPid);
  }

  return 0;
}