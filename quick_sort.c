#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
time_t quick_inicio, quick_final;
float quick_tempo;

dados *quick_info;
quick_info = dadosCriar();

int size = 100000;
int inicio = 0, fim = (size - 1);
int n;

int *vet =(int *)malloc(size * sizeof(int));

for(n = 0; n < size; n++)
  *(vet + n) = rand() % size;

quick_inicio = clock();
quicksort(vet, inicio, fim, quick_info);
quick_final = clock();
quick_tempo = ((float)(quick_final - quick_inicio) / CLOCKS_PER_SEC);

printf("\n(TEMPO DE EXECUCAO): %f(s)\n", quick_tempo);

free(vet);
dadosLiberar(quick_info);


vet = NULL;
return 0;
}