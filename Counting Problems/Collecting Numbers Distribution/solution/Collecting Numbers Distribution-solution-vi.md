# Collecting Numbers Distribution - Lời giải

**ID:** 3157 | **URL:** https://cses.fi/problemset/task/3157

## Phương pháp

### Tóm tắt bài toán

Với mỗi $k = 1, 2, \ldots, n$, đếm số hoán vị của $\{1, \ldots, n\}$ cần đúng $k$ vòng để thu thập tất cả các số theo thứ tự tăng dần (mỗi vòng quét trái sang phải, thu thập các số liên tiếp). Kết quả modulo $10^9 + 7$.

### Số vòng và bước giảm

Gọi $\text{pos}[x]$ là vị trí của giá trị $x$ trong hoán vị. Vòng mới bắt buộc tại giá trị $x+1$ khi $\text{pos}[x+1] < \text{pos}[x]$ — số tiếp theo nằm bên trái nên đã đi qua. Gọi đây là một **bước giảm** (của hàm vị trí). Tổng số vòng bằng:

$$\text{vòng} = 1 + (\text{số } x \in \{1, \ldots, n-1\} \text{ mà } \text{pos}[x+1] < \text{pos}[x])$$

Tương đương, đây là 1 cộng số bước giảm của hoán vị ngược $p^{-1}$. Vì ánh xạ $p \mapsto p^{-1}$ là song ánh trên $S_n$, số hoán vị có $j$ bước giảm trong hoán vị ngược bằng số hoán vị có $j$ bước giảm trong $p$ — cả hai đều được đếm bởi **số Euler** $A(n, j)$.

Vậy đáp án cho $k$ vòng là $A(n, k-1)$.

### Số Euler và công thức truy hồi

$A(n, j)$ đếm hoán vị của $\{1, \ldots, n\}$ có đúng $j$ bước giảm. Nó thỏa mãn:

$$A(n, j) = (j+1) \cdot A(n-1, j) + (n-j) \cdot A(n-1, j-1)$$

**Chứng minh bằng chèn phần tử $n$:** Lấy hoán vị của $\{1, \ldots, n-1\}$ và chèn $n$ vào một vị trí. Vì $n$ là phần tử lớn nhất, chèn $n$ vào vị trí nội luôn tạo thêm một bước tăng (bên trái $< n$) và một bước giảm ($n >$ bên phải), trong khi thay thế quan hệ ban đầu tại khoảng đó.

- **Giữ nguyên $j$ bước giảm** (từ hoán vị có $j$ bước giảm): Chèn $n$ ngay sau một bước giảm hiện có, hoặc ở cuối. Chèn sau bước giảm thay thế cặp $a > b$ bằng $a < n > b$ (một bước tăng + một bước giảm, ròng 0 thay đổi). Chèn ở cuối chỉ thêm bước tăng. Tổng: $j + 1$ vị trí.

- **Thêm một bước giảm** (từ hoán vị có $j-1$ bước giảm): Chèn $n$ sau một bước tăng, hoặc ở đầu. Chèn sau bước tăng thay thế cặp $a < b$ bằng $a < n > b$ (ròng +1 bước giảm). Chèn ở đầu chỉ thêm bước giảm. Tổng: $(n-1-(j-1)) + 1 = n - j$ vị trí.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 3$.

| $k$ | Bước giảm | Hoán vị | $A(3, k-1)$ |
|-----|-----------|---------|-------------|
| 1 | 0 | $[1,2,3]$ | $A(3,0) = 1$ |
| 2 | 1 | $[1,3,2],\ [2,1,3],\ [2,3,1],\ [3,1,2]$ | $A(3,1) = 4$ |
| 3 | 2 | $[3,2,1]$ | $A(3,2) = 1$ |

**Kiểm tra truy hồi** cho $A(3,1)$: $(1+1) \cdot A(2,1) + (3-1) \cdot A(2,0) = 2 \cdot 1 + 2 \cdot 1 = 4$. ✓

Tổng: $1 + 4 + 1 = 6 = 3!$. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — xây bảng QHD $n \times n$.
- **Bộ nhớ:** $O(n^2)$ — cho bảng QHD (có thể tối ưu xuống $O(n)$ bằng hai hàng).

## Mã nguồn (C++)

[Mã nguồn](../code/Collecting%20Numbers%20Distribution.cpp)
