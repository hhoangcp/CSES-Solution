# Subarray Sums II - Lời giải

**ID:** 1661 | **URL:** https://cses.fi/problemset/task/1661

## Đề bài

Cho mảng gồm $n$ số nguyên $a_1, a_2, \ldots, a_n$ (có thể âm, dương hoặc bằng $0$) và số nguyên $x$. Đếm số lượng mảng con liên tiếp có tổng các phần tử bằng $x$.

## Hướng tiếp cận

### 1. Biến đổi bài toán bằng tổng tiền tố

Gọi $S_k$ là tổng tiền tố từ phần tử đầu tiên đến vị trí $k$:

- $S_0 = 0$
- $S_k = a_1 + a_2 + \cdots + a_k$ với $1 \le k \le n$

Tổng của mảng con $[l, r]$ là:

$$\text{Sum}(l, r) = S_r - S_{l-1}$$

Mảng con này có tổng bằng $x$ khi và chỉ khi:

$$S_r - S_{l-1} = x \iff S_{l-1} = S_r - x$$

Như vậy, tại mỗi vị trí kết thúc $r$, ta cần đếm số vị trí khởi đầu $l-1$ ($0 \le l-1 < r$) thỏa mãn $S_{l-1} = S_r - x$.

### 2. Điểm khác biệt so với Subarray Sums I

Do mảng chứa các số nguyên bất kỳ (có thể âm):

- **Tổng tiền tố không còn tăng nghiêm ngặt:** các giá trị $S_k$ có thể trùng nhau tại nhiều vị trí (khi đó mảng con xen giữa có tổng $0$), nên tại một $r$ có thể có nhiều $l-1$ cùng thỏa mãn $\textemdash$ không thể dùng two-pointer như Subarray Sums I, mà phải đếm tần suất.
- **Cần kiểu dữ liệu lớn:** $S_k$ có thể rất lớn hoặc rất âm, nên phải dùng `long long` làm khóa cho cấu trúc đếm.

### 3. Tối ưu hóa bằng cấu trúc dữ liệu đếm tần suất

Duy trì một map (hoặc bảng băm) $M$ lưu tần suất các giá trị tổng tiền tố đã đi qua. Duyệt $r$ từ $1$ đến $n$:

1. Cập nhật $S_r = S_{r-1} + a_r$.
2. Nếu $S_r - x$ có trong $M$, cộng $M[S_r - x]$ vào kết quả $\textemdash$ mỗi lần xuất hiện ứng với một vị trí $l-1$ hợp lệ.
3. Tăng $M[S_r]$ thêm $1$.

**Khởi tạo:** đặt $M[0] = 1$ trước khi duyệt, để đếm được các mảng con thỏa mãn bắt đầu từ vị trí đầu tiên ($l = 1$, ứng với $S_{l-1} = S_0 = 0$).

## Ví dụ minh họa

Xét $n = 5$, $x = 7$ và mảng $a = [2, -1, 3, 5, -2]$.

Tổng tiền tố: $S_0 = 0,\ S_1 = 2,\ S_2 = 1,\ S_3 = 4,\ S_4 = 9,\ S_5 = 7$.

Khởi tạo $M = \{0: 1\}$, $\text{res} = 0$.

- **$r = 1$ ($a_1 = 2$):** $S_1 = 2$, cần $S_1 - 7 = -5 \notin M$. Cập nhật $M = \{0:1, 2:1\}$.
- **$r = 2$ ($a_2 = -1$):** $S_2 = 1$, cần $S_2 - 7 = -6 \notin M$. Cập nhật $M = \{0:1, 1:1, 2:1\}$.
- **$r = 3$ ($a_3 = 3$):** $S_3 = 4$, cần $S_3 - 7 = -3 \notin M$. Cập nhật $M = \{0:1, 1:1, 2:1, 4:1\}$.
- **$r = 4$ ($a_4 = 5$):** $S_4 = 9$, cần $S_4 - 7 = 2 \in M$ (tần suất $1$) $\to$ $\text{res} = 1$. Cập nhật $M = \{0:1, 1:1, 2:1, 4:1, 9:1\}$. *(Mảng con $[2,4]$: $-1+3+5=7$)*.
- **$r = 5$ ($a_5 = -2$):** $S_5 = 7$, cần $S_5 - 7 = 0 \in M$ (tần suất $1$) $\to$ $\text{res} = 2$. Cập nhật $M = \{0:1, 1:1, 2:1, 4:1, 7:1, 9:1\}$. *(Mảng con $[1,5]$: $2-1+3+5-2=7$)*.

Kết quả: $2$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ nếu dùng `std::map` (mỗi bước $O(\log n)$ tìm và cập nhật), hoặc $O(n)$ nếu dùng `std::unordered_map` (mỗi bước trung bình $O(1)$).
- **Bộ nhớ:** $O(n)$ để lưu tối đa $n+1$ giá trị tổng tiền tố.
