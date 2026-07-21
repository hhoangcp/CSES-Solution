# Bouncing Ball Cycle - Lời giải

**ID:** 3216 | **URL:** https://cses.fi/problemset/task/3216

## Đề bài

Quả bóng ở góc trên trái lưới $n \times m$, di chuyển chéo, nảy khi chạm biên. Sau bao nhiêu bước bóng quay lại vị trí ban đầu? Số ô phân biệt đã đi qua?

## Hướng tiếp cận

### Tọa độ độc lập

Hàng và cột tiến triển độc lập. Hàng theo mẫu răng cưa: $1, 2, \ldots, n, n-1, \ldots, 2, 1, \ldots$ chu kỳ $2N$ với $N = n - 1$. Cột chu kỳ $2M$ với $M = m - 1$.

### Số bước quay lại

Bóng quay về $(1,1)$ khi cả hai tọa độ đồng thời quay về 1: $\text{lcm}(2N, 2M) = 2 \cdot \text{lcm}(N, M)$. Với $g = \gcd(N, M)$, $N' = N/g$, $M' = M/g$:

$$\text{steps} = 2 \cdot N' \cdot M$$

### Số ô phân biệt

Trong một chu kỳ đầy đủ, mỗi ô được thăm đúng $g$ lần (ở các thời điểm khác nhau). Sau khi xét đối xứng phản xạ (vị trí $r$ và $2N' - r$ cho cùng hàng vật lý, tương tự cột), số ô phân biệt là:

$$\text{distinct} = \frac{N' \cdot M' \cdot (2g - 1) + N' + M' + 1}{2}$$

**Lưu ý cài đặt:** Với $n, m \le 10^9$, tích trung gian $N' \cdot M' \cdot (2g - 1)$ có thể vượt `long long`. Dùng `__int128` cho tính trung gian.

### Ví dụ

$n = 3, m = 4$: $N = 2, M = 3, g = 1, N' = 2, M' = 3$.

- Bước = $2 \cdot 2 \cdot 3 = 12$
- Ô phân biệt = $(2 \cdot 3 \cdot 1 + 2 + 3 + 1) / 2 = 6$

Kết quả: `12 6`.

## Độ phức tạp

- **Thời gian:** $O(\log(\min(n, m)))$ mỗi test cho GCD
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Bouncing%20Ball%20Cycle.cpp)
