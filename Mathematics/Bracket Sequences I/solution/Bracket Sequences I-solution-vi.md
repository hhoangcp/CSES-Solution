# Bracket Sequences I - Lời giải

**ID:** 2064 | **URL:** https://cses.fi/problemset/task/2064

## Phương pháp

### Tóm tắt bài toán

Đếm số dãy ngoặc hợp lệ độ dài $n$ ($1 \le n \le 10^6$), kết quả lấy modulo $10^9+7$. Dãy ngoặc hợp lệ là dãy mà tại mọi vị trí tiền tố, số ngoặc mở $\geq$ số ngoặc đóng, và tổng số ngoặc mở bằng đóng.

### Ý tưởng chính

Nếu $n$ lẻ, đáp án là $0$. Nếu $n = 2k$, đáp án là **số Catalan thứ $k$**:

$$C_k = \frac{1}{k+1}\binom{2k}{k} = \frac{(2k)!}{k! \cdot (k+1)!}$$

**Chứng minh (Nguyên lý phản xạ André).** Tổng số dãy gồm $k$ ngoặc mở và $k$ ngoặc đóng là $\binom{2k}{k}$. Để đếm các dãy không hợp lệ, với mỗi dãy không hợp lệ gọi $p$ là vị trí đầu tiên mà số ngoặc đóng vượt quá số ngoặc mở. Tại vị trí $p$, có $m$ ngoặc mở và $m+1$ ngoặc đóng. Đảo tất cả ngoặc từ vị trí $p$ trở đi (mở $\leftrightarrow$ đóng), dãy mới có $k-1$ ngoặc mở và $k+1$ ngoặc đóng. Đây là song ánh giữa các dãy không hợp lệ và tất cả dãy có $k-1$ mở, $k+1$ đóng, nên số dãy không hợp lệ là $\binom{2k}{k-1}$.

$$C_k = \binom{2k}{k} - \binom{2k}{k-1} = \frac{(2k)!}{k! \cdot k!} \cdot \left(1 - \frac{k}{k+1}\right) = \frac{1}{k+1}\binom{2k}{k}$$

**Tính modulo.** Với $p = 10^9+7$ nguyên tố, tính trước giai thừa $fact[i] = i! \bmod p$ và nghịch đảo giai thừa $inv\_f[i] = (i!)^{-1} \bmod p$ tới $n$. Khi đó:

$$C_k = fact[n] \cdot inv\_f[k] \cdot inv\_f[k+1] \bmod p$$

### Thuật toán

1. Nếu $n$ lẻ, xuất $0$.
2. Ngược lại, đặt $k = n/2$. Xuất $fact[n] \cdot inv\_f[k] \cdot inv\_f[k+1] \bmod p$.

### Ví dụ minh họa

$n = 6$ ($k = 3$): $C_3 = \frac{1}{4}\binom{6}{3} = \frac{20}{4} = 5$. 5 dãy hợp lệ: `((()))`, `(()())`, `(())()`, `()(())`, `()()()`.

## Độ phức tạp

- **Thời gian:** $O(n)$ — tiền xử lý giai thừa và nghịch đảo giai thừa
- **Bộ nhớ:** $O(n)$
