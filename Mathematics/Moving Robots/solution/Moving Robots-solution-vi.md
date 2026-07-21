# Moving Robots - Lời giải

**ID:** 1726 | **URL:** https://cses.fi/problemset/task/1726

## Phương pháp

### Tóm tắt bài toán

Bàn cờ $8 \times 8$, mỗi ô có một robot. Mỗi robot di chuyển độc lập $k$ bước ngẫu nhiên, mỗi bước chọn đều một hướng hợp lệ (lên, xuống, trái, phải, không đi ra ngoài). Nhiều robot có thể cùng đứng một ô. Tính kỳ vọng số ô trống sau $k$ bước, làm tròn 6 chữ số thập phân.

### Ý tưởng chính

Theo **tính tuyến tính của kỳ vọng**, kỳ vọng số ô trống bằng tổng xác suất mỗi ô trống:

$$E[\text{số ô trống}] = \sum_{(x,y)} P(\text{ô } (x,y) \text{ trống})$$

Vì các robot di chuyển độc lập, ô $(x,y)$ trống khi và chỉ khi **không** robot nào kết thúc tại đó. Xác suất là tích các xác suất đối:

$$P(\text{ô } (x,y) \text{ trống}) = \prod_{(i,j)} \left(1 - P_{(i,j) \to (x,y)}(k)\right)$$

trong đó $P_{(i,j) \to (x,y)}(k)$ là xác suất robot xuất phát từ $(i,j)$ đến $(x,y)$ sau $k$ bước.

Để tính $P_{(i,j) \to (x,y)}(k)$, dùng quy hoạch động cho bước đi ngẫu nhiên. Gọi $dp[t][x][y]$ là xác suất robot (xuất phát từ $(i,j)$) có mặt tại $(x,y)$ sau $t$ bước. Công thức chuyển trạng thái áp dụng quy tắc xác suất toàn phần — robot phải đến từ một láng giềng $(u,v)$ đã chọn hướng đi về phía $(x,y)$:

$$dp[t][x][y] = \sum_{(u,v) \in \text{Láng giềng}(x,y)} \frac{dp[t-1][u][v]}{\text{bậc}(u,v)}$$

trong đó $\text{bậc}(u,v)$ là số láng giềng hợp lệ của $(u,v)$ (2 cho góc, 3 cho biên, 4 cho nội tâm). Cơ sở: $dp[0][i][j] = 1$, các ô khác bằng 0.

### Thuật toán

1. Khởi tạo $ans[x][y] = 1$ cho mọi ô.
2. Với mỗi vị trí xuất phát $(i,j)$:
   - Đặt $dp[0][i][j] = 1$.
   - Với $t = 1, \ldots, k$: cập nhật $dp[t]$ từ $dp[t-1]$ bằng công thức chuyển.
   - Với mỗi ô $(x,y)$: $ans[x][y] \mathrel{\times}= (1 - dp[k][x][y])$.
3. Cộng tất cả $ans[x][y]$ và xuất kết quả làm tròn 6 chữ số thập phân.

### Ví dụ minh họa

$k = 10$: kỳ vọng số ô trống là **23.120740**.

Minh họa phép tính con với $k = 1$: robot ở góc $(1,1)$ có bậc 2, nên xác suất đi đến $(1,2)$ hoặc $(2,1)$ mỗi hướng là $1/2$. Sau 1 bước, $P_{(1,1) \to (1,2)}(1) = 1/2$.

## Độ phức tạp

- **Thời gian:** $O(64 \cdot k \cdot 64) = O(k)$ (64 vị trí xuất phát, mỗi lần $k$ bước trên 64 ô)
- **Không gian:** $O(k \cdot 64)$, có thể tối giản xuống $O(64)$ bằng cách chỉ giữ 2 lớp thời gian

## Mã nguồn (C++)

[Mã nguồn](../code/Moving%20Robots.cpp)
