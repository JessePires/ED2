#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selection_min_k.h"
#include "heap_min_k.h"
#include "quick_min_k.h"
#include "vetor_aleatorio.h"
#include "funcoes_auxiliares.h"

#define N 1000000
#define MAX N * 100
#define SEED 42
#define K N/2

int* random_vector (int n, int max, int seed) {
  int *v = (int *) calloc(n, sizeof(int));
  srand(seed);

  for (int i = 0; i < n; i++) {
    v[i] = rand() % max;
  }

  return v;
}

int main(int argc, char** argv){
  int *v;
  int elemento;
  clock_t time;

  // TESTE DO SELECTION_MN_K
  // v = random_vector_unique_elems(N, SEED);
  // time = clock();
  // elemento = selection_min_k(v, N, K);
  // time = clock() - time;

  // printf("K-ésima menor chave (selection): %d\n", elemento);
  // printf("Tempo gasto: %f segundos\n\n", ((float)time)/CLOCKS_PER_SEC);

  // TESTE DO HEAP_MIN_K
  v = random_vector_unique_elems(N, SEED);
  time = clock();
  elemento = heap_min_k(v, N, K);
  time = clock() - time;

  printf("K-ésima menor chave (heap): %d\n", elemento);
  printf("Tempo gasto: %f segundos\n\n", ((float)time)/CLOCKS_PER_SEC);

  //TESTE DO QUICK_MIN_K
  v = random_vector_unique_elems(N, SEED);
  time = clock();
  elemento = quick_min_k(v, 0, N-1, K);
  time = clock() - time;

  printf("K-ésima menor chave (quick): %d\n", elemento);
  printf("Tempo gasto: %f segundos\n", ((float)time)/CLOCKS_PER_SEC);

  return 0;
}
