# MST Edge Check - Lời giải

**ID:** 3407 | **URL:** https://cses.fi/problemset/task/3407

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng có trọng số liên thông, xác định với mỗi cạnh liệu nó có thể nằm trong một MST nào đó không.

### Ý tưởng chính

Cạnh $e = (u, v, w)$ thuộc MST nào đó iff trọng số cạnh lớn nhất trên đường đi $u$-$v$ trong MST cố định $\geq w$.

- Nếu `mx_query(u,v) >= w`: tồn tại cạnh $e'$ nặng nhất trên đường đi có trọng số $w' \geq w$. Thay $e'$ bằng $e$: $T' = T \setminus \{e'\} \cup \{e\}$ vẫn là cây bao trùm (loại $e'$ chia cây thành hai phần, $e$ nối lại), và $w(T') = w(T) - w' + w \leq w(T)$, nên $T'$ là MST chứa $e$.
- Nếu `mx_query(u,v) < w`: $e$ là cạnh nặng nhất trên chu trình tạo bởi đường đi $u$-$v$ trong MST cộng với $e$. Theo tính chất chu trình, cạnh nặng nhất trên chu trình không thuộc MST nào.

Cạnh thuộc MST luôn YES vì chính nó nằm trên đường đi, nên `mx_query >= w`.

### Thuật toán

1. Sắp xếp cạnh theo trọng số, xây MST bằng Kruskal.
2. Gốc hóa MST, tính binary lifting với trọng số cạnh lớn nhất trên đường đi đến tổ tiên.
3. Với mỗi cạnh $(u, v, w)$: tính `mx_query(u, v)`. Nếu `>= w`, xuất YES; ngược lại NO.

### Ví dụ minh họa

$n=5$, MST gồm (3,4,1), (1,3,2), (2,4,2), (3,5,3).

Cạnh (1,2,4): đường đi 1-3-4-2, max = 2 < 4 → NO.

Cạnh MST: luôn YES.

## Độ phức tạp

- **Thời gian:** $O(m \log m + n \log n)$
- **Không gian:** $O(n \log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/MST%20Edge%20Check.cpp)
