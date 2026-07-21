# Tree Diameter - Lời giải

**ID:** 1131 | **URL:** https://cses.fi/problemset/task/1131

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh. *Đường kính* của cây là khoảng cách lớn nhất giữa hai đỉnh bất kỳ. Tính đường kính.

**Ràng buộc:** $1 \le n \le 2 \cdot 10^5$.

### Ý tưởng chính

Dùng thuật toán **hai lần DFS**:

1. DFS lần 1 từ một đỉnh bất kỳ (chọn đỉnh $1$), tính $depth[u]$ và theo dõi đỉnh $s$ có $depth$ lớn nhất — tức đỉnh xa $1$ nhất.
2. DFS lần 2 từ $s$, tính lại $depth[u]$ và theo dõi đỉnh $t$ xa $s$ nhất. Khi đó $depth[t]$ chính là đường kính.

Mỗi DFS dùng `lab[v] = u` để không quay lên cha, $depth[v] = depth[u] + 1$, và cập nhật `(ans, s)` khi gặp $depth[v]$ lớn hơn.

**Tính đúng đắn:** Gọi $a \to b$ là một đường kính (độ dài $D$). Với $x$ là đỉnh bắt đầu và $s$ là đỉnh xa $x$ nhất, ta chứng minh $s$ là một đầu mút của một đường kính. Gọi $c$ là điểm phân nhánh nơi đường $x \to a$ và $x \to b$ tách nhau, và $p$ là điểm đường $s \to x$ gặp đường $a \to b$. Vì $s$ xa $x$ nhất nên $d(x, s) \ge d(x, a)$ và $d(x, s) \ge d(x, b)$. Nếu $s$ nằm phía nhánh của $a$ (trường hợp đối xứng cho phía $b$), thì $d(s, b) = d(s, p) + d(p, c) + d(c, b) \ge d(a, p) + d(p, c) + d(c, b) \ge d(a, b) = D$ (vì $d(s,p) \ge d(a,p)$ do $s$ xa $x$ hơn $a$). Mà $D$ là đường kính (giá trị lớn nhất có thể), nên $d(s, b) = D$, vậy $s$ là đầu mút của đường kính $s \to b$. Hệ quả: từ đầu mút $s$, khoảng cách xa nhất chính là đường kính $D$, nên DFS thứ hai từ $s$ cho ra $D$.

### Thuật toán

1. Đọc $n$; dựng danh sách kề từ $n-1$ cạnh.
2. Khởi tạo `depth`, `lab` toàn $0$; `ans = 0`, `s = 0`.
3. `DFS(u)`: với mỗi $v \in V[u]$ mà $lab[u] \ne v$: đặt $lab[v] = u$, $depth[v] = depth[u] + 1$, gọi `DFS(v)`; nếu $ans < depth[v]$ thì $ans = depth[v]$, $s = v$.
4. Gọi `DFS(1)`.
5. Đặt lại `depth[u] = lab[u] = 0` cho mọi $u$ (giữ nguyên `ans` không cần reset vì lần 2 sẽ cho kết quả lớn hơn).
6. Gọi `DFS(s)`.
7. In `ans`.

### Ví dụ minh họa

Đề bài cho $n = 5$, cạnh `1-2, 1-3, 3-4, 3-5`. Cây: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

**DFS lần 1 (từ đỉnh $1$)** — tính $depth$:

| $u$ | $1$ | $2$ | $3$ | $4$ | $5$ |
|---|---|---|---|---|---|
| $depth[u]$ | $0$ | $1$ | $1$ | $2$ | $2$ |

Đỉnh xa nhất: $depth_{\max} = 2$, chọn $s = 4$ (đỉnh $5$ cũng xa tương đương).

**DFS lần 2 (từ đỉnh $s = 4$)** — tính lại $depth$:

| $u$ | $1$ | $2$ | $3$ | $4$ | $5$ |
|---|---|---|---|---|---|
| $depth[u]$ | $2$ | $3$ | $1$ | $0$ | $2$ |

Đỉnh xa nhất từ $4$ là $2$ với $depth = 3$. Đường kính là đường $2 \to 1 \to 3 \to 4$ (hoặc $2 \to 1 \to 3 \to 5$), độ dài $3$.

Kết quả: `3` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n)$ — hai lần DFS, mỗi lần thăm hết các đỉnh và cạnh đúng một lần.
- **Bộ nhớ:** $O(n)$ — danh sách kề và các mảng $depth$, $lab$.

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Diameter.cpp)
