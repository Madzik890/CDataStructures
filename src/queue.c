#include "queue.h"

#include <assert.h>
#include <string.h>

Queue *QueueInitalize(const size_t elementSize)
{
    Queue *queue = (Queue *)calloc(1, sizeof(Queue));
    assert(queue);    
    queue->__elementSize = elementSize;    
    return queue;
}

void QueueDeinitalize(Queue *queue)
{           
    while(queue->__size > 0)
    {
        QueuePop(queue);
    }    

    free((void *)queue);    
}

void QueuePush(Queue *queue, void *element)
{
    QueueElement *node = (QueueElement*)malloc(sizeof(QueueElement));
    void *ptr = (void *)malloc(queue->__elementSize);        
    memcpy(ptr, element, queue->__elementSize);
    node->__element = ptr;

    queue->__size++;
    if(queue->__first == NULL)
    {        
        queue->__first = node;
        queue->__last = queue->__first;        
    }
    else
    {
        queue->__last->__nextElement = node;
        queue->__last = node;
    }
}

void QueuePop(Queue *queue)
{    
    if(queue->__size > 0)
    {        
        queue->__size--;
        QueueElement *node = queue->__first;              
        queue->__first = queue->__first->__nextElement;        
        free(node->__element);  
        free(node);        
        if(queue->__size == 0) queue->__first = NULL;
    }
}

const void *QueueFront(const Queue *queue)
{    
    if(queue->__size == 0) return NULL;
    return queue->__first->__element;
}

size_t QueueGetSize(const Queue const *queue)
{
    return queue->__size;
}