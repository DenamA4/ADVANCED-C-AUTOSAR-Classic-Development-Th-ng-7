# 1. Cấu trúc dữ liệu
- Cấu trúc dữ liệu là cách tổ chức, lưu trữ dữ liệu để dữ liệu có thể được truy cập và sử dụng một cách hiệu quả, quan trọng trong việc giải quyết các bài toán tối ưu hóa thuật toán, nó ảnh hưởng đến tốc độ thực thi và độ phức tạp của chương trình.
- Cấu trúc dữ liệu được chia làm 2 loại chính:

  - Cấu trúc dữ liệu tuyến tính(Linear data structure): Mảng(Array), Ngăn xếp(Stack), Hàng đợi(Queue), Danh sách liên kết(Linked list)
  - Cấu trúc dữ liệu phi tuyến tính(Nonlinear data structure): Đồ thị(Graph), cây(Tree)

# 2. Stack
- Stack là một cấu trúc dữ liệu có nguyên tắc hoạt động là LIFO(Last In First Out), về mặt bản chất nó được triển khai dựa trên phân vùng stack vì nó cùng nguyên lý hoạt động, nhưng khác nhau ở chỗ phân vùng stack do hệ điều hành quản lý, còn cấu trúc dữ liệu stack do người lập trình quản lý.
- Hoạt động LIFO là phần tử được Push vào cuối cùng sẽ được Pop ra đầu tiên. 

<svg xmlns="http://www.w3.org/2000/svg" width="300" height="160">
  <!-- Chữ U -->
  <polyline points="30,10 30,150 120,150 120,10" 
            style="fill:none;stroke:black;stroke-width:5" />

  <!-- Thanh số 1 (xanh lá) -->
  <rect x="160" y="50" width="90" height="20" fill="lime" stroke="black" stroke-width="1"/>
  <text x="205" y="65" font-size="14" text-anchor="middle" fill="black">1</text>

  <!-- Thanh số 2 (vàng) -->
  <rect x="160" y="80" width="90" height="20" fill="yellow" stroke="black" stroke-width="1"/> 
  <text x="205" y="95" font-size="14" text-anchor="middle" fill="black">2</text>

  <!-- Thanh số 3 (xanh dương) -->
  <rect x="160" y="110" width="90" height="20" fill="blue" stroke="black" stroke-width="1"/>
  <text x="205" y="125" font-size="14" text-anchor="middle" fill="black">3</text>
  <!-- Định nghĩa đầu mũi tên -->
  <defs>
    <marker id="arrowhead" markerWidth="10" markerHeight="7" 
            refX="10" refY="3.5" orient="auto">
      <polygon points="0 0, 3 3.5, 0 7" fill="black"/>
    </marker>
  </defs>
  <!-- Mũi tên đặt sau 3 thanh -->
  <line x1="265" y1="95" x2="322" y2="95" 
        stroke="black" stroke-width="3" marker-end="url(#arrowhead)"/>
</svg>

<svg xmlns="http://www.w3.org/2000/svg" width="150" height="160">
  <!-- Chữ U -->
  <polyline points="30,10 30,150 120,150 120,10" 
            style="fill:none;stroke:black;stroke-width:5" />

  <!-- Thanh số 2 -->
  <rect x="30" y="50" width="90" height="20" fill="blue" stroke="black" stroke-width="1"/>
  <text x="75" y="65" font-size="14" text-anchor="middle" fill="black">3</text>

  <!-- Thanh số 3 -->
  <rect x="30" y="80" width="90" height="20" fill="yellow" stroke="black" stroke-width="1"/>
  <text x="75" y="95" font-size="14" text-anchor="middle" fill="black">2</text>

  <!-- Thanh số 4 -->
  <rect x="30" y="110" width="90" height="20" fill="lime" stroke="black" stroke-width="1"/>
  <text x="75" y="125" font-size="14" text-anchor="middle" fill="black">1</text>
</svg>

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







    







