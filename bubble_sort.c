//quantidade de troca, comparações, varreduras e tempo de execução;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "ordenacao.h" 

int main()
{
    clock_t inicio, fim;
    double gasto;

    inicio = clock();

    int i; 
    int size = 8;
    int *vetor;

    vetor = (int *) malloc(size *sizeof(int)); 

    for (i = 0; i < size; i++)
    {
        vetor[i] = rand() % 10;
    }

    bubble(vetor, size);    
    
    printvetor(vetor, size);
    
    fim = clock();

    gasto =  ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %f\n", gasto); 

     free(vetor);
     vetor = NULL;

    return 0;
}