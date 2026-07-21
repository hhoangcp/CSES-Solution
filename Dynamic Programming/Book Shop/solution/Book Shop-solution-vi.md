# Book Shop - Lời giải

**ID:** 1158 | **URL:** https://cses.fi/problemset/task/1158

## Hướng tiếp cận

### Tóm tắt bài toán

Cho $n$ cuốn sách có giá $h_i$ và số trang $s_i$, ngân sách tối đa $x$. Mỗi sách chỉ mua tối đa một lần. Tìm tổng số trang lớn nhất mà tổng giá không vượt quá $x$.

### Ý tưởng chính

Đây là bài toán **Knapsack 0/1** cổ điển: chọn tập con từ $n$ vật, mỗi vật có trọng lượng $h_i$ và giá trị $s_i$, tối đa hóa tổng giá trị với giới hạn trọng lượng $x$. Mỗi vật chỉ được dùng tối đa một lần.

Gọi $dp[j]$ là tổng số trang lớn nhất đạt được với tổng giá **tối đa** $j$. Công thức truy hồi cho mỗi cuốn sách $i$:

$$dp[j] = \max(dp[j], dp[j - h_i] + s_i) \quad \text{với } j = x, x-1, \ldots, h_i$$

Điểm mấu chốt là duyệt $j$ theo chiều ngược. Nếu duyệt xuôi, $dp[j - h_i]$ có thể đã chứa sách $i$ (cập nhật trước đó trong cùng vòng), khiến sách $i$ được đếm hai lần — biến bài toán thành knapsack không hạn chế. Duyệt ngược đảm bảo $dp[j - h_i]$ vẫn chỉ phản ánh các sách $1, \ldots, i-1$, nên mỗi sách chỉ được chọn tối đa một lần. Điều này cũng đảm bảo cấu trúc con tối ưu: nếu lời giải tối ưu cho ngân sách $j$ chứa sách $i$, thì phần còn lại phải tối ưu cho ngân sách $j - h_i$; nếu không, thay bằng lời giải con tốt hơn sẽ cải thiện tổng thể, mâu thuẫn tính tối ưu.

### Thuật toán

1. Khởi tạo $dp[0 \ldots x] = 0$.
2. Với mỗi sách $i$ từ $1$ đến $n$, đọc giá $h_i$ và số trang $s_i$:
   - Với $j = x$ xuống $h_i$: $dp[j] = \max(dp[j], dp[j - h_i] + s_i)$.
3. Kết quả là $dp[x]$.

### Ví dụ minh họa

Input: $n = 4$, $x = 10$, giá $= \{4, 8, 5, 3\}$, số trang $= \{5, 12, 8, 1\}$.

| Sau sách | $dp[0]$ | $dp[1\textendash 2]$ | $dp[3]$ | $dp[4]$ | $dp[5]$ | $dp[6\textendash 7]$ | $dp[8]$ | $dp[9\textendash 10]$ |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 (4, 5) | 0 | 0 | 0 | 5 | 5 | 5 | 5 | 5 |
| 2 (8, 12) | 0 | 0 | 0 | 5 | 5 | 5 | 12 | 12 |
| 3 (5, 8) | 0 | 0 | 0 | 5 | 8 | 8 | 12 | 13 |
| 4 (3, 1) | 0 | 0 | 1 | 5 | 8 | 8 | 12 | 13 |

Kết quả: $dp[10] = 13$ — mua sách 1 và 3 (giá $4 + 5 = 9$, trang $5 + 8 = 13$).

## Độ phức tạp

- **Thời gian:** $O(n \cdot x)$
- **Không gian:** $O(x)$

## Mã nguồn (C++)

[Mã nguồn](../code/Book%20Shop.cpp)
