#pragma once

typedef struct ABB {
  struct ABB* esq;
  struct ABB* dir;
  int chave;
} ABB;

ABB* ABB_Criar (ABB* esq, ABB* dir, int chave);
ABB* ABB_Buscar (ABB* A, int chave);
void ABB_Inserir (ABB** A, int chave);
void ABB_Remover (ABB** A, int chave);
void ABB_Imprimir (ABB* A, int inicio, char direcao);
