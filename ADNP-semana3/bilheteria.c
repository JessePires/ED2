#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// PROTOTIPOS
int obtem_dados (char *caminho, int *M, int *N, int *lugares_por_fileira); // 1 para sucesso, 0 para erro
int soma_vetor (int *lugares_por_fileira, int n);
int valida_dados (int m, int n, int *lugares_por_fileira); // 1 para sucesso, 0 para erro
int esq (int i);
int dir (int i);
void troca (int *lugares_por_fileira, int i, int j);
void min_heapfy (int *lugares_por_fileira, int i, int th);
void build_min_heap (int *lugares_por_fileira, int n);
int FP_remover_minimo(int *lugares_por_fileira, int n); // retorna o tamanho da fila
int realiza_venda (int *lugares_por_fileira, int *M, int *N);
float obtem_lucro (int *lugares_por_fileira, int *M, int *N);

// IMPLEMENTACOES
int obtem_dados (char *caminho, int *M, int *N, int *lugares_por_fileira) {
  FILE *arquivo = fopen(caminho, "r");
  if (arquivo == NULL) return 0;
  
  int i = 0;
  char c[2];
  char string[5];

  fscanf(arquivo, "%d %d", M, N);

  do {
    fscanf(arquivo, "%d", &lugares_por_fileira[i]);
    i++;
  } while (i < *M);

  fclose(arquivo);
  return 1;
}

int soma_vetor (int *lugares_por_fileira, int n) {
  int total = 0;

  for (int i = 0; i < n; i++) {
    total += lugares_por_fileira[i];
  }

  return total;
}

int valida_dados (int m, int n, int *lugares_por_fileira) {
  if (m < 1 || m > 1000) return 0;
  if (n < 1 || n > 1000) return 0;
  if (soma_vetor(lugares_por_fileira, m) < n) return 0;

  for (int i = 0; i < m; i++) {
    if (lugares_por_fileira[i] < 1 || lugares_por_fileira[i] > 1000) return 0;
  }

  return 1;
}

int esq (int i) {
  return 2*i + 1;
}

int dir (int i) {
  return esq(i) + 1;
}

int pai (int i) {
  return (i-1)/2;
}

void troca (int *lugares_por_fileira, int i, int j) {
  int element_in_i = lugares_por_fileira[i];
  lugares_por_fileira[i] = lugares_por_fileira[j];
  lugares_por_fileira[j] = element_in_i;
}

void min_heapfy (int *lugares_por_fileira, int i, int th) {
  int menor = i;
  int e = esq(i);
  int d = dir(i);

  if ((e < th) && (lugares_por_fileira[e] < lugares_por_fileira[i])) {
    menor = e;
  }

  if ((d < th) && (lugares_por_fileira[d] < lugares_por_fileira[menor])) {
    menor = d;
  }

  if (menor != i) {
    troca(lugares_por_fileira, i, menor);
    min_heapfy(lugares_por_fileira, menor, th);
  }
}

void build_min_heap (int *lugares_por_fileira, int n) {
  for (int i = n/2; i >= 0; i--) {
    min_heapfy(lugares_por_fileira, i, n);
  } 
}

int FP_remover_minimo (int *lugares_por_fileira, int n) {
  lugares_por_fileira[0] = lugares_por_fileira[n-1];
  min_heapfy(lugares_por_fileira, 0, n-1);

  return n-1;
}

int realiza_venda (int *lugares_por_fileira, int *M, int *N) {
  float preco = 100 + (100/lugares_por_fileira[0]);
  lugares_por_fileira[0] = lugares_por_fileira[0] - 1;

  if (lugares_por_fileira[0] == 0) {
    *M = FP_remover_minimo(lugares_por_fileira, *M);
  }

  *N -= 1;
  return preco;
}

float obtem_lucro (int *lugares_por_fileira, int *M, int *N) {
  float lucro = 0;

  while (*N > 0) {
    lucro += realiza_venda(lugares_por_fileira, M, N);
  }

  return lucro;
}

int main () {
  clock_t tempo;
  int M;
  int N;
  int lugares_por_fileira[1000] = {};

  tempo = clock();
  obtem_dados("cases/case1.txt", &M, &N, lugares_por_fileira);

  if (valida_dados(M, N, lugares_por_fileira)) {
    build_min_heap(lugares_por_fileira, M);
    printf("Lucro: R$ %.2f\n", obtem_lucro(lugares_por_fileira, &M, &N));
  }
  tempo = clock() - tempo;

  printf("Tempo gasto: %f segundos\n", ((float)tempo)/CLOCKS_PER_SEC);

  return 0;
}
