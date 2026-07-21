# Fixed-Length Paths II - Lời giải

**ID:** 2081 | **URL:** https://cses.fi/problemset/task/2081

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh. Đếm số đường đi đơn có độ dài (số cạnh) nằm trong đoạn $[k_1, k_2]$.

**Ràng buộc:** $1 \le k_1 \le k_2 \le n \le 2 \cdot 10^5$.

### Ý tưởng chính

Dùng DFS hậu thứ tự kết hợp **gộp deque** và **kỹ thuật nhỏ vào lớn (Small-to-Large)**. Với mỗi đỉnh $u$, DFS trả về một `deque<int> res` lưu **tổng hậu tố (suffix sum)** theo độ sâu: $res[i]$ = số đỉnh trong cây con $u$ ở độ sâu $\ge i$ tính từ $u$ (với $res[0]$ = tổng số đỉnh, $u$ ở độ sâu $0$). Khởi tạo $res = \{1\}$.

Nhờ lưu suffix sum, tổng số đỉnh ở độ sâu $\le t$ được tính $O(1)$:

$$\text{Prefix}(res, t) = \begin{cases} 0 & t < 0 \\ res[0] & t+1 \ge |res| \\ res[0] - res[t+1] & \text{otherwise} \end{cases}$$

và số đỉnh ở đúng độ sâu $i$ là $res[i] - res[i+1]$ (qui ước $res[|res|]=0$).

Khi xử lý con $v$ của $u$: lấy $up = \text{DFS}(v)$, rồi `up.push_front(up.front())` để dịch mọi độ sâu thêm $1$ (thêm cạnh $v \to u$); phần tử mới ở vị trí $0$ đúng bằng tổng số đỉnh trong cây con $v$, nên suffix sum không đổi. Sau đó đếm và gộp:

- **Đếm:** chuyển $up$ từ suffix sum sang số lượng đúng tại mỗi độ sâu ($up[i] \mathrel{-}= up[i+1]$). Với mỗi độ sâu $i$, số đường đi hợp lệ ghép từ đỉnh ở độ sâu $i$ (qua $v$) với đỉnh ở độ sâu $[k_1-i,\ k_2-i]$ trong các cây con đã xử lý (tức trong $res$) là:

$$ans \mathrel{+}= up[i] \times \bigl(\text{Prefix}(res,\ k_2 - i) - \text{Prefix}(res,\ k_1 - i - 1)\bigr)$$

- **Gộp:** chuyển $up$ trở lại suffix sum ($up[i] \mathrel{+}= up[i+1]$), rồi nếu $|up| > |res|$ thì `swap(res, up)` (nhỏ vào lớn), cuối cùng $res[i] \mathrel{+}= up[i]$.

**Tính đúng đắn:** Mỗi cặp đỉnh $(p, q)$ có LCA là $u$ được đếm đúng một lần: các cặp có cả hai đầu trong cùng một cây con của $u$ được đếm trong lời gọi `DFS(v)` đệ quy (LCA của chúng thấp hơn); các cặp có hai đầu ở hai cây con khác nhau (hoặc một đầu là chính $u$) được đếm khi gộp cây con chứa $q$ — khi đó $res$ đã chứa cây con chứa $p$ và chính $u$ (ở độ sâu $0$). Thứ tự "truy vấn trước, cập nhật sau" đảm bảo hai đầu luôn ở hai cây con khác nhau, không đếm trùng. Phép `push_front` đúng vì nó chỉ chèn thêm bậc độ sâu $0$ (chính $v$, một đỉnh) trong khi mọi độ sâu cũ tăng $1$; tổng hậu tố giữ nguyên do phần tử mới bằng $up[0]$ cũ.

### Thuật toán

1. Đọc $n, k_1, k_2$; dựng danh sách kề; mảng `lab` lưu cha để không đi ngược.
2. `Prefix(p, t)`: trả về $0$ nếu $t<0$; $p[0]$ nếu $t+1 \ge |p|$; ngược lại $p[0] - p[t+1]$.
3. `Merging(res, up)`:
   - Nếu $|res| < |up|$, `swap(res, up)`.
   - For $i = 0 \dots |up|-2$: $up[i] \mathrel{-}= up[i+1]$ (chuyển sang số lượng đúng độ sâu).
   - For $i = 0 \dots |up|-1$: $ans \mathrel{+}= up[i] \cdot (\text{Prefix}(res, k_2 - i) - \text{Prefix}(res, k_1 - i - 1))$.
   - For $i = |up|-2 \dots 0$: $up[i] \mathrel{+}= up[i+1]$ (chuyển về suffix sum).
   - For $i = 0 \dots |up|-1$: $res[i] \mathrel{+}= up[i]$.
