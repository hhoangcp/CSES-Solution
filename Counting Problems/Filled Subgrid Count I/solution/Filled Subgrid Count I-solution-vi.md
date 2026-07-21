# Filled Subgrid Count I - Lời giải

**ID:** 3413 | **URL:** https://cses.fi/problemset/task/3413

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times n$ gồm các chữ cái in hoa, với mỗi chữ cái trong $k$ chữ cái đầu tiên, đếm số lưới con hình vuông mà mọi ô chứa cùng chữ cái đó.

### QHD hình vuông đồng nhất cực đại

Định nghĩa $\text{dp}[i][j]$ = cạnh hình vuông đồng nhất lớn nhất có góc dưới phải tại $(i, j)$. Với hình vuông đồng nhất kích thước $s$ kết thúc tại $(i, j)$, cả ba hình vuông kích thước $s{-}1$ chồng lấp (kết thúc tại $(i{-}1, j)$, $(i, j{-}1)$, và $(i{-}1, j{-}1)$) cũng phải đồng nhất. Nếu bất kỳ hình nào nhỏ hơn $s{-}1$, hình vuông tại $(i, j)$ không thể đạt kích thước $s$. Vậy:

$$\text{dp}[i][j] = \begin{cases} \min(\text{dp}[i{-}1][j], \text{dp}[i][j{-}1], \text{dp}[i{-}1][j{-}1]) + 1 & \text{nếu } a[i][j] = a[i{-}1][j] = a[i][j{-}1] = a[i{-}1][j{-}1] \\ 1 & \text{ngược lại} \end{cases}$$

### Đếm tất cả hình vuông đồng nhất

Nếu $\text{dp}[i][j] = s$, tồn tại đúng $s$ hình vuông đồng nhất kết thúc tại $(i, j)$: mỗi kích thước $1 \times 1, 2 \times 2, \ldots, s \times s$. Cộng $\text{dp}[i][j]$ vào kết quả cho chữ cái $a[i][j]$.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$, $k = 3$, lưới:
```
A B B B C
B B B B C
B C A A A
A A A A A
A A A A A
```

Bảng DP:
```
1 1 1 1 1
1 1 2 2 1
1 1 1 1 1
1 1 1 2 2
1 2 2 2 3
```

- **A:** $1 + 1{+}1{+}1 + 1{+}1{+}1{+}2{+}2 + 1{+}2{+}2{+}2{+}3 = 21$
- **B:** $1{+}1{+}1 + 1{+}1{+}2{+}2 + 1 = 10$
- **C:** $1 + 1 + 1 = 3$

Kết quả: 21, 10, 3. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — duyệt lưới một lần.
- **Bộ nhớ:** $O(n^2)$ — cho bảng QHD. Có thể tối ưu xuống $O(n)$ bằng cách chỉ lưu dòng hiện tại và dòng trước.

## Mã nguồn (C++)

[Mã nguồn](../code/Filled%20Subgrid%20Count%20I.cpp)
