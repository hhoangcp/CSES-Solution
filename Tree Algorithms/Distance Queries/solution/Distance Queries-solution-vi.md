# Distance Queries - Lời giải

**ID:** 1135 | **URL:** https://cses.fi/problemset/task/1135

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh. Xử lý $q$ truy vấn, mỗi truy vấn yêu cầu tính khoảng cách (số cạnh trên đường đi ngắn nhất) giữa hai đỉnh $a$ và $b$.

**Ràng buộc:** $1 \le n, q \le 2 \cdot 10^5$.

### Ý tưởng chính

Trong cây, đường đi duy nhất giữa $u$ và $v$ có dạng $u \to \text{LCA}(u,v) \to v$: đi lên từ $u$ đến tổ tiên chung thấp nhất $p = \text{LCA}(u,v)$ rồi đi xuống đến $v$. Phân tích số cạnh:

- Đoạn $u \to p$: $depth[u] - depth[p]$.
- Đoạn $p \to v$: $depth[v] - depth[p]$.

Tổng:

$$\text{dist}(u, v) = depth[u] + depth[v] - 2 \cdot depth[\text{LCA}(u, v)]$$

Vậy bài toán quy về tính LCA nhanh. Ta dùng **nhị phân nâng**: DFS từ gốc (đỉnh $1$) tính $par[u][i]$ (tổ tiên thứ $2^i$) với công thức $par[u][i] = par[par[u][i-1]][i-1]$ và $depth[u]$, đặt $LOG = 18$ vì $n \le 2 \cdot 10^5$. Mỗi truy vấn LCA tốn $O(\log n)$.

**Tính đúng đắn:** Đường đi trong cây là duy nhất, nên khoảng cách $\text{dist}(u,v)$ chính là số cạnh trên đường $u \to v$. Đường này bắt buộc đi qua $p = \text{LCA}(u,v)$: nếu đi qua tổ tiên cao hơn $p$ thì tạo thêm đoạn lên–xuống làm đường dài hơn (cây không có chu trình để "tắt"), còn tổ tiên thấp hơn $p$ không là tổ tiên chung của cả $u$ và $v$ nên không thể dẫn từ $u$ đến $v$. Do đó đường đi phải có dạng $u \to p \to v$, và tổng số cạnh đúng bằng $depth[u] + depth[v] - 2 \cdot depth[p]$.

### Thuật toán

1. Đọc $n, q$; dựng danh sách kề từ $n-1$ cạnh. Đặt $par[1][0] = 0$, $depth[1] = 0$.
2. DFS từ gốc $1$:
   - Với mỗi $i$ từ $1$ đến $18$: $par[u][i] = par[par[u][i-1]][i-1]$.
   - Với mỗi con $v$ của $u$ (không tính cha): đặt $par[v][0] = u$, $depth[v] = depth[u] + 1$, rồi DFS($v$).
3. Hàm LCA$(u, v)$:
   - Nếu $depth[u] > depth[v]$, đổi chỗ $u, v$. Tính $h = depth[v] - depth[u]$; duyệt $i$ từ $18$ xuống $0$, nếu bit $i$ của $h$ bật thì $v = par[v][i]$.
   - Nếu $u = v$, trả về $u$.
   - Duyệt $i$ từ $18$ xuống $0$: nếu $par[u][i] \ne par[v][i]$, gán $u = par[u][i]$, $v = par[v][i]$.
   - Trả về $par[u][0]$.
4. Với mỗi truy vấn $(a, b)$: in $depth[a] + depth[b] - 2 \cdot depth[\text{LCA}(a, b)]$.

### Ví dụ minh họa

Đề bài cho $n = 5$, $q = 3$; cạnh `1-2, 1-3, 3-4, 3-5`. Gốc là $1$.

Cây: con của $1$ là $\{2, 3\}$; con của $3$ là $\{4, 5\}$.

$depth$: $depth[1]=0,\ depth[2]=1,\ depth[3]=1,\ depth[4]=2,\ depth[5]=2$.

$par[\cdot][0]$: $par[1][0]=0,\ par[2][0]=1,\ par[3][0]=1,\ par[4][0]=3,\ par[5][0]=3$.

| Truy vấn | $p = \text{LCA}$ | Tính | Kết quả |
|---|---|---|---|
| $\text{dist}(1, 3)$ | $\text{LCA}(1,3)=1$ | $0 + 1 - 2 \cdot 0 = 1$ | $1$ |
| $\text{dist}(2, 5)$ | $\text{LCA}(2,5)=1$ | $1 + 2 - 2 \cdot 0 = 3$ | $3$ |
| $\text{dist}(1, 4)$ | $\text{LCA}(1,4)=1$ | $0 + 2 - 2 \cdot 0 = 2$ | $2$ |

Kết quả: `1`, `3`, `2` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$ — tiền xử lý $O(n \log n)$, mỗi truy vấn LCA $O(\log n)$.
- **Bộ nhớ:** $O(n \log n)$ — bảng nhị phân nâng $par$ kích thước $n \times (LOG + 1)$ và mảng $depth$.

## Mã nguồn (C++)

[Mã nguồn](../code/Distance%20Queries.cpp)
