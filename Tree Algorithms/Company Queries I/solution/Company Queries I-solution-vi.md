# Company Queries I - Lời giải

**ID:** 1687 | **URL:** https://cses.fi/problemset/task/1687

## Phương pháp

### Tóm tắt bài toán

Một công ty có $n$ nhân viên tạo thành hệ thống phân cấp dạng cây, với nhân viên $1$ là tổng giám đốc (gốc). Mỗi nhân viên khác có đúng một sếp trực tiếp. Xử lý $q$ truy vấn, mỗi truy vấn $(x, k)$ yêu cầu tìm sếp cao hơn $k$ cấp (tức tổ tiên thứ $k$) của nhân viên $x$. Nếu không tồn tại (nhảy vượt qua tổng giám đốc), in $-1$.

**Ràng buộc:** $1 \le n, q \le 2 \cdot 10^5$, $1 \le k \le n$.

### Ý tưởng chính

Nếu mỗi truy vấn nhảy từng bước lên sếp trực tiếp, chi phí là $O(k) = O(n)$, tổng $O(q \cdot n)$ — quá chậm. **Nhị phân nâng (Binary Lifting)** chuẩn bị trước các bước nhảy có độ dài là lũy thừa của $2$ ($1, 2, 4, 8, \dots$), giúp trả lời mỗi truy vấn trong $O(\log n)$.

Gọi $par[u][i]$ là tổ tiên thứ $2^i$ của nhân viên $u$. Công thức truy hồi:

$$par[u][i] = par[par[u][i-1]][i-1]$$

— nhảy $2^i$ cấp bằng cách nhảy $2^{i-1}$ cấp đến sếp trung gian, rồi từ đó nhảy tiếp $2^{i-1}$ cấp. Bảng được tính trong DFS từ gốc. Vì $n \le 2 \cdot 10^5$, chiều cao tối đa của cây không quá $n$, cần $\lceil \log_2 n \rceil = 18$ mức; đặt $LOG = 18$.

**Tính đúng đắn (quy nạp theo $i$):** Với $i = 0$, $par[u][0]$ là cha trực tiếp, đúng bằng tổ tiên thứ $2^0 = 1$. Với $i > 0$, tổ tiên thứ $2^i$ của $u$ chính là tổ tiên thứ $2^{i-1}$ của tổ tiên thứ $2^{i-1}$ của $u$, nên theo giả thiết quy nạp giá trị đúng là $par[par[u][i-1]][i-1]$. Khi trả lời truy vấn, biểu diễn nhị phân của $k$ cho $k = \sum_{i \in S} 2^i$ (duy nhất); nhảy $2^i$ bước ứng với mỗi bit $i$ bật (theo thứ tự bit cao xuống thấp) sẽ di chuyển đúng tổng cộng $k$ bước, tức đến đúng tổ tiên thứ $k$. Nếu tại bước nào $u$ đạt $0$ là đã vượt gốc, kết quả $-1$.

### Thuật toán

1. Đọc $n, q$; dựng danh sách kề cây từ $n-1$ sếp trực tiếp. Đặt $par[1][0] = 0$ (gốc không có cha).
2. DFS từ gốc $1$:
   - Với mỗi $i$ từ $1$ đến $18$: $par[u][i] = par[par[u][i-1]][i-1]$.
   - Với mỗi con $v$ của $u$ (không tính cha): đặt $par[v][0] = u$, rồi DFS($v$).
3. Với mỗi truy vấn $(x, k)$:
   - Đặt $\text{ans} = x$. Duyệt $i$ từ $18$ xuống $0$: nếu bit $i$ của $k$ bật ($k \wedge (1 \ll i) \ne 0$), gán $\text{ans} = par[\text{ans}][i]$.
   - Nếu $\text{ans} = 0$, in $-1$; ngược lại in $\text{ans}$.

### Ví dụ minh họa

Đề bài cho $n = 5$, $q = 3$, danh sách sếp $e_2 = 1,\ e_3 = 1,\ e_4 = 3,\ e_5 = 3$. Cây: nút $1$ là gốc; con của $1$ là $\{2, 3\}$; con của $3$ là $\{4, 5\}$.

Bảng $par[\cdot][0]$ (cha trực tiếp): $par[1][0]=0,\ par[2][0]=1,\ par[3][0]=1,\ par[4][0]=3,\ par[5][0]=3$.

Bảng $par[\cdot][1]$ (tổ tiên thứ $2$): $par[1][1]=0,\ par[2][1]=0,\ par[3][1]=0,\ par[4][1]=1,\ par[5][1]=1$.

- Truy vấn $(4, 1)$: $k = 1 = 2^0$. Nhảy $2^0$ từ $4$: $\text{ans} = par[4][0] = 3$. In $3$.
- Truy vấn $(4, 2)$: $k = 2 = 2^1$. Nhảy $2^1$ từ $4$: $\text{ans} = par[4][1] = 1$. In $1$.
- Truy vấn $(4, 3)$: $k = 3 = 2^0 + 2^1$. Nhảy $2^1$ từ $4$: $\text{ans} = par[4][1] = 1$; nhảy tiếp $2^0$ từ $1$: $\text{ans} = par[1][0] = 0$. In $-1$.

Kết quả: `3`, `1`, `-1` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$ — tiền xử lý $O(n \log n)$, mỗi truy vấn $O(\log n)$.
- **Bộ nhớ:** $O(n \log n)$ — bảng $par$ kích thước $n \times (LOG + 1)$.

## Mã nguồn (C++)

[Mã nguồn](../code/Company%20Queries%20I.cpp)
