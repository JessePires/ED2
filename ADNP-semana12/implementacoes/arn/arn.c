#include <stdlib.h>
#include "arn.h"

static ARN* ARN_Criar (int chave, int valor) {
  ARN* novo = malloc(sizeof(ARN));
  novo->chave = chave;
  novo->valor = valor;
  novo->cor = C_VERMELHO;
  novo->esq = NULL;
  novo->dir = NULL;

  return novo;
}

static inline int eh_vermelho (ARN *A) {
  if (A == NULL) return 0;

  return A->cor == C_VERMELHO ? 1 : 0;
}

static void inverter_cores (ARN *A) {
  A->cor = C_VERMELHO;
  A->esq->cor = C_PRETO;
  A->dir->cor = C_PRETO;
}

static void rotacao_esquerda (ARN **A) {
  ARN *h, *x;

  h = *A;
  x = h->dir;
  h->dir = x->esq;
  x->esq = h;
  x->cor = h->cor;
  h->cor = C_VERMELHO;
  *A = x;
}

static void rotacao_direita (ARN **A) {
  ARN *h, *x;

  h = *A;
  x = h->esq;
  h->esq = x->dir;
  x->dir = h;
  x->cor = h->cor;
  h->cor = C_VERMELHO;
  *A = x;
}

void ARN_Insercao_recursiva (ARN **A, int chave, int valor) {
  if((*A) == NULL) {
    *A = ARN_Criar(chave, valor);
    return;
  }

  if (chave < (*A)->chave) ARN_Insercao_recursiva(&(*A)->esq, chave, valor);

  if (chave > (*A)->chave) ARN_Insercao_recursiva(&(*A)->dir, chave, valor);

  if (eh_vermelho((*A)->dir) && !eh_vermelho((*A)->esq)) rotacao_esquerda(A);

  if (eh_vermelho((*A)->esq) && eh_vermelho((*A)->esq->esq)) rotacao_direita(A);

  if (eh_vermelho((*A)->esq) && eh_vermelho((*A)->dir)) inverter_cores(*A);
}

void ARN_Inserir (ARN **A, int chave, int valor) {
  ARN_Insercao_recursiva (A, chave, valor);
  (*A)->cor = C_PRETO;
}
