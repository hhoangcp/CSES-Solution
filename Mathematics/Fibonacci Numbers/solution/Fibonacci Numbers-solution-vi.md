# Fibonacci Numbers - Lời giải

**ID:** 1722 | **URL:** https://cses.fi/problemset/task/1722

## Phương pháp

### Tóm tắt bài toán

Tính $F_n \bmod (10^9+7)$ với $F_0 = 0$, $F_1 = 1$, $F_n = F_{n-1} + F_{n-2}$, và $0 \le n \le 10^{18}$.

### Ý tưởng chính

Với $n$ lên tới $10^{18}$, $O(n)$ tuần tự không khả thi. Dùng **lũy thừa ma trận** trong $O(\log n)$.

Đặt $\mathbf{v}_n = \begin{pmatrix} F_{n+1} \\ F_n \end{pmatrix}$. Khi đó:

$$\mathbf{v}_n = \begin{pmatrix} F_n + F_{n-1} \\ F_n \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} F_n \\ F_{n-1} \end{pmatrix} = A \cdot \mathbf{v}_{n-1}$$

với $A = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}$. Khai triển: $\mathbf{v}_n = A^n \cdot \mathbf{v}_0 = A^n \begin{pmatrix} 1 \\ 0 \end{pmatrix}$. Vậy $F_n$ là phần tử tại vị trí $(1,0)$ của $A^n$.

*Tính đúng đắn (quy nạp).* $A^n = \begin{pmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{pmatrix}$. Cơ sở: $A^1 = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} = \begin{pmatrix} F_2 & F_1 \\ F_1 & F_0 \end{pmatrix}$. Bước: $A^{n+1} = A \cdot A^n = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{pmatrix} = \begin{pmatrix} F_{n+2} & F_{n+1} \\ F_{n+1} & F_n \end{pmatrix}$.

**Lũy thừa nhị phân ma trận.** Tính $A^n$ bằng chia để trị:

$$A^n = \begin{cases} I & n = 0 \\ (A^{n/2})^2 & n \text{ chẵn} \\ (A^{(n-1)/2})^2 \cdot A & n \text{ lẻ} \end{cases}$$

Mỗi phép nhân ma trận $2 \times 2$ tốn $O(1)$. Tổng: $O(\log n)$.

### Thuật toán

1. Khởi tạo $R = I$ (ma trận đơn vị), $B = A$.
2. Khi $n > 0$: nếu $n$ lẻ, $R \gets R \cdot B$; $B \gets B \cdot B$; $n \gets n/2$.
3. Xuất $R[1][0] \bmod (10^9+7)$.

### Ví dụ minh họa

$n = 10$: $A^{10} = \begin{pmatrix} 89 & 55 \\ 55 & 34 \end{pmatrix}$, nên $F_{10} = 55$.

## Độ phức tạp

- **Thời gian:** $O(\log n)$ — mỗi bước là một phép nhân ma trận $2 \times 2$
- **Bộ nhớ:** $O(1)$
