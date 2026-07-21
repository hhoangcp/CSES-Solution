# Area of Rectangles - Lời giải

**ID:** 1741 | **URL:** https://cses.fi/problemset/task/1741

## Phương pháp

### Tóm tắt bài toán

Cho $n$ hình chữ nhật có cạnh song song trục tọa độ, tính tổng diện tích phần hợp (union) của chúng.

### Ý tưởng chính

Sử dụng kỹ thuật quét đường thẳng đứng từ trái sang phải. Với mỗi hình chữ nhật $(x_1, y_1, x_2, y_2)$, tạo hai sự kiện:
- Cạnh trái tại $x_1$ với loại $+1$ (bắt đầu bao phủ đoạn $[y_1, y_2]$)
- Cạnh phải tại $x_2$ với loại $-1$ (kết thúc bao phủ đoạn $[y_1, y_2]$)

Sắp xếp tất cả sự kiện theo tọa độ $x$. Giữa hai sự kiện liên tiếp tại $x_i$ và $x_{i+1}$, chiều dài bị phủ trên trục $y$ không đổi, nên phần diện tích đóng góp là:

$$\Delta A = \text{covered\_len} \times (x_{i+1} - x_i)$$

Để duy trì $\text{covered\_len}$ hiệu quả, dùng cây phân đoạn trên tọa độ $y$ đã nén (tối đa $2n$ giá trị phân biệt). Mỗi nút lưu:
- `cnt`: số hình chữ nhật đang hoạt động bao phủ đoạn này
- `len`: tổng chiều dài bị phủ (theo tọa độ gốc)

**Logic cập nhật:** Khi `cnt > 0`, đoạn bị phủ hoàn toàn nên `len` bằng chiều dài thực tế của đoạn. Khi `cnt == 0` ở nút lá thì `len = 0`; ở nút trong thì `len` bằng tổng `len` của hai con. Điều này đúng vì `cnt > 0` nghĩa là ít nhất một hình chữ nhật bao phủ toàn bộ đoạn, còn `cnt == 0` thì độ phủ hoàn toàn do các con quyết định. Giá trị `len` ở gốc luôn bằng tổng chiều dài bị phủ trên trục $y$.

### Thuật toán

1. Thu thập $2n$ sự kiện: với hình chữ nhật $(x_1, y_1, x_2, y_2)$, thêm $(x_1, +1, y_1, y_2)$ và $(x_2, -1, y_1, y_2)$.
2. Thu thập tất cả tọa độ $y$ phân biệt, sắp xếp và nén thành chỉ số. Xây cây phân đoạn trên $2n-1$ đoạn $y$ cơ bản.
3. Sắp xếp sự kiện theo $x$.
4. Với mỗi sự kiện $(x, \mathit{type}, y_1, y_2)$:
   - Nếu không phải sự kiện đầu tiên, cộng $\text{root.len} \times (x - x_{\text{prev}})$ vào đáp án.
   - Cập nhật cây phân đoạn: cộng $\mathit{type}$ vào đoạn tương ứng $[y_1, y_2)$.
   - Đặt $x_{\text{prev}} = x$.
5. Xuất đáp án.

### Ví dụ minh họa

$n=3$, hình chữ nhật: $(1,3,4,5)$, $(3,1,7,4)$, $(5,3,8,6)$.

Sự kiện sắp xếp theo $x$: $(1,+1,[3,5))$, $(3,+1,[1,4))$, $(4,-1,[3,5))$, $(5,+1,[3,6))$, $(7,-1,[1,4))$, $(8,-1,[3,6))$.

- $x=1$: thêm $[3,5)$. Phủ $= [3,5)$, len $= 2$.
- $x=3$: $\Delta A = 2 \times (3-1) = 4$. Thêm $[1,4)$. Phủ $= [1,5)$, len $= 4$.
- $x=4$: $\Delta A = 4 \times (4-3) = 4$. Xóa $[3,5)$. Phủ $= [1,4)$, len $= 3$.
- $x=5$: $\Delta A = 3 \times (5-4) = 3$. Thêm $[3,6)$. Phủ $= [1,6)$, len $= 5$.
- $x=7$: $\Delta A = 5 \times (7-5) = 10$. Xóa $[1,4)$. Phủ $= [3,6)$, len $= 3$.
- $x=8$: $\Delta A = 3 \times (8-7) = 3$. Xóa $[3,6)$. Phủ $= \emptyset$, len $= 0$.

Tổng: $4 + 4 + 3 + 10 + 3 = 24$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Area%20of%20Rectangles.cpp)
