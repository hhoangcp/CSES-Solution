# Line Segments Trace I - Lời giải

**ID:** 3427 | **URL:** https://cses.fi/problemset/task/3427

## Phương pháp

### Tóm tắt bài toán

Cho $n$ đoạn thẳng từ $(0, y_1)$ đến $(m, y_2)$ với độ dốc nguyên, tìm giá trị lớn nhất tại mỗi tọa độ $x \in \{0, 1, \ldots, m\}$.

### Ý tưởng chính

Mỗi đoạn thẳng từ $(0, y_1)$ đến $(m, y_2)$ là hàm tuyến tính $f(x) = ax + b$ với $a = (y_2 - y_1)/m$ và $b = y_1$. Bài toán trở thành: cho $n$ đường thẳng, tìm $\max_i f_i(x)$ tại mỗi $x \in \{0, \ldots, m\}$.

**Cây Li Chao** giải quyết bài toán hiệu quả. Cây được xây trên miền $[0, m]$, mỗi nút bao phủ đoạn $[l, r]$ và lưu một đường thẳng ưu thế. Khi chèn đường mới $f$ vào nút đang chứa đường $g$:

1. So sánh $f$ và $g$ tại $x = \text{mid} = \lfloor(l+r)/2\rfloor$. Nếu $f(\text{mid}) > g(\text{mid})$, đổi chỗ — $g$ trở thành đường kém hơn tại mid nhưng có thể vẫn tốt hơn ở một nửa.
2. Hai đường thẳng cắt nhau nhiều nhất một lần, nên đường kém hơn tại mid chỉ có thể tốt hơn ở một phía. Nếu $g$ có độ dốc nhỏ hơn $f$ (đường ưu thế mới), $g$ chỉ tốt hơn khi $x < x^*$ với $x^*$ là giao điểm. Vì $g(\text{mid}) < f(\text{mid})$, giao điểm $x^*$ nằm bên trái mid, nên đệ quy xuống nửa trái. Ngược lại, nếu $g$ có độ dốc lớn hơn, đệ quy xuống nửa phải.
3. Điều này đảm bảo đường tối ưu tại mọi $x$ được lưu tại một nút nào đó trên đường từ gốc đến lá. Khi truy vấn, tính giá trị đường lưu tại mỗi nút trên đường đi và trả về giá trị lớn nhất.

### Thuật toán

1. Xây cây Li Chao trên miền $[0, m]$.
2. Với mỗi đoạn thẳng, tính $a = (y_2 - y_1)/m$ và $b = y_1$, chèn đường $f(x) = ax + b$.
3. Với mỗi $x$ từ 0 đến $m$, truy vấn giá trị lớn nhất và xuất kết quả.

### Ví dụ minh họa

$n = 4$, $m = 5$. Đoạn: $(0,1)\text{–}(5,6)$, $(0,7)\text{–}(5,2)$, $(0,5)\text{–}(5,5)$, $(0,10)\text{–}(5,0)$.

Các đường: $f_1 = x + 1$, $f_2 = -x + 7$, $f_3 = 5$, $f_4 = -2x + 10$.

| $x$ | $f_1$ | $f_2$ | $f_3$ | $f_4$ | max |
|-----|-------|-------|-------|-------|-----|
| 0   | 1     | 7     | 5     | 10    | 10  |
| 1   | 2     | 6     | 5     | 8     | 8   |
| 2   | 3     | 5     | 5     | 6     | 6   |
| 3   | 4     | 4     | 5     | 4     | 5   |
| 4   | 5     | 3     | 5     | 2     | 5   |
| 5   | 6     | 2     | 5     | 0     | 6   |

Kết quả: `10 8 6 5 5 6`.

## Độ phức tạp

- **Thời gian:** $O(n \log m)$ cho chèn, $O(m \log m)$ cho truy vấn
- **Không gian:** $O(m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Line%20Segments%20Trace%20I.cpp)
