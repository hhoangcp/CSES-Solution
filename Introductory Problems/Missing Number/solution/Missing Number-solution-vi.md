# Missing Number - Lời giải

**ID:** 1083 | **URL:** https://cses.fi/problemset/task/1083

## Phương pháp

### Tóm tắt bài toán

Cho $n - 1$ số nguyên phân biệt từ tập $\{1, 2, \ldots, n\}$ ($2 \le n \le 2 \times 10^5$). Tìm số duy nhất bị thiếu.

### Ý tưởng chính

Ba cách tiếp cận tiêu chuẩn, đều có thời gian $O(n)$:

**1. Mảng đánh dấu (dùng trong code):** Đánh dấu mỗi số có mặt trong mảng boolean kích thước $n+1$. Với $n-1$ số phân biệt từ $\{1, \ldots, n\}$, đúng 1 vị trí không được đánh dấu — đó là đáp án. Không gian: $O(n)$.

**2. XOR:** Tính $(1 \oplus 2 \oplus \cdots \oplus n) \oplus (a_1 \oplus a_2 \oplus \cdots \oplus a_{n-1})$. Mỗi số có mặt $x$ xuất hiện trong cả hai tập nên triệt tiêu ($x \oplus x = 0$); số thiếu $m$ chỉ có trong tập thứ nhất nên tồn tại. Tiền tố XOR $1 \oplus \cdots \oplus n$ tính trong $O(1)$ theo quy luật: $n \bmod 4 = 0 \to n$, $1 \to 1$, $2 \to n+1$, $3 \to 0$. Không gian: $O(1)$, không rủi ro tràn.

**3. Tổng trừ:** $\text{số thiếu} = \frac{n(n+1)}{2} - \sum a_i$. Vì đầu vào chứa tất cả $\{1, \ldots, n\}$ trừ $m$, tổng đầu vào bằng $\frac{n(n+1)}{2} - m$. Không gian: $O(1)$, nhưng cần số nguyên 64-bit vì $\frac{n(n+1)}{2}$ có thể đạt $\approx 2 \times 10^{10}$.

### Thuật toán

Phương pháp mảng đánh dấu (như trong code):
1. Tạo mảng `mark[1..n]` khởi tạo bằng 0.
2. Với mỗi số đầu vào $x$, tăng `mark[x]`.
3. Tìm và xuất chỉ số $i$ mà `mark[i] == 0`.

### Ví dụ minh họa

$n = 5$, đầu vào: `2 3 1 5`. Số thiếu là **4**.
- Đánh dấu: vị trí 1, 2, 3, 5 đã đánh dấu; vị trí 4 chưa.
- XOR: $(1 \oplus 2 \oplus 3 \oplus 4 \oplus 5) \oplus (2 \oplus 3 \oplus 1 \oplus 5) = 4$.
- Tổng: $15 - 11 = 4$.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$ (đánh dấu); $O(1)$ (XOR hoặc tổng)

## Mã nguồn (C++)

[Mã nguồn](../code/Missing%20Number.cpp)
