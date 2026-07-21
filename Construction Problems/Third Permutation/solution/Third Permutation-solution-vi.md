# Third Permutation - Lời giải

**ID:** 3422 | **URL:** https://cses.fi/problemset/task/3422

## Phương pháp

### Tóm tắt bài toán

Cho hai hoán vị $a$ và $b$ kích thước $n$ với $a_i \ne b_i$ với mọi $i$, tìm hoán vị thứ ba $c$ sao cho $c_i \ne a_i$ và $c_i \ne b_i$ với mọi $i$.

### Ý tưởng chính

Với $n = 2$, không khả thi — $a_i$ và $b_i$ là hai giá trị khác nhau chiếm hết $\{1, 2\}$ tại mỗi vị trí. Với $n \ge 3$, luôn tồn tại lời giải bằng phép dịch vòng (cyclic shift).

Định nghĩa **độ lệch** tại vị trí $i$ là $s_i = (b_i - a_i) \bmod n$ (0-indexed). Vì $a_i \ne b_i$, $s_i \in \{1, \ldots, n-1\}$. Nếu đặt $c_i = (a_i + t) \bmod n + 1$ với hằng số $t \in \{1, \ldots, n-1\}$, thì $c$ là hoán vị, $c_i \ne a_i$ (vì $t \ne 0$), và $c_i \ne b_i$ miễn là $t \ne s_i$ với mọi $i$. Vậy nếu tồn tại $t$ với $\text{freq}[t] = 0$, ta hoàn thành.

Khi nào tồn tại độ lệch có tần suất 0? Vì $\sum_i s_i = \sum_i b_i - \sum_i a_i \equiv 0 \pmod{n}$: với **$n$ lẻ**, độ lệch tần suất 0 luôn tồn tại (nếu tất cả đều xuất hiện thì $\sum_{k=1}^{n-1} k + r \equiv 0 \pmod{n}$ với độ lệch lặp $r$, suy ra $r \equiv 0$, vô lý). Với **$n$ chẵn**, có thể tất cả độ lệch đều xuất hiện, nhưng khi đó độ lệch lặp bắt buộc là $r = n/2$.

Khi tất cả độ lệch xuất hiện ($n$ chẵn, độ lệch $n/2$ xuất hiện đúng 2 lần tại $p_1, p_2$): gán cơ sở $c_i = (a_i + n/2) \bmod n + 1$, chỉ xung đột $b$ tại $p_1, p_2$. **Trường hợp A**: nếu $a_{p_2} \not\equiv a_{p_1} + n/2 \pmod{n}$, hoán đổi $c_{p_1}$ và $c_{p_2}$ — giải quyết cả hai xung đột mà không tạo xung đột mới. **Trường hợp B**: nếu $a_{p_2} \equiv a_{p_1} + n/2 \pmod{n}$, hoán đổi trực tiếp sẽ gây $c_{p_1} = a_{p_1} + 1$. Thay vào đó, chọn hai vị trí khác $p_3, p_4$ và hoán đổi $c_{p_1} \leftrightarrow c_{p_3}$, $c_{p_2} \leftrightarrow c_{p_4}$ — vì $b$ là hoán vị, giá trị tại $p_3, p_4$ khác giá trị tại $p_1, p_2$, thỏa mãn mọi ràng buộc.

### Thuật toán

1. Nếu $n \le 2$: xuất `IMPOSSIBLE`.
2. Tính độ lệch $s_i = (b_i - a_i) \bmod n$ và tần suất.
3. Nếu có $t \in \{1, \ldots, n-1\}$ với $\text{freq}[t] = 0$: xuất $c_i = (a_i + t) \bmod n + 1$.
4. Ngược lại (tất cả độ lệch xuất hiện, $n$ chẵn, độ lệch $n/2$ xuất hiện 2 lần tại $p_1, p_2$):
   - Gán cơ sở $c_i = (a_i + n/2) \bmod n + 1$.
   - **Trường hợp A** ($a_{p_2} \not\equiv a_{p_1} + n/2 \pmod{n}$): hoán đổi $c_{p_1}$ và $c_{p_2}$.
   - **Trường hợp B**: chọn $p_3, p_4$ khác $p_1, p_2$, hoán đổi $c_{p_1} \leftrightarrow c_{p_3}$ và $c_{p_2} \leftrightarrow c_{p_4}$.
5. Xuất $c$.

### Ví dụ minh họa

$n = 5$, $a = [1, 3, 2, 5, 4]$, $b = [4, 1, 3, 2, 5]$ (ví dụ đề bài, kết quả hợp lệ: `3 2 5 4 1`):

1. 0-indexed: $a = [0, 2, 1, 4, 3]$, $b = [3, 0, 2, 1, 4]$. Độ lệch: $[3, 3, 1, 2, 1]$.
2. Tần suất: $1 \to 2$, $2 \to 1$, $3 \to 2$. Độ lệch $4$ có tần suất 0.
3. Dùng $t = 4$: $c_i = (a_i + 4) \bmod 5 + 1 = [5, 2, 1, 4, 3]$.

Kiểm tra: $5 \notin \{1,4\}$, $2 \notin \{3,1\}$, $1 \notin \{2,3\}$, $4 \notin \{5,2\}$, $3 \notin \{4,5\}$. ✓

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Third%20Permutation.cpp)
