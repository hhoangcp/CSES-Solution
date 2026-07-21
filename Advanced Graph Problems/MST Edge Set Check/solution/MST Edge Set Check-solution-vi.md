# MST Edge Set Check - Lời giải

**ID:** 3408 | **URL:** https://cses.fi/problemset/task/3408

## Đề bài

Cho đồ thị vô hướng có trọng số liên thông và $q$ tập cạnh, xác định mỗi tập có thể đồng thời nằm trong một MST nào đó hay không.

## Hướng tiếp cận

### Ý tưởng chính

Tập cạnh $S$ có thể nằm trong MST iff với mỗi trọng số $w$, các cạnh trọng số $w$ trong $S$ không tạo chu trình khi thêm vào DSU chỉ chứa cạnh trọng số $< w$. Nếu $S$ nằm trong MST $T$, mọi cạnh trong $T$ được Kruskal thêm mà không tạo chu trình, nên cạnh trọng số $w$ trong $S$ cũng vậy. Ngược lại, nếu không xung đột, ta mở rộng $S$ thành MST bằng Kruskal: vì các cạnh trong $S$ không xung đột với nhau hay với cạnh nhẹ hơn, tồn tại MST chứa $S$.

### Thuật toán

1. Nhóm cạnh đồ thị theo trọng số: `edgeW[w]`. Với mỗi truy vấn, nhóm cạnh theo trọng số: `layers[w]`.
2. Xử lý trọng số tăng dần. Với mỗi $w$:
   - **Kiểm tra truy vấn:** Lưu checkpoint $t = S.size()$. Với mỗi layer truy vấn tại $w$, thử union các cạnh. Nếu union thất bại, đánh dấu NO. Rollback về checkpoint.
   - **Thêm vĩnh viễn:** Union tất cả cạnh đồ thị trọng số $w$.
3. Xuất YES/NO cho mỗi truy vấn.

### Rollback DSU

Dùng union by size (không nén đường đi vì khó hoàn tác). Mỗi `Union` lưu $(u, v, cnt_v)$ vào stack. `Rollback(t)` hoàn tác tất cả thao tác từ vị trí $t$.

### Ví dụ minh họa

Truy vấn chứa cạnh trọng số 4 nối đỉnh 1 và 2: sau khi thêm cạnh trọng số $< 4$, đỉnh 1 và 2 đã liên thông. Union thất bại → NO.

Truy vấn chứa cạnh trọng số 2 nối đỉnh 3 và 4: khi DSU chỉ chứa cạnh $< 2$, đỉnh 3 và 4 khác thành phần. Union thành công → YES.

## Độ phức tạp

- **Thời gian:** $O(m \log m + (m + \sum k) \log n)$ — DSU không nén đường nên mỗi `Find` tốn $O(\log n)$
- **Bộ nhớ:** $O(n + m + q)$

## Mã nguồn (C++)

[Mã nguồn](../code/MST%20Edge%20Set%20Check.cpp)
