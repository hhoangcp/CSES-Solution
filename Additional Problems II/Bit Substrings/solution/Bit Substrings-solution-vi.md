# Bit Substrings - Lời giải

**ID:** 2115 | **URL:** https://cses.fi/problemset/task/2115

## Đề bài

Cho xâu nhị phân độ dài $n$, với mỗi $k$ từ $0$ đến $n$, đếm số xâu con không rỗng chứa đúng $k$ số `1`.

## Hướng tiếp cận

### Trường hợp $k = 0$

Xâu con có 0 số `1` gồm toàn các `0` liên tiếp. Một đoạn $c$ số `0` liên tiếp đóng góp $\binom{c+1}{2}$ xâu con. Xử lý riêng.

### Mảng khoảng cách

Gọi vị trí các `1` là $p_1 < p_2 < \cdots < p_m$. Xây mảng $\text{Num}$ độ dài $m + 1$:

- $\text{Num}[0]$ = số `0` trước `1` đầu tiên $+ 1$
- $\text{Num}[i]$ ($1 \leq i \leq m-1$) = số `0` giữa $p_i$ và $p_{i+1}$ $+ 1$
- $\text{Num}[m]$ = số `0` sau `1` cuối cùng $+ 1$

Xâu con từ $a$ đến $b$ chứa đúng các `1` tại $p_{i+1}, \ldots, p_{i+k}$ thì $a$ có $\text{Num}[i]$ cách chọn, $b$ có $\text{Num}[i+k]$ cách. Tổng trên mọi $i$:

$$\text{count}(k) = \sum_{i=0}^{m-k} \text{Num}[i] \cdot \text{Num}[i+k]$$

Đây là tích chập của $\text{Num}$ với mảng đảo — tính bằng FFT trong $O(n \log n)$.

### Ví dụ

Xâu `101`: vị trí `1`: $p_1 = 1, p_2 = 3$. $\text{Num} = [1, 2, 1]$.

| $k$ | Tính toán | Số lượng |
|-----|-----------|----------|
| 0 | 1 đoạn 1 số `0`: $\binom{2}{2} = 1$ | 1 |
| 1 | $1 \cdot 2 + 2 \cdot 1 = 4$ | 4 |
| 2 | $1 \cdot 1 = 1$ | 1 |

Kết quả: `1 4 1 0`.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — FFT chi phối
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Bit%20Substrings.cpp)
