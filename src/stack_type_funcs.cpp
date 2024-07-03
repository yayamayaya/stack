#include "stack.h"

template<>
void Stack<int>::data_print(FILE *filename, int *data)
{
    if (filename)
        fprintf(filename, "%d\n", *data);
}

template<>
void Stack<char>::data_print(FILE *filename, char * data)
{
    if (filename) 
        fprintf(filename, "%d\n", *data);
}

template<>
void Stack<double>::data_print(FILE *filename, double *data)
{
    if (filename)
        fprintf(filename, "%.2f\n", *data);
}

template<>
void Stack<long long int>::data_print(FILE *filename, long long int *data)
{
    if (filename)
        fprintf(filename, "%lld\n", *data);
}