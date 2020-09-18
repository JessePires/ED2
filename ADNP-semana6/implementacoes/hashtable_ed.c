#include <stdlib.h>
#include <limits.h>

#include "ilist.h"
#include "hashtable_ed.h"

#define VALOR_MAXIMO INT_MAX

int THED_Hash(THED* HT, int chave){
  return chave % HT->m;
}

THED* THED_Criar(int m, int alloc_step){
  THED *nova;
  int i;

  nova = malloc(sizeof(THED));
  nova->m = m;
  nova->t = malloc(sizeof(ILIST*) * m);
    
  for(i = 0; i < m; i++) {
      nova->t[i] = ILIST_Criar(alloc_step);
  }

  return nova;
}

void THED_Inserir(THED* HT, int chave, int valor) {
  int h;

  h = THED_Hash(HT, chave);
  ILIST_Inserir(HT->t[h], chave, valor);
}

void THED_Remover(THED* HT, int chave) {
  int h;

  h = THED_Hash(HT, chave);
  ILIST_Remover(HT->t[h], chave);
}

INOH* THED_Buscar(THED* HT, int chave) {
  int h;
  int pos;

  h = THED_Hash(HT, chave);
  pos = ILIST_Buscar(HT->t[h], chave);
    
  return ILIST_Endereco(HT->t[h], pos);
}

THED* inserir_n_aleatorios (int n, int m, int seed) {
  int i;
  THED* tabela_hash;
  
  tabela_hash = THED_Criar(m, m);
  srand(seed);

  for(i = 0; i < n; i++) {
    int chave_e_valor = rand() % (10 * n);
    THED_Inserir(tabela_hash, chave_e_valor, chave_e_valor);
  }

  return tabela_hash;
}

int THED_mais_longa (THED* TH) {
  int i;
  int maior_tamanho = TH->t[0]->tam;

  for (i = 0; i < TH->m; i++) {
    if (TH->t[i]->tam > maior_tamanho) {
      maior_tamanho = TH->t[i]->tam;
    }
  }

  return maior_tamanho;
}

int THED_mais_curta (THED* TH) {
  int i;
  int menor_tamanho = VALOR_MAXIMO;

  for (i = 0; i < TH->m; i++) {
    if (TH->t[i]->tam < menor_tamanho && TH->t[i]->tam > 0) {
      menor_tamanho = TH->t[i]->tam;
    }
  }

  return menor_tamanho;
}

float THED_tam_medio (THED* TH) {
  int i;
  int soma_tamanhos = 0;

  for (i = 0; i < TH->m; i++) {
    soma_tamanhos += TH->t[i]->tam;
  }

  return soma_tamanhos/TH->m;
}