4. `DFS(u)`:
   - $res = \{1\}$.
   - Với mỗi $v \in V[u]$, nếu $lab[u] \ne v$: $lab[v] = u$; $up = \text{DFS}(v)$; `up.push_front(up.front())`; `Merging(res, up)`.
   - Trả về $res$.
5. Gọi `DFS(1)`, in `ans`.

### Ví dụ minh họa

Đề bài cho $n = 5$, $k_1 = 2$, $k_2 = 3$, cạnh `1-2, 2-3, 3-4, 3-5`. Cây là đường $1-2-3$ rẽ nhánh tại $3$ sang $4, 5$.

Các deque lưu suffix sum ($res[i]$ = số đỉnh ở độ sâu $\ge i$ tính từ gốc của deque). Bảng trace theo code:

> **Lưu ý về thứ tự `swap`:** Bảng dưới đây minh họa công thức đếm dùng `res` **trước khi `swap`** (deque đang tích lũy, nhỏ hơn) và `up` **sau `push_front`** (deque sắp gộp, lớn hơn) — tức đếm "mỗi độ sâu $i$ trong `up` ghép với khoảng độ sâu $[k_1-i,\ k_2-i]$ trong `res`". Trong code, `Merging` thực hiện `swap(res, up)` **trước** khi đếm nên `up` trở thành deque nhỏ hơn và `res` trở thành deque lớn hơn; công thức đếm khi đó quay ngược lại: "mỗi độ sâu $i$ trong `up` (nhỏ) ghép với khoảng $[k_1-i,\ k_2-i]$ trong `res` (lớn)". Hai cách cho **cùng kết quả** nhờ tính đối xứng của phép đếm cặp (mỗi cặp $(p,q)$ được đếm một lần dù tính từ phía nào). Các cột `res trước` / `res sau` trong bảng áp dụng cho deque mang tên `res` ngay trước/sau bước `Merging` hoàn chỉnh (sau khi `swap` và cộng gộp).

| Bước | `res` trước | `up` (sau `push_front`) | Đếm `ans +=` | `res` sau |
|---|---|---|---|---|
| `DFS(4)` | — | — | — | $\{1\}$ |
| `DFS(5)` | — | — | — | $\{1\}$ |
| `DFS(3)`, gộp con $4$ | $\{1\}$ | $\{1,1\}$ | $0 \cdot (\text{Pref}(\{1\},3)-\text{Pref}(\{1\},1)) + 1 \cdot (\text{Pref}(\{1\},2)-\text{Pref}(\{1\},0)) = 0$ | $\{2,1\}$ |
| `DFS(3)`, gộp con $5$ | $\{2,1\}$ | $\{1,1\}$ | $0 \cdot \ldots + 1 \cdot (\text{Pref}(\{2,1\},2)-\text{Pref}(\{2,1\},0)) = 1$ (đường $5\leftrightarrow4$) | $\{3,2\}$ |
| `DFS(2)`, gộp con $3$ | $\{1\}$ | $\{3,3,2\}$ | $1 \cdot (\text{Pref}(\{3,3,2\},3)-\text{Pref}(\{3,3,2\},1)) = 2$ (đường $2\leftrightarrow4,\ 2\leftrightarrow5$) | $\{4,3,2\}$ |
| `DFS(1)`, gộp con $2$ | $\{1\}$ | $\{4,4,3,2\}$ | $1 \cdot (\text{Pref}(\{4,4,3,2\},3)-\text{Pref}(\{4,4,3,2\},1)) = 3$ (đường $1\leftrightarrow3,\ 1\leftrightarrow4,\ 1\leftrightarrow5$) | $\{5,4,3,2\}$ |

Tổng $ans = 0 + 1 + 2 + 3 = 6$. (Lưu ý: tại `DFS(3)` gộp con $4$, độ sâu $i=1$ ghép với độ sâu $[k_1-1, k_2-1]=[1,2]$ trong $res=\{1\}$ chỉ chứa đỉnh $3$ ở độ sâu $0$, không có đỉnh độ sâu $1$ hay $2$, nên đóng góp $0$ — đường $4\leftrightarrow3$ dài $1$ nằm ngoài $[2,3]$.)

Kết quả: `6` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — nhờ nhỏ vào lớn, mỗi lần một deque bị "đổ" vào deque lớn hơn thì kích thước chứa nó ít nhất nhân đôi, nên mỗi đỉnh bị copy tối đa $O(\log n)$ lần.
- **Bộ nhớ:** $O(n)$ — tại mỗi thời điểm chỉ có các deque trên đường DFS đang hoạt động.

## Mã nguồn (C++)

[Mã nguồn](../code/Fixed-Length%20Paths%20II.cpp)
