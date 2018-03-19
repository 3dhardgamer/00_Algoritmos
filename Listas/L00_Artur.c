#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int fibonacci(int num) {
  if (num == 0) {
    return 1;
  }
  if (num == 1) {
    return 1;
  }

  return fibonacci(num - 1) + fibonacci(num - 2);
}


int main() {
  char linebuffer[4096];

  while (fgets(linebuffer, sizeof(linebuffer), stdin)) {
    printf("%c\n", linebuffer[0]);
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
      printf("%i\n", total_votos);
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
    else if (linebuffer[0] == '5') {}

    // Exercicio 6
    else if (linebuffer[0] == '6') {}

    // Exercicio 7
    else if (linebuffer[0] == '7') {}

    // Exercicio 8
    else if (linebuffer[0] == '8') {}

    // Exercicio 9
    else if (linebuffer[0] == '9') {}
  }


// Versão antiga
  int exercicio;

  printf("Selecione o numero do exercicio (de 0 - 9): ");
  fscanf(stdin, "%i", &exercicio);


  switch(exercicio) {
    // Exercicio 5
    case 5: {
      int n;
      scanf("%i", &n);

      int fatorial = 1;
      for(int i = n; i > 0; i--) {
        fatorial *= i;
      }

      printf("%i\n", fatorial);
      break;
    }

    // Exercicio 6
    case 6: {
      int k;
      scanf("%i", &k);

      int num_sequencia;
      num_sequencia = fibonacci(k - 1);
      printf("%i\n", num_sequencia);
      break;
    }

    // Exercicio 7
    case 7: {
      int partidas;
      scanf("%i", &partidas);

      int maria = 0;
      int joao = 0;
      char jogada_maria;
      char jogada_joao;

      for(int i = 1; i <= partidas; i++) {
        printf("Partida %i\n", i);

        //jogada_maria = fgetc(stdin);
        //jogada_joao = fgetc(stdin);

        fscanf(stdin, "%c %c\n", &jogada_maria, &jogada_joao);
        printf("%c\n", jogada_maria);
        printf("%c\n", jogada_joao);

        if(jogada_maria == 't' && jogada_joao == 'p') {
          maria += 1;
        }
        else if(jogada_maria == 'p' && jogada_joao == 'd') {
          maria += 1;
        }
        else if(jogada_maria == 'd' && jogada_joao == 't') {
          maria += 1;
        }
        else if(jogada_maria == jogada_joao) {
          continue;
        }
        else {
          joao += 1;
        }
      }

      if(maria > joao) {
        printf("Maria\n");
      }
      else if(maria == joao) {
        printf("EMPATE\n");
      }
      else {
        printf("Joao\n");
      }

      break;
    }

    // Exercicio 8
    case 8: {
      int A;
      int B;
      int aux;

      scanf("%i", &A);
      scanf("%i", &B);

      aux = A;
      A = B;
      B = aux;

      printf("%i %i\n", A, B);
      break;
    }

    // Exercicio 9
    case 9: {
      int n;
      scanf("%i", &n);

      int vetor[n];
      for(int i = 0; i < n; i++) {
        scanf("%i", &vetor[i]);
      }

      int aux;
      for(int i = 0; i < n; i++) {
        printf("%i\n", vetor[i]);
        for(int j = 0; j < n - 1; j++) {
          if(vetor[j] > vetor[j + 1]) {
            printf("%i", vetor[j]);
            aux = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = aux;
          }
        }
      }

      for(int i = 0; i < n; i++) {
        printf("%i ", vetor[i]);
      }
      printf("\n");

    }

    default:
      printf("Opcao invalida, escolha um exercicio entre 0 - 9, por favor!\n");

  }

  return 0;
}
