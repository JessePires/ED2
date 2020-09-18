#include "funcoes_auxiliares.h"

int partition (int *v, int p, int direita) {
  int pivo, i, j;
  
  pivo = v[direita]; // essa implementação sempre usa o último elemento do vetor como pivô
  i = p-1;

  for (j = p; j < direita; j++) {
    if (v[j] <= pivo) {
      i++;
      troca(v, i, j);
    }
  }

  troca(v, i+1, direita);
  return i+1;
}

int quick_min_k (int *v, int esquerda, int direita, int k) {
  int q;

  if (k > direita + 1) return v[max(v, esquerda, direita+1)];

  if (esquerda < direita && q != k-1) {
    q = partition(v, esquerda, direita);

    if (q > k-1) {
      quick_min_k(v, esquerda, q-1, k);
    } else {
      quick_min_k(v, q+1, direita, k);
    }
  }

  return v[k-1];
}
