# Exponentiation II - Lời giải

**ID:** 1712 | **URL:** https://cses.fi/problemset/task/1712

## Phương pháp

### Tóm tắt bài toán

Tính $a^{b^c} \bmod (10^9+7)$ cho $n$ truy vấn ($1 \le n \le 10^5$, $0 \le a, b, c \le 10^9$), với quy ước $0^0 = 1$.

### Ý tưởng chính

Số mũ $b^c$ có thể đạt $10^{9 \cdot 10^9}$ — không thể tính trực tiếp. Theo **Định lý Fermat nhỏ**, vì $p = 10^9+7$ nguyên tố và $a^{p-1} \equiv 1 \pmod{p}$ khi $\gcd(a, p) = 1$, ta rút gọn số mũ modulo $p-1$:

$$a^{b^c} \equiv a^{b^c \bmod (p-1)} \pmod{p} \quad \text{(khi } \gcd(a, p) = 1\text{)}$$

*Chứng minh.* Viết $b^c = q(p-1) + r$ với $r = b^c \bmod (p-1)$. Khi đó $a^{b^c} = (a^{p-1})^q \cdot a^r \equiv a^r \pmod{p}$.

### Trường hợp biên

Công thức $a^{b^c} \equiv a^{b^c \bmod (p-1)} \pmod{p}$ **sai** khi $p \mid a$ và $b^c \bmod (p-1) = 0$ nhưng $b^c > 0$, vì sẽ tính $a^0 = 1$ thay vì đáp án đúng $0$. Vì $a \le 10^9 < p$, trường hợp $p \mid a$ duy nhất là $a = 0$.

**Phân tích trường hợp $a = 0$:**

| $b$ | $c$ | $b^c$ | $a^{b^c} = 0^{b^c}$ | Giải thích |
|:---:|:---:|:------:|:--------------------:|:------------|
| $0$ | $0$ | $1$ | $0^1 = 0$ | $0^0 = 1$ theo quy ước, nên $0^{0^0} = 0^1$ |
| $0$ | $>0$ | $0$ | $0^0 = 1$ | Quy ước $0^0 = 1$ |
| $>0$ | $0$ | $1$ | $0^1 = 0$ | |
| $>0$ | $>0$ | $>0$ | $0^+ = 0$ | |

Trường hợp duy nhất cho đáp án $1$ là $a = 0, b = 0, c > 0$. Mọi trường hợp khác với $a = 0$ đều cho đáp án $0$.

**Fix cho $a > 0$:** Khi $e = b^c \bmod (p-1) = 0$, hoặc $b^c = 0$ (nếu $b = 0, c > 0$) hoặc $b^c$ là bội dương của $p-1$. Trong cả hai trường hợp, $a^{b^c} \equiv 1 \pmod{p}$ (vì $a^0 = 1$ và $a^{k(p-1)} = (a^{p-1})^k \equiv 1$ theo FLT). Ta thay $e = 0$ bằng $e = p-1$: vì $a^{p-1} \equiv 1 \equiv a^0 \pmod{p}$, đáp án không đổi.

### Thuật toán

1. Với mỗi truy vấn $(a, b, c)$:
   - Nếu $a = 0$: xuất $1$ nếu $b = 0$ và $c > 0$, ngược lại xuất $0$.
   - Nếu $a > 0$: tính $e = b^c \bmod (10^9{+}6)$ bằng lũy thừa nhị phân. Nếu $e = 0$, đặt $e = 10^9{+}6$. Tính $a^e \bmod (10^9{+}7)$ bằng lũy thừa nhị phân.

### Ví dụ minh họa

**Test 1:** $3^{7^1} = 3^7 = 2187$. $7^1 \bmod (10^9{+}6) = 7$, $3^7 \bmod (10^9{+}7) = 2187$.

**Test 2:** $15^{2^2} = 15^4 = 50625$. $2^2 \bmod (10^9{+}6) = 4$, $15^4 \bmod (10^9{+}7) = 50625$.

**Test 3:** $3^{4^5}$. $4^5 = 1024$, $1024 \bmod (10^9{+}6) = 1024$, $3^{1024} \bmod (10^9{+}7) = 763327764$.

## Độ phức tạp

- **Thời gian:** $O(\log c + \log b)$ mỗi truy vấn — hai lần lũy thừa nhị phân
- **Bộ nhớ:** $O(1)$
