# Josephus Problem II - Lời giải

**ID:** 2163 | **URL:** https://cses.fi/problemset/task/2163

## Phương pháp

### Tóm tắt bài toán

Có $n$ đứa trẻ xếp vòng tròn, đánh số $1$ đến $n$. Bắt đầu từ trẻ số $1$, cứ bỏ qua $k$ trẻ rồi loại trẻ tiếp theo. Lặp lại cho đến khi tất cả bị loại. In ra thứ tự bị loại.

### Ý tưởng chính

Bài toán Josephus tổng quát với bước nhảy $k$ bất kỳ. Dùng mảng thông thường mất $O(n^2)$. Thay vào đó, dùng cây thống kê thứ tự (order-statistic tree) hỗ trợ truy cập theo chỉ số và xóa phần tử trong $O(\log n)$. Duy trì biến `cur` là chỉ số 0-indexed của phần tử tiếp theo bị loại. Mỗi bước: tìm phần tử tại `cur`, in ra, xóa khỏi cây. Sau khi xóa phần tử tại `cur`, các phần tử bên phải dịch trái 1 vị trí nên vị trí `cur` hiện tại chính là điểm bắt đầu mới trong tập hợp đã thu hẹp — ta nhảy thêm $k$ bước để bỏ qua $k$ người: `cur = (cur % n + k) % n` (với $n$ là kích thước cây sau xóa). Phép modulo đảm bảo chỉ số luôn hợp lệ kể cả khi $k$ rất lớn ($10^9$).

### Thuật toán

1. Nạp các số $1, 2, \dots, n$ vào cây thống kê thứ tự.
2. `cur = k % n`.
3. Lặp $n$ lần:
   - Tìm phần tử tại chỉ số `cur`, in ra, xóa khỏi cây.
   - Nếu còn phần tử: `cur = (cur % n + k) % n` ($n$ là kích thước mới).

### Ví dụ minh họa

$n = 7$, $k = 2$. Cây ban đầu: $\{1,2,3,4,5,6,7\}$, `cur = 2%7 = 2`.

| Bước | `cur` | Loại | Còn lại | `cur` mới |
|------|-------|------|---------|-----------|
| 1 | 2 | **3** | $\{1,2,4,5,6,7\}$ | $(2\%6+2)\%6=4$ |
| 2 | 4 | **6** | $\{1,2,4,5,7\}$ | $(4\%5+2)\%5=1$ |
| 3 | 1 | **2** | $\{1,4,5,7\}$ | $(1\%4+2)\%4=3$ |
| 4 | 3 | **7** | $\{1,4,5\}$ | $(3\%3+2)\%3=2$ |
| 5 | 2 | **5** | $\{1,4\}$ | $(2\%2+2)\%2=0$ |
| 6 | 0 | **1** | $\{4\}$ | $(0\%1+2)\%1=0$ |
| 7 | 0 | **4** | $\emptyset$ | — |

Kết quả: **3 6 2 7 5 1 4**.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Josephus%20Problem%20II.cpp)
