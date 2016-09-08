#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
};

typedef struct {
  link maisAntigo;
  link maisNovo;
} * FILA;

link novoNo(int item, link next);
FILA novaFila();
void inserirFinal(FILA f, int e);
void inserirInicio(FILA f, int e);
int removerInicio(FILA f);
int removerFinal(FILA f);
void imprimirFila(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f); 

#endif 
