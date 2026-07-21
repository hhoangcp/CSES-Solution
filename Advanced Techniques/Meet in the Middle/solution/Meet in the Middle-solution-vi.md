# Meet in the Middle - Lời giải

**ID:** 1628 | **URL:** https://cses.fi/problemset/task/1628

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số, có bao nhiêu cách chọn tập con có tổng bằng $x$?

### Ý tưởng chính

Với $n \le 40$, duyệt tất cả $2^{40} \approx 10^{12}$ tập con là không khả thi. Kỹ thuật **Meet in the Middle** chia mảng thành hai nửa, mỗi nửa tối đa 20 phần tử, giảm không gian tìm kiếm xuống $2 \times 2^{20} \approx 2 \times 10^6$.

Với mỗi nửa, liệt kê tất cả tổng tập con vào mảng $D_1$ và $D_2$. Mỗi tập con $S$ của toàn bộ mảng phân rã duy nhất thành $S_1 = S \cap \text{nửa đầu}$ và $S_2 = S \cap \text{nửa sau}$, với $\text{sum}(S) = \text{sum}(S_1) + \text{sum}(S_2)$. Vậy đếm tập con tổng $x$ quy về đếm cặp $(v_1, v_2)$ với $v_1 \in D_1$, $v_2 \in D_2$, $v_1 + v_2 = x$. Mỗi cặp tương ứng đúng 1 tập con, và mọi tập con tổng $x$ đều được đếm đúng 1 lần.

Sắp xếp $D_1$ và $D_2$. Vì $D_1$ sắp tăng, $x - v$ giảm dần khi $v$ tăng, nên quét hai con trỏ trên $D_2$ (chỉ di chuyển sang trái) đếm số phần tử bằng giá trị mục tiêu trong $O(|D_1| + |D_2|)$.

### Thuật toán

1. Chia mảng tại $mid = \lfloor n/2 \rfloor$.
2. Liệt kê tất cả tổng tập con cho mỗi nửa (cắt tỉa tổng vượt $x$).
3. Sắp xếp $D_1$ và $D_2$.
4. Quét $D_1$ từ nhỏ đến lớn; dùng hai con trỏ trên $D_2$ đếm phần tử bằng $x - v$ cho mỗi $v \in D_1$.
5. Xuất tổng đếm.

### Ví dụ minh họa

$n = 4$, $x = 5$, số: $[1, 2, 3, 2]$.

Nửa đầu $[1, 2]$: $D_1 = [0, 1, 2, 3]$. Nửa sau $[3, 2]$: $D_2 = [0, 2, 3, 5]$.

| $v \in D_1$ | Cần $x - v$ | Số lượng trong $D_2$ | Tập con |
|-------------|-------------|----------------------|---------|
| 0 | 5 | 1 | $\emptyset + \{3,2'\}$ |
| 1 | 4 | 0 | — |
| 2 | 3 | 1 | $\{2\} + \{3\}$ |
| 3 | 2 | 1 | $\{1,2\} + \{2'\}$ |

Tổng: 3.

## Độ phức tạp

- **Thời gian:** $O(2^{n/2} \cdot n/2 + 2^{n/2} \log 2^{n/2})$ — liệt kê + sắp xếp.
- **Không gian:** $O(2^{n/2})$

## Mã nguồn (C++)

[Mã nguồn](../code/Meet%20in%20the%20Middle.cpp)
