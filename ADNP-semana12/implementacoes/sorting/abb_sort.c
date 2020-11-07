#include <stdlib.h>
#include "../abb/abb.h"

static void inserir_elementos (ABB **A, int *v, int n) {
  int i;

  for (i = 0; i < n; i++) ABB_Inserir(A, v[i]);
}

static int ABB_Altura_recursivo (ABB *A) {  
  int altura_esquerda;
  int altura_direita;

  if (A->esq == NULL) altura_esquerda = -1;
  
  else altura_esquerda = ABB_Altura_recursivo(A->esq);
  
  if (A->dir == NULL) altura_direita = -1;
  
  else altura_direita = ABB_Altura_recursivo(A->dir);

  return altura_esquerda > altura_direita ? altura_esquerda+1 : altura_direita+1; 
}

static int ABB_Altura (ABB* A) {
  int altura_esquerda, altura_direita;

  int altura = ABB_Altura_recursivo(A);

  return altura;
}

static void ABB_Sort_recursivo (ABB *A, int *v, int *i) {
  if (A == NULL) return;

  ABB_Sort_recursivo(A->esq, v, i);
  v[*i] = A->chave;
  (*i)++;
  ABB_Sort_recursivo(A->dir, v, i);
  
  free(A);
}

int ABB_Sort (int *v, int n) {
  int i, altura;
  ABB *A = NULL;

  i = 0;
  inserir_elementos(&A, v, n);
  altura = ABB_Altura(A);
  ABB_Sort_recursivo(A, v, &i);

  return altura;
}
