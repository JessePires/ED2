#include <stdio.h>
#include <stdlib.h>
#include "hashtable_ea.h"

int* random_vector (int n, int max, int seed) {
  int i;
  int* vetor; 
  
  vetor = malloc(sizeof(int) * n);
  srand(seed);

  for (i = 0; i < n; i++) {
    vetor[i] = rand() % max;
  }

  return vetor;
}

void THEA_Print (THEA* TH) {
  int i;
  
  for (i = 0; i < TH->m; i++) {
    const char e = TH->TH[i].estado == E_OCUPADO ? 'O'
      : (TH->TH[i].estado == E_LIVRE ? 'L' : 'A');
    
    printf("%d: %d, %c\n", i, TH->TH[i].chave, e);
  }
}
