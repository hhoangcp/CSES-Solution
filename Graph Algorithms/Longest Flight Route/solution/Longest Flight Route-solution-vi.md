# Tuyến Bay Dài Nhất - Lời giải

**ID:** 1680 | **URL:** https://cses.fi/problemset/task/1680

## Phương pháp

### Tóm tắt bài toán

Cho DAG $n$ đỉnh và $m$ cạnh có hướng, tìm đường đi dài nhất (theo số đỉnh) từ đỉnh 1 đến đỉnh $n$, hoặc in "IMPOSSIBLE" nếu không tồn tại đường đi.

### Ý tưởng chính

Vì đồ thị là DAG, bài toán đường đi dài nhất — vốn NP-hard trên đồ thị tổng quát — có thể giải bằng quy hoạch động. Định nghĩa $dp[u]$ là số đỉnh tối đa trên đường đi từ $u$ đến $n$:

$$dp[u] = \max_{(u,v) \in E}(dp[v] + 1), \quad dp[n] = 1$$

Nếu $u$ không thể đến $n$, $dp[u] = -\infty$. Công thức đúng vì mọi đường đi từ $u$ đến $n$ bắt đầu bằng cạnh $(u, v)$ rồi tiếp tục tối ưu từ $v$; lấy max trên tất cả $v$ cho đường đi dài nhất. Vì DAG không có chu trình, ghi nhớ bằng DFS an toàn — mỗi trạng thái chỉ phụ thuộc các trạng thái gần $n$ hơn theo thứ tự tô-pô.

### Thuật toán

1. DFS từ đỉnh 1 với ghi nhớ. Tại mỗi đỉnh $u$:
   - Nếu $u = n$: đặt $dp[u] = 1$.
   - Ngược lại: khởi tạo $dp[u] = -\infty$, duyệt từng đỉnh kề $v$, cập nhật $dp[u] = \max(dp[u], dp[v] + 1)$ và ghi $\text{trace}[u] = v$ khi cập nhật.
2. Nếu $dp[1] \le 0$: không có đường đi, in "IMPOSSIBLE".
3. Ngược lại: in $dp[1]$, rồi theo `trace` từ 1 đến $n$ để tái thiết đường đi.

### Ví dụ minh họa

Input:
```
5 5
1 2
2 5
1 3
3 4
4 5
```

DFS tính từ dưới lên:
- $dp[5] = 1$
- $dp[2] = dp[5] + 1 = 2$, trace[2] = 5
- $dp[4] = dp[5] + 1 = 2$, trace[4] = 5
- $dp[3] = dp[4] + 1 = 3$, trace[3] = 4
- $dp[1] = \max(dp[2]+1, dp[3]+1) = \max(3, 4) = 4$, trace[1] = 3

Đường đi: $1 \to 3 \to 4 \to 5$ (4 thành phố).

Kết quả:
```
4
1 3 4 5
```

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Longest%20Flight%20Route.cpp)
