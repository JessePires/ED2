#include <stdio.h>
#include <stdlib.h>
#include "hashtable_ea.h"

int main(int argc, char** argv){
  THEA* t;
  int seed, n, chave, i; 
  PROBING probing;

  seed = 42;
  n = argc > 1 ? atoi(argv[1]) : 100;
  probing = argc > 2 ? atoi(argv[2]) : P_LINEAR;

  srand(seed);

  t = THEA_Criar(5, "primes1.dat", probing);

  for(i = 0; i < n; i++){
    chave = (rand() % (n*10));
    THEA_Inserir(t, chave, chave + (rand() % 10));
  }

  printf("Qtde. de colisões: %d\n", t->colisoes);

  return 0;
}
