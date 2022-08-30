#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"ordenacao.h"

int main()
{
time_t merge_ini, merge_fim;
float merge_tempo;

dados *merge;
merge = dadosCriar();

int g, size = 1000000;
int inicio = 0, fim = (size - 1);

int *merge_vetor =(int *)malloc(size * sizeof(int));

for(g=0; g < size; g++)
  *(merge_vetor + g) = rand() % size;

merge_ini = clock();
mergesort(merge_vetor, inicio, fim, merge);
merge_fim = clock();
merge_tempo = ((float)(merge_fim - merge_ini) / CLOCKS_PER_SEC);

printf("\n(TEMPO DE EXECUCAO): %f(s)\n", merge_tempo);

free(merge_vetor);
dadosLiberar(merge);

merge_vetor = NULL;

return 0;
}