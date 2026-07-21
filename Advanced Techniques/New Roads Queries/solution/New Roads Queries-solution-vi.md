# New Roads Queries - Lời giải

**ID:** 2101 | **URL:** https://cses.fi/problemset/task/2101

## Phương pháp

### Tóm tắt bài toán

$n$ thành phố ban đầu không có đường. Mỗi ngày xây một đường mới (tổng $m$ đường). Với $q$ truy vấn "sau bao nhiêu ngày thì có thể đi từ $a$ đến $b$ lần đầu tiên?", trả lời (hoặc $-1$ nếu không bao giờ liên thông).

### Ý tưởng chính

Với truy vấn $(a, b)$, đáp án là ngày nhỏ nhất $d$ mà sau khi thêm $d$ đường đầu tiên, $a$ và $b$ liên thông. Tính liên thông có tính **đơn điệu**: nếu $a$ và $b$ liên thông sau ngày $d$, chúng vẫn liên thông ở mọi ngày sau đó. Tính đơn điệu cho phép áp dụng tìm kiếm nhị phân trên đáp án.

**Tìm kiếm nhị phân song song (PBS):** Thay vì chạy tìm kiếm nhị phân riêng cho từng truy vấn ($O(q \cdot m \log m)$), xử lý tất cả truy vấn cùng lúc. Mỗi lần lặp, mỗi truy vấn hoạt động tính trung điểm $mid$ và xếp vào bucket theo $mid$. Sau đó, một lần quét thêm cạnh 1 đến $m$ vào DSU; sau khi thêm cạnh $i$, kiểm tra tất cả truy vấn trong bucket $i$ với DSU. Tổng số thao tác DSU giảm xuống $O((m + q) \log m)$.

### Thuật toán

1. Khởi tạo mỗi truy vấn $L=1$, $R=m$, `ans=-1` (hoặc 0 nếu $a=b$).
2. Lặp cho đến khi không còn truy vấn hoạt động:
   - Với mỗi truy vấn hoạt động, tính $mid = (L+R)/2$, xếp vào bucket $mid$.
   - Reset DSU về $n$ đỉnh biệt lập.
   - Quét cạnh $i = 1 \dots m$: gộp cạnh, kiểm tra từng truy vấn trong bucket $i$:
     - Nếu $a$ và $b$ liên thông: đặt `ans = i`, $R = i - 1$.
     - Ngược lại: $L = i + 1$.
3. Xuất đáp án.

### Ví dụ minh họa

$n=5$, $m=4$, đường: $(1,2), (2,3), (1,3), (2,5)$. Truy vấn: $(1,3), (3,4), (3,5)$.

**Lần lặp 1:** tất cả truy vấn $[1,4]$, $mid=2$, bucket[2] = $\{(1,3), (3,4), (3,5)\}$.

| Sau cạnh | Thành phần DSU | Kiểm tra bucket |
|----------|----------------|-----------------|
| 1: (1,2) | {1,2} {3} {4} {5} | — |
| 2: (2,3) | {1,2,3} {4} {5} | (1,3): liên thông → ans=2, R=1; (3,4): chưa → L=3; (3,5): chưa → L=3 |

**Lần lặp 2:** (3,4) và (3,5) đều $[3,4]$, $mid=3$, bucket[3] = $\{(3,4), (3,5)\}$.

Quét đến cạnh 3: DSU = {1,2,3} {4} {5}. (3,4): chưa liên thông → L=4. (3,5): chưa liên thông → L=4.

**Lần lặp 3:** cả hai $[4,4]$, $mid=4$, bucket[4] = $\{(3,4), (3,5)\}$.

Quét đến cạnh 4: thêm (2,5). DSU = {1,2,3,5} {4}. (3,4): chưa liên thông → ans=-1. (3,5): liên thông → ans=4.

Kết quả: **(1,3)→2, (3,4)→−1, (3,5)→4**.

## Độ phức tạp

- **Thời gian:** $O((m + q) \log m \cdot \alpha(n))$
- **Bộ nhớ:** $O(n + m + q)$

## Mã nguồn (C++)

[Mã nguồn](../code/New%20Roads%20Queries.cpp)
