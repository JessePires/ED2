#include <stdio.h>
#include <stdlib.h>
#include "hashtable_ea.h"
#include "funcoes_auxiliares.h"

#define DEBUG 0

#define N 10000
#define SEED 42
#define MAX N*10

int main(int argc, char** argv){
  THEA* t;
  int* valores_aleatorios;
  int i;
  int M;

  valores_aleatorios = random_vector(N, MAX, SEED);  

  M = 9973;

  printf("-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 10000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 11987;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 12000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 13999;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 14000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 15991;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 16000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 17989;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 18000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 19997;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 20000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 21997;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 22000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 23993;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 24000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 25999;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 26000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 26997;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 28000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 29989;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);
  M = 30000;

  printf("\n-------------------- M = %d --------------------\n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Fator de carga: %f\n", (float) t->n/t->m);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

  free(t);

  return 0;
}
