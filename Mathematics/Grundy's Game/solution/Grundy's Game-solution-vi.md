# Grundy's Game - Lời giải

**ID:** 2207 | **URL:** https://cses.fi/problemset/task/2207

## Phương pháp

### Tóm tắt bài toán

Có một đống gồm $n$ đồng xu. Hai người chơi luân phiên đi, mỗi lượt chọn một đống có ít nhất 3 đồng và chia thành hai đống không rỗng có kích thước **khác nhau**. Người đi cuối cùng thắng. Xác định người thắng khi cả hai chơi tối ưu.

### Ý tưởng chính

Bài toán là trò chơi tổ hợp trung lập (impartial game), nên **lý thuyết Sprague-Grundy** áp dụng được. Đống kích thước $n$ có thể chia thành $(j, n-j)$ với $1 \le j < n/2$ và $j \neq n-j$. Sau khi chia, hai đống tạo thành **tổng rời rạc** (disjunctive sum) của các trò chơi con độc lập. Giá trị Grundy:

$$G(n) = \text{mex}\{G(j) \oplus G(n-j) : 1 \le j < n/2\}$$

Cơ sở: $G(0) = G(1) = G(2) = 0$ (không có nước chia hợp lệ). Người đi trước thắng khi và chỉ khi $G(n) \neq 0$.

**Nhận xét thực nghiệm:** $G(n) = 0$ chỉ xuất hiện ở hữu hạn giá trị nhỏ của $n$. Vị thế thua cuối cùng là $n = 1222$; với mọi $n > 1222$, $G(n) > 0$. Nguyên nhân là khi $n$ đủ lớn, số cách chia tăng nhanh, tạo ra tập Nim-sum phong phú luôn bao gồm giá trị 0, nên $\text{mex}$ không bao giờ trả về 0.

Do đó, ta tính trước $G(n)$ cho $n < 2000$ (ngưỡng an toàn vượt quá 1222) và kết luận người đi trước luôn thắng với $n \geq 2000$.

### Thuật toán

1. Tính trước $G(n)$ cho $n = 0, 1, \ldots, 1999$ bằng định nghĩa mex.
2. Với mỗi truy vấn $n$: nếu $n \geq 2000$ hoặc $G(n) \neq 0$, xuất "first"; ngược lại xuất "second".

### Ví dụ minh họa

Tính một số giá trị Grundy đầu tiên:

| $n$ | Cách chia | Nim-sum | $G(n)$ |
|-----|-----------|---------|--------|
| 3 | $(1,2)$ | $\{0\}$ | 1 |
| 4 | $(1,3)$ | $\{1\}$ | 0 |
| 5 | $(1,4),(2,3)$ | $\{0,1\}$ | 2 |
| 6 | $(1,5),(2,4)$ | $\{2,0\}$ | 1 |
| 7 | $(1,6),(2,5),(3,4)$ | $\{1,2\}$ | 0 |
| 8 | $(1,7),(2,6),(3,5)$ | $\{0,1,3\}$ | 2 |

Theo ví dụ đề bài: $n = 6, 7, 8$.

- $G(6) = 1 \neq 0$ → "first"
- $G(7) = 0$ → "second"
- $G(8) = 2 \neq 0$ → "first"

## Độ phức tạp

- **Thời gian:** $O(N^2)$ tiền tính toán với $N = 2000$, $O(1)$ mỗi truy vấn
- **Không gian:** $O(N)$

## Mã nguồn (C++)

[Mã nguồn](../code/Grundy%27s%20Game.cpp)
