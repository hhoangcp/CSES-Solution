# Counting Towers - Lời giải

**ID:** 2413 | **URL:** https://cses.fi/problemset/task/2413

## Hướng tiếp cận

### Tóm tắt bài toán

Đếm số cách xây tháp rộng 2, cao $n$ bằng các khối kích thước nguyên, sao cho mỗi hàng được lấp đầy. Có $t$ truy vấn. Kết quả modulo $10^9 + 7$.

### Ý tưởng chính

Tại mỗi hàng, chỉ có hai profile quan trọng: **tách** (hai cột riêng biệt) hoặc **gộp** (một khối chiếm toàn chiều rộng 2). Profile của hàng trước quyết định cách đặt hàng sau.

Gọi $dp[i][0]$ = số cách xây tháp cao $i$ mà hàng trên cùng **tách**, và $dp[i][1]$ = số cách xây tháp cao $i$ mà hàng trên cùng **gộp**.

**Từ trạng thái tách ($dp[i{-}1][0]$):** Mỗi cột có thể kéo dài lên hoặc bị kín bằng khối $1 \times 1$ mới — 2 lựa chọn mỗi cột, được $2 \times 2 = 4$ cách giữ nguyên tách. Hoặc đặt khối $2 \times 1$ đè cả hai cột — 1 cách chuyển sang gộp.

**Từ trạng thái gộp ($dp[i{-}1][1]$):** Đặt hai khối $1 \times 1$ riêng biệt lên trên — 1 cách chuyển sang tách. Hoặc kéo dài khối gộp lên / đặt khối $2 \times 1$ mới lên trên — 2 cách giữ nguyên gộp.

$$dp[i][0] = 4 \cdot dp[i-1][0] + dp[i-1][1]$$
$$dp[i][1] = dp[i-1][0] + 2 \cdot dp[i-1][1]$$

Mỗi tháp tương ứng duy nhất với một dãy profile $(s_1, \ldots, s_n)$ với $s_k \in \{\text{tách}, \text{gộp}\}$, và quá trình xây từ dưới lên chỉ có một cách chuyển cho mỗi cặp trạng thái liên tiếp, nên không đếm trùng. Mọi tháp hợp lệ đều phân tích được thành tháp cao $i{-}1$ cộng hàng trên cùng, nên không đếm thiếu.

### Thuật toán

1. Khởi tạo $dp[1][0] = dp[1][1] = 1$.
2. Tiền tính $dp[i][0]$ và $dp[i][1]$ với $i = 2$ đến $10^6$ bằng công thức truy hồi.
3. Với mỗi truy vấn $n$: in ra $(dp[n][0] + dp[n][1]) \bmod (10^9 + 7)$.

### Ví dụ minh họa

Input: $t = 3$, các truy vấn $n = 2, 6, 1337$.

| $i$ | $dp[i][0]$ | $dp[i][1]$ | Tổng |
|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 2 |
| 2 | $4 \cdot 1 + 1 = 5$ | $1 + 2 \cdot 1 = 3$ | 8 |
| 3 | $4 \cdot 5 + 3 = 23$ | $5 + 2 \cdot 3 = 11$ | 34 |
| 4 | $4 \cdot 23 + 11 = 103$ | $23 + 2 \cdot 11 = 45$ | 148 |
| 5 | $4 \cdot 103 + 45 = 457$ | $103 + 2 \cdot 45 = 193$ | 650 |
| 6 | $4 \cdot 457 + 193 = 2021$ | $457 + 2 \cdot 193 = 843$ | 2864 |

- $n = 2$: tổng $= 8$.
- $n = 6$: tổng $= 2864$.
- $n = 1337$: tổng $= 640403945$.

## Độ phức tạp

- **Thời gian:** $O(N_{\max} + t)$ — tiền tính tuyến tính + $O(1)$ mỗi truy vấn
- **Không gian:** $O(N_{\max})$

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Towers.cpp)
