# Counting LCM Arrays - Lời giải

**ID:** 3169 | **URL:** https://cses.fi/problemset/task/3169

## Đề bài

Đếm số lượng mảng $a_1, a_2, \ldots, a_n$ gồm các số nguyên dương sao cho Bội chung nhỏ nhất (LCM) của hai phần tử liên tiếp luôn bằng $k$, tức $\operatorname{lcm}(a_i, a_{i+1}) = k$ với mọi $1 \leq i < n$. Kết quả trả về theo modulo $10^9 + 7$.

## Hướng tiếp cận

### 1. Phân tích điều kiện LCM

Để $\operatorname{lcm}(a_i, a_{i+1}) = k$, mọi phần tử $a_i$ đều phải là ước của $k$.

Xét phân tích thừa số nguyên tố của $k$:
$$k = p_1^{e_1} p_2^{e_2} \cdots p_r^{e_r}$$

Với mỗi thừa số nguyên tố $p_j$, gọi mũ của $p_j$ trong $a_i$ là $f_{i,j}$. Điều kiện LCM tương đương với:
$$\max(f_{i,j}, f_{i+1,j}) = e_j$$

Nghĩa là trong hai phần tử liên tiếp, **ít nhất một phần tử** phải có số mũ của $p_j$ bằng đúng $e_j$.

### 2. Tính độc lập giữa các thừa số nguyên tố

Do tính chất của LCM, điều kiện cho từng thừa số nguyên tố $p_j$ là hoàn toàn độc lập với nhau. Tổng số cách chọn mảng $a$ sẽ là **tích** số cách thỏa mãn điều kiện cho từng thừa số nguyên tố $p_j$.

### 3. Quy hoạch động và Lũy thừa ma trận

Với một thừa số nguyên tố $p$ có số mũ $e$ trong $k$, ta cần tìm số cách chọn dãy số mũ $f_1, f_2, \dots, f_n$ sao cho $0 \le f_i \le e$ và $\max(f_i, f_{i+1}) = e$.

Gọi:
- $f_i$: Số cách chọn dãy đến vị trí $i$ sao cho $f_i = e$ (có đúng 1 cách chọn giá trị mũ).
- $g_i$: Số cách chọn dãy đến vị trí $i$ sao cho $f_i < e$ (có $e$ cách chọn giá trị mũ từ $0, 1, \dots, e-1$).

**Công thức truy hồi:**
- $f_i = f_{i-1} + g_{i-1}$ (Nếu $f_i = e$, phần tử trước đó có thể là bất kỳ giá trị nào trong $[0, e]$).
- $g_i = f_{i-1} \cdot e$ (Nếu $f_i < e$, bắt buộc phần tử trước đó $f_{i-1}$ phải bằng $e$ để thỏa mãn $\max(f_{i-1}, f_i) = e$).

**Biểu diễn ma trận:**
$$\begin{pmatrix} f_i \\ g_i \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ e & 0 \end{pmatrix} \begin{pmatrix} f_{i-1} \\ g_{i-1} \end{pmatrix}$$

Với trạng thái cơ bản tại $n=1$ là $f_1 = 1$ và $g_1 = e$. Ta sử dụng **Lũy thừa ma trận** để tính trạng thái tại $n$ trong $O(\log n)$.

## Ví dụ minh họa

Với $n=3, k=4 = 2^2$ ($e=2$):

- Ma trận $M = \begin{pmatrix} 1 & 1 \\ 2 & 0 \end{pmatrix}$.
- $M^{3-1} = M^2 = \begin{pmatrix} 3 & 1 \\ 2 & 2 \end{pmatrix}$.
- $\begin{pmatrix} f_3 \\ g_3 \end{pmatrix} = \begin{pmatrix} 3 & 1 \\ 2 & 2 \end{pmatrix} \begin{pmatrix} 1 \\ 2 \end{pmatrix} = \begin{pmatrix} 5 \\ 6 \end{pmatrix}$.
- Tổng số cách: $5 + 6 = 11$ (Khớp với ví dụ đề bài).

## Độ phức tạp

- **Thời gian:** $O(\sqrt{k} + r \cdot \log n)$, với $r$ là số lượng thừa số nguyên tố phân biệt của $k$ (tối đa khoảng 9-10 số cho $k \le 10^9$).
- **Bộ nhớ:** $O(1)$ (không tính bộ nhớ lưu mảng kết quả).

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20LCM%20Arrays.cpp)
