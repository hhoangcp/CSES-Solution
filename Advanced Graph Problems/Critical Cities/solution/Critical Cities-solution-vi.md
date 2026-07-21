# Critical Cities - Lời giải

**ID:** 1703 | **URL:** https://cses.fi/problemset/task/1703

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh, $m$ cạnh. Tìm tất cả thành phố nằm trên **mọi** đường đi từ đỉnh 1 đến đỉnh $n$.

### Ý tưởng chính

Đỉnh $v$ nằm trên mọi đường đi từ 1 đến $n$ chính là **đỉnh dominate** của $n$ với nguồn 1. Tập các đỉnh dominate được biểu diễn bằng **cây dominate** gốc 1, trong đó $v$ dominate $u$ iff $v$ là tổ tiên của $u$. Các thành phố thiết yếu chính là các đỉnh trên đường đi từ 1 đến $n$ trong cây dominate.

**Tính tương đương:** Nếu $v$ nằm trên đường đi cây dominate từ 1 đến $n$, thì $v$ dominate $n$ (theo tính truyền: $v$ dominate $u$ và $u$ dominate $w$ thì $v$ dominate $w$), nên mọi đường đi từ 1 đến $n$ phải qua $v$. Ngược lại, nếu $v$ không nằm trên đường đi này thì $v$ không là tổ tiên của $n$ trong cây dominate, tức $v$ không dominate $n$, nên tồn tại đường đi từ 1 đến $n$ tránh $v$.

### Thuật toán

1. Chạy DFS từ đỉnh 1 để gán số DFS và xây cây DFS.
2. Áp dụng thuật toán **Lengauer-Tarjan**: tính semidominator dùng union-find với nén đường đi, xử lý đỉnh theo thứ tự DFS giảm dần, tính immediate dominator (`idom`).
3. Truy ngược từ $n$ về 1 qua các `idom` — các đỉnh trên đường đi này chính là thành phố thiết yếu.
4. Xuất số lượng và danh sách theo thứ tự tăng dần.

### Ví dụ minh họa

$n=5$, cạnh: $1\to2, 2\to3, 2\to4, 3\to5, 4\to5$.

Cây dominate: 1 dominate tất cả, 2 dominate 3,4,5. Đường đi từ 1 đến 5: $1 \to 2 \to 5$.

Thành phố thiết yếu: **1, 2, 5**.

## Độ phức tạp

- **Thời gian:** $O((n + m) \cdot \alpha(n, m))$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Critical%20Cities.cpp)
