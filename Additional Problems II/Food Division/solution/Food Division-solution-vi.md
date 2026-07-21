# Food Division - Lời giải

**ID:** 1189 | **URL:** https://cses.fi/problemset/task/1189

## Đề bài

$n$ trẻ ngồi quanh bàn tròn. Mỗi trẻ có lượng thức ăn hiện tại và mong muốn. Tổng thức ăn khớp. Mỗi bước, một trẻ cho 1 đơn vị thức ăn cho hàng xóm. Tìm số bước tối thiểu.

## Hướng tiếp cận

### Bài toán tuyến tính: Chi phí = Tổng |giá trị tiền tố|

Gọi $d_i = a_i - b_i$ (dư/thiếu). Tổng $d_i = 0$. Với trẻ ngồi hàng thẳng, lượng thức ăn phải qua ranh giới giữa trẻ $i$ và $i{+}1$ chính là $|s_i|$ với $s_i = \sum_{j=1}^{i} d_j$ (dư tích lũy phải gửi sang phải, hoặc thiếu phải nhận từ phải). Mỗi đơn vị chi phí 1, nên tổng chi phí tuyến tính là $\sum |s_i|$.

### Bài toán vòng tròn: Cắt tại điểm $k$, chi phí = $\sum |s_i - s_k|$

Với bàn tròn, chọn một "điểm cắt" sau trẻ $k$ nơi không có thức ăn đi qua — bài toán trở thành tuyến tính tính từ trẻ $k{+}1$. Dịch tổng tiền tố để $s_k = 0$ (điểm cắt), mọi $s_i$ giảm đi $s_k$, chi phí thành $\sum |s_i - s_k|$.

### Tối ưu: Trung vị của $s$

Cần tìm $c$ cực tiểu hóa $f(c) = \sum |s_i - c|$. Theo tính chất tổng độ lệch tuyệt đối, $f(c)$ đạt cực tiểu khi **$c$ là trung vị** của $\{s_1, \ldots, s_n\}$ (mọi điểm cắt $k$ cho $c = s_k$, nên chọn $k$ sao cho $s_k$ gần trung vị nhất; luôn tồn tại $s_k = $ trung vị vì $c$ lấy từ tập $s$).

## Thuật toán

1. Tính $a[i] = a[i] + a[i-1] - b_i$ (tổng tiền tố của $d$, sửa tại chỗ).
2. Sắp xếp mảng tổng tiền tố.
3. Trung vị $m = a[(n{+}1)/2]$.
4. Đáp án $= \sum_{i=1}^{n} |a[i] - m|$.

## Ví dụ minh họa

$n = 3$, $a = [3,5,0]$, $b = [2,4,2]$.

- $d = [1,1,-2]$. Tổng tiền tố: $[1,2,0]$.
- Sắp xếp: $[0,1,2]$. Trung vị $= 1$.
- Đáp án: $|1-1| + |2-1| + |0-1| = 0 + 1 + 1 = 2$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Food%20Division.cpp)
