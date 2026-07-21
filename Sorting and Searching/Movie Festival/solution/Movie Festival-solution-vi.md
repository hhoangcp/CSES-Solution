# Movie Festival - Lời giải

**ID:** 1629 | **URL:** https://cses.fi/problemset/task/1629

## Hướng tiếp cận

Sắp xếp tất cả $n$ bộ phim theo thời gian kết thúc tăng dần. Gọi mảng sau khi sắp xếp là $P[1], P[2], \ldots, P[n]$ với $P[1].v \le P[2].v \le \cdots \le P[n].v$.

Định nghĩa $f[i]$ = số phim tối đa có thể xem từ tập $\{P[1], \ldots, P[i]\}$, với $f[0] = 0$.

Với phim thứ $i$, ta có hai lựa chọn:

1. **Không xem phim $i$:** $f[i] = f[i-1]$.
2. **Xem phim $i$:** tìm chỉ số lớn nhất $\text{pos}$ sao cho $P[\text{pos}].v \le P[i].u$, khi đó $f[i] = f[\text{pos}] + 1$. Vì mảng đã sắp theo thời gian kết thúc, ta tìm $\text{pos}$ bằng tìm kiếm nhị phân trong $O(\log n)$.

Công thức chuyển: $f[i] = \max(f[i-1], f[\text{pos}] + 1)$, với $\text{pos} = 0$ nếu không có phim nào kết thúc trước khi phim $i$ bắt đầu.

**Tính đúng:** Bằng quy nạp. Nếu nghiệm tối ưu cho $\{P[1], \ldots, P[i]\}$ không chọn phim $i$, thì nghiệm là tập con của $\{P[1], \ldots, P[i-1]\}$, cho kết quả $f[i-1]$. Nếu chọn phim $i$, mọi phim khác phải kết thúc trước $P[i].u$; vì mảng đã sắp theo thời gian kết thúc, các phim này có chỉ số $\le \text{pos}$, cho kết quả $f[\text{pos}] + 1$. Max của hai trường hợp là tối ưu.

Đáp án là $f[n]$.

**Chú thích:** Bài toán này cũng có thể giải bằng tham lam (luôn chọn phim kết thúc sớm nhất). Cách tiếp cận DP tổng quát hơn và mở rộng được cho biến thể có trọng số.

### Ví dụ minh họa

Xét $n = 3$, các phim: $(3, 5)$, $(4, 9)$, $(5, 8)$. Sau khi sắp xếp theo thời gian kết thúc: $P[1] = (3, 5)$, $P[2] = (5, 8)$, $P[3] = (4, 9)$.

| $i$ | $P[i]$ | $\text{pos}$ (lớn nhất thỏa $P[\text{pos}].v \le P[i].u$) | $f[i] = \max(f[i-1], f[\text{pos}]+1)$ | $f[i]$ |
|---|---|---|---|---|
| 0 | — | — | Khởi tạo | 0 |
| 1 | $(3, 5)$ | Không có phim trước → $0$ | $\max(0, 0+1)$ | 1 |
| 2 | $(5, 8)$ | $P[1].v = 5 \le 5$ → $1$ | $\max(1, 1+1)$ | 2 |
| 3 | $(4, 9)$ | $P[1].v = 5 > 4$ → $0$ | $\max(2, 0+1)$ | 2 |

Đáp án: $f[3] = 2$ — xem phim $(3, 5)$ và $(5, 8)$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp $O(n \log n)$, mỗi bước duyệt thực hiện tìm kiếm nhị phân $O(\log n)$.
- **Bộ nhớ:** $O(n)$ — mảng phim và mảng quy hoạch động.

## Mã nguồn (C++)

[Mã nguồn](../code/Movie%20Festival.cpp)
