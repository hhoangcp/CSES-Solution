# Xây Đường - Lời giải

**ID:** 1666 | **URL:** https://cses.fi/problemset/task/1666

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị vô hướng $n$ đỉnh, $m$ cạnh. Tìm số lượng cạnh tối thiểu cần thêm sao cho đồ thị liên thông, và liệt kê các cạnh cần thêm.

### Ý tưởng chính

Đồ thị gồm $k$ thành phần liên thông. Để hợp nhất $k$ thành phần thành một, ta cần đúng $k - 1$ cạnh mới:

- **Cận dưới:** Mỗi cạnh mới tối đa giảm số thành phần đi 1 (nếu nối hai thành phần khác nhau). Từ $k$ thành phần, cần ít nhất $k - 1$ cạnh để về 1.
- **Cận trên (cách xây dựng):** Chọn đỉnh đại diện $r_i$ từ mỗi thành phần $C_i$. Thêm cạnh $(r_1, r_2), (r_2, r_3), \ldots, (r_{k-1}, r_k)$ sẽ hợp nhất tất cả $k$ thành phần: sau cạnh $(r_i, r_{i+1})$, các thành phần $C_1, \ldots, C_{i+1}$ đã liên thông (theo quy nạp), nên sau $k-1$ cạnh toàn bộ đồ thị liên thông.

Cách xây dựng này không duy nhất — bất kỳ tập $k - 1$ cạnh nào nối tất cả $k$ thành phần (tức tạo cây bao trùm trên các thành phần) đều hợp lệ.

### Thuật toán

1. Chạy DFS/BFS từ mỗi đỉnh chưa thăm để xác định tất cả thành phần liên thông. Với mỗi thành phần, ghi lại một đỉnh đại diện (bất kỳ đỉnh nào trong thành phần).
2. Gọi $r_1, r_2, \ldots, r_k$ là các đại diện. Xuất $k - 1$ cạnh $(r_1, r_2), (r_2, r_3), \ldots, (r_{k-1}, r_k)$.

### Ví dụ minh họa

Đầu vào:
```
4 2
1 2
3 4
```

Đồ thị có hai thành phần liên thông:
- Thành phần {1, 2}: đại diện $r_1 = 2$
- Thành phần {3, 4}: đại diện $r_2 = 3$

$k = 2$ thành phần, cần $k - 1 = 1$ cạnh: thêm cạnh $(2, 3)$.

Kết quả:
```
1
2 3
```

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — mỗi đỉnh và cạnh được duyệt đúng một lần.
- **Không gian:** $O(n + m)$ — danh sách kề và mảng `visited`.

## Mã nguồn (C++)

[Mã nguồn](../code/Building%20Roads.cpp)
