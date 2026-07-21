# Transfer Speeds Sum - Lời giải

**ID:** 3111 | **URL:** https://cses.fi/problemset/task/3111

## Phương pháp

### Tóm tắt bài toán

Cho cây $n$ đỉnh, mỗi cạnh có tốc độ truyền. $d(a,b)$ = trọng số cạnh nhỏ nhất trên đường đi $a$-$b$. Tính $\sum_{1 \leq a < b \leq n} d(a,b)$.

### Ý tưởng chính

Sắp xếp cạnh theo trọng số giảm dần, xử lý bằng union-find. Khi cạnh $e = (u, v, w)$ nối hai thành phần kích thước $|A|$ và $|B|$, đúng $|A| \times |B|$ cặp mới được nối, mỗi cặp có $d(a,b) = w$: vì mọi cạnh nặng hơn đã thêm, $e$ là cạnh nhẹ nhất (cổ chai) trên mọi đường vừa nối. Mỗi cặp $(a,b)$ đóng góp đúng 1 lần — tại bước xử lý cạnh cổ chai trên đường đi (cạnh nhẹ nhất), vì trước đó $a$ và $b$ còn khác thành phần, sau đó đã nối. Tổng bằng $\sum_e |A_e| \times |B_e| \times w_e$.

### Thuật toán

1. Sắp xếp $n-1$ cạnh theo trọng số giảm dần.
2. Khởi tạo union-find: mỗi đỉnh là thành phần kích thước 1.
3. Với mỗi cạnh $(u, v, w)$ theo thứ tự đã sắp:
   - $|A|$ = kích thước thành phần $u$, $|B|$ = kích thước thành phần $v$.
   - Cộng $|A| \times |B| \times w$ vào đáp án.
   - Union $u$ và $v$.
4. Xuất đáp án.

### Ví dụ minh họa

$n=4$, cạnh: (1,2,5), (2,3,1), (2,4,2). Sắp giảm: (1,2,5), (2,4,2), (2,3,1).

- (1,2,5): $|A|=1, |B|=1$, đóng góp $5$. Thành phần: {1,2}.
- (2,4,2): $|A|=2, |B|=1$, đóng góp $4$. Thành phần: {1,2,4}.
- (2,3,1): $|A|=3, |B|=1$, đóng góp $3$. Thành phần: {1,2,3,4}.

Tổng: $5 + 4 + 3 = 12$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Transfer%20Speeds%20Sum.cpp)
