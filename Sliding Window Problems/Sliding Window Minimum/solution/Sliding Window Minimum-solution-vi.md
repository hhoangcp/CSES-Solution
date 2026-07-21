# Sliding Window Minimum - Lời giải

**ID:** 3221 | **URL:** https://cses.fi/problemset/task/3221

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên (được sinh theo $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$), tìm giá trị nhỏ nhất của mỗi cửa sổ trượt $k$ phần tử. Xuất XOR của tất cả các giá trị nhỏ nhất. Lưu ý: $n$ có thể lên tới $10^7$, cần thuật toán $O(n)$ và tránh xuất từng giá trị riêng lẻ.

### Ý tưởng chính

Sử dụng hàng đợi hai đầu đơn điệu lưu chỉ số theo thứ tự không giảm của giá trị. Phần tử đầu hàng đợi luôn là chỉ số của giá trị nhỏ nhất trong cửa sổ hiện tại. Mỗi chỉ số được đẩy vào đúng một lần và bị loại tối đa một lần, tổng chi phí $O(n)$.

### Thuật toán

**Bước 1: Sinh mảng.** Tính $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$ với $i \ge 2$. Dùng phép nhân 64-bit để tránh tràn.

**Bước 2: Hàng đợi đơn điệu.** Với mỗi vị trí $i$:
1. Xóa từ cuối: loại các chỉ số $j$ có $x[j] \ge x[i]$. Các phần tử này không thể là nhỏ nhất cho bất kỳ cửa sổ tương lai nào chứa $i$, vì $x[i]$ nhỏ hơn và tồn tại trong cửa sổ lâu hơn.
2. Xóa từ đầu: loại các chỉ số $\le i - k$ (nằm ngoài cửa sổ hiện tại).
3. Đẩy $i$ vào cuối hàng đợi.
4. Khi $i \ge k$: giá trị nhỏ nhất là $x[\text{dq.front()}]$. XOR vào đáp án.

Sau bước 1 và 3, hàng đợi có giá trị không giảm, nên đầu hàng đợi luôn là nhỏ nhất. Không có ứng viên tối ưu nào bị mất: xóa cuối chỉ loại phần tử bị trội bởi phần tử nhỏ hơn mới hơn; xóa đầu chỉ loại phần tử đã rời cửa sổ.

### Ví dụ minh họa

Với $n=8$, $k=5$, bộ sinh $x=3, a=7, b=1, c=11$:

Mảng sinh ra: $[3, 0, 1, 8, 2, 4, 7, 6]$.

Dấu vết hàng đợi (chỉ số 1-indexed):
- $i=1$: đẩy 1. dq=[1]
- $i=2$: $x[1]=3 \ge 0$, xóa 1. Đẩy 2. dq=[2]
- $i=3$: đẩy 3. dq=[2,3]
- $i=4$: đẩy 4. dq=[2,3,4]
- $i=5$: $x[4]=8 \ge 2$, xóa 4. Đẩy 5. dq=[2,3,5]. Min $= x[2] = 0$
- $i=6$: đẩy 6. dq=[2,3,5,6]. Min $= x[2] = 0$
- $i=7$: đầu 2 $\le 7-5$, xóa đầu. dq=[3,5,6]. Đẩy 7. dq=[3,5,6,7]. Min $= x[3] = 1$
- $i=8$: $x[7]=7 \ge 6$, xóa 7. Đầu 3 $\le 8-5$, xóa đầu. dq=[5,6]. Đẩy 8. dq=[5,6,8]. Min $= x[5] = 2$

Các giá trị nhỏ nhất: $0, 0, 1, 2$. Đáp án: $0 \oplus 0 \oplus 1 \oplus 2 = 3$.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Minimum.cpp)
