#include <stdlib.h>
#include <stdio.h>
#include "abb.h"

int main(int argc, char** argv){
  ABB* abb;
  FILE* saida;

  // TESTE 1
  abb = NULL;

  ABB_Inserir(&abb, 70);
  ABB_Inserir(&abb, 39);
  ABB_Inserir(&abb, 88);

  ABB_Remover(&abb, 70);

  saida = fopen("teste1.txt", "w");
  ABB_Salvar_resultado(abb, saida, 0, 'r');
  fclose(saida);

  // TESTE 2
  abb = NULL;

  ABB_Inserir(&abb, 10);
  ABB_Inserir(&abb, 4);
  ABB_Inserir(&abb, 20);
  ABB_Inserir(&abb, 6);
  ABB_Inserir(&abb, 2);
  ABB_Inserir(&abb, 3);
  ABB_Inserir(&abb, 5);
  ABB_Inserir(&abb, 7);

  ABB_Remover(&abb, 10);
  ABB_Remover(&abb, 4);
  ABB_Remover(&abb, 5);

  saida = fopen("teste2.txt", "w");
  ABB_Salvar_resultado(abb, saida, 0, 'r');
  fclose(saida);

  // TESTE 3
  abb = NULL;

  ABB_Inserir(&abb, 30);
  ABB_Inserir(&abb, 50);
  ABB_Inserir(&abb, 40);
  ABB_Inserir(&abb, 47);
  ABB_Inserir(&abb, 15);
  ABB_Inserir(&abb, 20);
  ABB_Inserir(&abb, 25);
  ABB_Inserir(&abb, 17);
  ABB_Inserir(&abb, 19);
  ABB_Inserir(&abb, 4);
  ABB_Inserir(&abb, 7);
  ABB_Inserir(&abb, 0);

  ABB_Remover(&abb, 0);
  ABB_Remover(&abb, 30);
  ABB_Remover(&abb, 15);
  ABB_Remover(&abb, 20);

  saida = fopen("teste3.txt", "w");
  ABB_Salvar_resultado(abb, saida, 0, 'r');
  fclose(saida);

  return 0;
}
