#ifndef QUEUE_UNITTEST_H
#define QUEUE_UNITTEST_H

#include <boost/test/unit_test.hpp>
extern "C" {
#include "../src/queue.h"
}

static Queue *queue = NULL;

BOOST_AUTO_TEST_CASE( QueueSimpleTest )
{
    queue = QueueInitalize(sizeof(int));
    BOOST_ASSERT(queue);   

    {
        const int value = 1;
        SQueuePush(queue, value);
    }
    {
        const int value = 2;
        SQueuePush(queue, value);
    }
    {
        const int value = 3;
        SQueuePush(queue, value);
    }

    BOOST_ASSERT(QueueGetSize(queue) == 3);

    BOOST_ASSERT(*(int*)QueueFront(queue) == 1);
    QueuePop(queue);

    BOOST_ASSERT(*(int*)QueueFront(queue) == 2);
    QueuePop(queue);

    BOOST_ASSERT(*(int*)QueueFront(queue) == 3);
    QueuePop(queue);
}

BOOST_AUTO_TEST_CASE( QueueEmptyFrontTest )
{ 
    BOOST_ASSERT(QueueGetSize(queue) == 0);
    BOOST_ASSERT(QueueFront(queue) == NULL);
    QueuePop(queue);
}

BOOST_AUTO_TEST_CASE( QueueEndTest )
{
    {
        const int value = 1;
        SQueuePush(queue, value);
    }
    {
        const int value = 2;
        SQueuePush(queue, value);
    }
    {
        const int value = 3;
        SQueuePush(queue, value);
    }
    BOOST_ASSERT(QueueGetSize(queue) == 3);
    QueueDeinitalize(queue);
}

#endif