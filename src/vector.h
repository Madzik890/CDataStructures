#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdint.h>

typedef struct Vector {
    size_t __elementSize;
    size_t __size;
    void **__data;
} Vector;

extern Vector *VectorInitalize(const size_t elementSize);
extern void VectorDeinitalize(Vector *vector);

extern void VectorPushFront(Vector *vector, void *element);
extern void VectorPushBack(Vector *vector, void *element);
extern void VectorInsert(Vector *vector, void *element, const size_t index);

extern void VectorPopFront(Vector *vector);
extern void VectorPopBack(Vector *vector);

extern const void *VectorAt(const Vector *vector, const size_t index);
extern size_t VectorGetSize(const Vector *vector);

#define SVectorPushFront(vector, element) \
    VectorPushFront(vector, (void*)&element)

#define SVectorPushBack(vector, element) \
    VectorPushBack(vector, (void*)&element)

#define SVectorInsert(vector, element, index) \
    VectorInsert(vector, (void*)&element, index)

#endif