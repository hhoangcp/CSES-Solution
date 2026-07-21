# Các Tuyến Đường Trò Chơi - Lời giải

**ID:** 1681 | **URL:** https://cses.fi/problemset/task/1681

## Hướng tiếp cận

### Tóm tắt bài toán

Cho DAG (đồ thị có hướng không chu trình) $n$ đỉnh, $m$ cạnh. Đếm số đường đi khác nhau từ đỉnh 1 đến đỉnh $n$. Kết quả lấy modulo $10^9 + 7$.

### Ý tưởng chính

Gọi $dp[u]$ là số đường đi từ đỉnh $u$ đến đỉnh $n$. Công thức truy hồi:

$$dp[u] = \sum_{(u,v) \in E} dp[v] \pmod{10^9+7}$$

Công thức đúng vì mọi đường đi từ $u$ đến $n$ phải bắt đầu bằng một cạnh $(u, v)$ rồi đi từ $v$ đến $n$. Do đồ thị không có chu trình, phân hoạch theo cạnh đầu tiên là không giao nhau và đầy đủ — mỗi đường đi được đếm đúng 1 lần trong đúng một thành phần $dp[v]$.

Điều kiện biên: $dp[n] = 1$ (đường đi rỗng tại đích).

Tính bằng DFS + ghi nhớ: vì DAG không có chu trình nên DFS không bị lặp. Khi thăm đỉnh $u$, đệ quy tính $dp[v]$ cho mỗi đỉnh kề chưa thăm $v$ trước, rồi cộng dồn. Đánh dấu `visited[u] = true` sau khi tính xong để mỗi đỉnh chỉ xử lý 1 lần. Cấu trúc DAG đảm bảo $dp[v]$ luôn được tính trước khi dùng cho đỉnh tiền nhiệm (vì cạnh $u \to v$ nên DFS khám phá $v$ trước).

### Thuật toán

1. Khởi tạo `visited[] = false`, `dp[] = 0`.
2. DFS từ đỉnh 1:
   - Nếu $u = n$: gán $dp[u] = 1$ và trả về.
   - Với mỗi đỉnh kề $v$: nếu chưa thăm thì đệ quy; rồi cộng $dp[v]$ vào $dp[u]$ theo modulo $10^9+7$.
   - Đánh dấu `visited[u] = true`.
3. Xuất $dp[1]$.

### Ví dụ minh họa

Đầu vào:
```
4 5
1 2
2 4
1 3
3 4
1 4
```

DFS từ 1:
- Đệ quy đến 2 → đệ quy đến 4: $dp[4] = 1$. Quay lại: $dp[2] = 1$.
- Đệ quy đến 3 → 4 đã thăm: $dp[3] = dp[4] = 1$.
- 4 đã thăm: $dp[1] = dp[2] + dp[3] + dp[4] = 1 + 1 + 1 = 3$.

3 đường đi: $1 \to 2 \to 4$, $1 \to 3 \to 4$, $1 \to 4$.

Kết quả: `3`

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — mỗi đỉnh và cạnh được xử lý đúng 1 lần.
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Game%20Routes.cpp)
