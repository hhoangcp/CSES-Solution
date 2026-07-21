# Monster Game II - Lời giải

**ID:** 2085 | **URL:** https://cses.fi/problemset/task/2085

## Phương pháp

### Tóm tắt bài toán

Giống Monster Game I: $n$ màn, giết quái mất $s_i \cdot f$ thời gian, sau đó nhận hệ số kỹ năng mới. Tuy nhiên sức mạnh $s_i$ và hệ số $f_i$ **không nhất thiết được sắp xếp** — không có điều kiện đơn điệu. Tìm tổng thời gian tối thiểu.

### Ý tưởng chính

Công thức QHD giống Monster Game I:

$$dp[i] = \min_{j < i} \left( dp[j] + s_i \cdot f_j \right)$$

Đây là tối thiểu các đường thẳng $y = f_j \cdot x + dp[j]$ đánh giá tại $x = s_i$. Tuy nhiên, vì cả hệ góc $f_j$ và điểm truy vấn $s_i$ đều có thể bất kỳ thứ tự, CHT dùng deque không áp dụng được. Thay vào đó, ta dùng **Cây Li Chao**, hỗ trợ chèn đường thẳng và truy vấn tối thiểu tại điểm bất kỳ trong $O(\log C)$, không cần tính đơn điệu.

**Nguyên lý cây Li Chao:** Cây đoạn trên miền $[1, C]$, mỗi nút lưu một đường thẳng. Khi chèn đường $P$ vào nút $[l, r]$ đang lưu $Q$: so sánh tại trung điểm $mid$. Nếu $P(mid) < Q(mid)$, đổi — đường tốt hơn tại $mid$ ở lại. Đường bị đẩy có thể vẫn tốt hơn ở một nửa: kiểm tra bên nào và đệ quy xuống. Truy vấn: duyệt gốc đến lá, lấy tối thiểu tất cả đường trên đường đi. Đường tốt hơn tại $x$ nhưng bị đẩy khỏi nút sẽ được tìm thấy ở con chứa $x$.

### Thuật toán

1. Xây cây Li Chao trên miền $[1, 10^6]$.
2. Chèn đường ban đầu $y = C \cdot x + 0$.
3. Với mỗi quái $i$:
   - Truy vấn tại $x = s_i$ → $dp[i]$.
   - Chèn đường $y = f_i \cdot x + dp[i]$.
4. Xuất $dp[n]$.

### Ví dụ minh họa

$n = 5$, $C = 100$. Sức mạnh: $[50, 20, 30, 90, 30]$. Hệ số: $[60, 20, 20, 10, 90]$.

| $i$ | $s_i$ | $f_i$ | $dp[i]$ | Đường thêm |
|-----|--------|--------|----------|------------|
| 1 | 50 | 60 | $0 + 50 \cdot 100 = 5000$ | $60x + 5000$ |
| 2 | 20 | 20 | $\min(2000, 6200) = 2000$ | $20x + 2000$ |
| 3 | 30 | 20 | $\min(3000, 6800, 2600) = 2600$ | $20x + 2600$ |
| 4 | 90 | 10 | $\min(9000, 10400, 3800, 4400) = 3800$ | $10x + 3800$ |
| 5 | 30 | 90 | $\min(3000, 6800, 2600, 3200, 4100) = 2600$ | — |

Đáp án: 2600 (giết quái 2 chi phí 2000, rồi quái 5 chi phí 600).

## Độ phức tạp

- **Thời gian:** $O(n \log C)$ với $C = 10^6$.
- **Không gian:** $O(C)$ — cây đoạn $4 \cdot MAX$ nút.

## Mã nguồn (C++)

[Mã nguồn](../code/Monster%20Game%20II.cpp)
