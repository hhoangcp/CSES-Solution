# Minimal Rotation - Lời giải

**ID:** 1110 | **URL:** https://cses.fi/problemset/task/1110

## Đề bài

Cho một chuỗi $s$ độ dài $n$ gồm các ký tự 'a'–'z'. Một phép xoay sinh ra bằng cách di chuyển lần lượt các ký tự từ đầu xuống cuối. Hãy in phép xoay có thứ tự từ điển nhỏ nhất.

## Hướng tiếp cận

### Bước 1: Rút gọn bằng cách nhân đôi chuỗi

Nối $s$ với chính nó được $t = s + s$ độ dài $2n$. Mọi phép xoay của $s$ đúng là một chuỗi con độ dài $n$ của $t$ bắt đầu tại vị trí $1, 2, \ldots, n$. Bài toán quy về: tìm chỉ số $i \in [1, n]$ sao cho $t[i..i+n-1]$ nhỏ nhất theo thứ tự từ điển.

### Bước 2: Thuật toán Booth

Duy trì $i$ là ứng viên (vị trí bắt đầu) tốt nhất hiện tại, lần lượt so sánh với các ứng viên $c > i$ và loại bỏ hàng loạt vị trí kém hơn nhờ tính chất áp đảo. Gọi $d$ là độ dài tiền tố chung đã khớp giữa $t[i..]$ và $t[c..]$; ta so sánh $t[i+d]$ với $t[c+d]$:

- $t[i+d] < t[c+d]$: $c$ lớn hơn $i$ tại offset $d$; các ứng viên $c, c+1, \ldots, c+d$ bị áp đảo, bỏ qua cả đoạn, chuyển sang ứng viên $c+d+1$ (đặt lại $d=0$).
- $t[i+d] = t[c+d]$: mở rộng tiền tố khớp, $d \gets d+1$.
- $t[i+d] > t[c+d]$: $i$ lớn hơn $c$, $i$ thua; các ứng viên $i+1, \ldots, i+d$ bị áp đảo, dịch $i$ tới $c$ và tiếp tục (lặp bước nhảy nếu $c$ vẫn nằm trong vùng bị áp đảo).

**Tính chất áp đảo (đảm bảo không bỏ sót đáp án):** Nếu $t[i..i+d-1] = t[c..c+d-1]$ và phân biệt tại offset $d$, thì với mỗi $r \in [0, d]$, ứng viên $i+r$ và $c+r$ khớp nhau $d-r$ ký tự rồi cũng phân biệt tại vị trí tương ứng offset $d$ (do $t[i+d] \ne t[c+d]$). Do đó:
- khi $t[i+d] < t[c+d]$: $c+r > i+r$ với mọi $r \in [0,d]$, nên $c, c+1, \ldots, c+d$ đều không phải phép xoay nhỏ nhất;
- khi $t[i+d] > t[c+d]$: $i+r > c+r$ với mọi $r \in [0,d]$, nên $i+1, \ldots, i+d$ đều không tối ưu, và $c$ tốt hơn $i$.

Vậy các đoạn bị bỏ qua chắc chắn không chứa đáp án; thuật toán không bỏ sót phép xoay nhỏ nhất. (Code đi kèm thực hiện tại chỗ bằng con trỏ $k = i+d$ và $j = c+d$, so sánh $S[k]$ với $S[j]$.)

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"acab"}$ ($n = 4$), $t = \text{"acabacab"}$.

Các phép xoay (chuỗi con $t[i..i+3]$ bắt đầu tại $i = 1..4$): `acab`, `caba`, `abac`, `baca`.

Quét Booth (so sánh ứng viên $i$ với ứng viên $c$, $d$ là độ dài khớp):

- $i=1$ (`acab`) với $c=2$ (`caba`): $t[1]=\text{a} < t[2]=\text{c}$ $\Rightarrow$ ứng viên 2 lớn hơn, bỏ qua.
- $i=1$ (`acab`) với $c=3$ (`abac`): khớp $t[1]=t[3]=\text{a}$ (1 ký tự), rồi $t[2]=\text{c} > t[4]=\text{b}$ $\Rightarrow$ $i$ thua, nhảy $i \to 3$ (ứng viên 2 bị áp đảo, bỏ qua).
- $i=3$ (`abac`) với $c=4$ (`baca`): $t[3]=\text{a} < t[4]=\text{b}$ $\Rightarrow$ ứng viên 4 lớn hơn, bỏ qua.

Các ứng viên tiếp theo hoặc lớn hơn, hoặc nằm ngoài phạm vi xoay $[1, n]$, nên $i=3$ là tối ưu. Đáp án: bắt đầu tại $i=3$, in $t[3..6] = \text{"abac"}$.

Kết quả:
```
abac
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ mỗi phép so sánh ký tự hoặc đẩy con trỏ quét tiến lên, và mỗi lần $i$ thua thì $i$ được nhảy tiến; tổng số phép so sánh không vượt quá $2n$ (độ dài chuỗi nhân đôi), cộng thêm $O(n)$ phép nhảy $i$.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu chuỗi nhân đôi $t$ độ dài $2n$.

## Mã nguồn (C++)

[Mã nguồn](../code/Minimal%20Rotation.cpp)
