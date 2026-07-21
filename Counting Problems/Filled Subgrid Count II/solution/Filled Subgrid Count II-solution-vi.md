# Filled Subgrid Count II - Lời giải

**ID:** 3414 | **URL:** https://cses.fi/problemset/task/3414

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times n$ gồm các chữ cái in hoa, với mỗi chữ cái trong $k$ chữ cái đầu tiên, đếm số lưới con hình chữ nhật mà mọi ô chứa cùng chữ cái đó.

### Biểu đồ + ngăn xếp đơn điệu

Xử lý mỗi hàng $i$ làm đáy của biểu đồ. Với mỗi cột $j$, duy trì $h[j]$ = số ô liên tiếp cùng chữ cái với $a[i][j]$ kéo dài lên trên:

$$h[j] = \begin{cases} h[j] + 1 & \text{nếu } a[i][j] = a[i-1][j] \\ 1 & \text{ngược lại} \end{cases}$$

Đếm hình chữ nhật đồng nhất có cạnh dưới tại hàng $i$. Quét cột từ trái sang phải trong mỗi đoạn chạy cực đại cùng chữ cái theo chiều ngang — khi $a[i][j] \ne a[i][j{-}1]$, không có hình chữ nhật đồng nhất nào băng qua, nên đặt lại ngăn xếp và tổng.

Duy trì ngăn xếp các cặp (chiều cao, độ rộng) theo thứ tự chiều cao tăng nghiêm ngặt. Với mỗi cột $j$:

1. Loại các phần tử có chiều cao $\ge h[j]$, tích lũy độ rộng. Trừ đóng góp $h_k \cdot w_k$ khỏi tổng đang chạy.
2. Đẩy $(h[j], \text{độ rộng tích lũy} + 1)$, cộng $h[j] \cdot w$ vào tổng.

Tổng sau khi xử lý cột $j$ chính là số hình chữ nhật đồng nhất có cạnh dưới tại hàng $i$ kết thúc tại cột $j$. Nguyên lý: ngăn xếp phân vùng biểu đồ thành các khối chiều cao khác nhau, mỗi khối chiều cao $h_k$ và độ rộng $w_k$ đóng góp $h_k \cdot w_k$ hình chữ nhật — mỗi cách chọn hàng trên (từ $h_k$ lựa chọn) và cột trái (từ $w_k$ lựa chọn).

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$, $k = 3$, lưới:
```
A B B B C
B B B B C
B C A A A
A A A A A
A A A A A
```

Chiều cao biểu đồ $h$ và đóng góp theo hàng:

| Hàng | $h$ | A | B | C |
|------|-----|---|----|---|
| 1 | 1 1 1 1 1 | 1 | 6 | 1 |
| 2 | 1 2 2 2 2 | 0 | 16 | 2 |
| 3 | 2 1 1 1 1 | 6 | 2 | 1 |
| 4 | 1 1 2 2 2 | 21 | 0 | 0 |
| 5 | 2 2 3 3 3 | 36 | 0 | 0 |

Chi tiết hàng 5 (toàn A), tiến trình ngăn xếp tại cột 1–5:

- $j{=}1$: $h{=}2$. Ngăn xếp: $(2,1)$, sum $= 2$.
- $j{=}2$: $h{=}2$. Loại $(2,1)$, đẩy $(2,2)$. Sum $= 4$.
- $j{=}3$: $h{=}3$. Đẩy $(3,1)$. Sum $= 4 + 3 = 7$.
- $j{=}4$: $h{=}3$. Loại $(3,1)$, đẩy $(3,2)$. Sum $= 4 + 6 = 10$.
- $j{=}5$: $h{=}3$. Loại $(3,2)$, đẩy $(3,3)$. Sum $= 4 + 9 = 13$.

Hàng 5 đóng góp A: $2 + 4 + 7 + 10 + 13 = 36$.

**Tổng:** A $= 1{+}0{+}6{+}21{+}36 = \mathbf{64}$, B $= 6{+}16{+}2{+}0{+}0 = \mathbf{24}$, C $= 1{+}2{+}1{+}0{+}0 = \mathbf{4}$. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — mỗi ô được đẩy vào và lấy ra khỏi ngăn xếp tối đa một lần mỗi hàng.
- **Bộ nhớ:** $O(n)$ — cho mảng chiều cao và ngăn xếp đơn điệu.

## Mã nguồn (C++)

[Mã nguồn](../code/Filled%20Subgrid%20Count%20II.cpp)
