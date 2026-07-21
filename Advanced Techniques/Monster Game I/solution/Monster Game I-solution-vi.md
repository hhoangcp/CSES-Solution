# Monster Game I - Lời giải

**ID:** 2084 | **URL:** https://cses.fi/problemset/task/2084

## Phương pháp

### Tóm tắt bài toán

Bạn đang chơi trò chơi $n$ màn. Mỗi màn có quái vật. Ở màn $1 \ldots n-1$ có thể giết hoặc bỏ chạy, ở màn $n$ phải giết quái cuối. Giết quái mất $s \cdot f$ thời gian ($s$ = sức mạnh, $f$ = hệ số kỹ năng). Sau khi giết, nhận hệ số mới. Tìm tổng thời gian tối thiểu.

### Ý tưởng chính

Định nghĩa $dp[i]$ = thời gian tối thiểu để vừa giết quái $i$ (hệ số cập nhật thành $f_i$). Công thức chuyển:

$$dp[i] = \min_{j < i} \left( dp[j] + s_i \cdot f_j \right)$$

trong đó $j=0$ là trạng thái ban đầu với $dp[0]=0$, $f_0=C$. Công thức có dạng $\min_j (f_j \cdot x + dp[j])$ đánh giá tại $x = s_i$ — tối thiểu các đường thẳng, giải bằng **Convex Hull Trick (CHT)**.

**Tại sao CHT dùng deque hiệu quả:** Bài toán đảm bảo hệ góc $f_j$ không tăng và truy vấn $s_i$ không giảm. Hệ góc không tăng nên đường mới chèn vào cuối deque. Truy vấn không giảm nên đường tối ưu chỉ dịch tiến — nếu đường đầu thua đường kế tiếp tại $x = s_i$, nó sẽ thua tại mọi truy vấn sau, nên có thể loại an toàn.

Khi chèn đường mới $P$ vào cuối, ta loại đường cuối cũ $B$ nếu nó trở nên vô dụng: ba đường liên tiếp $A, B, P$ mà $B$ vô dụng khi giao $A, P$ nằm bên trái hoặc tại giao $A, B$ (kiểm tra bằng nhân chéo tránh dấu phẩy động).

### Thuật toán

1. Chèn đường ban đầu $y = C \cdot x + 0$ vào deque.
2. Với mỗi quái $i$ từ 1 đến $n$:
   - **Truy vấn:** trong khi deque $\ge 2$ đường và đường đầu cho giá trị $\ge$ đường thứ hai tại $x = s_i$, loại đầu. Đặt $dp[i] = \text{đầu}.get\_Y(s_i)$.
   - **Chèn:** trong khi deque $\ge 2$ đường và nhân chéo 3 đường cuối cho thấy đường áp chốt vô dụng, loại cuối. Chèn đường $y = f_i \cdot x + dp[i]$.
3. Xuất $dp[n]$.

### Ví dụ minh họa

$n = 5$, $C = 100$. Sức mạnh: $[20, 30, 30, 50, 90]$. Hệ số: $[90, 60, 20, 20, 10]$.

| $i$ | $s_i$ | Đường trong deque (trước truy vấn) | $dp[i]$ | Đường thêm |
|-----|--------|--------------------------------------|---------|------------|
| 1 | 20 | $(100, 0)$ | $100 \cdot 20 = 2000$ | $(90, 2000)$ |
| 2 | 30 | $(100, 0), (90, 2000)$ | $\min(3000, 4700) = 3000$ | $(60, 3000)$ |
| 3 | 30 | $(100, 0), (60, 3000)$ | $\min(3000, 4800) = 3000$ | $(20, 3000)$ |
| 4 | 50 | $(100, 0), (20, 3000)$ | $\min(5000, 4000) = 4000$ | $(20, 4000)$ |
| 5 | 90 | $(20, 3000), (20, 4000)$ | $20 \cdot 90 + 3000 = 4800$ | — |

Lưu ý: tại $i=2$, đường $(90,2000)$ bị loại vì $(60,3000)$ vượt trội. Tại $i=3$, đường $(60,3000)$ bị loại tương tự. Tại $i=4$, đường $(100,0)$ bị loại khỏi đầu vì $(20,3000)$ tốt hơn tại $x=50$.

Đáp án: 4800 (giết quái 3, rồi quái 5).

## Độ phức tạp

- **Thời gian:** $O(n)$ — mỗi đường chèn và loại tối đa 1 lần.
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Monster%20Game%20I.cpp)
