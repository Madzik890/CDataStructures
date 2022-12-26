#include <stdio.h>

#include "../src/simplevector.h"

int main(void)
{    
    SimpleVector *vector = SimpleVectorInitalize(sizeof(int));

    {
        const int xd = 3;
        SVectorPushFront(vector, xd);
    }

    {
        const int xd = 4;
        SVectorPushBack(vector, xd);
    }

    {
        const int xd = 2;
        SVectorPushFront(vector, xd);
    }

    {
        const int xd = 1;
        SVectorPushFront(vector, xd);
    }

    SimpleVectorPopFront(vector);    
    SimpleVectorPopBack(vector);    

    {
        const int xd = 7654;
        SVectorInsert(vector, xd, 1);
    }

    for(int i = 0; i < SimpleVectorGetSize(vector); i++)
    {
        const int *element = (int*)SimpleVectorAt(vector, i);            
        printf("Element %d has value: %d\n", i, *element);
    }
    
    SimpleVectorDeinitalize(vector);
    return 0;
}