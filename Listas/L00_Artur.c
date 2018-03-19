#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int fibonacci(int num) {
  if (num <= 1) {
    return num;
  }
  else {
    return fibonacci(num - 1) + fibonacci(num - 2);
  }
}

void swap(int *num1, int *num2) {
  int aux;
  aux = *num1;
  *num1 = *num2;
  *num2 = aux;
}

int main() {
  char linebuffer[4096];

  while (fgets(linebuffer, sizeof(linebuffer), stdin)) {
    //printf("%c\n", linebuffer[0]);
    // Exercicio 0
    if (linebuffer[0] == '0') {
      printf("Hello World!\n");
    }

    // Exercicio 1
    else if (linebuffer[0] == '1') {
      int a[2];
      int i = 0;
      while (fgets(linebuffer, sizeof(linebuffer), stdin)) {
        a[i] = atoi(linebuffer);
        i++;
      }

      for (int i = a[0]; i <= a[1]; i++) {
        printf("%i\n", i);
      }
    }

    // Exercicio 2
    else if (linebuffer[0] == '2') {
      // Pega a proxima linha do buffer
      fgets(linebuffer, sizeof(linebuffer), stdin);
      int total_votos = atoi(linebuffer);
      //printf("%i\n", total_votos);
      int candidatos[4] = {0, 0, 0, 0};
      int vencedor = 0;

      for (int n = 1; n <= total_votos; n++) {
        fgets(linebuffer, sizeof(linebuffer), stdin);
        if (linebuffer[0] == '0') {
          candidatos[0] += 1;
        }
        else if (linebuffer[0] == '1') {
          candidatos[1] += 1;
        }
        else if (linebuffer[0] == '2') {
          candidatos[2] += 1;
        }
        else if (linebuffer[0] == '3') {
          candidatos[3] += 1;
        }
        else {
          printf("Candidato inválido!\n");
          continue;
        }
      }

      for (int c = 1; c <= 3; c++) {
        if (candidatos[c] > candidatos[vencedor]) {
          vencedor = c;
        }
        else if (candidatos[c] == candidatos[vencedor]) {
          vencedor = 0;
          candidatos[vencedor] = candidatos [c];
        }
        else {
          continue;
        }
      }
      printf("%i\n", vencedor);
    }

    // Exercicio 3
    else if (linebuffer[0] == '3') {
      fgets(linebuffer, sizeof(linebuffer), stdin);
      int n = atoi(linebuffer);

      double vetor[n];
      double num;
      double soma = 0;
      double media = 0;
      double max = 0;
      double min = 0;

      int i = 0;
      while (fgets(linebuffer, sizeof(linebuffer), stdin)) {
        num = atof(linebuffer);
        soma += num;

        if (i == 0) {
          min = num;
        }

        if (max < num) {
          max = num;
        }
        if (min > num) {
          min = num;
        }
        i++;
      }

      media = soma / n;

      printf("%.1lf\n", soma);
      printf("%.1lf\n", media);
      printf("%.1lf\n", max);
      printf("%.1lf\n", min);

    }

    // Exercicio 4
    else if (linebuffer[0] == '4') {
      fgets(linebuffer, sizeof(linebuffer), stdin);
      int n = atoi(linebuffer);
      int aluno;

      struct Aluno {
        float nota;
        char nome[100];
        char sobrenome[100];
      };

      struct Aluno alunos[100];

      for (int i = 0; i < n; i++) {
        fgets(linebuffer, sizeof(linebuffer), stdin);
        sscanf(linebuffer, "%f %s %s", &alunos[i].nota, alunos[i].nome, alunos[i].sobrenome);
      }

      fgets(linebuffer, sizeof(linebuffer), stdin);
      aluno = atoi(linebuffer);

      if (alunos[aluno - 1].nota >= 7.0) {
        printf("%s %s Aprovado\n", alunos[aluno - 1].nome, alunos[aluno - 1].sobrenome);
      }

    }

    // Exercicio 5
    else if (linebuffer[0] == '5') {
      fgets(linebuffer, sizeof(linebuffer), stdin);
      int n = atoi(linebuffer);
      int fatorial = 1;

      for (int i = n; i > 0; i--) {
        fatorial *= i;
      }

      printf("%i\n", fatorial);
    }

    // Exercicio 6
    else if (linebuffer[0] == '6') {
      fgets(linebuffer, sizeof(linebuffer), stdin);
      int k = atoi(linebuffer);

      int num_sequencia;
      num_sequencia = fibonacci(k);
      printf("%i\n", num_sequencia);
    }

    // Exercicio 7
    else if (linebuffer[0] == '7') {
      fgets(linebuffer, sizeof(linebuffer), stdin);
      int partidas = atoi(linebuffer);

      // jogadas[0] = jogada da maria
      // jogadas[1] = jogada do joao
      char jogadas[2];
      int maria = 0;
      int joao = 0;

      for (int i = 0; i < partidas; i++) {
        fgets(linebuffer, sizeof(linebuffer), stdin);
        sscanf(linebuffer, "%c %c", &jogadas[0], &jogadas[1]);

        if (jogadas[0] == 't' && jogadas[1] == 'p') {
          maria += 1;
        }
        else if (jogadas[0] == 'p' && jogadas[1] == 'd') {
          maria += 1;
        }
        else if (jogadas[0] == 'd' && jogadas[1] == 't') {
          maria += 1;
        }
        else if (jogadas[0] == jogadas[1]) {
          continue;
        }
        else {
          joao += 1;
        }
      }

      if (maria > joao) {
        printf("Maria\n");
      }
      else if (maria == joao) {
        printf("EMPATE\n");
      }
      else {
        printf("Joao\n");
      }
    }

    // Exercicio 8
    else if (linebuffer[0] == '8') {
      int A, B;
      fgets(linebuffer, sizeof(linebuffer), stdin);
      sscanf(linebuffer, "%i %i", &A, &B);
      swap(&A, &B);
      printf("%i %i\n", A, B);
    }

    // Exercicio 9
    else if (linebuffer[0] == '9') {
      fgets(linebuffer, sizeof(linebuffer), stdin);
      int n = atoi(linebuffer);
      printf("%i\n", n);
      int vetor[n];
      int k = 0;
      char *ptr;

      fgets(linebuffer, sizeof(linebuffer), stdin);
      ptr = strtok(linebuffer, " ");
      while (ptr) {
        vetor[k] = strtol(ptr, NULL, 10);
        k++;
        ptr = strtok(NULL, " ");
      }

      int aux;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
          if (vetor[j] > vetor[j + 1]) {
            aux = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = aux;
          }
        }
      }

      for (int i = 0; i < n; i++) {
        printf("%i ", vetor[i]);
      }
      printf("\n");
    }
  }

  return 0;
}

