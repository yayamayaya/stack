#include "stack.h"

#ifndef STACK_INT_FUNC
#define STACK_INT_FUNC

template <typename T>
canary_t *Stack<T>:: get_left_canary_ptr()
{
    return (canary_t *)data;
}

template <typename T>
canary_t *Stack<T>:: get_right_canary_ptr()
{
    return (canary_t *)((char *)data + sizeof(canary_t) + sizeof(hash_t) + capacity * sizeof(T));
}

template <typename T>
hash_t *Stack<T>:: get_hash_number_ptr()
{
    return (hash_t *)((char *)data + sizeof(canary_t));
}

template <typename T>
hash_t Stack<T>::hash_func()
{
    hash_t hash_holder = 0;
    char *data_ptr = (char *)get_data_ptr();
    for (unsigned int i = 0; i < size * sizeof(T); i++)
        hash_holder += data_ptr[i];

    hash_holder += capacity;
    hash_holder += size;
    
    return hash_holder;
}

template <typename T>
int Stack<T>::poison_func(const int pos)
{   
    char *arr_ptr = (char *)get_data_ptr();
    for (unsigned int i = pos * sizeof(T); i < capacity * sizeof(T); i++)
        arr_ptr[i] = poison;

    return 0;
}

template <typename T>
int Stack<T>::poison_check()
{
    unsigned char *arr_ptr = (unsigned char *)get_data_ptr();
    for (unsigned int pos = size * sizeof(T); pos < capacity * sizeof(T); pos++)
        if (arr_ptr[pos] != poison)
            return PSN_ERR;

    return 0;
}

template <typename T>
int Stack<T>::canary_check()
{
    if (*(get_left_canary_ptr()) != lcanary || *(get_right_canary_ptr()) != rcanary)
        return CANARY_ERR;
        
    return 0;
}

template <typename T>
int Stack<T>::hash_check()
{
    if (*(get_hash_number_ptr()) != hash_func())
        return HASH_ERR;

    return 0;
}

template <typename T>
int Stack<T>::verificator()
{
    if (capacity == 0)
    {
        _STACK_LOG("[stack error]>>> Capacity can't be zero\n");
        printf("[stack error]>>> Capacity can't be zero, check whether the stack was constructed\n");
        return CAPACITY_ZERO;
    }
#ifdef SECURE
    if (poison_check())
    {
        _STACK_LOG("[stack error]>>> Number in array is not poison\n");
        return PSN_ERR;
    }
    if (canary_check())
    {
        _STACK_LOG("[stack error]>>> Canary is damaged\n");
        return CANARY_ERR;
    }
    if (hash_check())
    {
        _STACK_LOG("[stack error]>>> Hash is not matching.\n");
        return HASH_ERR;
    }
    if (class_lcanary != c_left_canary || class_rcanary != c_right_canary)
    {
        _STACK_LOG("[stack error]>>> Class canary is damaged\n");
        return CANARY_ERR;
    }
#endif  
    return 0;
}

template<typename T>
void Stack<T>::bin_print(FILE *filename, void *data_ptr, const int type_size)
{
    char *data = (char *)data_ptr;

    fprintf(filename, "> 0b ");
    for (int byte_num = 0; byte_num < type_size; byte_num++)
    {
        for (int i = 0; i < 8; i++)
        {
            fprintf(filename, "%d", (data[byte_num] >> i & 0x01 ? 1 : 0));
            if (!((i + 1) % 4))
                fprintf(filename, " ");
        }
        fprintf(filename, "  ");
    }
    fprintf(filename, "\n");
}

template<typename T>
void Stack<T>::data_print(FILE *filename, T *data)
{
    if (filename)
        bin_print(filename, data, sizeof(T));
}

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

#endif