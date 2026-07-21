# Knight Moves Grid - Lời giải

**ID:** 3217 | **URL:** https://cses.fi/problemset/task/3217

## Phương pháp

### Tóm tắt bài toán

Cho bàn cờ $n \times n$ ($4 \le n \le 1000$), với mỗi ô tính số bước đi mã ít nhất từ $(0,0)$. Mã di chuyển theo hình chữ "L": 2 ô theo một hướng và 1 ô vuông góc.

### Ý tưởng chính

Mô hình hóa lưới thành đồ thị không trọng số, mỗi ô là đỉnh, các cạnh nối các ô cách nhau một bước đi mã (8 hàng xóm mỗi ô: $(r \pm 2, c \pm 1)$ và $(r \pm 1, c \pm 2)$). BFS tìm đường đi ngắn nhất trên đồ thị không trọng số bằng cách khám phá đỉnh theo từng tầng khoảng cách — lần đầu tiên đến được một đỉnh, đường đi ngắn nhất đến nó đã chắc chắn. Nếu tồn tại đường ngắn hơn, đỉnh trước nó trên đường đó đã được xử lý sớm hơn và khám phá đỉnh đó rồi, mâu thuẫn.

**Đánh dấu lúc push:** Đánh dấu đã thăm ngay khi thêm ô vào hàng đợi, không phải lúc pop. Nếu không, cùng một ô có thể được push nhiều lần bởi các hàng xóm khác nhau trong cùng một tầng, gây hàng đợi phình to. Vì lần khám phá đầu tiên luôn cho khoảng cách tối ưu, bỏ qua các lần trùng là an toàn.

**Khả năng tiếp cận:** Với $n \ge 5$, tất cả ô đều đến được từ $(0,0)$. Với $n \le 4$, một số ô có thể không đến được và giữ khoảng cách 0.

### Thuật toán

1. Khởi tạo lưới khoảng cách bằng 0, đánh dấu $(0,0)$ đã thăm với khoảng cách 0, thêm vào hàng đợi.
2. Trong khi hàng đợi không rỗng:
   - Lấy $(r, c)$ khỏi hàng đợi.
   - Với mỗi trong 8 bước đi mã đến $(nr, nc)$: nếu trong biên và chưa thăm, đặt khoảng cách $= d[r][c] + 1$, đánh dấu đã thăm, và thêm vào hàng đợi.
3. Xuất lưới khoảng cách.

### Ví dụ minh họa

$n = 8$:

```
0 3 2 3 2 3 4 5
3 4 1 2 3 4 3 4
2 1 4 3 2 3 4 5
3 2 3 2 3 4 3 4
2 3 2 3 4 3 4 5
3 4 3 4 3 4 5 4
4 3 4 3 4 5 4 5
5 4 5 4 5 4 5 6
```

Kiểm tra: $(0,0) = 0$, $(1,2) = 1$ (một bước đi mã), $(0,1) = 3$.

## Độ phức tạp

- **Thời gian:** $O(n^2)$
- **Không gian:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Knight%20Moves%20Grid.cpp)
