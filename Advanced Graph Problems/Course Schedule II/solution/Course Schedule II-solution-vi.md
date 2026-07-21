# Course Schedule II - Lời giải

**ID:** 1757 | **URL:** https://cses.fi/problemset/task/1757

## Phương pháp

### Tóm tắt bài toán

Cho $n$ khóa học và $m$ cặp điều kiện tiên quyết $(a, b)$ nghĩa là khóa $a$ phải hoàn thành trước khóa $b$. Tìm thứ tự topo sao cho khóa 1 xuất hiện sớm nhất có thể, rồi khóa 2, v.v. (thứ tự từ điển nhỏ nhất).

### Ý tưởng chính

Một sai lầm phổ biến là dùng Kahn với min-heap để lấy đỉnh nhỏ nhất trước — điều này không đảm bảo tối ưu toàn cục vì chọn một đỉnh nhỏ sớm có thể "giam cầm" các đỉnh nhỏ hơn khác ở phía sau.

Chiến thuật đúng là **xây dựng từ dưới lên**: luôn chọn khóa có chỉ số lớn nhất để đặt vào vị trí cuối cùng. Hoãn nút lớn nhất đến vị trí muộn nhất giải phóng các nút nhỏ hơn để chiếm vị trí sớm hơn. Sau khi đảo ngược, dãy kết quả có thứ tự từ điển nhỏ nhất.

### Thuật toán

1. Xây đồ thị ngược: với mỗi điều kiện $a \to b$, lưu cạnh $b \to a$ và tăng bậc ra của $a$.
2. Khởi tạo **max-heap** với tất cả đỉnh có bậc ra bằng 0.
3. Lặp lại: rút đỉnh lớn nhất $u$ từ heap, thêm vào danh sách kết quả, giảm bậc ra của tất cả tiền nhiệm. Nếu bậc ra của tiền nhiệm trở thành 0, đẩy vào heap.
4. Đảo ngược danh sách kết quả và xuất.

### Ví dụ minh họa

$n=4$, $m=2$, điều kiện: $2 \to 1$, $2 \to 3$.

Bậc ra: out$[2]=2$, out$[1]=0$, out$[3]=0$, out$[4]=0$. Heap = $\{4, 3, 1\}$.

- Rút 4. Đáp án: [4].
- Rút 3. Đáp án: [4, 3]. out$[2]=1$.
- Rút 1. Đáp án: [4, 3, 1]. out$[2]=0$. Đẩy 2.
- Rút 2. Đáp án: [4, 3, 1, 2].

Đảo ngược: **2 1 3 4**.

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Course%20Schedule%20II.cpp)
