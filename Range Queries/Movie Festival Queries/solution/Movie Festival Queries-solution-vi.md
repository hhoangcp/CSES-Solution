# Movie Festival Queries - Lời giải

**ID:** 1664 | **URL:** https://cses.fi/problemset/task/1664

## Hướng tiếp cận

### Tóm tắt đề bài

Cho $n$ bộ phim có thời gian bắt đầu và kết thúc, xử lý $q$ truy vấn: nếu đến lúc $s$ và rời lúc $t$, số phim tối đa có thể xem trọn vẹn là bao nhiêu? Có thể xem phim $j$ sau phim $i$ nếu phim $i$ kết thúc $\le$ phim $j$ bắt đầu.

### Ý tưởng cốt lõi

Chiến lược tham lam chọn lịch trình là luôn ưu tiên phim kết thúc sớm nhất. Quay ngược từ thời điểm $t$, mỗi bước nhảy về **thời gian bắt đầu muộn nhất** của một phim kết thúc tại hoặc trước thời điểm hiện tại. Định nghĩa:

$$f[v] = \max\left(\max\{s_i : t_i \le v\}, f[v-1]\right)$$

Phép lấy maximum tiền tố đảm bảo $f$ đơn điệu không giảm. Đứng tại thời điểm $v$, xem 1 phim tối ưu sẽ nhảy lùi về $f[v]$. Đây chính là chọn phim kết thúc gần $v$ nhất có thời gian bắt đầu muộn nhất, tối đa hóa thời gian còn lại cho các phim tiếp theo.

Để tránh duyệt tuyến tính, áp dụng **nhảy nhị phân** (binary lifting): xây dựng $\text{jump}[v][i]$ = thời điểm đạt được sau khi xem $2^i$ phim bắt đầu từ $v$. Cơ sở: $\text{jump}[v][0] = f[v]$. Chuyển trạng thái: $\text{jump}[v][i] = \text{jump}[\text{jump}[v][i-1]][i-1]$. Đúng theo quy nạp: xem $2^{i-1}$ phim từ $v$ đến $\text{jump}[v][i-1]$, rồi $2^{i-1}$ phim nữa từ đó, tổng $2^i$ phim.

### Thuật toán

1. **Xây dựng $f$:** Với mỗi phim $(s_i, t_i)$, đặt $\text{jump}[t_i][0] = \max(\text{jump}[t_i][0], s_i)$. Sau đó tính maximum tiền tố theo thời gian.
2. **Xây bảng nhảy nhị phân:** Với $i = 1$ đến $20$, với mỗi thời điểm $v$: $\text{jump}[v][i] = \text{jump}[\text{jump}[v][i-1]][i-1]$.
3. **Trả lời truy vấn** $(s, t)$: Duyệt $i$ từ $20$ về $0$. Nếu $\text{jump}[t][i] \ge s$, cộng $2^i$ vào đáp án và đặt $t = \text{jump}[t][i]$.

### Ví dụ

Đầu vào:
```
4 3
2 5
6 10
4 7
9 10
5 9
2 10
7 10
```

Phim: $(2,5)$, $(6,10)$, $(4,7)$, $(9,10)$. Giá trị $f$ chính: $f[5]=2$, $f[7]=4$, $f[9]=4$, $f[10]=9$.

- Truy vấn $(5,9)$: $\text{jump}[9][0] = 4 < 5$. Không xem được phim nào. Đáp án = **0**.
- Truy vấn $(2,10)$: $\text{jump}[10][1] = \text{jump}[f[10]][0] = \text{jump}[9][0] = 4 \ge 2$. Nhảy: $+2$ phim, $t = 4$. Rồi $\text{jump}[4][0] = 0 < 2$. Dừng. Đáp án = **2**.
- Truy vấn $(7,10)$: $\text{jump}[10][0] = 9 \ge 7$. Nhảy: $+1$ phim, $t = 9$. Rồi $\text{jump}[9][0] = 4 < 7$. Dừng. Đáp án = **1**.

Kết quả:
```
0
2
1
```

## Độ phức tạp

- **Thời gian:** $O(T \log T + q \log T)$ với $T = 10^6$
- **Bộ nhớ:** $O(T \log T)$

## Mã nguồn (C++)

[Mã nguồn](../code/Movie%20Festival%20Queries.cpp)
