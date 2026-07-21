# Multiplication Table - Lời giải

**ID:** 2422 | **URL:** https://cses.fi/problemset/task/2422

## Đề bài

Cho bảng nhân ("cửu chương") kích thước $n \times n$ (với $n$ là số lẻ). Tìm phần tử nằm ở giữa (trung vị) khi tất cả $n^2$ phần tử của bảng được sắp xếp theo thứ tự tăng dần.

## Hướng tiếp cận

### 1. Phân tích bài toán

- Bảng nhân $n \times n$ có tổng cộng $n^2$ phần tử. Vì $n$ lẻ nên $n^2$ cũng lẻ.
- Phần tử ở giữa sẽ nằm ở vị trí thứ $p = \frac{n^2 + 1}{2}$ trong dãy đã sắp xếp.
- Với $n$ lên tới $10^6$, ta không thể tạo ra mảng chứa $n^2$ ($10^{12}$) phần tử vì sẽ vượt quá giới hạn bộ nhớ. Do đó, ta cần sử dụng **Tìm kiếm nhị phân trên giá trị**.

### 2. Tìm kiếm nhị phân trên giá trị kết quả

Ta cần tìm giá trị nhỏ nhất $x$ sao cho có ít nhất $p$ phần tử trong bảng nhân có giá trị $\le x$.

- Khoảng tìm kiếm: $l = 1$, $r = n^2$.
- Hàm đếm: Để đếm xem có bao nhiêu phần tử trong bảng $\le x$, ta duyệt qua từng hàng $i$ từ $1$ đến $n$.
  - Trong hàng $i$, các giá trị là: $i \times 1, i \times 2, \dots, i \times n$.
  - Số lượng phần tử $\le x$ trong hàng $i$ là $\min(n, \lfloor x/i \rfloor)$.
  - Tổng số phần tử $\le x$ trong toàn bảng là: $Leq = \sum_{i=1}^{n} \min(n, \lfloor x/i \rfloor)$.

### 3. Quy trình thực hiện

1. Tính vị trí mục tiêu $p = (n^2 + 1) / 2$.
2. Thực hiện chặt nhị phân $mid = (l + r) / 2$.
3. Tính tổng số phần tử $Leq \le mid$ bằng cách duyệt qua $n$ hàng.
4. Nếu $Leq \ge p$, giá trị trung vị có thể là $mid$ hoặc nhỏ hơn ($ans = mid, r = mid - 1$).
5. Nếu $Leq < p$, giá trị trung vị phải lớn hơn $mid$ ($l = mid + 1$).

## Ví dụ mô phỏng

Với $n = 3$, bảng nhân:
$$
\begin{matrix}
1 & 2 & 3 \\
2 & 4 & 6 \\
3 & 6 & 9 \\
\end{matrix}
$$

- Vị trí trung vị $p = (3^2 + 1) / 2 = 5$.
- Thử với $mid = 3$:
  - Hàng 1: $\min(3, 3/1) = 3$ (các số 1, 2, 3).
  - Hàng 2: $\min(3, 3/2) = 1$ (số 2).
  - Hàng 3: $\min(3, 3/3) = 1$ (số 3).
  - Tổng $Leq = 3 + 1 + 1 = 5$.
- Vì $Leq = 5$ đúng bằng vị trí mục tiêu, kết quả nhỏ nhất thỏa mãn là **3**.

## Độ phức tạp

- **Thời gian:** $O(n \log(n^2))$ — Vòng lặp nhị phân chạy $\log(n^2)$ lần, mỗi lần duyệt qua $n$ hàng để đếm.
- **Bộ nhớ:** $O(1)$ — Chỉ sử dụng một vài biến số nguyên, không phụ thuộc vào kích thước mảng.

## Mã nguồn (C++)

[Mã nguồn](../code/Multiplication%20Table.cpp)
