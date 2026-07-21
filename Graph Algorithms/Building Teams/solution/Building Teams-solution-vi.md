# Xây Đội - Lời giải

**ID:** 1668 | **URL:** https://cses.fi/problemset/task/1668

## Hướng tiếp cận

### Tóm tắt bài toán

Cho $n$ học sinh và $m$ quan hệ bạn bè. Chia tất cả học sinh thành hai đội sao cho không có hai bạn bè nào ở cùng đội. Nếu không thể, in "IMPOSSIBLE".

### Ý tưởng chính

Mô hình hóa bài toán thành đồ thị: đỉnh là học sinh, cạnh là quan hệ bạn bè. Bài toán trở thành tô 2-màu cho đồ thị sao cho hai đỉnh kề luôn khác màu — tức kiểm tra đồ thị có hai phía hay không.

**Sự kiện quan trọng:** Đồ thị hai phía khi và chỉ khi không chứa chu trình lẻ.

BFS tô màu mỗi đỉnh theo tính chẵn/lẻ của khoảng cách từ gốc: màu 1 cho khoảng cách chẵn, màu 2 cho khoảng cách lẻ. Cách tô này nhất quán trong mỗi thành phần liên thông vì:
- Nếu đồ thị hai phía, tồn tại phân chia $(A, B)$ mà mọi cạnh đều nối giữa $A$ và $B$. BFS tô các đỉnh trong $A$ màu 1, trong $B$ màu 2, nên không xảy ra xung đột.
- Nếu đồ thị chứa chu trình lẻ, hai đỉnh kề trên chu trình đó sẽ có cùng tính chẵn/lẻ khoảng cách từ gốc, dẫn đến bị tô cùng màu. Khi xét cạnh giữa chúng, thuật toán phát hiện $c[u] = c[v]$ và báo "IMPOSSIBLE".

### Thuật toán

1. Khởi tạo tất cả màu bằng 0 (chưa tô).
2. Với mỗi đỉnh chưa tô màu $s$:
   - Gán $c[s] = 1$, đẩy $s$ vào hàng đợi.
   - Lặp: lấy đỉnh $u$ từ hàng đợi. Với mỗi đỉnh kề $v$:
     - Nếu $c[v] = 0$: gán $c[v] = 3 - c[u]$, đẩy $v$.
     - Nếu $c[v] = c[u]$: xuất "IMPOSSIBLE" và dừng.
3. Nếu không phát hiện xung đột, xuất tất cả màu.

Công thức $3 - c[u]$ luân phiên giữa 1 và 2: $3 - 1 = 2$, $3 - 2 = 1$.

### Ví dụ minh họa

Đầu vào:
```
5 3
1 2
1 3
4 5
```

Đồ thị có hai thành phần liên thông:
- Thành phần {1, 2, 3}: BFS từ 1 → $c[1] = 1$, kề 2 và 3 → $c[2] = 2$, $c[3] = 2$.
- Thành phần {4, 5}: BFS từ 4 → $c[4] = 1$, kề 5 → $c[5] = 2$.

Không phát hiện xung đột. Kết quả:
```
1 2 2 1 2
```

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — mỗi đỉnh và cạnh được xử lý đúng một lần.
- **Không gian:** $O(n + m)$ — danh sách kề và mảng màu.

## Mã nguồn (C++)

[Mã nguồn](../code/Building%20Teams.cpp)
