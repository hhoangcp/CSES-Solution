# Corner Subgrid Count - Lời giải

**ID:** 2137 | **URL:** https://cses.fi/problemset/task/2137

## Phương pháp

### Tóm tắt bài toán

Cho lưới nhị phân $n \times n$, đếm số lưới con kích thước ít nhất $2 \times 2$ mà cả bốn góc đều đen (giá trị 1). Các lưới con như vậy được gọi là *đẹp*.

### Ý tưởng chính

Một lưới con đẹp được xác định bởi hai hàng khác nhau $r_1 < r_2$ và hai cột khác nhau $c_1 < c_2$ sao cho cả bốn vị trí góc đều bằng 1. Cố định cặp hàng $(r_1, r_2)$, gọi $S$ là tập các cột mà cả hai hàng đều có ô 1. Mỗi cặp cột từ $S$ cho một lưới con đẹp, đóng góp $\binom{|S|}{2} = |S|(|S|-1)/2$. Tổng trên tất cả cặp hàng cho kết quả cuối cùng.

Sự phân rã này là song ánh: mỗi lưới con đẹp có biểu diễn duy nhất (cặp hàng, cặp cột) và được đếm đúng một lần; ngược lại, mỗi cặp (hàng, cột) từ $S$ tạo ra lưới con đẹp hợp lệ vì cả bốn góc đều bằng 1 theo định nghĩa $S$.

Tính $|S|$ cho mỗi cặp hàng yêu cầu đếm các cột mà cả hai hàng đều bằng 1, tương đương AND bit hai bitmask hàng. Dùng `long long` 64-bit và `__builtin_popcountll`, ta xử lý 64 cột cùng lúc, giảm chi phí mỗi lần AND-đếm từ $O(n)$ xuống $O(n/64)$.

### Thuật toán

1. Mã hóa mỗi hàng thành bitset dùng mảng số nguyên 64-bit. Bit $j$ của khối $k$ được đặt nếu ô $(i, j)$ bằng 1.
2. Với mỗi cặp hàng $(i, j)$, $i < j$:
   - Tính AND bit từng khối của hai bitmask hàng.
   - Đếm tổng bit 1 trong kết quả AND bằng `__builtin_popcountll`: được $|S|$.
   - Cộng $\binom{|S|}{2}$ vào đáp án.
3. Xuất tổng.

### Ví dụ minh họa

Lưới:
```
5
00010
11111
00110
11001
00010
```

Các cặp hàng có đóng góp dương (chỉ số từ 1):

| Cặp hàng | Kết quả AND | $\|S\|$ | $\binom{\|S\|}{2}$ |
|----------|-------------|---------|---------------------|
| (2,3) | 00110 | 2 | 1 |
| (2,4) | 11001 | 3 | 3 |

(Các cặp hàng còn lại có $|S| \le 1$, đóng góp 0.)

Tổng: $1 + 3 = 4$.

## Độ phức tạp

- **Thời gian:** $O(n^3 / 64)$ — $O(n^2)$ cặp hàng, mỗi cặp tốn $O(n/64)$ cho AND và popcount.
- **Không gian:** $O(n^2 / 64)$ — lưu bitset.

## Mã nguồn (C++)

[Mã nguồn](../code/Corner%20Subgrid%20Count.cpp)
