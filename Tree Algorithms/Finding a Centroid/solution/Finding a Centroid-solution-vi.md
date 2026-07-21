# Finding a Centroid - Lời giải

**ID:** 2079 | **URL:** https://cses.fi/problemset/task/2079

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh. Tìm một *trọng tâm* (centroid), tức là một đỉnh $c$ sao cho khi chọn $c$ làm gốc, mỗi cây con thu được có không quá $\lfloor n/2 \rfloor$ đỉnh.

**Ràng buộc:** $1 \le n \le 2 \cdot 10^5$.

### Ý tưởng chính

Trọng tâm của cây là đỉnh $c$ sao cho khi loại $c$, mọi thành phần liên thông còn lại có $\le \lfloor n/2 \rfloor$ đỉnh — tương đương khi $c$ là gốc thì mọi cây con có kích thước $\le \lfloor n/2 \rfloor$.

Hai bước:

1. **Tính kích thước cây con:** DFS từ đỉnh $1$ (lưu cha `lab[v] = u` để tránh đi ngược lên), tính $sz[u]$ = số đỉnh trong cây con gốc $u$: $sz[u] = 1 + \sum_{v \in \text{con}(u)} sz[v]$.
2. **Đi theo con nặng:** Xuất phát từ đỉnh $1$, tại mỗi đỉnh $u$ nếu tồn tại con $v$ (không phải cha) có $sz[v] \cdot 2 > n$ thì nhảy xuống $v$; nếu không có con nào thỏa, $u$ chính là trọng tâm.

**Tính đúng đắn:** Tại mỗi bước có tối đa một con có $sz > n/2$, vì nếu có hai con $v_1, v_2$ đều $> n/2$ thì $sz[v_1] + sz[v_2] > n$, trái với tổng số đỉnh chỉ là $n$ (các cây con rời nhau). Nên hướng đi xuống là duy nhất. Quá trình đi xuống dừng chắc chắn: mỗi bước ta nhảy vào một cây con có kích thước $> n/2$ nhỏ hơn kích thước cây con hiện tại, kích thước giảm nghiêm ngặt trên cây hữu hạn. Khi dừng, mọi con đều có $sz \le n/2$; phần phía cha (nếu có) có kích thước $n - sz[u] \le n/2$ (vì ta vừa đi tới từ phía cha, nghĩa là $sz[u] > n/2$ tại bước trước nên $n - sz[u] < n/2$). Vậy $u$ là trọng tâm.

### Thuật toán

1. Đọc $n$; dựng danh sách kề từ $n-1$ cạnh.
2. `DFS(1)` với `lab` ban đầu $0$:
   - $sz[u] = 1$.
   - Với mỗi $v \in V[u]$, nếu $lab[u] \ne v$: đặt $lab[v] = u$, gọi `DFS(v)`, rồi $sz[u] \mathrel{+}= sz[v]$.
3. `Find_Centroid(u)`:
   - Với mỗi $v \in V[u]$, nếu $lab[u] \ne v$ và $sz[v] \cdot 2 > n$, trả về `Find_Centroid(v)`.
   - Nếu không có con nào thỏa, trả về $u$.
4. In kết quả `Find_Centroid(1)`.

### Ví dụ minh họa

Đề bài cho $n = 5$, cạnh `1-2, 2-3, 3-4, 3-5`. Cây là một đường $1-2-3$ rẽ nhánh tại $3$ sang $4, 5$.

DFS từ đỉnh $1$ (cha `lab` ghi trong ngoặc):

| $u$ | $sz[u]$ | Con |
|---|---|---|
| $4$ | $1$ | — |
| $5$ | $1$ | — |
| $3$ | $3$ | $4, 5$ |
| $2$ | $4$ | $3$ |
| $1$ | $5$ | $2$ |

Tìm trọng tâm (ngưỡng $\lfloor n/2 \rfloor = 2$, kiểm tra $sz[v] \cdot 2 > 5$):

- `Find_Centroid(1)`: con $2$ có $sz[2] \cdot 2 = 8 > 5$ $\to$ đi xuống $2$.
- `Find_Centroid(2)`: con $3$ có $sz[3] \cdot 2 = 6 > 5$ $\to$ đi xuống $3$.
- `Find_Centroid(3)`: con $4$ có $sz[4] \cdot 2 = 2 \le 5$, con $5$ có $sz[5] \cdot 2 = 2 \le 5$ $\to$ trả về $3$.

Kết quả: `3` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n)$ — DFS tính $sz$ mất $O(n)$; tìm trọng tâm đi theo một đường duy nhất, mỗi đỉnh thăm tối đa một lần.
- **Bộ nhớ:** $O(n)$ — danh sách kề và các mảng $sz$, $lab$.

## Mã nguồn (C++)

[Mã nguồn](../code/Finding%20a%20Centroid.cpp)
