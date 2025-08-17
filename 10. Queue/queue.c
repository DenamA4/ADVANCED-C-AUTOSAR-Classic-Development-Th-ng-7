#include "queue.h"

void init_queue(Queue* queue, int max_size)
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

bool isFull(Queue queue)    // Phần này thay là const Queue* queue là tham số truyền vào các hàm đẻ tối ưu bộ nhớ thay vì biến.
{
    if(queue.rear == queue.size-1) return true;
    return false;
}

bool isEmpty(Queue queue)
{
    return queue.front == QUEUE_EMPTY ? true : false;
}

void enqueue(Queue* queue, int data)
{
    if(isEmpty(*queue)) 
    {
        queue->front = 0;
    }
    if(!isFull(*queue))
    {
        queue->rear++; 
        queue->data[queue->rear] = data;
        printf("enqueue: %d and addr: %p\n", data, &queue->data[queue->rear]);
        return;
    }
    printf("ERROR: Hang doi da day\n");
}

int dequeue(Queue* queue)
{
    if(!isEmpty(*queue))
    {
        int data = queue->data[queue->front];
        queue->front++;
        if(queue->front > queue->rear) queue->front = queue->rear = QUEUE_EMPTY;
        return data;
    }
    printf("ERROR: Hang doi dang rong\n");
    return QUEUE_EMPTY;
}

int getFront(Queue queue)
{
   if(!isEmpty(queue))
   {
     return queue.data[queue.front];
   }
   return QUEUE_EMPTY;
}

int getRear(Queue queue)
{
    if(!isEmpty(queue))
    {
        return queue.data[queue.rear];
    }
    return QUEUE_EMPTY;
}

void clear(Queue* queue)
{
    if(queue != NULL)
    {
        free(queue->data);
        queue->data = NULL;
    }
    queue->size = 0;
    queue->front = queue->rear = QUEUE_EMPTY;
}


