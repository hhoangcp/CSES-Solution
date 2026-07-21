# Binomial Coefficients - Lời giải

**ID:** 1079 | **URL:** https://cses.fi/problemset/task/1079

## Phương pháp

### Tóm tắt bài toán

Cho $n$ truy vấn, mỗi truy vấn yêu cầu tính $\binom{a}{b} \mod (10^9 + 7)$ với $0 \le b \le a \le 10^6$.

### Ý tưởng chính

Theo định nghĩa, $\binom{a}{b} = \frac{a!}{b! \cdot (a-b)!}$. Vì giai thừa tăng quá nhanh gây tràn số và phép chia không thực hiện trực tiếp trong số học modulo, ta thay phép chia bằng nhân với nghịch đảo modulo:

$$\binom{a}{b} \equiv a! \cdot (b!)^{-1} \cdot ((a-b)!)^{-1} \pmod{p}$$

với $p = 10^9 + 7$ là số nguyên tố. Tính trước hai mảng tới $M = \max a$:

1. **Giai thừa:** $fact[i] = i! \mod p$
2. **Nghịch đảo giai thừa:** $inv\_f[i] = (i!)^{-1} \mod p$

**Nghịch đảo modulo từng phần tử.** Với $p$ nguyên tố và $1 \le i < p$, viết $p = q \cdot i + r$ với $q = \lfloor p/i \rfloor$ và $r = p \bmod i$. Khi đó:

$$q \cdot i + r \equiv 0 \pmod{p} \implies i^{-1} \equiv -q \cdot r^{-1} \pmod{p}$$

Vì $r < i$ nên $inv[r]$ đã được tính trước, ta có công thức truy hồi $O(1)$:

$$inv[i] = p - \lfloor p/i \rfloor \cdot inv[p \bmod i] \bmod p$$

**Nghịch đảo giai thừa.** Từ $inv\_f[0] = 1$:

$$inv\_f[i] = inv\_f[i-1] \cdot inv[i] \bmod p$$

do $(i!)^{-1} = i^{-1} \cdot ((i-1)!)^{-1} = inv[i] \cdot inv\_f[i-1]$.

### Thuật toán

1. Tính trước $fact[i]$ với $i = 0, 1, \ldots, M$ ($M = \max a$).
2. Tính trước $inv[i]$ và $inv\_f[i]$ với $i = 0, 1, \ldots, M$.
3. Với mỗi truy vấn $(a, b)$: xuất $fact[a] \cdot inv\_f[b] \cdot inv\_f[a-b] \bmod p$.

### Ví dụ minh họa

**Test 1:** $\binom{5}{3} = \frac{5!}{3! \cdot 2!} = \frac{120}{6 \cdot 2} = 10$. Kết quả: `10`.

**Test 2:** $\binom{8}{1} = \frac{8!}{1! \cdot 7!} = 8$. Kết quả: `8`.

**Test 3:** $\binom{9}{5} = \frac{9!}{5! \cdot 4!} = \frac{362880}{120 \cdot 24} = 126$. Kết quả: `126`.

## Độ phức tạp

- **Thời gian:** $O(M)$ tiền xử lý + $O(1)$ mỗi truy vấn, với $M = \max a$
- **Bộ nhớ:** $O(M)$
