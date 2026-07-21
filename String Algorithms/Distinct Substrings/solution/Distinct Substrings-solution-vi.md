# Distinct Substrings - Lời giải

**ID:** 2105 | **URL:** https://cses.fi/problemset/task/2105

## Đề bài

Cho một chuỗi $s$ độ dài $n$ gồm các ký tự 'a'–'z'. Hãy đếm số lượng chuỗi con khác nhau xuất hiện trong $s$.

## Hướng tiếp cận

### Bước 1: Ý tưởng cốt lõi

Mọi chuỗi con của $s$ đều là tiền tố của một hậu tố nào đó. Nếu liệt kê toàn bộ tiền tố của mọi hậu tố, tổng số (kể cả trùng lặp) là:

$$\text{Tổng} = \sum_{i=0}^{n-1} (n - sa[i]) = \frac{n(n+1)}{2}$$

trong đó $sa$ là mảng hậu tố (các chỉ số bắt đầu của các hậu tố, sắp xếp theo thứ tự từ điển). Để loại bỏ trùng lặp, ta cần biết mỗi hậu tố chia sẻ bao nhiêu tiền tố với các hậu tố đứng trước — thông tin này do mảng LCP cung cấp.

### Bước 2: Khử trùng bằng mảng LCP

Mảng LCP lưu độ dài tiền tố chung dài nhất giữa hai hậu tố kề nhau trong mảng hậu tố đã sắp xếp: $lcp[i] = \text{LCP}(sa[i-1], sa[i])$.

Khi xét hậu tố $sa[i]$, nó có $n - sa[i]$ tiền tố. Trong đó, $lcp[i]$ tiền tố đầu tiên đã trùng với hậu tố kề trước $sa[i-1]$ (đã được đếm); phần còn lại là mới:

$$\text{đóng góp của } sa[i] = (n - sa[i]) - lcp[i] \quad (i \ge 1); \qquad \text{đóng góp của } sa[0] = n - sa[0]$$

**Tại sao chỉ cần so với hậu tố kề trước?** Trong mảng hậu tố đã sắp xếp, tiền tố chung dài nhất giữa $sa[i]$ và tập các hậu tố đứng trước nó đúng bằng $lcp[i]$ — giá trị này đạt được với hậu tố kề trước $sa[i-1]$, còn với các hậu tố xa hơn thì tiền tố chung không dài hơn $lcp[i]$. Vậy mọi tiền tố của $sa[i]$ dài hơn $lcp[i]$ đều chưa từng xuất hiện ở các hậu tố trước, còn $lcp[i]$ tiền tố đầu tiên đã được tính — không thừa, không thiếu.

**Hệ quả:** Một chuỗi con xuất hiện tại nhiều vị trí tương ứng với một nhóm liên tiếp các hậu tố cùng chia sẻ tiền tố đó. Hậu tố đầu nhóm đóng góp chuỗi con này (vì $lcp$ của nó với hậu tố ngay trước nhóm nhỏ hơn độ dài chuỗi), còn các hậu tố sau có $lcp \ge$ độ dài chuỗi nên bị trừ đi — chuỗi con được đếm đúng một lần.

### Bước 3: Công thức và thuật toán

Tổng số chuỗi con phân biệt:

$$\text{Kết quả} = \sum_{i=0}^{n-1} (n - sa[i]) - \sum_{i=1}^{n-1} lcp[i]$$

Thuật toán gồm ba bước:

1. Xây dựng mảng hậu tố $sa$ bằng thuật toán SA-IS.
2. Tính mảng LCP bằng thuật toán Kasai.
3. Áp dụng công thức trên để tính kết quả.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"abaa"}$ ($n = 4$).

Mảng hậu tố (chỉ số từ 0) và LCP:

| $i$ | $sa[i]$ | hậu tố | $n - sa[i]$ | $lcp[i]$ | đóng góp mới |
|---|---|---|---|---|---|
| 0 | 3 | a | 1 | — | 1 |
| 1 | 2 | aa | 2 | 1 | 1 |
| 2 | 0 | abaa | 4 | 1 | 3 |
| 3 | 1 | baa | 3 | 0 | 3 |

Giải thích đóng góp:

- $sa[0] = 3$ ($\text{"a"}$): không có hậu tố trước, đóng góp cả 1 tiền tố $\to \text{"a"}$.
- $sa[1] = 2$ ($\text{"aa"}$): $lcp[1] = 1$, tiền tố $\text{"a"}$ đã có ở $sa[0]$; còn 1 tiền tố mới $\to \text{"aa"}$.
- $sa[2] = 0$ ($\text{"abaa"}$): $lcp[2] = 1$, tiền tố $\text{"a"}$ đã có; còn 3 tiền tố mới $\to \text{"ab"}, \text{"aba"}, \text{"abaa"}$.
- $sa[3] = 1$ ($\text{"baa"}$): $lcp[3] = 0$, không trùng; đóng góp cả 3 tiền tố mới $\to \text{"b"}, \text{"ba"}, \text{"baa"}$.

Tổng tiền tố: $1 + 2 + 4 + 3 = 10$. Tổng LCP: $1 + 1 + 0 = 2$. Kết quả: $10 - 2 = 8$.

Tập hợp 8 chuỗi con phân biệt: $\text{"a"}, \text{"b"}, \text{"aa"}, \text{"ab"}, \text{"ba"}, \text{"aba"}, \text{"baa"}, \text{"abaa"}$.

Kết quả:
```
8
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ xây dựng mảng hậu tố bằng SA-IS và tính mảng LCP bằng Kasai đều tuyến tính.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu mảng hậu tố, mảng LCP và các mảng bổ trợ.

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Substrings.cpp)
