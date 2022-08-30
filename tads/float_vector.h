
typedef struct float_vector FloatVector; //TAD

FloatVector *create(int tam);
void destroy(FloatVector **ref_vector);
int size(const FloatVector *vector); //danger
int capacity(const FloatVector *vector);
float at(const FloatVector *vector, int pos);//danger
float get(const FloatVector *vector, int endereco);//danger
void append(FloatVector *vector, float n);
void print(const FloatVector *vector);

// --------- PODERIA EXISTIR--------
// bool compare(FloatVector, FloatVector);
// void split(FloatVector, FloatVector);
// void join(FloatVector, FloatVector);
// bool isfull(FloatVector);