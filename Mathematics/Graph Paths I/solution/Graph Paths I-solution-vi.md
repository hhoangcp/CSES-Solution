# Graph Paths I - Lời giải

**ID:** 1723 | **URL:** https://cses.fi/problemset/task/1723

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh ($n \le 100$) và $m$ cạnh. Đếm số đường đi từ đỉnh 1 đến đỉnh $n$ có đúng $k$ cạnh ($k \le 10^9$), kết quả lấy modulo $10^9+7$.

### Ý tưởng chính

Gọi $A$ là ma trận kề, với $A[i][j]$ = số cạnh từ $i$ đến $j$. Khi đó $(A^k)[i][j]$ đếm số đường đi đúng $k$ cạnh từ $i$ đến $j$.

*Chứng minh (quy nạp theo $k$).* Cơ sở: $A^1[i][j]$ đếm đường đi 1 cạnh theo định nghĩa. Bước: giả sử $(A^{k-1})[i][\ell]$ đếm đúng số đường đi $k{-}1$ cạnh từ $i$ đến $\ell$. Khi đó:

$$(A^k)[i][j] = \sum_{\ell=1}^{n} (A^{k-1})[i][\ell] \cdot A[\ell][j]$$

Mỗi đường đi $k$ cạnh từ $i$ đến $j$ phân rã duy nhất thành: đường đi $k{-}1$ cạnh từ $i$ đến đỉnh trung gian $\ell$, cộng một cạnh từ $\ell$ đến $j$. Tổng trên mọi $\ell$ đếm chính xác mọi đường đi.

**Lũy thừa nhị phân ma trận.** Vì $k$ lên tới $10^9$, tính $A^k$ bằng chia để trị:

$$A^k = \begin{cases} I & k = 0 \\ (A^{k/2})^2 & k \text{ chẵn} \\ A \cdot (A^{(k-1)/2})^2 & k \text{ lẻ} \end{cases}$$

Mỗi phép nhân ma trận $n \times n$ tốn $O(n^3)$, lũy thừa nhị phân cần $O(\log k)$ lần nhân.

### Thuật toán

1. Xây ma trận kề $A$ từ các cạnh đầu vào.
2. Tính $A^k$ bằng lũy thừa nhị phân ma trận, lấy modulo $10^9+7$ sau mỗi phép nhân.
3. Xuất $(A^k)[1][n]$.

### Ví dụ minh họa

$n = 3$, $m = 4$, $k = 8$, cạnh: $1{\to}2$, $2{\to}3$, $3{\to}1$, $3{\to}2$.

$$A = \begin{pmatrix} 0 & 1 & 0 \\ 0 & 0 & 1 \\ 1 & 1 & 0 \end{pmatrix}, \quad A^8 = \begin{pmatrix} 3 & 4 & 2 \\ 2 & 3 & 4 \\ 4 & 6 & 3 \end{pmatrix}$$

$(A^8)[1][3] = 2$. Hai đường đi: $1{\to}2{\to}3{\to}1{\to}2{\to}3{\to}1{\to}2{\to}3$ và $1{\to}2{\to}3{\to}2{\to}3{\to}2{\to}3{\to}2{\to}3$.

## Độ phức tạp

- **Thời gian:** $O(n^3 \log k)$
- **Bộ nhớ:** $O(n^2)$
