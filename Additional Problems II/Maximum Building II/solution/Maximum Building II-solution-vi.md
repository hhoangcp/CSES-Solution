# Maximum Building II - Lời giải

**ID:** 1148 | **URL:** https://cses.fi/problemset/task/1148

## Đề bài

Cho lưới $n \times m$ có cây (`*`) và ô trống (`.`), với mỗi kích thước nhà $a \times b$, đếm số vị trí đặt nhà hình chữ nhật không phủ cây.

## Hướng tiếp cận

### Histogram + Stack đơn điệu: Tìm hình chữ nhật tối đa

Với mỗi hàng $i$, tính $h[j]$ = số ô trống liên tiếp tính từ hàng $i$ ngược lên tại cột $j$ (nếu ô có cây thì $h[j] = 0$). Dùng stack đơn điệu tìm biên trái `Left[j]` và biên phải `Right[j]` sao cho $h[k] \ge h[j]$ với mọi $k \in [\text{Left}[j], \text{Right}[j]]$. Đây là hình chữ nhật lớn nhất có chiều cao **đúng** $h[j]$ đi qua cột $j$.

### Mảng hiệu 2D: Cập nhật đóng góp $O(1)$ cho mỗi hình chữ nhật

Hình chữ nhật tối đa cao $H$ rộng $W$ đóng góp $C(H,W,a,b) = (W - b + 1)(H - a + 1)$ vị trí cho nhà $a \times b$ (nếu $a \le H, b \le W$). Phân tích:

$$C = (H - a + 1)(W - b + 1) = (H - a + 1)(W + 1) - (H - a + 1) \cdot b$$

Dùng 3 mảng hiệu để xử lý từng phần, mỗi hình chữ nhật cập nhật $O(1)$:

- **`ans[a][b]`**: mảng hiệu 2D đếm phần cơ bản. Cập nhật 4 góc dải $[1..H][1..W]$.
- **`add[a][b]`**: tích lũy hằng số $(W+1)$ cho $a \le H, b \le W$.
- **`sub[a][b]`**: tích lũy hệ số tuyến tính $b$ cho $a \le H, b \le W$.

Mỗi cách đặt nhà $a \times b$ cụ thể tương ứng một hình chữ nhật trống trên lưới, hình chữ nhật này chắc chắn được bao phủ bởi ít nhất một hình chữ nhật tối đa khi duyệt histogram. Mảng hiệu đảm bảo mỗi vị trí đặt được đếm chính xác.

## Thuật toán

1. Duyệt từng hàng $i = 1 \ldots n$, cập nhật histogram $h[j]$.
2. Với mỗi hàng, dùng stack đơn điệu tìm `Left[j]`, `Right[j]`.
3. Với mỗi $j$, gọi $H = h[j]$, $W = \text{Right}[j] - \text{Left}[j] + 1$. Cập nhật `ans`, `add`, `sub` bằng $O(1)$.
4. Sau khi duyệt hết lưới, tính tổng tiền tố 2D cho cả 3 mảng.
5. Kết quả tại $(a, b)$: `ans[a][b] + add[a][b] - sub[a][b]`.

## Ví dụ minh họa

Lưới $4 \times 7$ trong đề: có 5 vị trí đặt nhà $2 \times 4$.

## Độ phức tạp

- **Thời gian:** $O(nm)$ — mỗi hàng xử lý $O(m)$, tổng tiền tố cuối $O(nm)$
- **Bộ nhớ:** $O(nm)$

## Mã nguồn (C++)

[Mã nguồn](../code/Maximum%20Building%20II.cpp)
