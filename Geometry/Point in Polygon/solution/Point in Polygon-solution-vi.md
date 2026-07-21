# Point in Polygon - Lời giải

**ID:** 2192 | **URL:** https://cses.fi/problemset/task/2192

## Phương pháp

### Tóm tắt bài toán

Cho đa giác đơn và danh sách các điểm, xác định mỗi điểm nằm trong, ngoài hay trên biên của đa giác.

### Ý tưởng chính

Sử dụng thuật toán bắn tia. Bắn tia ngang từ điểm truy vấn $A$ theo hướng $x$ dương và đếm số cạnh đa giác mà tia cắt qua. Theo định lý đường cong Jordan, đường cong đơn đóng chia mặt phẳng thành miền trong và ngoài — mỗi lần tia cắt biên, ta chuyển đổi giữa hai miền. Số lần cắt lẻ → INSIDE; chẵn → OUTSIDE.

Với mỗi cạnh $(P_i, P_{i+1})$, trước tiên kiểm tra $A$ có nằm trên cạnh không bằng `onSeg`: tích có hướng của $A$ với hai đầu mút bằng 0 (thẳng hàng) và tích vô hướng $\le 0$ ($A$ nằm giữa hai đầu mút). Nếu có, trả về BOUNDARY ngay.

Để kiểm tra cắt tia, chuẩn hóa sao cho đầu mút thấp là $x$ và cao là $y$ (đổi nếu $x.y > y.y$). Tia cắt cạnh khi: (1) $x.y \le A.y < y.y$ — nửa mở tại $y.y$ tránh đếm hai lần tại đỉnh chung của hai cạnh liên tiếp (nếu cả hai cùng hướng lên/xuống qua $y = A.y$, chỉ đếm một lần); (2) $\text{cross}(A, x, y) > 0$ — $A$ nằm bên trái cạnh có hướng, nghĩa là tia sang phải phải cắt cạnh đó. Mỗi lần cắt, đảo trạng thái bằng $ans \gets ans \oplus 1$.

### Thuật toán

1. Đọc các đỉnh đa giác.
2. Với mỗi điểm truy vấn $A$:
   - Khởi tạo `ans = 0`.
   - Với mỗi cạnh $(P_i, P_{i+1})$:
     - Nếu `onSeg(A, Line(P_i, P_{i+1}))`: xuất BOUNDARY và chuyển sang điểm tiếp.
     - Chuẩn hóa đầu mút thấp $x$, cao $y$.
     - Nếu $x.y \le A.y < y.y$ và $\text{cross}(A, x, y) > 0$: $ans \gets ans \oplus 1$.
   - Xuất INSIDE nếu `ans` lẻ, OUTSIDE nếu chẵn.

### Ví dụ minh họa

Đa giác: $(1,1), (4,2), (3,5), (1,4)$. Điểm truy vấn: $(2,3), (3,1), (1,3)$.

**Điểm $(2,3)$:**
- Cạnh $(1,1)\text{–}(4,2)$: không trên biên. $1 \le 3 < 2$? Không.
- Cạnh $(4,2)\text{–}(3,5)$: không trên biên. $2 \le 3 < 5$? Có. $\text{cross}((2,3),(4,2),(3,5)) = 5 > 0$. Cắt. `ans = 1`.
- Cạnh $(3,5)\text{–}(1,4)$: $4 \le 3$? Không.
- Cạnh $(1,4)\text{–}(1,1)$: không trên biên. $1 \le 3 < 4$? Có. $\text{cross}((2,3),(1,1),(1,4)) = -3 < 0$. Không cắt.

Lẻ → INSIDE.

**Điểm $(3,1)$:**
- Cạnh $(1,1)\text{–}(4,2)$: $1 \le 1 < 2$? Có. $\text{cross}((3,1),(1,1),(4,2)) = -2 < 0$. Không cắt.
- Cạnh $(4,2)\text{–}(3,5)$: $2 \le 1$? Không.
- Cạnh $(3,5)\text{–}(1,4)$: $4 \le 1$? Không.
- Cạnh $(1,4)\text{–}(1,1)$: $1 \le 1 < 4$? Có. $\text{cross}((3,1),(1,1),(1,4)) = -6 < 0$. Không cắt.

Chẵn → OUTSIDE.

**Điểm $(1,3)$:**
- Cạnh $(1,4)\text{–}(1,1)$: $\text{cross}((1,3),(1,4),(1,1)) = 0$, $\text{dot}((1,3),(1,4),(1,1)) = -2 \le 0$. Nằm trên đoạn.

→ BOUNDARY.

## Độ phức tạp

- **Thời gian:** $O(n)$ mỗi điểm truy vấn
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Point%20in%20Polygon.cpp)
