# Graph Paths II - Lời giải

**ID:** 1724 | **URL:** https://cses.fi/problemset/task/1724

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị có hướng có trọng số gồm $n$ đỉnh và $m$ cạnh. Tìm độ dài đường đi ngắn nhất từ đỉnh $1$ đến đỉnh $n$ đi qua **đúng** $k$ cạnh. Nếu không tồn tại, xuất $-1$.

### Ý tưởng chính

Sử dụng **phép nhân ma trận min-plus** (còn gọi là tích khoảng cách) thay cho phép nhân ma trận thông thường:

$$C[i][j] = \min_{\ell=1}^{n}(A[i][\ell] + B[\ell][j])$$

$C[i][j]$ biểu diễn đường đi ngắn nhất kết hợp hai chặng liên tiếp: từ đỉnh $i$ đến đỉnh trung gian $\ell$ (theo ma trận $A$), rồi từ $\ell$ đến $j$ (theo ma trận $B$).

**Tính chất quan trọng:** Với phép nhân min-plus, $(A^k)[i][j]$ cho đường đi ngắn nhất đúng $k$ cạnh từ $i$ đến $j$.

**Chứng minh quy nạp:** Cơ sở $k=1$: $A[i][j]$ là trọng số cạnh nhỏ nhất từ $i$ đến $j$ (hoặc $\infty$ nếu không có cạnh). Bước quy nạp: giả sử $A^{k-1}[i][\ell]$ cho đường đi ngắn nhất $k-1$ cạnh từ $i$ đến $\ell$. Khi đó $A^k[i][j] = \min_\ell(A^{k-1}[i][\ell] + A[\ell][j])$. Mọi đường đi $k$ cạnh từ $i$ đến $j$ đều đi qua một đỉnh trung gian $\ell$ ở bước cuối: đường đi $k-1$ cạnh từ $i$ đến $\ell$, cộng một cạnh từ $\ell$ đến $j$. Lấy min trên mọi $\ell$ thu được đường đi ngắn nhất $k$ cạnh.

Phép nhân min-plus có tính kết hợp: $(A \cdot B) \cdot C = A \cdot (B \cdot C)$, do cả hai đều cho $\min_{\ell_1, \ell_2}(A[i][\ell_1] + B[\ell_1][\ell_2] + C[\ell_2][j])$. Do đó, lũy thừa nhị phân áp dụng được, tính $A^k$ trong $O(n^3 \log k)$.

### Thuật toán

1. Khởi tạo ma trận $A$ với $A[i][j]$ = trọng số cạnh nhỏ nhất từ $i$ đến $j$ (nhiều cạnh song song thì lấy min), hoặc $\infty$ nếu không có cạnh. Lưu ý: $A[i][i]$ không bằng 0 — đường đi 0 cạnh không hợp lệ vì $k \geq 1$.
2. Tính $A^k$ bằng lũy thừa nhị phân với phép nhân min-plus.
3. Xuất $(A^k)[1][n]$ nếu khác $\infty$, ngược lại xuất $-1$.

### Ví dụ minh họa

$n = 3$, $m = 4$, $k = 8$. Các cạnh: $1 \to 2$ (trọng 5), $2 \to 3$ (trọng 4), $3 \to 1$ (trọng 1), $3 \to 2$ (trọng 2).

$$A = \begin{pmatrix} \infty & 5 & \infty \\ \infty & \infty & 4 \\ 1 & 2 & \infty \end{pmatrix}$$

Sau khi tính $A^8$ bằng lũy thừa nhị phân, $(A^8)[1][3] = 27$. Đường đi tối ưu là $1 \to 2 \to 3 \to 2 \to 3 \to 2 \to 3 \to 2 \to 3$ với tổng chi phí $5 + 4 + 2 + 4 + 2 + 4 + 2 + 4 = 27$. Chú ý rằng đi $3 \to 2$ trực tiếp (chi phí 2) rẻ hơn đi $3 \to 1 \to 2$ (chi phí $1 + 5 = 6$), nên đường đi tối ưu tránh quay lại đỉnh 1.

## Độ phức tạp

- **Thời gian:** $O(n^3 \log k)$
- **Không gian:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Graph%20Paths%20II.cpp)
