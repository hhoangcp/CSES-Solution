# Nested Ranges Check - Lời giải

**ID:** 2168 | **URL:** https://cses.fi/problemset/task/2168

## Hướng tiếp cận

Sắp xếp $n$ đoạn theo điểm cuối $r$ tăng dần; nếu $r$ bằng nhau thì theo điểm đầu $l$ giảm dần. Sau khi sắp, khi xét đoạn $i$, mọi đoạn đã xử lý đều có $r_j \leq r_i$. Với cùng $r$, đoạn hẹp hơn (l lớn hơn) xếp trước, nên đoạn rộng hơn xử lý sau và có thể phát hiện quan hệ chứa.

Nén tọa độ các giá trị $l$ (do $x_i \leq 10^9$) và dùng cây Fenwick (BIT) cho cả hai truy vấn.

### Kiểm tra đoạn có chứa đoạn khác (duyệt thuận)

Duyệt các đoạn theo thứ tự đã sắp. Duy trì BIT đếm số giá trị $l$ đã xử lý.

Với đoạn $i$ (chỉ số 0 trong mảng đã sắp):
1. Số đoạn đã xử lý có $l_j \geq l_i$: $i - \text{query}(l_i - 1)$. (Tổng đã xử lý là $i$; $\text{query}(l_i - 1)$ đếm các đoạn có $l_j < l_i$.)
2. Nếu dương, tồn tại đoạn $j$ với $l_j \geq l_i$ và $r_j \leq r_i$ (do sắp xếp), nên đoạn $i$ chứa đoạn $j$.
3. Thêm $l_i$ vào BIT.

**Tính đúng:** Đoạn $j$ bị $i$ chứa khi $l_i \leq l_j$ và $r_i \geq r_j$. Mọi đoạn đã xử lý thỏa $r_j \leq r_i$. Giá trị $i - \text{query}(l_i - 1)$ chính xác đếm các đoạn có $l_j \geq l_i$.

### Kiểm tra đoạn có bị đoạn khác chứa (duyệt ngược)

Duyệt ngược thứ tự đã sắp. Duy trì BIT mới.

Với đoạn $i$ (theo thứ tự ngược):
1. Các đoạn đã xử lý có $r_j \geq r_i$ (nằm sau $i$ trong thứ tự sắp).
2. Số đoạn có $l_j \leq l_i$: $\text{query}(l_i)$.
3. Nếu dương, tồn tại đoạn $j$ với $l_j \leq l_i$ và $r_j \geq r_i$, nên đoạn $j$ chứa đoạn $i$.
4. Thêm $l_i$ vào BIT.

**Tính đúng:** Đoạn $j$ chứa $i$ khi $l_j \leq l_i$ và $r_j \geq r_i$. Duyệt ngược, mọi đoạn đã xử lý thỏa $r_j \geq r_i$. Truy vấn $\text{query}(l_i)$ đếm các đoạn có $l_j \leq l_i$.

### Ví dụ minh họa

Xét $n = 4$, các đoạn: $[1, 6], [2, 4], [4, 8], [3, 6]$.

Sắp xếp theo $r$ tăng, $l$ giảm: $[2,4], [3,6], [1,6], [4,8]$.

Nén tọa độ $l$: $\{1,2,3,4\} \to \{1,2,3,4\}$.

**Chứa đoạn khác (duyệt thuận):**

| $i$ | Đoạn | $l_i$ | $\text{query}(l_i-1)$ | $i - \text{query}$ | Chứa? |
|-----|------|-------|------------------------|---------------------|-------|
| 0 | $[2,4]$ | 2 | 0 | 0 | 0 |
| 1 | $[3,6]$ | 3 | 1 | 0 | 0 |
| 2 | $[1,6]$ | 1 | 0 | 2 | 1 |
| 3 | $[4,8]$ | 4 | 3 | 0 | 0 |

**Bị đoạn khác chứa (duyệt ngược):**

| $i$ | Đoạn | $l_i$ | $\text{query}(l_i)$ | Bị chứa? |
|-----|------|-------|----------------------|----------|
| 3 | $[4,8]$ | 4 | 0 | 0 |
| 2 | $[1,6]$ | 1 | 0 | 0 |
| 1 | $[3,6]$ | 3 | 1 | 1 |
| 0 | $[2,4]$ | 2 | 1 | 1 |

Kết quả (thứ tự gốc): `1 0 0 0` và `0 1 0 1`.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp $O(n \log n)$, mỗi thao tác BIT $O(\log n)$.
- **Bộ nhớ:** $O(n)$ — mảng đoạn và BIT.

## Mã nguồn (C++)

[Mã nguồn](../code/Nested%20Ranges%20Check.cpp)
