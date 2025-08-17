#include "queue.h"

int main(int argc, const char* argv[])
{
    Queue q;
    init_queue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("front: %d     back: %d\n", getFront(q), getRear(q));
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // printf("front: %d     back: %d\n", getFront(q), getRear(q));
    // dequeue(&q);
    enqueue(&q, 8);
    return 0;
}