# Monotone Subsequences - Lời giải

**ID:** 2215 | **URL:** https://cses.fi/problemset/task/2215

## Phương pháp

### Tóm tắt bài toán

Tạo một hoán vị của các số $1, 2, \ldots, n$ sao cho dãy con đơn điệu dài nhất (tăng hoặc giảm) có đúng $k$ phần tử.

### Ý tưởng chính

Theo định lý Erdős–Szekeres, bất kỳ dãy nào có hơn $(k-1)^2$ số phân biệt đều chứa dãy con đơn điệu dài $k$, nên cần $n \le k^2$. Khi đó, chia hoán vị thành các khối kích thước $k$, mỗi khối sắp giảm, các khối với nhau tăng dần:

$$\underbrace{k, k-1, \ldots, 1}_{\text{Khối 1}}, \underbrace{2k, 2k-1, \ldots, k+1}_{\text{Khối 2}}, \ldots$$

- **Dãy con giảm dài nhất:** Vì mọi phần tử khối sau đều lớn hơn mọi phần tử khối trước ($ik+1 > (i-1)k$), dãy giảm không thể kéo qua hai khối. Nó bị giới hạn trong một khối kích thước $k$, cho độ dài $k$.
- **Dãy con tăng dài nhất:** Trong mỗi khối, các phần tử giảm, nên chỉ lấy được tối đa một phần tử mỗi khối. Số khối là $\lceil n/k \rceil \le k$, nên dãy tăng dài nhất có độ dài $\le k$.

Vậy dãy con đơn điệu dài nhất là $\max(k, \lceil n/k \rceil) = k$ khi $\lceil n/k \rceil \le k$ (tương đương $n \le k^2$). Ngược lại, xuất `IMPOSSIBLE`.

### Thuật toán

1. Nếu $\lceil n/k \rceil > k$: xuất `IMPOSSIBLE`.
2. Ngược lại, với $i = 1, 2, \ldots, \lceil n/k \rceil$: xuất $\min(ik, n), \min(ik, n) - 1, \ldots, (i-1)k + 1$.

### Ví dụ minh họa

Ví dụ đề bài (đầu vào `3` test):

- $n = 5, k = 3$: $\lceil 5/3 \rceil = 2 \le 3$. Khối: `3 2 1 | 5 4`. Dãy giảm dài nhất: `3 2 1` (độ dài 3). Dãy tăng dài nhất: `1 5` (độ dài 2). Kết quả: `3 2 1 5 4`.
- $n = 5, k = 2$: $\lceil 5/2 \rceil = 3 > 2$. Kết quả: `IMPOSSIBLE`.
- $n = 7, k = 7$: $\lceil 7/7 \rceil = 1 \le 7$. Khối: `7 6 5 4 3 2 1`. Dãy giảm dài nhất: 7. Kết quả: `7 6 5 4 3 2 1` (hoặc `1 2 3 4 5 6 7`).

## Độ phức tạp

- **Thời gian:** $O(n)$ mỗi test case
- **Không gian:** $O(1)$ (không tính kết xuất)

## Mã nguồn (C++)

[Mã nguồn](../code/Monotone%20Subsequences.cpp)
