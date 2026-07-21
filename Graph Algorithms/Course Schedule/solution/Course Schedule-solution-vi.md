# Lịch Trình Khóa Học - Lời giải

**ID:** 1679 | **URL:** https://cses.fi/problemset/task/1679

## Hướng tiếp cận

### Tóm tắt bài toán

Có $n$ khóa học và $m$ điều kiện tiên quyết dạng "$a$ phải hoàn thành trước $b$". Tìm thứ tự hoàn thành tất cả khóa học thỏa mãn mọi điều kiện, hoặc xuất "IMPOSSIBLE" nếu không tồn tại thứ tự hợp lệ.

### Ý tưởng chính

Mô hình hóa mỗi khóa học là một đỉnh, điều kiện tiên quyết $(a, b)$ là cạnh có hướng $a \to b$. Thứ tự hoàn thành hợp lệ chính là **thứ tự tô-pô** — thứ tự tuyến tính sao cho mọi cạnh $u \to v$ đều có $u$ đứng trước $v$. Thứ tự tô-pô tồn tại khi và chỉ khi đồ thị là **DAG** (không có chu trình có hướng). Nếu tồn tại chu trình $v_1 \to v_2 \to \cdots \to v_k \to v_1$, theo dõi chuỗi tiên quyết sẽ yêu cầu $v_1$ trước $v_1$, vô lý.

Sử dụng DFS để tính thứ tự tô-pô:
- Khi DFS hoàn tất khám phá tất cả đỉnh kề của $u$, thêm $u$ vào danh sách hậu thứ tự.
- Sau khi xử lý xong mọi đỉnh, đảo ngược danh sách hậu thứ tự để thu được thứ tự tô-pô.

Cách làm này đúng vì: khi $u$ được thêm vào danh sách, mọi đỉnh $v$ kề từ $u$ (cạnh $u \to v$) đã được thêm trước. Sau khi đảo ngược, $u$ xuất hiện trước $v$, thỏa mãn điều kiện tô-pô.

**Phát hiện chu trình:** Duy trì cờ `in[u]` cho biết $u$ đang nằm trên ngăn xếp đệ quy DFS hiện tại. Khi xét cạnh $u \to v$: nếu $v$ đã thăm và `in[v]` true, thì $v$ nằm trên đường từ gốc DFS đến $u$, cạnh $u \to v$ tạo thành chu trình. Ngược lại, nếu đồ thị có chu trình thì DFS chắc chắn gặp cạnh ngược, nên thuật toán luôn phát hiện được.

### Thuật toán

1. Với mỗi đỉnh chưa thăm, chạy DFS.
2. Trong DFS từ đỉnh $u$:
   - Gán `visited[u] = in[u] = true`.
   - Với mỗi đỉnh kề $v$: nếu chưa thăm, đệ quy; nếu đã thăm và `in[v]` true → phát hiện chu trình, xuất "IMPOSSIBLE".
   - Sau khi xử lý xong tất cả đỉnh kề: gán `in[u] = false`, thêm $u$ vào danh sách kết quả.
3. Đảo ngược danh sách kết quả và xuất.

### Ví dụ minh họa

Đầu vào:
```
5 3
1 2
3 1
4 5
```

Cạnh đồ thị: $1 \to 2$, $3 \to 1$, $4 \to 5$.

- DFS từ 1: thăm 1 → kề 2 → thăm 2 (không có kề) → hậu thứ tự: 2. Quay lại 1 → hậu thứ tự: 2, 1.
- DFS từ 3: thăm 3 → kề 1 (đã thăm, không trong ngăn xếp) → hậu thứ tự: 2, 1, 3.
- DFS từ 4: thăm 4 → kề 5 → thăm 5 (không có kề) → hậu thứ tự: 2, 1, 3, 5. Quay lại 4 → hậu thứ tự: 2, 1, 3, 5, 4.

Đảo ngược: `4 5 3 1 2`. Kiểm tra: 1→2 (1 trước 2 ✓), 3→1 (3 trước 1 ✓), 4→5 (4 trước 5 ✓).

Kết quả:
```
4 5 3 1 2
```

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — mỗi đỉnh và cạnh được xử lý đúng một lần.
- **Không gian:** $O(n + m)$ — danh sách kề và các mảng trạng thái.

## Mã nguồn (C++)

[Mã nguồn](../code/Course%20Schedule.cpp)
