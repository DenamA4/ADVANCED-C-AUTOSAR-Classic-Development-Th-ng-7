#include <stdio.h>

#define FOR(i,x) for (int i = 0; i < (x); i++)
#define SUM(...)                      \
    int cnt = 0;                      \
    const int g[] = {__VA_ARGS__};     \
    int n = sizeof(g) / sizeof(int);  \
    FOR(m, n) {                       \
        cnt += g[m];                  \
    }                                 
   
int main()
{
    // Thực chất là thay thế đoạn văn bản qua Macro
    SUM(1,2,3,4,5,6);
    int value = cnt;   // Chỉ minh họa __VA_ARGS__, vì nếu trong chương trình chính init thêm 1 biến cnt thì sẽ bị error trùng tên biến.
    printf("Sum = %d\n", value);
}