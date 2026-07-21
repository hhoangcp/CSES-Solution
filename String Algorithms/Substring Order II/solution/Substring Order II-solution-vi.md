# Substring Order II - Lời giải

**ID:** 2109 | **URL:** https://cses.fi/problemset/task/2109

## Đề bài

Cho chuỗi $s$ độ dài $n$ (ký tự 'a'–'z') và số nguyên $k$. Sắp xếp tất cả chuỗi con của $s$ (không nhất thiết phân biệt — mỗi lần xuất hiện được tính riêng) theo thứ tự từ điển, in chuỗi con thứ $k$ nhỏ nhất.

## Hướng tiếp cận

### Bước 1: SAM và lan truyền số lần xuất hiện

Khác với bài *Substring Order I* (mỗi chuỗi phân biệt tính 1 lần), ở đây mỗi lần xuất hiện của một chuỗi con đều được tính riêng, nên cần biết số lần xuất hiện của mỗi chuỗi con.

Xây dựng automaton hậu tố (SAM) cho $s$. Khởi tạo $\text{cnt}[v] = 1$ cho trạng thái tạo mới (non-clone) và $\text{cnt}[\text{clone}] = 0$. Lan truyền dọc liên kết hậu tố theo $\text{len}$ giảm dần:

$$\text{cnt}[\text{link}[v]] \mathrel{+}= \text{cnt}[v]$$

Sau bước này, $\text{cnt}[v]$ = số lần xuất hiện (kích thước tập endpos) của các chuỗi con thuộc trạng thái $v$. Đặt $\text{cnt}[0] = 0$ (chuỗi rỗng không tính).

### Bước 2: QHĐ đếm tổng số chuỗi con (có trùng)

Với mỗi trạng thái $v$, tính $dp[v]$ = tổng số lần xuất hiện của mọi chuỗi con đến được từ $v$ (đi theo các cạnh chuyển). Vì mọi chuyển $v \xrightarrow{c} u$ có $\text{len}[u] > \text{len}[v]$, ta duyệt theo $\text{len}$ giảm dần (thứ tự tô-pô) rồi dùng:

$$dp[v] = \text{cnt}[v] + \sum_{v \xrightarrow{c} u} dp[u]$$

**Tính đúng:** mỗi đường đi từ $v$ tới trạng thái $w$ ứng với một chuỗi con, xuất hiện $\text{cnt}[w]$ lần. Tổng số lần xuất hiện của mọi chuỗi đến từ $v$ là $\sum_{v \leadsto w} \text{cnt}[w]$. Tách theo "dừng tại $v$" (đường đi rỗng, đóng góp $\text{cnt}[v]$) và "đi thêm một cạnh $v \xrightarrow{c} u$ rồi tiếp tục từ $u$" (đóng góp $dp[u]$), thu được đúng công thức trên. (Do $dp[v] \le \frac{n(n+1)}{2}$, giá trị nằm vừa trong 64-bit.)

### Bước 3: Tìm chuỗi con thứ $k$ bằng tham lam

Từ trạng thái 0, duyệt các cạnh chuyển theo thứ tự từ điển (`map` đã sắp xếp). Tại trạng thái $\text{cur}$ và mỗi chuyển $\text{cur} \xrightarrow{c} u$:

- Nếu $dp[u] < k$: chuỗi cần tìm không nằm trong nhánh $c$; bỏ qua, $k \mathrel{-}= dp[u]$.
- Ngược lại ($dp[u] \ge k$): chuỗi cần tìm nằm trong nhánh $c$. Thêm $c$ vào đáp án, $\text{cur} = u$, $k \mathrel{-}= \text{cnt}[u]$ (đã tiêu thụ $\text{cnt}[u]$ lần xuất hiện của chuỗi con hiện tại dẫn tới $u$). Nếu $k \le 0$ thì dừng; nếu $k > 0$ thì tiếp tục tìm chuỗi dài hơn từ $u$.

**Tính đúng:** như bài I, các chuyển ra theo thứ tự từ điển chia các chuỗi con thành các nhóm liên tiếp; duyệt và trừ dần $k$ sẽ dừng đúng nhóm chứa chuỗi thứ $k$. Bên trong nhánh $c$, $\text{cnt}[u]$ lần xuất hiện của "chuỗi hiện tại" đứng ngay trước các chuỗi dài hơn (mở rộng tiếp từ $u$), nên trừ $\text{cnt}[u]$ trước rồi mới xét các mở rộng.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"baabaa"}$ ($n = 6$), $k = 10$. SAM có 8 trạng thái; $dp[0] = 21 = \frac{6\cdot 7}{2}$ (tổng số lần xuất hiện của mọi chuỗi con).

Tìm tham lam (mỗi nhánh ghi $c\to\text{next}$ với $dp$ và $\text{cnt}$):

| bước | trạng thái | $k$ | các nhánh | hành động |
|---|---|---|---|---|
| 1 | 0 | 10 | a→4 ($dp=12$, $\text{cnt}=4$), b→1 ($dp=9$, $\text{cnt}=2$) | $12\ge 10$: chọn `a`, $k-=\text{cnt}[4]=4\to 6$, sang 4 |
| 2 | 4 | 6 | a→3 ($dp=5$, $\text{cnt}=2$), b→5 ($dp=3$, $\text{cnt}=1$) | bỏ `a` ($5<6$, $k\to 1$); $3\ge 1$: chọn `b`, $k-=\text{cnt}[5]=1\to 0$, dừng |

Đáp án: $\text{"ab"}$.

Kiểm tra: 10 chuỗi con nhỏ nhất (đếm trùng) theo thứ tự là `a`, `a`, `a`, `a`, `aa`, `aa`, `aab`, `aaba`, `aabaa`, `ab` — chuỗi thứ 10 đúng là `ab` (4 lần `a`, rồi 2 lần `aa`, rồi `aab`, `aaba`, `aabaa`, rồi `ab`).

Kết quả:
```
ab
```

## Độ phức tạp

- **Thời gian:** $O(n \log \sigma)$ $\textemdash$ xây dựng SAM, lan truyền $\text{cnt}$, tính $dp$, và tìm tham lam đều tuyến tính về số trạng thái/cạnh (hệ số $\log\sigma$, $\sigma=26$, từ bản đồ chuyển).
- **Bộ nhớ:** $O(n)$ $\textemdash$ SAM có tối đa $O(n)$ trạng thái và $O(n)$ cạnh chuyển, cộng các mảng $\text{cnt}$, $dp$ và thứ tự tô-pô.

## Mã nguồn (C++)

[Mã nguồn](../code/Substring%20Order%20II.cpp)
