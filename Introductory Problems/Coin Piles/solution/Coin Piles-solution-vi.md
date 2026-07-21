# Coin Piles - Lời giải

**ID:** 1754 | **URL:** https://cses.fi/problemset/task/1754

## Phương pháp

### Tóm tắt bài toán

Cho $t$ test case ($1 \le t \le 10^5$), mỗi test cho hai đống xu $a$ và $b$ ($0 \le a, b \le 10^9$). Mỗi nước đi phải lấy đúng 1 xu từ một đống và 2 xu từ đống còn lại. Xác định có thể làm rỗng cả hai đống hay không.

### Ý tưởng chính

Mô hình mỗi nước đi là lựa chọn giữa hai loại:
- **Loại X:** lấy 1 từ $a$ và 2 từ $b$. Gọi $x$ là số lần.
- **Loại Y:** lấy 2 từ $a$ và 1 từ $b$. Gọi $y$ là số lần.

Cả hai đống rỗng khi và chỉ khi: $\begin{cases} x + 2y = a \\ 2x + y = b \end{cases}$

Cộng hai phương trình: $3(x+y) = a+b$, suy ra $(a+b)$ phải chia hết cho 3. Giải ra: $x = \frac{2b-a}{3}$, $y = \frac{2a-b}{3}$.

Để có nghiệm hợp lệ, $x$ và $y$ phải là số nguyên không âm. Điều này cho các điều kiện cần và đủ:

1. $(a+b) \bmod 3 = 0$
2. $a \leq 2b$ (đảm bảo $x \geq 0$)
3. $b \leq 2a$ (đảm bảo $y \geq 0$)

Hoặc gọn: $\max(a,b) \leq 2 \cdot \min(a,b)$.

**Tính đúng đắn:** Nếu cả ba điều kiện thỏa mãn, $x$ và $y$ là số nguyên không âm thỏa hệ phương trình, tương ứng với một dãy nước đi cụ thể làm rỗng cả hai đống. Ngược lại, nếu có điều kiện vi phạm, không tồn tại $(x,y)$ hợp lệ — hoặc tổng xu không chia hết cho 3, hoặc một đống quá lớn so với đống kia để đáp ứng tỷ lệ 1:2.

### Thuật toán

Với mỗi test case, kiểm tra:
1. $(a+b) \bmod 3 = 0$
2. $\max(a,b) \leq 2 \cdot \min(a,b)$

Nếu cả hai đúng, xuất "YES"; ngược lại "NO".

### Ví dụ minh họa

Từ đề bài:
- $(a,b) = (2,1)$: tổng = 3 (chia hết cho 3), $\max(2,1) = 2 \leq 2 \cdot 1 = 2$. **YES** ($x=0, y=1$).
- $(a,b) = (2,2)$: tổng = 4 (không chia hết cho 3). **NO**.
- $(a,b) = (3,3)$: tổng = 6 (chia hết cho 3), $\max(3,3) = 3 \leq 2 \cdot 3 = 6$. **YES** ($x=1, y=1$).

## Độ phức tạp

- **Thời gian:** $O(1)$ mỗi test case
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Coin%20Piles.cpp)
