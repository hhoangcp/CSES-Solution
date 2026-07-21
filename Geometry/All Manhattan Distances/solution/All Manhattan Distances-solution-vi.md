# All Manhattan Distances - Lời giải

**ID:** 3411 | **URL:** https://cses.fi/problemset/task/3411

## Phương pháp

### Tóm tắt bài toán

Cho $n$ điểm trên mặt phẳng, tính $\sum_{i < j} (|x_i - x_j| + |y_i - y_j|)$, tổng tất cả khoảng cách Manhattan giữa các cặp điểm không có thứ tự.

### Ý tưởng chính

Khoảng cách Manhattan phân tách thành hai phần $x$ và $y$ độc lập:

$$\sum_{i < j} (|x_i - x_j| + |y_i - y_j|) = \sum_{i < j} |x_i - x_j| + \sum_{i < j} |y_i - y_j|$$

Vậy ta chỉ cần giải bài toán: cho mảng $a$, tính $\sum_{i < j} |a_i - a_j|$.

Sắp xếp $a$ theo thứ tự không giảm. Với $i > j$, ta có $a_i \ge a_j$, nên $|a_i - a_j| = a_i - a_j$. Đóng góp của $a_i$ vào tổng là:

$$\sum_{j=1}^{i-1} (a_i - a_j) = a_i \cdot (i-1) - \text{prefix\_sum}_{i-1}$$

Tổng tất cả đóng góp cho $i$ từ 1 đến $n$ chính là $\sum_{i < j} |a_i - a_j|$. Tổng tiền tố được duy trì tăng dần, mỗi phần tử xử lý trong $O(1)$. Áp dụng độc lập cho mảng $x$ và $y$. Với $n \le 2 \cdot 10^5$ và tọa độ lên tới $10^9$, kết quả có thể vượt phạm vi 64-bit, nên cần dùng `__int128`.

### Thuật toán

1. Đọc tất cả điểm, lưu tọa độ $x$ và $y$ vào hai mảng riêng.
2. Sắp xếp mảng $x$ và mảng $y$ độc lập.
3. Khởi tạo $\text{ans} = 0$, $\text{sumX} = 0$, $\text{sumY} = 0$.
4. Với $i$ từ 0 đến $n-1$:
   - $\text{ans} \mathrel{+}= (x_i + y_i) \cdot i - \text{sumX} - \text{sumY}$
   - $\text{sumX} \mathrel{+}= x_i$, $\text{sumY} \mathrel{+}= y_i$
5. Xuất $\text{ans}$.

### Ví dụ minh họa

$n=5$, điểm: $(1,1), (3,2), (2,4), (2,1), (4,5)$.

$x$ sắp xếp: $[1, 2, 2, 3, 4]$. $y$ sắp xếp: $[1, 1, 2, 4, 5]$.

- $i=0$: đóng góp $x = 1 \cdot 0 - 0 = 0$, đóng góp $y = 1 \cdot 0 - 0 = 0$.
- $i=1$: đóng góp $x = 2 \cdot 1 - 1 = 1$, đóng góp $y = 1 \cdot 1 - 1 = 0$.
- $i=2$: đóng góp $x = 2 \cdot 2 - 3 = 1$, đóng góp $y = 2 \cdot 2 - 2 = 2$.
- $i=3$: đóng góp $x = 3 \cdot 3 - 5 = 4$, đóng góp $y = 4 \cdot 3 - 4 = 8$.
- $i=4$: đóng góp $x = 4 \cdot 4 - 8 = 8$, đóng góp $y = 5 \cdot 4 - 8 = 12$.

Tổng $x$: $0+1+1+4+8 = 14$. Tổng $y$: $0+0+2+8+12 = 22$. Tổng: $14+22 = 36$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/All%20Manhattan%20Distances.cpp)
