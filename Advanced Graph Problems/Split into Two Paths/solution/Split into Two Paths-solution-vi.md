# Split into Two Paths - Lời giải

**ID:** 3358 | **URL:** https://cses.fi/problemset/task/3358

## Mã nguồn (C++)

### Tóm tắt bài toán

Cho DAG $n$ đỉnh, $m$ cạnh. Xác định có thể phân chia đỉnh thành tối đa hai đường đi có hướng (mỗi đỉnh thuộc đúng 1 đường, đỉnh liên tiếp trong mỗi đường phải có cạnh nối).

### Cách 1: Phủ đường đi tối thiểu bằng Matching

**Ý tưởng chính:** Số đường đi tối thiểu phủ đỉnh trong DAG bằng $n - |M|$, với $M$ là matching cực đại trên đồ thị hai phía xây bằng cách chia mỗi đỉnh $u$ thành $u_L$ (bên trái) và $u_R$ (bên phải), thêm cạnh $u_L \to v_R$ với mỗi cạnh gốc $u \to v$. Cần phủ bằng $\le 2$ đường (một đường có thể rỗng), tức $|M| \ge n - 2$.

**Thuật toán:**
1. Xây đồ thị hai phía: bên trái $\{u_L\}$, bên phải $\{v_R\}$. Với mỗi cạnh $u \to v$, thêm cạnh $u_L \to v_R$.
2. Tìm matching cực đại bằng Hopcroft-Karp. Nếu $|M| < n - 2$ (số đường $> 2$), xuất NO.
3. Trích đường đi từ matching: mỗi đỉnh $u$ không có cạnh matched đi vào $u_R$ là đầu đường; theo cạnh matched $u_L \to v_R$ để duyệt.
4. Xuất YES và tối đa hai đường (nếu chỉ 1 đường, xuất 0 cho đường thứ hai).

### Cách 2: QHĐ trên thứ tự Topo

**Ý tưởng chính:** Mọi đường đi trong DAG thăm đỉnh theo dãy con tăng của thứ tự topo. Nếu hai đường phân chia mọi đỉnh, tồn tại điểm phân chia $s$: đường 1 nằm trong $[1, s]$, đường 2 nằm trong $[s, n]$. Đoạn liên tiếp trong dãy topo là đường hợp lệ nếu mọi cặp liên tiếp có cạnh — theo dõi bằng đánh dấu "khoảng trống" và tiền tố.

**Thuật toán:**
1. **Sắp xếp topo** bằng Kahn. Nếu có chu trình, xuất NO.
2. **Đánh dấu khoảng trống:** Với mỗi vị trí $i = 2 \ldots n$, đánh dấu nếu không có cạnh từ đỉnh thứ $(i-1)$ sang đỉnh thứ $i$ trong thứ tự topo. Tính tiền tố.
3. **Kiểm tra đường:** Đoạn $[l, r]$ là đường hợp lệ nếu không chứa khoảng trống (kiểm tra $O(1)$ bằng tiền tố).
4. **QHĐ:** Gọi $f[j]$ = biên trái của đoạn đường thứ hai kết thúc tại vị trí $j$ (hoặc $-1$ nếu không đạt được).
   - Khởi tạo: với $h = 2 \ldots n$, nếu đoạn $[1, h)$ hợp lệ thì $f[h] = 1$.
   - Với mỗi vị trí $i$ có $f[i] \ne -1$:
     - Nếu đoạn $[i, n]$ hợp lệ, tìm thấy lời giải — tái tạo hai đường.
     - Ngược lại, với mỗi cạnh từ đỉnh thứ $(i-1)$ đến đỉnh $v$ ở vị trí $j > i$: nếu đoạn $[i, j)$ hợp lệ, đặt $f[j] = i$.
5. Nếu không tìm thấy điểm phân chia, xuất NO.

**Tái tạo lời giải:** Truy vết $f[\cdot]$ ngược từ điểm phân chia, xen kẽ đường cho từng đoạn, gom đỉnh thành hai đường.

