#include "BubbleSort.h"

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *ptr, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)  // Tưởng tượng cần lặp x lần for đi từ 0 -> (n - (2--))
        {
            if(ptr[j] > ptr[j+1]) swap(&ptr[j], &ptr[j+1]);
        }
    }
}