# Hành Tinh và Vương Quốc - Lời giải

**ID:** 1683 | **URL:** https://cses.fi/problemset/task/1683

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh và $m$ cạnh, tìm tất cả thành phần liên thông mạnh (SCC) — tập cực đại các đỉnh mà mỗi đỉnh có thể đến được mọi đỉnh khác trong tập. Xuất số SCC và nhãn thành phần của mỗi đỉnh.

### Ý tưởng chính

"Một vương quốc" chính là một SCC. Thuật toán Tarjan tìm tất cả SCC trong một lần DFS, dùng hai giá trị trên mỗi đỉnh:

- $\text{num}[u]$: thứ tự khám phá đỉnh $u$.
- $\text{low}[u]$: giá trị $\text{num}$ nhỏ nhất có thể đến từ $u$ qua cạnh cây và tối đa một cạnh ngược đến tổ tiên vẫn còn trên ngăn xếp.

Khi $\text{low}[u] \geq \text{num}[u]$, đỉnh $u$ là gốc của một SCC: không có con cháu nào của $u$ đến được tổ tiên của $u$ (nếu có thì $\text{low}[u]$ nhỏ hơn), nên các đỉnh từ đỉnh ngăn xếp đến $u$ tạo thành tập liên thông mạnh cực đại. Mọi đỉnh được đẩy vào ngăn xếp khi khám phá và lấy ra đúng một lần khi tìm thấy gốc SCC, nên mọi SCC đều được phát hiện. Điều kiện $\text{low}[u] < \text{num}[u]$ nghĩa là $u$ đến được tổ tiên — $u$ thuộc cùng SCC với tổ tiên đó và sẽ được thu thập khi gốc SCC của tổ tiên được tìm thấy.

### Thuật toán

1. DFS từ mỗi đỉnh chưa thăm $u$: đặt $\text{num}[u] = ++$time, $\text{low}[u] = \infty$, đẩy $u$ vào ngăn xếp.
2. Với mỗi cạnh $(u, v)$:
   - Nếu $v$ chưa thăm: đệ quy, rồi $\text{low}[u] = \min(\text{low}[u], \text{low}[v])$.
   - Nếu $v$ đã thăm và vẫn trên ngăn xếp: $\text{low}[u] = \min(\text{low}[u], \text{num}[v])$.
3. Sau khi duyệt hết cạnh từ $u$: nếu $\text{low}[u] \geq \text{num}[u]$, lấy các đỉnh từ đỉnh ngăn xếp đến $u$ gán nhãn SCC tiếp theo.
4. Xuất số SCC và nhãn của mỗi đỉnh.

### Ví dụ minh họa

Input:
```
5 6
1 2
2 3
3 1
3 4
4 5
5 4
```

SCC: $\{1, 2, 3\}$ và $\{4, 5\}$.

Kết quả:
```
2
1 1 1 2 2
```

(Bất kỳ nhãn hợp lệ nào đều được chấp nhận.)

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Planets%20and%20Kingdoms.cpp)
