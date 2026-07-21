# Điểm Cao - Lời giải

**ID:** 1673 | **URL:** https://cses.fi/problemset/task/1673

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh, $m$ cạnh với trọng số tùy ý (dương hoặc âm). Tìm đường đi có tổng trọng số lớn nhất từ đỉnh 1 đến đỉnh $n$. Có thể đi qua mỗi cạnh nhiều lần. Nếu điểm có thể tăng vô hạn, xuất $-1$.

### Ý tưởng chính

Đổi dấu tất cả trọng số: $c' = -c$. Đường đi tổng lớn nhất trên đồ thị gốc trở thành đường đi ngắn nhất trên đồ thị đổi dấu. Chu trình dương gốc ($\sum c_i > 0$) trở thành chu trình âm đổi dấu ($\sum c'_i < 0$). Nếu tồn tại chu trình âm reachable từ đỉnh 1 và có thể đến đỉnh $n$, điểm không giới hạn (lặp chu trình dương gốc nhiều lần rồi đi đến $n$).

Chỉ chu trình âm trên đường đi từ 1 đến $n$ mới ảnh hưởng. Để lọc bỏ chu trình không liên quan, chạy DFS từ đỉnh $n$ trên **đồ thị đảo ngược** đánh dấu mọi đỉnh có thể đến $n$. Chỉ xét cạnh đến đỉnh đã đánh dấu trong SPFA — tránh phát hiện sai chu trình âm không thể ảnh hưởng đường đi 1→$n$.

Nếu không có chu trình âm liên quan, SPFA hội tụ và đáp án là $-dist[n]$ (đổi dấu lại). Ngược lại, xuất $-1$.

### Thuật toán

1. **Đổi dấu trọng số** khi đọc input: lưu $c' = -c$ cho mỗi cạnh.
2. **DFS từ $n$ trên đồ thị đảo:** Đánh dấu `visited[u] = true` cho mọi đỉnh có thể đến $n$.
3. **SPFA từ đỉnh 1:** Chỉ relax cạnh đến đỉnh có `visited[v] = true`. Duy trì `cnt[v]` (số lần $v$ vào hàng đợi). Nếu `cnt[v] > n`, tồn tại chu trình âm liên quan — xuất $-1$.
4. Nếu SPFA hội tụ, xuất $-dist[n]$.

### Ví dụ minh họa

Đầu vào:
```
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
```

Trọng số đổi dấu: $1\to2\ (-3)$, $2\to4\ (1)$, $1\to3\ (2)$, $3\to4\ (-7)$, $1\to4\ (-4)$.

DFS từ 4 trên đồ thị đảo: mọi đỉnh đều đến được 4, nên `visited = {1,2,3,4}`.

SPFA: $dist[1]=0$. Xét đỉnh 1: $dist[2]=-3$, $dist[3]=2$, $dist[4]=-4$. Xét đỉnh 2: $2\to4$ cho $-3+1=-2 > -4$, không cập nhật. Xét đỉnh 3: $3\to4$ cho $2+(-7)=-5 < -4$, cập nhật $dist[4]=-5$.

Không đỉnh nào vào hàng đợi quá $n$ lần. Đáp án: $-dist[4] = -(-5) = 5$ (đường $1\to3\to4$, điểm gốc $-2+7=5$).

Kết quả: `5`

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$ — trường hợp xấu nhất của SPFA.
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/High%20Score.cpp)
