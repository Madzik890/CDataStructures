#include "simplevector.h"

#include <assert.h>
#include <string.h>

SimpleVector *SimpleVectorInitalize(const size_t elementSize)
{
    SimpleVector *vector = (SimpleVector *)calloc(1, sizeof(SimpleVector));
    assert(vector);    
    vector->__elementSize = elementSize;
    vector->__data = calloc(0, elementSize);
    return vector;
}

void SimpleVectorDeinitalize(const SimpleVector *vector)
{    
    for(size_t i = 0; i < vector->__size; i++)
       free((void*)vector->__data[i]);
    free((void *)vector->__data);
    free((void *)vector);
}

void SimpleVectorPushFront(SimpleVector *vector, void *element)
{
    vector->__data = (void**)realloc(vector->__data, ++vector->__size * sizeof(void*));
    memcpy(vector->__data + 1, vector->__data, (vector->__size - 1) * sizeof(void*));
    vector->__data[0] = (void *)malloc(vector->__elementSize);
    memcpy(vector->__data[0], element, vector->__elementSize);
}

void SimpleVectorPushBack(SimpleVector *vector, void *element)
{
    vector->__data = (void**)realloc(vector->__data, ++vector->__size * sizeof(void*));
    vector->__data[vector->__size - 1] = (void *)malloc(vector->__elementSize);
    memcpy(vector->__data[vector->__size - 1], element, vector->__elementSize);
}

void SimpleVectorInsert(SimpleVector *vector, void *element, const size_t index)
{
    vector->__data = (void**)realloc(vector->__data, ++vector->__size * sizeof(void*));
    memcpy(vector->__data + index, vector->__data + index - 1, (vector->__size - index) * sizeof(void*));
    vector->__data[index] = (void *)malloc(vector->__elementSize);
    memcpy(vector->__data[index], element, vector->__elementSize);
}

void SimpleVectorPopFront(SimpleVector *vector)
{
    assert(vector->__size > 0);

    void **ptr = (void**)malloc((vector->__size - 1) * sizeof(void*));
    memcpy(ptr, vector->__data + 1, --vector->__size * sizeof(void*));
    free((void *)vector->__data[0]);
    free((void *)vector->__data);
    vector->__data = ptr;        
}

void SimpleVectorPopBack(SimpleVector *vector)
{
    assert(vector->__size > 0);

    free(vector->__data[vector->__size - 1]);    
    vector->__data = (void**)realloc(vector->__data, --vector->__size * sizeof(void*));        
}

const void *SimpleVectorAt(const SimpleVector *vector, const size_t index)
{
    return index >= vector->__size && index < 0 ? NULL : vector->__data[index];
}

size_t SimpleVectorGetSize(const SimpleVector const *vector)
{
    return vector->__size;
}