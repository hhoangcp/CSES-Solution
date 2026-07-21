# Increasing Subsequence - Lời giải

**ID:** 1145 | **URL:** https://cses.fi/problemset/task/1145

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho mảng $n$ số nguyên ($1 \le n \le 2 \times 10^5$), tìm độ dài của dãy con tăng nghiêm ngặt dài nhất (LIS).

### Ý tưởng cốt lõi

Quy hoạch động $O(n^2)$ — $dp[i] = 1 + \max_{j<i, a_j<a_i} dp[j]$ — quá chậm. Ta cần cách tiếp cận $O(n \log n)$.

Duy trì mảng `tails` trong đó `tails[k]` lưu **giá trị đuôi nhỏ nhất có thể** của dãy con tăng độ dài $k+1$ đã tìm thấy. Ý tưởng then chốt: giữ giá trị đuôi càng nhỏ càng tốt để tối đa cơ hội mở rộng dãy con bằng các phần tử phía sau.

**Tại sao cách này đúng (hai bất biến):**

1. **`tails` luôn tăng nghiêm ngặt.** Quy nạp: thêm $a$ vào cuối giữ tính tăng vì $a$ lớn hơn mọi phần tử; thay `tails[p]` bằng $a$ giữ tính tăng vì `tails[p-1] < a` (`lower_bound` đảm bảo điều này) và $a \le$ `tails[p]` cũ $\le$ `tails[p+1]`.

2. **Sau khi xử lý $k$ phần tử, `tails[len-1]` là giá trị đuôi nhỏ nhất của mọi dãy con tăng độ dài `len` nằm trong $k$ phần tử đó.** Quy nạp: nếu $a$ thay `tails[p]`, thì `tails[p-1] < a` cho ta dãy con độ dài $p$ kết thúc dưới $a$, ghép $a$ vào được dãy độ dài $p+1$ kết thúc tại $a$; vì `lower_bound` tìm vị trí đầu tiên $\geq a$, không có dãy độ dài $p+1$ nào kết thúc dưới $a$.

Hai bất biến đảm bảo độ dài cuối cùng của `tails` chính là độ dài LIS.

### Thuật toán

Với mỗi phần tử $a$ trong mảng:
1. Tìm vị trí đầu tiên $p$ trong `tails` mà `tails[p]` $\geq a$ (tìm kiếm nhị phân / `lower_bound`).
2. Nếu tìm thấy: thay `tails[p]` bằng $a$.
3. Nếu không tìm thấy (tất cả giá trị $< a$): thêm $a$ vào cuối `tails`.

Kết quả là độ dài của `tails`.

### Ví dụ

Mảng đầu vào: $[7, 3, 5, 3, 6, 2, 9, 8]$

| Phần tử | `tails` sau xử lý | Hành động |
|---------|-------------------|-----------|
| 7 | $[7]$ | Thêm vào cuối |
| 3 | $[3]$ | Thay 7 |
| 5 | $[3, 5]$ | Thêm vào cuối |
| 3 | $[3, 5]$ | Thay 3 (không đổi) |
| 6 | $[3, 5, 6]$ | Thêm vào cuối |
| 2 | $[2, 5, 6]$ | Thay 3 |
| 9 | $[2, 5, 6, 9]$ | Thêm vào cuối |
| 8 | $[2, 5, 6, 8]$ | Thay 9 |

Kết quả: độ dài LIS = $4$ (ví dụ: $3, 5, 6, 8$).

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — mỗi phần tử thực hiện một tìm kiếm nhị phân $O(\log n)$.
- **Bộ nhớ:** $O(n)$ cho mảng `tails`.

## Mã nguồn (C++)

[Mã nguồn](../code/Increasing%20Subsequence.cpp)
