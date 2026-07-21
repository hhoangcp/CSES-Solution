# Houses and Schools - Lời giải

**ID:** 2087 | **URL:** https://cses.fi/problemset/task/2087

## Phương pháp

### Tóm tắt bài toán

Có $n$ ngôi nhà trên một con phố, đánh số $1, 2, \ldots, n$. Khoảng cách giữa hai nhà $a$ và $b$ là $|a - b|$. Xây $k$ trường học (mỗi trường tại một nhà) sao cho mỗi trẻ đến trường gần nhất. Tối thiểu hóa tổng khoảng cách đi bộ.

### Ý tưởng chính

**Tính liên tiếp của phân vùng:** Trong phương án tối ưu, các trường chia nhà thành $k$ nhóm liên tiếp trên đường thẳng. Nếu trường $A$ tại $p$ phục vụ nhà $h_2$ còn trường $B$ tại $q > p$ phục vụ nhà $h_1 < h_2$, đổi gán $h_1$ cho $A$ hoặc $h_2$ cho $B$ không tăng chi phí do tính lồi của $|x - p|$. Điều này cho phép dùng QHD trên các phân vùng.

**Hàm chi phí:** Định nghĩa $dp[t][j]$ = chi phí tối thiểu cho $j$ nhà đầu tiên dùng $t$ trường, với trường thứ $t$ tại vị trí $j$. Công thức chuyển:

$$dp[t][j] = \min_{k < j} \left(dp[t-1][k] + \text{Cost}(k, j)\right)$$

trong đó $\text{Cost}(k, j) = \text{Left}[k][mid] + \text{Right}[mid{+}1][j]$ với $mid = (k+j)/2$. Nhà $k$ đến $mid$ đi trường $k$ (gần hơn), nhà $mid{+}1$ đến $j$ đi trường $j$ (gần hơn). Tính trước:
- $\text{Left}[i][j] = \sum_{k=i}^{j}(k-i) \cdot c_k$: tổng khoảng cách từ nhà $i \ldots j$ đến vị trí $i$.
- $\text{Right}[j][i] = \sum_{k=j}^{i}(i-k) \cdot c_k$: tổng khoảng cách từ nhà $j \ldots i$ đến vị trí $i$.

**Tối ưu chia để trị:** Hàm chi phí thỏa mãn **bất đẳng thức tứ giác** $\text{Cost}(a,c) + \text{Cost}(b,d) \le \text{Cost}(a,d) + \text{Cost}(b,c)$ với $a \le b \le c \le d$, đảm bảo điểm chuyển tối ưu đơn điệu. Điều này cho phép tối ưu chia để trị, giảm QHD từ $O(kn^2)$ xuống $O(kn \log n)$.

### Thuật toán

1. Tính trước bảng `Left` và `Right` trong $O(n^2)$.
2. Cơ sở: $dp[1][j] = \text{Right}[1][j]$.
3. Với mỗi $t = 2 \ldots k$, tính $dp[t][\cdot]$ bằng tối ưu chia để trị.
4. Đáp án: $\min_{j=k}^{n} (dp[k][j] + \text{Left}[j][n])$ (trường cuối tại $j$ phục vụ các nhà bên phải).

### Ví dụ minh họa

$n = 6$, $k = 2$, trẻ em: $[2, 7, 1, 4, 6, 4]$.

Tối ưu: trường tại nhà 2 và 5.

| Nhà | Trẻ em | Trường gần nhất | Khoảng cách | Chi phí |
|-----|--------|-----------------|-------------|---------|
| 1 | 2 | 2 | 1 | $2 \cdot 1 = 2$ |
| 2 | 7 | 2 | 0 | 0 |
| 3 | 1 | 2 | 1 | $1 \cdot 1 = 1$ |
| 4 | 4 | 5 | 1 | $4 \cdot 1 = 4$ |
| 5 | 6 | 5 | 0 | 0 |
| 6 | 4 | 5 | 1 | $4 \cdot 1 = 4$ |

Tổng: $2 + 0 + 1 + 4 + 0 + 4 = 11$.

## Độ phức tạp

- **Thời gian:** $O(n^2 + k \cdot n \log n)$ — tiền xử lý $O(n^2)$, QHD chia để trị $O(kn \log n)$.
- **Không gian:** $O(n^2)$ — bảng Left, Right.

## Mã nguồn (C++)

[Mã nguồn](../code/Houses%20and%20Schools.cpp)
