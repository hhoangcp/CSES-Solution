# Same Sum Subsets - Lời giải

**ID:** 3425 | **URL:** https://cses.fi/problemset/task/3425

## Đề bài

Cho một tập gồm $n$ số nguyên dương, nhiệm vụ của bạn là chọn hai tập con không giao nhau có tổng bằng nhau.

## Hướng tiếp cận

### Bước 1: Bài toán tồn tại lời giải

Ràng buộc $\sum_{i=1}^{n} x_i \leq 2^n - 2$ đảm bảo lời giải tồn tại. Có $2^n - 1$ tập con không rỗng, mỗi tập có tổng là số nguyên dương từ $1$ đến $S = \sum x_i \leq 2^n - 2$, tức có tối đa $2^n - 2$ giá trị phân biệt. Vì $2^n - 1 > 2^n - 2$, theo **nguyên lý chuồng bồ câu**, phải có ít nhất hai tập con khác nhau có cùng tổng.

### Bước 2: Meet-in-the-middle

Với $n \leq 40$, $2^{40}$ quá lớn để liệt kê. Chia mảng thành hai nửa:

- Nửa đầu: $m = \lfloor n/2 \rfloor \leq 20$ phần tử.
- Nửa sau: $n - m \leq 20$ phần tử.

Với mỗi nửa, liệt kê tất cả $2^m$ (hoặc $2^{n-m}$) tổng tập con. Thay vì sắp xếp bằng `sort` $O(2^{n/2} \log 2^{n/2})$, ta dùng **phép liệt kê dựa trên trộn** (tương tự merge sort): khi thêm phần tử thứ $i$, ta có hai nhóm --- tập con không chứa $i$ (giữ nguyên) và tập con chứa $i$ (tăng thêm $a_i$). Trộn hai nhóm đã sắp thành một mảng đã sắp. Tổng thời gian $O(2^{n/2} \cdot n/2)$.

### Bước 3: Tìm hai tập con cùng tổng

Với mảng $D_1$ (tổng nửa đầu) và $D_2$ (tổng nửa sau) đã sắp, ta dùng **tìm kiếm nhị phân** để tìm tổng $s$ mà tồn tại ít nhất hai cách tạo:

- Hàm `countLess(s)`: đếm số cặp $(i, j)$ mà $D_1[i] + D_2[j] < s$, bằng kỹ thuật hai con trỏ trên $D_1$ (giảm) và $D_2$ (tăng).
- Điều kiện $P(s)$: $\text{countLess}(s) \leq s$.
- Chặt nhị phân tìm $s$ lớn nhất thỏa $P(s)$.

**Tính đúng của chặt nhị phân trên hàm không đơn điệu:** Gọi $g(s) = \text{countLess}(s) - s$. Vì $g(s+1) - g(s) = \text{freq}(s) - 1$ ($\text{freq}(s)$ là số cặp có tổng đúng $s$), $g$ không đơn điệu --- $P(s)$ **không** là hàm đơn điệu. Tuy nhiên, chặt nhị phân vẫn đúng nhờ hai bất biến:

1. $P(\texttt{lo})$ đúng. Ban đầu $\text{countLess}(0) = 0 \leq 0$. $\texttt{lo}$ chỉ tăng khi $P(\texttt{mid})$ đúng, nên bất biến được giữ.
2. $P(\texttt{hi} + 1)$ sai. Ban đầu $\text{countLess}(2^n - 1) = 2^n > 2^n - 1$. $\texttt{hi}$ chỉ giảm khi $P(\texttt{mid})$ sai, khi đó $\texttt{hi} = \texttt{mid} - 1$ nên $P(\texttt{hi} + 1) = P(\texttt{mid})$ sai, bất biến được giữ.

Khi hội tụ $\texttt{lo} = \texttt{hi} = s^*$, ta có $P(s^*)$ đúng và $P(s^* + 1)$ sai, tức:

$$\text{countLess}(s^*) \leq s^* \quad \text{và} \quad \text{countLess}(s^* + 1) > s^* + 1$$

Suy ra $\text{freq}(s^*) = \text{countLess}(s^* + 1) - \text{countLess}(s^*) > 1$, tức có ít nhất 2 cặp cùng tổng $s^*$.

Khi tìm được $s^*$, duyệt lại để tìm hai mặt nạ tập con $mask_1$ và $mask_2$ khác nhau đều cho tổng $s^*$.

### Bước 4: Loại bỏ phần tử chung

$mask_1$ và $mask_2$ có thể chung phần tử. Gọi $C = mask_1 \cap mask_2$. Ta có $\text{sum}(mask_1) = \text{sum}(mask_1 \setminus C) + \text{sum}(C) = s$ và $\text{sum}(mask_2) = \text{sum}(mask_2 \setminus C) + \text{sum}(C) = s$, suy ra $\text{sum}(mask_1 \setminus C) = \text{sum}(mask_2 \setminus C)$. Mặt khác $(mask_1 \setminus C) \cap (mask_2 \setminus C) = \emptyset$. Vậy $mask_1' = mask_1 \oplus C$ và $mask_2' = mask_2 \oplus C$ là hai tập con không giao có cùng tổng.

### Ví dụ

$n = 6$, phần tử: $[1, 2, 3, 5, 7, 8]$.

Kết quả: tập $\{2, 3\}$ và tập $\{5\}$, cùng tổng 5.

## Độ phức tạp

- **Thời gian:** $O(2^{n/2} \cdot n)$ --- liệt kê $O(2^{n/2} \cdot n/2)$, trộn, tìm kiếm nhị phân.
- **Bộ nhớ:** $O(2^{n/2})$

## Mã nguồn (C++)

[Mã nguồn](../code/Same%20Sum%20Subsets.cpp)
