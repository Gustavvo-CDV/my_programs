#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define BUF_SIZE 100

void child_process(char *in_file_name, char *out_file_name)
{  
    FILE *f_to = fopen(out_file_name, "w");

    int f_from = open(in_file_name, O_RDONLY);

    if (f_from == -1)
    {
        printf("%s doesn't exist.\n", in_file_name);
        exit(1);
    }

    ssize_t single_read_size = 0; //ilośc bytow oczytana przy jednym odczycie  
    char buffer[BUF_SIZE]; // bufor o rozmiarze BUF_SIZE 
    int total_bytes = 0; //

    while((single_read_size = read(f_from, &buffer, BUF_SIZE)) > 0)
    {
        total_bytes += (int)single_read_size;
    }
    
    char out_buff[50]; // dzieki niej moge zformatowac tekst który trafia do pliku wynikowego
    snprintf(out_buff, sizeof out_buff, "Plik %s ma wielkosc: %d bajtow\n", in_file_name, total_bytes);
    fputs(out_buff, f_to); //wczesniej sformatowany tekst, zapisuje do pliku x
    
    close(f_from);
    fclose(f_to);
}

int main(int argc, char *argv[])
{
    if(argc !=3 || strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: %s file_destination file_origin\n", argv[0]);
        return 1;
    }

    if (fork()== 0) // stworzenie procesu potomnego, sprawdzam który to proces (glowny czy potomny), jesli jest 0 jest procesem (dziecka) kazda inna to proces głowny (rodzica)
        child_process(argv[2], argv[1]);
    else
    {
        wait(NULL);
        printf("Program has finished\n");
    }
    exit(0);
 }