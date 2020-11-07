#pragma once

typedef enum {
  C_VERMELHO,
  C_PRETO
} ARN_COR;

typedef struct ARN {
  struct ARN *esq;
  struct ARN *dir;
  int chave;
  int valor;
  ARN_COR cor;
} ARN;

void ARN_Inserir (ARN **A, int chave, int valor);
