# Counting Reorders - Lời giải

**ID:** 2421 | **URL:** https://cses.fi/problemset/task/2421

## Phương pháp

### Tóm tắt bài toán

Đếm số cách sắp xếp lại các ký tự của một xâu sao cho không có hai ký tự liền kề nào giống nhau. Kết quả modulo $10^9 + 7$.

### QHD trên nhóm (runs)

Gọi $c_1, c_2, \ldots, c_{26}$ là tần suất các ký tự. Định nghĩa $\text{dp}[i][j]$ = số cách sắp xếp $i$ loại ký tự đầu tiên thành đúng $j$ **nhóm** (đoạn chạy liên tiếp cùng một ký tự).

Ví dụ, dãy `AABBC` có 3 nhóm: `{AA}, {BB}, {C}`.

**Cơ sở:** $\text{dp}[0][0] = 1$ (chưa đặt ký tự nào, 0 nhóm).

**Mục tiêu:** Sắp xếp hợp lệ có $j = n$ nhóm (mỗi ký tự là nhóm riêng, kích thước 1).

### Chuyển trạng thái

Khi thêm loại ký tự $i$ với tần suất $\text{num} = c_i$ vào dãy có $j$ nhóm hiện tại, chia `num` ký tự giống nhau thành $k$ nhóm mới ($1 \le k \le \text{num}$) và xen kẽ chúng vào các nhóm hiện có:

$$\text{dp}[i+1][j+k] \mathrel{+}= \text{dp}[i][j] \cdot \binom{\text{num}-1}{k-1} \cdot \binom{j+k}{k}$$

Hai hệ số tổ hợp đếm:

1. **$\binom{\text{num}-1}{k-1}$**: Chia `num` phần tử giống nhau thành $k$ nhóm không rỗng (sao-chữ-số: đặt $k-1$ vách ngăn vào $\text{num}-1$ vị trí nội).

2. **$\binom{j+k}{k}$**: Xen $k$ nhóm mới vào $j$ nhóm cũ. Phân phối $k$ nhóm giống nhau vào $j+1$ khoảng (trước, giữa và sau các nhóm cũ) bằng sao-chữ-số: $\binom{k+j}{k} = \binom{k+j}{j}$.

Nhiều nhóm mới đặt vào cùng một khoảng sẽ liền kề, tạo đoạn chạy dài hơn của cùng ký tự — điều này được phép trong QHD và sẽ được sửa lại bằng bao hàm - loại trừ.

### Bao hàm - loại trừ

Sau khi xử lý cả 26 loại ký tự, $\text{dp}[26][j]$ đếm các cách sắp xếp thành $j$ nhóm. Một cách sắp xếp có $j$ nhóm thì có $n - j$ cặp ký tự liền kề cùng loại (mỗi nhóm kích thước $g$ đóng góp $g - 1$ cặp, và $\sum(g-1) = n - j$).

Để chỉ đếm cách sắp xếp có **không** cặp vi phạm nào (tức $j = n$), áp dụng bao hàm - loại trừ. Mỗi cách sắp xếp có $n - j$ vi phạm đóng góp $(-1)^{n-j}$ vào tổng có dấu, và theo nguyên lý bao hàm - loại trừ, chỉ các cách không vi phạm còn lại:

$$\text{ans} = \sum_{j=0}^{n} (-1)^{n-j} \cdot \text{dp}[26][j]$$

### Ví dụ minh họa

**Ví dụ đề bài:** xâu `aabc`, $n = 4$, tần suất $a{=}2, b{=}1, c{=}1$.

**Sau 'a' (num=2):** Chia 2 chữ a thành $k$ nhóm, đặt vào 0 nhóm cũ.

| $j$ | $k$ | Công thức | $\text{dp}[1][j{+}k]$ |
|-----|-----|-----------|----------------------|
| 0 | 1 | $1 \cdot \binom{1}{0} \cdot \binom{1}{1} = 1$ | $\text{dp}[1][1] = 1$ |
| 0 | 2 | $1 \cdot \binom{1}{1} \cdot \binom{2}{2} = 1$ | $\text{dp}[1][2] = 1$ |

**Sau 'b' (num=1):** Thêm 1 nhóm b.

| Từ | $k$ | Công thức | Đóng góp |
|------|-----|-----------|-------------|
| $j{=}1$ | 1 | $1 \cdot \binom{0}{0} \cdot \binom{2}{1} = 2$ | $\text{dp}[2][2] {+}{=} 2$ |
| $j{=}2$ | 1 | $1 \cdot \binom{0}{0} \cdot \binom{3}{1} = 3$ | $\text{dp}[2][3] {+}{=} 3$ |

**Sau 'c' (num=1):** Thêm 1 nhóm c.

| Từ | $k$ | Công thức | Đóng góp |
|------|-----|-----------|-------------|
| $j{=}2$ | 1 | $2 \cdot \binom{0}{0} \cdot \binom{3}{1} = 6$ | $\text{dp}[3][3] {+}{=} 6$ |
| $j{=}3$ | 1 | $3 \cdot \binom{0}{0} \cdot \binom{4}{1} = 12$ | $\text{dp}[3][4] {+}{=} 12$ |

Các ký tự d–z có tần suất 0, nên $\text{dp}[26][3] = 6$, $\text{dp}[26][4] = 12$.

**Bao hàm - loại trừ:** $\text{ans} = (-1)^{4-3} \cdot 6 + (-1)^{4-4} \cdot 12 = -6 + 12 = \mathbf{6}$. ✓

6 cách sắp xếp hợp lệ: `abac, abca, acab, acba, baca, caba`.

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — với mỗi loại ký tự trong 26 loại, $O(n)$ nhóm $\times$ $O(n)$ cách chia.
- **Bộ nhớ:** $O(n^2)$ — cho bảng QHD và tổ hợp tính trước.

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Reorders.cpp)
