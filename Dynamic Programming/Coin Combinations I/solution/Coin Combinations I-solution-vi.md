# Coin Combinations I - Lời giải

**ID:** 1635 | **URL:** https://cses.fi/problemset/task/1635

## Hướng tiếp cận

### Tóm tắt bài toán

Cho $n$ loại đồng xu và tổng tiền $x$, đếm số cách **có thứ tự** để tạo ra tổng $x$ (hai cách sắp xếp khác nhau của cùng các đồng xu được tính riêng).

### Ý tưởng chính

Bài toán yêu cầu đếm cách **có thứ tự** để tạo tổng $x$: dãy $(1,2)$ và $(2,1)$ là hai cách khác nhau. Gọi $dp[i]$ là số cách có thứ tự tạo tổng $i$. Xét đồng xu **cuối cùng** trong dãy: nếu nó có giá trị $c_j$ ($c_j \le i$), phần trước tạo tổng $i - c_j$. Cộng qua mọi đồng xu cuối cùng có thể:

$$dp[i] = \sum_{\substack{j=1 \\ c_j \le i}}^{n} dp[i - c_j]$$

Thứ tự vòng lặp là yếu tố quyết định. Ta duyệt $i$ từ 1 đến $x$ ở **vòng ngoài** và $j$ từ 1 đến $n$ ở **vòng trong**. Cách này tự nhiên phân biệt các dãy theo đồng xu cuối cùng: hai dãy có đồng xu cuối khác nhau thuộc các số hạng khác nhau, hai dãy có đồng xu cuối giống nhưng thứ tự khác nhau đã được phân biệt theo quy nạp trên tiền tố. Điều này đảm bảo không đếm dư (các số hạng rời rạc) và không đếm thiếu (mọi dãy hợp lệ đều có một đồng xu cuối $c_j$, nên được đếm qua $dp[i - c_j]$). Trái ngược với Coin Combinations II, việc đổi thứ tự vòng lặp (đồng xu ngoài, tổng trong) sẽ đếm **không có thứ tự**.

### Thuật toán

1. Khởi tạo $dp[0] = 1$, $dp[1 \ldots x] = 0$.
2. Với $i = 1$ đến $x$:
   - Với $j = 1$ đến $n$:
     - Nếu $c_j \le i$: $dp[i] = (dp[i] + dp[i - c_j]) \bmod (10^9 + 7)$.
3. Kết quả là $dp[x]$.

### Ví dụ minh họa

Input: $n = 3$, đồng xu $= \{2, 3, 5\}$, $x = 9$.

| $i$ | $dp[i]$ | Tính toán |
|:---:|:---:|:---|
| 0 | 1 | Cơ sở |
| 1 | 0 | Không có đồng xu $\le 1$ |
| 2 | 1 | $dp[0] = 1$ |
| 3 | 1 | $dp[1] + dp[0] = 0 + 1$ |
| 4 | 1 | $dp[2] + dp[1] = 1 + 0$ |
| 5 | 3 | $dp[3] + dp[2] + dp[0] = 1 + 1 + 1$ |
| 6 | 2 | $dp[4] + dp[3] + dp[1] = 1 + 1 + 0$ |
| 7 | 5 | $dp[5] + dp[4] + dp[2] = 3 + 1 + 1$ |
| 8 | 6 | $dp[6] + dp[5] + dp[3] = 2 + 3 + 1$ |
| 9 | 8 | $dp[7] + dp[6] + dp[4] = 5 + 2 + 1$ |

Kết quả: $dp[9] = 8$ — 8 cách là $2{+}2{+}5$, $2{+}5{+}2$, $5{+}2{+}2$, $3{+}3{+}3$, $2{+}2{+}2{+}3$, $2{+}2{+}3{+}2$, $2{+}3{+}2{+}2$, $3{+}2{+}2{+}2$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot x)$
- **Không gian:** $O(x)$

## Mã nguồn (C++)

[Mã nguồn](../code/Coin%20Combinations%20I.cpp)
