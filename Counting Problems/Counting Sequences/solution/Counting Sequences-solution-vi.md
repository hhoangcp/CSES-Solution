# Counting Sequences - Lời giải

**ID:** 2228 | **URL:** https://cses.fi/problemset/task/2228

## Phương pháp

### Tóm tắt bài toán

Đếm số dãy độ dài $n$ với mỗi phần tử thuộc $\{1, \ldots, k\}$ và mọi số trong $\{1, \ldots, k\}$ xuất hiện ít nhất một lần. Kết quả modulo $10^9 + 7$.

### Bao hàm - loại trừ

Nếu không có điều kiện "xuất hiện ít nhất một lần", đáp số đơn giản là $k^n$. Để đảm bảo điều kiện này, gọi $A_j$ là tập dãy mà số $j$ **không** xuất hiện. Ta cần $|\overline{A_1} \cap \cdots \cap \overline{A_k}|$.

Với tập $S \subseteq \{1, \ldots, k\}$, số dãy chỉ sử dụng giá trị trong phần bù $\bar{S}$ (kích thước $k - |S|$) là $(k - |S|)^n$. Theo nguyên lý bao hàm - loại trừ:

$$|\overline{A_1} \cap \cdots \cap \overline{A_k}| = \sum_{S \subseteq \{1,\ldots,k\}} (-1)^{|S|} (k-|S|)^n$$

Đặt $i = k - |S|$ (số giá trị được phép sử dụng) và nhận thấy có $\binom{k}{k-i} = \binom{k}{i}$ tập $S$ với $|S| = k - i$:

$$\text{ans} = \sum_{i=0}^{k} (-1)^{k-i} \binom{k}{i} i^n$$

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 6$, $k = 4$.

$$\sum_{i=0}^{4} (-1)^{4-i} \binom{4}{i} i^6 = 0 - 4 \cdot 1 + 6 \cdot 64 - 4 \cdot 729 + 1 \cdot 4096 = 0 - 4 + 384 - 2916 + 4096 = \mathbf{1560}$$

Kết quả khớp với đáp án đề bài. ✓

**Ví dụ nhỏ:** $n = 3$, $k = 2$.

$$\sum_{i=0}^{2} (-1)^{2-i} \binom{2}{i} i^3 = 0 - 2 \cdot 1 + 1 \cdot 8 = 6$$

6 dãy hợp lệ: $112, 121, 122, 211, 212, 221$.

## Độ phức tạp

- **Thời gian:** $O(n + k \log n)$ — $O(n)$ tiền xử lý giai thừa, $O(k \log n)$ tính lũy thừa nhanh trong vòng lặp tổng.
- **Bộ nhớ:** $O(n)$ — lưu mảng giai thừa và giai thừa nghịch đảo.

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Sequences.cpp)
