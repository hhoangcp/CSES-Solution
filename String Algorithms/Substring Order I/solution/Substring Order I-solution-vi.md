# Substring Order I - Lời giải

**ID:** 2108 | **URL:** https://cses.fi/problemset/task/2108

## Đề bài

Cho chuỗi $s$ độ dài $n$ (ký tự 'a'–'z') và số nguyên $k$. Sắp xếp tất cả chuỗi con phân biệt của $s$ theo thứ tự từ điển, in chuỗi con thứ $k$ nhỏ nhất.

## Hướng tiếp cận

### Bước 1: Xây dựng SAM

Xây dựng automaton hậu tố (SAM) cho $s$: một DFA tối tiểu nhận biết đúng tập các chuỗi con phân biệt của $s$. Mỗi đường đi từ trạng thái gốc (trạng thái 0) theo các cạnh chuyển tương ứng với một chuỗi con phân biệt, và ngược lại.

### Bước 2: QHĐ đếm số chuỗi con phân biệt

Với mỗi trạng thái $v$, tính $dp[v]$ = số chuỗi con phân biệt đến được từ $v$ (đi theo các cạnh chuyển). Vì mọi cạnh chuyển $v \xrightarrow{c} u$ đều có $\text{len}[u] > \text{len}[v]$, ta duyệt các trạng thái theo $\text{len}$ giảm dần (sắp xếp cơ số, thứ tự tô-pô) rồi dùng:

$$dp[v] = \sum_{v \xrightarrow{c} u} (dp[u] + 1)$$

**Tính đúng:** mỗi đường đi từ $v$ ứng với một chuỗi con phân biệt (SAM là DFA). Với chuyển $v \xrightarrow{c} u$, các chuỗi bắt đầu bằng $c$ gồm: chính $c$ (1 chuỗi) và $c$ nối tiếp một chuỗi con bất kỳ từ $u$ ($dp[u]$ chuỗi) — tổng $dp[u]+1$. Cộng dồn theo các chuyển ra được $dp[v]$. (Vì $dp[v] \le \frac{n(n+1)}{2}$, ta giới hạn mỗi giá trị bởi một hằng số lớn để tránh tràn.)

### Bước 3: Tìm chuỗi con thứ $k$ bằng tham lam

Từ trạng thái 0, duyệt các cạnh chuyển theo thứ tự từ điển (do dùng `map` nên các ký tự đã được sắp xếp). Tại trạng thái $\text{cur}$ và mỗi chuyển $\text{cur} \xrightarrow{c} u$:

- Nếu $dp[u] + 1 < k$: chuỗi cần tìm không nằm trong nhánh $c$; bỏ qua, $k \mathrel{-}= dp[u] + 1$.
- Ngược lại ($dp[u] + 1 \ge k$): chuỗi cần tìm nằm trong nhánh $c$; thêm $c$ vào đáp án, $\text{cur} = u$, $k \mathrel{-}= 1$ (đã chọn chuỗi con chỉ gồm $c$), rồi tiếp tục tìm từ $u$.

Lặp đến khi $k = 0$.

**Tính đúng:** các chuyển ra từ một trạng thái theo thứ tự từ điển chia các chuỗi con thành các nhóm liên tiếp (nhóm đầu = chuỗi bắt đầu bằng ký tự nhỏ nhất, …). Duyệt theo thứ tự này và trừ dần $k$ sẽ dừng đúng tại nhóm chứa chuỗi thứ $k$; bên trong nhóm lại đệ quy tương tự.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"babaacbaab"}$ ($n = 10$), $k = 10$. SAM có 14 trạng thái; $dp[0] = 43$ (tổng số chuỗi con phân biệt).

Tìm tham lam (mỗi nhánh ghi $c\to\text{next}$ và số chuỗi $dp[\text{next}]+1$):

| bước | trạng thái | $k$ | các nhánh | hành động |
|---|---|---|---|---|
| 1 | 0 | 10 | a→6 (21), b→1 (17), c→7 (5) | $21 \ge 10$: chọn `a`, $k\to9$, sang 6 |
| 2 | 6 | 9 | a→11 (7), b→13 (8), c→7 (5) | bỏ `a` ($7<9$, $k\to2$); $8\ge 2$: chọn `b`, $k\to1$, sang 13 |
| 3 | 13 | 1 | a→4 (7) | $7\ge 1$: chọn `a`, $k\to0$, dừng |

Đáp án: $\text{"aba"}$.

Kiểm tra: 10 chuỗi con phân biệt nhỏ nhất theo thứ tự là `a`, `aa`, `aab`, `aac`, `aacb`, `aacba`, `aacbaa`, `aacbaab`, `ab`, `aba`; chuỗi thứ 10 đúng là `aba`.

Kết quả:
```
aba
```

## Độ phức tạp

- **Thời gian:** $O(n \log \sigma)$ $\textemdash$ xây dựng SAM (dùng bản đồ chuyển, $\sigma = 26$), sắp xếp tô-pô theo độ dài, tính $dp$, và tìm tham lam đều tuyến tính về số trạng thái/cạnh (hệ số $\log\sigma$ từ bản đồ chuyển).
- **Bộ nhớ:** $O(n)$ $\textemdash$ SAM có tối đa $O(n)$ trạng thái và $O(n)$ cạnh chuyển, cộng mảng $dp$ và thứ tự tô-pô.

## Mã nguồn (C++)

[Mã nguồn](../code/Substring%20Order%20I.cpp)
