# Minimum Euclidean Distance - Lời giải

**ID:** 2194 | **URL:** https://cses.fi/problemset/task/2194

## Phương pháp

### Tóm tắt bài toán

Cho $n$ điểm trên mặt phẳng, tìm bình phương khoảng cách Euclid nhỏ nhất giữa hai điểm phân biệt.

### Ý tưởng chính

Sử dụng chia để trị. Sắp xếp tất cả điểm theo tọa độ $x$, sau đó đệ quy chia tại trung vị. Mỗi lời gọi trả về khoảng cách bình phương nhỏ nhất $d$ trong khoảng của nó, và danh sách điểm sắp theo $y$.

**Chia và trị:** Chia thành nửa trái và nửa phải. Đệ quy tính $d_L$ và $d_R$, rồi $d = \min(d_L, d_R)$. Cặp gần nhất hoặc cùng nằm trong một nửa (đệ quy xử lý), hoặc nằm ở hai nửa khác nhau (bước ghép xử lý).

**Bước ghép:** Mọi cặp vượt hai nửa có khoảng cách bình phương $< d$ phải nằm trong dải $|x - x_{\text{mid}}|^2 < d$. Sau khi đệ quy, các điểm đã sắp theo $y$ (qua trộn merge). Với mỗi điểm trong dải, so sánh với các điểm tiếp theo theo $y$, dừng khi hiệu $y$ bình phương vượt $d$.

**Số điểm cần kiểm tra mỗi điểm bị chặn bởi hằng số:** Chia hình vuông $\sqrt{d} \times \sqrt{d}$ thành 6 ô con kích thước $\frac{\sqrt{d}}{2} \times \frac{2\sqrt{d}}{3}$. Đường chéo mỗi ô là $\sqrt{d/4 + 4d/9} < \sqrt{d}$, nên mỗi ô chứa tối đa 1 điểm (hai điểm cùng ô có khoảng cách $< d$, mâu thuẫn với việc mỗi nửa đã có khoảng cách nhỏ nhất $\ge d$). Vậy tối đa 6 điểm nằm trong hình vuông $\sqrt{d} \times \sqrt{d}$, mỗi điểm trong dải chỉ cần so sánh với hằng số điểm gần theo $y$. Không bỏ sót cặp nào: cặp tối ưu vượt hai nửa phải nằm trong dải, và quét $y$ kiểm tra mọi điểm trong khoảng $\sqrt{d}$.

### Thuật toán

1. Sắp xếp tất cả điểm theo tọa độ $x$.
2. Đệ quy solve(l, r):
   - Cơ sở: nếu $r - l \le 3$, tính trực tiếp tất cả khoảng cách cặp và sắp theo $y$.
   - Chia tại mid. Đệ quy hai nửa, nhận $d_L$, $d_R$ và mỗi nửa sắp theo $y$.
   - Trộn hai nửa đã sắp theo $y$.
   - $d = \min(d_L, d_R)$. Thu thập các điểm có $|x - x_{\text{mid}}|^2 < d$ từ danh sách đã trộn.
   - Với mỗi điểm trong dải, so sánh với các điểm tiếp theo theo $y$ cho đến khi hiệu $y$ bình phương $\ge d$, cập nhật $d$.
   - Trả về $d$ và danh sách đã trộn theo $y$.

### Ví dụ minh họa

4 điểm: $(2,1), (4,4), (1,2), (6,3)$.

Sắp xếp theo $x$: $(1,2), (2,1), (4,4), (6,3)$.

Chia: trái $[(1,2), (2,1)]$, phải $[(4,4), (6,3)]$.

- Trái: $d_L = (1-2)^2 + (2-1)^2 = 2$.
- Phải: $d_R = (4-6)^2 + (4-3)^2 = 5$.
- $d = \min(2, 5) = 2$. Dải: điểm có $|x - 3|^2 < 2$, tức $(2,1)$ và $(4,4)$. Khoảng cách: $(2-4)^2 + (1-4)^2 = 13 \ge 2$.

Kết quả: 2.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Minimum%20Euclidean%20Distance.cpp)
