# Concert Tickets - Lời giải

**ID:** 1091 | **URL:** https://cses.fi/problemset/task/1091

## Phương pháp

### Tóm tắt bài toán

Có $n$ vé xem hòa nhạc với giá $h_i$, $m$ khách hàng đến theo thứ tự, khách thứ $j$ sẵn sàng trả tối đa $t_j$. Mỗi khách mua vé có giá cao nhất mà không vượt quá ngân sách của họ. Mỗi vé chỉ bán một lần. Nếu không có vé phù hợp, khách đó không mua. Xác định giá vé mỗi khách mua được (hoặc $-1$).

### Ý tưởng chính

Với mỗi khách hàng có ngân sách $b$, ta cần tìm vé có giá lớn nhất thỏa $\le b$ — đây là bài toán tìm predecessor. Lựa chọn này tối ưu toàn cục vì bán vé đắt nhất phù hợp cho khách hiện tại sẽ giữ lại các vé rẻ hơn cho khách sau: mọi khách sau có ngân sách $b' \ge v^*$ đều cũng mua được vé rẻ $v' < v^*$, nhưng ngược lại, khách có ngân sách $v' \le b' < v^*$ không thể mua vé $v^*$. Do đó, bán $v^*$ cho khách hiện tại không bao giờ làm giảm tổng số vé bán được.

Để thực hiện predecessor search hiệu quả, ta dùng `multiset` (cây tìm kiếm nhị phân cân bằng). Hàm `upper_bound(b)` trả về iterator trỏ phần tử đầu tiên $> b$; giảm iterator đi 1 (`--it`) cho phần tử lớn nhất $\le b$. Nếu `upper_bound` trả về `begin()`, không có phần tử nào $\le b$.

### Thuật toán

1. Nạp tất cả $n$ vé vào `multiset`.
2. Với mỗi khách hàng có ngân sách $b$:
   - Gọi `it = S.upper_bound(b)`.
   - Nếu `it == S.begin()`: không có vé phù hợp, xuất $-1$.
   - Ngược lại: `--it`, xuất `*it`, xóa bằng `S.erase(it)`.

### Ví dụ minh họa

$n = 5$, $m = 3$. Vé: $[5, 3, 7, 8, 5]$, Khách: $[4, 8, 3]$.

$S = \{3, 5, 5, 7, 8\}$.

| Khách | $b$ | `upper_bound(b)` | `--it` | Kết quả | $S$ sau |
|-------|-----|-------------------|--------|----------|---------|
| 1 | 4 | → 5 | → 3 | **3** | $\{5, 5, 7, 8\}$ |
| 2 | 8 | → end() | → 8 | **8** | $\{5, 5, 7\}$ |
| 3 | 3 | → 5 = begin() | — | **-1** | $\{5, 5, 7\}$ |

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Concert%20Tickets.cpp)
