# Chu Trình Hành Tinh - Lời giải

**ID:** 1751 | **URL:** https://cses.fi/problemset/task/1751

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị hàm (mỗi đỉnh đúng một cạnh ra) trên $n$ đỉnh, tính với mỗi đỉnh số đỉnh phân biệt được thăm khi xuất phát từ nó và đi theo cạnh cho đến khi chạm đỉnh đã thăm.

### Ý tưởng chính

Mỗi thành phần liên thông của đồ thị hàm gồm đúng một chu trình và các cây có hướng (đuôi) đổ vào chu trình. Với đỉnh trên chu trình độ dài $c$, đáp án là $c$. Với đỉnh trên đuôi cách chu trình $d$ bước, đáp án là $d + c$ — tàu đi $d$ bước dọc đuôi rồi thăm cả $c$ đỉnh chu trình.

Thuật toán xử lý từng thành phần bằng DFS. Mỗi đỉnh được đẩy vào hàng đợi $Q$ trước khi kiểm tra đã thăm, nên hàng đợi ghi lại toàn bộ đường đi DFS bao gồm đỉnh lặp lại khi đóng chu trình. Sau DFS, xử lý hàng đợi: đỉnh đuôi nhận `len` giảm dần (trừ 1 mỗi bước gần chu trình hơn), còn đỉnh chu trình cùng nhận `len` bằng độ dài chu trình. Chuyển đổi từ đuôi sang chu trình được phát hiện khi `Q.front() == Q.back()` — đã đến đỉnh đầu tiên của chu trình.

### Thuật toán

1. Với mỗi đỉnh chưa thăm $u$, bắt đầu DFS theo cạnh ra. Đẩy mỗi đỉnh vào $Q$ trước khi kiểm tra đã thăm. Đếm `steps`.
2. Nếu DFS đến đỉnh $v$ đã thăm và có `len[v]`: cộng `len[v]` vào `steps` rồi trả về (đường đi nhập vào thành phần đã xử lý).
3. Sau DFS, xử lý $Q$ với `sub = 1`. Với mỗi đỉnh lấy ra $u$:
   - Nếu `Q.front() == Q.back()`: đặt `sub = 0` (đã vào chu trình).
   - Đặt `len[u] = steps`, rồi `steps -= sub`.
4. Xuất `len[1..n]`.

### Ví dụ minh họa

Input:
```
5
2 4 3 1 4
```

Đồ thị hàm: $1 \to 2 \to 4 \to 1$ (chu trình độ dài 3), $3 \to 3$ (tự vòng, độ dài 1), $5 \to 4$ (đuôi độ dài 1 vào chu trình).

- DFS từ 1: thăm $1 \to 2 \to 4 \to 1$. $Q = [1,2,4,1]$, steps = 3. Front == back ngay từ đầu → toàn chu trình: len[1] = len[2] = len[4] = 3.
- DFS từ 3: thăm $3 \to 3$. $Q = [3,3]$, steps = 1. Tự vòng: len[3] = 1.
- DFS từ 5: thăm $5$, rồi 4 (đã thăm, len[4] = 3). steps = 1 + 3 = 4. $Q = [5,4]$. Lấy 5 (đuôi, sub = 1): len[5] = 4. Lấy 4 (front == back, sub = 0): len[4] = 3.

Kết quả:
```
3 3 1 3 4
```

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Planets%20Cycles.cpp)
