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

     vetor = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        vetor[i] = rand() % 10;
        printf("%d ", vetor[i]);
    }
printf("\n\n");
    mergesort(vetor, 0, 7); 
    print(vetor, size);   
    
    
    fim = clock();

    gasto =  ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %f\n", gasto); 

    free(vetor);
    vetor = NULL;

    return 0;

}


//int main()
//{
  //  int vetor[] = {3, 0, 7, 1, 5, 2, 4, 6};
     
    //print(vetor, 8); 
    //mergesort(vetor, 0, 8 - 1);
    //qprint(vetor, 8);
    
//}///////////////