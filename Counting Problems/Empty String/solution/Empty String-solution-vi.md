# Empty String - Lời giải

**ID:** 1080 | **URL:** https://cses.fi/problemset/task/1080

## Phương pháp

### Tóm tắt bài toán

Cho xâu $s$ độ dài $n$, đếm số cách xóa hoàn toàn xâu bằng cách liên tục xóa hai ký tự liền kề giống nhau. Kết quả modulo $10^9 + 7$.

### QHD khoảng

Định nghĩa $\text{dp}[i][j]$ = số cách xóa hoàn toàn xâu con $s[i \ldots j]$. Điều kiện cần là $(j - i + 1)$ chẵn.

**Cơ sở:** $\text{dp}[i][i-1] = 1$ (xâu con rỗng, một cách — không làm gì).

**Quan sát chính:** Ký tự đầu $s[i]$ cuối cùng phải được ghép cặp với $s[k]$ nào đó thỏa $k > i$ và $s[i] = s[k]$. Để cặp này trở nên liền kề, tất cả ký tự trong $s[i{+}1 \ldots k{-}1]$ phải được xóa trước. Sau khi xóa $s[i]$ và $s[k]$, phần còn lại $s[k{+}1 \ldots j]$ được xóa độc lập.

Ta có hai quá trình con độc lập:
1. **Xóa $s[i{+}1 \ldots k{-}1]$, rồi ghép cặp $s[i]$ và $s[k]$:** mất $(k{-}i{+}1)/2$ bước.
2. **Xóa $s[k{+}1 \ldots j]$:** mất $(j{-}k)/2$ bước.

Hai quá trình này độc lập và các bước có thể xen kẽ nhau (giữ nguyên thứ tự nội bộ mỗi quá trình). Trong tổng số $(j{-}i{+}1)/2$ bước, chọn $(k{-}i{+}1)/2$ bước thuộc quá trình 1:

$$\text{dp}[i][j] = \sum_{\substack{k=i+1 \\ k \text{ bước } 2}}^{j} [s[i] = s[k]] \cdot \text{dp}[i{+}1][k{-}1] \cdot \text{dp}[k{+}1][j] \cdot \binom{(j-i+1)/2}{(k-i+1)/2}$$

Bước nhảy 2 của $k$ đảm bảo cả hai xâu con đều có độ dài chẵn.

### Ví dụ minh họa

**Ví dụ đề bài:** $s = \texttt{aabccb}$ (chỉ số từ 1).

**Độ dài 2:**
- $\text{dp}[1][2]$: "aa" — $k{=}2$, $s[1]{=}s[2]$. $1 \cdot 1 \cdot \binom{1}{1} = \mathbf{1}$.
- $\text{dp}[4][5]$: "cc" — $k{=}5$, $s[4]{=}s[5]$. $1 \cdot 1 \cdot \binom{1}{1} = \mathbf{1}$.
- $\text{dp}[2][3]$, $\text{dp}[3][4]$, $\text{dp}[5][6]$: không có cặp khớp. $\mathbf{0}$.

**Độ dài 4:**
- $\text{dp}[3][6]$: "bccb" — $k{=}6$, $s[3]{=}b{=}s[6]$. $\text{dp}[4][5] \cdot \text{dp}[7][6] \cdot \binom{2}{2} = 1 \cdot 1 \cdot 1 = \mathbf{1}$.
- $\text{dp}[1][4]$, $\text{dp}[2][5]$: không có $k$ hợp lệ. $\mathbf{0}$.

**Độ dài 6:**
- $\text{dp}[1][6]$: "aabccb" — $k{=}2$, $s[1]{=}a{=}s[2]$. $\text{dp}[2][1] \cdot \text{dp}[3][6] \cdot \binom{3}{1} = 1 \cdot 1 \cdot 3 = \mathbf{3}$.

Kết quả: **3**. ✓

3 cách xóa: (aa→cc→bb), (cc→aa→bb), (cc→bb→aa).

## Độ phức tạp

- **Thời gian:** $O(n^3)$ — $O(n^2)$ khoảng, mỗi khoảng duyệt $O(n)$ giá trị $k$.
- **Bộ nhớ:** $O(n^2)$ — cho bảng QHD và tổ hợp tính trước.

## Mã nguồn (C++)

[Mã nguồn](../code/Empty%20String.cpp)
