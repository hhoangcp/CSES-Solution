# Path Queries - Lời giải

**ID:** 1138 | **URL:** https://cses.fi/problemset/task/1138

## Phương pháp

### Tóm tắt bài toán

Cho một cây có gốc gồm $n$ đỉnh (gốc là đỉnh $1$), mỗi đỉnh $u$ có trọng số $w[u]$. Xử lý $q$ truy vấn:

1. `$1\ s\ x$`: đổi trọng số đỉnh $s$ thành $x$.
2. `$2\ s$`: tính tổng trọng số các đỉnh trên đường đi từ gốc đến $s$.

**Ràng buộc:** $1 \le n, q \le 2 \cdot 10^5$, $1 \le v_i, x \le 10^9$.

### Ý tưởng chính

Tổng trên đường đi gốc $\to v$ chính là tổng trọng số của mọi tổ tiên của $v$ (kể cả $v$). Do đó trọng số $w[u]$ của một đỉnh $u$ ảnh hưởng đến tổng đường đi của **mọi đỉnh trong cây con** $u$ (vì $u$ là tổ tiên của chúng). Coi truy vấn gốc $\to v$ là truy vấn điểm tại $v$, thì việc cập nhật $w[u]$ chính là cập nhật đoạn trên cây con $u$.

Phẳng hóa cây bằng Euler Tour: DFS từ gốc, gán $Start[u]$ là thời điểm vào và $End[u]$ là thời điểm ra (cả cây con $u$ chiếm đoạn $[Start[u], End[u]]$). Dùng BIT chênh lệch để hỗ trợ **cập nhật đoạn — truy vấn điểm**: khi $w[u]$ thay đổi một lượng $\Delta$, cập nhật `Update(Start[u], +Δ)` và `Update(End[u]+1, -Δ)`. Khi đó tổng tiền tố tại vị trí $Start[v]$, tức `Query(Start[v])`, đúng bằng tổng trọng số mọi tổ tiên của $v$.

**Tính đúng đắn:** $w[u]$ được cộng tại $Start[u]$ và trừ tại $End[u]+1$, nên nó nằm trong tổng tiền tố tại vị trí $p$ khi và chỉ khi $Start[u] \le p \le End[u]$. Đặt $p = Start[v]$: điều kiện này đúng khi $v$ nằm trong cây con của $u$, tức $u$ là tổ tiên của $v$. Vậy `Query(Start[v])` chỉ cộng đúng đóng góp của các tổ tiên (kể cả $v$); các đỉnh không phải tổ tiên thì hoặc $Start[u] > Start[v]$ (chưa được cộng) hoặc $End[u]+1 \le Start[v]$ (đã bị trừ).

### Thuật toán

1. Đọc $n, q$; mảng trọng số $w[1..n]$; dựng danh sách kề (mảng `lab` để không đi ngược lên cha).
2. `DFS(1)`: $Start[u] = ++Time$; với mỗi con $v$ (`lab[u] != v`), đặt $lab[v]=u$ rồi DFS; sau cùng $End[u] = Time$.
3. Khởi tạo BIT: với mỗi $u$, `Update(Start[u], w[u])` và `Update(End[u]+1, -w[u])`.
4. Với mỗi truy vấn:
   - Loại `1 s x`: $\Delta = x - w[s]$; `Update(Start[s], Δ)`; `Update(End[s]+1, -Δ)`; gán $w[s] = x$.
   - Loại `2 s`: in `Query(Start[s])`.

### Ví dụ minh họa

Đề bài cho $n = 5$, $q = 3$, trọng số $\{4, 2, 5, 2, 1\}$ (đỉnh $1..5$), cạnh `1-2, 1-3, 3-4, 3-5`. Gốc là $1$.

DFS (theo thứ tự kề `V[1]=[2,3]`, `V[3]=[1,4,5]`):

| $u$ | $Start[u]$ | $End[u]$ | $w[u]$ |
|---|---|---|---|
| $1$ | $1$ | $5$ | $4$ |
| $2$ | $2$ | $2$ | $2$ |
| $3$ | $3$ | $5$ | $5$ |
| $4$ | $4$ | $4$ | $2$ |
| $5$ | $5$ | $5$ | $1$ |

Khởi tạo BIT (cộng tại $Start[u]$, trừ tại $End[u]+1$):

| $u$ | $+w[u]$ tại | $-w[u]$ tại |
|---|---|---|
| $1$ | $1$ | $6$ |
| $2$ | $2$ | $3$ |
| $3$ | $3$ | $6$ |
| $4$ | $4$ | $5$ |
| $5$ | $5$ | $6$ |

Mảng chênh lệch $d[1..6]$: $[+4,\ +2,\ +3(=5-2),\ +2,\ -1(=1-2),\ -10(=-4-5-1)]$.

- Truy vấn `2 4`: `Query(Start[4]=4)` $= 4+2+3+2 = 11$ $= w[1]+w[3]+w[4] = 4+5+2$. In `11`.
- Truy vấn `1 3 2`: $\Delta = 2 - 5 = -3$; `Update(3, -3)`, `Update(6, +3)`; $w[3] = 2$. Mảng chênh lệch mới: $d[3]=0$, $d[6]=-7$.
- Truy vấn `2 4`: `Query(4)` $= 4+2+0+2 = 8$ $= w[1]+w[3]+w[4] = 4+2+2$. In `8`.

Kết quả: `11`, `8` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n + q \log n)$ — DFS $O(n)$; khởi tạo BIT $O(n \log n)$; mỗi truy vấn $O(\log n)$.
- **Bộ nhớ:** $O(n)$ — danh sách kề, mảng $Start/End/w/lab$ và BIT.

## Mã nguồn (C++)

[Mã nguồn](../code/Path%20Queries.cpp)
