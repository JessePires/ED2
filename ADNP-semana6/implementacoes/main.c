#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"
#include "hashtable_ed.h"

#define DEBUG 0

int main(int argc, char** argv){
  int i;
  int m = 499;
  int n = 50000;
  int seed = 42;

  THED* tabela_hash_n_aleatorios = inserir_n_aleatorios(n, m, seed);

  #if DEBUG
  for (i = 0; i < tabela_hash_n_aleatorios->m; i++) {
      printf("%d: ", i);
      ILIST_Imprimir(tabela_hash_n_aleatorios->t[i], 1);
  }
  #endif

  printf("Maior tamanho: %d\n", THED_mais_longa(tabela_hash_n_aleatorios));
  printf("Menor tamanho: %d\n", THED_mais_curta(tabela_hash_n_aleatorios));
  printf("Tamanho médio das listas: %f\n", THED_tam_medio(tabela_hash_n_aleatorios));

  return 0;
}
