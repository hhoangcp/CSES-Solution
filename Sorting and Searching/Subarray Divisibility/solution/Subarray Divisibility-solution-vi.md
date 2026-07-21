# Subarray Divisibility - Lời giải

**ID:** 1662 | **URL:** https://cses.fi/problemset/task/1662

## Hướng tiếp cận

### Tóm tắt đề bài

Cho một mảng $n$ số nguyên, đếm số mảng con liên tục mà tổng các phần tử chia hết cho $n$.

### Ý tưởng cốt lõi

Gọi $\text{prefix}[0] = 0$ và $\text{prefix}[i] = \sum_{j=1}^{i} a_j$. Tổng mảng con $[l, r]$ là
$$S(l, r) = \text{prefix}[r] - \text{prefix}[l-1].$$
Tổng này chia hết cho $n$ đúng khi hai tổng tiền tố có cùng số dư modulo $n$:
$$\text{prefix}[r] \equiv \text{prefix}[l-1] \pmod{n},$$
vì $S(l,r) \bmod n = (\text{prefix}[r] - \text{prefix}[l-1]) \bmod n$ bằng $0$ đúng khi hai số dư trùng nhau. Vậy bài toán quy về đếm số cặp chỉ số tiền tố $(j, i)$ với $j < i$ có cùng số dư modulo $n$ — tương đương $\sum_{r} \binom{c_r}{2}$, với $c_r$ là số tổng tiền tố dư $r$. Đếm các cặp này trong một lượt duyệt trái sang phải sẽ ra đáp án.

### Thuật toán

Duy trì bảng tần suất của các số dư đã gặp.
1. Khởi tạo $\text{freq}[0] = 1$ cho tổng tiền tố rỗng $\text{prefix}[0] = 0$, để đếm được các mảng con bắt đầu từ vị trí $1$.
2. Với mỗi $i = 1, \ldots, n$:
   - Cập nhật tổng tiền tố đang chạy và quy về số dư chuẩn trong $\{0, \ldots, n-1\}$:
     $$r = ((\text{prefix} + a_i) \bmod n + n) \bmod n.$$
     Phép modulo kép sửa lỗi của `%` trong C++, vốn có thể trả số âm với số hạng âm.
   - Cộng $\text{freq}[r]$ vào đáp án — mỗi tổng tiền tố trước đó cùng số dư cho một mảng con hợp lệ kết thúc tại $i$.
   - Tăng $\text{freq}[r]$ lên $1$.

### Ví dụ minh họa

Ví dụ của đề bài là $n = 5$, $a = [3, 1, 2, 7, 4]$.

| $i$ | $a_i$ | tổng tiền tố | số dư (mod 5) | $\text{freq}[r]$ trước | cộng |
|-----|-------|--------------|---------------|------------------------|------|
| 0 | — | 0 | 0 | (khởi tạo $\text{freq}[0]=1$) | — |
| 1 | 3 | 3 | 3 | 0 | 0 |
| 2 | 1 | 4 | 4 | 0 | 0 |
| 3 | 2 | 6 | 1 | 0 | 0 |
| 4 | 7 | 13 | 3 | 1 | $+1$ |
| 5 | 4 | 17 | 2 | 0 | 0 |

Tổng: $1$. Mảng con duy nhất hợp lệ là $[2,4]$: $1 + 2 + 7 = 10$, chia hết cho $5$. $\checkmark$

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ nếu dùng `std::map`, hoặc $O(n)$ nếu dùng mảng tần suất kích thước $n$ (các số dư luôn nằm trong $\{0, \ldots, n-1\}$).
- **Bộ nhớ:** $O(n)$ cho bảng tần suất.
