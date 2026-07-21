# Mountain Range - Lời giải

**ID:** 3314 | **URL:** https://cses.fi/problemset/task/3314

## Hướng tiếp cận

### Phát biểu lại bài toán

Có $n$ ngọn núi xếp thành hàng với chiều cao $h_i$. Bạn có thể bay lượn từ núi $a$ sang núi $b$ nếu $h_a > h_b$ và mọi núi giữa $a$ và $b$ đều thấp hơn $h_a$. Tìm số núi tối đa có thể đi qua trên một hành trình.

### Ý tưởng cốt lõi

Từ núi $i$, ta có thể bay trực tiếp đến bất kỳ núi $j$ nào trong khoảng $(L[i], R[i])$ với $h_j < h_i$, trong đó $L[i]$ là chỉ số gần nhất bên trái có $h_{L[i]} > h_i$ và $R[i]$ là chỉ số gần nhất bên phải có $h_{R[i]} > h_i$. Núi $i$ là núi cao nhất trong $[L[i]+1, R[i]-1]$ nên chi phối mọi núi trong khoảng đó.

**Tại sao $(L[i], R[i])$ là vùng bay chính xác:** Nếu $b < L[a]$, thì $h_{L[a]} > h_a$ và $L[a]$ nằm giữa $a$ và $b$, nên $a$ không cao hơn mọi núi ở giữa. Ngược lại, nếu $b \in (L[a], R[a])$ và $h_b < h_a$, thì mọi núi giữa $a$ và $b$ đều nằm trong $(L[a], R[a])$ và có chiều cao $< h_a$, nên bay được.

**QHD theo chiều cao giảm:** Gọi $dp[i]$ là số núi tối đa thăm được trên hành trình kết thúc tại $i$. Xử lý các núi từ cao đến thấp bằng cây phân đoạn. Khi xử lý $p$: truy vấn $dp[p]$ từ cây phân đoạn (giá trị đã được lan truyền bởi các núi cao hơn có thể bay đến $p$), rồi lan truyền $dp[p] + 1$ đến các đoạn $[L[p]+1, p-1]$ và $[p+1, R[p]-1]$. Đáp án là $\max(dp) + 1$.

**Tính đúng:** Quy nạp theo chiều cao. Núi cao nhất có $dp = 0$. Khi xử lý $p$, mọi núi cao hơn đã lan truyền xong. Giá trị tại $p$ trên cây phân đoạn là $\max$ của $dp[q] + 1$ trên các $q$ cao hơn và có thể bay đến $p$ — đúng là tiền tố hành trình tốt nhất kết thúc tại $p$.

Tính $L[i]$ và $R[i]$ bằng stack đơn điệu trong $O(n)$: duy trì stack giảm nghiêm ngặt; $L[i]$ (hoặc $R[i]$) là đỉnh stack sau khi pop tất cả chiều cao $< h_i$.

### Thuật toán

1. Tính $L[i]$ và $R[i]$ bằng stack đơn điệu.
2. Sắp xếp chỉ số núi theo chiều cao giảm dần.
3. Với mỗi núi $p$ theo thứ tự đã sắp:
   - $dp[p] = \text{query}(p)$ trên cây phân đoạn
   - $\text{update}(L[p]+1, p-1, dp[p]+1)$ và $\text{update}(p+1, R[p]-1, dp[p]+1)$
4. Xuất $\max(dp) + 1$.

### Ví dụ

$h = [20, 15, 17, 35, 25, 40, 12, 19, 13, 12]$

$L = [0, 1, 1, 0, 4, 0, 6, 6, 8, 9]$, $R = [4, 3, 4, 6, 6, 11, 8, 11, 11, 11]$ (biên 0, 11)

Xử lý theo chiều cao giảm dần:

| Bước | $p$ | $h_p$ | $dp[p]$ | Lan truyền $dp[p]+1$ đến |
|------|-----|-------|---------|--------------------------|
| 1 | 6 | 40 | 0 | $[1,5]$ và $[7,10]$ |
| 2 | 4 | 35 | 1 | $[1,3]$ và $[5,5]$ |
| 3 | 5 | 25 | 2 | — (đoạn rỗng) |
| 4 | 1 | 20 | 2 | $[2,3]$ |
| 5 | 8 | 19 | 1 | $[7,7]$ và $[9,10]$ |
| 6 | 3 | 17 | 3 | $[2,2]$ |
| 7 | 2 | 15 | 4 | — |
| 8 | 9 | 13 | 2 | $[10,10]$ |
| 9 | 7 | 12 | 2 | — |
| 10 | 10 | 12 | 3 | — |

$\max(dp) = 4$, đáp án $= 4 + 1 = \mathbf{5}$.

Một hành trình tối ưu: núi 6 → 4 → 1 → 3 → 2 (chiều cao 40 → 35 → 20 → 17 → 15).

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp + $n$ thao tác cây phân đoạn mỗi cái $O(\log n)$
- **Bộ nhớ:** $O(n)$ — cho các mảng, cây phân đoạn, và stack

## Mã nguồn (C++)

[Mã nguồn](../code/Mountain%20Range.cpp)
