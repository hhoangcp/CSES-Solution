# Josephus Problem I - Lời giải

**ID:** 2162 | **URL:** https://cses.fi/problemset/task/2162

## Phương pháp

### Tóm tắt bài toán

Có $n$ đứa trẻ xếp vòng tròn, đánh số $1$ đến $n$. Bắt đầu từ trẻ số $1$, cứ bỏ qua $1$ trẻ rồi loại trẻ tiếp theo ($k=2$). Lặp lại cho đến khi tất cả bị loại. In ra thứ tự bị loại.

### Ý tưởng chính

Bài toán Josephus cổ điển với bước nhảy $k=2$. Dùng mảng/danh sách liên kết sẽ mất $O(n^2)$ do xóa phần tử giữa. Thay vào đó, ta dùng cây thống kê thứ tự (order-statistic tree) hỗ trợ: (1) truy cập phần tử theo chỉ số trong $O(\log n)$, (2) xóa phần tử trong $O(\log n)$. Duy trì biến `cur` là chỉ số 0-indexed của phần tử tiếp theo bị loại. Mỗi bước: tìm phần tử tại `cur`, in ra, xóa khỏi cây. Sau khi xóa phần tử tại `cur`, các phần tử bên phải dịch trái 1 vị trí nên phần tử kế tiếp trong vòng tròn nằm tại chính chỉ số `cur` trong cây mới — ta nhảy thêm 1 bước (bỏ qua 1 người) để chọn người tiếp theo: `cur = (cur % n + 1) % n` (với $n$ là kích thước cây sau xóa).

### Thuật toán

1. Nạp các số $1, 2, \dots, n$ vào cây thống kê thứ tự.
2. `cur = 1 % n`.
3. Lặp $n$ lần:
   - Tìm phần tử tại chỉ số `cur`, in ra, xóa khỏi cây.
   - Nếu còn phần tử: `cur = (cur % n + 1) % n` ($n$ là kích thước mới).

### Ví dụ minh họa

$n = 7$. Cây ban đầu: $\{1,2,3,4,5,6,7\}$, `cur = 1`.

| Bước | `cur` | Loại | Còn lại | `cur` mới |
|------|-------|------|---------|-----------|
| 1 | 1 | **2** | $\{1,3,4,5,6,7\}$ | $(1\%6+1)\%6=2$ |
| 2 | 2 | **4** | $\{1,3,5,6,7\}$ | $(2\%5+1)\%5=3$ |
| 3 | 3 | **6** | $\{1,3,5,7\}$ | $(3\%4+1)\%4=0$ |
| 4 | 0 | **1** | $\{3,5,7\}$ | $(0\%3+1)\%3=1$ |
| 5 | 1 | **5** | $\{3,7\}$ | $(1\%2+1)\%2=0$ |
| 6 | 0 | **3** | $\{7\}$ | $(0\%1+1)\%1=0$ |
| 7 | 0 | **7** | $\emptyset$ | — |

Kết quả: **2 4 6 1 5 3 7**.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Josephus%20Problem%20I.cpp)
