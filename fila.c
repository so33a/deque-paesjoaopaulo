#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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
    link novono = novoNo(e, NULL);
    novono->next = f->maisAntigo;
    f->maisAntigo->next = novono;
    f->maisAntigo = f->maisAntigo->next;
  }
}

int removerInicio(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisAntigo->item;
  t = f->maisAntigo;
  f->maisAntigo = f->maisAntigo->next;
 
  if(f->maisAntigo == NULL)
    f->maisNovo = NULL;

  free(t);
  return x;
}

int removerFinal(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisNovo->item;
  t = f->maisNovo;
  f->maisNovo = f->maisNovo->next;
 
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
  for(t = f->maisAntigo; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}

void destroiFila(FILA f) {
  while (!filaVazia(f))
    removerFinal(f);
  free(f);
}

