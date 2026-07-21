# Tuyến Tin Nhắn - Lời giải

**ID:** 1667 | **URL:** https://cses.fi/problemset/task/1667

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng $n$ đỉnh và $m$ cạnh, tìm đường đi ngắn nhất (ít cạnh nhất) từ đỉnh 1 đến đỉnh $n$, hoặc kết luận "IMPOSSIBLE" nếu không tồn tại đường đi.

### Ý tưởng chính

BFS trên đồ thị không trọng số luôn tìm đường đi ngắn nhất. Khi khám phá theo từng lớp ($L_0 = \{\text{nguồn}\}$, $L_k$ = các đỉnh chưa thăm kề $L_{k-1}$), mỗi đỉnh lần đầu được phát hiện đúng ở khoảng cách tối thiểu — không tồn tại đường đi ngắn hơn vì khi đó đỉnh đã nằm ở lớp sớm hơn. Nếu đỉnh 1 không thể đến từ đỉnh $n$, không có đường đi.

BFS bắt đầu từ đỉnh $n$ (đích) tìm về đỉnh 1 (nguồn). Việc này thuận tiện cho truy vết: theo con trỏ `trace` từ đỉnh 1 đến đỉnh $n$ cho đường đi đúng thứ tự từ nguồn đến đích mà không cần đảo ngược.

### Thuật toán

1. Chạy BFS từ đỉnh $n$. Với mỗi đỉnh $v$ được phát hiện, lưu đỉnh cha (`trace[v]`) và khoảng cách từ $n$ (`dist[v]`).
2. Nếu đỉnh 1 không được thăm, in "IMPOSSIBLE".
3. Ngược lại, in `dist[1]` và truy vết đường đi từ 1 đến $n$ qua `trace`.

### Ví dụ minh họa

Input:
```
5 5
1 2
1 3
1 4
2 3
5 4
```

BFS từ đỉnh 5:
- $L_0 = \{5\}$, dist[5] = 1
- $L_1 = \{4\}$, dist[4] = 2, trace[4] = 5
- $L_2 = \{1\}$, dist[1] = 3, trace[1] = 4
- $L_3 = \{2, 3\}$, dist[2] = 4, trace[2] = 1; dist[3] = 4, trace[3] = 1

Truy vết từ đỉnh 1: $1 \to 4 \to 5$.

Kết quả:
```
3
1 4 5
```

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Message%20Route.cpp)
