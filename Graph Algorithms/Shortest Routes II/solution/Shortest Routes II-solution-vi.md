# Tuyến Đường Ngắn Nhất II - Lời giải

**ID:** 1672 | **URL:** https://cses.fi/problemset/task/1672

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị vô hướng có trọng số không âm với $n$ đỉnh ($n \le 500$) và $m$ cạnh, xử lý $q$ truy vấn mỗi truy vấn hỏi khoảng cách ngắn nhất giữa hai đỉnh. Nếu không tồn tại đường đi, xuất $-1$.

### Ý tưởng chính

Với $n \le 500$, dùng thuật toán **Floyd-Warshall** tính khoảng cách ngắn nhất giữa mọi cặp đỉnh trong $O(n^3)$ tiền xử lý, sau đó trả lời mỗi truy vấn trong $O(1)$.

Khởi tạo ma trận khoảng cách `floyd[i][j]`: `floyd[i][i] = 0`, `floyd[i][j] =` trọng số cạnh trực tiếp (lấy nhỏ nhất nếu có nhiều cạnh), và `floyd[i][j] = +\infty` nếu không có cạnh. Sau đó duyệt từng đỉnh trung gian $k$ từ $1$ đến $n$, cập nhật mọi cặp:

$$\text{floyd}[i][j] = \min(\text{floyd}[i][j],  \text{floyd}[i][k] + \text{floyd}[k][j])$$

Vòng lặp trung gian $k$ phải nằm ngoài cùng. Sau khi xử lý hết $k$, `floyd[i][j]` chứa khoảng cách ngắn nhất giữa mọi cặp đỉnh.

**Tính đúng đắn.** Sau bước $k$, `floyd[i][j]` bằng khoảng cách ngắn nhất từ $i$ đến $j$ chỉ đi qua các đỉnh trung gian trong tập $\{1, 2, \ldots, k\}$. Chứng minh quy nạp: tại bước $k$, đường đi ngắn nhất hoặc không qua đỉnh $k$ (giá trị giữ nguyên), hoặc qua $k$, khi đó chia thành $i \leadsto k$ và $k \leadsto j$ — mỗi phần chỉ dùng trung gian trong $\{1, \ldots, k-1\}$ nên đã được tính đúng ở bước trước. Sau bước $n$, mọi đỉnh đều được phép làm trung gian, ta có khoảng cách ngắn nhất thực sự.

### Thuật toán

1. Khởi tạo: `floyd[i][i] = 0`, `floyd[i][j] = +\infty` với $i \neq j$. Với mỗi cạnh $(u, v, c)$: `floyd[u][v] = floyd[v][u] = min(floyd[u][v], c)`.
2. Cho $k = 1$ đến $n$: cho $i = 1$ đến $n$: cho $j = 1$ đến $n$: `floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j])`.
3. Với mỗi truy vấn $(a, b)$: nếu `floyd[a][b] = +\infty`, xuất $-1$; ngược lại xuất `floyd[a][b]`.

### Ví dụ minh họa

Input:
```
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
```

Ma trận ban đầu (các ô khác $\infty$): $f[1][2] = f[2][1] = 5$, $f[1][3] = f[3][1] = 9$, $f[2][3] = f[3][2] = 3$.

- $k = 1$: không có cập nhật (đỉnh 1 không tạo đường tắt).
- $k = 2$: $f[1][3] = \min(9, 5 + 3) = 8$, $f[3][1] = \min(9, 3 + 5) = 8$.
- $k = 3$: không cải thiện (ví dụ $f[1][2] = \min(5, 8 + 3) = 5$).
- $k = 4$: đỉnh 4 cô lập, không cập nhật.

Các truy vấn:
- $1 \to 2$: $5$
- $2 \to 1$: $5$
- $1 \to 3$: $8$
- $1 \to 4$: $\infty$ → $-1$
- $3 \to 2$: $3$

Kết quả:
```
5
5
8
-1
3
```

## Độ phức tạp

- **Thời gian:** $O(n^3 + q)$ — tiền xử lý Floyd-Warshall cộng $O(1)$ mỗi truy vấn.
- **Bộ nhớ:** $O(n^2)$ — ma trận khoảng cách.

## Mã nguồn (C++)

[Mã nguồn](../code/Shortest%20Routes%20II.cpp)
