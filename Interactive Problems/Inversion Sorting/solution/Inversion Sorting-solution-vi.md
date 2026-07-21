# Sắp xếp theo nghịch thế - Lời giải

**ID:** 3140 | **URL:** https://cses.fi/problemset/task/3140

## Phương pháp

### Tóm tắt bài toán

Có một hoán vị ẩn $a_1, a_2, \dots, a_n$ của các số nguyên $1, 2, \dots, n$. Trên mỗi lượt, bạn đảo ngược một mảng con $[i, j]$ và nhận được số nghịch thế hiện tại. Nếu số nghịch thế bằng 0, bạn thắng. Tối đa $4n$ phép toán.

### Ý tưởng chính

**Chiến lược:** Xác định hoán vị ẩn trước, rồi sắp xếp nó sau.

Gọi $inv[i]$ là số nghịch thế trong tiền tố $a[1 \ldots i]$, tức số cặp $(p, q)$ với $1 \le p < q \le i$ và $a_p > a_q$. Ta tính $inv[i]$ với mọi $i$, tái tạo hoán vị, rồi sắp xếp.

**Suy ra $inv[i]$:** Đảo $[1, i]$ hai lần. Gọi `pre` là số nghịch thế sau lần đảo đầu, `cur` sau lần đảo thứ hai (hoàn tác).

Khi đảo $[1, i]$, tổng số nghịch thế phân thành ba phần:
- **Trong** $[1, i]$: thay đổi từ $inv[i]$ sang $\binom{i}{2} - inv[i]$ (đảo ngược làm lật mọi cặp).
- **Trong** $[i+1, n]$: không đổi (gọi là $out$).
- **Giao thoa** (một đầu trong $[1, i]$, một đầu trong $[i+1, n]$): **cũng không đổi**, vì tập giá trị trong $[1, i]$ được bảo toàn — chỉ thứ tự thay đổi, nên với mỗi phần tử cố định trong $[i+1, n]$, số phần tử trong $[1, i]$ lớn hơn nó không đổi.

Gọi $cross$ là số giao thoa (không đổi). Khi đó:

$$pre = \left(\binom{i}{2} - inv[i]\right) + out + cross, \quad cur = inv[i] + out + cross$$

Lấy hiệu: $cur - pre = 2 \cdot inv[i] - \binom{i}{2}$, suy ra:

$$inv[i] = \frac{cur - pre + \binom{i}{2}}{2}$$

### Thuật toán

**Giai đoạn 1 — Tính số nghịch thế tiền tố:** Với mỗi $i$ từ 2 đến $n$, đảo $[1, i]$ (được `pre`), rồi đảo lại $[1, i]$ (được `cur`). Tính $inv[i]$ theo công thức. Nếu bất kỳ lúc nào số nghịch thế bằng 0 thì dừng ngay. Tổng: $2(n-1)$ phép toán.

**Giai đoạn 2 — Tái tạo hoán vị:** Với mỗi giá trị $v$ từ 1 đến $n$, tìm vị trí $pos$ sao cho $a[pos] = v$. Tại vị trí $i$ chưa gán, số phần tử trước $i$ lớn hơn $v$ là $inv[i] - inv[i-1]$, số vị trí trước $i$ đã gán giá trị nhỏ hơn $v$ là $\text{cnt}$. Điều kiện $a[i] = v$ tương đương:

$$inv[i] - inv[i-1] + \text{cnt} = i - 1$$

Chọn vị trí **cuối cùng** thỏa mãn (giá trị nhỏ hơn chiếm vị trí trước). Tổng: $O(n^2)$, không tốn truy vấn.

**Giai đoạn 3 — Sắp xếp bằng selection sort với đảo đoạn:** Với mỗi $i$ từ 1 đến $n$, tìm phần tử nhỏ nhất trong $a[i \ldots n]$, gọi vị trí là $pos$. Đảo $[i, pos]$ để đưa nó về vị trí $i$. Nếu số nghịch thế bằng 0 thì dừng. Tổng: tối đa $n - 1$ phép toán.

**Tổng số phép toán:** $2(n-1) + (n-1) = 3n - 3 < 4n$.

### Ví dụ minh họa

$n = 3$, hoán vị ẩn $[3, 1, 2]$ (trùng ví dụ đề bài):

**Giai đoạn 1:** $inv[1] = 0$.

- $i = 2$: Đảo $[1, 2]$ → $[1, 3, 2]$, $pre = 1$. Đảo lại $[1, 2]$ → $[3, 1, 2]$, $cur = 2$. $inv[2] = (2 - 1 + 1) / 2 = 1$.
- $i = 3$: Đảo $[1, 3]$ → $[2, 1, 3]$, $pre = 1$. Đảo lại $[1, 3]$ → $[3, 1, 2]$, $cur = 2$. $inv[3] = (2 - 1 + 3) / 2 = 2$.

**Giai đoạn 2:** $inv = [0, 1, 2]$. Tái tạo:

- $v = 1$: $i=1$: $0 - 0 + 0 = 0 = 0$ ✓. $i=2$: $1 - 0 + 0 = 1 = 1$ ✓. $i=3$: $2 - 1 + 0 = 1 \neq 2$. Vị trí cuối: $pos = 2$. $a[2] = 1$.
- $v = 2$: $i=1$: $0 - 0 + 0 = 0 = 0$ ✓. $i=3$: $2 - 1 + 1 = 2 = 2$ ✓. Vị trí cuối: $pos = 3$. $a[3] = 2$.
- $v = 3$: $i=1$: $0 - 0 + 0 = 0 = 0$ ✓. Vị trí cuối: $pos = 1$. $a[1] = 3$.

Kết quả: $a = [3, 1, 2]$. ✓

**Giai đoạn 3:** Sắp xếp $[3, 1, 2]$:

- $i = 1$: min trong $[1, 3]$ là 1 tại $pos = 2$. Đảo $[1, 2]$ → $[1, 3, 2]$, nghịch thế $= 1$.
- $i = 2$: min trong $[2, 3]$ là 2 tại $pos = 3$. Đảo $[2, 3]$ → $[1, 2, 3]$, nghịch thế $= 0$. Xong!

## Độ phức tạp

- **Thời gian:** $O(n^2)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Inversion%20Sorting.cpp)
