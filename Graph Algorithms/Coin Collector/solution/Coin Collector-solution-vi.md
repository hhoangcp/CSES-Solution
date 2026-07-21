# Người Thu Thập Tiền - Lời giải

**ID:** 1686 | **URL:** https://cses.fi/problemset/task/1686

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng gồm $n$ phòng (mỗi phòng chứa một số đồng xu) và $m$ đường hầm một chiều. Tìm số đồng xu tối đa có thể thu thập, biết rằng có thể bắt đầu và kết thúc ở bất kỳ phòng nào, mỗi phòng chỉ thu đồng xu một lần.

### Ý tưởng chính

Trong đồ thị có hướng, khi vào một thành phần liên thông mạnh (SCC), ta có thể đến mọi đỉnh trong đó và thu thập toàn bộ đồng xu. Do đó, ta **ngưng tụ đồ thị**: gộp mỗi SCC thành một siêu đỉnh với trọng số bằng tổng đồng xu của SCC đó. Đồ thị ngưng tụ được là DAG (chu trình trong đồ thị ngưng tụ sẽ mâu thuẫn với phân tách SCC).

Trên DAG này, số đồng xu tối đa từ siêu đỉnh $u$ là:
$$dp[u] = W[u] + \max_{(u,v) \in E'} dp[v]$$

Công thức này đúng vì:
- **Ngưng tụ bảo toàn khả năng tiếp cận:** Trong SCC, mọi đỉnh đều đến được nhau, nên gộp thành một đỉnh có trọng số tương đương. Các cạnh giữa SCC trong đồ thị ngưng tụ giữ nguyên quan hệ tiếp cận của đồ thị gốc.
- **DP đúng trên DAG:** Quy nạp theo thứ tự tô-pô ngược: nếu $u$ không có cạnh ra, $dp[u] = W[u]$ (cơ sở). Ngược lại, từ $u$ ta đi đến một đỉnh kề $v$ và thu thêm $dp[v]$ đồng xu tối ưu (theo giả thiết quy nạp), nên $dp[u] = W[u] + \max_v dp[v]$. Cấu trúc DAG đảm bảo thứ tự tô-pô hợp lệ cho quy nạp.

Đáp án: $\max_u dp[u]$ (vì có thể bắt đầu từ bất kỳ phòng nào).

### Thuật toán

1. **Tìm SCC** bằng thuật toán Tarjan: chạy DFS duy trì `num[u]`, `low[u]`, và ngăn xếp. Khi `low[u] >= num[u]`, lấy tất cả đỉnh từ đỉnh ngăn xếp đến $u$ thành một SCC.
2. **Xây đồ thị ngưng tụ**: với mỗi cạnh gốc $(u, v)$, nếu $\text{lab}[u] \neq \text{lab}[v]$, thêm cạnh $\text{lab}[u] \to \text{lab}[v]$. Tính $W[i] = \sum_{v \in \text{SCC}_i} w_v$.
3. **DP trên DAG**: chạy DFS trên đồ thị ngưng tụ. Với mỗi siêu đỉnh $u$, tính $dp[u] = W[u] + \max_{v} dp[v]$ trên tất cả đỉnh kề $v$ (tính $dp[v]$ đệ quy trước).
4. Xuất $\max_u dp[u]$.

### Ví dụ minh họa

Đầu vào:
```
4 4
4 5 2 7
1 2
2 1
1 3
2 4
```

- SCC 1: $\{1, 2\}$ (đến được nhau qua $1 \to 2, 2 \to 1$), $W_1 = 4 + 5 = 9$.
- SCC 2: $\{3\}$, $W_2 = 2$.
- SCC 3: $\{4\}$, $W_3 = 7$.
- Cạnh ngưng tụ: $1 \to 2$ (từ cạnh $1 \to 3$), $1 \to 3$ (từ cạnh $2 \to 4$).

DP: $dp[2] = 2$, $dp[3] = 7$, $dp[1] = 9 + \max(2, 7) = 16$.

Kết quả: `16`

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — Tarjan, xây dựng đồ thị ngưng tụ, và DP trên DAG đều tuyến tính.
- **Không gian:** $O(n + m)$ — lưu đồ thị gốc, đồ thị ngưng tụ, và các mảng phụ.

## Mã nguồn (C++)

[Mã nguồn](../code/Coin%20Collector.cpp)
