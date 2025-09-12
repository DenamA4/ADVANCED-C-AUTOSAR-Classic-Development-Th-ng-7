# 1. Compiler
- Môi trường phần mềm bên trong máy tính hay các thiết bị phần cứng khác nó chỉ hiểu được các mức điện áp hay là các bit 0 và 1.
- Mã lập trình C là các text gần với ngôn ngữ con người có thể hiểu để viết chương trình logic chạy trên phần cứng nhúng, thì ta phải có một trình biên dịch(compiler) để biên dịch chương trình C chúng ta viết ra thành các mã máy 0/1 để máy tính có thể hiểu được và thực thi lệnh.
- Quá trình để biên dịch từ mã lập trình viên viết ra sang mã máy để máy tính có thể hiểu được gồm 4 bước lần lượt là: Preprocessing - Compilation - Assemble - linking:

![](../image/1.%20Compiler and Macro/image_0.jpg)

## a) Preprocessor
- Quá trình này gồm việc:

  - Include các file header(.h)
  - Expand Macro
  - Xử lý #if, #undef,...
  - Delete comment

- File sinh ra sau quá trình này có đuôi là: .i
- Câu lệnh command để tạo file.i từ file.c: 

        gcc -E file_name.c -o file_name.i

## b) Compiler
- Đây là quá trình biên dịch mã C ra mã hợp ngữ assembly.
- Đầu vào bộ Compiler là file.i và cho đầu ra là file.s.
- Câu lệnh command để tạo file.s từ file.i: 

        gcc -S file_name.i -o file_name.s

## c) Assembler
- Đây là quá trình chuyển đổi mã hợp ngữ qua quá trình Compilation sang mã object (đây cũng là mã máy rồi).
- Đầu vào bộ Assembler là file.s và cho đầu ra là file.o.
- Câu lệnh command để tạo file.o từ file.s: 

        gcc -c file_name.s -o file_name.o

- Vì trình biên dịch sẽ biên dịch các file.c riêng lẻ cho đến quá trình cuối cùng tạo thành file.o, nên quá trình cuối là bước linking để liên kết các file.o có liên quan của 1 project phần mềm tạo thành một file thực thi duy nhất có đuôi là .exe.

## d) Linker
- Kết quả đầu ra của linker:

    - Thư viện động (shared library)
    - Hoặc tệp thực thi (executable file)

- Nhiệm vụ của linker:

    - Kết hợp các tệp mã đối tượng (.o, .obj)
    - Thay thế các tham chiếu đến biểu tượng (symbol) bằng địa chỉ cụ thể.
    - Nếu biểu tượng nằm trong thư viện ngoài, cần báo cho linker biết (điều này thường được thực hiện qua các tệp cấu hình xây dựng).

- Lỗi phổ biến:

    - Thiếu định nghĩa (undefined reference) → do chưa có triển khai hàm/biến hoặc chưa link đúng thư viện.
    - Trùng lặp (multiple definition) → khi cùng một symbol nhưng được định nghĩa trong hai hoặc nhiều tệp mã đối tượng hoặc thư viện khác nhau.

- Câu lệnh command để tạo 1 file thực thi duy nhất file.exe từ các file.o: 

        gcc file1.o file2.o ....o -o file_name.exe

Example trong phần folder Compiler Process và các file tương ứng với từng quá trình chuyển đổi qua các giai đoạn của từng bộ Processing(.i, .s, .o, .exe).

# 2. Macro
- MACRO là những thông tin được xử lý trong quá trình Preprocessing của quá trình COMPILE. Một số macro tiêu biểu:

  - #include: khi preprocessing, editor sẽ chèn nội dung của một file vào chương trình. Macro này giúp chia nhỏ chương trình chính thành những file nhỏ hơn để dễ dàng quản lý và có thể tái sử dụng ở những dự án khác.

  - #define: định nghĩa một chuỗi code bằng một chuỗi code khác giúp code được gọn, debug dễ. Khi preprocessing, những chuỗi được #define sẽ được thay thế bằng định nghĩa của chúng.

  - #undef: xoá định nghĩa trước đó của chuỗi.

  - #ifdef, #ifndef: check xem chuỗi đó đã được định nghĩa chưa, nếu có (#ifdef) hoặc không (#ifndef) thì sẽ biên dịch chương trình sau macro cho tới #endif.

  - #if, #elif, #else: nếu điều kiện #if đúng thì sẽ biên dịch chương trình sau đó, nếu sai thì bỏ qua và xét tới các #elif, nếu tất cả sai thì biên dịch chương trình sau #else cho tới khi gặp #endif.

- Các toán tử của macro: (Xem ví dụ ở folder Macro):

  - Có thể khai báo macro có tham số bằng cách bỏ chúng giữa () sau tên macro (giống với cách khai báo hàm nhưng không thêm kiểu biến).

  - Nếu muốn viết macro nhiều dòng thì chèn ký tự '\' vào cuối mỗi dòng của định nghĩa (ngoại trừ dòng cuối).

  - Toán tử #: chuẩn hoá biến hoặc chuỗi ký tự sau nó thành dạng string khi preprocessing (đặt chúng giữa "").

  - Toán tử ##: nối 2 chuỗi ký tự trước và sau ## lại, thường được dùng để nối 1 chuỗi ký tự với tên 1 biến.

Ngoài ra, có thể sử dụng "__VA_ARGS__" để thay thế cho số lượng tham số không biết trước, dành cho những hàm hay macro mà ta không biết trước số lượng tham số truyền vào hàm.