#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

// PROTÓTIPOS
int esq (int i);
int dir (int i);
int pai (int i);
void troca (int *v, int i, int j);
void print_vector(int *v, int n);
int FP_inicio(int *fp, int n); // retorna o elemento no início da fila

// MAX HEAP
void max_heapfy(int *v, int i, int th);
void build_max_heap(int *v, int n);
void heap_sort(int *v, int n);
int FP_remover_maximo(int *fp, int n); // retorna o tamanho da fila
int FP_inserir(int *fp, int n, int x); // retorna o tamanho da fila
void max_heap_testes(int *fp, int n);

// MIN HEAP
void min_heapfy(int *v, int i, int th);
void build_min_heap(int *v, int n);
int FP_remover_minimo(int *fp, int n); // retorna o tamanho da fila
int min_FP_inserir(int *fp, int n, int x); // retorna o tamanho da fila
void min_heap_testes(int *fp, int n);

// IMPLEMENTACOES
int esq (int i) {
  return 2*i + 1;
}

int dir (int i) {
  return esq(i) + 1;
}

int pai (int i) {
  return (i-1)/2;
}

void troca (int *v, int i, int j) {
  int element_in_i = v[i];
  v[i] = v[j];
  v[j] = element_in_i;
}

void print_vector (int *v, int n) {
  printf("[");

  for (int i = 0; i < n; i++) {
    printf("%d", v[i]);
    printf("%s", i == n - 1 ? "" : ", ");
  }
  printf("]\n");
}


// MAX HEAP
void max_heapfy (int *v, int i, int th) {
  int maior = i;
  int e = esq(i);
  int d = dir(i);

  if ((e < th) && (v[e] > v[i])) {
    maior = e;
  }

  if ((d < th) && (v[d] > v[maior])) {
    maior = d;
  }

  if (maior != i) {
    troca(v, i, maior);
    max_heapfy(v, maior, th);
  }
}

void build_max_heap (int *v, int n) {
  for (int i = n/2; i >= 0; i--) {
    max_heapfy(v, i, n);
  }
}

void heap_sort (int *v, int n) {
  build_max_heap(v, n);

  for (int i = n-1; i > 0; i--) {
    troca(v, 0, i);
    max_heapfy(v, 0, i);
  }
}

int FP_inicio (int *fp, int n) {
  return fp[0];
} 

int FP_remover_maximo (int *fp, int n) {
  fp[0] = fp[n-1];
  max_heapfy(fp, 0, n-1);

  return n-1;
}

int FP_inserir (int *fp, int n, int x) {
  int new_n = n+1;
  fp[new_n - 1] = x;
  int i = new_n - 1;

  while (fp[i] > fp[pai(i)]) {
    troca(fp, pai(i), i);
    i = pai(i);
  }

  return new_n;
}

void max_heap_testes(int *fp, int n) {
  n = FP_inserir(fp, n, 2);
  n = FP_inserir(fp, n, 3);
  n = FP_inserir(fp, n, 10);
  printf("Elemento com maior prioridade com Max Heap: %d\n", FP_inicio(fp, n));

  n = FP_inserir(fp, n, 5);
  n = FP_inserir(fp, n, 15);
  n = FP_inserir(fp, n, 20);
  printf("Elemento com maior prioridade com Max Heap: %d\n", FP_inicio(fp, n));

  #if DEBUG
  printf("Fila de prioridades com Max Heap: ");
  print_vector(fp, n);
  #endif
  n = FP_remover_maximo(fp, n);
  n = FP_remover_maximo(fp, n);
  #if DEBUG
  printf("Fila de prioridades com Max Heap após a remoção de elementos: ");
  print_vector(fp, n);
  #endif
  n = FP_remover_maximo(fp, n);
  
  #if DEBUG
  printf("Fila de prioridades com Max Heap após a remoção de elementos: ");
  print_vector(max_heap_fp, n);
  #endif
}


// MIN HEAP
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

int FP_remover_minimo (int *fp, int n) {
  fp[0] = fp[n-1];
  min_heapfy(fp, 0, n-1);

  return n-1;
}

int min_FP_inserir (int *fp, int n, int x) {
  int new_n = n+1;
  fp[new_n - 1] = x;
  int i = new_n - 1;

  while (fp[i] < fp[pai(i)]) {
    troca(fp, pai(i), i);
    i = pai(i);
  }

  return new_n;
}

void min_heap_testes(int *fp, int n) {
  n = min_FP_inserir(fp, n, 2);
  n = min_FP_inserir(fp, n, 3);
  n = min_FP_inserir(fp, n, 10);
  printf("\nElemento com maior prioridade com Min Heap: %d\n", FP_inicio(fp, n));

  n = min_FP_inserir(fp, n, 5);
  n = min_FP_inserir(fp, n, 15);
  n = min_FP_inserir(fp, n, 15);
  n = min_FP_inserir(fp, n, 20);
  printf("Elemento com maior prioridade com Min Heap: %d\n", FP_inicio(fp, n));

  #if DEBUG
  printf("Fila de prioridades com Min Heap: ");
  print_vector(fp, n);
  #endif
  n = FP_remover_minimo(fp, n);
  n = FP_remover_minimo(fp, n);
  #if DEBUG
  printf("Fila de prioridades com Min Heap após a remoção de elementos: ");
  print_vector(fp, n);
  #endif
  printf("Elemento com maior prioridade com Min Heap: %d\n", FP_inicio(fp, n));
}

int main (int argc, char** argv) {
  int size = 0;
  int max_heap_fp[1000] = {};
  int min_heap_fp[1000] = {};

  // TESTES DA FILA DE PRIORIDADE UTILIZANDO MAX_HEAP
  max_heap_testes(max_heap_fp, size);

  // TESTES DA FILA DE PRIORIDADE UTILIZANDO MIN_HEAP
  min_heap_testes(min_heap_fp, size);

  printf("\n\n");
  return 0;
}
