# Counting Permutations - Lời giải

**ID:** 1075 | **URL:** https://cses.fi/problemset/task/1075

## Phương pháp

### Tóm tắt bài toán

Đếm số hoán vị "đẹp" của $\{1, 2, \ldots, n\}$ mà không có hai phần tử liền kề có hiệu bằng 1 (tức $|p_i - p_{i+1}| \neq 1$ với mọi $i$). Kết quả modulo $10^9 + 7$.

### Bao hàm - loại trừ và đệ quy bậc 4

Dãy này là OEIS A002464. Gọi $A_i$ là tập hoán vị mà $i$ và $i+1$ đứng liền nhau. Cần đếm hoán vị không thuộc $A_1 \cup A_2 \cup \cdots \cup A_{n-1}$.

Áp dụng bao hàm - loại trừ trên các tập cấm, và dùng kỹ thuật gộp mỗi cặp liền nhau $(i, i+1)$ thành một "siêu phần tử," ta thu được đệ quy tuyến tính bậc 4 (xem Shar, 1968; Kaplansky & Riordan, 1946):

$$f(n) = (n+1) \cdot f(n-1) - (n-2) \cdot f(n-2) - (n-5) \cdot f(n-3) + (n-3) \cdot f(n-4)$$

**Giải thích các số hạng** (chèn phần tử $n$ vào hoán vị của $\{1, \ldots, n-1\}$):

- $(n+1) \cdot f(n-1)$: Chèn $n$ vào hoán vị đẹp kích thước $n-1$ ở $n$ vị trí khả dĩ. Tổng đếm bị đếm dư do bao gồm cả hoán vị mà $n$ tạo cặp cấm mới.
- $-(n-2) \cdot f(n-2)$: Bớt các trường hợp chèn $n$ tạo cặp liền nhau $(n-1, n)$.
- $-(n-5) \cdot f(n-3)$ và $+(n-3) \cdot f(n-4)$: Điều chỉnh các tương tác bậc cao — khi nhiều cặp liền nhau được tạo hoặc phá cùng lúc.

### Các trường hợp cơ sở

| $n$ | $f(n)$ | Giải thích |
|-----|---------|-------------|
| 0 | 1 | Hoán vị rỗng |
| 1 | 1 | Chỉ có $[1]$ |
| 2 | 0 | $[1,2]$ và $[2,1]$ đều có cặp liền nhau |
| 3 | 0 | Mọi hoán vị của $\{1,2,3\}$ đều có cặp liền nhau |
| 4 | 2 | Chỉ có $[2,4,1,3]$ và $[3,1,4,2]$ |

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$.

$$f(5) = 6 \cdot f(4) - 3 \cdot f(3) - 0 \cdot f(2) + 2 \cdot f(1) = 6 \cdot 2 - 3 \cdot 0 - 0 \cdot 0 + 2 \cdot 1 = 14$$

**Kiểm tra $f(4) = 2$:** $f(4) = 5 \cdot f(3) - 2 \cdot f(2) - (-1) \cdot f(1) + 1 \cdot f(0) = 0 - 0 + 1 + 1 = 2$. ✓

## Độ phức tạp

- **Thời gian:** $O(n)$ — tính đệ quy một lượt.
- **Bộ nhớ:** $O(n)$ — cho mảng QHD.

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Permutations.cpp)
