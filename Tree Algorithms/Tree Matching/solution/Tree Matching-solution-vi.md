# Tree Matching - Lời giải

**ID:** 1130 | **URL:** https://cses.fi/problemset/task/1130

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh. Một *phép ghép* là tập hợp các cạnh sao cho mỗi đỉnh là đầu mút của nhiều nhất một cạnh. Tìm số cạnh tối đa trong một phép ghép.

**Ràng buộc:** $1 \le n \le 2 \cdot 10^5$.

### Ý tưởng chính

Dùng quy hoạch động trên cây. Chọn đỉnh $1$ làm gốc tạm. Với mỗi $u$, định nghĩa hai trạng thái:

- $dp[u][0]$: số cạnh ghép tối đa trong cây con $u$ khi $u$ **không** ghép với bất kỳ con nào.
- $dp[u][1]$: số cạnh ghép tối đa trong cây con $u$ khi $u$ **được** ghép với đúng một con.

Công thức chuyển (DFS hậu thứ tự):

- $dp[u][0] = \sum_{v \in \text{con}(u)} \max(dp[v][0], dp[v][1])$ — $u$ không ghép với con nên mỗi cây con $v$ độc lập, chọn trạng thái tốt hơn.
- $dp[u][1] = \max_{w \in \text{con}(u)} \bigl(1 + dp[w][0] + \sum_{v \ne w} \max(dp[v][0], dp[v][1])\bigr)$ — chọn đúng một con $w$ để ghép; $w$ buộc không ghép với con của nó ($dp[w][0]$), các con khác tự do.

Tính trực tiếp $dp[u][1]$ sẽ tốn $O(\deg(u)^2)$. Đặt $S = dp[u][0] = \sum_v \max(dp[v][0], dp[v][1])$ và $f[v] = \max(dp[v][0], dp[v][1])$, ta rút gọn:

$$dp[u][1] = 1 + S + \max_{w \in \text{con}(u)} \bigl(dp[w][0] - f[w]\bigr)$$

vì $1 + dp[w][0] + (S - f[w]) = 1 + S + (dp[w][0] - f[w])$. Code dùng mảng tiền tố/hậu tố để lấy $\sum_{v \ne w} f[v] = S - f[w]$ trong $O(1)$ cho từng $w$, giảm tổng thời gian về $O(n)$. Đáp án là $\max(dp[1][0], dp[1][1])$.

**Tính đúng đắn (quy nạp theo chiều cao cây con):** Lá: $dp[u][0]=dp[u][1]=0$ đúng. Giả sử đúng với mọi con $v$. Nếu $u$ không ghép với con, các cây con độc lập nên tối ưu đúng $\sum_v \max(dp[v][0],dp[v][1])=dp[u][0]$. Nếu $u$ ghép đúng một con $w$, cạnh $(u,w)$ dùng $1$ cạnh, $w$ phải không ghép với con ($dp[w][0]$), các cây con khác độc lập với đóng góp $\sum_{v\ne w}\max(dp[v][0],dp[v][1])$; lấy max theo $w$ đúng cho $dp[u][1]$. Tại gốc, chọn trạng thái tốt hơn giữa "ghép" và "không ghép" cho ra $\max(dp[1][0], dp[1][1])$.

### Thuật toán

1. Đọc $n$; dựng danh sách kề từ $n-1$ cạnh.
2. `DFS(u)` (dùng `lab` để không quay lên cha): $dp[u][0] = dp[u][1] = 0$.
   - Với mỗi con $v$ (`lab[u] != v`): $lab[v] = u$, `DFS(v)`, $dp[u][0] \mathrel{+}= \max(dp[v][0], dp[v][1])$.
   - Dựng mảng tiền tố $Left$ trên $V[u]$: với mỗi $v = V[u][i]$ không phải cha, $Left[i] = \max(dp[v][0], dp[v][1])$; nếu $i>0$ thì $Left[i] \mathrel{+}= Left[i-1]$ (bỏ qua cha, giữ giá trị trước đó).
   - Duyệt $i$ từ $|V[u]|-1$ xuống $0$, duy trì $Right$ = tổng $\max(dp[v][0], dp[v][1])$ của các con bên phải $i$: với mỗi con $v = V[u][i]$, cập nhật $dp[u][1] = \max\bigl(dp[u][1],\ 1 + dp[v][0] + Right + Left[i-1]\bigr)$ (hoặc $1 + dp[v][0] + Right$ nếu $i=0$); rồi $Right \mathrel{+}= \max(dp[v][0], dp[v][1])$.
3. Gọi `DFS(1)`; in $\max(dp[1][0], dp[1][1])$.

### Ví dụ minh họa

Đề bài cho $n = 5$, cạnh `1-2, 1-3, 3-4, 3-5`. Cây: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

DFS hậu thứ tự tính $dp$:

| $u$ | $dp[u][0]$ | $dp[u][1]$ | Ghi chú |
|---|---|---|---|
| $2$ (lá) | $0$ | $0$ | không có con |
| $4$ (lá) | $0$ | $0$ | không có con |
| $5$ (lá) | $0$ | $0$ | không có con |
| $3$ | $\max(0,0)+\max(0,0)=0$ | $\max(1+dp[4][0],\ 1+dp[5][0])=1$ | ghép $3$ với $4$ hoặc $5$ |
| $1$ | $\max(0,0)+\max(0,1)=1$ | $\max\bigl(1+dp[2][0]+(S-f[2]),\ 1+dp[3][0]+(S-f[3])\bigr) = \max(1+0+1,\ 1+0+0)=2$ | ghép $1$ với $2$; nhánh $3$ đóng góp $\max(0,1)=1$ (ghép $3$ với $4$) |

Chi tiết $dp[1][1]$: $S = dp[1][0] = 1$, $f[2]=\max(0,0)=0$, $f[3]=\max(0,1)=1$.

- Ghép $1$ với $2$: $1 + dp[2][0] + (S - f[2]) = 1 + 0 + (1 - 0) = 2$.
- Ghép $1$ với $3$: $1 + dp[3][0] + (S - f[3]) = 1 + 0 + (1 - 1) = 1$.

$\max = 2$ (chọn ghép $1$ với $2$, nhánh $3$ tự do ghép $3$ với $4$).

Kết quả: $\max(dp[1][0], dp[1][1]) = \max(1, 2) = 2$. Phép ghép tối ưu: $(1,2)$ và $(3,4)$. Khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n)$ — mỗi đỉnh $u$ xử lý $O(\deg(u))$ (dựng $Left$ và duyệt $Right$), tổng đúng $O(n)$.
- **Bộ nhớ:** $O(n)$ — danh sách kề, mảng `lab` và bảng $dp$ hai trạng thái, mảng $Left$ tạm trong DFS.

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Matching.cpp)
