# Grid Puzzle I - Lời giải

**ID:** 2432 | **URL:** https://cses.fi/problemset/task/2432

## Đề bài

Có một lưới $n \times n$, chọn từ mỗi hàng đúng $a_i$ ô và từ mỗi cột đúng $b_j$ ô. Xuất bất kỳ cách chọn hợp lệ hoặc $-1$ nếu không thể.

## Hướng tiếp cận

### Mô hình hóa: Luồng nguyên trên đồ thị hai phía

Bài toán là tìm cách chọn ô thỏa mãn đồng thời ràng buộc bậc hàng ($a_i$) và cột ($b_j$). Xây mạng luồng:

- **Nguồn $S$** $\to$ **hàng $i$**: dung lượng $a_i$ (hàng $i$ chọn đúng $a_i$ ô).
- **Hàng $i$** $\to$ **cột $j$**: dung lượng 1 (mỗi ô chọn tối đa 1 lần). Mỗi đơn vị luồng qua đây = chọn ô $(i,j)$.
- **Cột $j$** $\to$ **đích $T$**: dung lượng $b_j$ (cột $j$ chọn đúng $b_j$ ô).

### Lời giải tồn tại khi và chỉ khi luồng cực đại = $\sum a_i$

Cách chọn hợp lệ gửi 1 đơn vị qua mỗi ô được chọn, tổng luồng = $\sum a_i$, bão hòa mọi cạnh nguồn $\to$ hàng và cột $\to$ đích. Ngược lại, nếu luồng cực đại = $\sum a_i$, mọi cạnh nguồn $\to$ hàng và cột $\to$ đích đều bão hòa. Vì cạnh hàng $\to$ cột có dung lượng nguyên (1), theo định lý luồng nguyên, luồng trên mỗi cạnh chỉ là 0 hoặc 1 — tương ứng "không chọn" hoặc "chọn" ô đó, thỏa mãn chính xác mọi ràng buộc bậc.

## Thuật toán

1. Nếu $\sum a_i \neq \sum b_j$, xuất $-1$.
2. Tìm luồng cực đại bằng Dinic.
3. Nếu luồng $< \sum a_i$, xuất $-1$.
4. Ngược lại, với mỗi cạnh hàng $\to$ cột có flow = 1, đánh dấu ô `X`.

## Ví dụ minh họa

$n = 5$, $a = [0, 1, 3, 2, 0]$, $b = [1, 2, 2, 0, 1]$. $\sum = 6$.

Luồng cực đại = 6 = $\sum a_i$. Các ô có flow = 1 được đánh `X`, mỗi hàng đúng $a_i$ ô, mỗi cột đúng $b_j$ ô.

## Độ phức tạp

- **Thời gian:** $O(n^{5/2})$ — Dinic trên đồ thị hai phía dung lượng đơn vị
- **Bộ nhớ:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Puzzle%20I.cpp)
