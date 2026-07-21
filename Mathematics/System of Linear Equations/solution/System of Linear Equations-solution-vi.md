# System of Linear Equations - Lời giải

**ID:** 3154 | **URL:** https://cses.fi/problemset/task/3154

## Phương pháp

### Tóm tắt bài toán

Cho $n$ phương trình tuyến tính $m$ ẩn với hệ số modulo $p = 10^9+7$: $a_{i,1}x_1 + \cdots + a_{i,m}x_m = b_i \pmod{p}$. Tìm một nghiệm bất kỳ, hoặc xuất $-1$ nếu hệ vô nghiệm.

### Ý tưởng chính

Áp dụng **khử Gauss** trên trường hữu hạn $\mathbb{F}_p$. Vì $p = 10^9+7$ là số nguyên tố, $\mathbb{F}_p$ là trường, mọi phần tử khác 0 đều có nghịch đảo modulo (tính bằng Định lý Fermat nhỏ: $a^{-1} \equiv a^{p-2} \pmod{p}$). Các phép biến đổi hàng sơ cấp:

1. **Tìm trục** tại cột $j$: xác định hàng có hệ số khác 0. Nếu không có, $x_j$ là ẩn tự do.
2. **Chuẩn hóa:** nhân hàng trục với $a_{i,j}^{-1}$ để đưa hệ số trục về 1.
3. **Khử:** trừ $a_{k,j}$ lần hàng trục khỏi mỗi hàng khác $k$ để triệt tiêu cột $j$.

Các phép biến đổi hàng sơ cấp bảo toàn không gian nghiệm (nhân hàng với số khác 0 là khả nghịch; cộng bội hàng này vào hàng khác không thay đổi tập nghiệm). Sau khử, ma trận dạng bậc thang thu gọn cho nghiệm trực tiếp.

**Kiểm tra tương thích:** Nếu xuất hiện hàng có tất cả hệ số bằng 0 nhưng vế phải khác 0 ($0 = b_i$), hệ vô nghiệm → xuất $-1$.

**Ẩn tự do:** Nếu $\text{rank}(A) < m$, hệ có vô số nghiệm. Đặt các ẩn tự do bằng 0 để thu được một nghiệm cụ thể.

### Thuật toán

1. Lập ma trận mở rộng $[A \mid b]$.
2. Với mỗi cột $j = 1, \ldots, m$: tìm trục, đổi hàng, chuẩn hóa, khử.
3. Kiểm tra hàng mâu thuẫn. Nếu có, xuất $-1$.
4. Với mỗi ẩn: nếu cột có trục, $x_j = b_i$ của hàng trục; ngược lại $x_j = 0$.

### Ví dụ minh họa

$n = m = 3$, hệ: $2x_1 + x_3 = 7$, $x_1 + 2x_2 = 0$, $x_1 + 3x_2 + x_3 = 2$.

Sau khử: $x_1 = 2$, $x_2 = 10^9+6 \equiv -1 \pmod{p}$, $x_3 = 3$.

Kiểm tra: $2(2) + 3 = 7$ $\checkmark$, $2 + 2(10^9+6) \equiv 0$ $\checkmark$, $2 + 3(10^9+6) + 3 \equiv 2$ $\checkmark$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot m^2)$
- **Không gian:** $O(n \cdot m)$

## Mã nguồn (C++)

[Mã nguồn](../code/System%20of%20Linear%20Equations.cpp)
