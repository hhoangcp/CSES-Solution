# Trailing Zeros - Lời giải

**ID:** 1618 | **URL:** https://cses.fi/problemset/task/1618

## Hướng tiếp cận

### Tóm tắt bài toán

Cho $n$ ($1 \le n \le 10^9$), tính số chữ số 0 ở cuối của $n!$.

### Ý tưởng chính

Mỗi chữ số 0 ở cuối tương ứng với một thừa số 10 trong $n!$. Vì $10 = 2 \times 5$, số chữ số 0 bằng $\min(v_2(n!), v_5(n!))$, với $v_p(n!)$ là số mũ của số nguyên tố $p$ trong phân tích $n!$.

**Tại sao $v_5$ là yếu tố quyết định.** Trong $\{1, \ldots, n\}$, bội số của 2 xuất hiện không ít hơn bội số của 5 ($\lfloor n/2 \rfloor \ge \lfloor n/5 \rfloor$), và tương tự cho mọi lũy thừa ($\lfloor n/2^k \rfloor \ge \lfloor n/5^k \rfloor$). Tổng tất cả cho $v_2(n!) \ge v_5(n!)$. Do đó, số chữ số 0 ở cuối chính là $v_5(n!)$.

**Tính $v_5(n!)$ theo công thức Legendre:**

$$v_p(n!) = \left\lfloor \frac{n}{p} \right\rfloor + \left\lfloor \frac{n}{p^2} \right\rfloor + \left\lfloor \frac{n}{p^3} \right\rfloor + \cdots$$

Số hạng $\lfloor n/p^k \rfloor$ đếm số nguyên trong $[1, n]$ chia hết cho $p^k$, mỗi số đóng góp thêm một thừa số $p$ so với các lũy thừa thấp hơn đã đếm. Một số chia hết cho $p^k$ được đếm đúng $k$ lần qua các số hạng $p^1, p^2, \ldots, p^k$, tương ứng với tổng đóng góp $k$ thừa số $p$.

### Thuật toán

Chọn $p = 5$. Lặp lại chia $n$ cho 5 và cộng dồn các thương cho đến khi $n = 0$:
1. Khởi tạo $\text{ans} = 0$.
2. Khi $n > 0$: đặt $n = \lfloor n/5 \rfloor$, rồi $\text{ans} \mathrel{+}= n$.
3. Xuất $\text{ans}$.

Vòng lặp tính đúng $\lfloor n/5 \rfloor + \lfloor n/25 \rfloor + \cdots = v_5(n!)$.

### Ví dụ minh họa

**Ví dụ đề bài ($n = 20$):** $\lfloor 20/5 \rfloor = 4$, $\lfloor 20/25 \rfloor = 0$. Kết quả: 4.

$20! = 2432902008176640000$ có đúng 4 chữ số 0 ở cuối. ✓

**Ví dụ bổ sung ($n = 125$):** $25 + 5 + 1 = 31$. Số $125 = 5^3$ đóng góp 3 thừa số 5 qua ba vòng lặp.

## Độ phức tạp

- **Thời gian:** $O(\log_5 n)$ — tối đa 13 vòng lặp với $n \le 10^9$
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Trailing%20Zeros.cpp)
