# Maximum Building I - Lời giải

**ID:** 1147 | **URL:** https://cses.fi/problemset/task/1147

## Đề bài

Cho một bản đồ khu rừng kích thước $n \times m$ gồm các ô trống (`.`) và các ô có cây (`*`). Nhiệm vụ của bạn là tìm diện tích lớn nhất của một tòa nhà hình chữ nhật có thể đặt vào các ô trống mà không cần chặt bất kỳ cái cây nào.

## Hướng tiếp cận

### 1. Quy bài toán 2D về 1D

Ý tưởng cốt lõi là duyệt qua từng hàng của lưới và coi mỗi hàng đó là "nền" của một biểu đồ hình cột (histogram).

- Với mỗi cột $j$ tại hàng $i$, ta tính chiều cao $h[j]$ là số ô trống liên tiếp kéo dài từ hàng $i$ ngược lên trên.
- Công thức cập nhật chiều cao khi chuyển từ hàng $i-1$ sang hàng $i$:
  - Nếu ô $(i, j)$ là cây (`*`): $h[j] = 0$.
  - Nếu ô $(i, j)$ là ô trống (`.`): $h[j] = h[j] + 1$.

### 2. Giải bài toán "Hình chữ nhật lớn nhất trong biểu đồ"

Tại mỗi hàng $i$, sau khi đã có mảng chiều cao $h[1 \dots m]$, bài toán trở thành tìm hình chữ nhật có diện tích lớn nhất trong biểu đồ này (tương tự bài **Advertisement**).

- Sử dụng **Ngăn xếp đơn điệu (Monotone Stack)** để tìm biên trái $L[j]$ và biên phải $R[j]$ của mỗi cột $j$:
  - $L[j]$ là vị trí gần nhất bên trái $j$ có $h[L[j]] < h[j]$.
  - $R[j]$ là vị trí gần nhất bên phải $j$ có $h[R[j]] < h[j]$.
- Diện tích lớn nhất tại hàng $i$ sử dụng cột $j$ làm chiều cao thấp nhất là:
  $$\text{Area} = h[j] \times (R[j] - L[j] - 1)$$

### 3. Chứng minh tính đúng đắn

- **Tính bao quát:** Mọi hình chữ nhật trống trong lưới 2D đều phải có một hàng dưới cùng nào đó. Khi ta duyệt qua tất cả các hàng từ $1$ đến $n$, ta chắc chắn sẽ xét qua hàng chứa đáy của hình chữ nhật tối ưu.
- **Tính tối ưu của 1D:** Tại mỗi hàng, thuật toán Monotone Stack đảm bảo tìm được hình chữ nhật lớn nhất có thể dựa trên các "cột" ô trống tính từ hàng đó trở lên.

## Ví dụ minh họa

Lưới ví dụ:
```
...*.*.
.*.....
.......
......*
```

- **Hàng 1:** $h = [1, 1, 1, 0, 1, 0, 1]$. Diện tích max = 3.
- **Hàng 2:** $h = [2, 0, 2, 1, 2, 1, 2]$ (cập nhật từ hàng 1). Diện tích max = 5.
- **Hàng 3:** $h = [3, 1, 3, 2, 3, 2, 3]$. Diện tích max = 10.
- **Hàng 4:** $h = [4, 2, 4, 3, 4, 3, 0]$. Diện tích max = 12.

**Kết quả:** 12.

## Độ phức tạp

- **Thời gian:** $O(n \times m)$ — Ta duyệt qua từng ô của lưới một lần để cập nhật chiều cao và thực hiện thuật toán ngăn xếp đơn điệu (tổng cộng $O(m)$ cho mỗi hàng).
- **Bộ nhớ:** $O(m)$ — Chỉ cần lưu mảng chiều cao hiện tại và mảng biên trái/phải cho một hàng.

## Mã nguồn (C++)

[Mã nguồn](../code/Maximum%20Building%20I.cpp)
