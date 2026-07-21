# Static Range Sum Queries - Lời giải

**ID:** 1646 | **URL:** https://cses.fi/problemset/task/1646

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng tĩnh $n$ số nguyên, xử lý $q$ truy vấn: tính tổng các phần tử trong đoạn $[a, b]$.

### Ý tưởng cốt lõi

Dùng **mảng tổng tiền tố**. Xây mảng $S$ với $S[0] = 0$ và $S[i] = S[i-1] + x_i$. Tổng đoạn $[a, b]$ là:

$$S[b] - S[a-1] = (x_1 + \cdots + x_{a-1} + x_a + \cdots + x_b) - (x_1 + \cdots + x_{a-1}) = x_a + \cdots + x_b$$

Các phần tử $x_1, \ldots, x_{a-1}$ triệt tiêu nhau, phần còn lại chính là tổng đoạn cần tìm.

Lưu ý: với $n \le 2 \cdot 10^5$ và $x_i \le 10^9$, tổng tiền tố có thể đạt $2 \cdot 10^{14}$, vượt phạm vi 32-bit. Cần dùng số nguyên 64-bit.

### Thuật toán

1. Xây mảng tổng tiền tố: $S[0] = 0$, $S[i] = S[i-1] + x_i$ với $i = 1, \ldots, n$.
2. Với mỗi truy vấn đoạn $[a, b]$, xuất $S[b] - S[a-1]$.

### Ví dụ minh họa

Đầu vào:
```
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
```

Mảng: $[3, 2, 4, 5, 1, 1, 5, 3]$. Tổng tiền tố: $S = [0, 3, 5, 9, 14, 15, 16, 21, 24]$.

- Tổng $[2, 4]$: $S[4] - S[1] = 14 - 3 = 11$.
- Tổng $[5, 6]$: $S[6] - S[4] = 16 - 14 = 2$.
- Tổng $[1, 8]$: $S[8] - S[0] = 24 - 0 = 24$.
- Tổng $[3, 3]$: $S[3] - S[2] = 9 - 5 = 4$.

Kết quả:
```
11
2
24
4
```

## Độ phức tạp

- **Thời gian:** $O(n + q)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Static%20Range%20Sum%20Queries.cpp)
