# Điều Tra - Lời giải

**ID:** 1202 | **URL:** https://cses.fi/problemset/task/1202

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng với trọng số dương. Từ đỉnh 1 đến đỉnh $n$, tìm: (1) khoảng cách ngắn nhất, (2) số đường đi ngắn nhất mod $10^9+7$, (3) số cạnh tối thiểu trong đường ngắn nhất, (4) số cạnh tối đa trong đường ngắn nhất.

### Ý tưởng chính

Mở rộng Dijkstra để theo dõi bốn giá trị cho mỗi đỉnh $u$:
- $d[u]$: khoảng cách ngắn nhất từ 1 đến $u$
- $\text{num}[u]$: số đường đi ngắn nhất từ 1 đến $u$ (mod $10^9+7$)
- $\text{Min}[u]$: số cạnh tối thiểu trong đường ngắn nhất đến $u$
- $\text{Max}[u]$: số cạnh tối đa trong đường ngắn nhất đến $u$

Khi relax cạnh $u \to v$ trọng số $c$, tính $\text{tmp} = d[u] + c$:
- **Nếu $d[v] > \text{tmp}$** (tìm đường ngắn hơn): đặt lại $d[v] = \text{tmp}$, $\text{num}[v] = \text{num}[u]$, $\text{Min}[v] = \text{Min}[u] + 1$, $\text{Max}[v] = \text{Max}[u] + 1$.
- **Nếu $d[v] = \text{tmp}$** (thêm đường ngắn nhất): $\text{num}[v] \mathrel{+}= \text{num}[u]$, $\text{Min}[v] = \min(\text{Min}[v], \text{Min}[u] + 1)$, $\text{Max}[v] = \max(\text{Max}[v], \text{Max}[u] + 1)$.

Cách làm đúng vì Dijkstra xử lý đỉnh theo thứ tự khoảng cách không giảm (trọng số dương). Khi $u$ được xử lý, $d[u]$ đã cuối — không có đường ngắn hơn đến $u$. Mọi đường ngắn nhất đến $v$ phải đi qua một tiền nhiệm $u$ với $d[u] + c = d[v]$, nên nguyên lý cộng đảm bảo $\text{num}$, $\text{Min}$, $\text{Max}$ được tích lũy đúng từ tất cả các tiền nhiệm.

### Thuật toán

1. Khởi tạo: $d[1] = 0$, $\text{num}[1] = 1$, $\text{Min}[1] = 0$, $\text{Max}[1] = 0$; các đỉnh khác: $d = \infty$, $\text{num} = 0$, $\text{Min} = \infty$, $\text{Max} = 0$.
2. Chạy Dijkstra với hàng đợi ưu tiên. Khi xử lý đỉnh $u$, relax mỗi cạnh $u \to v$ theo quy tắc trên.
3. Xuất $d[n]$, $\text{num}[n]$, $\text{Min}[n]$, $\text{Max}[n]$.

### Ví dụ minh họa

Đầu vào:
```
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3
```

Dijkstra từ đỉnh 1:
- Xử lý 1 ($d=0$): $d[4]=5$ (1 cạnh), $d[2]=4$ (1 cạnh), $d[3]=2$ (1 cạnh).
- Xử lý 3 ($d=2$): $3\to4$ cho $\text{tmp}=5 = d[4]$. Thêm đường ngắn nhất: $\text{num}[4] = 1+1=2$, $\text{Min}[4] = \min(1, 2) = 1$, $\text{Max}[4] = \max(1, 2) = 2$.
- Xử lý 2 ($d=4$): $2\to4$ cho $\text{tmp}=9 > d[4]$, bỏ qua.
- Xử lý 4 ($d=5$): không có cạnh đi ra.

2 đường ngắn nhất: $1 \to 4$ (1 cạnh, giá 5) và $1 \to 3 \to 4$ (2 cạnh, giá 5).

Kết quả: `5 2 1 2`

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Investigation.cpp)
