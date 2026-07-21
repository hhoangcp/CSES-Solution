# Knight Moves Queries - Lời giải

**ID:** 3218 | **URL:** https://cses.fi/problemset/task/3218

## Đề bài

Mã bắt đầu ở $(x, y)$ trên bàn cờ vô hạn. Tìm số bước tối thiểu để đến góc trái trên $(1, 1)$.

## Hướng tiếp cận

### Cận dưới vật lý: 3 ràng buộc

Chuyển tọa độ tương đối: $x' = x - 1$, $y' = y - 1$, mục tiêu về $(0, 0)$. Mỗi bước mã đổi $x'$ tối đa 2, $y'$ tối đa 2, $x' + y'$ tối đa 3. Số bước $d$ phải thỏa mãn:

1. $d \ge \lceil x'/2 \rceil$ — cần đủ bước giảm $x'$ về 0.
2. $d \ge \lceil y'/2 \rceil$ — cần đủ bước giảm $y'$ về 0.
3. $d \ge \lceil (x'+y')/3 \rceil$ — cần đủ bước giảm tổng về 0.

Cận dưới hợp lệ: $d_0 = \max$ của ba giá trị trên.

### Ràng buộc tính chẵn lẻ: $d$ phải cùng parity với $x' + y'$

Mỗi bước mã đổi $x' + y'$ đúng $\pm 1$ hoặc $\pm 3$ (đều lẻ). Sau $d$ bước, tổng thay đổi cùng parity với $d$. Đích $(0, 0)$ có tổng 0, nên **$d$ và $x' + y'$ phải cùng parity**. Nếu $d_0 + x' + y'$ lẻ, tăng $d_0$ lên 1.

Với $x', y'$ đủ lớn (ngoài 4 trường hợp đặc biệt), cận dưới luôn đạt được sau điều chỉnh parity — vì đủ "không gian" để phân bổ bước giảm $x'$ và $y'$, và bước dư (nếu có) dùng để tiêu hao (đi lùi rồi đi lại).

### 4 trường hợp đặc biệt: Thiếu không gian điều chỉnh

Tại các vị trí rất gần $(0, 0)$, hình học bước mã không cho phép giảm cả $x'$ và $y'$ đủ nhanh. Cần cộng thêm 2 bước:

- $(0, 1)$ và $(1, 0)$: $d_0 = 1$, thực tế cần 3 bước.
- $(1, 1)$: $d_0 = 1$, thực tế cần 4 bước.
- $(2, 2)$: $d_0 = 2$, thực tế cần 4 bước.

## Thuật toán

1. Chuyển 0-indexed: $x' = x - 1$, $y' = y - 1$.
2. Tính $d = \max\left(\lceil x'/2 \rceil, \lceil y'/2 \rceil, \lceil (x'+y')/3 \rceil\right)$.
3. Nếu $x' + y' + d$ lẻ, $d \gets d + 1$.
4. Nếu $(x', y') \in \{(0,1), (1,0), (1,1), (2,2)\}$, $d \gets d + 2$.
5. Xuất $d$.

## Ví dụ minh họa

$(42, 1337)$: $x' = 41$, $y' = 1336$.

- $d_0 = \max(\lceil 41/2 \rceil, \lceil 1336/2 \rceil, \lceil 1377/3 \rceil) = \max(21, 668, 459) = 668$.
- $x' + y' + d = 41 + 1336 + 668 = 2045$ (lẻ). Tăng $d$ lên 1: $d = 669$.
- Kết quả: **669**.

## Độ phức tạp

- **Thời gian:** $O(1)$ mỗi truy vấn
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Knight%20Moves%20Queries.cpp)
