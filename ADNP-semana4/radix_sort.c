#include <stdlib.h>
#include <string.h>
#include "funcoes_auxiliares.h"

void counting_sort_base_dois (int *v, int n, int posicao, int *temp) {
  int i, t;
  int acum = 0;
  int base = 2;
  int c[base];
  
  memset(c, 0, base *sizeof(int));

  #define DIGIT(X) (X >> posicao) & 1

  for (i = 0; i < n; i++) {
    c[DIGIT(v[i])]++;
  }

  for (i = 0; i < base; i++) {
    t = c[i];
    c[i] = acum;
    acum += t;
  }

  for (i = 0; i < n; i++) {
    temp[c[DIGIT(v[i])]] = v[i];
    c[DIGIT(v[i])]++;
  }

  memcpy(v, temp, sizeof(int) * n);
}

void counting_sort (int *v, int n, int div, int base, int *temp) {
  int i, t;
  int c[base];
  int acum = 0;
  
  memset(c, 0, base *sizeof(int));

  #define DIGIT(X) (X / div) % base

  for (i = 0; i < n; i++) {
    c[DIGIT(v[i])]++;
  }

  for (i = 0; i < base; i++) {
    t = c[i];
    c[i] = acum;
    acum += t;
  }

  for (i = 0; i < n; i++) {
    temp[c[DIGIT(v[i])]] = v[i];
    c[DIGIT(v[i])]++;
  }

  memcpy(v, temp, sizeof(int) * n);
}

void radix_sort (int *v, int n, int base) {
  int k;
  int div = 1;

  k = max(v, n);
  int *temp = malloc(sizeof(int) * n);

  while (k > 0) {
    counting_sort(v, n, div, base, temp);
  
    div *= base;
    k /= base;
  }
  
  free(temp);
}

void radix_sort_base_dois (int *v, int n) {
  int k;
  int posicao = 0;

  k = max(v, n);
  int *temp = malloc(sizeof(int) * n);

  while (k > 0) {
    counting_sort_base_dois(v, n, posicao, temp);
    posicao += 1;
    k /= 2;
  }
  
  free(temp);
}
