# Chuyến Đi Vòng Quanh - Lời giải

**ID:** 1669 | **URL:** https://cses.fi/problemset/task/1669

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng $n$ đỉnh và $m$ cạnh, tìm một chu trình đơn có độ dài $\geq 3$, hoặc kết luận "IMPOSSIBLE" nếu không tồn tại.

### Ý tưởng chính

Chạy DFS từ mỗi đỉnh chưa thăm, duy trì ngăn xếp $S$ chứa các đỉnh trên đường DFS hiện tại và mảng `in[u]` đánh dấu $u$ có nằm trên đường đó không. Khi DFS tại đỉnh $u$ gặp đỉnh kề $v$ đã thăm, nằm trên đường hiện tại (`in[v] = true`), và không phải cha trực tiếp của $u$, thì phát hiện **cạnh ngược** — đường đi từ $v$ đến $u$ dọc theo ngăn xếp cộng với cạnh $(u, v)$ tạo thành chu trình.

Chu trình hợp lệ vì các đỉnh trên ngăn xếp phân biệt (DFS không thăm lại), và việc kiểm tra cha đảm bảo $v$ không phải đỉnh liền trước $u$, nên đường đi có độ dài $\geq 2$ và chu trình có độ dài $\geq 3$. Ngược lại, nếu đồ thị chứa chu trình thì DFS sẽ gặp cạnh ngược: khi lần đầu đến chu trình, DFS theo cạnh cây đi vòng và sẽ thấy cạnh quay về tổ tiên còn trên đường đi. Nếu DFS hoàn thành không gặp cạnh ngược, đồ thị là rừng không chu trình.

### Thuật toán

1. Với mỗi đỉnh chưa thăm, chạy DFS với ngăn xếp theo dõi đường đi hiện tại.
2. Tại đỉnh $u$, với mỗi đỉnh kề $v$: nếu $v$ đã thăm, `in[v]` true, và $v$ không phải cha của $u$ — tìm thấy chu trình. Lấy các đỉnh từ đỉnh ngăn xếp đến $v$, thêm $v$ để đóng chu trình, xuất kết quả và kết thúc.
3. Nếu không tìm thấy chu trình sau tất cả DFS, xuất "IMPOSSIBLE".

### Ví dụ minh họa

Input:
```
5 6
1 3
1 2
5 3
1 5
2 4
4 5
```

DFS từ 1: $S = [1, 3, 5]$. Từ 5, đỉnh kề 1 đã thăm, `in[1]` true, và 1 không phải cha của 5. Phát hiện chu trình. Lấy từ ngăn xếp: $1, 5, 3, 1$.

Kết quả:
```
4
3 5 1 3
```

(Bất kỳ chu trình hợp lệ nào đều được chấp nhận.)

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Round%20Trip.cpp)
