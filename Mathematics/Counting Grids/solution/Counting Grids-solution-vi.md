# Counting Grids - Lời giải

**ID:** 2210 | **URL:** https://cses.fi/problemset/task/2210

## Phương pháp

### Tóm tắt bài toán

Đếm số lưới $n \times n$ phân biệt ($1 \le n \le 10^9$), mỗi ô màu đen hoặc trắng, xét đến phép quay. Hai lưới giống nhau nếu có thể quay một lưới để được lưới kia. Kết quả lấy modulo $10^9+7$.

### Ý tưởng chính

Áp dụng **Bổ đề Burnside** với nhóm quay $C_4 = \{0°, 90°, 180°, 270°\}$:

$$\text{đáp án} = \frac{1}{4} \sum_{g \in C_4} |X^g|$$

trong đó $|X^g|$ là số lưới bất biến dưới phép quay $g$. Mỗi phép quay phân chia các ô thành **quỹ đạo**; các ô trong cùng quỹ đạo phải cùng màu để lưới bất biến, nên $|X^g| = 2^{\text{số quỹ đạo}}$.

**Quay $0°$:** Mỗi ô là quỹ đạo riêng. $|X^{0°}| = 2^{n^2}$.

**Quay $90°$ và $270°$:** Ô $(r,c)$ ánh xạ sang $(c, n{+}1{-}r)$, tạo quỹ đạo kích thước 4 (trừ ô trung tâm khi $n$ lẻ, quỹ đạo kích thước 1). Số quỹ đạo $= \lceil n^2/4 \rceil$. Vì $90°$ và $270°$ có cùng cấu trúc quỹ đạo: $|X^{90°}| = |X^{270°}| = 2^{\lceil n^2/4 \rceil}$.

**Quay $180°$:** Ô $(r,c)$ ánh xạ sang $(n{+}1{-}r, n{+}1{-}c)$, tạo quỹ đạo kích thước 2 (trừ ô trung tâm khi $n$ lẻ). Số quỹ đạo $= \lceil n^2/2 \rceil$. $|X^{180°}| = 2^{\lceil n^2/2 \rceil}$.

**Công thức đóng:**

$$\text{đáp án} = \frac{2^{n^2} + 2 \cdot 2^{\lceil n^2/4 \rceil} + 2^{\lceil n^2/2 \rceil}}{4} \pmod{10^9+7}$$

**Số học modulo.** Vì $n \le 10^9$, số mũ đạt $10^{18}$. Giảm số mũ modulo $\phi(10^9{+}7) = 10^9{+}6$ trước khi tính $2^E \bmod (10^9{+}7)$ (định lý Fermat nhỏ). Phép chia cho 4 dùng nghịch đảo modulo $4^{-1} \equiv 250000002 \pmod{10^9+7}$.

### Thuật toán

1. Tính $e_1 = n^2 \bmod (10^9{+}6)$, $e_2 = \lceil n^2/4 \rceil \bmod (10^9{+}6)$, $e_3 = \lceil n^2/2 \rceil \bmod (10^9{+}6)$.
2. Tính $v_1 = 2^{e_1}$, $v_2 = 2^{e_2}$, $v_3 = 2^{e_3}$, đều modulo $10^9{+}7$.
3. Xuất $(v_1 + 2 \cdot v_2 + v_3) \cdot 250000002 \bmod (10^9{+}7)$.

### Ví dụ minh họa

$n = 4$:
- $|X^{0°}| = 2^{16} = 65536$
- $|X^{90°}| = |X^{270°}| = 2^{4} = 16$
- $|X^{180°}| = 2^{8} = 256$
- Đáp án $= (65536 + 32 + 256)/4 = 65824/4 = 16456$

## Độ phức tạp

- **Thời gian:** $O(\log n)$ — lũy thừa modular
- **Bộ nhớ:** $O(1)$
