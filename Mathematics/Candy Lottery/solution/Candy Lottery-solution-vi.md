# Candy Lottery - Lời giải

**ID:** 1727 | **URL:** https://cses.fi/problemset/task/1727

## Phương pháp

### Tóm tắt bài toán

Có $n$ đứa trẻ, mỗi đứa độc lập nhận một số nguyên ngẫu nhiên kẹo từ $1$ đến $k$. Tính kỳ vọng giá trị lớn nhất số kẹo mà một đứa trẻ nhận được, làm tròn đến 6 chữ số thập phân (làm tròn nửa về số chẵn).

### Ý tưởng chính

Gọi $X_1, X_2, \ldots, X_n$ là số kẹo mỗi đứa nhận, các biến độc lập và đều phân phối uniform trên $\{1, 2, \ldots, k\}$. Cần tính $E[\max(X_1, \ldots, X_n)]$.

**Phương pháp CDF.** Sự kiện $\max \leq i$ tương đương mọi $X_j \leq i$. Do tính độc lập:

$$P(\max \leq i) = \left(\frac{i}{k}\right)^n$$

Xác suất chính xác $P(\max = i)$ được tính bằng hiệu hai CDF liên tiếp:

$$P(\max = i) = P(\max \leq i) - P(\max \leq i-1) = \left(\frac{i}{k}\right)^n - \left(\frac{i-1}{k}\right)^n$$

**Hai công thức tương đương.** Thay vào định nghĩa $E[\max] = \sum_{i=1}^{k} i \cdot P(\max = i)$:

$$E[\max] = \sum_{i=1}^{k} i \cdot \left[\left(\frac{i}{k}\right)^n - \left(\frac{i-1}{k}\right)^n\right]$$

Biến đổi bằng tổng từng phần (đặt $a_i = (i/k)^n$):

$$E[\max] = \sum_{i=1}^{k} i(a_i - a_{i-1}) = k \cdot a_k - \sum_{i=0}^{k-1} a_i = k - \sum_{i=1}^{k-1} \left(\frac{i}{k}\right)^n$$

### Thuật toán

1. Với $i = 1$ đến $k-1$: cộng dồn $\left(\frac{i}{k}\right)^n$.
2. Xuất $k - \text{tổng}$, làm tròn 6 chữ số thập phân.

### Ví dụ minh họa

$n = 2$, $k = 3$:

| $i$ | $P(\max \leq i)$ | $P(\max = i)$ |
|:---:|:---:|:---:|
| 1 | $1/9$ | $1/9$ |
| 2 | $4/9$ | $3/9$ |
| 3 | $1$ | $5/9$ |

$$E[\max] = 1 \cdot \frac{1}{9} + 2 \cdot \frac{3}{9} + 3 \cdot \frac{5}{9} = \frac{22}{9} \approx 2.444444$$

Kiểm tra bằng công thức rút gọn: $3 - (1/3)^2 - (2/3)^2 = 3 - \frac{1}{9} - \frac{4}{9} = \frac{22}{9} \approx 2.444444$.

## Độ phức tạp

- **Thời gian:** $O(nk)$ — lặp $k$ lần, mỗi lần tính lũy thừa bậc $n$
- **Bộ nhớ:** $O(1)$
