# 1. Cấu trúc dữ liệu
- Cấu trúc dữ liệu là cách tổ chức, lưu trữ dữ liệu để dữ liệu có thể được truy cập và sử dụng một cách hiệu quả, quan trọng trong việc giải quyết các bài toán tối ưu hóa thuật toán, nó ảnh hưởng đến tốc độ thực thi và độ phức tạp của chương trình.
- Cấu trúc dữ liệu được chia làm 2 loại chính:

  - Cấu trúc dữ liệu tuyến tính(Linear data structure): Mảng(Array), Ngăn xếp(Stack), Hàng đợi(Queue), Danh sách liên kết(Linked list)
  - Cấu trúc dữ liệu phi tuyến tính(Nonlinear data structure): Đồ thị(Graph), cây(Tree)

# 2. Stack
- Stack là một cấu trúc dữ liệu có nguyên tắc hoạt động là LIFO(Last In First Out), về mặt bản chất nó được triển khai dựa trên phân vùng stack vì nó cùng nguyên lý hoạt động, nhưng khác nhau ở chỗ phân vùng stack do hệ điều hành quản lý, còn cấu trúc dữ liệu stack do người lập trình quản lý.
- Hoạt động LIFO là phần tử được Push vào cuối cùng sẽ được Pop ra đầu tiên. 

![](../image/9.%20Stack/image_0.jpg)

- Ta liên tưởng stack giống một chiếc bình có đáy, ta đưa vào vật nào đầu tiên thì nó năm sâu dưới đáy bình (Hình trên bến trái mũi tên).
- Hình bến trái lúc đầu Stack đang  rỗng, sau khi ta push lần lượt thanh 1, thanh 2, thanh 3 vào thì ở đáy stack đang là thanh 1, đỉnh stack lúc này là thanh 3.
- Lúc này ta không có cách nào để lấy thanh 1 hay thanh 2 ra đầu tiên được vì cả 2 thanh này đều bị thanh số 3 chặn ở đỉnh, nên ta chỉ có thể lấy thanh 3 ra đầu tiên rồi tiếp đó lần lượt là thanh 2, thanh 1 --> Đây là cơ chế LIFO vì thanh 3 được push vào cuối cùng và cũng được lấy ra đầu tiên.

# 3. Các thao tác cơ bản trên Stack
- "push" để thêm một phần tử vào đỉnh của stack.
- "pop" để xóa một phần tử ở đỉnh stack.
- "peek/top" để lấy giá trị của phần tử ở đỉnh ngăn xếp.
- Kiểm tra stack đầy: top = size -1.
- Kiểm tra stack rỗng: top = -1: Khi stack chưa có phần tử nào thì đỉnh stack sẽ trỏ vào đáy của stack.
- Mô tả các thao tác: Giả sử stack có số lượng phần tử tối đa là 5:
 
  a. Quá trình Push:

    - Ban đầu stack rỗng, biến top = -1, tiếp đến ta push thanh 1 vào stack:

    ![](../image/9.%20Stack/image_1.jpg)

    - Sau khi push thanh 1 vào thì này đỉnh stack đang trỏ đến thanh 1 và top tăng lên 1 là bằng 0:

    ![](../image/9.%20Stack/image_2.jpg)

    - Sau đó ta push tiếp thanh 2 vào, lúc này đỉnh stack đang trỏ đến thanh 2 và top tiếp tục tăng thêm 1 và bằng 1:

    ![](../image/9.%20Stack/image_3.jpg)

    - Tiếp đó, push 3 thanh còn lại vào stack, và bây giờ đỉnh stack là ở thanh 5, biến top = 4 = max_size - 1 tức là stack đã đầy:

    ![](../image/9.%20Stack/image_4.jpg)

  b. Quá trình Pop:

    -  Ta pop phần tử ở đỉnh stack ra là thanh 5, bây giờ đỉnh stack là ở thanh 4, biến top giảm đi một và lúc này bằng 3:

    ![](../image/9.%20Stack/image_5.jpg)

    - Tiếp tục pop đỉnh stack ra, thanh 4 được xóa khỏi stack, đỉnh stack hiện tại là thanh số 3, biến top được giảm tiếp đi 1 và bằng 2:

    ![](../image/9.%20Stack/image_6.jpg)

    - Pop tiếp 2 lần nữa để lấy thanh số 3, thanh số 2 ra thì lúc này đỉnh stack đang ở thanh số 1, và biến top = 0:

    ![](../image/9.%20Stack/image_7.jpg)

    - Khi pop nốt thanh số 1, stack trở thành rỗng và biến top = -1:

    ![](../image/9.%20Stack/image_8.jpg)

# 4. Ứng dụng của stack

