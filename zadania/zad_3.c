#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int main(int argc, char *argv[])
{
  int c;
  int i = 0;
  //char *file_out_name;

  FILE *f_from, *f_to;

  if(argc !=2 || strcmp(argv[1], "--help") == 0)
  {
    printf("Usage: %s\n", argv[0]);
    exit(1);
  }

  f_from = fopen(argv[1], "r");
  if (f_from == NULL)
  {
    printf("%s doesn't exist.", argv[1]);
    exit(1);
  }

  // file_out_name = strcat(argv[1], ".red");

  f_to = fopen(strcat(argv[1], ".red"), "w");

   while((c = getc(f_from)) != EOF)
    {
      if(i %3 == 0)
      {
        fputc(c, f_to);
      }
        i++;
    }

  fclose(f_to);
  fclose(f_from);
 exit(0);
 }