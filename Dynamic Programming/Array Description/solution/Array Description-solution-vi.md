# Array Description - Lời giải

**ID:** 1746 | **URL:** https://cses.fi/problemset/task/1746

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ phần tử trong $[1, m]$, một số vị trí bằng $0$ (chưa biết). Đếm số cách điền các vị trí $0$ sao cho hai phần tử kề nhau chênh lệch tối đa $1$.

### Ý tưởng chính

Ràng buộc $|a_i - a_{i+1}| \le 1$ nghĩa là mỗi phần tử chỉ phụ thuộc vào phần tử kề ngay trước nó. Tính chất cục bộ này khiến bài toán phù hợp với quy hoạch động theo vị trí, tại mỗi vị trí theo dõi số cách hợp lệ kết thúc bằng mỗi giá trị có thể.

Gọi $dp[i][v]$ là số cách điền hợp lệ $i$ phần tử đầu tiên với $a_i = v$. Công thức truy hồi cộng qua ba giá trị trước có thể $\{v-1, v, v+1\} \cap [1, m]$:

$$dp[i][v] = \sum_{k=v-1}^{v+1} dp[i-1][k]$$

Khi $a_i$ đã biết (khác $0$), chỉ $dp[i][a_i]$ được cập nhật; mọi $dp[i][v]$ khác bằng $0$, đảm bảo không mảng nào vi phạm giá trị cố định. Điều này cũng đảm bảo không đếm trùng, vì mỗi mảng hợp lệ duy nhất xác định một đường đi trong bảng DP (vị trí $\times$ giá trị).

### Thuật toán

1. **Khởi tạo** vị trí 1:
   - Nếu $a_1 = 0$: đặt $dp[1][v] = 1$ với mọi $v \in [1, m]$.
   - Nếu $a_1 = v \neq 0$: đặt $dp[1][v] = 1$, các vị trí khác bằng $0$.
2. **Chuyển trạng thái** cho mỗi vị trí $i$ từ $2$ đến $n$:
   - Nếu $a_i = 0$: với mỗi $v \in [1, m]$, tính $dp[i][v] = \sum_{k=\max(1,v-1)}^{\min(m,v+1)} dp[i-1][k]$.
   - Nếu $a_i = v \neq 0$: tính $dp[i][v] = \sum_{k=\max(1,v-1)}^{\min(m,v+1)} dp[i-1][k]$; đặt $dp[i][j] = 0$ với $j \neq v$.
3. **Kết quả**: $\sum_{v=1}^{m} dp[n][v] \pmod{10^9 + 7}$.

Dùng mảng cuộn hai hàng (hoặc ghi đè tại chỗ) vì $dp[i]$ chỉ phụ thuộc $dp[i-1]$.

### Ví dụ minh họa

Input: $n = 3$, $m = 5$, $a = [2, 0, 2]$.

**Vị trí 1** ($a_1 = 2$): $dp[1] = [0, 1, 0, 0, 0]$ (giá trị $1$ đến $5$).

**Vị trí 2** ($a_2 = 0$): Cập nhật tất cả giá trị:
- $dp[2][1] = dp[1][1] + dp[1][2] = 0 + 1 = 1$
- $dp[2][2] = dp[1][1] + dp[1][2] + dp[1][3] = 0 + 1 + 0 = 1$
- $dp[2][3] = dp[1][2] + dp[1][3] + dp[1][4] = 1 + 0 + 0 = 1$
- $dp[2][4] = dp[1][3] + dp[1][4] + dp[1][5] = 0 + 0 + 0 = 0$
- $dp[2][5] = dp[1][4] + dp[1][5] = 0 + 0 = 0$

**Vị trí 3** ($a_3 = 2$): Chỉ cập nhật $dp[3][2]$:
- $dp[3][2] = dp[2][1] + dp[2][2] + dp[2][3] = 1 + 1 + 1 = 3$

Kết quả: $3$ — tương ứng các mảng $[2,1,2]$, $[2,2,2]$, $[2,3,2]$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$ — $n$ vị trí, mỗi vị trí cập nhật tối đa $m$ trạng thái (mỗi trạng thái cộng tối đa 3 giá trị).
- **Không gian:** $O(m)$ — mảng cuộn.

## Mã nguồn (C++)

[Mã nguồn](../code/Array%20Description.cpp)
