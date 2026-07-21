# Repeating Substring - Lời giải

**ID:** 2106 | **URL:** https://cses.fi/problemset/task/2106

## Đề bài

Cho một chuỗi $s$ độ dài $n$ gồm các ký tự 'a'–'z'. Chuỗi con lặp lại là chuỗi con xuất hiện từ hai lần trở lên tại các vị trí khác nhau. Hãy in chuỗi con lặp lại dài nhất; nếu có nhiều chuỗi cùng độ dài lớn nhất, in bất kỳ; nếu không có chuỗi con nào lặp lại, in $-1$.

## Hướng tiếp cận

### Bước 1: Mảng hậu tố, LCP và chuỗi con lặp lại

Mảng hậu tố $sa$ sắp xếp mọi hậu tố của $s$ theo thứ tự từ điển; $lcp[i] = \text{LCP}(sa[i-1], sa[i])$ là độ dài tiền tố chung dài nhất của hai hậu tố kề nhau.

**Tính chất cốt lõi:** Nếu một chuỗi con $w$ xuất hiện tại $k \ge 2$ vị trí, $k$ hậu tố tương ứng đều lấy $w$ làm tiền tố, và trong $sa$ chúng tạo thành một đoạn liên tiếp (chung tiền tố thì kề nhau khi sắp xếp); LCP của mỗi cặp kề trong đoạn đó $\ge |w|$.

**Định lý:** $\max_i lcp[i]$ đúng bằng độ dài chuỗi con lặp lại dài nhất.

**Chứng minh:**
- ($\ge$) Gọi $w$ là chuỗi con lặp lại dài nhất (độ dài $|w|$); hai vị trí xuất hiện của $w$ cho hai hậu tố cùng lấy $w$ làm tiền tố, nên $\max lcp \ge |w|$.
- ($\le$) Nếu $lcp[i] = L = \max lcp$ thì hai hậu tố $sa[i-1]$ và $sa[i]$ chia sẻ tiền tố dài $L$; chuỗi con đó (độ dài $L$) xuất hiện cả tại $sa[i-1]$ lẫn $sa[i]$, nên tồn tại chuỗi con lặp lại độ dài $L$, tức chuỗi lặp lại dài nhất $\ge L$.
- Kết hợp hai chiều: $\max lcp = $ độ dài chuỗi con lặp lại dài nhất.

Vậy cặp kề $(sa[i-1], sa[i])$ đạt $\max lcp$ chia sẻ đúng chuỗi con lặp lại dài nhất làm tiền tố.

### Bước 2: Thuật toán và trích xuất kết quả

1. Xây $sa$ bằng SA-IS và tính $lcp$ bằng Kasai, đều trong $O(n)$.
2. Trong lúc tính $lcp$, duy trì $\text{res} = \max lcp$ và $\text{pos}$ = vị trí (trong chuỗi gốc) của hậu tố đạt $\text{res}$ (cập nhật khi gặp giá trị lớn hơn).
3. Nếu $\text{res} \le 0$, không có chuỗi con nào lặp lại $\to$ in $-1$.
4. Ngược lại, in $s[\text{pos}..\text{pos}+\text{res}-1]$: đây là tiền tố chung dài nhất của hậu tố tại $\text{pos}$ với hậu tố đứng ngay trước nó trong $sa$, nên xuất hiện ở cả hai nơi — một chuỗi con lặp lại hợp lệ độ dài $\text{res}$. Đề bài chấp nhận bất kỳ chuỗi lặp lại dài nhất nào nên vị trí $\text{pos}$ được ghi nhận đều cho kết quả đúng.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"cabababc"}$ ($n = 8$).

| $i$ | $sa[i]$ | hậu tố | $lcp[i]$ |
|---|---|---|---|
| 0 | 1 | abababc | — |
| 1 | 3 | ababc | 4 |
| 2 | 5 | abc | 2 |
| 3 | 2 | bababc | 0 |
| 4 | 4 | babc | 3 |
| 5 | 6 | bc | 1 |
| 6 | 7 | c | 0 |
| 7 | 0 | cabababc | 1 |

$\max lcp = 4$ tại $i = 1$: hai hậu tố $sa[0] = 1$ ($\text{"abababc"}$) và $sa[1] = 3$ ($\text{"ababc"}$) chia sẻ tiền tố $\text{"abab"}$ (độ dài 4). Vậy $\text{"abab"}$ là chuỗi con lặp lại dài nhất, xuất hiện tại vị trí 1 và 3 ($s[1..4]$ và $s[3..6]$). Thuật toán ghi nhận $\text{pos} = 3$ (hậu tố tại vị trí 3 có LCP với tiền nhiệm bằng 4) và in $s[3..6] = \text{"abab"}$.

Kết quả:
```
abab
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ xây dựng $sa$ bằng SA-IS và tính $lcp$ bằng Kasai đều tuyến tính.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu mảng hậu tố, mảng Rank, mảng LCP và các mảng bổ trợ.

## Mã nguồn (C++)

[Mã nguồn](../code/Repeating%20Substring.cpp)
