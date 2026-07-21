# Sửa Chữa Đường - Lời giải

**ID:** 1675 | **URL:** https://cses.fi/problemset/task/1675

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng có trọng số $n$ đỉnh và $m$ cạnh, tìm tổng trọng số nhỏ nhất của tập cạnh nối tất cả đỉnh, hoặc kết luận "IMPOSSIBLE" nếu đồ thị không liên thông.

### Ý tưởng chính

Đây là bài toán **cây khung nhỏ nhất (MST)**. Thuật toán Kruskal giải bằng tham lam: sắp xếp cạnh theo trọng số tăng, duyệt và chọn mỗi cạnh nếu nó nối hai thành phần khác nhau (không tạo chu trình). Dùng DSU với nén đường đi và hợp nhất theo hạng để kiểm tra và gộp thành phần.

Kruskal đúng vì nếu nó chọn cạnh $e$ mà tồn tại cạnh thay thế $e'$ nhẹ hơn có thể nối cùng hai thành phần, thì $e'$ đã được xét trước (sắp xếp trước) và đã được chọn — mâu thuẫn. Hơn hình thức, với mọi MST $T^*$, ta có thể trao đổi từng cạnh của $T \setminus T^*$ với một cạnh của $T^* \setminus T$ có trọng số lớn hơn hoặc bằng mà không phá tính cây khung, chứng minh $w(T) \leq w(T^*)$.

Nếu sau khi duyệt hết cạnh mà chọn được ít hơn $n - 1$ cạnh, đồ thị không liên thông.

### Thuật toán

1. Sắp xếp tất cả cạnh theo trọng số tăng dần.
2. Khởi tạo DSU: mỗi đỉnh là một thành phần riêng.
3. Với mỗi cạnh $(u, v, c)$ theo thứ tự đã sắp:
   - Nếu $\text{Find}(u) \neq \text{Find}(v)$: chọn cạnh, $\text{Union}(u, v)$, cộng $c$ vào đáp án.
   - Ngược lại: bỏ qua (sẽ tạo chu trình).
4. Nếu chọn được ít hơn $n - 1$ cạnh: xuất "IMPOSSIBLE". Ngược lại: xuất tổng chi phí.

### Ví dụ minh họa

Input:
```
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
```

Sắp xếp: $(2,4,2), (1,2,3), (5,4,4), (2,3,5), (5,1,7), (3,4,8)$.

| Cạnh   | Find(u)≠Find(v)? | Chi phí |
|--------|-------------------|---------|
| (2,4,2)| Có                | 2       |
| (1,2,3)| Có                | 5       |
| (5,4,4)| Có                | 9       |
| (2,3,5)| Có                | 14      |

Đã chọn 4 cạnh = $n - 1$. Dừng.

Kết quả:
```
14
```

## Độ phức tạp

- **Thời gian:** $O(m \log m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Road%20Reparation.cpp)
