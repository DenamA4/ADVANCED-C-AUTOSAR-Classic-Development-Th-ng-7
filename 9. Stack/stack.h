#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_EMPTY -1

/*

- Prototype của các hàm cấp phát động:
    + void *malloc(size_t size);
    + void *calloc(size_t num, size_t size);
    + void *realloc(void *ptr, size_t new_size);
    + void free(void *ptr);

*/

/* 

- Lý do dùng cấp phát động: 
    + Nếu cấp phát tĩnh thì có trường hợp mình sẽ bị thừa byte do không dùng hết vùng tĩnh đó.
    + Nên mình dùng cấp phát động để cấp phát đến đâu mình dùng đến đó --> tối ưu hơn với, thao tác vùng heap đa năng hơn.

*/
typedef struct {
    int* data;  // Trỏ đến phân vùng heap của stack hiện tại, giúp thao tác trên phần tử trong stack này.
    int size;   // number of elements in stack
    int top;
} Stack;

// Function khởi tạo vùng nhớ cho stack
void init_stack(Stack* stack, int max_size);

// Function kiểm tra stack đầy 
bool isFull(Stack stack);

// Function kiểm tra stack rỗng 
bool isEmpty(Stack stack);

// Push operation
void push(Stack* stack, int new_data);

// Pop operation
int pop(Stack* stack);

// Hàm lấy giá trị ở đỉnh stack
int top(Stack stack);

// Hàm clear full phần tử trong stack --> khiến stack->top = 0 (giải phóng vùng nhớ đã cấp phát heap)
bool clear(Stack* stack);

#endif