# Range Xor Queries - Lời giải

**ID:** 1650 | **URL:** https://cses.fi/problemset/task/1650

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng tĩnh $n$ số nguyên, xử lý $q$ truy vấn, mỗi truy vấn yêu cầu tính XOR của các phần tử trong đoạn $[a, b]$.

### Ý tưởng cốt lõi

Dùng **mảng tiền tố XOR**, tương tự mảng tổng tiền tố. Xây mảng $S$ với $S[0] = 0$ và $S[i] = S[i-1] \oplus x_i$. XOR đoạn $[a, b]$ là:

$$x_a \oplus x_{a+1} \oplus \cdots \oplus x_b = S[b] \oplus S[a-1]$$

Công thức đúng nhờ tính tự nghịch đảo của XOR: $x \oplus x = 0$ và $x \oplus 0 = x$. Các phần tử $x_1, \ldots, x_{a-1}$ xuất hiện trong cả $S[b]$ và $S[a-1]$ nên tự triệt tiêu:

$$S[b] \oplus S[a-1] = (x_1 \oplus \cdots \oplus x_{a-1} \oplus x_a \oplus \cdots \oplus x_b) \oplus (x_1 \oplus \cdots \oplus x_{a-1}) = x_a \oplus \cdots \oplus x_b$$

Đây là phiên bản XOR của kỹ thuật tổng tiền tố cho truy vấn tổng đoạn, tận dụng $x \oplus x = 0$ thay vì $x + (-x) = 0$.

### Thuật toán

1. Xây mảng tiền tố XOR: $S[0] = 0$, $S[i] = S[i-1] \oplus x_i$ với $i = 1, \ldots, n$.
2. Với mỗi truy vấn đoạn $[a, b]$, xuất $S[b] \oplus S[a-1]$.

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

Mảng: $[3, 2, 4, 5, 1, 1, 5, 3]$. Tiền tố XOR: $S = [0, 3, 1, 5, 0, 1, 0, 5, 6]$.

- Truy vấn $[2, 4]$: $S[4] \oplus S[1] = 0 \oplus 3 = 3$. Kiểm tra: $2 \oplus 4 \oplus 5 = 3$.
- Truy vấn $[5, 6]$: $S[6] \oplus S[4] = 0 \oplus 0 = 0$. Kiểm tra: $1 \oplus 1 = 0$.
- Truy vấn $[1, 8]$: $S[8] \oplus S[0] = 6 \oplus 0 = 6$.
- Truy vấn $[3, 3]$: $S[3] \oplus S[2] = 5 \oplus 1 = 4$.

Kết quả:
```
3
0
6
4
```

## Độ phức tạp

- **Thời gian:** $O(n + q)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Range%20Xor%20Queries.cpp)
