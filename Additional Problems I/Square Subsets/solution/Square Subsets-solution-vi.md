# Square Subsets - Lời giải

**ID:** 3193 | **URL:** https://cses.fi/problemset/task/3193

## Đề bài

Đếm số tập con của mảng mà tích các phần tử là số chính phương (bao gồm tập rỗng có tích 1). Kết quả modulo $10^9 + 7$.

## Hướng tiếp cận

### Bitmask parity

Một số là chính phương khi và chỉ khi mọi số nguyên tố trong phân tích có mũ chẵn. Với mỗi $x_i$, định nghĩa **mask parity**: bit $j = 1$ nếu số nguyên tố $p_j$ xuất hiện số lần lẻ trong $x_i$.

Tích của tập con là chính phương khi và chỉ khi XOR tất cả mask bằng 0 (vì XOR trên bit $j$ tương đương cộng modulo 2 số mũ của $p_j$; XOR = 0 tức mọi mũ chẵn).

### Cơ sở tuyến tính

Quy về: cho $n$ bitmask trong $\mathbb{F}_2^P$ ($P$ là số nguyên tố $\le 5000$), đếm tập con có XOR bằng 0.

Xây cơ sở tuyến tính bằng khử Gauss: với mỗi mask, duyệt các bit 1 từ cao xuống thấp; nếu cơ sở chưa có phần tử ở bit đó thì chèn mask vào; ngược lại XOR với phần tử cơ sở tương ứng và tiếp tục.

**Vì sao $2^{n-r}$:** Ánh xạ tuyến tính $f: \mathbb{F}_2^n \to \mathbb{F}_2^P$ từ tập con (vector đặc trưng) sang XOR các mask có hạt nhân kích thước $2^{n-r}$ với $r = \dim(\text{im}(f))$ là kích thước cơ sở. Theo định lý đẳng cấu thứ nhất, $|\ker(f)| = 2^n / 2^r = 2^{n-r}$.

Hiểu trực quan: $n - r$ phần tử phụ thuộc có thể tự do chọn hay không; với mỗi cách chọn, có đúng 1 cách chọn thêm các phần tử cơ sở để XOR tổng bằng 0.

### Ví dụ mô phỏng

$a = [2, 2, 3, 6]$, số nguyên tố: $\{2, 3\}$.

| Phần tử | Phân tích | Mask $(p_2, p_3)$ |
|---------|-----------|-------------------|
| 2₁ | $2^1$ | $(1, 0)$ |
| 2₂ | $2^1$ | $(1, 0)$ |
| 3 | $3^1$ | $(0, 1)$ |
| 6 | $2^1 \cdot 3^1$ | $(1, 1)$ |

Cơ sở: $\{(1,0), (0,1)\}$, $r = 2$. Đáp án: $2^{4-2} = 4$.

| Tập con | XOR mask | Tích | Chính phương? |
|---------|----------|------|--------------|
| $\emptyset$ | $(0,0)$ | 1 | ✓ |
| $\{2_1, 2_2\}$ | $(1,0) \oplus (1,0) = (0,0)$ | 4 | ✓ |
| $\{2_1, 3, 6\}$ | $(1,0) \oplus (0,1) \oplus (1,1) = (0,0)$ | 36 | ✓ |
| $\{2_2, 3, 6\}$ | $(1,0) \oplus (0,1) \oplus (1,1) = (0,0)$ | 36 | ✓ |

## Độ phức tạp

- **Thời gian:** $O(n \cdot P / w)$ với $P = 669$ (số nguyên tố $\le 5000$), $w = 64$ (kích thước word của bitset)
- **Bộ nhớ:** $O(P^2 / w)$ để lưu ma trận cơ sở

## Mã nguồn (C++)

[Mã nguồn](../code/Square%20Substrings.cpp)
