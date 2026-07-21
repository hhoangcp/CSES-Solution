# MST Edge Cost - Lời giải

**ID:** 3409 | **URL:** https://cses.fi/problemset/task/3409

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng có trọng số liên thông, với mỗi cạnh $e$, tính chi phí MST khi $e$ **bắt buộc** nằm trong cây bao trùm.

### Ý tưởng chính

Thêm cạnh $e = (u, v, w)$ vào MST tạo đúng một chu trình: đường đi $u$-$v$ trong MST cộng cạnh $e$. Để có cây bao trùm chứa $e$, phải loại một cạnh trên chu trình. Để tối ưu, loại cạnh nặng nhất trên đường đi $u$-$v$, tiết kiệm `max_w`, thêm $e$ tốn $w$. Chi phí = `mst_cost - max_w + w`. Nếu $e$ đã thuộc MST thì $e$ nằm trên đường đi nên `max_w >= w`, vì MST tối ưu nên kết quả phải bằng đúng `mst_cost`.

### Thuật toán

1. Xây MST bằng Kruskal. Tính `mst_cost`.
2. Xây cây từ cạnh MST. Tính binary lifting với truy vấn max cạnh trên đường đi.
3. Với mỗi cạnh $(u, v, w)$: đáp án = `mst_cost - mx_query(u, v) + w`.

### Ví dụ minh họa

MST: (3,4,1), (1,3,2), (2,4,2), (4,5,3). Chi phí = 8.

Cạnh (1,2,4): đường đi 1-3-4-2, max = 2. Đáp án = 8 - 2 + 4 = 10.
Cạnh (3,5,4): đường đi 3-4-5, max = 3. Đáp án = 8 - 3 + 4 = 9.
Cạnh MST: đáp án = 8.

## Độ phức tạp

- **Thời gian:** $O(m \log m + n \log n)$
- **Không gian:** $O(n \log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/MST%20Edge%20Cost.cpp)
