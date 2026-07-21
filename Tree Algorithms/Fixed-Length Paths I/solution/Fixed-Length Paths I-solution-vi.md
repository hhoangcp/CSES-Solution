# Fixed-Length Paths I - Lời giải

**ID:** 2080 | **URL:** https://cses.fi/problemset/task/2080

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh. Đếm số đường đi đơn có độ dài đúng bằng $k$ cạnh.

**Ràng buộc:** $1 \le k \le n \le 2 \cdot 10^5$.

### Ý tưởng chính

Dùng **phân tách trọng tâm (Centroid Decomposition)**: tại mỗi bước tìm trọng tâm $c$ của thành phần hiện tại, đếm các đường đi độ dài $k$ đi qua $c$, rồi đệ quy trên các thành phần sau khi loại $c$. Mọi đường đi đều thuộc đúng một trong hai loại — đi qua trọng tâm $c$ của bước hiện tại, hoặc nằm trọn trong một thành phần sau khi loại $c$ (loại sau được giải ở đệ quy). Vậy chỉ cần đếm đúng loại đầu để không trùng/lạc.

Một đường đi qua $c$ tách thành hai đoạn $u \to c$ (độ dài $d_1$) và $c \to v$ (độ dài $d_2$) với $d_1 + d_2 = k$, và $u, v$ phải ở **hai cây con khác nhau** của $c$ (hoặc một đầu là chính $c$). Để đếm không trùng, duyệt lần lượt từng cây con của $c$ với mảng `cnt[d]` = số đỉnh ở độ sâu $d$ từ $c$ thuộc các cây con **đã xử lý**; với mỗi cây con mới, trước khi đưa vào `cnt` ta **truy vấn** rồi mới **cập nhật**:

- Truy vấn: với mỗi đỉnh ở độ sâu $d \le k$ trong cây con, cộng `cnt[k - d]` vào đáp án.
- Cập nhật: tăng `cnt[d]` cho các đỉnh ở độ sâu $d$ trong cây con.

Khởi tạo `cnt[0] = 1` (chính $c$ ở độ sâu $0$), nên đường đi có một đầu là $c$ được tính qua `cnt[k - d] = cnt[0]`.

**Tính đúng đắn:** Mỗi đường đi có duy nhất một trọng tâm $c$ nằm trên nó — trọng tâm ở mức phân tách cao nhất mà thành phần chứa nó còn bao trọn đường đi. Tại mức đó $c$ nằm trên đường đi nên được đếm; ở các mức sâu hơn đường đi bị cắt khi loại $c$ nên không được đếm lại. Với đường đi $u \to v$ qua $c$ ($u, v$ ở hai cây con khác nhau), khi xử lý cây con chứa $v$, `cnt` đã chứa đóng góp của cây con chứa $u$ (xử lý trước), nên `cnt[k - d(v,c)] = cnt[d(u,c)] \ge 1` và đường đi được cộng đúng một lần. Thứ tự "truy vấn trước, cập nhật sau" đảm bảo hai đầu luôn ở cây con khác nhau, không đếm trùng.

### Thuật toán

1. Đọc $n, k$; dựng danh sách kề. Khởi tạo `cnt[0] = 1`, đánh dấu mảng `cnode[]` (đỉnh đã bị loại).
2. `DFS_sz(u, par)`: tính `subtree_sz[u]` (chỉ đếm đỉnh chưa bị loại `!cnode[v]`).
3. `Find_Centroid(sz, u, par)`: đi xuống con $v$ có `subtree_sz[v] * 2 > sz`, trả về đỉnh dừng.
4. `Get_cnt(u, par, add, depth=1)`: dừng khi `depth > k`.
   - `add = false` (truy vấn): `ans += cnt[k - depth]`.
   - `add = true` (cập nhật): `++cnt[depth]`.
   - Cập nhật `max_depth = max(max_depth, depth)`, rồi đệ quy vào các con chưa bị loại.
5. `Centroid_Decomposition(u = 1)`:
   - `centroid = Find_Centroid(DFS_sz(u, 0), u, 0)`, đánh dấu `cnode[centroid] = true`.
   - `max_depth = 0`. Với mỗi con $v$ của `centroid` chưa bị loại: gọi `Get_cnt(v, centroid, false)` rồi `Get_cnt(v, centroid, true)`.
   - Xóa `cnt` từ `max_depth` xuống $1$ (tránh reset cả mảng), rồi đệ quy `Centroid_Decomposition(v)` cho từng con chưa bị loại.
6. In `ans`.

### Ví dụ minh họa

Đề bài cho $n = 5$, $k = 2$, cạnh `1-2, 2-3, 3-4, 3-5`. Cây là đường $1-2-3$ rẽ nhánh tại $3$ sang $4, 5$.

Trọng tâm đầu tiên là $c = 3$. `cnt[0] = 1` (chính đỉnh $3$).

| Cây con (qua con của $3$) | Đỉnh (độ sâu) | Truy vấn `ans += cnt[k-d]` | Cập nhật `cnt` |
|---|---|---|---|
| qua $2$ | $2(d{=}1)$, $1(d{=}2)$ | $d{=}1$: `cnt[1]=0`; $d{=}2$: `cnt[0]=1` $\Rightarrow$ `ans=1` (đường $1\leftrightarrow 3$: $1-2-3$) | `cnt[1]+=1`, `cnt[2]+=1` |
| qua $4$ | $4(d{=}1)$ | $d{=}1$: `cnt[1]=1` $\Rightarrow$ `ans=2` (đường $4\leftrightarrow 2$: $4-3-2$) | `cnt[1]+=1` |
| qua $5$ | $5(d{=}1)$ | $d{=}1$: `cnt[1]=2` $\Rightarrow$ `ans=4` (đường $5\leftrightarrow 2$: $5-3-2$ và $5\leftrightarrow 4$: $5-3-4$) | `cnt[1]+=1` |

Sau `cnt`: `cnt[0]=1, cnt[1]=3, cnt[2]=1`. Tổng qua trọng tâm $3$ là $4$.

Đệ quy vào các thành phần sau khi loại $3$: $\{1,2\}$ (khoảng cách duy nhất là $1$), và $\{4\}, \{5\}$ (đỉnh đơn) — không đóng góp thêm đường đi độ dài $2$.

Kết quả: `4` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — phân tách trọng tâm có chiều cao $O(\log n)$; mỗi đỉnh xuất hiện trong $O(\log n)$ mức và mỗi mức được DFS đúng một lần, mỗi thao tác `cnt` $O(1)$.
- **Bộ nhớ:** $O(n)$ — danh sách kề và các mảng `subtree_sz`, `cnt`, `cnode`.

## Mã nguồn (C++)

[Mã nguồn](../code/Fixed-Length%20Paths%20I.cpp)
