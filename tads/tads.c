#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "float_vector.h"


int main(int argc, char *argv[])
{
    FloatVector *vector = create(10);

    append(vector, 1);
    append(vector, 2);
    append(vector, 3);
    append(vector, 4);
    print(vector);

    
    destroy(&vector);


 return 0;   
}