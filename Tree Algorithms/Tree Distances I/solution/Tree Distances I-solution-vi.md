# Tree Distances I - Lời giải

**ID:** 1132 | **URL:** https://cses.fi/problemset/task/1132

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh. Tính với mỗi đỉnh khoảng cách lớn nhất từ nó đến một đỉnh khác bất kỳ.

**Ràng buộc:** $1 \le n \le 2 \cdot 10^5$.

### Ý tưởng chính

Bài toán quy hoạch động chuyển gốc (rerooting DP) qua hai lần DFS. Khoảng cách lớn nhất từ $u$ đi theo hai hướng: **xuống** các cây con của $u$, hoặc **lên** qua cha rồi có thể rẽ xuống nhánh khác hoặc tiếp tục đi lên.

**DFS lần 1 (tính khoảng cách đi xuống):** Chọn đỉnh $1$ làm gốc tạm. Với mỗi $u$, tính $dp[u]$ = khoảng cách lớn nhất từ $u$ đến một đỉnh trong cây con gốc $u$:

$$dp[u] = \max_{v \in \text{con}(u)} (dp[v] + 1) \quad (\text{lá: } dp[u] = 0)$$

**DFS lần 2 (chuyển gốc):** Khi duyệt $u$, trước tiên $ans[u] = dp[u]$ (đây là kết quả cho $u$ khi $u$ đang là "gốc" của phần đã xét). Để chuyển gốc từ $u$ sang con $v$, ta tạm loại đóng góp của $v$ khỏi $dp[u]$ được $dp'[u]$, rồi gán $dp[v] = \max(dp[v],\ dp'[u] + 1)$ để đưa hướng "lên qua $u$" vào $v$, sau đó đệ quy `Rotate(v)`. Trở về ta khôi phục $dp[u], dp[v]$.

Để tính $dp'[u]$ trong $O(1)$ khi bỏ con thứ $i$ (kề cả cha, vì cha cũng xuất hiện trong $V[u]$ với $dp$ đã được chuyển gốc phản ánh hướng lên), dựng mảng tiền tố max trên danh sách con của $u$:

$$Left[i] = \max_{j \le i}(dp[V[u][j]] + 1)$$

và duyệt các con từ phải sang trái để duy trì $Right$ = max của $dp[w]+1$ với các con bên phải $i$. Khi đó:

$$dp'[u] = \max(Left[i-1],\ Right)$$

**Tính đúng đắn (quy nạp theo DFS chuyển gốc):** Tại gốc $1$, $dp[1]$ đúng vì mọi đỉnh đều nằm trong cây con $1$. Giả sử khi `Rotate(u)` được gọi, $dp[u]$ đã đúng bằng khoảng cách lớn nhất từ $u$ tới mọi đỉnh trong cây (bao gồm hướng lên cha, do bước chuyển gốc của cha đã cập nhật $dp[u] \mathrel{+}= dp'[\text{cha}]+1$). Khi chuyển gốc sang con $v$, $dp'[u]$ lấy max trên mọi hướng đi xuống từ $u$ trừ hướng $v$ — nhưng hướng "lên qua cha của $u$" vẫn còn (nó nằm trong $dp[\text{cha}]+1$ được tính vào $Left/Right$). Do đó $dp[v] = \max(dp[v], dp'[u]+1)$ đưa đúng hướng lên qua $u$ vào $v$, và `ans[v] = dp[v]` ghi nhận kết quả đúng của $v$ trước khi đi sâu hơn.

### Thuật toán

1. Đọc $n$; dựng danh sách kề từ $n-1$ cạnh.
2. `DFS(u)` (dùng `lab` để không quay lên cha): $dp[u] = 0$; với mỗi con $v$ (`lab[u] != v`): $lab[v] = u$, `DFS(v)`, $dp[u] = \max(dp[u], dp[v] + 1)$.
3. `Rotate(u)`:
   - $ans[u] = dp[u]$.
   - Dựng $Left[i] = \max(Left[i-1],\ dp[V[u][i]] + 1)$ trên $V[u]$.
   - $Right = 0$. Duyệt $i$ từ $|V[u]|-1$ xuống $0$, với $v = V[u][i]$:
     - Nếu $lab[u] \ne v$: lưu $tmp_u = dp[u], tmp_v = dp[v]$; gán $dp[u] = \max(Left[i-1], Right)$ (hoặc $Right$ nếu $i=0$); $dp[v] = \max(dp[v], dp[u]+1)$; gọi `Rotate(v)`; khôi phục $dp[u] = tmp_u, dp[v] = tmp_v$.
     - $Right = \max(Right, dp[v] + 1)$.
4. Gọi `DFS(1)`, rồi `Rotate(1)`; in $ans[1..n]$.

### Ví dụ minh họa

Đề bài cho $n = 5$, cạnh `1-2, 1-3, 3-4, 3-5`. Cây: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

**DFS lần 1 (gốc $1$)** — khoảng cách đi xuống $dp$:

| $u$ | $1$ | $2$ | $3$ | $4$ | $5$ |
|---|---|---|---|---|---|
| $dp[u]$ | $2$ | $0$ | $1$ | $0$ | $0$ |

**DFS lần 2 (chuyển gốc)** — ghi $ans[u] = dp[u]$ tại lượt vào mỗi $u$:

| Bước | Đang ở | $dp'$ tạm | Cập nhật | $ans$ |
|---|---|---|---|---|
| vào $1$ | — | — | $ans[1] = dp[1] = 2$ | $ans[1]=2$ |
| $1 \to 3$ | bỏ con $3$ khỏi $dp[1]$: $dp'[1] = dp[2]+1 = 1$ | $dp'[1]=1$ | $dp[3] = \max(1,\ 1+1) = 2$ | $ans[3]=2$ |
| $3 \to 5$ | bỏ con $5$ khỏi $dp[3]$: $dp'[3] = \max(dp[1]+1,\ dp[4]+1) = \max(2, 1) = 2$ | $dp'[3]=2$ | $dp[5] = \max(0,\ 2+1) = 3$ | $ans[5]=3$ |
| $3 \to 4$ | bỏ con $4$ khỏi $dp[3]$: $dp'[3] = \max(dp[1]+1,\ dp[5]+1) = \max(2, 1) = 2$ | $dp'[3]=2$ | $dp[4] = \max(0,\ 2+1) = 3$ | $ans[4]=3$ |
| $1 \to 2$ | bỏ con $2$ khỏi $dp[1]$: $dp'[1] = dp[3]+1 = 2$ | $dp'[1]=2$ | $dp[2] = \max(0,\ 2+1) = 3$ | $ans[2]=3$ |

(Lưu ý: tại $3$, $V[3]=[1,4,5]$ gồm cả cha $1$; $dp[1]$ lúc này đã được chuyển gốc thành $1$, nên $dp[1]+1 = 2$ chính là hướng "lên qua cha" của $3$.)

Kết quả theo thứ tự đỉnh $1..5$: `2 3 2 3 3` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n)$ — hai lần DFS; tại mỗi $u$, việc dựng $Left/Right$ và duyệt các con tốn tỉ lệ với $|V[u]|$, tổng đúng $O(n)$.
- **Bộ nhớ:** $O(n)$ — danh sách kề, các mảng $dp$, $ans$, $lab$ và mảng $Left$ tạm trong `Rotate`.

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Distances%20I.cpp)
