# Subordinates - Lời giải

**ID:** 1674 | **URL:** https://cses.fi/problemset/task/1674

## Phương pháp

### Tóm tắt bài toán

Cho cấu trúc nhân sự của một công ty gồm $n$ nhân viên, nhân viên $1$ là tổng giám đốc. Với mỗi nhân viên $i$ ($2 \le i \le n$) cho biết sếp trực tiếp. Tính với mỗi nhân viên số cấp dưới (trực tiếp và gián tiếp).

**Ràng buộc:** $1 \le n \le 2 \cdot 10^5$.

### Ý tưởng chính

Cấu trúc công ty là một **cây có gốc** với nhân viên $1$ là gốc (mỗi nhân viên ngoài gốc có đúng một sếp trực tiếp). Số cấp dưới của nhân viên $u$ đúng bằng **kích thước cây con gốc $u$ trừ $1$** (trừ chính $u$).

Định nghĩa $sz[u]$ = số đỉnh trong cây con gốc $u$ (kể cả $u$). Tính $sz$ bằng DFS hậu thứ tự:

$$sz[u] = 1 + \sum_{v \in \text{con}(u)} sz[v]$$

vì cây con $u$ gồm chính $u$ và hợp (rời nhau) của các cây con của các con $v$. Đáp án cho nhân viên $u$ là $sz[u] - 1$.

**Tính đúng đắn (quy nạp theo chiều cao cây con):** lá không có con nên $sz = 1$, đúng bằng chính nó. Với nút nội, giả thiết quy nạp đúng cho mọi con $v$; vì mỗi đỉnh ngoài $u$ có đúng một cha, các cây con của các con là rời nhau, nên $|T_u| = 1 + \sum_v |T_v| = 1 + \sum_v sz[v] = sz[u]$. Vậy $sz[u]$ đúng bằng số đỉnh trong cây con gốc $u$, và số cấp dưới của $u$ là $sz[u] - 1$.

### Thuật toán

1. Đọc $n$; với mỗi nhân viên $i$ từ $2$ đến $n$, đọc sếp $p$ và thêm cạnh có hướng $p \to i$ vào danh sách kề (chỉ cần hướng từ cha xuống con).
2. `DFS(u)`: $sz[u] = 1$; với mỗi con $v \in V[u]$, gọi `DFS(v)` rồi $sz[u] \mathrel{+}= sz[v]$.
3. Gọi `DFS(1)`; in $sz[i] - 1$ với $i = 1 \dots n$.

### Ví dụ minh họa

Đề bài cho $n = 5$, danh sách sếp của nhân viên $2..5$ là `1 1 2 3`.

Cây (cha $\to$ con): $1 \to \{2, 3\}$; $2 \to \{4\}$; $3 \to \{5\}$.

DFS hậu thứ tự tính $sz$:

| $u$ | Tính $sz[u]$ | $sz[u]$ | Số cấp dưới $sz[u]-1$ |
|---|---|---|---|
| $4$ (lá) | $1$ | $1$ | $0$ |
| $5$ (lá) | $1$ | $1$ | $0$ |
| $2$ | $1 + sz[4] = 1 + 1$ | $2$ | $1$ |
| $3$ | $1 + sz[5] = 1 + 1$ | $2$ | $1$ |
| $1$ | $1 + sz[2] + sz[3] = 1 + 2 + 2$ | $5$ | $4$ |

Kết quả theo thứ tự nhân viên $1..5$: `4 1 1 0 0` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n)$ — mỗi đỉnh và mỗi cạnh được duyệt đúng một lần qua DFS.
- **Bộ nhớ:** $O(n)$ — danh sách kề và mảng $sz$.

## Mã nguồn (C++)

[Mã nguồn](../code/Subordinates.cpp)
