# Water Containers Moves - Lời giải

**ID:** 3213 | **URL:** https://cses.fi/problemset/task/3213

## Đề bài

Hai bình chứa nước dung tích $a$ và $b$. Tìm dãy thao tác để có đúng $x$ đơn vị trong bình $A$, tối thiểu hóa tổng lượng nước di chuyển. Nếu không thể, xuất -1.

## Hướng tiếp cận

### Dijkstra trên đồ thị trạng thái

Trạng thái: $(u_a, u_b)$. Ban đầu: $(0, 0)$. Trọng số mỗi cạnh = lượng nước di chuyển.

| Thao tác | Trạng thái mới | Chi phí |
|----------|---------------|---------|
| FILL A | $(a, u_b)$ | $a - u_a$ |
| FILL B | $(u_a, b)$ | $b - u_b$ |
| EMPTY A | $(0, u_b)$ | $u_a$ |
| EMPTY B | $(u_a, 0)$ | $u_b$ |
| MOVE A→B | $(u_a - m, u_b + m)$ | $m = \min(u_a, b - u_b)$ |
| MOVE B→A | $(u_a + m, u_b - m)$ | $m = \min(u_b, a - u_a)$ |

Vì mọi trọng số cạnh không âm, Dijkstra tìm đường đi có tổng lượng nước di chuyển tối thiểu. Dừng khi $u_a = x$. Truy vết ngược để khôi phục dãy thao tác.

### Ví dụ

$a = 5, b = 3, x = 4$:

| Bước | Thao tác | Trạng thái | Chi phí |
|------|----------|-----------|---------|
| 1 | FILL A | (5, 0) | 5 |
| 2 | MOVE A→B | (2, 3) | 3 |
| 3 | EMPTY B | (2, 0) | 3 |
| 4 | MOVE A→B | (0, 2) | 2 |
| 5 | FILL A | (5, 2) | 5 |
| 6 | MOVE A→B | (4, 3) | 1 |

Tổng: **6 bước, 19 đơn vị nước di chuyển**.

## Độ phức tạp

- **Thời gian:** $O(ab \log(ab))$ — tối đa $(a+1)(b+1)$ trạng thái
- **Bộ nhớ:** $O(ab)$ cho mảng khoảng cách và truy vết

## Mã nguồn (C++)

[Mã nguồn](../code/Water%20Containers%20Moves.cpp)
