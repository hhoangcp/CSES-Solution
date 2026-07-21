# Lines and Queries I - Lời giải

**ID:** 3429 | **URL:** https://cses.fi/problemset/task/3429

## Phương pháp

### Tóm tắt bài toán

Xử lý truy vấn trực tuyến: (1) thêm đường thẳng $y = ax + b$, (2) tìm giá trị lớn nhất trong tất cả đường đã thêm tại vị trí $x$.

### Ý tưởng chính

Sử dụng cây Li Chao trên miền $x \in [0, 10^5]$. Mỗi nút bao phủ đoạn $[l, r]$ và lưu một đường thẳng ưu thế. Khi chèn đường mới $f$ vào nút đang chứa đường $g$:

1. So sánh $f(\text{mid})$ và $g(\text{mid})$ với $\text{mid} = \lfloor(l+r)/2\rfloor$. Nếu $f$ tốt hơn, đổi chỗ để đường tốt hơn ở lại nút này.
2. Đường kém hơn tại mid chỉ có thể tốt hơn ở một nửa — vì hai đường thẳng cắt nhau nhiều nhất 1 lần, đường kém tại mid hoặc luôn kém, hoặc chỉ tốt hơn ở đúng một nửa. Nếu đường kém có độ dốc nhỏ hơn, đệ quy xuống nửa trái $[l, \text{mid}]$; nếu lớn hơn, đệ quy xuống nửa phải $[\text{mid}+1, r]$. Nếu độ dốc bằng nhau (song song), dừng.
3. Để truy vấn tại $x$, duyệt từ gốc đến lá và tính giá trị đường lưu tại mỗi nút trên đường đi. Đường tối ưu tại $x$ phải được lưu tại một nút nào đó trên đường đi — nó hoặc được giữ tại nút, hoặc được đẩy xuống đúng nhánh nằm trên đường đi.

Mỗi thao tác đệ quy qua tối đa $O(\log m)$ độ sâu vì khoảng giảm đi một nửa mỗi bước. Các nút được khởi tạo với đường có $b = \text{LLONG\_MIN}$ nên không đóng góp vào truy vấn max trước khi có đường thực sự được chèn.

### Thuật toán

1. Xây cây Li Chao trên $[0, 10^5]$, mỗi nút lưu đường có $b = \text{LLONG\_MIN}$.
2. Với mỗi truy vấn:
   - Loại 1 ($a, b$): chèn đường $f(x) = ax + b$.
   - Loại 2 ($x$): truy vấn giá trị lớn nhất tại $x$, xuất kết quả.

### Ví dụ minh họa

6 truy vấn từ đề bài:

| # | Truy vấn | Thao tác | Kết quả |
|---|----------|----------|---------|
| 1 | `1 1 2` | Chèn $y = x + 2$ | — |
| 2 | `2 1` | $\max(x+2)$ tại $x=1$ | 3 |
| 3 | `2 3` | $\max(x+2)$ tại $x=3$ | 5 |
| 4 | `1 0 4` | Chèn $y = 4$ | — |
| 5 | `2 1` | $\max(3, 4)$ tại $x=1$ | 4 |
| 6 | `2 3` | $\max(5, 4)$ tại $x=3$ | 5 |

Kết quả: `3 5 4 5`.

## Độ phức tạp

- **Thời gian:** $O(\log m)$ mỗi thao tác
- **Không gian:** $O(m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Lines%20and%20Queries%20I.cpp)
