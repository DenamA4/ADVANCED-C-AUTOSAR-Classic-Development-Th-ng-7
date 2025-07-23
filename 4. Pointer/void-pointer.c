#include <stdio.h>

int main()
{
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    void *ptr1[] = {&value, &test, &letter, array};
    printf("value: %d\n", *(int*)ptr1[0]);
    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}
