#include <stdio.h>
#include <time.h>
#include "radix_sort.h"
#include "funcoes_auxiliares.h"

#define DEBUG 0
#define N 1000000
#define MAX N * 100
#define SEED 42

int main(int argc, char** argv){
  int *valores;
  clock_t time;

  // RADIX SORT NA BASE 2
  valores = random_vector(N, MAX, SEED);

  #if DEBUG
    printf("Vetor desordenado: ");
    print_vector(valores, N);
  #endif

  time = clock();
  radix_sort_base_dois(valores, N);
  time = clock() - time;

  #if DEBUG
  printf("\n\nVetor ordenado com Radix Sort na base 2: ");
  print_vector(valores, N);
  #endif

  printf("Tempo gasto com base 2: %f milisegundos\n", ((float) time)/(CLOCKS_PER_SEC/1000));


  // RADIX SORT NA BASE 10
  valores = random_vector(N, MAX, SEED);
  time = clock();
  radix_sort(valores, N, 10);
  time = clock() - time;

  #if DEBUG
  printf("\nVetor ordenado com Radix Sort na base 10: ");
  print_vector(valores, N);
  printf("\n");
  #endif

  printf("Tempo gasto com base 10: %f milisegundos\n\n", ((float) time)/(CLOCKS_PER_SEC/1000));

  return 0;
}
