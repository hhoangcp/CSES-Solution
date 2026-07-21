# Subarray Sum Constraints - Lời giải

**ID:** 3294 | **URL:** https://cses.fi/problemset/task/3294

## Đề bài

Xây mảng $x_1, x_2, \ldots, x_n$ thỏa $m$ ràng buộc dạng: $x_l + x_{l+1} + \ldots + x_r = s$, hoặc xác định không tồn tại.

## Hướng tiếp cận

### Biến đổi tổng tiền tố

Định nghĩa $p_0 = 0, p_i = x_1 + \ldots + x_i$. Ràng buộc $x_l + \ldots + x_r = s$ trở thành:

$$p_r - p_{l-1} = s$$

Bài toán quy về: gán giá trị cho $p_0, p_1, \ldots, p_n$ thỏa mọi ràng buộc hiệu, hoặc phát hiện mâu thuẫn.

### Weighted DSU

Coi mỗi $p_i$ là nút đồ thị. Ràng buộc $p_r - p_{l-1} = s$ tạo cạnh giữa nút $l-1$ và $r$ trọng số $s$. Dùng DSU với `diff[x]` lưu $p_x - p_{\text{root}(x)}$:

- **`find(x)`**: nén đường đi + tích lũy `diff` sao cho `diff[x] = p_x - p_\text{root}`.
- **`unite(u, v, w)`** (ép $p_v - p_u = w$):
  - Cùng gốc: kiểm tra nhất quán — $diff[v] - diff[u]$ phải bằng $w$, ngược lại mâu thuẫn.
  - Khác gốc: gắn gốc $rv$ vào gốc $ru$, đặt `diff[rv] = diff[u] - diff[v] + w` để bảo toàn $p_v - p_u = w$.

Sau `unite`, gọi `find(x)` cho $p_x - p_\text{root}$ đúng nhờ tích lũy diff dốc đường đi.

### Khôi phục mảng

1. Với mỗi $i \in [0, n]$, gọi `find(i)` và đọc `diff[i]` (= $p_i - p_{\text{root}}$).
2. Tính $x_i = p_i - p_{i-1}$.

Mỗi gốc DSU có `diff = 0` (nên $p_\text{root} = 0$ tương đối), các nút tự do mặc định $p = 0$.

### Ví dụ

$n = 5, m = 3$: $(1,3,3), (3,5,3), (4,4,-1)$.

Ràng buộc: $p_3 - p_0 = 3$, $p_5 - p_2 = 3$, $p_4 - p_3 = -1$.

| Ràng buộc | Lệnh `unite` | Thay đổi DSU |
|-----------|-------------|--------------|
| $p_3 - p_0 = 3$ | `unite(0, 3, 3)` | nút 3 → gốc 0, `diff[3] = 3` |
| $p_5 - p_2 = 3$ | `unite(2, 5, 3)` | nút 5 → gốc 2, `diff[5] = 3` |
| $p_4 - p_3 = -1$ | `unite(3, 4, -1)` | nút 4 → gốc 0, `diff[4] = 2` |

Khôi phục: $p = [0, 0, 0, 3, 2, 3]$, suy ra $x = [0, 0, 3, -1, 1]$.

Kiểm tra: $0+0+3=3$ ✓, $3+(-1)+1=3$ ✓, $-1=-1$ ✓.

## Độ phức tạp

- **Thời gian:** $O((n + m) \cdot \alpha(n))$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Subarray%20Sum%20Constraints.cpp)
