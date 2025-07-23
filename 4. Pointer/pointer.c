#include <stdio.h>

int main(int argc, char const* argv[])
{
    int a = 10;
    int *ptr = &a;
    printf("%p\n%p", ptr, &a);
    *ptr = 19;
    printf("\n%d", a);
    return 0;
}