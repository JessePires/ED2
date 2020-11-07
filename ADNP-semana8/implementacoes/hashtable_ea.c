#include <stdlib.h>
#include <math.h>
#include "hashtable_ea.h"

static void THEA_Redimensionar (THEA* TH, int m_novo) {
  ELEMENTO* nova;
  ELEMENTO* antiga;
  int i, m_antigo, ultimo_primo;

  ultimo_primo = TH->prime_list->PL[(TH->prime_list->n)-1];

  if (m_novo < ultimo_primo) {
    m_novo = PL_NextPrime(TH->prime_list, m_novo); 
  }

  nova = malloc(sizeof(ELEMENTO) * m_novo);
  
  for (i = 0; i < m_novo; i++) {
    nova[i].estado = E_LIVRE;
  }

  antiga = TH->TH;
  m_antigo = TH->m;
  TH->TH = nova;
  TH->m = m_novo;
  TH->n = 0;
  TH->colisoes = 0;

  for (i = 0; i < m_antigo; i++) {
    if (antiga[i].estado == E_OCUPADO) {
      THEA_Inserir(TH, antiga[i].chave, antiga[i].valor);
    }
  }

  free(antiga);
}

int probing_linear (int m, int chave, int k) {
  return k;
}

int probing_quadratica (int m, int chave, int k) {
  return pow(k, 2);
}

int probing_dupla (int m, int chave, int k) {
  return (k * ((chave % (m - 1)) + 1));
}

int THEA_Hash (THEA* TH, int chave, int k) {
  return ((chave % TH->m) + TH->funcao_de_probing(TH->m, chave, k)) % TH->m;
}

THEA* THEA_Criar (int m, const char* nome_arquivo, PROBING probing) {
  prime_list_t* lista_primos;
  THEA* nova_thea;
  int m_primo, i;

  lista_primos = PL_Load(nome_arquivo);
  m_primo = PL_NextPrime(lista_primos, m);
  nova_thea = malloc(sizeof(THEA));
  nova_thea->TH = malloc(sizeof(ELEMENTO) * m_primo);
  nova_thea->m = m_primo;
  nova_thea->n = 0;
  nova_thea->colisoes = 0;
  nova_thea->prime_list = lista_primos;

  for (i = 0; i < m_primo; i++) {
    nova_thea->TH[i].estado = E_LIVRE;
  }

  if (probing == P_LINEAR) {
    nova_thea->funcao_de_probing = probing_linear;
  }else if (probing == P_QUADRATICA) {
    nova_thea->funcao_de_probing = probing_quadratica;
  }else if (probing == P_DUPLA) {
    nova_thea->funcao_de_probing = probing_dupla;
  }

  return nova_thea;
}

int THEA_Inserir (THEA* TH, int chave, int valor) {
  int h, h_inicial, k;

  if (TH->n >= (TH->m / 2)) THEA_Redimensionar(TH, TH->m*2);

  k = 0;
  h = THEA_Hash(TH, chave, k);
  h_inicial = h;

  while (TH->TH[h].estado == E_OCUPADO) {
    TH->colisoes++;

    if (TH->TH[h].chave == chave) break;
    
    k++;
    h = THEA_Hash(TH, chave, k);

    if (h == h_inicial) return -1;
  }

  TH->n += TH->TH[h].chave == chave ? 0 : 1;
  TH->TH[h].chave = chave;
  TH->TH[h].valor = valor;
  TH->TH[h].estado = E_OCUPADO;

  return h;
}

int THEA_Buscar (THEA* TH, int chave) {
  int h, h_inicial, k;

  k = 0;
  h = THEA_Hash(TH, chave, k);
  h_inicial = h;
  
  while (TH->TH[h].estado != E_LIVRE) {
    if (TH->TH[h].estado == E_OCUPADO && TH->TH[h].chave == chave) return h;

    k++;
    h = THEA_Hash(TH, chave, k);
    
    if (h_inicial == h) return -1;
  }

  return -1;
}

int THEA_Remover (THEA* TH, int chave) {
  int posicao_elemento;

  posicao_elemento = THEA_Buscar(TH, chave);

  if (posicao_elemento == -1) return -1;
  
  TH->TH[posicao_elemento].estado = E_APAGADO;
  TH->n -= 1;

  return posicao_elemento;
}
