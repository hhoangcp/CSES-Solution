# Coin Combinations II - Lời giải

**ID:** 1636 | **URL:** https://cses.fi/problemset/task/1636

## Hướng tiếp cận

### Tóm tắt bài toán

Cho $n$ loại đồng xu và tổng tiền $x$, đếm số cách **không có thứ tự** để tạo ra tổng $x$ (hai cách sắp xếp khác nhau của cùng một multiset chỉ tính là một).

### Ý tưởng chính

Đây là biến thể **không có thứ tự** của Coin Combinations I: hai cách sắp xếp khác nhau của cùng một multiset chỉ tính một. Chìa khóa là thứ tự vòng lặp — duyệt **đồng xu ở vòng ngoài** và **tổng ở vòng trong** ép một thứ tự chuẩn cho các đồng xu.

Gọi $dp[i]$ là số cách không có thứ tự tạo tổng $i$ bằng các đồng xu đã xét. Sau khi xử lý $c_1, \ldots, c_j$, $dp[i]$ đếm cách chỉ dùng các đồng xu đó. Khi thêm $c_{j+1}$ (duyệt $i$ từ $c_{j+1}$ đến $x$ xuôi), ta mở rộng mỗi multiset hiện có bằng $0, 1, 2, \ldots$ bản sao của $c_{j+1}$. Việc duyệt xuôi trên $i$ cho phép dùng $c_{j+1}$ nhiều lần trong cùng một vòng.

Không đếm dư: mỗi multiset có một bộ số đếm $(a_1, \ldots, a_n)$ duy nhất. Đồng xu $c_j$ chỉ được giới thiệu ở bước $j$, nên multiset chỉ được xây dựng đúng một cách — thêm $a_j$ bản sao $c_j$ ở bước $j$. Không đếm thiếu: mọi multiset hợp lệ tạo tổng $x$ sẽ được xây dựng khi loại đồng xu cuối cùng trong tập được xử lý.

Trái ngược với Coin Combinations I (tổng ngoài, đồng xu trong): ở đó mỗi vị trí trong dãy tự do chọn đồng xu, nên các hoán vị khác nhau được đếm riêng.

### Thuật toán

1. Khởi tạo $dp[0] = 1$, $dp[1 \ldots x] = 0$.
2. Với $j = 1$ đến $n$:
   - Với $i = c_j$ đến $x$: $dp[i] = (dp[i] + dp[i - c_j]) \bmod (10^9 + 7)$.
3. Kết quả là $dp[x]$.

### Ví dụ minh họa

Input: $n = 3$, đồng xu $= \{2, 3, 5\}$, $x = 9$.

**Sau $c_1 = 2$:** $dp = [1, 0, 1, 0, 1, 0, 1, 0, 1, 0]$

| $i$ | $dp[i]$ | Cách |
|:---:|:---:|:---|
| 2 | 1 | $\{2\}$ |
| 4 | 1 | $\{2,2\}$ |
| 6 | 1 | $\{2,2,2\}$ |
| 8 | 1 | $\{2,2,2,2\}$ |

**Sau $c_2 = 3$:** $dp = [1, 0, 1, 1, 1, 1, 2, 1, 2, 2]$

| $i$ | $dp[i]$ | Cách mới thêm |
|:---:|:---:|:---|
| 5 | 1 | $\{2,3\}$ |
| 9 | 2 | $\{2,2,2,3\}$, $\{3,3,3\}$ |

**Sau $c_3 = 5$:** $dp = [1, 0, 1, 1, 1, 2, 2, 2, 3, 3]$

| $i$ | $dp[i]$ | Cách mới thêm |
|:---:|:---:|:---|
| 9 | 3 | $\{2,2,5\}$ |

Kết quả: $dp[9] = 3$ — 3 cách là $\{2,2,5\}$, $\{3,3,3\}$, $\{2,2,2,3\}$.

So với Coin Combinations I cùng đầu vào cho 8 cách có thứ tự, 8 dãy thu gọn thành 3 multiset.

## Độ phức tạp

- **Thời gian:** $O(n \cdot x)$
- **Không gian:** $O(x)$

## Mã nguồn (C++)

[Mã nguồn](../code/Coin%20Combinations%20II.cpp)
