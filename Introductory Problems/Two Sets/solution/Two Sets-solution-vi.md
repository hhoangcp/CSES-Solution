# Two Sets - Lời giải

**ID:** 1092 | **URL:** https://cses.fi/problemset/task/1092

## Hướng tiếp cận

### Tóm tắt bài toán

Cho $n$ ($1 \le n \le 10^6$), chia các số $1, 2, \ldots, n$ thành hai tập có tổng bằng nhau. Nếu không thể, in "NO".

### Ý tưởng chính

**Khả thi.** Tổng tất cả là $S = \frac{n(n+1)}{2}$. Để chia đôi, $S$ phải chẵn. Phân tích $n \bmod 4$:

| $n \bmod 4$ | Tính chẵn lẻ của $S$ | Khả thi? |
|---|---|---|
| 0 | $S = 2k(4k+1)$, chẵn | ✓ |
| 1 | $S = (4k+1)(2k+1)$, lẻ | ✗ |
| 2 | $S = (2k+1)(4k+3)$, lẻ | ✗ |
| 3 | $S = 2(4k+3)(k+1)$, chẵn | ✓ |

Lời giải tồn tại khi và chỉ khi $n \bmod 4 \in \{0, 3\}$.

**Cấu trúc.** Khi khả thi, tìm tập con có tổng bằng $\text{target} = S/2$ bằng cách tích lũy tiền tố tham lam:

1. Cộng dồn $1 + 2 + \cdots + k$ cho đến khi tổng $\ge \text{target}$. Gọi $k$ là số cuối cùng được thêm.
2. Phần dư: $r = \frac{k(k+1)}{2} - \text{target}$.
3. **Tập 1:** $\{1, \ldots, k\} \setminus \{r\}$ (loại $r$ nếu $r > 0$).
4. **Tập 2:** $\{r\} \cup \{k+1, \ldots, n\}$ (thêm $r$ nếu $r > 0$).

**Tính đúng.** Vì $k$ là số nguyên nhỏ nhất thỏa $\frac{k(k+1)}{2} \ge \text{target}$, ta có $\frac{(k-1)k}{2} < \text{target}$, suy ra $r < k$. Điều này đảm bảo $r \in \{1, \ldots, k-1\}$, nên việc loại $r$ khỏi $\{1, \ldots, k\}$ là hợp lệ. Tập 1 có tổng $\frac{k(k+1)}{2} - r = \text{target}$; Tập 2 có tổng $r + S - \frac{k(k+1)}{2} = S - \text{target} = \text{target}$. Hai tập không giao nhau (Tập 1 dùng $\{1, \ldots, k\} \setminus \{r\}$, Tập 2 dùng $\{r\} \cup \{k+1, \ldots, n\}$ với $r < k < k+1$) và phủ đủ $\{1, \ldots, n\}$.

### Thuật toán

1. Nếu $n \bmod 4 \in \{1, 2\}$, xuất "NO".
2. Ngược lại, tính $\text{target} = \frac{n(n+1)}{4}$.
3. Tìm $k$ nhỏ nhất thỏa $\frac{k(k+1)}{2} \ge \text{target}$. Tính $r = \frac{k(k+1)}{2} - \text{target}$.
4. Xuất Tập 1 = $\{1, \ldots, k\} \setminus \{r\}$ và Tập 2 = $\{r\} \cup \{k+1, \ldots, n\}$.

### Ví dụ minh họa

**Ví dụ đề bài 1 ($n = 7$):** $S = 28$, target = 14. $1+2+3+4+5 = 15 \ge 14$, vậy $k = 5$, $r = 1$.

- Tập 1: $\{2, 3, 4, 5\}$ (tổng 14)
- Tập 2: $\{1, 6, 7\}$ (tổng 14)

**Ví dụ đề bài 2 ($n = 6$):** $S = 21$, lẻ → "NO".

**Ví dụ bổ sung ($n = 4$):** $S = 10$, target = 5. $1+2+3 = 6 \ge 5$, vậy $k = 3$, $r = 1$.

- Tập 1: $\{2, 3\}$ (tổng 5)
- Tập 2: $\{1, 4\}$ (tổng 5)

## Độ phức tạp

- **Thời gian:** $O(n)$ — duyệt tuyến tính để xuất hai tập
- **Không gian:** $O(n)$ — lưu kết quả xuất

## Mã nguồn (C++)

[Mã nguồn](../code/Two%20Sets.cpp)
