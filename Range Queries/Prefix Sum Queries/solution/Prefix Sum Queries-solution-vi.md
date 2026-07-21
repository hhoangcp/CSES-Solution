# Prefix Sum Queries - Lời giải

**ID:** 2166 | **URL:** https://cses.fi/problemset/task/2166

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, xử lý $q$ truy vấn:
1. Cập nhật giá trị tại vị trí $k$ thành $u$.
2. Tìm tổng tiền tố lớn nhất trong đoạn $[a, b]$. Tiền tố rỗng (tổng bằng 0) được phép.

### Ý tưởng cốt lõi

Gọi $P[i] = x_1 + x_2 + \cdots + x_i$ (với $P[0] = 0$). Tổng đoạn con bắt đầu từ $a$ kết thúc tại $j$ là $P[j] - P[a-1]$. Vì $P[a-1]$ là hằng số với mỗi truy vấn:

$$\max_{a \le j \le b}(P[j] - P[a-1]) = \max_{j \in [a, b]} P[j] - P[a-1]$$

Mở rộng miền tìm kiếm bao gồm $j = a-1$. Nếu cực đại nằm tại $j = a-1$, kết quả là $P[a-1] - P[a-1] = 0$, tự động xử lý trường hợp tiền tố rỗng mà không cần $\max(0, \ldots)$ rời rạc:

$$\text{đáp án} = \max_{j \in [a-1, b]} P[j] - P[a-1]$$

Giờ duy trì trực tiếp mảng $P$. Khi cập nhật $x_k = u$ với $\delta = u - x_k^{\text{cũ}}$, mọi $P[i]$ với $i \ge k$ đều tăng thêm $\delta$, nên cập nhật điểm trên $x$ quy về cộng đoạn $[k, n]$ trên $P$. Xây cây phân đoạn trên $P$ (kích thước $n+1$, chỉ số $0$ đến $n$) hỗ trợ cộng đoạn (truyền lười) và truy vấn maximum đoạn.

### Thuật toán

1. **Xây dựng** cây phân đoạn trên $P[0..n]$, hỗ trợ cộng đoạn và truy vấn max đoạn.
2. **Cập nhật** $x_k = u$: tính $\delta = u - x_k$, gọi `Update(k, n, delta)`, đặt $a[k] = u$.
3. **Truy vấn** $[a, b]$:
   - $M = \text{Query}(a-1, b)$ — giá trị lớn nhất của $P$ trên $[a-1, b]$.
   - $P_{a-1} = \text{Query}(a-1, a-1)$ — giá trị $P[a-1]$.
   - Đáp án $= M - P_{a-1}$.

### Ví dụ minh họa

Đầu vào:
```
8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4
```

Mảng: $[1, 2, -1, 3, 1, -5, 1, 4]$. $P = [0, 1, 3, 2, 5, 6, 1, 2, 6]$.

- Truy vấn $[2, 6]$: $\max(P[1..6]) = \max(1, 3, 2, 5, 6, 1) = 6$. $P[1] = 1$. Đáp án $= 6 - 1 = 5$.
- Cập nhật $x_4 = -2$: $\delta = -2 - 3 = -5$. Cộng $-5$ lên $P[4..8]$. $P$ mới: $[0, 1, 3, 2, 0, 1, -4, -3, 1]$.
- Truy vấn $[2, 6]$: $\max(P[1..6]) = \max(1, 3, 2, 0, 1, -4) = 3$. $P[1] = 1$. Đáp án $= 3 - 1 = 2$.
- Truy vấn $[3, 4]$: $\max(P[2..4]) = \max(3, 2, 0) = 3$. $P[2] = 3$. Đáp án $= 3 - 3 = 0$ (tiền tố rỗng).

Kết quả:
```
5
2
0
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Prefix%20Sum%20Queries.cpp)
