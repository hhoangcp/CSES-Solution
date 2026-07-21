# Finding Periods - Lời giải

**ID:** 1733 | **URL:** https://cses.fi/problemset/task/1733

## Đề bài

Cho một chuỗi $s$ độ dài $n$ gồm các ký tự 'a'–'z'. Một chu kỳ (period) độ dài $k$ là tiền tố $s[1..k]$ sao cho $s$ là tiền tố của chuỗi vô hạn $s[1..k]^{\infty}$ (lần lặp cuối có thể không trọn vẹn). Hãy in tất cả các độ dài chu kỳ theo thứ tự tăng dần.

## Hướng tiếp cận

### Bước 1: Hàm Z và điều kiện chu kỳ

Với chuỗi $s$ (đánh số từ 1), $Z[i]$ là độ dài chuỗi con dài nhất bắt đầu tại $i$ khớp với tiền tố của $s$; theo quy ước $Z[1] = 0$.

Xét một độ dài $k$ ($1 \le k < n$). Để $k$ là chu kỳ, phần còn lại của chuỗi tính từ $k+1$, tức hậu tố $s[k+1..n]$, phải khớp hoàn toàn với tiền tố cùng độ dài $n-k$ của $s$ (vì mỗi vị trí $i \ge k+1$ phải bằng $s[i-k]$). Điều kiện cần và đủ là:

$$Z[k+1] = n - k \quad \Longleftrightarrow \quad (k+1) + Z[k+1] - 1 = n$$

**Chứng minh tương đương:**
- ($\Rightarrow$) Nếu $k$ là chu kỳ thì $s[i] = s[i-k]$ với mọi $i \ge k+1$, nên $s[k+1..n] = s[1..n-k]$, tức $Z[k+1] \ge n-k$; mà đoạn này chỉ dài $n-k$ nên $Z[k+1] = n-k$.
- ($\Leftarrow$) Nếu $Z[k+1] = n-k$ thì $s[i] = s[i-k]$ với mọi $i \in [k+1, n]$. Áp dụng liên tục quan hệ này đưa mọi chỉ số $i$ về $r = ((i-1) \bmod k) + 1 \in [1, k]$, được $s[i] = s[r]$, đúng là định nghĩa của chu kỳ.

Đặt $i = k+1$, điều kiện trở thành $i + Z[i] - 1 = n$ và độ dài chu kỳ là $k = i - 1$.

### Bước 2: Thuật toán

1. Tính mảng $Z$ cho $s$ trong $O(n)$ (phương pháp hai con trỏ).
2. Duyệt $i$ tăng dần từ $2$ đến $n$; mỗi vị trí thỏa $i + Z[i] - 1 = n$ cho một chu kỳ độ dài $i - 1$. Vì $i$ tăng nên các độ dài $i - 1$ tự động ra theo thứ tự tăng dần, không cần sắp xếp hay ngăn xếp.
3. Độ dài $n$ luôn là chu kỳ (lặp chính chuỗi một lần), nên in $n$ ở cuối.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"abcabca"}$ ($n = 7$).

| $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| $s[i]$ | a | b | c | a | b | c | a |
| $Z[i]$ | 0 | 0 | 0 | 4 | 0 | 0 | 1 |

Kiểm tra điều kiện $i + Z[i] - 1 = n = 7$:

| $i$ | $Z[i]$ | $i + Z[i] - 1$ | chu kỳ? |
|---|---|---|---|
| 4 | 4 | 7 | có, độ dài $i - 1 = 3$: $\text{"abc"}$ |
| 7 | 1 | 7 | có, độ dài $i - 1 = 6$: $\text{"abcabc"}$ |

(Các $i$ còn lại có $Z[i] = 0$ nên $i + Z[i] - 1 < n$.) Cộng thêm $n = 7$ luôn là chu kỳ.

Thật vậy, $\text{"abcabca"}$ là tiền tố của $\text{"abc"}^{\infty}$ (lặp $\text{"abc"}$ rồi thêm $\text{"a"}$) và cũng của $\text{"abcabc"}^{\infty}$ (thêm $\text{"a"}$), nên các chu kỳ là $3, 6, 7$.

Kết quả:
```
3 6 7
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ tính hàm Z tuyến tính, duyệt kiểm tra mỗi vị trí trong $O(1)$.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu mảng $Z$.

## Mã nguồn (C++)

[Mã nguồn](../code/Finding%20Periods.cpp)
