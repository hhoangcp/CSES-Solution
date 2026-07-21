# Rectangle Cutting - Lời giải

**ID:** 1744 | **URL:** https://cses.fi/problemset/task/1744

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho hình chữ nhật $a \times b$ ($1 \le a, b \le 500$), tìm số lần cắt ít nhất để chia hoàn toàn thành các hình vuông. Mỗi lần cắt chia một hình chữ nhật thành hai hình chữ nhật có cạnh nguyên.

### Ý tưởng cốt lõi

Gọi $dp[n][m]$ là số **mảnh** tối thiểu khi chia hình chữ nhật $n \times m$ thành các hình vuông. Đáp án là $dp[a][b] - 1$ (mỗi lần cắt thêm đúng một mảnh).

Nếu $n = m$, hình chữ nhật đã là hình vuông: $dp[n][n] = 1$. Ngược lại, ta phải thực hiện một nhát cắt đầu tiên — ngang hoặc dọc — rồi tối ưu từng nửa:

$$dp[n][m] = \min\left(\min_{i=1}^{n-1}\big(dp[i][m] + dp[n-i][m]\big),\min_{j=1}^{m-1}\big(dp[n][j] + dp[n][m-j]\big)\right)$$

**Tính đúng (cấu trúc con tối ưu):** Mọi cách cắt đều bắt đầu bằng một nhát cắt đầu (ngang ở $i$ nào đó hoặc dọc ở $j$ nào đó). Sau nhát cắt đó, hai hình chữ nhật con phải được chia tối ưu — nếu không, thay phần chưa tối ưu bằng nghiệm tốt hơn sẽ cải thiện tổng. Quy nạp theo diện tích, $dp[n][m]$ đúng bằng số mảnh tối thiểu.

### Thuật toán

1. Trường hợp cơ sở: $dp[i][i] = 1$ với mọi $i$.
2. Với mỗi $(n, m)$ có $n \neq m$, thử tất cả cách cắt ngang $i = 1 \ldots n-1$ và cắt dọc $j = 1 \ldots m-1$, lấy giá trị nhỏ nhất.
3. Xuất $dp[a][b] - 1$.

### Ví dụ

Đầu vào: $3 \times 5$. Các bài toán con quan trọng:

| Hình chữ nhật | Cắt tốt nhất | Số mảnh |
|---------------|--------------|---------|
| $1 \times k$ | — | $k$ |
| $2 \times 2$ | — | 1 |
| $2 \times 3$ | dọc $j{=}1$ | $2{+}1 = 3$ |
| $2 \times 4$ | dọc $j{=}2$ | $1{+}1 = 2$ |
| $2 \times 5$ | dọc $j{=}1$ | $2{+}2 = 4$ |
| $3 \times 2$ | ngang $i{=}1$ | $2{+}1 = 3$ |
| $3 \times 3$ | — | 1 |
| $3 \times 5$ | dọc $j{=}2$ | $3{+}1 = 4$ |

$dp[3][5] = 4$ mảnh, đáp án $= 4 - 1 = \mathbf{3}$ lần cắt.

Quy trình cắt: $3{\times}5 \xrightarrow{j=2}$ $3{\times}2 + 3{\times}3$; $3{\times}2 \xrightarrow{i=1}$ $1{\times}2 + 2{\times}2$; $1{\times}2 \xrightarrow{j=1}$ hai $1{\times}1$.

## Độ phức tạp

- **Thời gian:** $O(a^2 \cdot b + a \cdot b^2)$ — với mỗi trạng thái $(n, m)$, duyệt $O(n+m)$ vị trí cắt
- **Bộ nhớ:** $O(a \cdot b)$

## Mã nguồn (C++)

[Mã nguồn](../code/Rectangle%20Cutting.cpp)
