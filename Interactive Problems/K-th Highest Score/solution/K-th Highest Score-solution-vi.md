# Điểm cao thứ K - Lời giải

**ID:** 3305 | **URL:** https://cses.fi/problemset/task/3305

## Phương pháp

### Tóm tắt bài toán

Có $n$ lập trình viên Phần Lan và $n$ lập trình viên Thụy Điển, mỗi người có điểm số khác nhau. Tìm điểm cao thứ $k$ trong cuộc thi bằng cách hỏi điểm cao thứ $i$ của Phần Lan (`F i`) hoặc Thụy Điển (`S i`), tối đa 100 truy vấn.

### Ý tưởng chính

Đây là biến thể của bài toán "tìm phần tử thứ $k$ trong hai mảng đã sắp xếp". Gọi $F_1 > F_2 > \cdots > F_n$ và $S_1 > S_2 > \cdots > S_n$. Nếu top $k$ gồm $i$ người Phần Lan và $k-i$ người Thụy Điển, điểm ranh giới là $\min(F_i, S_{k-i})$.

**Tính đơn điệu:** Khi $i$ tăng, $F_i$ giảm và $S_{k-i}$ tăng (do $k-i$ giảm). Vậy $F_i - S_{k-i}$ giảm đơn điệu theo $i$. Chặt nhị phân tìm điểm chuyển $l$: giá trị $i$ nhỏ nhất mà $F_i \le S_{k-i}$.

**Xử lý biên:** Khi $i = 0$, coi $F_0 = +\infty$ (luôn $F_0 > S_k$, tức cần thêm người Phần Lan). Khi $k-i = 0$, coi $S_0 = +\infty$ (luôn $F_i < S_0$, tức đủ người Phần Lan).

**Kết quả:** Điểm cao thứ $k$ là max của hai trường hợp ranh giới tại $l$ và $l-1$:

$$\max\bigl(\min(F_l, S_{k-l}),\min(F_{l-1}, S_{k-l+1})\bigr)$$

### Thuật toán

1. Đặt $l = \max(0, k-n)$, $r = \min(k, n)$.
2. Chặt nhị phân tìm $l$ nhỏ nhất mà $F_l \le S_{k-l}$:
   - $mid = \lfloor(l+r)/2\rfloor$. Hỏi $F_{mid}$ và $S_{k-mid}$.
   - Nếu $F_{mid} \le S_{k-mid}$: $r = mid$.
   - Ngược lại: $l = mid + 1$.
3. Tính $\min(F_l, S_{k-l})$. Nếu $l > 0$, tính thêm $\min(F_{l-1}, S_{k-l+1})$.
4. Xuất giá trị lớn nhất trong các ứng cử viên.

**Số truy vấn:** $\lceil\log_2 n\rceil$ bước, mỗi bước tối đa 2 truy vấn, cộng thêm 2 truy vấn cuối. Với $n \le 10^5$: dưới 40 truy vấn, thỏa mãn giới hạn 100.

### Ví dụ minh họa

$n = 3, k = 3$. Phần Lan: $[9, 4, 3]$, Thụy Điển: $[8, 6, 1]$ (cùng dữ liệu với đề bài). Gộp: $[9, 8, 6, 4, 3, 1]$. Điểm cao thứ 3 là **6**.

- Miền: $i \in [0, 3]$.
- $l=0, r=3, mid=1$: $F_1 = 9$, $S_2 = 6$. $9 > 6$ → $l = 2$.
- $l=2, r=3, mid=2$: $F_2 = 4$, $S_1 = 8$. $4 \le 8$ → $r = 2$.
- $l = r = 2$.
- Tại $l=2$: $\min(F_2, S_1) = \min(4, 8) = 4$.
- Tại $l-1=1$: $\min(F_1, S_2) = \min(9, 6) = 6$.
- Đáp án: $\max(4, 6) = \mathbf{6}$. ✓

## Độ phức tạp

- **Thời gian:** $O(\log n)$ truy vấn
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/K-th%20Highest%20Score.cpp)
