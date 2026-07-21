# Exponentiation - Lời giải

**ID:** 1095 | **URL:** https://cses.fi/problemset/task/1095

## Phương pháp

### Tóm tắt bài toán

Tính $a^b \bmod (10^9+7)$ cho $n$ truy vấn ($1 \le n \le 2 \cdot 10^5$, $0 \le a, b \le 10^9$), với quy ước $0^0 = 1$.

### Ý tưởng chính

Với $b$ lên tới $10^9$, cách nhân tuyến tính $O(b)$ mỗi truy vấn không khả thi. Dùng **lũy thừa nhị phân**: phân rã $b$ sang hệ nhị phân và tận dụng:

$$a^b = a^{b_0 \cdot 2^0 + b_1 \cdot 2^1 + \cdots + b_k \cdot 2^k} = \prod_{i: b_i = 1} a^{2^i}$$

Tương đương, chia để trị:

$$a^b = \begin{cases} 1 & b = 0 \\ (a^{b/2})^2 & b \text{ chẵn} \\ (a^{(b-1)/2})^2 \cdot a & b \text{ lẻ} \end{cases}$$

Mỗi bước giảm $b$ đi một nửa, chỉ cần $O(\log b)$ phép nhân.

*Tính đúng đắn (quy nạp theo $b$).* Cơ sở: $b = 0$ trả về 1. Bước: với $b = 2k$, theo giả thiết quy nạp bài toán con trả $a^k$, bình phương được $a^{2k} = a^b$. Với $b = 2k+1$, bình phương $a^k$ rồi nhân $a$ được $a^{2k+1} = a^b$.

**Trường hợp đặc biệt.** $0^0 = 1$ theo quy ước (do $b = 0$ trả về 1). $0^b = 0$ với $b > 0$ (xử lý tự nhiên). Mọi phép nhân đều lấy modulo sau mỗi bước để chống tràn: với $p < 2^{30}$, tích hai số dư vừa đủ trong số nguyên 64-bit.

### Thuật toán

1. Với mỗi truy vấn $(a, b)$: tính $a^b \bmod p$ bằng lũy thừa nhị phân lặp.
2. Duy trì biến kết quả (ban đầu 1) và cơ số dồn (ban đầu $a$). Khi $b > 0$: nếu $b$ lẻ, nhân kết quả với cơ số; bình phương cơ số; chia $b$ cho 2.

### Ví dụ minh họa

$3^{13}$: hệ nhị phân $13 = 1101_2 = 8 + 4 + 1$.

| Bước | $b$ | Cơ số dồn | Kết quả |
|:---:|:---:|:---:|:---:|
| 0 | 13 (lẻ) | $3^1 = 3$ | $1 \cdot 3 = 3$ |
| 1 | 6 (chẵn) | $3^2 = 9$ | 3 |
| 2 | 3 (lẻ) | $3^4 = 81$ | $3 \cdot 81 = 243$ |
| 3 | 1 (lẻ) | $3^8 = 6561$ | $243 \cdot 6561 = 1594323$ |

$3^{13} = 1594323$.

## Độ phức tạp

- **Thời gian:** $O(n \log b_{\max})$ — $O(\log b)$ mỗi truy vấn
- **Bộ nhớ:** $O(1)$ — phiên bản lặp
