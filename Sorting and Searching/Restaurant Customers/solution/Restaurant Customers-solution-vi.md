# Restaurant Customers - Lời giải

**ID:** 1619 | **URL:** https://cses.fi/problemset/task/1619

## Hướng tiếp cận

Chuyển mỗi khoảng thời gian $[a_i, b_i]$ của khách hàng thành hai sự kiện: **đến** tại thời điểm $a_i$ với giá trị $+1$, và **rời** tại thời điểm $b_i$ với giá trị $-1$. Tổng cộng có $2n$ sự kiện.

Sắp xếp $2n$ sự kiện theo thời gian tăng dần. Khi trùng thời điểm, xử lý đến ($+1$) trước rời ($-1$) — sắp xếp theo `val` giảm đảm bảo điều này. Quy ước này phù hợp trường hợp khách rời lúc $t$ và khách đến lúc $t$ đều đang có mặt tại $t$.

Duyệt qua các sự kiện đã sắp, duy trì `cnt` (số khách hiện tại): `cnt += val`, rồi `res = max(res, cnt)`.

**Tính đúng:** Số khách chỉ thay đổi tại các thời điểm sự kiện và không đổi giữa hai sự kiện liên tiếp. Tại mỗi thời điểm sự kiện, `cnt` phản ánh chính xác số khách đang có mặt (đến thì cộng, rời thì trừ). Xử lý đến trước rời tại cùng thời điểm đảm bảo đếm đúng tại đỉnh. Vậy giá trị lớn nhất của `cnt` trong quá trình quét chính là số khách đồng thời tối đa.

### Ví dụ minh họa

Xét $n = 3$, khách: $(5, 8)$, $(2, 4)$, $(3, 9)$.

Sự kiện: $(2,+1)$, $(3,+1)$, $(4,-1)$, $(5,+1)$, $(8,-1)$, $(9,-1)$.

| Bước | Thời điểm | `val` | `cnt` | `res` |
|------|-----------|-------|-------|-------|
| Khởi tạo | — | — | 0 | 0 |
| 1 | $2$ | $+1$ | 1 | 1 |
| 2 | $3$ | $+1$ | 2 | 2 |
| 3 | $4$ | $-1$ | 1 | 2 |
| 4 | $5$ | $+1$ | 2 | 2 |
| 5 | $8$ | $-1$ | 1 | 2 |
| 6 | $9$ | $-1$ | 0 | 2 |

Đáp án: 2 (đỉnh tại thời điểm $t = 3$).

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp $2n$ sự kiện; bước quét chỉ $O(n)$.
- **Bộ nhớ:** $O(n)$ — mảng $2n$ sự kiện.

## Mã nguồn (C++)

[Mã nguồn](../code/Restaurant%20Customers.cpp)
