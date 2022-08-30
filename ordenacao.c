#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ordenacao.h"

struct DADOS
  {
  int troca;
  int varredura;
  int comparacao;
  }DADOS;

//BUBBLE SORT//
void swap(int *a, int *b)
{
   int aux = *a;
   *a = *b;
   *b = aux;

}

void bubble(int *vetor, int size)
{
    int i, j;
    int troca = 0, varredura = 0, comparacao = 0;

    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < (size - (1 + i)); j++)
        {

        if(vetor[j] > vetor[j + 1])
        {
            swap(&vetor[j], &vetor[j + 1]);
            troca++;
            }
            comparacao++;
        }
        varredura++;
     }
     printf("Qntd de Troca [%d]\n Qntd de comparacao [%d]\n Qntd de varredura [%d]\n", troca, comparacao, varredura);
}


void printvetor(const int *vetor, int size)
{ 
    int i;
    for(i = 0; i < size - 1; i++)
    {
        printf("[%d] ", vetor[i]);
        }
    
}




//MERGE SORT//

int mergesort(int *vetor, int inicio, int fim)
{ 
    int meio;
    
    if(inicio < fim) 
    {
        meio = (inicio + fim) / 2; 
        mergesort(vetor, inicio, meio); //chama a funcao para as 2 metades
        mergesort(vetor, meio + 1, fim);//chama a funcao para as 2 metades
        merge(vetor, inicio, meio, fim); //combina as 2 metades de forma ordenada
    }

  
}

void merge(int *vetor, int inicio, int meio, int fim)
{
    int *comb, v1, v2, tam;
    int i, j, k;
    int fim1 = 0;
    int fim2 = 0;

    v1 = inicio;
    v2 = meio + 1;
    tam = fim - inicio + 1;

    comb = (int *)malloc(tam*sizeof(int));

    if(comb != NULL)
    {
      for(i = 0; i < tam; i++)
      {
        if(!fim1 && !fim2)
        {
            //combinar ordenado
            if(vetor[v1] < vetor[v2])
            comb[i] = vetor[v1++];
            else
                comb[i] = vetor[v2++];

            //se o vetor acabar
            if(v1 > meio) fim1 = 1;
            if(v2 > fim) fim2 = 1;    
        }else{

            //copiar o que sobrou
            if(!fim1)
              comb[i] = vetor[v1++];
            else
              comb[i] = vetor[v2++]; 
            }

      }

      //pegar o dados do vetor comb e colocar de volta no *vetor em forma ordenada
      for(j = 0, k = inicio; j < tam; j ++, k++)
      vetor[k] = comb[j];
    }
    free(comb);
}

void print(int vetor[], int TAM)
{
    int i;

    for(i = 0; i < TAM + 1; i++)
    {
        printf("%d\n", vetor[i]);
        }
      
 }



//SELECTION SORT//

void selection(int vetor[], int TAM)
{
    int i, j;
    int troca = 0, varredura = 0, comparacao = 0;

    for(i = 0; i < TAM; i++)
    {
        int menor = i; //armazenando apenas o indice
        for(j = i; j < TAM; j++) 
        {
            if(vetor[j] < vetor[menor])
            {
                menor = j;
                troca++;
            }
            comparacao++;
        }
        swap(&vetor[i], &vetor[menor]);
        varredura++;
    }
     printf("Qntd de Troca [%d]\n Qntd de comparacao [%d]\n Qntd de varredura [%d]\n", troca, comparacao, varredura);

}
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void print(int array[], int TAM)
{
    int i;
    for(i = 0; i < TAM; i++)
    {
        printf("%d ", array);
        }


 }


//QUICK SORT//

int quick(int *vetor, int inicio, int fim, dados *dado)
  {
  int esq = inicio, dir = fim, pivo = *(vetor + inicio);

//VERIFICACAO DE VETOR JA ORDENADO 
  int c = 0;
  while(*(vetor + c) < *(vetor + c + 1))
    {
    c++;
    if(c == fim)
      return 0;
    }

/*
COMPARACAO COM O PIVO FEITA DA ESQUERDA PARA A DIREITA E DA DIREITA PARA A ESQUERDA
O LADO ESQUERDO RECEBE OS VALORES MENORES OU IGUAIS AO PIVO
O LADO DIREITO VAI RECEBER OS VALORES MAIORES QUE O PIVO
ASSIM A TROCA E FEITA ENTRE AS REFERENCIAS DA ESQUERDA E DA DIREITA
*/
  while(esq < dir)
    {
    while(*(vetor + esq) <= pivo)
    {
    dado->comparacao++;
    esq++;
    }
    
    while(*(vetor + dir) > pivo)
    {
    dado->comparacao++;
    dir--;
    }

    if(esq < dir)
    {
    dado->troca++;
    swap((vetor + dir), (vetor + esq));  
    }
    }

//COLOCA O PIVO ENTRE AS POSICOES DE ESQUERDA E DIREITA, FICANDO ASSIM NA POSICAO CORRETA DO VETOR
//pivo QUE E O INICIO TROCA COM O ULTIMA POSICAO DOS VALORES MENORES QUE ELE('dir')
  *(vetor + inicio) = *(vetor + dir);
  *(vetor + dir) = pivo;
  return dir;
  }

void quicksort(int *vetor, int inicio, int fim, dados *dado)
  {
  if(inicio < fim)
    {
    int pivo = quick(vetor, inicio, fim, dado);
    quicksort(vetor, inicio, pivo - 1, dado);
    quicksort(vetor, pivo + 1, fim, dado);
    }
  }

dados *dadosCriar()
  {
  dados *inf = (dados *)calloc(1, sizeof(dados));
  return inf;
  }

void dadosPrint(dados *dado, FILE *arq, float tempo, int size)
  {
  fprintf(arq,"\n %d ; %f ; %d ; %d ; %d ", size, tempo, dado->troca, dado->comparacao, dado->varredura);
  }

void dadosLiberar(dados *dado)
  {
  free(dado);
  dado=NULL;
  }
  
void printVetor(const int *vetor, int size)
  {
    int n;
  for(n = 0; n < size; n++)
    printf("[%d] ", *(vetor + n));
  }

