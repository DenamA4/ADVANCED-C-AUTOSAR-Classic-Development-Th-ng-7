#include "stack.h"

// Ví dụ hàm tính giai thừa
int giaithua(int n)
{
    if(n < 0)
    {
        printf("Khong the tinh giai thua so am");
        return STACK_EMPTY;
    }
    int result = 1;
    Stack st;
    init_stack(&st, n);
    for(int i = n; i > 0; i--)  
    {
        push(&st, i);
    }
    for(int i = 0; i < n; i++)
    {
        result *= pop(&st);
    }
    clear(&st);
    return result;
}

int main(int argc, const char* argv[])
{
    Stack st;
    int size = 5;
    init_stack(&st, size);
    // push(&st, 1);
    // push(&st, 2);
    // push(&st, 3);
    // push(&st, 4);
    // push(&st, 5);
    // push(&st, 6);
    printf("%d\n", giaithua(5));
    return 0;
}