# 1. Pointer
- Con trỏ (biến con trỏ) là một biến dùng để lưu giá trị, giá trị này có định dạng là một địa chỉ của vùng nhớ tùy vào kiểu dữ liệu nó trỏ tới. Qua đó ta có thể thao tác trên bộ nhớ một cách đơn giản.
- Format specifier(định dạng kí tự) của biến con trỏ là %p.
<details>
<summary>Demo</summary>

    int a = 10;
    int *ptr = &a;
    printf("%p\n%p", ptr, &a);
    *ptr = 19;
    printf("\n%d", a);
</details>

# 2. Ứng dụng của Pointer
- Bình thường, khi truyền một biến vào hàm dưới dạng tham trị (giá trị của biến), hàm sẽ tạo một bản sao của biến đó tại một địa chỉ bộ nhớ mới. Sau khi hàm thực thi xong, mọi thay đổi chỉ ảnh hưởng đến bản sao, không ảnh hưởng đến biến gốc bên ngoài.

- Tuy nhiên, khi truyền biến vào hàm dưới dạng tham chiếu (tức là truyền địa chỉ của biến, dùng con trỏ), hàm sẽ thao tác trực tiếp trên địa chỉ gốc. Do đó, mọi thay đổi sẽ tác động lên chính biến ban đầu.

- Đây là một trong những ứng dụng quan trọng của con trỏ (pointer): giúp hàm truy cập và thay đổi trực tiếp dữ liệu bên ngoài, thay vì làm việc với bản sao.
# 3. Endianness
- Trong bộ nhớ RAM (khi chương trình running), với các dữ liệu nhiều hơn 1 byte, vì mỗi ô nhớ là 1 byte (8 bits) nên thứ tự lưu trữ các byte để cpu có thể đọc được, điều này được triển khai với cơ chế Endianness.
- Dùng để xác định byte thấp, byte cao nằm ở đâu.
- Có 2 kiểu phổ biến: Little endian và Big endian.
1. Little endian
- Byte thấp (Least significant byte - LSB) nằm ở ô nhớ có địa chỉ thấp nhất.
- Byte cao (Most significant byte - MSB) nằm ở ô nhớ có địa chỉ cao nhất.
VD: 0xAABBCCDD
                        
                        | **Địa chỉ** | **Giá trị** |
                        |:------------:|:-------------:|
                        | 0x01       | 0xDD        |
                        | 0x02       | 0xCC        |
                        | 0x03       | 0xBB        |
                        | 0x04       | 0xAA        |

2.Big endian
- Byte thấp (Least significant byte - LSB) nằm ở ô nhớ có địa chỉ cao nhất.
- Byte cao (Most significant byte - MSB) nằm ở ô nhớ có địa chỉ thấp nhất.
VD: 0x12345678

                        | **Địa chỉ** | **Giá trị** |
                        |:----------:|:-----------:|
                        | 0x01       | 0x12        |
                        | 0x02       | 0x34        |
                        | 0x03       | 0x56        |
                        | 0x04       | 0x78        |

<details>
<summary>Demo</summary>

    int b = 0x12345678;
    char *p = (char*)&b;
    if (*p == 0x12) printf("Big endian");
    else if(*p == 0x78) printf("Little endian");
</details>

# 4. Kích thước Pointer
- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch hoặc kiến trúc vi xử lý (stm8, stm32, esp32).
<details>
<summary>Code test</summary>

    #include <stdio.h>

    int main(int argc, const char*argv[])
    {
        printf("Sizeof pointer: %d bytes\n", sizeof(int*));
        return 0;
    }
</details>

# 5. Void Pointer
- Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
*Lưu ý khi dùng void pointer phải ép kiểu khi muốn in giá trị.*
<details>
<summary>Demo</summary>

    int value = 5;
    double test = 15.7;
    char letter = 'A';

    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));
</details>

# 6. Function Pointer
- Con trỏ hàm là một biến con trỏ lưu trữ giá trị là địa chỉ của một hàm nào đó, tức là nó trỏ tới vùng nhớ chứa mã máy của hàm mà ta đã định nghĩa trong chương trình.
- Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
- Cú pháp con trỏ hàm: 
           
       return_type (*name_pointer)(<data_type_1>, <data_type_2>,...);
<details>
<summary>Ví dụ</summary>

    #include <stdio.h>

    // Hàm mẫu 1
    void greetEnglish(){ printf("Hello!\n"); }

    // Hàm mẫu 2
    void greetFrench(){ printf("Bonjour!\n"); }

    int main()
    {
        // Khai báo con trỏ hàm
        void (*ptrToGreet)();

        // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
        ptrToGreet = greetEnglish;

        // Gọi hàm thông qua con trỏ hàm
        ptrToGreet();  // In ra: Hello!

        // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
        ptrToGreet = greetFrench;

        // Gọi hàm thông qua con trỏ hàm
        (*ptrToGreet)();  // In ra: Bonjour!
        return 0;
    }
</details>

# 7. Pointer to constant
- Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference.
- Biến con trỏ này có thể lưu giá trị là địa chỉ của vùng nhớ khác được, nhưng giá trị bên trong vùng nhớ đó con trỏ này không thay đổi được (chỉ Read-only).
- Cú pháp:

    Cách 1: <data_type> const *ptr_const;

    Cách 2: const <data_type> *ptr_const;

<details>
<summary>Demo</summary>

    int value = 5;
    int test = 8;
    int const *ptr_const = &value;

    //*ptr_const = 7;    // wrong
    //ptr_const = &test; // right
   
    printf("value: %d\n", *ptr_const);

    value = 9;
    printf("value: %d\n", *ptr_const);
</details>

# 8. Constant Pointer
- Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
- Nó có thể thay đổi giá trị chứa trong vùng nhớ nó trỏ đến.
- Cú pháp:

    <data_type> *const const_ptr = &value;

<details>
<summary>Demo</summary>

    int value = 5;
    int test = 15;
    int *const const_ptr = &value;

    printf("value: %d\n", *const_ptr);

    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);

    //const_ptr = &test; // wrong
</details>

# 9. Pointer to Pointer
- Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ.
- Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. 
- Cú pháp:

    <data_type> **ptr;

- Ứng dụng thường thấy trong xây dựng danh sách liên kết, Json... trong ngôn ngữ C.
<details>
<summary>Demo</summary>

    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến
    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    /*
        **ptr2 = &ptr1
        ptr2 = &ptr1;
        *ptr2 = ptr1 = &value;
        **ptr2 = *ptr1 = value
    */

    printf("address of value: %p\n", &value);
    printf("value of ptr1: %p\n", ptr1);

    printf("address of ptr1: %p\n", &ptr1);
    printf("value of ptr2: %p\n", ptr2);

    printf("dereference ptr2 first time: %p\n", *ptr2);
    printf("dereference ptr2 second time: %d\n", **ptr2);
</details>

# 10. NULL Pointer
- NULL được define trong thư viện của C là: 

        #define NULL (void*)0
- Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. 
- Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null, C++ (NULL, nullptr).
- Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.





