# Path Queries II - Lời giải

**ID:** 2134 | **URL:** https://cses.fi/problemset/task/2134

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh, mỗi đỉnh $u$ có trọng số $w[u]$. Xử lý $q$ truy vấn:

1. `$1\ s\ x$`: đổi trọng số đỉnh $s$ thành $x$.
2. `$2\ a\ b$`: tìm trọng số lớn nhất trên đường đi đơn giữa $a$ và $b$.

**Ràng buộc:** $1 \le n, q \le 2 \cdot 10^5$, $1 \le v_i, x \le 10^9$.

### Ý tưởng chính

Dùng **phân tách nặng–nhẹ (Heavy-Light Decomposition, HLD)** kết hợp **cây phân đoạn (Segment Tree)**.

HLD chia các đỉnh của cây thành các **chuỗi** sao cho đường đi từ bất kỳ đỉnh nào lên gốc chỉ cắt tối đa $O(\log n)$ chuỗi. Xác định **con nặng** của mỗi đỉnh $u$ là con có $sz$ (kích thước cây con) lớn nhất; cạnh đến con nặng là **cạnh nặng**, các cạnh còn lại là **cạnh nhẹ**. Chuỗi đi dọc theo các cạnh nặng; con nhẹ bắt đầu một chuỗi mới.

Qua hai lượt DFS:

1. DFS thứ nhất tính $sz[u]$, $depth[u]$, lưu cha $lab[u]$, và đổi chỗ danh sách kề để con nặng nằm ở vị trí đầu (nối tiếp chuỗi của cha).
2. DFS thứ hai (HLD) gán $chain[u]$ và vị trí tuyến tính $pos[u]$: con nặng kế thừa $chain[u]$ ($chain[v]=chain[u]$), con nhẹ bắt đầu chuỗi mới ($chain[v]=v$). Các đỉnh cùng chuỗi nhận $pos$ liên tiếp, nên mỗi chuỗi chiếm một đoạn liên tục trên mảng tuyến tính.

Dựng Segment Tree trên mảng $pos$ để hỗ trợ cập nhật điểm và truy vấn max đoạn, đều $O(\log n)$.

Truy vấn max trên đường đi $u \to v$: khi $u, v$ khác chuỗi, nhảy chuỗi có **đầu sâu hơn** — giả sử $depth[chain[v]] \ge depth[chain[u]]$, lấy max trên đoạn $[pos[chain[v]], pos[v]]$ rồi đặt $v = lab[chain[v]]$; lặp đến khi cùng chuỗi, khi đó lấy max trên đoạn $[pos[u], pos[v]]$ (với $u$ nông hơn). Mỗi truy vấn cắt $\le O(\log n)$ chuỗi, mỗi lần một truy vấn đoạn $O(\log n)$, tổng $O(\log^2 n)$.

**Tính đúng đắn:** Mỗi lần nhảy qua một cạnh nhẹ, đỉnh đến là con nhẹ nên $sz$ của nó $\le sz[cha]/2$, tức kích thước cây con chứa đỉnh hiện tại tăng ít nhất gấp đôi; vì $sz \le n$ nên số lần nhảy cạnh nhẹ $\le \log_2 n$ — vậy đường đi lên gốc cắt $\le O(\log n)$ chuỗi. Thuật toán truy vấn nhảy chuỗi có đầu sâu hơn chính là đi lên từ cả $u$ và $v$ hướng về LCA: mỗi bước lấy max đúng trên đoạn từ đầu chuỗi đến đỉnh hiện tại (nằm trên đường đi lên LCA); khi hai đỉnh cùng chuỗi, đoạn còn lại từ đỉnh nông đến sâu chính là phần cuối của đường đi. Vậy toàn bộ đường đi được phủ kín, không trùng không sót.

### Thuật toán

