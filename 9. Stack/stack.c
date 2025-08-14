#include "stack.h"

void init_stack(Stack* stack, int max_size)
{
    stack->data = (int*)malloc(max_size*sizeof(int));
    stack->size = max_size;
    stack->top = -1;
}

bool isFull(Stack stack)
{
    return stack.top == stack.size - 1 ? true : false;
}

bool isEmpty(Stack stack)
{
    return stack.top == STACK_EMPTY;
}

void push(Stack* stack, int new_data)
{
    if(!isFull(*stack)) 
    {
        stack->top++;
        // *(++stack->data) = new_data; --> chú ý cách này có thể thay đổi con trỏ gốc làm free() sau này sai lệch
        stack->data[stack->top] = new_data; 
        printf("%d\n", stack->data[stack->top]);
        return;
    }    
    printf("stack full!\n");
}

int pop(Stack* stack)
{
    if(!isEmpty(*stack))
    {
        int data = stack->data[stack->top];
        stack->top--;
        return data;
    }
    printf("stack empty!\n");
    return STACK_EMPTY;
}

int top(Stack stack)
{
    if(!isEmpty(stack)) 
    {
        return stack.data[stack.top];
    }
    return STACK_EMPTY;
}

bool clear(Stack* stack)
{
    if(stack->data != NULL)
    {
        free(stack->data);
        stack->data = NULL;
    }
    stack->size = 0;
    stack->top = -1;
}