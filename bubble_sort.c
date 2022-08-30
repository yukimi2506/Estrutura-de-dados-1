#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"
#include<time.h>

int main()
  {

  int size = 100000, c = 0;
  int *vetor =(int *) malloc(size * sizeof(int));

  while(c < size)
    {
    *(vetor + c) = rand() % 100000;
    c++;
    }

  bubble(vetor, size); 

  free(vetor);
  vetor = NULL;

  return 0;
  }