1. Đọc $n, q$; mảng $w[1..n]$; dựng danh sách kề.
2. `DFS(1)`: $sz[u]=1$; với mỗi $v \in V[u]$ không phải cha, đặt $lab[v]=u$, $depth[v]=depth[u]+1$, đệ quy rồi $sz[u] \mathrel{+}= sz[v]$; ghi nhận con nặng (chỉ số con có $sz$ lớn nhất); cuối cùng `swap` con nặng lên $V[u][0]$.
3. `HLD(u, c)`: $chain[u]=c$; $pos[u] = ++pos[0]$; nếu $V[u][0]$ không phải cha thì `HLD(V[u][0], c)` (nối chuỗi); với các con nhẹ $V[u][i]$ ($i \ge 1$) không phải cha, gọi `HLD(v, v)`.
4. Khởi tạo Segment Tree: với mỗi $u$, `Update(pos[u], w[u])`.
5. Với mỗi truy vấn:
   - Loại `1 s x`: `Update(pos[s], x)`.
   - Loại `2 a b`: lặp trong khi $chain[u] \ne chain[v]$: nếu $depth[chain[u]] > depth[chain[v]]$ thì `swap(u, v)`; `mmax = max(mmax, Query(pos[chain[v]], pos[v]))`; $v = lab[chain[v]]$. Ra khỏi vòng, nếu $depth[u] > depth[v]$ thì `swap(u, v)`; `mmax = max(mmax, Query(pos[u], pos[v]))`; in `mmax`.

### Ví dụ minh họa

Đề bài cho $n = 5$, $q = 3$, trọng số $\{2, 4, 1, 3, 3\}$ (đỉnh $1..5$), cạnh `1-2, 1-3, 2-4, 2-5`. Gốc là $1$.

Cây: $1 \to \{2, 3\}$; $2 \to \{4, 5\}$.

DFS tính $sz$: $sz[1]=5,\ sz[2]=3,\ sz[3]=1,\ sz[4]=1,\ sz[5]=1$. Con nặng của $1$ là $2$, con nặng của $2$ là $4$ (con có $sz$ lớn nhất, chọn $4$). $depth$: $0,1,1,2,2$.

HLD gán chuỗi và vị trí:

| $u$ | $chain[u]$ | $pos[u]$ | $w[u]$ |
|---|---|---|---|
| $1$ | $1$ | $1$ | $2$ |
| $2$ | $1$ | $2$ | $4$ |
| $4$ | $1$ | $3$ | $3$ |
| $5$ | $5$ | $4$ | $3$ |
| $3$ | $3$ | $5$ | $1$ |

Ba chuỗi: $\{1,2,4\}$ (đoạn $pos\ [1,3]$), $\{3\}$ ($pos\ 5$), $\{5\}$ ($pos\ 4$). Mảng tuyến tính theo $pos$: $A[1..5] = [2, 4, 3, 3, 1]$.

Truy vấn `2 3 5` (max trên đường $3 \to 1 \to 2 \to 5$):

| Bước | $u$ | $v$ | $chain[u], chain[v]$ | Thao tác | `mmax` |
|---|---|---|---|---|---|
| 1 | $3$ | $5$ | $3,\ 5$ (khác; $depth[chain[5]]=2 > depth[chain[3]]=1$) | `Query(pos[5], pos[5]) = A[4]=3`; $v = lab[5] = 2$ | $3$ |
| 2 | $3$ | $2$ | $3,\ 1$ (khác; $depth[chain[3]]=1 > depth[chain[2]]=0$ $\Rightarrow$ swap) | `Query(pos[3], pos[3]) = A[5]=1`; $v = lab[3] = 1$ | $3$ |
| 3 | $2$ | $1$ | $1,\ 1$ (cùng chuỗi; $depth[2] > depth[1]$ $\Rightarrow$ swap) | `Query(pos[1], pos[2]) = max(A[1],A[2]) = max(2,4) = 4` | $4$ |

Kết quả `2 3 5` $= 4$.

Truy vấn `1 2 2`: `Update(pos[2]=2, 2)` $\Rightarrow$ $A[2]=2$.

Truy vấn `2 3 5` (đường $3 \to 1 \to 2 \to 5$, giờ $w[2]=2$): các bước tương tự cho `Query(pos[5],pos[5])=3`, `Query(pos[3],pos[3])=1`, `Query(pos[1],pos[2])=max(2,2)=2`; `mmax = max(3,1,2) = 3`. Kết quả $= 3$.

Output: `4 3` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n + q \log^2 n)$ — xây dựng HLD và Segment Tree $O(n)$; cập nhật điểm $O(\log n)$; mỗi truy vấn đường đi $\le O(\log n)$ chuỗi $\times$ $O(\log n)$ mỗi đoạn.
- **Bộ nhớ:** $O(n)$ — danh sách kề, các mảng HLD ($sz$, $depth$, $chain$, $lab$, $pos$) và Segment Tree.

## Mã nguồn (C++)

[Mã nguồn](../code/Path%20Queries%20II.cpp)
