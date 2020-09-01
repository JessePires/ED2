#include <stdlib.h>

int max (int *v, int n) {
  int i, maior_elemento = 0;

  for (i = 0; i < n; i++) {
    if (v[i] > maior_elemento) {
      maior_elemento = v[i];
    }
  }

  return maior_elemento;
}

int* random_vector (int n, int max, int seed) {
  int i;
  int *v = (int*) malloc(n * sizeof(int));
  srand(seed);

  for (i = 0; i < n; i++) {
    v[i] = rand() % max;
  }

  return v;
}

void print_vector (int *v, int n) {
  int i;
  
  printf("[");
  for (i = 0; i < n; i++) {
    printf("%d", v[i]);
    printf("%s", i == n-1 ? "]" : ", ");
  }
}
