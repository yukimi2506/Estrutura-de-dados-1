typedef struct DADOS dados;

//bubble//
void swap(int *a, int *b);
void bubble(int *vetor, int size);

//merge//
int mergesort(int *vetor, int inicio, int fim, dados *dado);
void merge(int *vetor, int inicio, int meio, int fim, dados *dado);
void print(int vetor[], int TAM);

//selection//
void selection(int *vetor, int TAM);
void swap(int *a, int *b);
void print(int array[], int TAM);

//quick//
void quicksort(int *vetor, int inicio, int fim, dados *dado);
int quick(int *vetor, int inicio, int fim, dados *dado);
dados *dadosCriar();
void dadosPrint(dados *dado, FILE *arq, float tempo, int size);
void dadosLiberar(dados *dado);

void printvetor(const int *vetor, int size); 