### Ví dụ minh họa

**Ví dụ YES (Matching):** $n=4$, cạnh: $1 \to 2$, $1 \to 3$, $2 \to 4$, $3 \to 4$.

Đồ thị hai phía: $1_L \to 2_R$, $1_L \to 3_R$, $2_L \to 4_R$, $3_L \to 4_R$. Matching cực đại: $\{1_L \to 2_R, 2_L \to 4_R\}$, $|M|=2 \ge 4-2$. Phân chia: Đường 1: $1 \to 2 \to 4$, Đường 2: $3$.

**Ví dụ NO (Matching):** $n=4$, cạnh: $1 \to 4$, $2 \to 4$, $3 \to 4$.

Đồ thị hai phía: $1_L \to 4_R$, $2_L \to 4_R$, $3_L \to 4_R$. Chỉ khớp được tối đa $|M|=1 < 4-2=2$. Cần ít nhất 3 đường → NO.

**Ví dụ YES (DP trên Topo):** $n=5$, cạnh: $1 \to 2$, $1 \to 4$, $3 \to 4$, $4 \to 5$.

Thứ tự topo: $3, 1, 2, 4, 5$. Đánh dấu khoảng trống: vị trí 2 (không cạnh $3 \to 1$), vị trí 4 (không cạnh $2 \to 4$). Tiền tố: $\text{pref}=[0,0,1,1,2,2]$.

QHĐ:
- Khởi tạo: $f[2]=1$ (đoạn $[1,1]$ hợp lệ). Đoạn $[1,2]$ có gap → dừng.
- $i=2$: Đoạn $[2,5]$ không hợp lệ. Từ $\text{topo}[1]=3$, cạnh $3\to 4$ ở vị trí 4. Đoạn $[2,3]$ hợp lệ ($\text{pref}[3]-\text{pref}[2]=0$) → $f[4]=2$.
- $i=4$: Đoạn $[4,5]$ hợp lệ ($\text{pref}[5]-\text{pref}[4]=0$) → tìm thấy lời giải!

Tái tạo (xen kẽ đường):
- $[4,5]$: đường 1 → $\text{topo}[4..5]=4,5$
- $[2,4)$: đường 2 → $\text{topo}[2..3]=1,2$
- $[1,2)$: đường 1 → $\text{topo}[1]=3$

Kết quả: Đường 1: $3\to 4\to 5$, Đường 2: $1\to 2$. ✓

**Ví dụ NO (DP trên Topo):** $n=4$, cạnh: $1 \to 4$, $2 \to 4$, $3 \to 4$.

Thứ tự topo: $1, 2, 3, 4$. Khoảng trống: vị trí 2, 3. Tiền tố: $\text{pref}=[0,0,1,2,2]$.

QHĐ:
- Khởi tạo: $f[2]=1$ (đoạn $[1,1]$ hợp lệ). Đoạn $[1,2]$ có gap → dừng.
- $i=2$: Đoạn $[2,4]$ không hợp lệ. Từ $\text{topo}[1]=1$, cạnh $1\to 4$ ở vị trí 4. Đoạn $[2,3]$ không hợp lệ → không cập nhật.
- Không còn vị trí đạt được → NO.

### So sánh

| | Matching / Flow | QHĐ trên Topo |
|---|---|---|
| **Thời gian** | $O(m\sqrt{n})$ | $O(n + m)$ |
| **Không gian** | $O(n + m)$ | $O(n + m)$ |
| **Ưu điểm** | Tổng quát cho $k$ đường | Đơn giản, nhanh cho $k=2$ |
| **Mã nguồn** | [C++ (Matching)](../code/Split%20into%20Two%20Paths%20-%20Matching.cpp) | [C++ (DP Topo)](../code/Split%20into%20Two%20Paths%20-%20DP%20Topo.cpp) |

## Độ phức tạp

- **Cách 1:** $O(m\sqrt{n})$ thời gian, $O(n + m)$ không gian
- **Cách 2:** $O(n + m)$ thời gian, $O(n + m)$ không gian
