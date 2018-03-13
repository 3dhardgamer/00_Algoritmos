#include <stdio.h>

int main() {
  int exercicio;

  printf("Selecione o numero do exercicio (de 0 - 9): ");
  scanf("%d", &exercicio);
//  printf("Exercicio numero: %d", exercicio);

  switch(exercicio) {
    // Exercicio 0
    case 0:
      printf("Hello World!\n");
      break;

    // Exercicio 1
    case 1: {
      int a;
      int b;

      scanf("%d", &a);
      scanf("%d", &b);

      for(int i = a; i <= b; i++){
        printf("%d\n", i);
      }
      break;
    }
    // Exercicio 2
    case 2: {
      int total_votos;
      scanf("%d", &total_votos);

      int candidatos[4] = {0, 0, 0, 0};
      int voto, vencedor;

      for(int n = 1; n <= total_votos; n++) {
        scanf("%d", &voto);

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
        printf("%d %d\n", candidatos[vencedor], candidatos[c]);
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

      printf("%d", vencedor);
      break;
    }

    // Exercicio 3
    case 3: {
      int n;
      scanf("%d", &n);

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
    case 4: {}

    // Exercicio 5
    case 5: {}

    // Exercicio 6
    case 6: {}

    // Exercicio 7
    case 7: {}

    // Exercicio 8
    case 8: {}

    // Exercicio 9
    case 9: {}

    default:
      printf("Opcao invalida, escolha um exercicio entre 0 - 9, por favor!\n");

  }

  return 0;
}
