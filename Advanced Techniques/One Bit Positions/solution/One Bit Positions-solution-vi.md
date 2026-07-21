# One Bit Positions - Lời giải

**ID:** 2112 | **URL:** https://cses.fi/problemset/task/2112

## Phương pháp

### Tóm tắt bài toán

Cho chuỗi nhị phân dài $n$, với mỗi khoảng cách $k$ từ 1 đến $n-1$, đếm số cặp vị trí $(i, j)$ với $i - j = k$ và cả hai vị trí đều có bit 1.

### Ý tưởng chính

Đặt $A[i] = 1$ nếu $S[i] = \text{'1'}$, ngược lại 0. Cần tính $\text{ans}[k] = \sum_j A[j] \cdot A[j+k]$, đây là tương quan — không phải tích chập. Để chuyển đổi, định nghĩa $B[i] = A[n-1-i]$ (đảo ngược $A$). Tích chập $C = A * B$ cho:

$$C[m] = \sum_i A[i] \cdot B[m-i] = \sum_i A[i] \cdot A[n-1-m+i]$$

Đặt $m = n-1+k$:

$$C[n-1+k] = \sum_i A[i] \cdot A[i-k]$$

Đây chính là số cặp bit 1 cách nhau $k$ vị trí. **Mẹo đảo ngược** là then chốt: biến tương quan thành tích chập, cho phép dùng FFT trong $O(n \log n)$.

### Thuật toán

1. Tạo mảng $A$ với $A[i] = 1$ nếu $S[i] = \text{'1'}$, ngược lại 0.
2. Tạo mảng $B$ với $B[i] = A[n-1-i]$.
3. Tính tích chập $C = A * B$ bằng FFT (biến đổi xuôi cả hai, nhân điểm, biến đổi ngược).
4. Với mỗi $k$ từ 1 đến $n-1$, xuất $\text{round}(C[n-1+k])$.

### Ví dụ minh họa

Chuỗi: `1001011010` ($n=10$). Vị trí bit '1': 0, 3, 5, 6, 8.

| $k$ | Cặp $(j, j{+}k)$ cùng bit '1' | Đếm |
|-----|-------------------------------|------|
| 1   | (5,6)                         | 1    |
| 2   | (3,5), (6,8)                  | 2    |
| 3   | (0,3), (3,6), (5,8)           | 3    |
| 4   | —                             | 0    |
| 5   | (0,5), (3,8)                  | 2    |
| 6   | (0,6)                         | 1    |
| 7   | —                             | 0    |
| 8   | (0,8)                         | 1    |
| 9   | —                             | 0    |

Kết quả: `1 2 3 0 2 1 0 1 0`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/One%20Bit%20Positions.cpp)
