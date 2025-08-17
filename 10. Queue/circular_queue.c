#include "queue.h"

void init_circular_queue(Queue* queue, int max_size)
{
    queue->data = (int*)malloc(max_size*sizeof(int));
    if(queue->data == NULL)
    {
        printf("Cap phat vung nho cho hang doi that bai\n");
        return;
    }
    queue->size = max_size;
    queue->front = queue->rear = QUEUE_EMPTY;
}

bool isFullCircular(Queue queue)
{
    if((queue.rear == queue.size-1 && queue.front == 0) 
                        || (queue.front == queue.rear + 1)) return true;
    return false;

    /* Cách 2:

    return (queue.front == (queue.rear + 1) % queue.size);

    */
}

bool isEmptyCircular(Queue queue)
{
    return queue.front == QUEUE_EMPTY ? true : false;
}

void enqueueCircular(Queue* queue, int data)   // Với hàng đợi index [0 --> max_size) từ trái sang, dù push vô phải đảm bảo theo chiều tăng
                                                // của index (phần tử tại index nhỏ sẽ pop ra đầu tiên kể cả trường hợp rear < front)
{
    if(isEmptyCircular(*queue)) queue->front = 0; 
    if(!isFullCircular(*queue))
    {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->data[queue->rear] = data;
        printf("enqueue: %d and addr: %p\n", data, &queue->data[queue->rear]);
        return;
    }
    printf("ERROR: Hang doi da day\n");
}

int dequeueCircular(Queue* queue)  // Trong hàng đợi vòng thì front liên tục đuổi theo rear khi có thao tác dequeue hay enqueue.
{
    if(!isEmpty(*queue))
    {
        int data = queue->data[queue->front];
        if(queue->front == queue->rear) 
        {
            queue->front = queue->rear = QUEUE_EMPTY;
            return data;
        }
        queue->front = (queue->front + 1) % queue->size;
        return data;
    }
    printf("ERROR: Hang doi dang rong\n");
    return QUEUE_EMPTY;
}

int getFrontCircular(Queue queue)
{
    if(!isEmpty(queue))
   {
     return queue.data[queue.front];
   }
   return QUEUE_EMPTY;
}

int getRearCircular(Queue queue)
{
    if(!isEmpty(queue))
    {
        return queue.data[queue.rear];
    }
    return QUEUE_EMPTY;
}

void clearCircular(Queue* queue)
{
    if(queue != NULL)
    {
        free(queue->data);
        queue->data = NULL;
    }
    queue->size = 0;
    queue->front = queue->rear = QUEUE_EMPTY;
}