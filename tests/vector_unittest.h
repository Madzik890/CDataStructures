#ifndef DEQUE_UNITTEST_H
#define DEQUE_UNITTEST_H
    
#include <boost/test/unit_test.hpp>
#include <iostream>
extern "C" {
#include "../src/vector.h"
}

BOOST_AUTO_TEST_CASE( VectorTest )
{
    Vector *vector = VectorInitalize(sizeof(int));

    {
        const int xd = 3;
        SVectorPushFront(vector, xd);
    }

    {
        const int xd = 4;
        SVectorPushFront(vector, xd);
    }

    {
        const int xd = 2;
        SVectorPushFront(vector, xd);
    }

    {
        const int xd = 1;
        SVectorPushFront(vector, xd);
    }

    VectorPopFront(vector);    
    VectorPopBack(vector);    

    {
        const int xd = 7654;
        SVectorInsert(vector, xd, 1);
    }

    BOOST_ASSERT(*(int*)VectorAt(vector, 0) == 2);
    BOOST_ASSERT(*(int*)VectorAt(vector, 1) == 7654);
    BOOST_ASSERT(*(int*)VectorAt(vector, 2) == 4);
    
    VectorDeinitalize(vector);
}

#endif