- Ngăn xếp được ứng dụng để giải quyết những vấn đề sau:
  
  - Xây dựng các giải thuật đệ qui: tất cả các giải thuật đệ qui được xây dựng dựa trên cơ chế LIFO của ngăn xếp.

  - Khử bỏ các giải thuật đệ qui.
  
  - Biểu diễn tính toán.
 
  - Duyệt cây, duyệt đồ thị...

  VD về ứng dụng biểu diễn tính toán: Chuyển đổi biểu thức trung tố về biểu thức hậu tố. Ta vẫn hay làm quen và thực hiện tính toán trên các biểu thức số học trung tố. Ví dụ biểu thức trung tố P = (a+b*c)-(a/b+c). Trong cách viết này các phép toán bao giờ cũng đứng giữa hai toán hạng. Phương pháp tính toán được thực hiện theo thứ tự ưu tiên các phép toán số học. Biểu thức số học hậu tố là phương pháp biểu diễn các phép toán hai ngôi +, -, *, /, ^ đứng sau các toán hạng. Phương pháp biểu diễn được thực hiện theo nguyên tắc như sau:
  
      - Nếu a + b là biểu thức trung tố thì biểu thức hậu tố tương ứng là a b +
      
      - Nếu a - b là biểu thức trung tố thì biểu thức hậu tố tương ứng là a b -
      
      - Nếu a * b là biểu thức trung tố thì biểu thức hậu tố tương ứng là a b *
      
      - Nếu a / b là biểu thức trung tố thì biểu thức hậu tố tương ứng là a b /
      
      - Nếu a ^ b là biểu thức trung tố thì biểu thức hậu tố tương ứng là a b ^ (phép ^ được ký hiệu cho phép lấy lũy thừa)
      
      - Nếu (P) trong đó P là hậu tố thì biểu thức hậu tố tương ứng P.

  
  ![](../image/9.%20Stack/image_9.jpg)

Ví dụ với biểu thức P = (a+b*c)-(a/b+c) sẽ được biến đổi thành biểu thức hậu tố tương đương như dưới đây:
                  
                  (a+b*c)-(a/b+c) = (a+bc*)-(ab/+c)

                                  = (abc*+)-(ab/c+)
        
                                  = abc*+-ab/c+

                                  = abc*+ab/c+-

Đối với biểu thức số học hậu tố, không còn các phép toán ‘(‘ , ‘)’, không còn thứ tự ưu tiên các phép toán. Bài toán đặt ra là cho biểu thức trung tố P hãy chuyển đổi P thành biểu diễn hậu tố tương đương với P. Sau khi đã có biểu thức trung tố P, hãy xây dựng thuật toán tính toán giá trị biểu thức hậu tố P. Thuật toán được xây dựng dựa vào ngăn xếp được thể hiện trong hinh như dưới đây:

Thuật toán chuyển đổi biểu thức trung tố thành biểu thức hậu tố.
Kiểm nghiệm thuật toán với P = (a+b*c)–(a/b+c):

  ![](../image/9.%20Stack/image_10.jpg)

Kiểm nghiệm thuật toán:

  ![](../image/9.%20Stack/image_11.jpg)

Tính toán biểu thức hậu tố:

  ![](../image/9.%20Stack/image_12.jpg)

# 5. Demo code

<details>
<summary>Định nghĩa cấu trúc dữ liệu Stack</summary>

    #define STACK_EMPTY -1

    typedef struct {
        int* data;   // Trỏ đến phân vùng heap của stack hiện tại, giúp thao tác trên phần tử trong stack này.
        int size;    // number of elements in stack
        int top;
    } Stack;
</details>

<details>
<summary>Hàm khởi tạo Stack ban đầu</summary>

    void init_stack(Stack* stack, int max_size)
    {
        stack->data = (int*)malloc(max_size*sizeof(int));
        stack->size = max_size;
        stack->top = -1;
    }
</details>

<details>
<summary>Hàm kiểm tra Stack đầy</summary>

    bool isFull(Stack stack)
    {
        return stack.top == stack.size - 1 ? true : false;
    }
</details>

<details>
<summary>Hàm kiểm tra Stack rỗng</summary>

    bool isEmpty(Stack stack)
    {
        return stack.top == STACK_EMPTY;
    }
</details>

<details>
<summary>Hàm thêm phần tử mới vào đỉnh Stack</summary>

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
</details>

<details>
<summary>Hàm xóa phần tử ở đỉnh Stack</summary>

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
</details>

<details>
<summary>Hàm xem giá trị phần tử ở đỉnh Stack</summary>

    int top(Stack stack)
  ``{
      if(!isEmpty(stack)) 
      {
          return stack.data[stack.top];
      }
      return STACK_EMPTY;
    }
</details>

<details>
<summary>Hàm giải phóng vùng nhớ, clear cả Stack</summary>

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
</details>