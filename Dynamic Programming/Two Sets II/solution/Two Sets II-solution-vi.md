# Two Sets II - Lời giải

**ID:** 1093 | **URL:** https://cses.fi/problemset/task/1093

## Hướng tiếp cận

### Phát biểu lại bài toán

Đếm số cách chia $\{1, 2, \ldots, n\}$ thành hai tập có tổng bằng nhau. Kết quả lấy modulo $10^9 + 7$.

### Ý tưởng cốt lõi

Tổng tất cả các số là $S = n(n+1)/2$. Nếu $S$ lẻ, đáp án là 0. Ngược lại, bài toán quy về đếm số tập con có tổng $S/2$ — mỗi tập con $A$ như vậy ghép với phần bù $B = \{1,\ldots,n\} \setminus A$ thành một cách chia hợp lệ.

**QHD kiểu knapsack 0/1:** Gọi $dp[j]$ là số tập con có tổng $j$. Khởi tạo $dp[0] = 1$. Với mỗi số $i$ từ 1 đến $n$, cập nhật $dp[j] = (dp[j] + dp[j-i]) \bmod (10^9+7)$ duyệt $j$ từ $S/2$ xuống $i$ (duyệt ngược đảm bảo mỗi $i$ dùng tối đa 1 lần).

**Tại sao chia 2:** Mỗi cách chia $\{A, B\}$ được đếm hai lần — một lần chọn $A$, một lần chọn $B$. Vì $S > 0$, không có tập con nào bằng phần bù của chính nó, nên số cách bị nhân đôi chính xác. Đáp án là $dp[S/2] \cdot 2^{-1} \bmod (10^9+7)$, với $2^{-1} \equiv 5 \times 10^8 + 4 \pmod{10^9+7}$.

**Tính đúng (bất biến):** Sau khi xử lý các số từ 1 đến $i$, $dp[j]$ bằng số tập con của $\{1, \ldots, i\}$ có tổng $j$. Chứng minh quy nạp: cơ sở $i=0$ chỉ có $dp[0]=1$ (tập rỗng). Khi thêm $i$, mỗi tập con mới hoặc không chứa $i$ ($dp_{\text{cũ}}[j]$ cách), hoặc chứa $i$ (bỏ $i$ ra còn tập con tổng $j-i$, có $dp_{\text{cũ}}[j-i]$ cách). Duyệt ngược giữ nguyên giá trị cũ.

### Thuật toán

1. Nếu $S = n(n+1)/2$ lẻ, xuất 0.
2. Khởi tạo $dp[0] = 1$.
3. Với $i = 1$ đến $n$: với $j = S/2$ xuống $i$: $dp[j] = (dp[j] + dp[j-i]) \bmod (10^9+7)$.
4. Xuất $dp[S/2] \cdot 2^{-1} \bmod (10^9+7)$.

### Ví dụ

$n = 7$, $S = 28$, $S/2 = 14$:

| Sau $i$ | $dp[14]$ |
|---------|-----------|
| 1–4 | 0 |
| 5 | 1 |
| 6 | 4 |
| 7 | 8 |

$dp[14] = 8$, đáp án $= 8 \cdot 2^{-1} = \mathbf{4}$.

4 cách chia: $\{1,3,4,6\}$/$\{2,5,7\}$, $\{1,2,5,6\}$/$\{3,4,7\}$, $\{1,2,4,7\}$/$\{3,5,6\}$, $\{1,6,7\}$/$\{2,3,4,5\}$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot S/2) = O(n^3)$ — với $S/2 \approx n^2/4$
- **Bộ nhớ:** $O(S) = O(n^2)$ — cho mảng $dp$

## Mã nguồn (C++)

[Mã nguồn](../code/Two%20Sets%20II.cpp)
