# Functional Graph Distribution - Lời giải

**ID:** 2415 | **URL:** https://cses.fi/problemset/task/2415

## Phương pháp

### Tóm tắt bài toán

Với mỗi $k = 1 \ldots n$, đếm số đồ thị hàm trên $n$ đỉnh có đúng $k$ thành phần liên thông. Đồ thị hàm là đồ thị có hướng mà mỗi đỉnh có đúng một cạnh đi ra.

### Cấu trúc đồ thị hàm

Trong đồ thị hàm, duyệt theo cạnh ra từ bất kỳ đỉnh nào luôn kết thúc ở chu trình (vì đồ thị hữu hạn và mỗi đỉnh có bậc ra 1). Mỗi thành phần liên thông chứa đúng một chu trình, nên số thành phần bằng số chu trình. Bài toán quy về: đếm đồ thị hàm có đúng $k$ chu trình.

### Công thức chính

$$\text{ans}(k) = \sum_{i=1}^{n} \binom{n-1}{i-1} \cdot n^{n-i} \cdot c(i, k)$$

với $c(i, k)$ là **số Stirling không dấu loại một** (số hoán vị của $i$ phần tử có đúng $k$ chu trình).

Tổng theo $i$ — số đỉnh nằm trên chu trình. Cố định đỉnh 1 luôn nằm trên chu trình (tránh đếm lặp), chọn $i - 1$ đỉnh chu trình khác từ $n - 1$ đỉnh: $\binom{n-1}{i-1}$. $i$ đỉnh này tạo $k$ chu trình: $c(i, k)$ cách. $n - i$ đỉnh còn lại mỗi đỉnh độc lập chọn đích từ tất cả $n$ đỉnh (tạo cây hướng gắn vào chu trình): $n^{n-i}$.

### Số Stirling không dấu loại một

$$c(i, j) = (i-1) \cdot c(i-1, j) + c(i-1, j-1)$$

Khi thêm phần tử $i$ vào hoán vị của $\{1, \ldots, i{-}1\}$: chèn $i$ vào chu trình hiện có (sau bất kỳ phần tử nào, không đổi số chu trình, $(i{-}1)$ cách), hoặc tạo chu trình mới chỉ chứa $i$ (tăng số chu trình lên 1, 1 cách).

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 3$.

Số Stirling: $c(1,1){=}1$; $c(2,1){=}1, c(2,2){=}1$; $c(3,1){=}2, c(3,2){=}3, c(3,3){=}1$.

| $k$ | $i{=}1$ | $i{=}2$ | $i{=}3$ | **kết quả** |
|-----|---------|---------|---------|-------------|
| 1 | $\binom{2}{0} \cdot 9 \cdot 1 = 9$ | $\binom{2}{1} \cdot 3 \cdot 1 = 6$ | $\binom{2}{2} \cdot 1 \cdot 2 = 2$ | **17** |
| 2 | $\binom{2}{0} \cdot 9 \cdot 0 = 0$ | $\binom{2}{1} \cdot 3 \cdot 1 = 6$ | $\binom{2}{2} \cdot 1 \cdot 3 = 3$ | **9** |
| 3 | 0 | 0 | $\binom{2}{2} \cdot 1 \cdot 1 = 1$ | **1** |

Kết quả: 17, 9, 1. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — tiền xử lý bảng Stirling và tính tất cả đáp án.
- **Bộ nhớ:** $O(n^2)$ — cho bảng số Stirling.

## Mã nguồn (C++)

[Mã nguồn](../code/Functional%20Graph%20Distribution.cpp)
