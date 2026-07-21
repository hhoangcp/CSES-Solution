# Dice Probability - Lời giải

**ID:** 1725 | **URL:** https://cses.fi/problemset/task/1725

## Phương pháp

### Tóm tắt bài toán

Tung xúc xắc $n$ lần ($1 \le n \le 100$), mỗi lần cho kết quả từ 1 đến 6 với xác suất đồng đều. Tính xác suất tổng kết quả nằm trong đoạn $[a, b]$, làm tròn đến 6 chữ số thập phân (làm tròn nửa về số chẵn).

### Ý tưởng chính

Dùng quy hoạch động trên phân phối tổng. Gọi $dp[i][j]$ là xác suất đạt tổng $j$ sau $i$ lần tung. Theo **định lý xác suất toàn phần**, lần tung cuối phải ra mặt $k \in \{1, \ldots, 6\}$ và tổng trước đó phải bằng $j - k$:

$$dp[i][j] = \sum_{k=1}^{6} dp[i-1][j-k] \cdot \frac{1}{6}$$

Cơ sở: $dp[0][0] = 1$. Sau $i$ lần tung, tổng nằm trong $[i, 6i]$, nên chỉ duyệt $j$ trong phạm vi này (coi $dp[i-1][j-k] = 0$ khi $j - k < 0$).

Đáp án là tổng các sự kiện rời rạc xung khắc:

$$P(a \le S \le b) = \sum_{j=a}^{b} dp[n][j]$$

### Thuật toán

1. Khởi tạo $dp[0][0] = 1$.
2. Với $i = 1$ đến $n$: với $j = i$ đến $6i$: $dp[i][j] = \frac{1}{6}\sum_{k=1}^{6} dp[i-1][j-k]$.
3. Cộng $dp[n][j]$ với $j$ từ $a$ đến $b$.

### Ví dụ minh họa

$n = 2$, $a = 9$, $b = 10$:

- $dp[1][j] = 1/6$ với $j = 1, \ldots, 6$.
- $dp[2][9] = \frac{1}{6}(0 + 0 + \frac{1}{6} + \frac{1}{6} + \frac{1}{6} + \frac{1}{6}) = \frac{4}{36}$
- $dp[2][10] = \frac{1}{6}(0 + 0 + 0 + \frac{1}{6} + \frac{1}{6} + \frac{1}{6}) = \frac{3}{36}$
- $P = \frac{4+3}{36} = \frac{7}{36} \approx 0.194444$

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — $n$ bước, mỗi bước xử lý tới $6n$ tổng với 6 số hạng
- **Bộ nhớ:** $O(n^2)$ — tối ưu được xuống $O(n)$ bằng mảng cuộn
