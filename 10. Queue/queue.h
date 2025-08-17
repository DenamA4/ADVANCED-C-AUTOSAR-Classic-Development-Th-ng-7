#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY -1

typedef struct {
    int *data;
    int size;
    int front;
    int rear;
} Queue;

/*                            Prototype cho linear_queue:                              */

// Function khởi tạo vùng nhớ cho queue
void init_queue(Queue* queue, int max_size);

// Function kiểm tra queue đầy 
bool isFull(Queue queue);

// Function kiểm tra queue rỗng 
bool isEmpty(Queue stack);

// Function thêm phần tử vào cuối hàng đợi
void enqueue(Queue* queue, int data);

// Function xóa phần tử khỏi đầu hàng đợi
int dequeue(Queue* queue);

// Xem giá trị của phần tử ở đầu hàng đợi
int getFront(Queue queue);

// Xem giá trị của phần tử ở cuối hàng đợi
int getRear(Queue queue);

// Giải phóng hàng đợi
void clear(Queue* queue);

/*                            Prototype cho circular_queue:                              */

// Function khởi tạo vùng nhớ cho circular_queue
void init_circular_queue(Queue* queue, int max_size);

// Function kiểm tra circular_queue đầy
bool isFullCircular(Queue queue);

// Function kiểm tra circular_queue rỗng
bool isEmptyCircular(Queue queue);

// Function thêm phần tử vào cuối hàng đợi circular
void enqueueCircular(Queue* queue, int data);

// Function xóa phần tử khỏi đầu hàng đợi circular
int dequeueCircular(Queue* queue);

// Xem giá trị của phần tử ở đầu hàng đợi circular
int getFrontCircular(Queue queue);

// Xem giá trị của phần tử ở cuối hàng đợi circular
int getRearCircular(Queue queue);

// Giải phóng hàng đợi circular
void clearCircular(Queue* queue);

#endif