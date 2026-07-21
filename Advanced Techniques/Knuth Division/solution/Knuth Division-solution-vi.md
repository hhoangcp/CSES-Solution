# Knuth Division - Lời giải

**ID:** 2088 | **URL:** https://cses.fi/problemset/task/2088

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số, chia thành $n$ mảng con mỗi mảng một phần tử. Mỗi bước chọn một mảng con và tách thành hai, chi phí bằng tổng giá trị trong mảng con được chọn. Tìm tổng chi phí nhỏ nhất.

### Ý tưởng chính

Định nghĩa $dp[i][j]$ = chi phí tối thiểu để chia đoạn $[i, j]$ thành các phần tử đơn:

$$dp[i][j] = \min_{i \le k < j} \left( dp[i][k] + dp[k+1][j] + S(i, j) \right)$$

trong đó $S(i, j) = \text{prefix}[j] - \text{prefix}[i-1]$. Chi phí $S(i,j)$ là bước tách hiện tại, hai hạng còn lại là chi phí tách tiếp hai nửa. QHD thông thường $O(n^3)$ — quá chậm với $n = 5000$.

**Tối ưu Knuth** giảm xuống $O(n^2)$ nhờ tính đơn điệu của vị trí cắt tối ưu: $opt[i][j-1] \le opt[i][j] \le opt[i+1][j]$. Điều này đúng khi hàm chi phí $w(i,j) = S(i,j)$ thỏa mãn:
1. **Bất đẳng thức tứ giác:** $w(a,c) + w(b,d) \le w(a,d) + w(b,c)$ với $a \le b \le c \le d$. Hai vế bằng nhau: $(prefix[c] - prefix[a-1]) + (prefix[d] - prefix[b-1])$, nên QI đúng với đẳng thức.
2. **Đơn điệu:** $w(b,c) \le w(a,d)$ với $a \le b \le c \le d$. Đúng vì mọi $a_i > 0$.

Vì $S$ thỏa mãn QI, $dp$ cũng thỏa mãn QI (quy nạp theo độ dài đoạn), kéo theo tính đơn điệu của $opt$. Tổng số ứng cử viên kiểm tra trên mọi trạng thái DP là $O(n^2)$.

### Thuật toán

1. Tính tổng tiền tố.
2. Khởi tạo $dp[i][i] = 0$, $opt[i][i] = i$.
3. Điền DP theo chiều dài đoạn tăng dần. Với mỗi $[i, j]$: tìm $k$ chỉ trong $[opt[i][j-1], \min(opt[i+1][j], j-1)]$.
4. Xuất $dp[1][n]$.

### Ví dụ minh họa

Mảng: $[2, 7, 3, 2, 5]$. Tổng tiền tố: $[0, 2, 9, 12, 14, 19]$.

Các bước tách tối ưu của đoạn $[1, 5]$:

| Bước | Đoạn | Tách tại $k$ | Chi phí $S(i,j)$ | Kết quả |
|------|------|-------------|-------------------|---------|
| 1 | $[1,5]$ | 2 | $19$ | $[1,2] + [3,5]$ |
| 2 | $[1,2]$ | 1 | $9$ | $[1] + [2]$ |
| 3 | $[3,5]$ | 4 | $10$ | $[3,4] + [5]$ |
| 4 | $[3,4]$ | 3 | $5$ | $[3] + [4]$ |

Tổng: $19 + 9 + 10 + 5 = 43$.

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — tối ưu Knuth giảm từ $O(n^3)$.
- **Không gian:** $O(n^2)$ — bảng DP và `opt`.

## Mã nguồn (C++)

[Mã nguồn](../code/Knuth%20Division.cpp)
