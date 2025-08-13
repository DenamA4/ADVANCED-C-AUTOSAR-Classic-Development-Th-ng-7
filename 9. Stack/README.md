# 1. Cấu trúc dữ liệu
- Cấu trúc dữ liệu là cách tổ chức, lưu trữ dữ liệu để dữ liệu có thể được truy cập và sử dụng một cách hiệu quả, quan trọng trong việc giải quyết các bài toán tối ưu hóa thuật toán, nó ảnh hưởng đến tốc độ thực thi và độ phức tạp của chương trình.
- Cấu trúc dữ liệu được chia làm 2 loại chính:

  - Cấu trúc dữ liệu tuyến tính(Linear data structure): Mảng(Array), Ngăn xếp(Stack), Hàng đợi(Queue), Danh sách liên kết(Linked list)
  - Cấu trúc dữ liệu phi tuyến tính(Nonlinear data structure): Đồ thị(Graph), cây(Tree)

# 2. Stack
- Stack là một cấu trúc dữ liệu có nguyên tắc hoạt động là LIFO(Last In First Out), về mặt bản chất nó được triển khai dựa trên phân vùng stack vì nó cùng nguyên lý hoạt động, nhưng khác nhau ở chỗ phân vùng stack do hệ điều hành quản lý, còn cấu trúc dữ liệu stack do người lập trình quản lý.
- Hoạt động LIFO là phần tử được Push vào cuối cùng sẽ được Pop ra đầu tiên. 

![](images/9. Stack/image_0.png)

- Ta liên tưởng stack giống một chiếc bình có đáy, ta đưa vào vật nào đầu tiên thì nó năm sâu dưới đáy bình (Hình trên bến trái mũi tên).
- Hình bến trái lúc đầu Stack đang  rỗng, sau khi ta push lần lượt thanh 1, thanh 2, thanh 3 vào thì ở đáy stack đang là thanh 1, đỉnh stack lúc này là thanh 3.
- Lúc này ta không có cách nào để lấy thanh 1 hay thanh 2 ra đầu tiên được vì cả 2 thanh này đều bị thanh số 3 chặn ở đỉnh, nên ta chỉ có thể lấy thanh 3 ra đầu tiên rồi tiếp đó lần lượt là thanh 2, thanh 1 --> Đây là cơ chế LIFO vì thanh 3 được push vào cuối cùng và cũng được lấy ra đầu tiên.

# 3. Các thao tác cơ bản trên Stack
- "push" để thêm một phần tử vào đỉnh của stack:
- "pop" để xóa một phần tử ở đỉnh stack:
- "peek/top" để lấy giá trị của phần tử ở đỉnh ngăn xếp:
- Kiểm tra stack đầy: top = size -1:
- Kiểm tra stack rỗng: top = -1:
- Mô tả các thao tác:







    







