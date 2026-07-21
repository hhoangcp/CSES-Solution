# Throwing Dice - Lời giải

**ID:** 1096 | **URL:** https://cses.fi/problemset/task/1096

## Phương pháp

### Tóm tắt bài toán

Đếm số cách tung xúc xắc để đạt tổng $n$, mỗi lần tung cho giá trị từ 1 đến 6. Kết quả modulo $10^9+7$. $n$ lên đến $10^{18}$.

### Ý tưởng chính

Gọi $f(n)$ là số cách đạt tổng $n$. Lần tung cuối có thể là 1 đến 6, chia các cách thành các nhóm rời rạc:

$$f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)$$

Cơ sở: $f(0) = 1$, $f(k) = 0$ với $k < 0$.

Đây là truy hồi tuyến tính bậc 6. Chuyển sang dạng ma trận dùng vector trạng thái $\mathbf{v}_n = (f(n{-}5), f(n{-}4), \ldots, f(n))^T$:

$$\mathbf{v}_{n+1} = A \cdot \mathbf{v}_n, \quad A = \begin{pmatrix} 0 & 1 & 0 & 0 & 0 & 0 \\ 0 & 0 & 1 & 0 & 0 & 0 \\ 0 & 0 & 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 0 & 0 & 1 \\ 1 & 1 & 1 & 1 & 1 & 1 \end{pmatrix}$$

5 dòng đầu dịch chuyển cửa sổ; dòng 6 thực hiện truy hồi. Khi đó $\mathbf{v}_n = A^n \cdot \mathbf{v}_0$ với $\mathbf{v}_0 = (0, 0, 0, 0, 0, 1)^T$, và $f(n)$ là phần tử cuối của $\mathbf{v}_n$.

Tính $A^n$ bằng **lũy thừa nhị phân** trong $O(6^3 \log n)$.

### Thuật toán

1. Xây dựng ma trận chuyển $A$ kích thước $6 \times 6$.
2. Tính $A^n$ bằng lũy thừa nhị phân.
3. Xuất phần tử $[5][5]$ của $A^n$.

### Ví dụ minh họa

$n = 8$: $f(1){=}1, f(2){=}2, f(3){=}4, f(4){=}8, f(5){=}16, f(6){=}32, f(7){=}1{+}2{+}4{+}8{+}16{+}32{=}63, f(8){=}2{+}4{+}8{+}16{+}32{+}63{=}125$ $\checkmark$.

## Độ phức tạp

- **Thời gian:** $O(\log n)$ (hằng số $6^3$ mỗi phép nhân ma trận, $\log n$ lần bình phương)
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Throwing%20Dice.cpp)
