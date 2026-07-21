# Removing Digits - Lời giải

**ID:** 1637 | **URL:** https://cses.fi/problemset/task/1637

## Mã nguồn (C++)

### Tóm tắt bài toán

Cho số nguyên dương $n$ ($1 \le n \le 10^6$), tìm số bước ít nhất để đưa $n$ về 0, mỗi bước trừ đi một chữ số khác 0 của số hiện tại.

### Cách 1: BFS trên đồ thị ẩn

**Ý tưởng chính:** Mỗi số nguyên là một đỉnh, cạnh $u \to u - d$ cho mỗi chữ số khác 0 $d$ của $u$. Vì mọi cạnh có chi phí 1, BFS từ $n$ sẽ tìm được đường đi ngắn nhất đến 0. Gọi $dist[u]$ là khoảng cách ngắn nhất từ $n$ đến $u$.

**Tính đúng:** BFS trên đồ thị không trọng số luôn tìm đường đi ngắn nhất. Mỗi bước trừ chữ số tương ứng với một cạnh, nên độ dài đường đi BFS chính là số bước tối thiểu.

**Thuật toán:**
1. Khởi tạo $dist[n] = 0$, đánh dấu $n$ đã thăm, đẩy $n$ vào hàng đợi.
2. Lần lượt lấy đỉnh $u$ ra khỏi hàng đợi. Nếu $u = 0$ thì dừng.
3. Với mỗi chữ số khác 0 $d$ của $u$: nếu $v = u - d$ chưa thăm, đặt $dist[v] = dist[u] + 1$, đánh dấu đã thăm, đẩy $v$ vào hàng đợi.
4. Xuất $dist[0]$.

### Cách 2: Quy hoạch động (Bottom-up)

**Ý tưởng chính:** Gọi $dp[u]$ là số bước tối thiểu để đưa $u$ về 0. Vì mỗi lần trừ giá trị luôn giảm (chữ số $\ge 1$), nên khi tính từ 0 đến $n$, mọi bài toán con $dp[u-d]$ đã được giải:

$$dp[u] = 1 + \min_{d \in \text{digits}(u), d \neq 0} dp[u - d]$$

Trường hợp cơ sở: $dp[0] = 0$.

**Tính đúng (cấu trúc con tối ưu):** Nếu bước đầu tiên tối ưu trừ $d^*$, thì $dp[u - d^*]$ phải tối ưu — nếu không, kết hợp $d^*$ với cách tốt hơn cho $u - d^*$ sẽ cho ít bước hơn cho $u$, mâu thuẫn. Lấy min trên mọi chữ số cho nghiệm tối ưu.

**Thuật toán:**
1. Khởi tạo $dp[0] = 0$, $dp[u] = +\infty$ với $u \ge 1$.
2. Với $u = 1$ đến $n$: trích xuất các chữ số của $u$, đặt $dp[u] = 1 + \min(dp[u-d])$ trên mọi chữ số khác 0 $d$.
3. Xuất $dp[n]$.

### Ví dụ minh họa

**Ví dụ BFS:** $n = 27$. Đường đi tối ưu: $27 \xrightarrow{-7} 20 \xrightarrow{-2} 18 \xrightarrow{-8} 10 \xrightarrow{-1} 9 \xrightarrow{-9} 0$.

Khoảng cách BFS từ $n = 27$:

| $u$ | Cạnh | $dist[u]$ |
|-----|------|------|
| 27 | khởi đầu | 0 |
| 20 | $27 - 7$ | 1 |
| 18 | $20 - 2$ | 2 |
| 10 | $18 - 8$ | 3 |
| 9 | $10 - 1$ | 4 |
| 0 | $9 - 9$ | 5 |

Kết quả: $dist[0] = 5$.

**Ví dụ DP:** $n = 27$. Tính bottom-up từ 0.

Các giá trị $dp$ quan trọng:

| $u$ | Chữ số | Chữ số tốt nhất | $dp[u]$ |
|-----|--------|-----------------|---------|
| 0 | — | — | 0 |
| 1–9 | chính nó | chính nó | 1 |
| 10 | 1 | 1 | $1 + dp[9] = 2$ |
| 18 | 1, 8 | 8 | $1 + dp[10] = 3$ |
| 20 | 2 | 2 | $1 + dp[18] = 4$ |
| 27 | 2, 7 | 7 | $1 + dp[20] = 5$ |

Kết quả: $dp[27] = 5$.

### So sánh

| | BFS | QHD Bottom-up |
|---|---|---|
| **Thời gian** | $O(n \log n)$ | $O(n \log n)$ |
| **Không gian** | $O(n)$ | $O(n)$ |
| **Ưu điểm** | Dừng sớm khi đến 0 | Code đơn giản, không cần queue |
| **Mã nguồn** | [C++ (BFS)](../code/Removing%20Digits%20-%20BFS.cpp) | [C++ (DP)](../code/Removing%20Digits%20-%20DP.cpp) |

## Độ phức tạp

- **Cách 1:** $O(n \log n)$ thời gian, $O(n)$ không gian
- **Cách 2:** $O(n \log n)$ thời gian, $O(n)$ không gian
