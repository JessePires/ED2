#include <stdlib.h>
#include "../arn/arn.h"

static void inserir_elementos (ARN **A, int *v, int n) {
  int i;

  for (i = 0; i < n; i++) ARN_Inserir(A, v[i], v[i]);
}

static int ARN_Altura_recursivo (ARN *A) {  
  int altura_esquerda;
  int altura_direita;

  if (A->esq == NULL) altura_esquerda = -1;
  
  else altura_esquerda = ARN_Altura_recursivo(A->esq);
  
  if (A->dir == NULL) altura_direita = -1;
  
  else altura_direita = ARN_Altura_recursivo(A->dir);

  return altura_esquerda > altura_direita ? altura_esquerda+1 : altura_direita+1; 
}

static int ARN_Altura (ARN* A) {
  int altura = ARN_Altura_recursivo(A);

  return altura;
}

static void ARN_Sort_recursivo (ARN *A, int *v, int *i) {
  if (A == NULL) return;

  ARN_Sort_recursivo(A->esq, v, i);
  v[*i] = A->chave;
  (*i)++;
  ARN_Sort_recursivo(A->dir, v, i);
  
  free(A);
}

int ARN_Sort (int *v, int n) {
  int i, altura;
  ARN *A = NULL;
  
  i = 0;
  inserir_elementos(&A, v, n);
  altura = ARN_Altura(A);
  ARN_Sort_recursivo(A, v, &i);

  return altura;
}
