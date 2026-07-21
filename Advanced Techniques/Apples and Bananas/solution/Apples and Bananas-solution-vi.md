# Apples and Bananas - Lời giải

**ID:** 2111 | **URL:** https://cses.fi/problemset/task/2111

## Phương pháp

### Tóm tắt bài toán

Cho $n$ quả táo và $m$ quả chuối, mỗi quả có trọng lượng nguyên trong $[1, k]$. Với mỗi trọng lượng tổng $w \in [2, 2k]$, đếm số cách chọn một quả táo và một quả chuối sao cho tổng trọng lượng bằng $w$. Hai quả cùng loại và cùng trọng lượng được xem là khác nhau.

### Ý tưởng chính

Gọi $A[i]$ là số quả táo trọng lượng $i$, $B[j]$ là số quả chuối trọng lượng $j$. Đáp án cho trọng lượng $w$ là:

$$\text{ans}[w] = \sum_{\substack{i+j=w \\ 1 \le i,j \le k}} A[i] \cdot B[j]$$

Đây chính là **tích chập rời rạc** của hai dãy $A$ và $B$, tương ứng với nhân đa thức. Nếu xây $P(x) = \sum_{i} A[i] x^i$ và $Q(x) = \sum_{j} B[j] x^j$, thì hệ số $x^w$ trong $P \cdot Q$ bằng $\sum_{i+j=w} A[i] B[j]$.

Tích chập thông thường mất $O(k^2)$, quá chậm. **FFT** tính nhân đa thức trong $O(n \log n)$ với $n$ là lũy thừa 2 nhỏ nhất $\ge 2k+1$. Tính đúng đắn dựa trên **định lý tích chập**: nếu $R(x) = P(x) \cdot Q(x)$, thì với mỗi căn bậc đơn vị $\omega^k$: $R(\omega^k) = P(\omega^k) \cdot Q(\omega^k)$. Vậy biểu diễn điểm-giá trị của $R$ thu được bằng nhân từng phần tử. FFT ngược khôi phục hệ số từ điểm-giá trị. Vì $A[i]=0$ với $i>k$, $B[j]=0$ với $j>k$, chỉ số hệ số khác 0 tối đa là $2k$, nên chọn $h \ge 2k+1$ tránh aliasing.

### Thuật toán

1. Xây mảng $A$ và $B$ kích thước $h$ (lũy thừa 2 nhỏ nhất $\ge 2k+1$), với $A[i]$ đếm táo trọng lượng $i$, $B[j]$ đếm chuối trọng lượng $j$.
2. Áp dụng FFT thuận cho $A$ và $B$, chuyển từ biểu diễn hệ số sang biểu diễn điểm-giá trị.
3. Nhân từng phần tử hai biểu diễn điểm-giá trị: $C[i] = A[i] \cdot B[i]$.
4. Áp dụng FFT ngược cho $C$ để thu kết quả dạng hệ số.
5. Với $w$ từ 2 đến $2k$, xuất $\text{round}(C[w].a)$.

### Ví dụ minh họa

$k=5$, táo: $[5, 2, 5]$, chuối: $[4, 3, 2, 3]$.

Mảng tần suất (chỉ số 0–5):

| $i$ | 0 | 1 | 2 | 3 | 4 | 5 |
|-----|---|---|---|---|---|---|
| $A[i]$ | 0 | 0 | 1 | 0 | 0 | 2 |
| $B[i]$ | 0 | 0 | 1 | 2 | 1 | 0 |

Kết quả tích chập ($w$ từ 2 đến $2k{=}10$):

- $w=4$: $A[2] \cdot B[2] = 1 \cdot 1 = 1$
- $w=5$: $A[2] \cdot B[3] = 1 \cdot 2 = 2$
- $w=6$: $A[2] \cdot B[4] = 1 \cdot 1 = 1$
- $w=7$: $A[5] \cdot B[2] = 2 \cdot 1 = 2$
- $w=8$: $A[5] \cdot B[3] = 2 \cdot 2 = 4$
- $w=9$: $A[5] \cdot B[4] = 2 \cdot 1 = 2$

(Các $w$ còn lại đều bằng 0.)

Kết quả: `0 0 1 2 1 2 4 2 0`

## Độ phức tạp

- **Thời gian:** $O(k \log k)$
- **Không gian:** $O(k)$

## Mã nguồn (C++)

[Mã nguồn](../code/Apples%20and%20Bananas.cpp)
