# Counting Divisors - Lời giải

**ID:** 1713 | **URL:** https://cses.fi/problemset/task/1713

## Phương pháp

### Tóm tắt bài toán

Cho $n$ số nguyên dương ($1 \le n \le 10^5$, $1 \le x \le 10^6$), với mỗi số $x$, hãy đếm số ước nguyên dương của nó.

### Ý tưởng chính

Cách thông thường duyệt đến $\sqrt{x}$ mỗi truy vấn, nhưng $O(n\sqrt{\max x}) \approx 10^8$ có thể vượt thời gian. Thay vào đó, **tính trước** số ước cho tất cả các số tới $M = 10^6$ bằng sàng Dirichlet.

Nguyên lý: nếu $i$ là ước của $j$, thì $j$ là bội của $i$. Do đó, với mỗi $i$, tăng $\text{DIV}[j]$ lên 1 cho mọi bội $j = i, 2i, 3i, \ldots, M$. Mỗi lần tăng tại $\text{DIV}[j]$ tương ứng với việc phát hiện $i$ là ước của $j$. Sau khi duyệt hết tất cả $i$, $\text{DIV}[j]$ chính bằng số ước nguyên dương của $j$.

**Tính đúng đắn.** Tồn tại song ánh giữa các lần tăng $\text{DIV}[j]$ và các ước của $j$: mọi ước $d$ của $j$ gây đúng một lần tăng (khi $i = d$), và mọi lần tăng tại $i = d$ kéo theo $d \mid j$. Vậy phép đếm hoàn toàn chính xác.

Tổng số bước lặp tuân theo **chuỗi điều hòa**:

$$\sum_{i=1}^{M} \left\lfloor \frac{M}{i} \right\rfloor \approx M \ln M$$

### Thuật toán

1. Khởi tạo mảng $\text{DIV}[1 \ldots M]$ bằng 0.
2. Với $i = 1$ đến $M$: với mỗi bội $j = i, 2i, 3i, \ldots, M$: tăng $\text{DIV}[j]$ lên 1.
3. Với mỗi truy vấn $x$: xuất $\text{DIV}[x]$.

### Ví dụ minh họa

**Test 1:** $x = 16$. Ước: $\{1, 2, 4, 8, 16\}$, $\text{DIV}[16] = 5$.

**Test 2:** $x = 17$. Ước: $\{1, 17\}$, $\text{DIV}[17] = 2$.

**Test 3:** $x = 18$. Ước: $\{1, 2, 3, 6, 9, 18\}$, $\text{DIV}[18] = 6$.

## Độ phức tạp

- **Thời gian:** $O(M \log M)$ tiền xử lý + $O(1)$ mỗi truy vấn, với $M = 10^6$
- **Bộ nhớ:** $O(M)$
