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


int main(int argc, char *argv[]) {
  char linebuffer[4096];

  while(fgets(linebuffer, sizeof(linebuffer), stdin)) {
    // Exercicio 0
    if (linebuffer[0] == 0) {
      printf("Hello World!\n");
    }
    // Exercicio 1
    else if (linebuffer[0] == 1) {
      int a;
      int b;
      while(fgets(linebuffer, sizeof(linebuffer), stdin)) {
        a = atoi(linebuffer);
        b = atoi(linebuffer);
      }

      for (int i = a; i <= b; i++) {
        printf("%i\n", i);
      }
    }
    // Exercicio 2
    else if (linebuffer[0] == 2) {
      int total_votos;
      fscanf(stdin, "%i", &total_votos);

      int candidatos[4] = {0, 0, 0, 0};
      int voto, vencedor;

      for (int n = 1; n <= total_votos; n++) {
        fscanf(stdin, "%i", &voto);
      }
    }
  }


// Versão antiga
  int exercicio;

  printf("Selecione o numero do exercicio (de 0 - 9): ");
  fscanf(stdin, "%i", &exercicio);


  switch(exercicio) {
    // Exercicio 0
    case 0:
      printf("Hello World!\n");
      break;

    // Exercicio 1
    case 1: {
      int a;
      int b;

      scanf("%i", &a);
      scanf("%i", &b);

      for(int i = a; i <= b; i++){
        printf("%i\n", i);
      }
      break;
    }
    // Exercicio 2
    case 2: {
      int total_votos;
      scanf("%i", &total_votos);

      int candidatos[4] = {0, 0, 0, 0};
      int voto, vencedor;

      for(int n = 1; n <= total_votos; n++) {
        scanf("%i", &voto);

        if(voto == 0) {
          candidatos[0] += 1;
        } else if(voto == 1){
          candidatos[1] += 1;
        }
        else if(voto == 2){
          candidatos[2] += 1;
        }
        else if(voto == 3){
          candidatos[3] += 1;
        }
        else {
          printf("Candidato invalido!\n");
          continue;
        }
      }

      vencedor = 0;
      for(int c = 1; c <= 3; c++) {
        printf("%i %i\n", candidatos[vencedor], candidatos[c]);
        if(candidatos[c] > candidatos[vencedor]) {
          vencedor = c;
        }
        else if(candidatos[c] == candidatos[vencedor]) {
          vencedor = 0;
          candidatos[vencedor] = candidatos[c];
        }
        else {
          continue;
        }
      }

      printf("%i\n", vencedor);
      break;
    }

    // Exercicio 3
    case 3: {
      int n;
      scanf("%i", &n);

      double vetor[n];
      double soma = 0;
      double media = 0;
      double max = 0;
      double min = 0;

      for(int i = 0; i < n; i++) {
        scanf("%lf", &vetor[i]);
      }

      max = vetor[0];
      min = vetor[0];

      for(int i = 0; i < n; i++) {
        soma += vetor[i];

        if(max < vetor[i]) {
          max = vetor[i];
        }

        if(min > vetor[i]) {
          min = vetor[i];
        }
      }
      media = soma / n;

      printf("%.1lf\n", soma);
      printf("%.1lf\n", media);
      printf("%.1lf\n", max);
      printf("%.1lf\n", min);
      break;
    }

    // Exercicio 4
    case 4: {
      int n;
      scanf("%i", &n);

      float notas[100];
      char alunos[100];
      int aluno;

      for(int i = 0; i < n; i++) {
        scanf("%f", &notas[i]);
       // scanf("%s", alunos[i]);
       // gets(alunos[i]);
      }

      scanf("%i", &aluno);
      if(notas[aluno] >= 7.0) {
        printf("%s Aprovado\n", &alunos[aluno]);
      }

      break;
    }

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
