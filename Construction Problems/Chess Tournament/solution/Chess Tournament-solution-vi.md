# Chess Tournament - Lời giải

**ID:** 1697 | **URL:** https://cses.fi/problemset/task/1697

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho $n$ người chơi, người thứ $i$ muốn đấu đúng $x_i$ ván, mỗi cặp người chơi chỉ đấu tối đa một ván. Tìm tập ván đấu hợp lệ hoặc kết luận không thể.

### Ý tưởng cốt lõi

Mô hình hóa bài toán thành **bài toán thực hiện đồ thị** (graph realization): mỗi người chơi là một đỉnh, số ván muốn đấu là bậc, mỗi ván đấu là một cạnh. Ràng buộc "mỗi cặp đấu tối đa một ván" tương đương đồ thị đơn giản (không đa cạnh, không khuyên). Bài toán quy về: cho dãy bậc $x_1, x_2, \ldots, x_n$, xây dựng đồ thị đơn giản có các bậc tương ứng.

Sử dụng **thuật toán Havel-Hakimi** cài đặt bằng max-heap. Ý tưởng quan trọng: nếu dãy bậc là đồ thị được, ta luôn có thể ghép đỉnh có bậc lớn nhất với các đỉnh có bậc lớn nhất tiếp theo mà không mất tính tổng quát.

Max-heap thực hiện tham lam dựa trên định lý Havel-Hakimi: luôn ghép người bị ràng buộc nhiều nhất trước, tương đương việc lấy bậc lớn nhất và giảm $d_1$ bậc lớn nhất tiếp theo.

### Thuật toán

1. Đưa tất cả người chơi vào max-heap, khóa là số ván còn lại.
2. Lấy người chơi $u$ có số ván còn lại lớn nhất ra khỏi heap.
3. Lấy tiếp $x_u$ người chơi có số ván lớn nhất từ heap. Ghép mỗi người $v$ với $u$, giảm số ván của $v$ xuống 1.
4. Nếu heap có ít hơn $x_u$ người, hoặc có người được lấy ra có số ván bằng 0, xuất `IMPOSSIBLE`.
5. Đẩy các người chơi đã ghép trở lại heap với số ván cập nhật.
6. Lặp lại cho đến khi heap rỗng.

### Ví dụ minh họa

$n = 5$, $x = [1, 3, 2, 0, 2]$ (người chơi đánh số $1 \ldots 5$):

- **Vòng 1:** Lấy người chơi 2 (cần 3 ván). Heap còn $\{(1, P1), (2, P3), (2, P5), (0, P4)\}$. Lấy 3 người: 1, 3, 5. Ghép $(2,1)$, $(2,3)$, $(2,5)$. Cập nhật: P1→0, P3→1, P5→1.
- **Vòng 2:** Lấy người chơi 3 (cần 1 ván). Heap còn $\{(1, P5), (0, P4), (0, P1)\}$. Lấy 1 người: 5. Ghép $(3,5)$. Cập nhật: P5→0.
- Tất cả người chơi còn lại đều có số ván bằng 0. Hoàn thành.

Kết quả: 4 ván đấu $\{(1,2), (2,3), (2,5), (3,5)\}$, khớp với kết quả mong đợi.

## Độ phức tạp

- **Thời gian:** $O((n + S) \log n)$ với $S = \sum x_i$
- **Bộ nhớ:** $O(n + S)$

## Mã nguồn (C++)

[Mã nguồn](../code/Chess%20Tournament.cpp)
