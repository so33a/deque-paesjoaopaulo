#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int i = 0;

link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisNovo = f->maisAntigo = NULL;
  return f;
}

void inserirFinal(FILA f, int e) {
  if(f->maisAntigo == NULL) {
    f->maisAntigo = f->maisNovo = novoNo(e, NULL);
  } else {
    f->maisNovo->next = novoNo(e, NULL);
    f->maisNovo = f->maisNovo->next;
  }
}

void inserirInicio(FILA f, int e) {
  if(f->maisNovo == NULL) {
    f->maisNovo = f->maisAntigo = novoNo(e, NULL);
  } else {
    f->maisAntigo = novoNo(e, f->maisAntigo);
  }
}

int removerInicio(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia.\n");
    return 0;
  }
  x = f->maisAntigo->item;
  t = f->maisAntigo;
  f->maisAntigo = t->next;
 
  if(f->maisAntigo == NULL)
    f->maisNovo = NULL;

  free(t);
  return x;
}

int removerFinal(FILA f){
  int x;
  link t;
  
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia.\n");
    return 0;
  }
  
  t = f->maisNovo;
  link atual = f->maisAntigo;
  while(atual->next != t){
    atual = atual->next;
  }
  x = atual->next->item;
  atual->next = NULL;
  f->maisNovo = atual;
 
  if(f->maisNovo == NULL)
    f->maisAntigo = NULL;

  free(t);
  return x;
}

int filaVazia(FILA f) {
  return ((f->maisNovo == NULL) || (f->maisAntigo == NULL));
}

void imprimirFila(FILA f) {
  link t;
  if(!filaVazia(f)){
    for(t = f->maisAntigo; t != NULL; t = t->next) 
      printf ("%d ", t->item);
    printf ("\n");

  } else {
    printf ("FILA VAZIA::\n");
  }
}

void destroiFila(FILA f) {
  while (!filaVazia(f))
    removerInicio(f);
  free(f);
}

