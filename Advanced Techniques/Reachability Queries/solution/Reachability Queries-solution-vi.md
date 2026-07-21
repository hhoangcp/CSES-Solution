# Reachability Queries - Lời giải

**ID:** 2143 | **URL:** https://cses.fi/problemset/task/2143

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh và $m$ cạnh, trả lời $q$ truy vấn dạng "có thể đến được đỉnh $b$ từ đỉnh $a$ không?"

### Ý tưởng chính

Với $n \leq 5 \times 10^4$ và $q \leq 10^5$, BFS/DFS cho từng truy vấn là quá chậm. Thay vào đó:

1. **Co về SCC:** Các đỉnh trong cùng SCC đến được nhau, nên co đồ thị thành DAG các SCC. Đỉnh $a$ đến được $b$ khi và chỉ khi SCC($a$) đến được SCC($b$) trong DAG — mọi đường đi từ $a$ đến $b$ đi qua chuỗi SCC tương ứng đường trong DAG, và ngược lại đường DAG mở rộng được bằng đường nội SCC.

2. **Bitset khả năng tiếp cận trên DAG:** Với mỗi SCC $u$, duy trì bitset $dp[u]$ với bit $j$ bật nếu $u$ đến được SCC $j$. Xử lý SCC theo thứ tự tô-pô ngược bằng DFS:

$$dp[u] = \{u\} \cup \bigcup_{v \in \text{kế}(u)} dp[v]$$

Phép hợp thực hiện qua OR bitset trong $O(S/64)$ mỗi cạnh, với $S$ là số SCC.

3. **Trả lời truy vấn** trong $O(1)$: kiểm tra bit SCC($b$) trong $dp[\text{SCC}(a)]$.

### Thuật toán

1. Tìm tất cả SCC bằng Tarjan ($O(n + m)$).
2. Xây DAG cô đặc: với mỗi cạnh $(u, v)$ mà SCC($u$) $\neq$ SCC($v$), thêm cạnh SCC($u$) $\to$ SCC($v$). Loại cạnh trùng.
3. Chạy DFS trên DAG tính bitset: đặt bit tự thân, rồi OR bitset của từng kế.
4. Với mỗi truy vấn $(a, b)$: nếu bit SCC($b$) bật trong $dp[\text{SCC}(a)]$, xuất "YES"; ngược lại "NO".

### Ví dụ minh họa

4 đỉnh, 4 cạnh: $(1,2), (2,3), (3,1), (4,3)$.

**SCC:** $\{1,2,3\}$ (SCC 0), $\{4\}$ (SCC 1). DAG: $1 \to 0$ (cạnh từ SCC 1 đến SCC 0).

**Tính bitset:**
- DFS(0): không có kế. $dp[0] = \{\text{bit } 0\}$.
- DFS(1): kế là SCC 0. $dp[1] = \{\text{bit } 1\} \cup dp[0] = \{\text{bit } 0, \text{bit } 1\}$.

**Truy vấn:**

| Truy vấn | SCC($a$) | SCC($b$) | Kiểm tra | Kết quả |
|----------|----------|----------|----------|---------|
| $1 \to 3$ | 0 | 0 | bit 0 trong $dp[0]$ | YES |
| $1 \to 4$ | 0 | 1 | bit 1 trong $dp[0]$ | NO |
| $4 \to 1$ | 1 | 0 | bit 0 trong $dp[1]$ | YES |

## Độ phức tạp

- **Thời gian:** $O(n + m + q + \frac{m \cdot S}{64})$, với $S$ là số SCC
- **Bộ nhớ:** $O(\frac{S^2}{64})$

## Mã nguồn (C++)

[Mã nguồn](../code/Reachability%20Queries.cpp)
