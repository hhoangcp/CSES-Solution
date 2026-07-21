# Subarray Squares - Lời giải

**ID:** 2086 | **URL:** https://cses.fi/problemset/task/2086

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ phần tử, chia thành $k$ mảng con liên tiếp. Chi phí mỗi mảng con là bình phương tổng phần tử. Tối thiểu hóa tổng chi phí.

### Ý tưởng chính

Định nghĩa $dp[j][i]$ = chi phí tối thiểu chia $j$ phần tử đầu thành $i$ mảng con. Gọi $S_j$ là tổng tiền tố. Công thức truy hồi:

$$dp[j][i] = \min_{k < j} \left( dp[k][i-1] + (S_j - S_k)^2 \right)$$

Khai triển bình phương và tách các hạng chứa $S_j$:

$$dp[j][i] = S_j^2 + \min_{k < j} \left( -2S_k \cdot S_j + (dp[k][i-1] + S_k^2) \right)$$

Đây là hàm tuyến tính $y = mx + b$ theo $x = S_j$ với hệ góc $m = -2S_k$ và tung độ gốc $b = dp[k][i-1] + S_k^2$. Vì tổng tiền tố không giảm, các hệ góc chèn theo thứ tự không tăng và truy vấn $x = S_j$ không giảm. Điều này cho phép dùng **Convex Hull Trick (CHT)** với deque: duy trì bao dưới, loại đầu khi có đường tốt hơn (an toàn vì truy vấn chỉ dịch phải), loại cuối khi đường mới làm đường cuối trở nên dư thừa (kiểm tra bằng nhân chéo giao điểm).

QHD đơn thuần là $O(k \cdot n^2)$; CHT giảm mỗi lớp xuống $O(n)$ biên độ.

### Thuật toán

1. Tính tổng tiền tố. Khởi tạo $dp[j][1] = S_j^2$.
2. Với $i = 2$ đến $k$:
   - Xóa deque CHT.
   - Chèn đường ứng với $k = i{-}1$: hệ góc $-2S_{i-1}$, tung độ gốc $dp[i{-}1][i{-}1] + S_{i-1}^2$.
   - Với $j = i$ đến $n$:
     - Truy vấn CHT tại $x = S_j$: $dp[j][i] = \text{Query}(S_j) + S_j^2$.
     - Chèn đường: hệ góc $-2S_j$, tung độ gốc $dp[j][i{-}1] + S_j^2$.
3. Xuất $dp[n][k]$.

### Ví dụ minh họa

$n=8$, $k=3$, mảng: $[2, 3, 1, 2, 2, 3, 4, 1]$.

Tổng tiền tố: $S = [0, 2, 5, 6, 8, 10, 13, 17, 18]$.

Phân chia tối ưu: $[2,3,1]$, $[2,2,3]$, $[4,1]$.

| Mảng con | Tổng | Chi phí |
|----------|------|---------|
| $[2,3,1]$ | 6 | $6^2 = 36$ |
| $[2,2,3]$ | 7 | $7^2 = 49$ |
| $[4,1]$ | 5 | $5^2 = 25$ |

Tổng: $36 + 49 + 25 = \mathbf{110}$.

## Độ phức tạp

- **Thời gian:** $O(k \cdot n)$
- **Bộ nhớ:** $O(n \cdot k)$

## Mã nguồn (C++)

[Mã nguồn](../code/Subarray%20Squares.cpp)
