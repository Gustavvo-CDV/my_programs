#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c;
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

    while ((c = getc(f_from)) != EOF) {
    putc(c, f_to);
}

  fclose(f_to);
  fclose(f_from);
  exit(0);
}