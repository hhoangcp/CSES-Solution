# GCD Subsets - Lời giải

**ID:** 3161 | **URL:** https://cses.fi/problemset/task/3161

## Đề bài

Cho mảng $n$ số nguyên, mỗi $x_i \le n$. Với mỗi $k$ từ 1 đến $n$, tính số tập con không rỗng có GCD đúng bằng $k$.

## Hướng tiếp cận

### $f(k)$: Số tập con có GCD chia hết cho $k$

Gọi $c_k$ là số phần tử trong mảng chia hết cho $k$. Mọi tập con không rỗng gồm các phần tử chia hết cho $k$ đều có GCD chia hết cho $k$, và ngược lại. Số tập con như vậy là $f(k) = 2^{c_k} - 1$.

### $g(k)$: Bao hàm-loại trừ ngược (Nghịch đảo Möbius)

Gọi $g(k)$ là số tập con có GCD **đúng bằng** $k$. Theo định nghĩa, $f(k) = \sum_{j: k|j} g(j)$ vì mọi tập con GCD đúng $j$ (với $k | j$) đều được đếm trong $f(k)$.

Xử lý từ $k = n$ xuống 1. Khi tính $g(k)$, mọi $g(j)$ với $j > k$ đã biết, nên:

$$g(k) = f(k) - \sum_{j=2k, 3k, \ldots} g(j)$$

## Thuật toán

1. Đếm tần suất: $\text{freq}[v]$ = số lần xuất hiện giá trị $v$.
2. Tính trước $\text{pow2}[i] = 2^i \bmod (10^9{+}7)$.
3. Với $k$ từ $n$ xuống 1:
   - $c_k = \sum_{j=k, 2k, \ldots} \text{freq}[j]$.
   - $f(k) = \text{pow2}[c_k] - 1$.
   - $g(k) = f(k) - \sum_{j=2k, 3k, \ldots} g(j)$.
4. Xuất $g(1), g(2), \ldots, g(n)$.

## Ví dụ minh họa

Mảng: $[5, 4, 4, 2, 3]$.

| $k$ | $c_k$ | $f(k)$ | trừ | $g(k)$ |
|:---:|:-----:|:------:|:---:|:------:|
| 5 | 1 | $2^1-1=1$ | — | **1** |
| 4 | 2 | $2^2-1=3$ | — | **3** |
| 3 | 1 | $2^1-1=1$ | — | **1** |
| 2 | 3 | $2^3-1=7$ | $g(4)=3$ | **4** |
| 1 | 5 | $2^5-1=31$ | $g(2)+g(3)+g(4)+g(5)=9$ | **22** |

Kết quả: `22 4 1 3 1`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/GCD%20Subsets.cpp)
