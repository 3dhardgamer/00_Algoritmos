#include <stdio.h>


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

      printf("%d\n", vencedor);
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
    case 4: {
      int n;
      scanf("%d", &n);

      float notas[100];
      char alunos[100];
      int aluno;

      for(int i = 0; i < n; i++) {
        scanf("%f", &notas[i]);
       // scanf("%s", alunos[i]);
       // gets(alunos[i]);
      }

      scanf("%d", &aluno);
      if(notas[aluno] >= 7.0) {
        printf("%s Aprovado\n", &alunos[aluno]);
      }

      break;
    }

    // Exercicio 5
    case 5: {
      int n;
      scanf("%d", &n);

      int fatorial = 1;
      for(int i = n; i > 0; i--) {
        fatorial *= i;
      }

      printf("%d\n", fatorial);
      break;
    }

    // Exercicio 6
    case 6: {
      int k;
      scanf("%d", &k);

      int num_sequencia;
      num_sequencia = fibonacci(k - 1);
      printf("%d\n", num_sequencia);
      break;
    }

    // Exercicio 7
    case 7: {
			int partidas;
			scanf("%d", &partidas);

			int maria = 0;
			int joao = 0;
			char jogada_maria;
			char jogada_joao;

			for(int i = 0; i < partidas; i++) {
				scanf("%c", &jogada_maria);
				scanf("%c", &jogada_joao);
				
				if(jogada_maria == "t" && jogada_joao == "p") {
					maria += 1;
				} else if(jogada_maria == "p" && jogada_joao == "")
			}

			break;
		}

    // Exercicio 8
    case 8: {}

    // Exercicio 9
    case 9: {}

    default:
      printf("Opcao invalida, escolha um exercicio entre 0 - 9, por favor!\n");

  }

  return 0;
}
