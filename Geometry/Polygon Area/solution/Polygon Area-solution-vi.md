# Polygon Area - Lời giải

**ID:** 2191 | **URL:** https://cses.fi/problemset/task/2191

## Phương pháp

### Tóm tắt bài toán

Tính diện tích của đa giác đơn cho trước. Kết quả in ra $2a$ với $a$ là diện tích (đảm bảo kết quả nguyên).

### Ý tưởng chính

Sử dụng công thức Shoelace. Cho đa giác có các đỉnh $(x_1, y_1), \ldots, (x_n, y_n)$ theo thứ tự:

$$2A = \left|\sum_{i=1}^{n} (x_i y_{i+1} - x_{i+1} y_i)\right|$$

với $x_{n+1} = x_1$ và $y_{n+1} = y_1$. Mỗi số hạng $x_i y_{i+1} - x_{i+1} y_i$ là hai lần diện tích có hướng của tam giác $O p_i p_{i+1}$ (với $O$ là gốc tọa độ). Với đa giác lồi có đỉnh ngược chiều kim đồng hồ, tổng các diện tích có hướng này bằng diện tích đa giác — các tam giác phủ kín đa giác không chồng lấp. Với chiều kim đồng hồ, tổng mang dấu âm. Với đa giác đơn không lồi, công thức vẫn đúng vì các phần "dư" do tam giác vươn ra ngoài bị triệt tiêu bởi các tam giác có diện tích có hướng âm. Giá trị tuyệt đối cho diện tích thực.

Một dạng tương đương dễ cài đặt hơn:

$$2A = \left|\sum_{i=1}^{n} (x_i - x_{i-1})(y_i + y_{i-1})\right|$$

với $x_0 = x_n$, $y_0 = y_n$. Khai triển cho thấy các số hạng $x_i y_i$ bị triệt tiêu liên tiếp, phần còn lại là $\sum(x_i y_{i-1} - x_{i-1} y_i)$ tương đương dạng gốc với chỉ số dịch (modulo $n$).

### Thuật toán

1. Đọc $n$ đỉnh.
2. Khởi tạo `sum = 0`.
3. Với mỗi $i$ từ 1 đến $n$: `sum += (x_i - x_{i-1}) * (y_i + y_{i-1})`, với chỉ số vòng ($x_0 = x_n$, $y_0 = y_n$).
4. Xuất `|sum|`.

### Ví dụ minh họa

Đa giác: $(1,1), (4,2), (3,5), (1,4)$.

| $i$ | $(x_i - x_{i-1})(y_i + y_{i-1})$ | Giá trị |
|-----|-------------------------------------|----------|
| 1 | $(1-1)(1+4)$ | 0 |
| 2 | $(4-1)(2+1)$ | 9 |
| 3 | $(3-4)(5+2)$ | $-7$ |
| 4 | $(1-3)(4+5)$ | $-18$ |

$2A = |0 + 9 - 7 - 18| = |{-16}| = 16$.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Polygon%20Area.cpp)
