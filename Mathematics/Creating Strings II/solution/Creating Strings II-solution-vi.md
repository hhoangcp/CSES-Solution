# Creating Strings II - Lời giải

**ID:** 1715 | **URL:** https://cses.fi/problemset/task/1715

## Phương pháp

### Tóm tắt bài toán

Cho xâu độ dài $n$ ($1 \le n \le 10^6$) gồm các ký tự từ `a` đến `z`. Đếm số hoán vị phân biệt, kết quả lấy modulo $10^9+7$.

### Ý tưởng chính

Gọi $c_1, c_2, \ldots, c_{26}$ là tần số các ký tự ($\sum c_i = n$). Nếu mọi ký tự khác nhau, có $n!$ hoán vị. Với các ký tự lặp, hoán vị nội bộ mỗi nhóm $c_i$ ký tự giống nhau sinh ra $c_i!$ cách sắp xếp trùng nhau, nên đáp án là **hệ số đa thức**:

$$\frac{n!}{c_1! \cdot c_2! \cdot \ldots \cdot c_{26}!}$$

*Chứng minh.* Chọn vị trí tuần tự: chọn $c_1$ vị trí cho ký tự 1 trong $\binom{n}{c_1}$ cách, rồi $c_2$ vị trí từ $n-c_1$ còn lại trong $\binom{n-c_1}{c_2}$ cách, v.v. Tích các tổ hợp triệt tiêu thành $\frac{n!}{c_1! \cdot c_2! \cdot \ldots \cdot c_{26}!}$.

**Tính modulo.** Với $p = 10^9+7$ nguyên tố, thay phép chia bằng nhân với nghịch đảo modulo:

$$\frac{n!}{\prod c_i!} \equiv n! \cdot \prod (c_i!)^{-1} \pmod{p}$$

Tính trước $fact[i] = i! \bmod p$ và $inv\_f[i] = (i!)^{-1} \bmod p$ tới $n$, dùng công thức nghịch đảo tuyến tính. Khi đó:

$$\text{đáp án} = fact[n] \cdot \prod_{i: c_i > 0} inv\_f[c_i] \bmod p$$

### Thuật toán

1. Đọc xâu, đếm tần số ký tự.
2. Tính trước $fact$ và $inv\_f$ tới $n$.
3. Tính $fact[n] \cdot \prod inv\_f[c_i] \bmod p$.

### Ví dụ minh họa

Xâu `aabac`: $n = 5$, tần số $c_a = 3, c_b = 1, c_c = 1$.

$$\text{đáp án} = \frac{5!}{3! \cdot 1! \cdot 1!} = \frac{120}{6} = 20$$

## Độ phức tạp

- **Thời gian:** $O(n)$ — đếm tần số + tiền xử lý giai thừa
- **Bộ nhớ:** $O(n)$
