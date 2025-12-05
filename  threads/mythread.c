#include <stdio.h>
#include <pthread.h>
#include <assert.h>

void *mythread(void *arg) {
  printf("%s\n", (char *) arg);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t p1, p2;
  int rc;
  printf("main: bgin\n");
  rc = pthread_create(&p1, NULL, mythread, "A"); assert(rc == 0);
  rc = pthread_create(&p2, NULL, mythread, "B"); assert(rc == 0);
  //join ждет завершения потока
  rc=pthread_join(p1, NULL); assert(rc ==0);
  rc=pthread_join(p2, NULL); assert(rc ==0);

  printf("main: end\n");

  return 0;
}