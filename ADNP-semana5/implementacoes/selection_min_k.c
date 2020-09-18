#include "funcoes_auxiliares.h"

int selection_min_k (int *v, int n, int k) {
  int i;
  int menor;

  if (k > n) return v[max(v, 0, n)];

  for (i = 0; i < k; i++) {
    menor = min(v, i, n);
    troca(v, i, menor);
  }

  return v[k-1];
}
