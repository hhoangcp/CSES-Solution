# Number Spiral - Lời giải

**ID:** 1071 | **URL:** https://cses.fi/problemset/task/1071

## Phương pháp

### Tóm tắt bài toán

Xoắn số là lưới vô hạn bắt đầu bằng 1 ở góc trên-trái:

```
 1   2   9  10  25
 4   3   8  11  24
 5   6   7  12  23
16  15  14  13  22
17  18  19  20  21
```

Với $t$ truy vấn ($1 \le t \le 10^5$), mỗi truy vấn cho tọa độ $(x, y)$ ($1 \le x, y \le 10^9$, $x$ = hàng, $y$ = cột), tìm giá trị tại ô đó.

### Ý tưởng chính

Gọi $m = \max(x, y)$. Ô $(x, y)$ nằm ở lớp $m$, đường biên ngoài của ô vuông $m \times m$. Ô đường chéo $(m, m)$ là điểm mỏ neo với giá trị $\text{base} = m(m-1) + 1$ (vì lớp $m$ bắt đầu tại $(m-1)^2 + 1$, và $(m, m)$ là ô thứ $m$ trong lớp).

Các ô khác trong cùng lớp lệch từ base khoảng $|m - x|$ hoặc $|m - y|$, hướng dịch phụ thuộc vào tính chẵn/lẻ của lớp:

| Điều kiện | Công thức |
|-----------|-----------|
| $x = y$ | base |
| $x < y$, $y$ lẻ | base $+ (y - x)$ |
| $x < y$, $y$ chẵn | base $- (y - x)$ |
| $x > y$, $x$ lẻ | base $- (x - y)$ |
| $x > y$, $x$ chẵn | base $+ (x - y)$ |

*Trực giác:* Lớp $m$ lẻ — xoắn đi xuống dọc cột $m$ rồi sang trái dọc hàng $m$, nên đi lên từ đường chéo làm giá trị tăng, đi trái làm giảm. Lớp $m$ chẵn — hướng ngược lại.

### Thuật toán

1. Tính $m = \max(x, y)$ và $\text{base} = m(m-1) + 1$.
2. Áp dụng dịch phù hợp từ bảng trên.
3. Xuất kết quả.

### Ví dụ minh họa

Từ đề bài:
- $(x, y) = (2, 3)$: $m = 3$, base $= 7$. $x < y$, $y$ lẻ $\to 7 + 1 = \mathbf{8}$.
- $(x, y) = (1, 1)$: $m = 1$, base $= 1$. $x = y$ $\to \mathbf{1}$.
- $(x, y) = (4, 2)$: $m = 4$, base $= 13$. $x > y$, $x$ chẵn $\to 13 + 2 = \mathbf{15}$.

## Độ phức tạp

- **Thời gian:** $O(1)$ mỗi truy vấn
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Number%20Spiral.cpp)
