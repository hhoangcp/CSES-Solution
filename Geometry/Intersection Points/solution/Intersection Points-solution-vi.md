# Intersection Points - Lời giải

**ID:** 1740 | **URL:** https://cses.fi/problemset/task/1740

## Phương pháp

### Tóm tắt bài toán

Cho $n$ đoạn thẳng ngang và dọc, đếm số điểm giao nhau. Không có đoạn song song nào cắt nhau, và không có đầu mút nào là giao điểm.

### Ý tưởng chính

Mỗi giao điểm là giao của đúng một đoạn ngang và một đoạn dọc. Đoạn dọc tại $x$ trải $[y_1, y_2]$ cắt đoạn ngang tại $y$ trải $[x_1, x_2]$ khi $x_1 \le x \le x_2$ và $y_1 \le y \le y_2$. Vì không có đầu mút nào là giao điểm, điều kiện nghiêm ngặt và không nghiêm ngặt cho kết quả tương đương.

Quét đường theo trục $x$, duy trì BIT trên tọa độ $y$ theo dõi các đoạn ngang đang hoạt động. Đoạn ngang tại $y$ trải $[x_1, x_2]$ tạo sự kiện mở tại $x_1$ (thêm $+1$ tại $y$) và sự kiện đóng tại $x_2 + 1$ (thêm $-1$ tại $y$). Sự kiện đóng dùng $x_2 + 1$ vì đoạn vẫn hoạt động tại $x_2$. Đoạn dọc tại $x$ trải $[y_1, y_2]$ tạo sự kiện truy vấn tại $x$: số giao điểm bằng số đoạn ngang đang hoạt động trong $[y_1, y_2]$, tính bằng `Query(y₂) - Query(y₁ - 1)`.

Tại mỗi tọa độ $x$, tất cả sự kiện cập nhật đoạn ngang được xử lý trước các truy vấn đoạn dọc, nên BIT phản ánh đúng các đoạn đang hoạt động. Mỗi giao điểm được đếm đúng một lần — khi xử lý truy vấn của đoạn dọc. Nén tọa độ ánh xạ các giá trị $y$ về chỉ số trong $[1, 2n]$ vì chỉ có tối đa $2n$ giá trị phân biệt.

### Thuật toán

1. Với mỗi đoạn:
   - Ngang $[x_1, x_2]$ tại $y$: thêm sự kiện mở $(x_1, y, +1)$ và sự kiện đóng $(x_2 + 1, y, -1)$.
   - Dọc tại $x$ trải $[y_1, y_2]$: thêm sự kiện truy vấn $(x, y_1, y_2)$.
2. Nén tọa độ tất cả giá trị $y$.
3. Sắp xếp sự kiện theo $x$; tại cùng $x$, xử lý cập nhật trước truy vấn.
4. Với mỗi sự kiện:
   - Cập nhật: `Update(rank(y), val)`.
   - Truy vấn: `ans += Query(rank(y₂)) - Query(rank(y₁) - 1)`.
5. Xuất `ans`.

### Ví dụ minh họa

3 đoạn: ngang $(2,3)\text{–}(7,3)$, dọc $(3,1)\text{–}(3,5)$, dọc $(6,2)\text{–}(6,6)$.

Sự kiện sắp xếp theo $x$: mở tại 2, truy vấn tại 3, truy vấn tại 6, đóng tại 8.

- $x=2$: mở đoạn ngang tại $y=3$. BIT: $y=3 \to 1$.
- $x=3$: truy vấn đoạn dọc $[1,5]$. Tổng BIT trong $[1,5] = 1$. → 1 giao điểm.
- $x=6$: truy vấn đoạn dọc $[2,6]$. Tổng BIT trong $[2,6] = 1$. → 1 giao điểm.
- $x=8$: đóng đoạn ngang tại $y=3$. BIT: $y=3 \to 0$.

Tổng: 2.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Intersection%20Points.cpp)
