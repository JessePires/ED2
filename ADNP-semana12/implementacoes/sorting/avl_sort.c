#include <stdlib.h>
#include "../avl/avl.h"

static void inserir_elementos (AAVL **A, int *v, int n) {
  int i;

  for (i = 0; i < n; i++) AAVL_Inserir(A, v[i], v[i]);
}

static int AVL_Altura_recursivo (AAVL *A) {  
  int altura_esquerda;
  int altura_direita;
  
  if (A->esq == NULL) altura_esquerda = -1;
  
  else altura_esquerda = AVL_Altura_recursivo(A->esq);
  
  if (A->dir == NULL) altura_direita = -1;
  
  else altura_direita = AVL_Altura_recursivo(A->dir);

  return altura_esquerda > altura_direita ? altura_esquerda+1 : altura_direita+1; 
}

static int AVL_Altura (AAVL* A) {
  int altura = AVL_Altura_recursivo(A);

  return altura;
}

static void AVL_Sort_recursivo (AAVL *A, int *v, int *i) {
  if (A == NULL) return;

  AVL_Sort_recursivo(A->esq, v, i);
  v[*i] = A->chave;
  (*i)++;
  AVL_Sort_recursivo(A->dir, v, i);
  
  free(A);
}

int AVL_Sort (int *v, int n) {
  int i, altura;
  AAVL *A = NULL;

  i = 0;
  inserir_elementos(&A, v, n);
  altura = AVL_Altura(A);
  AVL_Sort_recursivo(A, v, &i);

  return altura;
}
