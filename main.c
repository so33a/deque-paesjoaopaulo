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

  printf ("removido final': %d \n", removerFinal(alunos));
  printf ("removido final': %d \n", removerFinal(alunos));
  while(!filaVazia(alunos))
    printf ("remove inicio: %d \n", removerInicio(alunos));


  imprimirFila(alunos);
  
  inserirFinal(alunos, 10);
  inserirFinal(alunos, 32);
  inserirInicio(alunos, 35);
  inserirFinal(alunos, 38);
  
  imprimirFila(alunos);

  destroiFila(alunos);
  return 0;
}
