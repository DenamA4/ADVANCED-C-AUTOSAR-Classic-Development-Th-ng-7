#include <stdio.h>

int main(int argc, char const* argv[])
{
    int b = 0x12345678;
    char *p = (char*)&b;
    if (*p == 0x12) printf("Big endian");
    else if(*p == 0x78) printf("Little endian");
    return 0;
}