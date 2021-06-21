#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c;
  size_t linecount = 0;
  FILE *f_from, *f_to;

  f_from = fopen("myfile.txt", "r");
  if (f_from == NULL)
  {
    perror("myfile.txt doesn't exist.");
    exit(1);
  }

  f_to = fopen("copy.txt", "w");
  if (f_to == NULL)
    {
      perror("copy.txt doesn't exist.");
      exit(1);
    }

  
   while((c = fgetc(f_from)) != EOF)
    {
  
        printf("%c ", c);
    }

  fclose(f_to);
  fclose(f_from);
  exit(0);
}