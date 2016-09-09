#include <stdio.h>
#include "fila.h"


int main () {
  FILA alunos = novaFila();
  inserirInicio(alunos, 11);
  inserirInicio(alunos, 9);
  inserirFinal(alunos, 8);
  inserirInicio(alunos, 3);
  inserirFinal(alunos, 10);

  imprimirFila(alunos);

  while(!filaVazia(alunos))
    printf ("removido: %d \n", removerInicio(alunos));


  inserirFinal(alunos, 10);
  inserirFinal(alunos, 32);
  
  imprimirFila(alunos);

  destroiFila(alunos);
  return 0;
}
