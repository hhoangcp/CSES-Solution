# SOS Bit Problem - Lời giải

**ID:** 1654 | **URL:** https://cses.fi/problemset/task/1654

## Phương pháp

### Tóm tắt bài toán

Cho danh sách $n$ số nguyên, với mỗi phần tử $x$ tính:
1. Số $y$ sao cho $x \mid y = x$ (tức $y$ là mặt con của $x$)
2. Số $y$ sao cho $x \wedge y = x$ (tức $y$ là siêu tập của $x$)
3. Số $y$ sao cho $x \wedge y \ne 0$

### Ý tưởng chính

Cả ba câu hỏi đều quy về đếm phần tử theo quan hệ mặt con hoặc siêu tập. **SOS DP** (Sum Over Subsets) tính các số liệu này cho mọi mask đồng thời trong $O(h \cdot 2^h)$ thay vì $O(3^h)$ mỗi truy vấn:
- Câu hỏi 1: đếm mặt con của $x$ → $dp_1[x]$
- Câu hỏi 2: đếm siêu tập của $x$ → $dp_0[x]$
- Câu hỏi 3: đếm theo phần bù → $n - dp_1[\overline{x} \wedge (2^h - 1)]$

### Thuật toán

**SOS DP mặt con ($dp_1$):** Khởi tạo $dp_1[mask] = f[mask]$ (tần suất). Với mỗi bit $i$ từ 0 đến $h-1$, nếu bit $i$ được đặt trong $mask$: $dp_1[mask] \mathrel{+}= dp_1[mask \oplus 2^i]$. Điều này cộng dồn số lượng từ mặt con chỉ khác ở bit $i$ bằng 0. Sau khi xử lý hết các bit, $dp_1[mask]$ đếm tất cả phần tử là mặt con của $mask$.

**SOS DP siêu tập ($dp_0$):** Khởi tạo $dp_0[mask] = f[mask]$. Với mỗi bit $i$, nếu bit $i$ **không** được đặt trong $mask$: $dp_0[mask] \mathrel{+}= dp_0[mask \mid 2^i]$. Điều này cộng dồn số lượng từ siêu tập có thêm bit $i$. Sau khi xử lý, $dp_0[mask]$ đếm tất cả phần tử là siêu tập của $mask$.

**Tại sao SOS DP đúng:** Theo quy nạp trên bit $i$. Sau khi xử lý bit $i$, $dp_1[mask]$ đếm chính xác mặt con xét đến bit $0$ đến $i$. Khi bit $i$ được đặt trong $mask$, việc cộng $dp_1[mask \oplus 2^i]$ thêm vào các mặt con có bit $i = 0$; các mặt con có bit $i = 1$ đã được tính trước đó. Chiều siêu tập đối xứng tương tự.

**Câu hỏi 3 qua phần bù:** $x \wedge y \ne 0$ iff $y$ chia sẻ ít nhất một bit với $x$. Phần bù là $x \wedge y = 0$, tức $y$ chỉ dùng các bit mà $x$ không có — $y$ là mặt con của $\overline{x}$ (phần bù bit của $x$, giới hạn $h$ bit). Số lượng là $dp_1[\overline{x} \wedge (2^h - 1)]$, nên đáp án là $n$ trừ đi giá trị này.

### Ví dụ minh họa

Đầu vào: $n = 5$, danh sách $[3, 7, 2, 9, 2]$. $h = 4$, $2^h - 1 = 15$.

Tần suất: $f[2]=2, f[3]=1, f[7]=1, f[9]=1$ (còn lại 0).

**Với $x = 3$ (0011):**
1. Mặt con của 3: $\{0, 1, 2, 3\}$. Tổng = $f[0]+f[1]+f[2]+f[3] = 0+0+2+1 = \mathbf{3}$.
2. Siêu tập của 3 (phần tử có bit 0 và 1): $\{3, 7\}$. Tổng = $f[3]+f[7] = 1+1 = \mathbf{2}$.
3. $\overline{3} \wedge 15 = 12$ (1100). Mặt con của 12: $\{0, 4, 8, 12\}$. Tổng = 0. Đáp án = $5 - 0 = \mathbf{5}$.

**Với $x = 9$ (1001):**
1. Mặt con của 9: $\{0, 1, 8, 9\}$. Tổng = $f[9] = \mathbf{1}$.
2. Siêu tập của 9 (phần tử có bit 0 và 3): $\{9\}$. Tổng = $\mathbf{1}$.
3. $\overline{9} \wedge 15 = 6$ (0110). Mặt con của 6: $\{0, 2, 4, 6\}$. Tổng = $f[2] = 2$. Đáp án = $5 - 2 = \mathbf{3}$.

Kết quả đầy đủ: `3 2 5`, `4 1 5`, `2 4 4`, `1 1 3`, `2 4 4`.

## Độ phức tạp

- **Thời gian:** $O(n + h \cdot 2^h)$
- **Không gian:** $O(2^h)$

## Mã nguồn (C++)

[Mã nguồn](../code/SOS%20Bit%20Problem.cpp)
