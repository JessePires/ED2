#include <stdlib.h>
#include <time.h>
#include "funcoes_auxiliares.h"

void embaralhar (int *v, int ini, int fim) {
  int i, j;

  for (i = fim-1; i > ini; i--) {
    j = (rand() % (i + 1));
    j = j <= ini? ini+1 : j;
    troca(v, i, j);
  }
}

int* random_vector_unique_elems(int n, int seed) {
  int *v = (int *) malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    v[i] = i+1;
  }

  srand(seed);
  embaralhar(v, 0, n);

  return v;
}
