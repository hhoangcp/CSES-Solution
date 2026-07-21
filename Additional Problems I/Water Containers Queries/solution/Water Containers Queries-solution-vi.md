# Water Containers Queries - Lời giải

**ID:** 3214 | **URL:** https://cses.fi/problemset/task/3214

## Đề bài

Với nhiều truy vấn, xác định có thể đo $x$ đơn vị nước trong bình $A$ bằng hai bình dung tích $a$ và $b$ hay không.

## Hướng tiếp cận

### Định lý Bezout

Lượng nước $x$ trong bình $A$ đạt được khi và chỉ khi $0 \leq x \leq a$ và $\gcd(a, b) \mid x$.

**Điều kiện cần:** Mọi thao tác (FILL, EMPTY, MOVE) thay đổi $u_a$ một lượng là bội của $\gcd(a, b)$ (vì $a, b$ là bội của $d = \gcd(a, b)$, quy nạp được $u_a, u_b$ luôn là bội của $d$). Vậy $u_a$ đạt được phải là bội của $d$.

**Điều kiện đủ:** Lặp lại FILL A → MOVE A→B → EMPTY B mô phỏng thuật toán Euclid, tạo mọi bội của $d$ trong bình $A$.

### Thuật toán

Với mỗi truy vấn $(a, b, x)$:
- Nếu $x > a$: `NO`.
- Ngược lại nếu $x \mod \gcd(a, b) = 0$: `YES`.
- Ngược lại: `NO`.

### Ví dụ

| $a$ | $b$ | $x$ | $\gcd(a,b)$ | $x \leq a$? | $x \mod g = 0$? | Kết quả |
|-----|-----|-----|-------------|-------------|-----------------|---------|
| 5 | 3 | 4 | 1 | ✓ | ✓ | YES |
| 1 | 1 | 2 | 1 | ✗ | — | NO |
| 2 | 2 | 1 | 2 | ✓ | ✗ | NO |
| 123 | 456 | 42 | 3 | ✓ | ✓ | YES |

## Độ phức tạp

- **Thời gian:** $O(\log(\min(a, b)))$ mỗi truy vấn cho GCD
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Water%20Containers%20Queries.cpp)
