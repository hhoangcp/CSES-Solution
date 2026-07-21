# Line Segments Trace II - Lời giải

**ID:** 3428 | **URL:** https://cses.fi/problemset/task/3428

## Phương pháp

### Tóm tắt bài toán

Cho $n$ đoạn thẳng có đầu mút nguyên, mỗi đoạn hoạt động trên khoảng $[x_1, x_2]$, tìm giá trị lớn nhất tại mỗi $x \in \{0, 1, \ldots, m\}$. Nếu không có đoạn nào bao phủ $x$, giá trị là $-1$.

### Ý tưởng chính

Mỗi đoạn từ $(x_1, y_1)$ đến $(x_2, y_2)$ tương ứng với $f(x) = ax + b$ với $a = (y_2 - y_1)/(x_2 - x_1)$ và $b = y_1 - a \cdot x_1$. Khác với Line Segments Trace I (mọi đường trải dài $[0, m]$), ở đây mỗi đường chỉ hoạt động trên $[x_1, x_2]$. Ta cần cấu trúc dữ liệu hỗ trợ chèn đoạn đường thẳng và truy vấn điểm cực đại.

Sử dụng **cây phân đoạn trên $[0, m]$, mỗi nút lưu một đường thẳng** với logic chèn Li Chao. Để chèn đường $f$ trên $[l, r]$: phân giải $[l, r]$ thành $O(\log m)$ nút cây phân đoạn bị bao phủ hoàn toàn (cập nhật đoạn chuẩn). Tại mỗi nút như vậy, áp dụng chèn Li Chao — so sánh đường mới với đường lưu tại mid, giữ đường tốt hơn, đẩy đường kém xuống một con dựa trên độ dốc. Điều này đúng vì hai đường thẳng cắt nhau nhiều nhất một lần, nên đường thua tại mid chỉ có thể thắng ở một nửa.

Để truy vấn tại điểm $x$: duyệt từ gốc đến lá, tính giá trị đường lưu tại mỗi nút trên đường đi, trả về giá trị lớn nhất. Mọi đường hoạt động tại $x$ được chèn tại một nút bao phủ hoàn toàn chứa $x$; nút đó nằm trên đường gốc-lá, và chèn Li Chao đảm bảo đường tối ưu được bảo toàn qua cây. Đường mặc định có giá trị $-1$, xử lý trường hợp không có đoạn.

### Thuật toán

1. Xây cây phân đoạn trên $[0, m]$, mỗi nút khởi tạo đường $y = -1$.
2. Với mỗi đoạn $(x_1, y_1) \to (x_2, y_2)$:
   - Tính $a = (y_2 - y_1) / (x_2 - x_1)$ và $b = y_1 - a \cdot x_1$.
   - Chèn đường $f(x) = ax + b$ trên đoạn $[x_1, x_2]$.
3. Với mỗi $x$ từ 0 đến $m$, truy vấn giá trị lớn nhất và xuất kết quả.

### Ví dụ minh họa

$n = 4$, $m = 5$. Đoạn: $(1,1)\text{–}(3,3)$, $(1,2)\text{–}(4,2)$, $(2,4)\text{–}(5,7)$, $(2,8)\text{–}(5,2)$.

Các đường: $f_1 = x$ trên $[1,3]$, $f_2 = 2$ trên $[1,4]$, $f_3 = x+2$ trên $[2,5]$, $f_4 = -2x+12$ trên $[2,5]$.

| $x$ | Đường hoạt động | Giá trị | max |
|-----|-----------------|---------|-----|
| 0   | (không)         | —       | $-1$ |
| 1   | $f_1, f_2$     | $1, 2$  | 2   |
| 2   | $f_1, f_2, f_3, f_4$ | $2, 2, 4, 8$ | 8   |
| 3   | $f_1, f_2, f_3, f_4$ | $3, 2, 5, 6$ | 6   |
| 4   | $f_2, f_3, f_4$ | $2, 6, 4$ | 6   |
| 5   | $f_3, f_4$     | $7, 2$  | 7   |

Kết quả: `-1 2 8 6 6 7`.

## Độ phức tạp

- **Thời gian:** $O(n \log^2 m)$ cho chèn, $O(m \log m)$ cho truy vấn
- **Không gian:** $O(m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Line%20Segments%20Trace%20II.cpp)
