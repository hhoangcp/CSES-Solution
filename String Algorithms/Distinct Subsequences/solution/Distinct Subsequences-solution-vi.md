# Distinct Subsequences - Lời giải

**ID:** 1149 | **URL:** https://cses.fi/problemset/task/1149

## Đề bài

Cho một chuỗi $s$ độ dài $n$. Bằng cách xóa một số ký tự (giữ nguyên thứ tự các ký tự còn lại), có thể tạo ra bao nhiêu chuỗi khác nhau? Kết quả lấy theo modulo $10^9+7$ (không tính chuỗi rỗng).

## Hướng tiếp cận

### Bước 1: Định nghĩa quy hoạch động

Gọi $dp[i]$ là số dãy con khác nhau của tiền tố $s[1..i]$, **tính cả dãy con rỗng** (để công thức được gọn). 

**Trường hợp cơ sở:** $dp[0] = 1$ (chỉ có dãy rỗng).

### Bước 2: Công thức truy hồi và loại trùng lặp

Khi thêm ký tự $c = s[i]$, mỗi dãy con của $s[1..i-1]$ có hai lựa chọn: giữ nguyên, hoặc thêm $c$ vào cuối. Bắt nhẩm công thức là $dp[i] = 2 \cdot dp[i-1]$. Tuy nhiên việc thêm $c$ ở vị trí $i$ sẽ tạo ra những dãy con kết thúc bằng $c$ vốn đã được tạo từ lần xuất hiện trước đó của $c$, gây đếm trùng.

Gọi $j$ là vị trí xuất hiện gần nhất của $c$ trước $i$ (nếu $c$ chưa từng xuất hiện thì không có $j$). Đặt $\text{pre}[c] = j - 1$, khi đó $dp[\text{pre}[c]] = dp[j-1]$ chính là số dãy con khác nhau của tiền tố $s[1..j-1]$.

**Số lượng bị trùng chính bằng $dp[\text{pre}[c]]$.** Thật vậy, mỗi dãy con $w$ của $s[1..j-1]$ khi thêm $c$ cho ra $w + c$; chuỗi này cũng tạo được bằng cách lấy dãy con $w$ của $s[1..i-1]$ rồi thêm $c$ tại vị trí $i$ — hai cách tạo ra cùng một chuỗi nên bị trùng. Ngược lại, mọi chuỗi $w + c$ đã được đếm từ trước (không dùng vị trí $i$) đều lấy ký tự $c$ từ một vị trí $\le j$, nên $w$ là dãy con của $s[1..j-1]$. Vậy số trùng lặp đúng bằng $dp[j-1] = dp[\text{pre}[c]]$.

Công thức truy hồi:

$$dp[i] = 2 \cdot dp[i-1] - dp[\text{pre}[s[i]]]$$

(khi $\text{pre}[s[i]] = -1$, tức $c$ chưa từng xuất hiện, không có trùng lặp nên $dp[i] = 2 \cdot dp[i-1]$).

Vì có phép trừ, cần thực hiện modulo cẩn thận để tránh giá trị âm (cộng thêm $10^9+7$ trước khi lấy dư).

### Bước 3: Đáp án cuối cùng

$dp[n]$ đếm tất cả dãy con khác nhau **bao gồm dãy rỗng**. Đề bài yêu cầu đếm các chuỗi tạo ra bằng cách xóa ký tự (không tính chuỗi rỗng), nên đáp án là:

$$\text{Đáp án} = (dp[n] - 1) \bmod (10^9 + 7)$$

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"aybabtu"}$ ($n = 7$).

| $i$ | $s[i]$ | $dp[i-1]$ | $2 \cdot dp[i-1]$ | $\text{pre}[s[i]]$ | $dp[\text{pre}]$ | $dp[i]$ |
|---|---|---|---|---|---|---|
| 0 | — | — | — | — | — | 1 |
| 1 | a | 1 | 2 | $-1$ | — | 2 |
| 2 | y | 2 | 4 | $-1$ | — | 4 |
| 3 | b | 4 | 8 | $-1$ | — | 8 |
| 4 | a | 8 | 16 | $0$ | $1$ | 15 |
| 5 | b | 15 | 30 | $2$ | $4$ | 26 |
| 6 | t | 26 | 52 | $-1$ | — | 52 |
| 7 | u | 52 | 104 | $-1$ | — | 104 |

Một số bước đáng chú ý:

- $i = 1, 2, 3$: các ký tự `a`, `y`, `b` xuất hiện lần đầu nên $\text{pre} = -1$ và $dp[i] = 2 \cdot dp[i-1]$.
- $i = 4$ (ký tự `a` lặp): lần xuất hiện trước của `a` tại $j = 1$, $\text{pre} = 0$, $dp[4] = 16 - dp[0] = 16 - 1 = 15$. Phần trùng là dãy con rỗng $+\text{"a"}$ = $\text{"a"}$ (đã tồn tại).
- $i = 5$ (ký tự `b` lặp): lần xuất hiện trước của `b` tại $j = 3$, $\text{pre} = 2$, $dp[5] = 30 - dp[2] = 30 - 4 = 26$. Phần trùng là 4 dãy con của $\text{"ay"}$ thêm `b`: $\text{"b"}$, $\text{"ab"}$, $\text{"yb"}$, $\text{"ayb"}$ (đều đã tồn tại).
- $i = 6, 7$: `t`, `u` xuất hiện lần đầu nên $dp$ chỉ nhân đôi.

$dp[7] = 104$ (gồm cả dãy rỗng). Đáp án: $104 - 1 = 103$.

Kết quả:
```
103
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ duyệt chuỗi một lần, mỗi vị trí xử lý trong $O(1)$.
- **Bộ nhớ:** $O(n)$ $\textemdash$ mảng $dp$ lưu trạng thái quy hoạch động; mảng $\text{pre}$ cố định 26 phần tử cho các ký tự 'a'–'z'.

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Subsequences.cpp)
