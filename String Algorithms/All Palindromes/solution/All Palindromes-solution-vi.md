# All Palindromes - Lời giải

**ID:** 3138 | **URL:** https://cses.fi/problemset/task/3138

## Đề bài

Cho một chuỗi $s$ độ dài $n$, với mỗi vị trí $i$ ($1 \le i \le n$), hãy tìm độ dài chuỗi đối xứng (palindrome) dài nhất kết thúc tại vị trí $i$.

## Hướng tiếp cận

### Bước 1: Biến đổi chuỗi bằng ký tự sentinel

Chèn ký tự sentinel `$` giữa mọi cặp ký tự liên tiếp và ở cả hai đầu, tạo ra chuỗi $t$ độ dài $2n+1$. Ví dụ, $s = \text{"abba"}$ trở thành $t = \text{"\$a\$b\$b\$a\$"}$.

**Tính chất:** Mọi chuỗi đối xứng trong $t$ đều có độ dài lẻ. Một chuỗi đối xứng tâm $c$ bán kính $r$ trong $t$ tương ứng với một chuỗi đối xứng độ dài $r$ trong $s$.

### Bước 2: Thuật toán Manacher

Tính mảng $\text{manacher}[i]$ = bán kính chuỗi đối xứng dài nhất nhận $i$ làm tâm trong $t$, tức $t[i - \text{manacher}[i] .. i + \text{manacher}[i]]$ là chuỗi đối xứng.

Thuật toán duy trì một cửa sổ đối xứng $[l, r]$ xa nhất về bên phải (tâm $l$, biên phải $r = l + \text{manacher}[l]$) để tận dụng tính đối xứng gương:

1. Nếu $i \le r$, khởi tạo $\text{manacher}[i] = \min(r - i, \text{manacher}[2l - i])$ (đối xứng qua tâm $l$); ngược lại khởi tạo bằng $0$.
2. Mở rộng bằng cách so sánh $t[i - \text{manacher}[i] - 1]$ và $t[i + \text{manacher}[i] + 1]$.
3. Nếu $i + \text{manacher}[i] > r$, cập nhật $l = i$, $r = i + \text{manacher}[i]$.

### Bước 3: Tìm palindrome dài nhất kết thúc tại mỗi vị trí

Xét một vị trí $i$ lẻ trong $t$ (tương ứng một ký tự thực trong $s$). Mọi chuỗi đối xứng kết thúc đúng tại $i$ đều có tâm $c \le i$, dùng bán kính $i - c$ để chạm tới $i$, và có độ dài trong $s$ là $i - c + 1$. Để hợp lệ, tâm $c$ phải có bán kính đủ lớn: $c + \text{manacher}[c] \ge i$ (biên phải của palindrome tâm $c$ bao phủ tới $i$).

Vì độ dài $i - c + 1$ tăng khi $c$ giảm, **tâm nhỏ nhất** (xa $i$ nhất về phía trái) vẫn thoả $c + \text{manacher}[c] \ge i$ sẽ cho chuỗi đối xứng dài nhất kết thúc tại $i$.

Tối ưu bằng một hàng đợi (queue) lưu các tâm theo thứ tự tăng dần, duyệt $i$ từ trái sang phải:

- Loại bỏ liên tục các tâm ở đầu hàng đợi nếu biên phải không còn bao phủ tới $i$: $c + \text{manacher}[c] < i$.
- Đẩy $i$ vào cuối hàng đợi làm tâm ứng cử mới.
- Nếu $i$ lẻ, đáp án cho vị trí tương ứng trong $s$ là $i - (\text{tâm đầu hàng đợi}) + 1$.

**Tại sao đầu hàng đợi cho kết quả tối ưu?** Các tâm được lưu theo thứ tự tăng dần. Khi một tâm bị loại (vì $c + \text{manacher}[c] < i$), nó cũng không thể bao phủ bất kỳ vị trí $i' > i$ nào sau đó, nên việc loại bỏ là an toàn và không cần khôi phục. Sau khi loại bỏ, tâm ở đầu hàng đợi là tâm nhỏ nhất vẫn bao phủ $i$; vì độ dài $i - c + 1$ đạt lớn nhất khi $c$ nhỏ nhất, tâm đầu hàng đợi chính là tâm cho chuỗi đối xứng dài nhất kết thúc tại $i$.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"ababbababaa"}$ ($n = 11$). Chuỗi biến đổi $t = \text{"\$a\$b\$a\$b\$b\$a\$b\$a\$b\$a\$a\$"}$ ($|t| = 23$).

Bảng $\text{manacher}$ (chỉ số $i$ tính từ $0$):

| $i$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| $t[i]$ | \$ | a | \$ | b | \$ | a | \$ | b | \$ | b | \$ | a | \$ | b | \$ | a | \$ | b | \$ | a | \$ | a | \$ |
| $\text{manacher}$ | 0 | 1 | 0 | 3 | 0 | 3 | 0 | 1 | 8 | 1 | 0 | 3 | 0 | 5 | 0 | 5 | 0 | 3 | 0 | 1 | 2 | 1 | 0 |

Các vị trí lẻ $i = 1, 3, 5, \dots, 21$ tương ứng với $s[1..11]$. Quá trình duyệt deque cho:

| $i$ | 1 | 3 | 5 | 7 | 9 | 11 | 13 | 15 | 17 | 19 | 21 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| tâm đầu deque | 1 | 3 | 3 | 5 | 8 | 8 | 8 | 8 | 13 | 15 | 20 |
| kết quả | 1 | 1 | 3 | 3 | 2 | 4 | 6 | 8 | 5 | 5 | 2 |

Một số bước đáng chú ý:

- $i = 5$: tâm đầu $3$, $\text{manacher}[3] = 3$ nên $3 + 3 = 6 \ge 5$. Đáp án $5 - 3 + 1 = 3$ (palindrome $\text{"aba"}$).
- $i = 9$: các tâm $1, 3, 5, 7$ bị loại vì không còn bao phủ $9$; tâm đầu mới là $8$ với $\text{manacher}[8] = 8$. Đáp án $9 - 8 + 1 = 2$ (palindrome $\text{"bb"}$).
- $i = 15$: tâm đầu vẫn là $8$ vì $8 + 8 = 16 \ge 15$. Đáp án $15 - 8 + 1 = 8$ (palindrome $\text{"ababbaba"}$).
- $i = 17$: tâm $8$ bị loại ($8 + 8 = 16 < 17$), tâm đầu mới là $13$ với $\text{manacher}[13] = 5$. Đáp án $17 - 13 + 1 = 5$ (palindrome $\text{"babab"}$).

Kết quả: `1 1 3 3 2 4 6 8 5 5 2`.

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ Manacher tuyến tính; mỗi vị trí được thêm vào và loại khỏi deque nhiều nhất một lần.
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/All%20Palindromes.cpp)
