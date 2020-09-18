#include "funcoes_auxiliares.h"

int esq (int i) {
  return 2*i + 1;
}

int dir (int i) {
  return esq(i) + 1;
}

void min_heapfy (int *v, int i, int th) {
  int menor = i;
  int e = esq(i);
  int d = dir(i);

  if ((e < th) && (v[e] < v[i])) {
    menor = e;
  }

  if ((d < th) && (v[d] < v[menor])) {
    menor = d;
  }

  if (menor != i) {
    troca(v, i, menor);
    min_heapfy(v, menor, th);
  }
}

void build_min_heap (int *v, int n) {
  for (int i = n/2; i >= 0; i--) {
    min_heapfy(v, i, n);
  } 
}

int heap_min_k (int *v, int n, int k) {
  int i;
  
  if (k > n) return v[max(v, 0, n)];
  
  build_min_heap(v, n);

  for (int i = n-1; i > n-k; i--) {
    troca(v, 0, i);
    min_heapfy(v, 0, i);
  } 

  return v[0];
}
