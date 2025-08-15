# 1. Queue
- Hàng đợi được hiểu là một hàng để đợi. Hàng đợi trong máy tính cũng giống như hàng đợi trong thực tế: hàng đợi mua vé tàu, vé xe, vé máy bay. Hàng đợi ứng dụng trong nhiều lĩnh vực khác nhau của khoa học máy tính. 

- Hàng đợi (queue) là tập các node thông tin được tổ chức liên tục hoặc rời rạc nhau trong bộ nhớ và thực hiện theo cơ chế FIFO(First-In-First-Out).

# 2. Một số loại hàng đợi
- Hàng đợi tuyến tính (linear queue): hàng đợi liên tục được xây dựng theo nguyên tắc có điểm vào (inp) luôn lớn hơn điểm ra (out). Không gian nhớ sẽ không được tái sử dụng sau mỗi phép lấy phần tử ra khỏi hàng đợi:

  - Điểm vào (inp) luôn nằm ở chỉ số lớn hơn điểm ra (out).

  - Khi lấy một phần tử ra (dequeue), ô nhớ ở vị trí đó không được tái sử dụng nữa — trừ khi bạn dịch toàn bộ phần tử còn lại lên đầu mảng, nhưng đó là thao tác tốn thời gian nên trong cài đặt thông thường bằng mảng tĩnh, không gian đó bị bỏ trống.

  - Vì vậy, nếu inp đạt tới cuối mảng thì hàng đợi bị coi là đầy, ngay cả khi còn ô trống ở đầu mảng.

- Hàng đợi vòng (curcular queue): hàng đợi liên tục được xây dựng theo nguyên tắc không gian nhớ sẽ được tái sử dụng sau mỗi phép lấy phần tử ra khỏi hàng đợi.

- Hàng đợi ưu tiên (priority queue): hàng đợi được xây dựng theo nguyên tắc phép đưa phần tử vào hàng đợi được xếp ứng với thứ tự ưu tiên của nó.

- Hàng đợi hai điểm cuối (double ended queue): hàng đợi được xây dựng theo nguyên tắc phép đưa phần tử vào và lấy phần tử ra khỏi hàng đợi được thực hiện ở hai điểm cuối.

    ![](../image/10.%20Queue/image_0.jpg)
