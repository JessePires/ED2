#include <stdlib.h>
#include "hashtable_ea.h"

int THEA_Hash (THEA* TH, int chave, int k) {
  return ((chave % TH->m) + k) % TH->m;
}

THEA* THEA_Criar (int m) {
  THEA* nova_thea;
  int i;

  nova_thea = (THEA*) malloc(sizeof(THEA));
  nova_thea->TH = (ELEMENTO*) malloc(sizeof(ELEMENTO) * m);
  nova_thea->m = m;
  nova_thea->n = 0;
  
  for (i = 0; i < m; i++) {
    nova_thea->TH[i].estado = E_LIVRE;
  }

  return nova_thea;
}

int THEA_Inserir (THEA* TH, int chave, int valor) {
  int h, h_inicial, k;

  k = 0;
  h = THEA_Hash(TH, chave, k);
  h_inicial = h;

  while (TH->TH[h].estado == E_OCUPADO) {
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
    if (TH->TH[h].estado == E_OCUPADO && TH->TH[h].chave == chave) {
      return h;
    }

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

int THEA_ClusterMaximo (THEA* TH) {
  int i;
  int maior_cluster;
  int cluster_atual;

  maior_cluster = 0;
  cluster_atual = 0;

  for (i = 0; i < TH->m; i++) {
    if (TH->TH[i].estado != E_OCUPADO) {
      if (cluster_atual > maior_cluster) {
        maior_cluster = cluster_atual;
      }

      cluster_atual = 0;
    }

    cluster_atual++;
  }

  return maior_cluster;
}

float THEA_TamMedioClusters (THEA* TH) {
  int i;
  float soma_tamanho_clusters = 0;
  int qtd_clusters = 0;

  for (i = 0; i < TH->m; i++) {
    if (TH->TH[i].estado != E_OCUPADO) {
      if (TH->TH[i-1].estado == E_OCUPADO) {
        qtd_clusters++;
      }
    } else {
      soma_tamanho_clusters++;
    }
  }

  return soma_tamanho_clusters/qtd_clusters;
}

int* tamanhos_clusters (THEA* TH, int *t) {
  int i;
  int* tamanhos;
  
  *t = 0;
  tamanhos = (int*) calloc(*t+1, sizeof(int));

  for (i = 0; i < TH->m; i++) {
    if (TH->TH[i].estado != E_OCUPADO) {
      if (TH->TH[i-1].estado == E_OCUPADO) {
        *t += 1;
        tamanhos = realloc(tamanhos, (*t+1) * sizeof(int));
        tamanhos[*t] = 0;
      }
    }else {
      tamanhos[*t] += 1;
    }
  }
  
  return tamanhos;
}

float THEA_CustoBemSucedida (THEA* TH) {
  int i, t;
  int* tamanhos;
  float custo_bem_sucedida;

  #define MAX(x, y) (x > y) ? x : y

  tamanhos = tamanhos_clusters(TH, &t);
  custo_bem_sucedida = 0;

  for (i = 0; i < t; i++) {
    custo_bem_sucedida += (MAX(((float)tamanhos[i]/2), 1))/TH->n;
  }

  free(tamanhos);

  return custo_bem_sucedida;
}
