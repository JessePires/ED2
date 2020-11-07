#pragma once

#include "prime_list.h"

typedef enum ESTADO {
  E_LIVRE,
  E_OCUPADO,
  E_APAGADO,
} ESTADO;

typedef enum PROBING {
  P_LINEAR,
  P_QUADRATICA,
  P_DUPLA
} PROBING;

typedef struct ELEMENTO {
  int chave;
  int valor;
  ESTADO estado;
} ELEMENTO;


typedef struct THEA {
  int m;
  int n;
  int colisoes;
  prime_list_t* prime_list;
  PROBING probing;
  int (*funcao_de_probing)(int, int, int);
  ELEMENTO* TH;
} THEA; 

int THEA_HASH (THEA* TH, int chave, int k);
THEA* THEA_Criar (int m, const char* nome_arquivo, PROBING probing);
int THEA_Inserir (THEA* TH, int chave, int valor);
int THEA_Buscar (THEA* TH, int chave);
int THEA_Remover (THEA* TH, int chave);
