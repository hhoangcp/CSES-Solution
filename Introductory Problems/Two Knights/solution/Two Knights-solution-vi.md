# Two Knights - Lời giải

**ID:** 1072 | **URL:** https://cses.fi/problemset/task/1072

## Hướng tiếp cận

### Tóm tắt bài toán

Với mỗi $k$ từ 1 đến $n$ ($1 \le n \le 10000$), đếm số cách đặt hai mã trên bàn cờ $k \times k$ sao cho chúng **không** tấn công nhau.

### Ý tưởng chính

Dùng đếm bù: số cách hợp lệ = tổng số cách đặt − số cách hai mã tấn công nhau.

**Tổng số cách đặt.** Bàn cờ có $k^2$ ô. Chọn 2 ô khác nhau (không phân biệt thứ tự):

$$\binom{k^2}{2} = \frac{k^2(k^2 - 1)}{2}$$

**Số cách tấn công nhau.** Mã di chuyển theo hình chữ "L" (2 ô theo một hướng, 1 ô vuông góc). Hai mã tấn công nhau khi và chỉ khi chúng nằm ở hai đỉnh đối diện của hình chữ nhật $2 \times 3$ hoặc $3 \times 2$. Điều này đúng vì hiệu tọa độ giữa hai ô phải là $(\pm 1, \pm 2)$ hoặc $(\pm 2, \pm 1)$, chính xác mô tả hai đỉnh đối diện của các hình chữ nhật đó.

Mỗi hình chữ nhật $2 \times 3$: góc trên-trái có $(k-1)$ lựa chọn hàng và $(k-2)$ lựa chọn cột → $(k-1)(k-2)$ hình. Mỗi hình có đúng 2 cặp đỉnh đối diện. Tương tự, mỗi hình chữ nhật $3 \times 2$ cho $(k-2)(k-1)$ hình với 2 cặp tấn công. Tổng:

$$\text{Tấn công} = 2(k-1)(k-2) + 2(k-2)(k-1) = 4(k-1)(k-2)$$

**Công thức cuối cùng:**

$$\text{Kết quả} = \frac{k^2(k^2 - 1)}{2} - 4(k-1)(k-2)$$

### Thuật toán

Với mỗi $k$ từ 1 đến $n$, tính công thức trên và xuất kết quả.

### Ví dụ minh họa

**Ví dụ đề bài ($n = 8$):**

| $k$ | $\binom{k^2}{2}$ | $4(k-1)(k-2)$ | Kết quả |
|---|---|---|---|
| 1 | 0 | 0 | 0 |
| 2 | 6 | 0 | 6 |
| 3 | 36 | 8 | 28 |
| 4 | 120 | 24 | 96 |
| 5 | 300 | 48 | 252 |
| 6 | 630 | 80 | 550 |
| 7 | 1176 | 120 | 1056 |
| 8 | 2016 | 168 | 1848 |

## Độ phức tạp

- **Thời gian:** $O(n)$ — $O(1)$ cho mỗi giá trị $k$
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Two%20Knights.cpp)
