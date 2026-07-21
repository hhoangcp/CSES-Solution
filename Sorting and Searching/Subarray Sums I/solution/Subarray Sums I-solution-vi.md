# Subarray Sums I - Lời giải

**ID:** 1660 | **URL:** https://cses.fi/problemset/task/1660

## Đề bài

Cho mảng gồm $n$ số nguyên dương $a_1, a_2, \ldots, a_n$ và số nguyên dương $x$. Đếm số lượng mảng con liên tiếp có tổng các phần tử bằng $x$.

## Hướng tiếp cận

### Ý tưởng cốt lõi

Vì mọi $a_i \ge 1$, tổng của một đoạn con luôn tăng nghiêm ngặt khi mở rộng về bên phải và giảm nghiêm ngặt khi thu hẹp từ bên trái. Tính đơn điệu này cho phép dùng **hai con trỏ**:

- Với mỗi vị trí kết thúc $r$, khi đẩy con trỏ trái `left` sang phải, tổng đoạn $[\text{left}, r]$ chỉ giảm. Do đó tồn tại nhiều nhất một `left` cho ra tổng đúng bằng $x$ — không cần bảng đếm tần suất hay xét trùng.
- Khi $r$ tăng, `left` hợp lệ không bao giờ lùi (thêm phần tử chỉ làm tổng tăng, nên `left` giữ nguyên hoặc tiến lên). Vì vậy hai con trỏ cùng quét mảng trong một lượt duy nhất.

### Thuật toán

Duy trì tổng đoạn đang xét `sum` và con trỏ trái `left`:

1. Khởi tạo `left = 1`, `sum = 0`, `ans = 0`.
2. Với mỗi $r$ từ $1$ đến $n$:
   - Cộng $a_r$ vào `sum`.
   - Trong khi `sum > x` và `left <= r`: trừ $a_{\text{left}}$ khỏi `sum`, rồi tăng `left`.
   - Nếu `sum == x`: tăng `ans` thêm $1$.
3. Đưa ra `ans`.

Mỗi mảng con thỏa mãn được đếm đúng một lần, tại đúng endpoint bên phải của nó.

## Ví dụ minh họa

Xét $n = 5$, $x = 7$, mảng $a = [2, 4, 1, 2, 7]$.

| $r$ | $a_r$ | `sum` sau cộng | sau thu hẹp | `left` | `ans` |
| --- | --- | --- | --- | --- | --- |
| 1 | 2 | 2 | 2 | 1 | 0 |
| 2 | 4 | 6 | 6 | 1 | 0 |
| 3 | 1 | 7 | 7 | 1 | 1 |
| 4 | 2 | 9 | 7 | 2 | 2 |
| 5 | 7 | 14 | 7 | 5 | 3 |

Tại $r=4$, sau khi cộng $a_4=2$ tổng thành $9>7$, ta loại $a_1=2$ (`left` $\to 2$), tổng về $7$. Tại $r=5$, tổng thành $14>7$, ta loại lần lượt $a_2, a_3, a_4$ (`left` $\to 5$), tổng về $7$. Ba đoạn khớp là $[1,3]$, $[2,4]$, $[5,5]$, đều có tổng $7$.

## Độ phức tạp

- **Thời gian:** $O(n)$ — mỗi phần tử được cộng vào `sum` đúng một lần (bởi $r$) và bị trừ ra nhiều nhất một lần (bởi `left`); tổng cộng không quá $2n$ thao tác.
- **Bộ nhớ:** $O(n)$ để lưu mảng.
