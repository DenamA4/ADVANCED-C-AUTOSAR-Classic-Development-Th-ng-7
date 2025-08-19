#include <stdio.h>
#include <stdbool.h>

typedef enum{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JSONType;

typedef struct JSONValue{

    JSONType type;  //Xác định kiểu thành phần mình đang phân tích
    union 
    {
        bool boolean;
        double number;
        char *string;   // Chỉ lưu trữ được 1 chuỗi

        struct
        {
            struct JSONValue *values; // trong mảng json thì các phần tử có kiểu dữ liệu, cấu trúc bất kì, nên khai báo lại con trỏ kiểu JSONValue để đệ quy
            size_t count;         // Biến xác định số lượng phần tử trong mảng json đó
        } array;

        struct
        {
            char **keys;  // Chứa mảng các key
            struct JSONValue *values;     // value là bất kì kiểu dữ liệu nào.
            size_t count;          // Xác định số cặp key-value ở trong đối tượng json đó
        } object;

    } value;
} JSONValue;   // Cấu trúc Json      --> Đây là cách dữ liệu json được lưu trữ ở máy mình, còn quá trình xử lý phân tích ra thì làm sau

//"{"name":"nguyen van A","tuoi":18,"isStudent":true,}"

/*

    cặp key - value:
        key
            - *string : "name"
        value
            - type : JSON_STRING
            - *string : "nguyen van A"

*/

/*
 * [50.456, true, [5, "hello world"]]
*/


int main(int argc, char const *argv[])
{
    //printf("%lu", sizeof(size_t));
    JSONValue *json_str = (JSONValue*)malloc(sizeof(JSONValue));    // Đầu tiên cấp 1 vùng nhớ ví dụ 0x001 cho lần lưu trữ toàn file .json

    json_str->type = JSON_ARRAY;
    json_str->value.array.count = 3;
    json_str->value.array.values = (JSONValue*)malloc(json_str->value.array.count * sizeof(JSONValue));   // VÌ là mảng nên 24 bytes cuối của vùng malloc line 59 là địa chỉ đến vùng 
                                                                                                                    // malloc mới ví dụ 0x34 chằng hạn để phân tích tiếp trong mảng

    // phần tử 0
    json_str->value.array.values[0].type = JSON_NUMBER;
    json_str->value.array.values[0].value.number = 50.456;

    // phần tử 1
    json_str->value.array.values[1].type = JSON_BOOLEAN;
    json_str->value.array.values[1].value.boolean = true;

    // phần tử 2
    json_str->value.array.values[2].type = JSON_ARRAY;
    json_str->value.array.values[2].value.array.count = 2;
    json_str->value.array.values[2].value.array.values = (JSONValue*)malloc(json_str->value.array.values[2].value.array.count * sizeof(JSONValue));

    // phần tử 2.0
    json_str->value.array.values[2].value.array.values[0].type = JSON_NUMBER;
    json_str->value.array.values[2].value.array.values[0].value.number = 5;

    // phần tử 2.1
    json_str->value.array.values[2].value.array.values[1].type = JSON_STRING;
    json_str->value.array.values[2].value.array.values[1].value.string = "hello world";

    return 0;
}
