# Tournament Graph Distribution - Lời giải

**ID:** 3232 | **URL:** https://cses.fi/problemset/task/3232

## Phương pháp

### Tóm tắt bài toán

Với mỗi $k = 1 \ldots n$, đếm số đồ thị giải đấu trên $n$ đỉnh có đúng $k$ thành phần liên thông mạnh (SCC). Đồ thị giải đấu có đúng một cạnh hướng giữa mỗi cặp đỉnh. Kết quả modulo $10^9 + 7$.

### Đếm đồ thị giải đấu liên thông mạnh $T[i]$

Tổng số đồ thị giải đấu trên $i$ đỉnh là $2^{\binom{i}{2}}$ (mỗi cặp trong $\binom{i}{2}$ cặp độc lập chọn 1 trong 2 hướng). Để đếm chỉ các đồ thị liên thông mạnh, trừ các trường hợp không liên thông mạnh:

$$T[i] = 2^{\binom{i}{2}} - \sum_{j=1}^{i-1} \binom{i}{j} \cdot T[j] \cdot 2^{\binom{i-j}{2}}$$

**Tại sao công thức đúng:** Đồ thị giải đấu không liên thông mạnh khi và chỉ khi tồn tại tập con riêng $S$ tạo "SCC hút" — tất cả cạnh giữa $S$ và $V \setminus S$ hướng vào $S$. Mỗi đồ thị không liên thông mạnh có **đúng một** SCC hút (đồ thị thu gọn của giải đấu luôn là DAG, mọi DAG có đúng một điểm hút). Vậy mỗi đồ thị bị trừ đúng một lần. Các thành phần:

- $\binom{i}{j}$: chọn $j$ đỉnh cho tập $S$.
- $T[j]$: $S$ phải tạo đồ thị liên thông mạnh bên trong.
- $2^{\binom{i-j}{2}}$: $i - j$ đỉnh còn lại tạo đồ thị giải đấu bất kỳ (cạnh liên SCC bị ép hướng cố định, không đóng góp phương án thêm).

### QHD trên phân tách SCC

Cho $T[s]$, tính $\text{dp}[i][k]$ = số cách chia $i$ đỉnh đánh nhãn thành $k$ nhóm **có thứ tự**, nhóm đầu chứa đỉnh 1, mỗi nhóm tạo đồ thị giải đấu liên thông mạnh:

$$\text{dp}[i][k] = \sum_{s=1}^{i} \text{dp}[i-s][k-1] \cdot \binom{i-1}{s-1} \cdot T[s]$$

Nhóm đầu kích thước $s$ phải chứa đỉnh 1, nên chọn thêm $s-1$ đỉnh từ $i-1$ đỉnh còn lại.

### Tại sao nhân $k!$

Trong đồ thị có hướng nói chung, các SCC tạo DAG. Nhưng trong đồ thị giải đấu, DAG thu gọn cũng là đồ thị giải đấu — giữa hai SCC bất kỳ, mọi cạnh hướng cùng một phía. Một giải đấu không chu trình có **thứ tự tô-pô duy nhất** (đường Hamilton). Vậy $k$ SCC có thể xếp theo $k!$ thứ tự, mỗi thứ tự xác định duy nhất tất cả cạnh liên SCC (luôn hướng từ SCC trước sang SCC sau). Mỗi thứ tự tạo đồ thị khác nhau, nên nhân $k!$.

$$\text{ans}(k) = \text{dp}[n][k] \cdot k!$$

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 3$.

$T[1] = 1$, $T[2] = 2^1 - \binom{2}{1} \cdot 1 \cdot 1 = 0$, $T[3] = 2^3 - \binom{3}{1} \cdot 1 \cdot 2 = 2$.

Bảng QHD:

| $(i, k)$ | tính | giá trị |
|----------|------|---------|
| (3, 1) | $\text{dp}[0][0] \cdot \binom{2}{2} \cdot T[3] = 1 \cdot 1 \cdot 2$ | 2 |
| (3, 2) | mọi số hạng 0 (liên quan $T[2] = 0$) | 0 |
| (3, 3) | $\text{dp}[2][2] \cdot \binom{2}{0} \cdot T[1] = 1 \cdot 1 \cdot 1$ | 1 |

Kết quả: $k{=}1$: $2 \cdot 1! = \mathbf{2}$, $k{=}2$: $0 \cdot 2! = \mathbf{0}$, $k{=}3$: $1 \cdot 3! = \mathbf{6}$. ✓

Chú ý: $T[2] = 0$ vì trên 2 đỉnh, giải đấu luôn có người thắng người thua, tạo DAG với 2 SCC riêng biệt.

## Độ phức tạp

- **Thời gian:** $O(n^3)$ — $O(n^2)$ tính $T[i]$ và $O(n^3)$ cho QHD.
- **Bộ nhớ:** $O(n^2)$ — cho tổ hợp, lũy thừa 2, $T$ và bảng QHD.

## Mã nguồn (C++)

[Mã nguồn](../code/Tournament%20Graph%20Distribution.cpp)
