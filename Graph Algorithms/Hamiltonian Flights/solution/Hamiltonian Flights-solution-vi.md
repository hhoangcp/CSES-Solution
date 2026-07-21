# Chuyến Bay Hamiltonian - Lời giải

**ID:** 1690 | **URL:** https://cses.fi/problemset/task/1690

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ thành phố, $m$ chuyến bay một chiều. Đếm số đường đi Hamilton từ thành phố 1 đến thành phố $n$ (đường đi thăm mỗi thành phố đúng 1 lần). Kết quả lấy modulo $10^9 + 7$.

### Ý tưởng chính

Với $n \le 20$, dùng **quy hoạch động bitmask**. Định nghĩa $dp[mask][u]$ = số cách đứng tại thành phố $u$ (đánh số từ 0) sau khi thăm đúng tập thành phố trong $mask$ (bit $i$ bật nghĩa là thành phố $i$ đã thăm).

Cơ sở: $dp[1][0] = 1$ (bắt đầu tại thành phố 0, chỉ nó được thăm).

Chuyển trạng thái: với mỗi trạng thái $(mask, u)$ mà bit $u$ bật, và mỗi cạnh $u \to v$ mà bit $v$ chưa bật trong $mask$:

$$dp[mask \mid 2^v][v] \mathrel{+}= dp[mask][u] \pmod{10^9+7}$$

Mỗi đường đi Hamilton tương ứng duy nhất với một dãy trạng thái có $mask$ tăng dần (thêm đúng 1 bit mỗi bước), nên không bị đếm trùng. Đường đi thăm hết $n$ thành phố, đáp án là $dp[2^n - 1][n-1]$.

**Tối ưu:** Vì thành phố 0 luôn đầu tiên, bit 0 của $mask$ luôn bật — chỉ duyệt $mask$ lẻ. Thành phố $n-1$ luôn cuối cùng, nên mask trung gian chỉ chứa thành phố 0 đến $n-2$ (tối đa $n-1$ bit), giới hạn vòng lặp là $2^{n-1}$.

### Thuật toán

1. Chuyển thành phố sang 0-indexed. Khởi tạo $dp[1][0] = 1$.
2. Với mỗi $mask$ lẻ từ 1 đến $2^{n-1} - 1$:
   - Với mỗi thành phố $u$ có bit $u$ bật trong $mask$:
     - Với mỗi cạnh $u \to v$ mà bit $v$ chưa bật trong $mask$:
       - $dp[mask \mid 2^v][v] \mathrel{+}= dp[mask][u] \pmod{10^9+7}$.
3. Xuất $dp[2^n - 1][n-1]$.

### Ví dụ minh họa

Đầu vào:
```
4 6
1 2
1 3
2 3
3 2
2 4
3 4
```

Cạnh (0-indexed): $0 \to 1$, $0 \to 2$, $1 \to 2$, $2 \to 1$, $1 \to 3$, $2 \to 3$.

- $dp[\{0\}][0] = 1$
- mask $\{0\}$: $0 \to 1$ → $dp[\{0,1\}][1] = 1$; $0 \to 2$ → $dp[\{0,2\}][2] = 1$
- mask $\{0,1\}$: $1 \to 2$ → $dp[\{0,1,2\}][2] = 1$; $1 \to 3$ → $dp[\{0,1,3\}][3] = 1$
- mask $\{0,2\}$: $2 \to 1$ → $dp[\{0,1,2\}][1] = 1$; $2 \to 3$ → $dp[\{0,2,3\}][3] = 1$
- mask $\{0,1,2\}$: $1 \to 3$ → $dp[\{0,1,2,3\}][3] \mathrel{+}= dp[\{0,1,2\}][1] = 1$; $2 \to 3$ → $dp[\{0,1,2,3\}][3] \mathrel{+}= dp[\{0,1,2\}][2] = 1$. Tổng: 2.

2 đường đi Hamilton: $1 \to 2 \to 3 \to 4$ và $1 \to 3 \to 2 \to 4$.

Kết quả: `2`

## Độ phức tạp

- **Thời gian:** $O(2^n \cdot n^2)$ — $2^n$ mask, mỗi mask duyệt $n$ đỉnh với tối đa $n$ cạnh.
- **Không gian:** $O(2^n \cdot n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Hamiltonian%20Flights.cpp)
