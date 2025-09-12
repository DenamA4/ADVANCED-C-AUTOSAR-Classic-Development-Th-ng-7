#include <stdio.h>

#define CREATE_VAR(name)   \
    int int_##name;        \
    char char_##name;      \
    double double_##name

// ## dùng để nối chuỗi

#define CREATE_STRING(cmd) printf(#cmd "\n")

// # chuẩn hóa đoạn văn bản thành chuỗi (a text --> a string in C/C++ program)

#define CONCAT(a,b) a##b

int main()
{
    CREATE_VAR(test);
    CREATE_STRING(hello world);

    int ab = 50;
    printf("Value: %d\n", CONCAT(a,b));
    return 0;
}
