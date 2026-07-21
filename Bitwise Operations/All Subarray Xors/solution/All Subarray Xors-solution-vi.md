# All Subarray Xors - Lời giải

**ID:** 3233 | **URL:** https://cses.fi/problemset/task/3233

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, tìm tất cả giá trị phân biệt là XOR của một đoạn con nào đó, in theo thứ tự tăng dần.

### Ý tưởng chính

XOR của đoạn con $[l, r]$ bằng $\text{pre}[r] \oplus \text{pre}[l-1]$, với $\text{pre}[i]$ là tiền tố XOR. Vậy bài toán quy về tìm tất cả giá trị $\text{pre}[i] \oplus \text{pre}[j]$ với $j < i$. Đây là phép chập XOR của mảng tần suất tiền tố với chính nó, tính được trong $O(MAX \cdot H)$ nhờ Fast Walsh-Hadamard Transform (FWHT).

### Thuật toán

1. **Tiền tố XOR:** Tính $\text{pre}[0] = 0$, $\text{pre}[i] = x_1 \oplus \cdots \oplus x_i$. Xây mảng tần suất $f[v]$ = số tiền tố bằng $v$.
2. **Phép chập XOR bằng FWHT:**
   - Áp dụng FWHT thuận: biến đổi $f$ thành $\hat{f}$.
   - Bình phương từng phần tử: $\hat{f}[i] = \hat{f}[i]^2$.
   - Áp dụng FWHT ngược: thu được $\text{numX}[v] = \sum_{a \oplus b = v} f[a] \cdot f[b]$.

   Phép biến đổi thuận tại mỗi bước với độ dài $len$: $\hat{f}[i] = f[i] + f[i + len]$, $\hat{f}[i + len] = f[i] - f[i + len]$. Phép ngược tương tự, sau đó chia $2^H$. Biến đổi Walsh-Hadamard chéo hóa phép chập XOR: $\widehat{f * g}[i] = \hat{f}[i] \cdot \hat{g}[i]$, nên bình phương trong miền biến đổi chính là chập XOR với chính nó.

3. **Hiệu chỉnh kết quả:** $\text{numX}[v]$ đếm cặp có thứ tự $(i, j)$ bao gồm cặp tự ghép. Hiệu chỉnh:
   - Trừ $n + 1$ khỏi $\text{numX}[0]$ để loại cặp tự ghép ($\text{pre}[i] \oplus \text{pre}[i] = 0$).
   - Chia mọi $\text{numX}[v]$ cho 2 để đổi cặp có thứ tự thành cặp không thứ tự ($j < i$).
   - Mọi $v > 0$ có $\text{numX}[v] > 0$ là XOR đoạn con hợp lệ.

### Ví dụ minh họa

Đầu vào: $n = 4$, mảng $[5, 1, 5, 9]$.

Tiền tố XOR: $[0, 5, 4, 1, 8]$. Tần suất: $f[0]{=}f[1]{=}f[4]{=}f[5]{=}f[8]{=}1$.

Các cặp ($j < i$) và XOR tương ứng:
- $(0,1)$: $5 \oplus 0 = 5$
- $(0,2)$: $4 \oplus 0 = 4$
- $(0,3)$: $1 \oplus 0 = 1$
- $(0,4)$: $8 \oplus 0 = 8$
- $(1,2)$: $4 \oplus 5 = 1$
- $(1,3)$: $1 \oplus 5 = 4$
- $(1,4)$: $8 \oplus 5 = 13$
- $(2,3)$: $1 \oplus 4 = 5$
- $(2,4)$: $8 \oplus 4 = 12$
- $(3,4)$: $8 \oplus 1 = 9$

Các giá trị phân biệt khác 0: $\{1, 4, 5, 8, 9, 12, 13\}$ → **7 giá trị**.

## Độ phức tạp

- **Thời gian:** $O(n + 2^{20} \cdot 20)$ — FWHT chiếm ưu thế
- **Không gian:** $O(2^{20})$

## Mã nguồn (C++)

[Mã nguồn](../code/All%20Subarray%20Xors.cpp)
