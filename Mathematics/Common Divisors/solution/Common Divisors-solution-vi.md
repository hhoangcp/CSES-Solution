# Common Divisors - Lời giải

**ID:** 1081 | **URL:** https://cses.fi/problemset/task/1081

## Phương pháp

### Tóm tắt bài toán

Cho $n$ số nguyên dương $x_1, x_2, \ldots, x_n$ ($n \leq 2 \cdot 10^5$, $x_i \leq 10^6$). Tìm $\max_{i \neq j} \gcd(x_i, x_j)$.

### Ý tưởng chính

Thay vì kiểm tra tất cả $O(n^2)$ cặp, đảo ngược góc nhìn: với mỗi giá trị $d$, hỏi "có bao nhiêu phần tử chia hết cho $d$?". Nếu có ít nhất 2 phần tử chia hết cho $d$, tồn tại cặp có $\gcd \geq d$. Giá trị $d$ lớn nhất thỏa mãn chính là đáp án.

**Tính đúng đắn.** Gọi $d^* = \max\{d : N(d) \geq 2\}$. Nếu cặp tối ưu có $\gcd = g$, cả hai phần tử đều chia hết cho $g$, nên $N(g) \geq 2$ và $d^* \geq g$. Ngược lại, vì $N(d^*) \geq 2$, tồn tại hai phần tử $x_i, x_j$ chia hết cho $d^*$, nên $\gcd(x_i, x_j) \geq d^*$. Vậy $d^* = \max_{i \neq j} \gcd(x_i, x_j)$.

**Đếm bội.** Xây mảng tần số $\text{cnt}[v]$. Với mỗi $d$, số phần tử chia hết cho $d$ là:

$$N(d) = \sum_{k=1}^{\lfloor M/d \rfloor} \text{cnt}[k \cdot d]$$

với $M = 10^6$. Duyệt $d$ từ $M$ xuống $1$; giá trị $d$ đầu tiên có $N(d) \geq 2$ chính là đáp án.

### Thuật toán

1. Xây mảng tần số $\text{cnt}[v]$ từ mảng đầu vào.
2. Với $d = M$ xuống $1$: tính $N(d)$ bằng cách cộng $\text{cnt}[k \cdot d]$ cho mọi bội $k \cdot d \leq M$.
3. Giá trị $d$ đầu tiên có $N(d) \geq 2$ là đáp án.

### Ví dụ minh họa

Mảng $[3, 14, 15, 7, 9]$:

| $d$ | Bội của $d$ trong mảng | $N(d)$ | $\geq 2$? |
|:---:|:---:|:---:|:---:|
| 15 | $\{15\}$ | 1 | Không |
| 14 | $\{14\}$ | 1 | Không |
| 9 | $\{9\}$ | 1 | Không |
| 7 | $\{7, 14\}$ | 2 | **Có** |

$d = 7$ là giá trị đầu tiên có $N(d) \geq 2$. Thật vậy, $\gcd(14, 7) = 7$ là GCD lớn nhất.

## Độ phức tạp

- **Thời gian:** $O(n + M \log M)$ — mảng tần số $O(n)$, sàng $O(M \log M)$ theo chuỗi điều hòa
- **Bộ nhớ:** $O(M)$
