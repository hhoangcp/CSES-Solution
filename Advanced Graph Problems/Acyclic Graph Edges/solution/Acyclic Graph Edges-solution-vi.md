# Acyclic Graph Edges - Lời giải

**ID:** 1756 | **URL:** https://cses.fi/problemset/task/1756

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng có $n$ đỉnh và $m$ cạnh, hãy định hướng mỗi cạnh sao cho đồ thị có hướng kết quả không chứa chu trình.

### Ý tưởng chính

Sử dụng chính chỉ số đỉnh $1, 2, \ldots, n$ làm thứ tự topo. Định hướng mọi cạnh từ đỉnh nhỏ hơn sang đỉnh lớn hơn. Khi đó mọi đường đi có hướng phải đi qua các đỉnh theo thứ tự tăng nghiêm ngặt, và một dãy tăng nghiêm ngặt không thể tạo thành chu trình: giả sử tồn tại chu trình $v_1 \to v_2 \to \cdots \to v_k \to v_1$, thì $v_1 < v_2 < \cdots < v_k < v_1$, suy ra $v_1 < v_1$ — vô lý. Cách này hoạt động với bất kỳ đồ thị vô hướng nào.

### Thuật toán

Với mỗi cạnh vô hướng $\{u, v\}$:
1. Nếu $u > v$, đổi chỗ $u$ và $v$ sao cho $u < v$.
2. Xuất cạnh có hướng $u \to v$.

### Ví dụ minh họa

Đầu vào: chu trình vô hướng $1\text{-}2, 2\text{-}3, 3\text{-}1$.

- Cạnh $\{1, 2\}$: $1 < 2$, xuất $1 \to 2$.
- Cạnh $\{2, 3\}$: $2 < 3$, xuất $2 \to 3$.
- Cạnh $\{3, 1\}$: đổi thành $\{1, 3\}$, xuất $1 \to 3$.

Kết quả: $1 \to 2, 2 \to 3, 1 \to 3$ — DAG hợp lệ (thứ tự topo: $1, 2, 3$).

## Độ phức tạp

- **Thời gian:** $O(m)$
- **Không gian:** $O(1)$ ngoài đầu vào

## Mã nguồn (C++)

[Mã nguồn](../code/Acyclic%20Graph%20Edges.cpp)
