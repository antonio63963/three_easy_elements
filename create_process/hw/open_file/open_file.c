#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
  const char *fileName = "open_test.txt";
  const char *data_to_add = "Это добавлено через системный вызов write().\n";

  int fd = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0666);
  printf("FD::: %d\n", fd);

  size_t len = strlen(data_to_add);
  ssize_t bytes_written = write( fd, data_to_add, len);

  if (bytes_written != (ssize_t)len) {
        perror("Ошибка записи в файл");
        // В случае ошибки записи все равно нужно попытаться закрыть дескриптор
    } else {
        printf("Успешно добавлено %zd байтов в файл '%s'.\n", bytes_written, fileName);
    }
    
    // НЕ ЗАКРЫВАЮ, ДЛЯ ИСПОЛЬЗОВАНИЯ В ДОЧ. ПРОЦЕССЕ!! Закрытие файлового дескриптора
    // if (close(fd) < 0) {
    //     perror("Ошибка при закрытии файла");
    //     exit(1);
    // }

  if (fd < 0)
  {
    perror("Ошибка при открытии/создании файла");
    exit(1);
  }

  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "Fork Error, quit...");
    exit(1);
  }
  else if (rc == 0)
  {
    char *childText = "Child text append\n";
    size_t lenChildText = strlen(childText);
    ssize_t child_writter = write(fd, childText, lenChildText);

    printf("CHild:::X+10 = %zd, (pid: %d)\n", child_writter, getpid());
  }
  else
  {
    int rc_wait = wait(NULL);
    printf("Parent::: (pid: %d)\n", getpid());
  }
  return 0;
}