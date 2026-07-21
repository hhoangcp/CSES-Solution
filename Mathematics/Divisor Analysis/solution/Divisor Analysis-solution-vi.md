# Divisor Analysis - Lời giải

**ID:** 2182 | **URL:** https://cses.fi/problemset/task/2182

## Phương pháp

### Tóm tắt bài toán

Cho $n = x_1^{k_1} \cdot x_2^{k_2} \cdots x_m^{k_m}$ dưới dạng phân tích thừa số nguyên tố. Tính: (1) số ước, (2) tổng các ước, (3) tích các ước, tất cả modulo $10^9+7$.

### Ý tưởng chính

**Số lượng ước.** Mỗi ước có dạng $x_1^{e_1} \cdots x_m^{e_m}$ với $0 \le e_i \le k_i$, cho $k_i+1$ lựa chọn độc lập cho mỗi thừa số:

$$d(n) = \prod_{i=1}^{m}(k_i + 1) \pmod{10^9+7}$$

**Tổng các ước.** Do tính nhân của hàm tổng ước, từng thừa số $x_i^{k_i}$ đóng góp một cấp số nhân:

$$\sigma(n) = \prod_{i=1}^{m} \frac{x_i^{k_i+1} - 1}{x_i - 1} \pmod{10^9+7}$$

Phép chia cho $x_i - 1$ dùng nghịch đảo modulo ($x_i \ge 2$ là số nguyên tố nên $x_i - 1 \ge 1$).

**Tích các ước.** Gọi $D = d(n)$. Các ước xuất hiện thành cặp $(d, n/d)$ có tích $n$, nên tích tất cả ước là $n^{D/2}$. Cụ thể: nếu $D$ chẵn, có $D/2$ cặp mỗi cặp tích $n$; nếu $D$ lẻ, ước giữa là $\sqrt{n}$ và tích bằng $n^{(D-1)/2} \cdot \sqrt{n} = n^{D/2}$.

**Tính $n^{D/2} \bmod p$.** Thay vì tính trực tiếp $n^{D/2}$ (với $D/2$ có thể không nguyên), tính đóng góp số mũ của từng $x_i$. Tổng số mũ của $x_i$ trong tất cả $D$ ước là:

$$e_i = \frac{k_i(k_i+1)}{2} \cdot \frac{D}{k_i+1} = \frac{k_i \cdot D}{2}$$

*Chứng minh.* Có $D/(k_i+1)$ ước có mũ $j$ của $x_i$, với mỗi $j = 0, \ldots, k_i$. Tổng: $\frac{D}{k_i+1} \cdot \sum_{j=0}^{k_i} j = \frac{D}{k_i+1} \cdot \frac{k_i(k_i+1)}{2} = \frac{k_i \cdot D}{2}$.

Để tính $\frac{D}{k_i+1} = \prod_{j \ne i}(k_j+1)$ modulo $\phi(p) = 10^9+6$, dùng mảng tích tiền tố/hậu tố của $(k_j+1)$. Tích các ước là:

$$\prod_{i=1}^{m} x_i^{e_i} \pmod{p}$$

với $e_i = \frac{k_i(k_i+1)}{2} \cdot \prod_{j \ne i}(k_j+1) \bmod \phi(p)$.

### Thuật toán

1. Tính $D = \prod (k_i+1) \bmod p$.
2. Xây mảng tích tiền tố/hậu tố của $(k_i+1)$ modulo $\phi(p)$.
3. Với mỗi $i$: tính $e_i = \frac{k_i(k_i+1)}{2} \cdot \text{Pre}[i{-}1] \cdot \text{Suf}[i{+}1] \bmod \phi(p)$, rồi nhân $x_i^{e_i} \bmod p$.
4. Tính tổng ước bằng công thức cấp số nhân với nghịch đảo modulo.

### Ví dụ minh họa

$n = 12 = 2^2 \cdot 3^1$:

- Số ước: $(2+1)(1+1) = 6$
- Tổng ước: $\frac{2^3-1}{2-1} \cdot \frac{3^2-1}{3-1} = 7 \cdot 4 = 28$
- Tích ước: $e_1 = \frac{2 \cdot 3}{2} \cdot 2 = 6$, $e_2 = \frac{1 \cdot 2}{2} \cdot 3 = 3$ → $2^6 \cdot 3^3 = 64 \cdot 27 = 1728$

## Độ phức tạp

- **Thời gian:** $O(m \log k_{\max})$ — lũy thừa modular cho mỗi thừa số
- **Bộ nhớ:** $O(m)$ — mảng tiền tố/hậu tố
