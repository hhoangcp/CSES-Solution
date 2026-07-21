# Grid Paths II - Lời giải

**ID:** 1078 | **URL:** https://cses.fi/problemset/task/1078

## Phương pháp

### Tóm tắt bài toán

Đếm số đường đi từ $(1,1)$ đến $(n,n)$ trên lưới $n \times n$, chỉ đi phải hoặc xuống, tránh $m$ ô bẫy. Kết quả modulo $10^9 + 7$.

### Đếm đường đi không có bẫy

Số đường đi từ $(r_1, c_1)$ đến $(r_2, c_2)$ (với $r_2 \ge r_1$, $c_2 \ge c_1$) không xét bẫy là $\binom{(r_2 - r_1) + (c_2 - c_1)}{r_2 - r_1}$: chọn trong tổng số bước, bước nào là bước xuống.

### Bao hàm - loại trừ QHD trên bẫy

Vì $m \le 1000$ (nhỏ hơn nhiều so với $n$), ta dùng QHD trên danh sách bẫy thay vì trên toàn lưới.

**Sắp xếp bẫy** theo hàng rồi cột. Điều này đảm bảo nếu bẫy $j$ có thể nằm trên đường đi đến bẫy $i$ (tức $r_j \le r_i$ và $c_j \le c_i$) thì $j < i$.

Định nghĩa $P[i]$ = số đường đi từ $(1,1)$ đến bẫy $i$ mà bẫy $i$ là **bẫy đầu tiên** gặp phải. Xử lý bẫy theo thứ tự đã sắp:

$$P[i] = \binom{r_i + c_i - 2}{r_i - 1} - \sum_{\substack{j < i \\ r_j \le r_i, c_j \le c_i}} P[j] \cdot \binom{(r_i - r_j) + (c_i - c_j)}{r_i - r_j}$$

Số hạng đầu đếm tất cả đường đi đến bẫy $i$. Tổng trừ đi các đường đi đã đi qua bẫy $j$ trước đó — với mỗi $j$, có $P[j]$ đường đi đến $j$ là bẫy đầu tiên, rồi tiếp tục tự do đến $i$. Điều kiện $r_j \le r_i$, $c_j \le c_i$ đảm bảo $j$ có thể nằm trên đường đi đến $i$.

**Kết quả cuối cùng:** Trừ đi tất cả đường đi mà bẫy đầu tiên là $i$, rồi tiếp tục đến $(n,n)$:

$$\text{ans} = \binom{2n-2}{n-1} - \sum_{i=1}^{m} P[i] \cdot \binom{(n - r_i) + (n - c_i)}{n - r_i}$$

Mỗi đường đi vi phạm chỉ bị trừ đúng một lần — được gán cho bẫy đầu tiên nó gặp — nên không đếm lặp.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 3$, $m = 1$, bẫy tại $(2, 2)$.

$P[1] = \binom{2}{1} = 2$ (đường đến bẫy: R,D và D,R).

$\text{ans} = \binom{4}{2} - 2 \cdot \binom{2}{1} = 6 - 4 = \mathbf{2}$. ✓

2 đường hợp lệ: RRDD và DDRR (4 đường còn lại đều đi qua $(2,2)$).

**Ví dụ nhiều bẫy:** $n = 3$, bẫy tại $(2,1)$ và $(2,2)$.

- $P[1] = \binom{1}{1} = 1$ (chỉ có đường D đến $(2,1)$).
- $P[2] = \binom{2}{1} - P[1] \cdot \binom{1}{0} = 2 - 1 = 1$ (đường đến $(2,2)$ trừ đường qua $(2,1)$).

$\text{ans} = 6 - 1 \cdot \binom{3}{1} - 1 \cdot \binom{2}{1} = 6 - 3 - 2 = \mathbf{1}$. ✓ (Chỉ RRDD hợp lệ.)

## Độ phức tạp

- **Thời gian:** $O(n + m^2)$ — $O(n)$ tiền xử lý giai thừa, $O(m^2)$ cho QHD trên các cặp bẫy.
- **Bộ nhớ:** $O(n + m)$ — cho giai thừa và thông tin bẫy.

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Paths%20II.cpp)
