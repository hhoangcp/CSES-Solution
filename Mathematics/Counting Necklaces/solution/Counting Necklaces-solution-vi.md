# Counting Necklaces - Lời giải

**ID:** 2209 | **URL:** https://cses.fi/problemset/task/2209

## Phương pháp

### Tóm tắt bài toán

Đếm số dây chuyền phân biệt gồm $n$ hạt ($1 \le n \le 10^6$), mỗi hạt tô một trong $m$ màu ($1 \le m \le 10^6$), xét đến phép quay. Kết quả lấy modulo $10^9+7$.

### Ý tưởng chính

Áp dụng **Bổ đề Burnside** với nhóm quay $\mathbb{Z}_n = \{r_0, r_1, \ldots, r_{n-1}\}$:

$$\text{đáp án} = \frac{1}{n} \sum_{i=0}^{n-1} |X^{r_i}|$$

trong đó $|X^{r_i}|$ là số tô màu bất biến dưới phép quay $i$ vị trí.

**Đếm tô màu bất biến.** Phép quay $r_i$ ánh xạ vị trí $j$ sang $j + i \pmod{n}$, phân chia $n$ vị trí thành các chu kỳ. Mỗi chu kỳ có độ dài $n / \gcd(n, i)$, nên số chu kỳ là $\gcd(n, i)$. Các vị trí trong cùng chu kỳ phải cùng màu để bất biến:

$$|X^{r_i}| = m^{\gcd(n, i)}$$

*Chứng minh số chu kỳ.* Chu kỳ của vị trí $j$ có độ dài bằng $t$ nhỏ nhất sao cho $t \cdot i \equiv 0 \pmod{n}$, tức $t = n/\gcd(n,i)$. Các chu kỳ đều dài bằng nhau, nên số chu kỳ là $n/(n/\gcd(n,i)) = \gcd(n,i)$.

**Công thức đóng:**

$$\text{đáp án} = \frac{1}{n} \sum_{i=0}^{n-1} m^{\gcd(n, i)}$$

**Tối ưu bằng hàm Euler.** Nhóm các số hạng theo $d = \gcd(n, i)$. Với $d \mid n$, số $i \in [0, n{-}1]$ có $\gcd(n, i) = d$ là $\varphi(n/d)$:

$$\text{đáp án} = \frac{1}{n} \sum_{d \mid n} \varphi(n/d) \cdot m^d$$

Với $n \le 10^6$, lặp trực tiếp $O(n \log n)$ đã đủ. Phép chia cho $n$ dùng nghịch đảo modulo: $n^{-1} \equiv n^{p-2} \pmod{10^9+7}$.

### Thuật toán

1. Với $i = 0$ đến $n-1$: cộng dồn $m^{\gcd(n,i)} \bmod (10^9{+}7)$.
2. Nhân tổng với $n^{-1} \bmod (10^9{+}7)$.

### Ví dụ minh họa

$n = 4$, $m = 3$:

| $i$ | $\gcd(4, i)$ | $m^{\gcd(4,i)}$ |
|:---:|:---:|:---:|
| 0 | 4 | $3^4 = 81$ |
| 1 | 1 | $3^1 = 3$ |
| 2 | 2 | $3^2 = 9$ |
| 3 | 1 | $3^1 = 3$ |

Đáp án $= (81 + 3 + 9 + 3)/4 = 96/4 = 24$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — $n$ bước lặp, mỗi bước tính $\gcd$ và lũy thừa modular
- **Bộ nhớ:** $O(1)$
