#include <stdio.h>
#include <stdlib.h>
#include "funcoes_auxiliares.h"

int* vetor_aleatorio (int n) {
  int i;

  int *v = malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    v[i] = rand() % n;
  }

  return v;
}

int* vetor_decrescente (int n) {
  int i, j;

  int *v = malloc(n * sizeof(int));
  j = 0;
  for (i = n; i > 0; i--) {
    v[j] = i;
    j++;
  }

  return v;
}

void imprimir_vetor (int *v, int n) {
  int i;

  printf("[");
  for (i = 0; i < n; i++) {
    printf("%d", v[i]);
    printf("%s", i == n-1 ? "]\n" : ", ");
  }
}
