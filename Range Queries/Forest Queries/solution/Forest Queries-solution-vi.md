# Forest Queries - Lời giải

**ID:** 1652 | **URL:** https://cses.fi/problemset/task/1652

## Hướng tiếp cận

### Tóm tắt đề bài

Cho lưới $n \times n$, mỗi ô hoặc trống (`.`) hoặc có cây (`*`). Xử lý $q$ truy vấn: có bao nhiêu cây bên trong hình chữ nhật từ $(y_1, x_1)$ đến $(y_2, x_2)$?

### Ý tưởng cốt lõi

Bản đồ là tĩnh (không cập nhật), nên **tổng tiền tố hai chiều** (2D prefix sum) cho phép mỗi truy vấn trong $O(1)$ với tiền xử lý $O(n^2)$.

Định nghĩa $a[i][j]$ = số cây trong hình chữ nhật từ $(1,1)$ đến $(i,j)$. Xây dựng bằng bao hàm-loại trừ:

$$a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + \text{tree}(i,j)$$

trong đó $\text{tree}(i,j) = 1$ nếu có cây tại $(i,j)$, ngược lại $0$. Công thức đúng theo nguyên lý bao hàm-loại trừ: hai hình chữ nhật $[1,i{-}1] \times [1,j]$ và $[1,i] \times [1,j{-}1]$ bao phủ $[1,i] \times [1,j]$, nhưng phần giao $[1,i{-}1] \times [1,j{-}1]$ bị tính hai lần nên trừ đi một lần, cộng thêm ô $(i,j)$.

Truy vấn hình chữ nhật từ $(y_1, x_1)$ đến $(y_2, x_2)$:

$$\text{đáp án} = a[y_2][x_2] - a[y_2][x_1-1] - a[y_1-1][x_2] + a[y_1-1][x_1-1]$$

Cùng nguyên lý: xuất phát từ $[1,y_2] \times [1,x_2]$, trừ các dải nằm ngoài truy vấn, cộng bù góc bị trừ lặp hai lần.

### Thuật toán

1. **Xây dựng tổng tiền tố:** Đọc lưới từng hàng. Với mỗi ô $(i,j)$, tính $a[i][j]$ theo công thức quy hoạch động trên.
2. **Trả lời truy vấn:** Với mỗi truy vấn, áp dụng công thức bao hàm-loại trừ trong $O(1)$.

### Ví dụ

Đầu vào:
```
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
```

Lưới (đánh chỉ số từ 1):
```
Hàng 1: . * . .
Hàng 2: * . * *
Hàng 3: * * . .
Hàng 4: * * * *
```

Mảng tổng tiền tố $a$:
| | j=1 | j=2 | j=3 | j=4 |
|---|---|---|---|---|
| i=1 | 0 | 1 | 1 | 1 |
| i=2 | 1 | 2 | 3 | 4 |
| i=3 | 2 | 4 | 5 | 6 |
| i=4 | 3 | 6 | 8 | 10 |

- Truy vấn $(2,2)$ đến $(3,4)$: $a[3][4] - a[3][1] - a[1][4] + a[1][1] = 6 - 2 - 1 + 0 = 3$.
- Truy vấn $(3,1)$ đến $(3,1)$: $a[3][1] - a[3][0] - a[2][1] + a[2][0] = 2 - 0 - 1 + 0 = 1$.
- Truy vấn $(1,1)$ đến $(2,2)$: $a[2][2] - a[2][0] - a[0][2] + a[0][0] = 2 - 0 - 0 + 0 = 2$.

Kết quả:
```
3
1
2
```

## Độ phức tạp

- **Thời gian:** $O(n^2 + q)$
- **Bộ nhớ:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Forest%20Queries.cpp)
