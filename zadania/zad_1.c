#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
  int f_from, f_to, i;
  char buf[BUF_SIZE];
  ssize_t buf_read;
  
  

  if(argc !=2 || strcmp(argv[1], "--help") == 0)
  {
    printf("Usage: %s\n", argv[0]);
    exit(1);
  }

  f_from = open(argv[1], O_RDONLY);
  if (f_from == -1)
  {
    printf("%s doesn't exist.", argv[1]);
    exit(1);
  }

  // file_out_name = strcat(argv[1], ".red");

    // strcat = łacznie 2 stringów w jeden :) 
    f_to = open(strcat(argv[1], ".red"), O_CREAT | O_WRONLY | O_TRUNC | O_APPEND);


    while((buf_read = read(f_from, &buf, BUF_SIZE)) > 0)
    {
        for(i = 0; i < buf_read; i++){
            if(i %3 == 0)
            {
                write(f_to, &buf[i], 1);
            }
        }
    }
  close(f_to);
  close(f_from);
 exit(0);
 }