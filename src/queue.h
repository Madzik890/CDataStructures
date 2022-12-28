#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdint.h>

typedef struct QueueElement {
    struct QueueElement *__nextElement;
    void *__element;
} QueueElement;

typedef struct Queue {
    size_t __elementSize;
    size_t __size;
    QueueElement *__first;    
    QueueElement *__last;    
} Queue;

extern Queue *QueueInitalize(const size_t elementSize);
extern void QueueDeinitalize(Queue *queue);

extern void QueuePush(Queue *queue, void *element);
extern void QueuePop(Queue *queue);

extern const void *QueueFront(const Queue *queue);

extern size_t QueueGetSize(const Queue *queue);

#define SQueuePush(queue, element) \
    QueuePush(queue, (void*)&element)

#endif