# Sum of Divisors - Lời giải

**ID:** 1082 | **URL:** https://cses.fi/problemset/task/1082

## Phương pháp

### Tóm tắt bài toán

Cho $n$ ($1 \le n \le 10^{12}$), tính $\sum_{i=1}^{n} \sigma(i) \pmod{10^9+7}$, trong đó $\sigma(i)$ là tổng tất cả các ước dương của $i$.

### Ý tưởng chính

Đổi thứ tự lấy tổng: thay vì tính tổng ước cho từng số $i$, đếm số lần mỗi ước $d$ đóng góp. Ước $d$ xuất hiện trong tổng cho mọi bội của $d$ trong $[1, n]$, tức đúng $\lfloor n/d \rfloor$ lần:

$$\sum_{i=1}^{n} \sigma(i) = \sum_{i=1}^{n} \sum_{d \mid i} d = \sum_{d=1}^{n} d \cdot \left\lfloor \frac{n}{d} \right\rfloor$$

Biểu thức này vẫn có $O(n)$ số hạng. Tuy nhiên, $\lfloor n/d \rfloor$ chỉ nhận $O(\sqrt{n})$ giá trị phân biệt: khi $d \le \sqrt{n}$ có tối đa $\sqrt{n}$ giá trị $d$; khi $d > \sqrt{n}$ thì $\lfloor n/d \rfloor < \sqrt{n}$, nên tối đa $\sqrt{n}$ giá trị thương. Tổng cộng $O(\sqrt{n})$ khối.

**Tính tổng theo khối:** Nhóm các giá trị $d$ liên tiếp có cùng thương $q = \lfloor n/d \rfloor$ thành khối $[l, r]$ với $r = \lfloor n/q \rfloor$. Đóng góp của khối:

$$q \cdot \sum_{d=l}^{r} d = q \cdot \frac{(l+r)(r-l+1)}{2}$$

Phép chia 2 được thực hiện qua nghịch đảo modulo ($5 \cdot 10^8 + 4 \pmod{10^9+7}$). Sau mỗi khối, dịch chuyển $l \gets r + 1$.

### Thuật toán

1. Với $d = 1, 2, \ldots, \lfloor\sqrt{n}\rfloor$: cộng trực tiếp $d \cdot \lfloor n/d \rfloor$.
2. Với mỗi thương $q$ từ $1$ đến $\lfloor\sqrt{n}\rfloor$: tìm khối $[l, r]$ với $l > \lfloor\sqrt{n}\rfloor$ và $\lfloor n/d \rfloor = q$, tính tổng khối và cộng $q \cdot \text{tổng\_khối}$.
3. Xuất kết quả modulo $10^9+7$.

### Ví dụ minh họa

$n = 5$.

| Khối | Khoảng $d$ | $q = \lfloor 5/d \rfloor$ | Đóng góp |
|------|-----------|---------------------------|----------|
| 1 | $[1, 1]$ | 5 | $5 \cdot 1 = 5$ |
| 2 | $[2, 2]$ | 2 | $2 \cdot 2 = 4$ |
| 3 | $[3, 5]$ | 1 | $1 \cdot \frac{8 \cdot 3}{2} = 12$ |

Tổng = $5 + 4 + 12 = 21$ $\checkmark$.

Kiểm tra trực tiếp: $\sigma(1){+}\sigma(2){+}\sigma(3){+}\sigma(4){+}\sigma(5) = 1{+}3{+}4{+}7{+}6 = 21$.

## Độ phức tạp

- **Thời gian:** $O(\sqrt{n})$
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sum%20of%20Divisors.cpp)
