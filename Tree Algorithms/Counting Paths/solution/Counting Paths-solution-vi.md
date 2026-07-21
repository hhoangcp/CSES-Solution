# Counting Paths - Lời giải

**ID:** 1136 | **URL:** https://cses.fi/problemset/task/1136

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh và $m$ đường đi trên cây. Tính với mỗi đỉnh số lượng đường đi chứa đỉnh đó.

**Ràng buộc:** $1 \le n, m \le 2 \cdot 10^5$.

### Ý tưởng chính

Nếu với mỗi đường đi ta duyệt và cộng $+1$ cho mọi đỉnh trên đường đi, chi phí là $O(n)$ mỗi đường đi, tổng $O(nm)$ — quá chậm. Áp dụng **mảng chênh lệch trên cây** kết hợp **LCA** để ghi nhận mỗi đường đi trong $O(\log n)$.

Về tiền xử lý, dùng nhị phân nâng: DFS từ gốc (đỉnh $1$) tính $par[u][i]$ (tổ tiên thứ $2^i$) và $depth[u]$, với công thức $par[u][i] = par[par[u][i-1]][i-1]$, đặt $LOG = 18$ vì $n \le 2 \cdot 10^5$.

Với mỗi đường đi từ $u$ đến $v$, gọi $p = \text{LCA}(u, v)$. Đường đi có dạng $u \to p \to v$. Ta ghi nhận $4$ cập nhật chênh lệch:

- $++ans[u]$ và $++ans[v]$: đánh dấu hai đầu mút.
- $--ans[p]$: tại $p$ hai nhánh $u \to p$ và $v \to p$ cùng đổ lên $+2$ sau lan truyền, trừ $1$ để $p$ nhận đúng $+1$.
- $--ans[par[p]]$ (chỉ khi $p \ne 1$): triệt tiêu dòng $+1$ vượt lên phía trên $p$ ngoài phạm vi đường đi.

Sau khi ghi nhận toàn bộ $m$ đường đi, lan truyền kết quả bằng DFS hậu thứ tự: mỗi nút cộng dồn giá trị của các con vào chính nó, $ans[u] \mathrel{+}= \sum_{v \in \text{con}(u)} ans[v]$.

**Tính đúng đắn:** Xét đóng góp của một đường đi $a \to b$ với $p = \text{LCA}(a,b)$ vào $val[u]$ sau lan truyền. Lan truyền từ lá lên gốc nên $val[u] = \text{init}[u] + \sum_{\text{con}} val[\text{con}]$. Các nút trên nhánh $a \to p$ (trừ $p$) nhận $+1$ từ con dọc đường đi rồi lan truyền $+1$ lên; tương tự cho nhánh $b \to p$. Tại $p$: nhận $+1$ từ mỗi nhánh ($2$ tổng) cộng khởi tạo $-1$ ra $1$, lan truyền $+1$ lên. Tại $par[p]$: nhận $+1$ từ $p$ cộng khởi tạo $-1$ ra $0$, lan truyền $0$ lên — chặn dòng chảy ngoài đường đi. Các nút không trên đường đi không nhận đóng góp. Vậy $val[u] = 1$ đúng khi $u$ nằm trên đường đi, $0$ khi ngoài.

### Thuật toán

1. Đọc $n, m$; dựng danh sách kề từ $n-1$ cạnh. Đặt $par[1][0] = 0$, $depth[1] = 0$.
2. DFS từ gốc $1$: với mỗi $i$ từ $1$ đến $18$, $par[u][i] = par[par[u][i-1]][i-1]$; với mỗi con $v$ của $u$ (không tính cha) đặt $par[v][0] = u$, $depth[v] = depth[u] + 1$, DFS($v$).
3. Hàm LCA$(u, v)$: cân bằng độ sâu (đổi chỗ để $depth[u] \le depth[v]$, nâng $v$ lên $h = depth[v] - depth[u]$ bước theo bit nhị phân); nếu $u = v$ trả về $u$; ngược lại duyệt $i$ từ $18$ xuống $0$, nếu $par[u][i] \ne par[v][i]$ thì nâng cả hai lên; trả về $par[u][0]$.
4. Với mỗi đường đi $(u, v)$: $p = \text{LCA}(u,v)$; thực hiện $++ans[u],\ ++ans[v],\ --ans[p]$; nếu $p \ne 1$ thì $--ans[par[p][0]]$.
5. DFS hậu thứ tự `DFS2` từ gốc: với mỗi con $v$ của $u$, `DFS2(v)` rồi $ans[u] \mathrel{+}= ans[v]$.
6. In $ans[1..n]$.

### Ví dụ minh họa

Đề bài cho $n = 5$, $m = 3$; cạnh `1-2, 1-3, 3-4, 3-5`; đường đi `1→3, 2→5, 1→4`. Gốc là $1$.

Cây: con của $1$ là $\{2, 3\}$; con của $3$ là $\{4, 5\}$.

$depth$: $depth[1]=0,\ depth[2]=1,\ depth[3]=1,\ depth[4]=2,\ depth[5]=2$.

$par[\cdot][0]$: $par[1][0]=0,\ par[2][0]=1,\ par[3][0]=1,\ par[4][0]=3,\ par[5][0]=3$.

Tính LCA cho từng đường đi:

- $\text{LCA}(1, 3) = 1$ (đỉnh $1$ là tổ tiên của $3$).
- $\text{LCA}(2, 5) = 1$ (đường $2 \to 1 \to 3 \to 5$, hội tại $1$).
- $\text{LCA}(1, 4) = 1$ (đỉnh $1$ là tổ tiên của $4$).

Cập nhật chênh lệch (khởi tạo $ans \equiv 0$):

| Đường đi | $p$ | Cập nhật | Tổng mỗi ô |
|---|---|---|---|
| $1 \to 3$ | $1$ | $+1[1],\ +1[3],\ -1[1]$ ($p=1$ nên bỏ $-1[par]$) | $ans[1]\mathrel{+}=0,\ ans[3]\mathrel{+}=1$ |
| $2 \to 5$ | $1$ | $+1[2],\ +1[5],\ -1[1]$ ($p=1$) | $ans[1]\mathrel{+}=-1,\ ans[2]\mathrel{+}=1,\ ans[5]\mathrel{+}=1$ |
| $1 \to 4$ | $1$ | $+1[1],\ +1[4],\ -1[1]$ ($p=1$) | $ans[1]\mathrel{+}=0,\ ans[4]\mathrel{+}=1$ |

Sau cập nhật: $ans[1]=-1,\ ans[2]=1,\ ans[3]=1,\ ans[4]=1,\ ans[5]=1$.

Lan truyền hậu thứ tự:

- $ans[4] = 1$ (không có con).
- $ans[5] = 1$ (không có con).
- $ans[3] \mathrel{+}= ans[4] + ans[5] = 1 + 1 + 1 = 3$.
- $ans[2] = 1$ (không có con).
- $ans[1] \mathrel{+}= ans[2] + ans[3] = -1 + 1 + 3 = 3$.

Kết quả: `3 1 3 1 1` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$ — tiền xử lý LCA $O(n \log n)$, $m$ truy vấn LCA $O(m \log n)$, lan truyền $O(n)$.
- **Bộ nhớ:** $O(n \log n)$ — bảng nhị phân nâng $par$ kích thước $n \times (LOG + 1)$, mảng $depth$ và mảng $ans$.

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Paths.cpp)
