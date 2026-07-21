# Permutation Inversions - Lời giải

**ID:** 2229 | **URL:** https://cses.fi/problemset/task/2229

## Phương pháp

### Tóm tắt bài toán

Đếm số hoán vị của $\{1, \ldots, n\}$ có đúng $k$ nghịch thế. Kết quả modulo $10^9 + 7$.

### Hàm sinh

Xây dựng hoán vị bằng cách chèn lần lượt các phần tử $1, 2, \ldots, n$. Khi chèn phần tử $i$ vào hoán vị của $\{1, \ldots, i-1\}$, có $i$ vị trí. Chèn vào vị trí thứ $t$ từ phải sang (tính từ 0) tạo đúng $t$ nghịch thế mới. Nhân tử cho phần tử $i$:

$$\sum_{t=0}^{i-1} x^t = \frac{1 - x^i}{1 - x}$$

Hàm sinh cho tổng số nghịch thế:

$$I_n(x) = \prod_{i=1}^{n} \frac{1 - x^i}{1 - x} = \frac{P(x)}{(1-x)^n} \quad \text{với } P(x) = \prod_{i=1}^{n}(1-x^i)$$

### Phân tích thành tử và mẫu

**Mẫu:** $(1-x)^{-n} = \sum_{j \ge 0} \binom{n-1+j}{n-1} x^j$ (chuỗi nhị thức suy rộng).

**Tử:** $P(x) = \prod_{i=1}^{n}(1-x^i)$. Mỗi tập con $S \subseteq \{1, \ldots, n\}$ đóng góp $(-1)^{|S|} x^{\sum S}$. Hệ số $P_j$ đếm (có dấu xen) các tập con của $\{1, \ldots, n\}$ có tổng bằng $j$.

**Kết hợp:** $[x^k] I_n(x) = \sum_{i=0}^{k} P_i \cdot \binom{n-1+k-i}{n-1}$.

### Tính hệ số tử bằng QHD phân hoạch

$P_j = \sum_{m=0}^{\sqrt{2k}} (-1)^m \cdot dp[m][j]$, với $dp[m][j]$ = số tập con $m$ phần tử của $\{1, \ldots, n\}$ có tổng $j$. Giới hạn $m \le \sqrt{2k}$ vì $1 + 2 + \cdots + m = m(m+1)/2 \le k$.

Chuyển trạng thái QHD dùng cấu trúc "tăng dịch" của phân hoạch phân biệt:

$$dp[m][j] = dp[m][j-m] + dp[m-1][j-m]$$

- **$dp[m][j-m]$:** Lấy phân hoạch $m$ phần tử phân biệt tổng $j-m$, tăng mỗi phần tử lên 1 (tổng tăng $m$).
- **$dp[m-1][j-m]$:** Lấy phân hoạch $m{-}1$ phần tử phân biệt tổng $j-m$, tăng mỗi phần tử lên 1, thêm phần tử mới giá trị 1 (tổng tăng $m{-}1{+}1 = m$).

**Giới hạn trên $n$:** Sau khi tăng, nếu một phần tử vượt $n+1$, trừ $dp[m-1][j-(n+1)]$ để loại bỏ các trường hợp vi phạm.

### Tối ưu đối xứng

$I_n(k) = I_n\left(\binom{n}{2} - k\right)$: thay mỗi phần tử $\pi(i)$ bằng $n+1-\pi(i)$ đảo ngược mọi thứ tự tương đối, chuyển $k$ nghịch thế thành $\binom{n}{2} - k$. Thay $k$ bằng $\min\left(k, \binom{n}{2} - k\right)$ để giảm tính toán.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 4$, $k = 3$.

Các tập con của $\{1,2,3,4\}$ và đóng góp vào $P(x)$:

| Tổng $j$ | Tập con | $P_j$ |
|----------|---------|-------|
| 0 | $\emptyset$ | $+1$ |
| 1 | $\{1\}$ | $-1$ |
| 2 | $\{2\}$ | $-1$ |
| 3 | $\{3\},\{1,2\}$ | $-1+1=0$ |

$$\text{ans} = 1 \cdot \binom{6}{3} + (-1) \cdot \binom{5}{3} + (-1) \cdot \binom{4}{3} + 0 \cdot \binom{3}{3} = 20 - 10 - 4 = \mathbf{6}$$

6 hoán vị: $[1,4,3,2]$, $[2,3,4,1]$, $[2,4,1,3]$, $[3,1,4,2]$, $[3,2,1,4]$, $[4,1,2,3]$. ✓

## Độ phức tạp

- **Thời gian:** $O(k\sqrt{k})$ — QHD phân hoạch có $O(\sqrt{k})$ tầng, mỗi tầng xử lý $O(k)$ phần tử.
- **Bộ nhớ:** $O(k)$ — mảng cuộn cho các hàng QHD.

## Mã nguồn (C++)

[Mã nguồn](../code/Permutation%20Inversions.cpp)
