# Point Location Test - Lời giải

**ID:** 2189 | **URL:** https://cses.fi/problemset/task/2189

## Phương pháp

### Tóm tắt bài toán

Cho đường có hướng từ $p_1$ đến $p_2$ và điểm $p_3$, xác định $p_3$ nằm bên trái, bên phải hay trên đường thẳng khi nhìn từ $p_1$ đến $p_2$.

### Ý tưởng chính

Tính tích có hướng của hai vector $\vec{p_1p_2}$ và $\vec{p_1p_3}$:

$$\text{cross}(p_1, p_2, p_3) = (x_2 - x_1)(y_3 - y_1) - (y_2 - y_1)(x_3 - x_1)$$

Giá trị này bằng diện tích có hướng của tam giác $p_1p_2p_3$ (nhân đôi) và mang thông tin định hướng:

- **cross > 0**: $p_3$ nằm bên **trái** (vòng quay ngược chiều kim đồng hồ từ $p_1$ đến $p_2$ đến $p_3$).
- **cross < 0**: $p_3$ nằm bên **phải** (vòng quay cùng chiều kim đồng hồ).
- **cross = 0**: $p_3$ nằm trên đường thẳng (thẳng hàng — độ dốc từ $p_1$ đến $p_2$ bằng từ $p_1$ đến $p_3$, tức ba điểm có diện tích bằng 0).

Tích có hướng bất biến dưới phép tịnh tiến và quay, đổi dấu dưới phép đối xứng, nên kết quả nhất quán bất kể vị trí tương đối các điểm.

### Thuật toán

1. Với mỗi test, đọc $p_1, p_2, p_3$.
2. Tính $\text{cross}(p_1, p_2, p_3)$.
3. Nếu cross > 0: xuất LEFT. Nếu cross < 0: xuất RIGHT. Nếu cross = 0: xuất TOUCH.

### Ví dụ minh họa

3 test từ đề bài, đều dùng $p_1=(1,1), p_2=(5,3)$:

| Test | $p_3$ | cross | Kết quả |
|------|-------|-------|---------|
| 1 | $(2,3)$ | $4 \cdot 2 - 2 \cdot 1 = 6$ | LEFT |
| 2 | $(4,1)$ | $4 \cdot 0 - 2 \cdot 3 = -6$ | RIGHT |
| 3 | $(3,2)$ | $4 \cdot 1 - 2 \cdot 2 = 0$ | TOUCH |

## Độ phức tạp

- **Thời gian:** $O(1)$ mỗi test
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Point%20Location%20Test.cpp)
