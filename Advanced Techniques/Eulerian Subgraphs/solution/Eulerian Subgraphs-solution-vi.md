# Eulerian Subgraphs - Lời giải

**ID:** 2078 | **URL:** https://cses.fi/problemset/task/2078

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng $n$ đỉnh và $m$ cạnh. Xét các đồ thị con giữ nguyên $n$ đỉnh và chọn tập con cạnh. Đồ thị con *Euler* là đồ thị mà mỗi đỉnh có bậc chẵn. Đếm số đồ thị con Euler modulo $10^9 + 7$.

### Ý tưởng chính

Xây **rừng bao trùm** bằng DSU. Khi duyệt cạnh, cạnh nối hai thành phần khác nhau là **cạnh cây** (thuộc rừng); cạnh nối hai đỉnh đã cùng thành phần là **cạnh chu trình**. Rừng bao trùm có $n - c$ cạnh cây (với $c$ là số thành phần liên thông), nên số cạnh chu trình là $m - (n - c) = m - n + c$.

Mỗi cạnh chu trình, khi thêm vào rừng, tạo đúng một **chu trình cơ bản**. Các chu trình cơ bản tạo **cơ sở cho không gian chu trình trên $\mathbb{F}_2$**: chúng độc lập tuyến tính và sinh ra mọi đồ thị con Euler. Tương ứng 1-1 đúng vì ma trận liên thuộc của đồ thị trên $\mathbb{F}_2$ có hạng $n - c$ (mỗi thành phần đóng góp $n_i - 1$), nên kernel (không gian chu trình) có chiều $m - n + c$. Mỗi tập con của $m - n + c$ chu trình cơ bản tương ứng đúng với một đồ thị con Euler (XOR các chu trình được chọn), và ngược lại.

Vậy đáp án là $2^{m - n + c} \pmod{10^9 + 7}$.

### Thuật toán

1. Khởi tạo DSU với $n$ phần tử và `res = 1`.
2. Với mỗi cạnh $(u, v)$: nếu `Union(u, v)` thất bại (đã cùng thành phần), nhân `res` với 2 modulo $10^9 + 7$.
3. Xuất `res`.

### Ví dụ minh họa

$n = 4$, $m = 3$, cạnh: (1,2), (1,3), (2,3).

- Cạnh (1,2): khác thành phần → cạnh cây.
- Cạnh (1,3): khác thành phần → cạnh cây.
- Cạnh (2,3): cùng thành phần (2→1→3) → cạnh chu trình. `res *= 2 = 2`.

$c = 2$ (thành phần $\{1,2,3\}$ và đỉnh cô lập $\{4\}$). Đáp án: $2^{3-4+2} = 2^1 = 2$.

Hai đồ thị con Euler: đồ thị rỗng (mọi đỉnh bậc 0) và đồ thị gồm cả 3 cạnh (mọi đỉnh bậc 2).

## Độ phức tạp

- **Thời gian:** $O(m \cdot \alpha(n))$ — mỗi cạnh 1 thao tác DSU.
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Eulerian%20Subgraphs.cpp)
