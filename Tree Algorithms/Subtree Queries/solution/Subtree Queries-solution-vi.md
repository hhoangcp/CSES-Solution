# Subtree Queries - Lời giải

**ID:** 1137 | **URL:** https://cses.fi/problemset/task/1137

## Phương pháp

### Tóm tắt bài toán

Cho một cây có gốc gồm $n$ đỉnh (gốc là đỉnh $1$), mỗi đỉnh $u$ có trọng số $w[u]$. Xử lý $q$ truy vấn:

1. `$1\ s\ x$`: đổi trọng số đỉnh $s$ thành $x$.
2. `$2\ s$`: tính tổng trọng số các đỉnh trong cây con gốc $s$.

**Ràng buộc:** $1 \le n, q \le 2 \cdot 10^5$, $1 \le v_i, x \le 10^9$.

### Ý tưởng chính

Phẳng hóa cây bằng Euler Tour: DFS từ gốc, khi vào $u$ gán $Start[u] = ++Time$; sau khi duyệt hết các con, gán $End[u] = Time$. Khi đó toàn bộ cây con gốc $u$ chiếm đúng đoạn liên tiếp $[Start[u], End[u]]$ trong thứ tự duyệt.

Dựng BIT (Fenwick Tree) trên mảng tuyến tính theo $Start$ để hỗ trợ **cập nhật điểm — truy vấn đoạn**:

- Khởi tạo: với mỗi đỉnh $u$, `Update(Start[u], w[u])`.
- Cập nhật đỉnh $s$ thành $x$: `Update(Start[s], x - w[s])`; gán $w[s] = x$.
- Truy vấn tổng cây con $s$: `Query(End[s]) - Query(Start[s] - 1)`.

**Tính đúng đắn:** DFS thăm $u$ tại thời điểm $Start[u]$, rồi đi lần lượt qua các cây con (mỗi cây con chiếm một đoạn liên tiếp), và không thăm đỉnh nào ngoài cây con $u$ cho đến khi ra khỏi $u$ tại $End[u]$. Do đó đúng các đỉnh thuộc cây con $u$ có $Start$ nằm trong $[Start[u], End[u]]$, và các đỉnh ngoài cây con $u$ có $Start$ ngoài đoạn này. Vì mỗi đỉnh $v$ đặt trọng số tại đúng vị trí $Start[v]$, tổng đoạn $[Start[s], End[s]]$ đúng bằng tổng trọng số cây con $s$.

### Thuật toán

1. Đọc $n, q$; mảng trọng số $w[1..n]$; dựng danh sách kề (mảng `lab` để không đi ngược lên cha).
2. `DFS(1)`: $Start[u] = ++Time$; với mỗi con $v$ (`lab[u] != v`), đặt $lab[v]=u$ rồi DFS; sau cùng $End[u] = Time$.
3. Khởi tạo BIT: với mỗi $u$, `Update(Start[u], w[u])`.
4. Với mỗi truy vấn:
   - Loại `1 s x`: `Update(Start[s], x - w[s])`; $w[s] = x$.
   - Loại `2 s`: in `Query(End[s]) - Query(Start[s] - 1)`.

### Ví dụ minh họa

Đề bài cho $n = 5$, $q = 3$, trọng số $\{4, 2, 5, 2, 1\}$ (đỉnh $1..5$), cạnh `1-2, 1-3, 3-4, 3-5`. Gốc là $1$.

Cây: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

DFS gán $Start/End$:

| $u$ | $Start[u]$ | $End[u]$ | $w[u]$ |
|---|---|---|---|
| $1$ | $1$ | $5$ | $4$ |
| $2$ | $2$ | $2$ | $2$ |
| $3$ | $3$ | $5$ | $5$ |
| $4$ | $4$ | $4$ | $2$ |
| $5$ | $5$ | $5$ | $1$ |

Khởi tạo BIT: đặt $w[u]$ tại vị trí $Start[u]$, mảng tuyến tính theo $Start$: $A[1..5] = [4, 2, 5, 2, 1]$.

- Truy vấn `2 3` (cây con $3$ gồm $\{3,4,5\}$): `Query(End[3]=5) - Query(Start[3]-1=2)` $= (4+2+5+2+1) - (4+2) = 14 - 6 = 8$. In `8`.
- Truy vấn `1 5 3`: $\Delta = 3 - 1 = 2$; `Update(Start[5]=5, +2)`; $w[5]=3$. Mảng tuyến tính mới: $A[5]=3$.
- Truy vấn `2 3`: `Query(5) - Query(2)` $= (4+2+5+2+3) - (4+2) = 16 - 6 = 10$. In `10`.

Kết quả: `8`, `10` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n + q \log n)$ — DFS $O(n)$; khởi tạo BIT $O(n \log n)$; mỗi truy vấn $O(\log n)$.
- **Bộ nhớ:** $O(n)$ — danh sách kề, mảng $Start/End/w/lab$ và BIT.

## Mã nguồn (C++)

[Mã nguồn](../code/Subtree%20Queries.cpp)
