#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <stdlib.h>
#include <stdint.h>

typedef struct SimpleVector {
    size_t __elementSize;
    size_t __size;
    void **__data;
} SimpleVector;

extern SimpleVector *SimpleVectorInitalize();
extern void SimpleVectorDeinitalize(const SimpleVector *vector);

extern void SimpleVectorPushFront(SimpleVector *vector, void *element);
extern void SimpleVectorPushBack(SimpleVector *vector, void *element);
extern void SimpleVectorInsert(SimpleVector *vector, void *element, const size_t index);

extern void SimpleVectorPopFront(SimpleVector *vector);
extern void SimpleVectorPopBack(SimpleVector *vector);

extern const void *SimpleVectorAt(const SimpleVector *vector, const size_t index);
extern size_t SimpleVectorGetSize(const SimpleVector const *vector);

#define SVectorPushFront(vector, element) \
    SimpleVectorPushFront(vector, (void*)&element)

#define SVectorPushBack(vector, element) \
    SimpleVectorPushBack(vector, (void*)&element)

#define SVectorInsert(vector, element, index) \
    SimpleVectorInsert(vector, (void*)&element, index)

#endif