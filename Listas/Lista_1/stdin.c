#include <stdio.h>
#include <stdlib.h>

int main() {
    char linebuffer[4096];

    while(fgets(linebuffer, sizeof linebuffer, stdin))  {
        switch(linebuffer[0]) {
            case '1':
                fprintf(stdout, "Estou no exercicio 1(soma)\n");
                int soma = 0;
                while(fgets(linebuffer, sizeof linebuffer, stdin))  {
                    soma += atoi(linebuffer);
                }
                fprintf(stdout, "A soma eh: %d", soma);
                return 0;

            case '2':
                fprintf(stdout, "Estou no exercicio 2 (fscanf)\n");
                float f[2];
                int i=0;
                while(fgets(linebuffer, sizeof linebuffer, stdin))  {
                    //sprintf(linebuffer, "%f %f", &f[0], &f[1]);
                    sscanf(linebuffer, "%f %f", &f[0], &f[1]);
                    fprintf(stdout, "%i: f[0]: %f, f[1]: %f\n", i, f[0], f[1]);
                    i++;
                }
                return 0;

            case '3':
                fprintf(stdout, "Estou no exercicio 3\n");
    
                while(fgets(linebuffer, sizeof linebuffer, stdin))  {
                    fprintf(stdout, "(3): %s", linebuffer);
                }
                return 0;
                
            default:
                fprintf(stdout, "Nao estou\n");
        }
    }

    return 0;
}
