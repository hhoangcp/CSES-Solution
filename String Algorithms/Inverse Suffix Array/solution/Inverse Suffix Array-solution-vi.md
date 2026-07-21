# Inverse Suffix Array - Lời giải

**ID:** 3225 | **URL:** https://cses.fi/problemset/task/3225

## Đề bài

Cho mảng hậu tố $sa$ (đánh số từ 1) của một chuỗi $s$ độ dài $n$. Hãy tái tạo $s$ dùng ít ký tự khác nhau nhất (chỉ trong khoảng 'a'–'z'). Nếu không tồn tại chuỗi nào tương ứng với $sa$, in $-1$.

## Hướng tiếp cận

### Bước 1: Mảng hoán vị nghịch và điều kiện khác ký tự

Đặt $p[sa[i]] = i$, tức $p[j]$ là thứ hạng từ điển của hậu tố bắt đầu tại $j$. Quy ước $p[n+1] = 0$ (hậu tố rỗng, luôn nhỏ nhất).

Khi so sánh hai hậu tố kề nhau trong $sa$ là $sa[i]$ và $sa[i+1]$:

- Nếu hai ký tự đầu giống nhau ($s[sa[i]] = s[sa[i+1]]$), thứ tự của chúng do phần còn lại quyết định, tức hậu tố tại $sa[i]+1$ và $sa[i+1]+1$. Vì hậu tố $sa[i]$ đứng trước, bắt buộc $p[sa[i]+1] \le p[sa[i+1]+1]$.
- Nếu $p[sa[i]+1] > p[sa[i+1]+1]$, phần còn lại của hậu tố $sa[i]+1$ lại đứng **sau** $sa[i+1]+1$; để hậu tố $sa[i]$ vẫn đứng trước, hai ký tự đầu **bắt buộc phải khác** ($s[sa[i]] \neq s[sa[i+1]]$), vì nếu giống nhau thì bỏ ký tự đầu sẽ đảo ngược thứ tự, mâu thuẫn với $sa$.

Vậy điều kiện cần và đủ để $s[sa[i]] \neq s[sa[i+1]]$ là:

$$p[sa[i]+1] > p[sa[i+1]+1]$$

### Bước 2: Đếm và gán tham lam

Gọi $C$ là số vị trí $i$ ($1 \le i < n$) thỏa mãn điều kiện trên. Theo thứ tự $sa$, dãy ký tự $s[sa[1]], s[sa[2]], \ldots, s[sa[n]]$ phải không giảm (hậu tố trước nhỏ hơn hậu tố sau), và mỗi vị trí vi phạm ép một bước tăng nghiêm ngặt. Dọc theo dãy này, $C$ bước tăng nghiêm ngặt buộc dùng ít nhất $C + 1$ ký tự khác nhau. Nếu $C + 1 > 26$ (tức $C \ge 26$), vượt quá bảng chữ cái 'a'–'z', in $-1$.

Thuật toán tham lam gán ký tự theo thứ tự $sa$, chỉ tăng đúng tại các vị trí vi phạm nên đạt đúng $C + 1$ ký tự $\textemdash$ tối ưu:

- Gán $s[sa[1]] = \text{'a'}$.
- Duyệt $i$ từ $1$ đến $n-1$:
  - Nếu $p[sa[i]+1] > p[sa[i+1]+1]$: tăng bậc ký tự, $s[sa[i+1]] = s[sa[i]] + 1$.
  - Ngược lại: $s[sa[i+1]] = s[sa[i]]$ (giữ nguyên).

**Tính nhất quán:** Khi không vi phạm, hai ký tự đầu giống nhau là hợp lệ vì thứ tự hậu tố lúc đó hoàn toàn do phần sau quyết định, mà $p[sa[i]+1] \le p[sa[i+1]+1]$ đã đảm bảo phần sau đúng thứ tự; khi vi phạm, $s[sa[i]] < s[sa[i+1]]$ trực tiếp cho $sa[i] < sa[i+1]$. Vậy chuỗi tạo ra có đúng mảng hậu tố $sa$.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $n = 7$, $sa = [4, 1, 3, 5, 6, 7, 2]$.

Mảng hoán vị nghịch $p$ (kèm $p[8] = 0$ cho hậu tố rỗng):

| $j$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|
| $p[j]$ | 2 | 7 | 3 | 1 | 4 | 5 | 6 | 0 |

Kiểm tra điều kiện $p[sa[i]+1] > p[sa[i+1]+1]$:

| $i$ | $sa[i]$ | $sa[i+1]$ | $p[sa[i]+1]$ | $p[sa[i+1]+1]$ | vi phạm? |
|---|---|---|---|---|---|
| 1 | 4 | 1 | $p[5]=4$ | $p[2]=7$ | không |
| 2 | 1 | 3 | $p[2]=7$ | $p[4]=1$ | có |
| 3 | 3 | 5 | $p[4]=1$ | $p[6]=5$ | không |
| 4 | 5 | 6 | $p[6]=5$ | $p[7]=6$ | không |
| 5 | 6 | 7 | $p[7]=6$ | $p[8]=0$ | có |
| 6 | 7 | 2 | $p[8]=0$ | $p[3]=3$ | không |

$C = 2$ (tại $i = 2$ và $i = 5$), cần $C + 1 = 3$ ký tự khác nhau $\le 26$: hợp lệ.

Gán tham lam theo thứ tự $sa$:

| bước | gán | ký tự |
|---|---|---|
| khởi tạo | $s[sa[1]] = s[4]$ | a |
| $i=1$ | $s[sa[2]] = s[1]$ | a (không tăng) |
| $i=2$ | $s[sa[3]] = s[3]$ | b (tăng) |
| $i=3$ | $s[sa[4]] = s[5]$ | b |
| $i=4$ | $s[sa[5]] = s[6]$ | b |
| $i=5$ | $s[sa[6]] = s[7]$ | c (tăng) |
| $i=6$ | $s[sa[7]] = s[2]$ | c |

Kết quả: $s = \text{"acbabbc"}$ (chỉ dùng 3 ký tự `a, b, c`).

Kiểm tra: các hậu tố của `acbabbc` sắp xếp tăng dần cho $sa = [4, 1, 3, 5, 6, 7, 2]$, đúng với đầu vào. Mẫu trong đề bài in `aybabtu` (chuỗi gốc, 5 ký tự), nhưng đề bài chấp nhận **bất kỳ** chuỗi nào có đúng mảng hậu tố đã cho; thuật toán tối thiểu số ký tự khác nhau nên cho `acbabbc`, cũng là một đáp án hợp lệ.

Kết quả:
```
acbabbc
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ xây dựng mảng nghịch đảo $p$, đếm vi phạm và gán ký tự tham lam đều là các vòng lặp tuyến tính.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu mảng hậu tố, mảng nghịch đảo $p$ và chuỗi kết quả.

## Mã nguồn (C++)

[Mã nguồn](../code/Inverse%20Suffix%20Array.cpp)
