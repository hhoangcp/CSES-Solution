# Company Queries II - Lời giải

**ID:** 1688 | **URL:** https://cses.fi/problemset/task/1688

## Phương pháp

### Tóm tắt bài toán

Một công ty có $n$ nhân viên tạo thành hệ thống phân cấp dạng cây, với nhân viên $1$ là tổng giám đốc (gốc). Mỗi nhân viên khác có đúng một sếp trực tiếp. Xử lý $q$ truy vấn, mỗi truy vấn $(a, b)$ yêu cầu tìm sếp chung thấp nhất (Lowest Common Ancestor — LCA) của hai nhân viên $a$ và $b$.

**Ràng buộc:** $1 \le n, q \le 2 \cdot 10^5$.

### Ý tưởng chính

Sử dụng **nhị phân nâng (Binary Lifting)**: tiền xử lý bằng DFS từ gốc để tính:

- $par[u][i]$: tổ tiên thứ $2^i$ của $u$, với công thức truy hồi $par[u][i] = par[par[u][i-1]][i-1]$, cơ sở $par[u][0]$ là cha trực tiếp.
- $depth[u]$: độ sâu của $u$ tính từ gốc.

Đặt $LOG = 18$ vì $n \le 2 \cdot 10^5$.

Với truy vấn LCA$(u, v)$, thực hiện ba bước: (1) **cân bằng độ sâu** — đặt $depth[u] \le depth[v]$ (đổi chỗ nếu cần), nâng $v$ lên đúng $h = depth[v] - depth[u]$ bước bằng cách nhảy theo các bit nhị phân của $h$; (2) nếu sau đó $u = v$ thì đó chính là LCA; (3) ngược lại, **tìm nhị phân LCA** — duyệt $i$ từ $LOG$ xuống $0$, mỗi khi $par[u][i] \ne par[v][i]$ thì nâng cả $u$ và $v$ lên $par[u][i]$. Sau vòng lặp, $u$ và $v$ nằm ngay dưới LCA, kết quả là $par[u][0]$.

**Tính đúng đắn:** Bước cân bằng chỉ nâng $v$ (hoặc $u$) lên phía gốc đúng bằng khoảng chênh lệch độ sâu, vì $v$ chỉ đi lên và không vượt qua LCA (tổ tiên chung của $u, v$ có độ sâu $\le \min(depth[u], depth[v])$), nên LCA không đổi. Sau bước này, $u$ và $v$ cùng độ sâu. Gọi $L = \text{LCA}(u,v)$. Trong vòng lặp bước 3, nếu $par[u][i] \ne par[v][i]$ thì nhảy $2^i$ bước vẫn chưa chạm tới tổ tiên chung (do kết quả hai bên khác nhau), nên nhảy là an toàn và không vượt LCA; nếu $par[u][i] = par[v][i]$ thì nhảy có thể vượt $L$, nên không nhảy. Khảo sát theo bit từ cao xuống thấp đảm bảo sau vòng lặp $u, v$ ở vị trí cao nhất mà chúng còn khác nhau, tức ngay dưới $L$; do đó cha của chúng $par[u][0] = par[v][0] = L$ chính là LCA.

### Thuật toán

1. Đọc $n, q$; dựng danh sách kề cây từ $n-1$ sếp trực tiếp. Đặt $par[1][0] = 0$, $depth[1] = 0$.
2. DFS từ gốc $1$:
   - Với mỗi $i$ từ $1$ đến $18$: $par[u][i] = par[par[u][i-1]][i-1]$.
   - Với mỗi con $v$ của $u$ (không tính cha): đặt $par[v][0] = u$, $depth[v] = depth[u] + 1$, rồi DFS($v$).
3. Với mỗi truy vấn $(a, b)$, gọi hàm LCA$(u, v)$ (ban đầu $u = a, v = b$):
   - Nếu $depth[u] > depth[v]$, đổi chỗ $u, v$. Tính $h = depth[v] - depth[u]$; duyệt $i$ từ $18$ xuống $0$, nếu bit $i$ của $h$ bật thì $v = par[v][i]$.
   - Nếu $u = v$, trả về $u$.
   - Duyệt $i$ từ $18$ xuống $0$: nếu $par[u][i] \ne par[v][i]$, gán $u = par[u][i]$, $v = par[v][i]$.
   - Trả về $par[u][0]$.

### Ví dụ minh họa

Đề bài cho $n = 5$, $q = 3$, danh sách sếp $e_2 = 1,\ e_3 = 1,\ e_4 = 3,\ e_5 = 3$. Cây: nút $1$ là gốc; con của $1$ là $\{2, 3\}$; con của $3$ là $\{4, 5\}$.

$depth$: $depth[1]=0,\ depth[2]=1,\ depth[3]=1,\ depth[4]=2,\ depth[5]=2$.

$par[\cdot][0]$: $par[1][0]=0,\ par[2][0]=1,\ par[3][0]=1,\ par[4][0]=3,\ par[5][0]=3$.

$par[\cdot][1]$: $par[1][1]=0,\ par[2][1]=0,\ par[3][1]=0,\ par[4][1]=1,\ par[5][1]=1$.

- Truy vấn LCA$(4, 5)$: $depth[4] = depth[5] = 2$, $h = 0$ (không phải nhảy). $4 \ne 5$.
  - $i = 1$: $par[4][1] = par[5][1] = 1$, bằng nhau $\to$ không nhảy.
  - $i = 0$: $par[4][0] = par[5][0] = 3$, bằng nhau $\to$ không nhảy.
  - Kết quả $par[4][0] = 3$. In $3$.
- Truy vấn LCA$(2, 5)$: $depth[2] = 1 \le depth[5] = 2$, $h = 1$. Nâng $v = 5$ lên $1$ bước: $v = par[5][0] = 3$. $2 \ne 3$.
  - $i = 0$: $par[2][0] = par[3][0] = 1$, bằng nhau $\to$ không nhảy.
  - Kết quả $par[2][0] = 1$. In $1$.
- Truy vấn LCA$(1, 4)$: $depth[1] = 0 \le depth[4] = 2$, $h = 2 = 2^1$. Nâng $v = 4$ lên $2$ bước: $v = par[4][1] = 1$. $u = v = 1 \to$ trả về $1$. In $1$.

Kết quả: `3`, `1`, `1` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$ — tiền xử lý $O(n \log n)$, mỗi truy vấn LCA $O(\log n)$.
- **Bộ nhớ:** $O(n \log n)$ — bảng $par$ kích thước $n \times (LOG + 1)$ và mảng $depth$.

## Mã nguồn (C++)

[Mã nguồn](../code/Company%20Queries%20II.cpp)
