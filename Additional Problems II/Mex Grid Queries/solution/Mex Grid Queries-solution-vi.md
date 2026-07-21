# Mex Grid Queries - Lời giải

**ID:** 1157 | **URL:** https://cses.fi/problemset/task/1157

## Đề bài

Xét lưới hai chiều với hàng/cột đánh số từ 1. Mỗi ô chứa số nguyên không âm nhỏ nhất không xuất hiện bên trái trên cùng hàng hoặc bên trên trên cùng cột. Tính giá trị tại ô $(y, x)$.

## Hướng tiếp cận

### Quan sát mẫu: Bảng Nim-sum

Xét các ô đầu tiên (0-indexed): $(0,0) = 0$, $(0,1) = 1$, $(1,0) = 1$, $(1,1) = 2$. Bảng kết quả:

| $y \backslash x$ | 0 | 1 | 2 | 3 | 4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **0** | 0 | 1 | 2 | 3 | 4 |
| **1** | 1 | 0 | 3 | 2 | 5 |
| **2** | 2 | 3 | 0 | 1 | 6 |
| **3** | 3 | 2 | 1 | 0 | 7 |
| **4** | 4 | 5 | 6 | 7 | 0 |

Ô $(i, j)$ có giá trị $i \oplus j$ — đây là **bảng Nim-sum**. Vì bài toán 1-indexed, chuyển về 0-indexed trước khi XOR:

$$\text{Giá trị tại } (y, x) = (y - 1) \oplus (x - 1)$$

### Tại sao XOR thỏa mãn MEX

Quy nạp mạnh trên $y + x$. Giả sử đúng cho mọi ô có $y' + x' < y + x$. Tập cấm tại $(y, x)$ (0-indexed: $(i, j)$):

- Hàng: $\{i \oplus k : 0 \le k \le j-1\}$. Cột: $\{k \oplus j : 0 \le k \le i-1\}$.

**$i \oplus j$ không bị cấm:** Nếu $i \oplus j$ thuộc hàng, cần $k = j$ (do XOR khả nghịch), nhưng $k \le j-1$. Nếu thuộc cột, cần $k = i$, nhưng $k \le i-1$.

**Mọi $v < i \oplus j$ đều bị cấm:** Xét bit cao nhất mà $v$ khác $i \oplus j$ (tại đây $v$ có 0, $i \oplus j$ có 1). Nếu bit đó thuộc phần $i$, thì $i \oplus v$ có bit đó là 0 nên $i \oplus v < i$, tức tồn tại $k = i \oplus v \le i-1$ trong cột. Nếu thuộc phần $j$, tương tự $j \oplus v < j$, tức tồn tại trong hàng. Ít nhất một hướng chứa $v$.

## Ví dụ minh họa

$y = 3, x = 5$: $(3-1) \oplus (5-1) = 2 \oplus 4$.

- $2 = 010_2$, $4 = 100_2$, $2 \oplus 4 = 110_2 = 6$.
- Kiểm tra: hàng 3 trước đó $\{2,3,0,1\}$, cột 5 trước đó $\{4,5\}$. Tập cấm $\{0,1,2,3,4,5\}$. MEX = 6. Khớp.

## Độ phức tạp

- **Thời gian:** $O(1)$ mỗi truy vấn
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Mex%20Grid%20Queries.cpp)
