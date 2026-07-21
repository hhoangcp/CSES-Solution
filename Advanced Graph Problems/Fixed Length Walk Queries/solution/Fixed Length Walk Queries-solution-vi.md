# Fixed Length Walk Queries - Lời giải

**ID:** 3357 | **URL:** https://cses.fi/problemset/task/3357

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng liên thông $n$ đỉnh, $m$ cạnh. Trả lời $q$ truy vấn: có thể đi từ đỉnh $a$ đến đỉnh $b$ trong đúng $x$ bước không?

### Ý tưởng chính

Vì đồ thị liên thông và $n \geq 2$, mọi đỉnh đều có ít nhất một hàng xóm, cho phép kéo dài bất kỳ đường đi nào thêm 2 bước bằng cách đi tới hàng xóm rồi quay lại. Do đó, đi được độ dài $x$ iff tồn tại đường đi ngắn nhất cùng tính chẵn lẻ với $x$ và có độ dài $\leq x$.

### Thuật toán

1. Với mỗi đỉnh nguồn $s$, chạy BFS theo dõi cả đỉnh hiện tại và tính chẵn lẻ:
   - Trạng thái: $(v, p)$ với $v$ là đỉnh, $p \in \{0, 1\}$ là tính chẵn lẻ số bước.
   - Từ $(v, p)$, đi qua cạnh dẫn đến $(u, 1-p)$.
2. Lưu `dist[s][v][0]` = đường đi chẵn ngắn nhất từ $s$ đến $v$, `dist[s][v][1]` = đường đi lẻ ngắn nhất.
3. Với mỗi truy vấn $(a, b, x)$: $p = x \bmod 2$. Trả lời YES nếu `dist[a][b][p] != -1` và `dist[a][b][p] <= x`.

### Ví dụ minh họa

Truy vấn: $a=1, b=4, x=5$. Tính chẵn lẻ = 1. Nếu đường đi lẻ ngắn nhất từ 1 đến 4 là 3, vì $3 \leq 5$, đi $1\to2\to3\to4$ rồi dùng 2 bước còn lại $4\to3\to4$. Kết quả: YES.

Truy vấn: $a=1, b=4, x=1$. `dist[1][4][1] = 3 > 1`, kết quả: NO.

## Độ phức tạp

- **Thời gian:** $O(n \cdot (n + m))$ tiền xử lý, $O(1)$ mỗi truy vấn.
- **Không gian:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Fixed%20Length%20Walk%20Queries.cpp)
