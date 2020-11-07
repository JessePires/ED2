#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes_auxiliares/funcoes_auxiliares.h"
#include "abb/abb.h"
#include "arn/arn.h"
#include "avl/avl.h"
#include "sorting/sorting.h"

void teste_com_dez_vetores (int n) {
  int altura;
  clock_t tempo;
  float tempo_total;
  int *v;
  
  printf("TESTE DE ORDENAÇÃO DE 10 VETORES\n");
  printf("\nQuantidade de elementos: %d\n", n);
  printf("====================================================");
  
  printf("\nOrdenando com uma Árvore de Busca Binária:\n\n");
  v = vetor_aleatorio(n);
  altura = 0;
  tempo_total = 0;

  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ABB_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  printf("Média das alturas: %d\n", altura/10);
  printf("Tempo gasto na execução: %f\n", tempo_total/10);

  printf("====================================================");
  
  printf("\nOrdenando com uma Árvore Rubro-Negra:\n\n");
  v = vetor_aleatorio(n);
  altura = 0;
  tempo_total = 0;

  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += ARN_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  printf("Média das alturas: %d\n", altura/10);
  printf("Tempo gasto na execução: %f\n", tempo_total/10);

  printf("====================================================");
  
  printf("\nOrdenando com uma Árvore AVL:\n\n");
  v = vetor_aleatorio(n);
  altura = 0;
  tempo_total = 0;

  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  v = vetor_aleatorio(n);
  tempo = clock();
  altura += AVL_Sort(v, n);
  tempo = clock() - tempo;
  tempo_total += (float)tempo/CLOCKS_PER_SEC;

  printf("Média das alturas: %d\n", altura/10);
  printf("Tempo gasto na execução: %f\n", tempo_total/10);

  printf("====================================================\n");

  free(v);
}

void teste_com_um_vetor (int n) {
  int altura;
  clock_t tempo;
  int *v;

  printf("====================================================");
  
  printf("\nQuantidade de elementos do vetor: %d\n", n);

  printf("====================================================");
  
  printf("\nOrdenando com uma Árvore de Busca Binária:\n\n");
  v = vetor_decrescente(n);

  tempo = clock();
  altura = ABB_Sort(v, n);
  tempo = clock() - tempo;

  printf("Altura da árvore criada: %d\n", altura);
  printf("Tempo gasto na execução: %f\n", ((float)tempo)/CLOCKS_PER_SEC);

  printf("====================================================");
  
  printf("\nOrdenando com uma Árvore Rubro-Negra:\n\n");
  v = vetor_decrescente(n);

  tempo = clock();
  altura = ARN_Sort(v, n);
  tempo = clock() - tempo;

  printf("Altura da árvore criada: %d\n", altura);
  printf("Tempo gasto na execução: %f\n", ((float)tempo)/CLOCKS_PER_SEC);

  printf("====================================================");
  
  printf("\nOrdenando com uma Árvore AVL:\n\n");
  v = vetor_decrescente(n);

  tempo = clock();
  altura = AVL_Sort(v, n);
  tempo = clock() - tempo;

  printf("Altura da árvore criada: %d\n", altura);
  printf("Tempo gasto na execução: %f\n", ((float)tempo)/CLOCKS_PER_SEC);

  printf("====================================================\n");

  free(v);
}

int main (int argc, char **argv) {
  int n, teste;

  n = (argc > 1) ? atoi(argv[1]) : 1000;
  teste = (argc > 2) ? atoi(argv[2]) : 1;

  if (teste == 2) teste_com_dez_vetores(n);
  else teste_com_um_vetor(n);

  return 0;
}
