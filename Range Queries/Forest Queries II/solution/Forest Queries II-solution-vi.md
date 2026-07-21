# Forest Queries II - Lời giải

**ID:** 1739 | **URL:** https://cses.fi/problemset/task/1739

## Hướng tiếp cận

### Tóm tắt đề bài

Cho lưới $n \times n$, mỗi ô hoặc trống (`.`) hoặc có cây (`*`). Xử lý $q$ truy vấn:
1. Chuyển đổi trạng thái (trống/cây) của ô $(y, x)$.
2. Có bao nhiêu cây bên trong hình chữ nhật từ $(y_1, x_1)$ đến $(y_2, x_2)$?

### Ý tưởng cốt lõi

Lưới giờ có cập nhật điểm, nên tổng tiền tố hai chiều tĩnh không còn phù hợp (mỗi cập nhật tốn $O(n^2)$ để tính lại). Ta cần cấu trúc dữ liệu động hỗ trợ cả cập nhật điểm lẫn truy vấn tổng hình chữ nhật. **Cây Fenwick hai chiều** (2D BIT) đạt cả hai thao tác trong $O(\log^2 n)$.

Cây Fenwick 2D mở rộng từ phiên bản 1D: mỗi nút `bit[i][j]` lưu tổng trên hình chữ nhật $[i - \text{lowbit}(i) + 1, i] \times [j - \text{lowbit}(j) + 1, j]$, với $\text{lowbit}(x) = x\ \wedge\ (-x)$. Cập nhật điểm lan truyền tiến theo cả hai trục (mỗi trục đóng góp $O(\log n)$ bước), truy vấn tổng tiền tố phân rã lùi theo cả hai trục. Truy vấn phân rã hình chữ nhật $[1, x] \times [1, y]$ thành các hình chữ nhật con rời nhau qua cơ chế lowbit, và cập nhật phân phối giá trị đến tất cả các hình chữ nhật con chứa ô bị sửa đổi. Truy vấn hình chữ nhật bất kỳ dùng bao hàm-loại trừ với 4 tổng tiền tố.

### Thuật toán

1. **Xây dựng:** Đọc lưới, gọi `update(i, j, 1)` cho mỗi ô chứa cây.
2. **Chuyển đổi trạng thái** (loại 1): Nếu ô đang có cây, gọi `update(y, x, -1)` và đặt trạng thái về 0. Ngược lại gọi `update(y, x, +1)` và đặt trạng thái về 1.
3. **Truy vấn hình chữ nhật** (loại 2): Tính
   $$\text{đáp án} = \text{query}(y_2, x_2) - \text{query}(y_2, x_1{-}1) - \text{query}(y_1{-}1, x_2) + \text{query}(y_1{-}1, x_1{-}1)$$

### Ví dụ

Đầu vào:
```
4 3
.*..
*.**
**..
****
2 2 2 3 4
1 3 3
2 2 2 3 4
```

Lưới:
```
Hàng 1: . * . .
Hàng 2: * . * *
Hàng 3: * * . .
Hàng 4: * * * *
```

- Truy vấn $(2,2)$ đến $(3,4)$: $\text{query}(3,4) - \text{query}(3,1) - \text{query}(1,4) + \text{query}(1,1) = 6 - 2 - 1 + 0 = 3$.
- Chuyển đổi $(3,3)$: ô đang là `.` (trống), trở thành `*` (cây). Gọi `update(3, 3, +1)`.
- Truy vấn $(2,2)$ đến $(3,4)$: ô $(3,3)$ giờ chứa cây và nằm trong vùng truy vấn, nên số cây tăng 1. Kết quả = 4.

Kết quả:
```
3
4
```

## Độ phức tạp

- **Thời gian:** $O(n^2 \log^2 n + q \log^2 n)$
- **Bộ nhớ:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Forest%20Queries%20II.cpp)
