#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

#define AAVL_DEBUG 0

static AAVL* AAVL_Criar(int chave, int dado){
  AAVL* novo;

  novo = malloc(sizeof(AAVL));
  novo->fb = 0;
  novo->dir = NULL;
  novo->esq = NULL;
  novo->dado = dado;
  novo->chave = chave;

  return novo;
}

static void RotDir(AAVL *A){
  AAVL *p, *u, *t;
  
  p = A;
  u = p->esq;
  t = u->dir;
  u->dir = p;
  p->esq = t;

  return;
}

static void RotEsq(AAVL *A){
  AAVL *p, *z, *t;
  
  p = A;
  z = p->dir;
  t = z->esq;
  z->esq = p;
  p->dir = t;

  return;
}

static void CasoE(AAVL **A, int *verificar){
    AAVL *p, *u, *v;
  
  p = *A;
  u = p->esq;

  if(u->fb == 1) {
    #if AAVL_DEBUG
      printf("Caso E, RotDir(p)\n");
    #endif
    // caso E
    RotDir(p);
    *A = u;
    p->fb = 0;
  } else {
    #if AAVL_DEBUG
      printf("Caso E D, RotEsq(u), RotDir(p)\n");
    #endif        
    // caso E D
    v = u->dir;
    RotEsq(u);
    //anteriormente p->esq = u. No entanto, após a rotação, v->esq = u, logo p->esq deve apontar para v.
    p->esq = v; 
        
    RotDir(p);
    //Após a rotação p se torna o filho direito de v e v se torna a nova raíz da subárvore.
    *A = v;
        
    switch(v->fb){
      case -1:
        u->fb = 1;
        p->fb = 0;
        break;

      case 0:
        u->fb = 0;
        p->fb = 0;
        break;

      case 1:
        u->fb = 0;
        p->fb = -1;
        break;
    }
  }
  
  (*A)->fb = 0;
  *verificar = 0;
}

static void CasoD(AAVL **A, int *verificar){
  AAVL *p, *z, *y;
  
  p = *A;
  z = p->dir;

  if(z->fb == -1) {
    #if AAVL_DEBUG
      printf("Caso D, RotEsq(p)\n");
    #endif
    //caso D
    RotEsq(p);
    *A = z;
    p->fb = 0;
  } else {
    #if AAVL_DEBUG
      printf("Caso D E, RotEsq(z), RotDir(p)\n");
    #endif          
    //caso D E
    y = z->esq;
    RotDir(z);

    //anteriormente p->dir = z. No entanto, após a rotação, y->dir = z, logo p->dir deve apontar para y.
    p->dir = y;
    RotEsq(p);

    //Após a rotação p se torna o filho esquerdo de y e y se torna a nova raíz da subárvore.
    *A = y;

    switch(y->fb){
      case -1:
        z->fb = 0;
        p->fb = 1;
        break;
  
      case 0:
        z->fb = 0;
        p->fb = 0;
        break;
      case 1:
        z->fb = -1;
        p->fb = 0;
        break;
    }
  }
  
  (*A)->fb = 0;
  *verificar = 0;
}

static void AAVL_Inserir_R(AAVL **A, int chave, int dado, int *verificar){
  if(*A == NULL) {
    *A = AAVL_Criar(chave, dado);
    *verificar = 1;
    return;
  }

  if(chave == (*A)->chave) {
    (*A)->dado = dado;
    *verificar = 0;
    return;
  }

  if(chave < (*A)->chave){
    AAVL_Inserir_R(&(*A)->esq, chave, dado, verificar);
    if(*verificar){
      switch((*A)->fb){
        case -1:
          (*A)->fb = 0;
          *verificar = 0;
          break;
  
        case 0:
          (*A)->fb = 1;
          break;                    
  
        case 1:
          CasoE(A, verificar);
          break;
      }
    }
  } else {
    AAVL_Inserir_R(&(*A)->dir, chave, dado, verificar);

    if(*verificar){
      switch((*A)->fb){
        case -1:
          CasoD(A, verificar);                    
          break;
  
        case 0:
          (*A)->fb = -1;
          break;                    
                
        case 1:
          (*A)->fb = 0;
          *verificar = 0;
          break;
      }
    }
  }
}

void AAVL_Inserir(AAVL** A, int chave, int dado){
  int verificar = 0;
  AAVL_Inserir_R(A, chave, dado, &verificar);
}

static void AAVL_Imprimir_R(AAVL *A, int nivel, char lado){
  int i;
  
  if(A == NULL) return;
  
  for(i = 0 ; i < nivel; i++) printf(" ");
  
  printf("(%c) %d [%d]\n", lado, A->chave, A->fb);
  AAVL_Imprimir_R(A->esq, nivel+1, 'e');
  AAVL_Imprimir_R(A->dir, nivel+1, 'd');
}

void AAVL_Imprimir(AAVL *A){
  AAVL_Imprimir_R(A, 0, 'r');
}


static int AAVL_GenDOT_R(AAVL *A, FILE* saida, int *id){
  int e, d, me;

  if(A == NULL) return 0;

  e = AAVL_GenDOT_R(A->esq, saida, id);
  d = AAVL_GenDOT_R(A->dir, saida, id);
  me = (*id)++;

  fprintf(saida, "%d [label=\"%d\n(%d)\"];\n", me, A->chave, A->fb);

  if(e || d){
    if(e) fprintf(saida, "%d -> %d [label=\"esq\"];\n", me, e);
    if(d) fprintf(saida, "%d -> %d [label=\"dir\"];\n", me, d);
  }

  return me;
}

void AAVL_GenDOT(AAVL *A, const char* arq_saida){
  FILE* saida;
  int id = 1;

  saida = fopen(arq_saida, "w");
  fprintf(saida, "digraph G {\n");
  AAVL_GenDOT_R(A, saida, &id);
  fprintf(saida, "}\n");
  fclose(saida);
}
