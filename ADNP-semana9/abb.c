#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

ABB* ABB_Criar (ABB* esq, ABB* dir, int chave) {
  ABB* novo;

  novo = malloc(sizeof(ABB));
  novo->chave = chave;
  novo->esq = esq;
  novo->dir = dir;

  return novo;
}

ABB* ABB_Buscar (ABB* A, int chave) {
  if (A == NULL) return NULL;

  if (chave == A->chave) return A;
  
  if (chave < A->chave) return ABB_Buscar(A->esq, chave);
  
  return ABB_Buscar(A->dir, chave);
}

void ABB_Inserir (ABB** A, int chave) {
  if ((*A) == NULL) {
    *A = ABB_Criar(NULL, NULL, chave);
    return;
  } else {
    if (chave < (*A)->chave) {
      ABB_Inserir(&(*A)->esq, chave);
    } else {
      ABB_Inserir(&(*A)->dir, chave);
    }
  }
}

static void ABB_remover_folha (ABB* pai, ABB* noh) {
  if (pai->esq == noh) {
    pai->esq = NULL;
  }else {
    pai->dir = NULL;
  }

  free(noh);
}

static void ABB_remover_com_um_filho (ABB** A, ABB* pai, ABB* noh) {  
  if (pai->chave > noh->chave) {
    pai->esq = noh->dir != NULL ? noh->dir : noh->esq;
  }else {
    if (noh->dir != NULL) {
      if (pai == noh) {
        (*A) = noh->dir;  
      } else {
        pai->dir = noh->dir;
      }
    }else {
      if (pai == noh) {
        (*A) = noh->esq;
      }else {
        pai->dir = noh->esq;
      }
    }
  }

  free(noh);
}

static void ABB_remover_com_dois_filhos (ABB** A, ABB* noh) {
  ABB* pai_sucessor;
  ABB* sucessor;

  pai_sucessor = noh;
  sucessor = noh->dir;

  while (sucessor->esq != NULL) {
    pai_sucessor = sucessor;
    sucessor = sucessor->esq;
  }

  noh->chave = sucessor->chave;

  if (sucessor->dir == NULL && sucessor->esq == NULL) {
    ABB_remover_folha(pai_sucessor, sucessor);
  }else {
    ABB_remover_com_um_filho(A, pai_sucessor, sucessor);
  }
}

void ABB_Remover (ABB** A, int chave) {
  ABB* pai;
  ABB* noh;

  if ((*A) == NULL) return;
  if (!ABB_Buscar(*A, chave)) return;

  pai = *A;
  
  if(pai->chave == chave) {
    noh = *A;
  }else{
    while (noh->chave != chave) {
      pai = noh;
      noh = chave > noh->chave ? noh->dir : noh->esq;
    }
  }

   if (noh->esq == NULL && noh->dir == NULL) {
    ABB_remover_folha(pai, noh);
  }else if (noh->dir != NULL && noh->esq != NULL) {
    ABB_remover_com_dois_filhos(A, noh);
  } else {
    ABB_remover_com_um_filho(A, pai, noh);
  }
}

void ABB_Imprimir (ABB* A, int inicio, char direcao) {
  int i;
  
  if (A == NULL) return;

  for(i = 0; i < inicio; i++){
    printf("\t");
  }
  printf("(%c) %d\n", direcao, A->chave);

  ABB_Imprimir(A->esq, inicio+1, 'e');
  ABB_Imprimir(A->dir, inicio+1, 'd');
}

void ABB_Salvar_resultado (ABB* A, FILE* resultado, int inicio, char direcao) {
  int i;

  if (A == NULL) return;

  for (i = 0; i < inicio; i++) {
    fputc('\t', resultado);
  }
  fprintf(resultado, "(%c) %d\n", direcao, A->chave);

  ABB_Salvar_resultado(A->esq, resultado, inicio+1, 'e');
  ABB_Salvar_resultado(A->dir, resultado, inicio+1, 'd');
}
