# Grid Paths I - Lời giải

**ID:** 1638 | **URL:** https://cses.fi/problemset/task/1638

## Hướng tiếp cận

### Tóm tắt bài toán

Cho lưới $n \times n$ với ô trống (`.`) và bẫy (`*`), đếm số đường đi từ $(1,1)$ đến $(n,n)$ chỉ đi sang phải hoặc xuống dưới, không qua ô bẫy. Kết quả modulo $10^9 + 7$.

### Ý tưởng chính

Gọi $dp[i][j]$ là số đường đi hợp lệ từ $(1,1)$ đến $(i,j)$. Vì chỉ được đi sang phải hoặc xuống dưới, mọi đường đi đến $(i,j)$ phải đến từ $(i{-}1,j)$ (xuống) hoặc $(i,j{-}1)$ (sang phải). Hai loại này rời rạc (bước cuối khác hướng), nên không đếm dư. Mọi đường đi hợp lệ phải đi qua một trong hai ô trước đó ở bước kế cuối, nên không đếm thiếu.

$$dp[i][j] = \begin{cases} (dp[i-1][j] + dp[i][j-1]) \bmod (10^9+7) & \text{nếu ô } (i,j) \text{ trống} \\ 0 & \text{nếu ô } (i,j) \text{ có bẫy} \end{cases}$$

Ô bẫy đóng góp $0$ — không có đường đi nào kết thúc tại đó, và giá trị $0$ tự nhiên lan truyền chặn các đường đi phải đi qua nó.

Trường hợp cơ sở: $dp[1][1] = 1$ nếu trống, $0$ nếu bẫy. Biên: $dp[i][0] = dp[0][j] = 0$.

### Thuật toán

1. Khởi tạo $dp[0][\cdot] = dp[\cdot][0] = 0$.
2. Với $i = 1$ đến $n$, $j = 1$ đến $n$:
   - Nếu $(i,j)$ là bẫy: $dp[i][j] = 0$.
   - Nếu $(i,j) = (1,1)$ và trống: $dp[1][1] = 1$.
   - Ngược lại: $dp[i][j] = (dp[i{-}1][j] + dp[i][j{-}1]) \bmod (10^9 + 7)$.
3. In ra $dp[n][n]$.

### Ví dụ minh họa

Input: $n = 4$, lưới (bẫy tại $(2,2)$, $(3,4)$, $(4,1)$):

```
. . . .
. * . .
. . . *
* . . .
```

| | $j{=}1$ | $j{=}2$ | $j{=}3$ | $j{=}4$ |
|:---:|:---:|:---:|:---:|:---:|
| $i{=}1$ | 1 | 1 | 1 | 1 |
| $i{=}2$ | 1 | 0 | 1 | 2 |
| $i{=}3$ | 1 | 1 | 2 | 0 |
| $i{=}4$ | 0 | 1 | 3 | 3 |

Nhận xét: $dp[2][2]=0$ (bẫy) chặn hàng 2 từ bên trái. $dp[3][4]=0$ (bẫy) buộc mọi đường qua hàng 4 phải đến từ $(4,3)$. $dp[4][1]=0$ (bẫy) nhưng $(4,2)$ vẫn đến được từ $(3,2)$.

Kết quả: $dp[4][4] = 3$.

## Độ phức tạp

- **Thời gian:** $O(n^2)$
- **Không gian:** $O(n^2)$ (tối ưu được $O(n)$ bằng mảng cuộn)

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Paths%20I.cpp)
