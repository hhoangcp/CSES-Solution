# Bouncing Ball Steps - Lời giải

**ID:** 3215 | **URL:** https://cses.fi/problemset/task/3215

## Đề bài

Quả bóng ở góc trên trái lưới $n \times m$, di chuyển chéo, nảy khi chạm biên. Vị trí của bóng sau $k$ bước là gì? Đổi hướng bao nhiêu lần?

## Hướng tiếp cận

### Vị trí sau $k$ bước

Hàng và cột tiến triển độc lập (chuyển động chéo đổi cả hai đúng $\pm 1$ mỗi bước, mỗi thành phần đổi hướng riêng khi chạm biên tương ứng).

Với chiều dài $L$ (hàng: $L = n$, cột: $L = m$), tọa độ theo răng cưa chu kỳ $2(L-1)$. Tính $r = k \bmod 2(L-1)$:

- Nếu $r \leq L - 1$: vị trí $= 1 + r$ (đang đi về biên).
- Nếu $r > L - 1$: vị trí $= 2L - 1 - r$ (đang nảy ngược).

### Số lần đổi hướng

Bóng nảy khi chạm biên hàng (mỗi $n-1$ bước) hoặc biên cột (mỗi $m-1$ bước). Chạm góc tính là 1 lần (không 2), nên dùng bao hàm-loại trừ:

$$\text{nảy} = \left\lfloor \frac{k}{n-1} \right\rfloor + \left\lfloor \frac{k}{m-1} \right\rfloor - \left\lfloor \frac{k}{\text{lcm}(n-1, m-1)} \right\rfloor$$

**Lưu ý cài đặt:** Tính $\text{lcm}(n-1, m-1) = (n-1)(m-1) / \gcd(n-1, m-1)$ cần `__int128` cho tích trung gian khi $n, m \leq 10^9$.

### Ví dụ

$n = 3, m = 4, k = 3$:

- Hàng: $r = 3 \bmod 4 = 3$. $3 > 2$, vị trí $= 2 \cdot 3 - 1 - 3 = 2$.
- Cột: $r = 3 \bmod 6 = 3$. $3 \leq 3$, vị trí $= 1 + 3 = 4$.
- Nảy: $\lfloor 3/2 \rfloor + \lfloor 3/3 \rfloor - \lfloor 3/6 \rfloor = 1 + 1 - 0 = 2$.

Kết quả: `2 4 2`.

## Độ phức tạp

- **Thời gian:** $O(\log(\min(n, m)))$ mỗi truy vấn cho GCD
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Bouncing%20Ball%20Steps.cpp)
