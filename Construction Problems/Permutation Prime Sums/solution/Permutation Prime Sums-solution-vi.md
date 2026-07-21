# Permutation Prime Sums - Lời giải

**ID:** 3423 | **URL:** https://cses.fi/problemset/task/3423

## Phương pháp

### Tóm tắt bài toán

Cho $n$, tạo hai hoán vị $a$ và $b$ kích thước $n$ sao cho $a_i + b_i$ là số nguyên tố với mọi $i = 1, 2, \ldots, n$.

### Ý tưởng chính

Không mất tổng quát, đặt $a_i = i$ (hoán vị đồng nhất). Nhiệm vụ còn lại là tìm hoán vị $b$ sao cho $i + b_i$ nguyên tố với mọi $i$. Với số nguyên tố $p$, ánh xạ $i \mapsto p - i$ ghép cặp các giá trị có tổng bằng $p$ và là ánh xạ nghịch đảo của chính nó, tạo thành song ánh. Ta phân hoạch $\{1, \ldots, n\}$ thành các đoạn, mỗi đoạn được phủ bởi một số nguyên tố.

Xây dựng đệ quy $b$ cho đoạn $[1, n]$: tìm số nguyên tố nhỏ nhất $p > n$, đặt $m = p - n$, rồi gán $b[i] = p - i$ cho $i \in [m, n]$. Vì $p - i \in [m, n]$ (do $p - i \ge p - n = m$ và $p - i \le p - m = n$), ánh xạ này đưa đoạn $[m, n]$ song ánh lên chính nó, mỗi tổng bằng $p$. Đệ quy tiếp trên đoạn $[1, m-1]$.

Theo tiên đề Bertrand, với mọi $n \ge 1$ tồn tại số nguyên tố $p$ với $n < p < 2n$, nên $m = p - n < n$ và bài toán con nhỏ hơn nghiêm ngặt. Đệ quy kết thúc tại $n = 0$.

### Thuật toán

1. Sàng nguyên tố đến $2n$.
2. Gọi `solve(n)`:
   - Nếu $n \le 0$: trả về.
   - Tìm số nguyên tố nhỏ nhất $p > n$ (tìm kiếm nhị phân trên sàng).
   - Đặt $m = p - n$.
   - Với $i = m$ đến $n$: đặt $b[i] = p - i$.
   - Đệ quy `solve(m - 1)`.
3. Xuất $a_i = i$ và $b_i$ với $i = 1, \ldots, n$.

### Ví dụ minh họa

$n = 5$ (ví dụ đề bài, kết quả hợp lệ: `2 1 3 5 4` / `5 1 4 2 3`):

- `solve(5)`: số nguyên tố nhỏ nhất $> 5$ là $p = 7$, $m = 7 - 5 = 2$.
  - Đoạn $[2, 5]$: $b[2] = 5, b[3] = 4, b[4] = 3, b[5] = 2$. Tổng: đều bằng $7$.
- `solve(1)`: số nguyên tố nhỏ nhất $> 1$ là $p = 2$, $m = 2 - 1 = 1$.
  - Đoạn $[1, 1]$: $b[1] = 1$. Tổng: $1 + 1 = 2$.
- `solve(0)`: kết thúc.

Kết quả: $a = [1, 2, 3, 4, 5]$, $b = [1, 5, 4, 3, 2]$. Các tổng: $2, 7, 7, 7, 7$ — đều nguyên tố.

## Độ phức tạp

- **Thời gian:** $O(n)$ cho sàng + $O(n)$ cho cấu trúc
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Permutation%20Prime%20Sums.cpp)
