# Movie Festival II - Lời giải

**ID:** 1632 | **URL:** https://cses.fi/problemset/task/1632

## Hướng tiếp cận

Sắp xếp tất cả phim theo thời gian kết thúc tăng dần. Thứ tự tham lam này đảm bảo rằng chọn phim kết thúc sớm không bao giờ chặn nhiều lựa chọn tương lai hơn chọn phim kết thúc muộn.

Duy trì một `multiset` kích thước $k$, mỗi phần tử là thời gian kết thúc của phim cuối cùng được phân cho một thành viên. Khởi tạo $k$ phần tử bằng $0$ (tất cả đều rảnh ngay từ đầu).

Với mỗi phim $(a_i, b_i)$ theo thứ tự đã sắp:

1. Dùng `upper_bound(a_i)` trên multiset để tìm thời gian kết thúc đầu tiên $> a_i$, rồi lấy phần tử ngay trước — đó là thành viên rảnh muộn nhất nhưng vẫn xem được phim này ($\leq a_i$).
2. Nếu tìm được: xóa thời gian kết thúc cũ, chèn $b_i$, tăng đáp án.
3. Nếu không tìm được (tất cả thành viên đều bận lúc $a_i$): bỏ qua phim này.

**Tại sao phân cho thành viên rảnh muộn nhất?** Giả sử thành viên $X$ rảnh từ thời điểm $3$ và thành viên $Y$ rảnh từ thời điểm $5$. Khi có phim bắt đầu lúc $6$, phân cho $Y$ giúp $X$ vẫn sẵn sàng cho các phim bắt đầu trong $[3, 5]$, trong khi phân cho $X$ làm mất đi sự linh hoạt của $X$. Chọn thành viên rảnh muộn nhất giữ lại nhiều linh hoạt nhất cho các bước sau.

**Tính đúng:** Bằng lập luận đổi chỗ. Nếu nghiệm tối ưu phân phim hiện tại cho thành viên rảnh sớm hơn $X$ thay vì thành viên rảnh muộn hơn $Y$, đổi phân cho $Y$ vẫn giữ được thời gian kết thúc sớm của $X$, không tệ hơn cho mọi phân phối sau. Vậy luôn chọn thành viên rảnh muộn nhất không bao giờ tệ hơn lựa chọn khác.

### Ví dụ minh họa

Xét $n = 5$, $k = 2$, các phim: $(1, 5)$, $(8, 10)$, $(3, 6)$, $(2, 5)$, $(6, 9)$.

Sau khi sắp xếp theo thời gian kết thúc: $(1, 5)$, $(2, 5)$, $(3, 6)$, $(6, 9)$, $(8, 10)$.

Multiset ban đầu: $\{0, 0\}$.

| Phim | $a_i$ | $b_i$ | Kết quả `upper_bound(a_i)` | Hành động | Multiset sau |
|------|-------|-------|----------------------------|-----------|--------------|
| $(1,5)$ | $1$ | $5$ | Tìm thấy $0$ (muộn nhất $\leq 1$) | Phân cho thành viên | $\{0, 5\}$ |
| $(2,5)$ | $2$ | $5$ | Tìm thấy $0$ (muộn nhất $\leq 2$) | Phân cho thành viên | $\{5, 5\}$ |
| $(3,6)$ | $3$ | $6$ | `it == begin()` (không có $\leq 3$) | Bỏ qua | $\{5, 5\}$ |
| $(6,9)$ | $6$ | $9$ | Tìm thấy $5$ (muộn nhất $\leq 6$) | Phân cho thành viên | $\{5, 9\}$ |
| $(8,10)$ | $8$ | $10$ | Tìm thấy $5$ (muộn nhất $\leq 8$) | Phân cho thành viên | $\{9, 10\}$ |

Đáp án: 4 phim được xem.

## Độ phức tạp

- **Thời gian:** $O(n \log n + n \log k)$ — sắp xếp $O(n \log n)$, mỗi phim tìm/xóa/chèn trong multiset kích thước $k$ mất $O(\log k)$.
- **Bộ nhớ:** $O(n + k)$

## Mã nguồn (C++)

[Mã nguồn](../code/Movie%20Festival%20II.cpp)
