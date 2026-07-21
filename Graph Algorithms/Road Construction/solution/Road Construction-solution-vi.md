# Xây Dựng Đường - Lời giải

**ID:** 1676 | **URL:** https://cses.fi/problemset/task/1676

## Phương pháp

### Tóm tắt bài toán

Có $n$ thành phố, ban đầu không có đường. Các con đường được xây lần lượt. Sau mỗi lần xây, cho biết số thành phần liên thông và kích thước thành phần lớn nhất.

### Ý tưởng chính

Sử dụng **Disjoint Set Union (DSU)** với hai tối ưu: nén đường đi trong `Find` và hợp nhất theo kích thước trong `Union`. Duy trì biến toàn cục `components` (khởi tạo $n$, giảm 1 mỗi lần gộp thành công) và `cur_max` (cập nhật $\max(\text{cur\_max}, \text{sz}[ru])$ sau mỗi lần gộp).

Bất biến đúng vì `components` chỉ giảm khi thực sự gộp hai tập khác nhau, và `cur_max` chỉ tăng khi gộp tạo tập lớn hơn mọi tập hiện có. Hợp nhất theo kích thước gắn cây nhỏ hơn dưới cây lớn hơn, giữ độ sâu cây $O(\log n)$; kết hợp nén đường đi, mỗi thao tác chạy trong $O(\alpha(n))$ — gần như hằng số.

### Thuật toán

1. Khởi tạo: $\text{par}[u] = u$, $\text{sz}[u] = 1$ với mọi $u$. Đặt `components = n`, `cur_max = 1`.
2. Với mỗi con đường $(u, v)$:
   - Tìm $ru = \text{Find}(u)$, $rv = \text{Find}(v)$.
   - Nếu $ru = rv$: không thay đổi.
   - Nếu $ru \neq rv$: gắn tập nhỏ dưới tập lớn, cập nhật $\text{sz}$, `components--`, `cur_max = max(cur_max, sz[ru])`.
   - Xuất `components` và `cur_max`.

### Ví dụ minh họa

Input:
```
5 3
1 2
1 3
4 5
```

| Đường  | Gộp?  | components | cur_max |
|--------|-------|------------|---------|
| Ban đầu| —     | 5          | 1       |
| (1, 2) | Có    | 4          | 2       |
| (1, 3) | Có    | 3          | 3       |
| (4, 5) | Có    | 2          | 3       |

Kết quả:
```
4 2
3 3
2 3
```

## Độ phức tạp

- **Thời gian:** $O(m \cdot \alpha(n))$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Road%20Construction.cpp)
