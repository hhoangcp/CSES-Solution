# Nested Ranges Count - Lời giải

**ID:** 2169 | **URL:** https://cses.fi/problemset/task/2169

## Hướng tiếp cận

Sắp xếp $n$ đoạn theo điểm cuối $r$ tăng dần; nếu $r$ bằng nhau thì theo điểm đầu $l$ giảm dần. Việc này cố định một biên: duyệt thuận thì mọi đoạn đã xử lý có $r_j \leq r_i$; duyệt ngược thì có $r_j \geq r_i$. Sắp xếp $l$ giảm khi $r$ bằng đảm bảo đoạn hẹp hơn xử lý trước, nên đoạn rộng hơn đếm chính xác.

Nén tọa độ các giá trị $l$ (do $x_i \leq 10^9$) và dùng cây Fenwick (BIT) cho cả hai truy vấn.

### Đếm số đoạn bị chứa (duyệt thuận)

Duyệt các đoạn theo thứ tự đã sắp. Duy trì BIT đếm số giá trị $l$ đã xử lý.

Với đoạn $i$ (chỉ số 0 trong mảng đã sắp):
1. Số đoạn đã xử lý có $l_j \geq l_i$: $i - \text{query}(l_i - 1)$. (Tổng đã xử lý là $i$; $\text{query}(l_i - 1)$ đếm đoạn có $l_j < l_i$.)
2. Đây chính là số đoạn bị $i$ chứa: mọi đoạn đã xử lý thỏa $r_j \leq r_i$, và $l_j \geq l_i$ theo truy vấn.
3. Lưu giá trị đếm đầy đủ.
4. Thêm $l_i$ vào BIT.

### Đếm số đoạn chứa mình (duyệt ngược)

Duyệt ngược thứ tự đã sắp. Duy trì BIT mới.

Với đoạn $i$ (theo thứ tự ngược):
1. Các đoạn đã xử lý có $r_j \geq r_i$ (nằm sau $i$ trong thứ tự sắp).
2. Số đoạn có $l_j \leq l_i$: $\text{query}(l_i)$.
3. Đây chính là số đoạn chứa $i$: mọi đoạn đã xử lý thỏa $r_j \geq r_i$, và $l_j \leq l_i$ theo truy vấn.
4. Lưu giá trị đếm đầy đủ.
5. Thêm $l_i$ vào BIT.

**Không đếm trùng:** Mỗi đoạn chỉ xét quan hệ với các đoạn đã xử lý trước đó trong mỗi lượt duyệt, không tự xét mình.

### Ví dụ minh họa

Xét $n = 4$, các đoạn: $[1, 6], [2, 4], [4, 8], [3, 6]$.

Sắp xếp theo $r$ tăng, $l$ giảm: $[2,4], [3,6], [1,6], [4,8]$.

Nén tọa độ $l$: $\{1,2,3,4\} \to \{1,2,3,4\}$.

**Đếm bị chứa (duyệt thuận):**

| $i$ | Đoạn | $l_i$ | $\text{query}(l_i-1)$ | $i - \text{query}$ | Số đoạn bị chứa |
|-----|------|-------|------------------------|---------------------|-----------------|
| 0 | $[2,4]$ | 2 | 0 | 0 | 0 |
| 1 | $[3,6]$ | 3 | 1 | 0 | 0 |
| 2 | $[1,6]$ | 1 | 0 | 2 | 2 |
| 3 | $[4,8]$ | 4 | 3 | 0 | 0 |

**Đếm chứa mình (duyệt ngược):**

| $i$ | Đoạn | $l_i$ | $\text{query}(l_i)$ | Số đoạn chứa mình |
|-----|------|-------|----------------------|-------------------|
| 3 | $[4,8]$ | 4 | 0 | 0 |
| 2 | $[1,6]$ | 1 | 0 | 0 |
| 1 | $[3,6]$ | 3 | 1 | 1 |
| 0 | $[2,4]$ | 2 | 1 | 1 |

Kết quả (thứ tự gốc): `2 0 0 0` và `0 1 0 1`.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp $O(n \log n)$, mỗi thao tác BIT $O(\log n)$.
- **Bộ nhớ:** $O(n)$ — mảng đoạn và BIT.

## Mã nguồn (C++)

[Mã nguồn](../code/Nested%20Ranges%20Count.cpp)
