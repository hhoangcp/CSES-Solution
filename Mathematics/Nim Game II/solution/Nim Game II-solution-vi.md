# Nim Game II - Lời giải

**ID:** 1098 | **URL:** https://cses.fi/problemset/task/1098

## Phương pháp

### Tóm tắt bài toán

Có $n$ đống que, hai người chơi luân phiên đi. Mỗi lượt, người chơi chọn một đống không rỗng và lấy **đúng 1, 2, hoặc 3** que. Người lấy que cuối cùng thắng. Xác định người thắng khi cả hai chơi tối ưu.

### Ý tưởng chính

Đây là biến thể Nim có giới hạn số que lấy (trò chơi trung lập), nên **lý thuyết Sprague-Grundy** áp dụng được. Với một đống $x$ que, giới hạn lấy 1–3, giá trị Grundy là:

$$G(x) = \text{mex}\{G(x-1), G(x-2), G(x-3)\}, \quad G(0) = 0$$

Tính thử các giá trị đầu tiên cho thấy quy luật tuần hoàn:

| $x$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|-----|---|---|---|---|---|---|---|---|---|
| $G(x)$ | 0 | 1 | 2 | 3 | 0 | 1 | 2 | 3 | 0 |

**Khẳng định:** $G(x) = x \bmod 4$.

**Chứng minh quy nạp.** Cơ sở $x = 0, 1, 2, 3$ kiểm tra trực tiếp. Bước quy nạp: giả sử $G(y) = y \bmod 4$ với mọi $y < x$, xét theo $x \bmod 4$:

- $x \equiv 0$: các ô kế có Grundy $\{3, 2, 1\}$, $\text{mex}\{1, 2, 3\} = 0$.
- $x \equiv 1$: các ô kế có $\{0, 3, 2\}$, $\text{mex}\{0, 2, 3\} = 1$.
- $x \equiv 2$: các ô kế có $\{1, 0, 3\}$, $\text{mex}\{0, 1, 3\} = 2$.
- $x \equiv 3$: các ô kế có $\{2, 1, 0\}$, $\text{mex}\{0, 1, 2\} = 3$.

Theo lý thuyết Sprague-Grundy, nhiều đống độc lập kết hợp bằng XOR. Giá trị Grundy tổng thể:

$$S = \bigoplus_{i=1}^{n} (x_i \bmod 4)$$

Người đi trước thắng nếu $S \neq 0$, thua nếu $S = 0$.

### Thuật toán

Với mỗi test case, tính XOR tất cả $x_i \bmod 4$. Nếu khác 0, xuất "first"; ngược lại xuất "second".

### Ví dụ minh họa

| Đống que | $x_i \bmod 4$ | XOR | Người thắng |
|----------|---------------|-----|-------------|
| $\{5, 7, 2, 5\}$ | $\{1, 3, 2, 1\}$ | $1 \oplus 3 \oplus 2 \oplus 1 = 1 \neq 0$ | first |
| $\{4, 1\}$ | $\{0, 1\}$ | $0 \oplus 1 = 1 \neq 0$ | first |
| $\{4, 4, 4\}$ | $\{0, 0, 0\}$ | $0 \oplus 0 \oplus 0 = 0$ | second |

## Độ phức tạp

- **Thời gian:** $O(n)$ mỗi test case
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Nim%20Game%20II.cpp)
