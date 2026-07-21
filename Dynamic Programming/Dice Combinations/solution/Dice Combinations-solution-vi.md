# Dice Combinations - Lời giải

**ID:** 1633 | **URL:** https://cses.fi/problemset/task/1633

## Hướng tiếp cận

### Tóm tắt bài toán

Đếm số cách có thứ tự tạo ra tổng $n$ bằng cách tung xúc xắc 6 mặt một hoặc nhiều lần. Mỗi lần tung cho kết quả 1–6. Thứ tự khác nhau tính là cách khác nhau. Kết quả modulo $10^9 + 7$.

### Ý tưởng chính

Gọi $dp[i]$ là số cách có thứ tự tạo ra tổng $i$. Xét lần tung **cuối cùng**: nếu ra mặt $k$ ($1 \le k \le \min(6, i)$), các lần tung trước phải tạo tổng $i - k$. Cộng qua mọi mặt có thể:

$$dp[i] = \sum_{k=1}^{\min(6,i)} dp[i - k]$$

Không đếm dư: hai dãy từ các $k$ khác nhau có lần tung cuối khác nhau; dãy cùng $k$ đã khác nhau theo quy nạp trên tiền tố. Không đếm thiếu: mọi dãy hợp lệ đều có một lần tung cuối $k$, nên được đếm qua $dp[i - k]$.

Trường hợp cơ sở: $dp[0] = 1$ (có một cách tạo tổng 0: không tung xúc xắc nào).

### Thuật toán

1. Khởi tạo $dp[0] = 1$.
2. Với $i = 1$ đến $n$: $dp[i] = \sum_{k=1}^{\min(6,i)} dp[i - k] \bmod (10^9 + 7)$.
3. Kết quả là $dp[n]$.

### Ví dụ minh họa

Input: $n = 3$.

| $i$ | $dp[i]$ | Cách |
|:---:|:---:|:---|
| 0 | 1 | Cơ sở |
| 1 | $dp[0] = 1$ | $(1)$ |
| 2 | $dp[1] + dp[0] = 2$ | $(1,1), (2)$ |
| 3 | $dp[2] + dp[1] + dp[0] = 4$ | $(1,1,1), (1,2), (2,1), (3)$ |

Kết quả: $dp[3] = 4$ — tương ứng $1{+}1{+}1$, $1{+}2$, $2{+}1$, $3$.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Dice%20Combinations.cpp)
