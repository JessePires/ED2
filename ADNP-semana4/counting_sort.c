#include <stdlib.h>
#include <string.h>

typedef struct Info {
  int chave;
  int dado;
} Info;

int max (Info *v, int n) {
  int i, maior_elemento = 0;

  for (i = 0; i < n; i++) {
    if (v[i].chave > maior_elemento) {
      maior_elemento = v[i].chave;
    }
  }

  return maior_elemento;
}

void counting_sort (Info *v, int n) {
  int k, i, j, t;
  int *s, *c;
  int acum = 0;

  k = max(v, n);
  c = calloc(k + 1, sizeof(int));
  s = malloc(n * sizeof(Info));

  for (j = 0; j < n; j++) {
    c[v[j].chave]++;
  }

  for (i = 0; i <= k; i++) {
    t = c[i];
    c[i] = acum;
    acum += t;
  }

  for (i = 0; i < n; i++) {
    s[c[v[i].chave]] = v[i].dado;
    c[v[i].chave]++;
  }

  memcpy(v, s, sizeof(Info) * n);
  free(s);
  free(c);
}
