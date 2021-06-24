#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int open_file, number_int, i;
  char buffer[50], number_char;
    srand(time(NULL));
  
if(argc !=2 || strcmp(argv[1], "--help") == 0)
{
    printf("Usage: %s file_destination file origin\n", argv[0]);
    return 1;

}

  open_file = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND);

  if (open_file == -1)
    {
    printf("%s doesn't exist.", argv[1]);
    exit(1);
    }

  for(int i = 0; i <10; i++)
    {
    number_char = (rand() % 100);
    number_int = sprintf(buffer, "%d\n", number_char);
    write(open_file, buffer, number_int);
    }

  close(open_file);
  exit(0);
 }