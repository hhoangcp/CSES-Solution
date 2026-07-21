# Maximum Xor Subarray - Lời giải

**ID:** 1655 | **URL:** https://cses.fi/problemset/task/1655

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, tìm tổng XOR lớn nhất của một đoạn con liên tiếp.

### Ý tưởng chính

XOR của đoạn con $[l, r]$ bằng $\text{pre}[r] \oplus \text{pre}[l-1]$, với $\text{pre}[i]$ là tiền tố XOR. Vậy ta cần $\max_{0 \le j < i \le n} (\text{pre}[i] \oplus \text{pre}[j])$. Với mỗi $i$, tìm $j < i$ tối đa hóa $\text{pre}[i] \oplus \text{pre}[j]$ bằng **cây trie nhị phân** với chiến lược chọn bit tham lam.

### Thuật toán

1. **Tiền tố XOR:** Tính $\text{pre}[0] = 0$, $\text{pre}[i] = x_1 \oplus \cdots \oplus x_i$. Chèn $\text{pre}[0]$ vào trie.
2. **Xử lý từng vị trí:** Với $i = 1$ đến $n$:
   - Truy vấn trie tìm giá trị đã lưu tối đa hóa $\text{pre}[i] \oplus v$. Tại mỗi mức bit $i$ (từ 30 xuống 0), ưu tiên nhánh có bit đối lập với bit tương ứng của $\text{pre}[i]$ (để bit kết quả bằng 1). Nếu nhánh ưu tiên không tồn tại, đi nhánh còn lại. Lựa chọn tham lam này tối ưu vì $2^i > 2^0 + 2^1 + \cdots + 2^{i-1}$ — việc mất bit $i$ không thể được bù đắp bởi bất kỳ tổ hợp bit thấp hơn nào.
   - Cập nhật đáp án với kết quả truy vấn.
   - Chèn $\text{pre}[i]$ vào trie.

### Ví dụ minh họa

Đầu vào: $n = 4$, mảng $[5, 1, 5, 9]$.

Tiền tố XOR: $\text{pre}[0]{=}0, \text{pre}[1]{=}5, \text{pre}[2]{=}4, \text{pre}[3]{=}1, \text{pre}[4]{=}8$.

| $i$ | $\text{pre}[i]$ | Trie chứa | XOR lớn nhất | Giá trị |
|---|---|---|---|---|
| 1 | 5 | $\{0\}$ | $5 \oplus 0$ | 5 |
| 2 | 4 | $\{0, 5\}$ | $4 \oplus 0$ | 4 |
| 3 | 1 | $\{0, 5, 4\}$ | $1 \oplus 4$ | 5 |
| 4 | 8 | $\{0, 5, 4, 1\}$ | $8 \oplus 5$ | **13** |

Kết quả: **13**.

## Độ phức tạp

- **Thời gian:** $O(n \cdot 31)$ — mỗi phần tử chèn và truy vấn trong $O(31)$
- **Không gian:** $O(n \cdot 31)$ — tối đa $n$ giá trị tiền tố, mỗi giá trị cần 31 nút trie

## Mã nguồn (C++)

[Mã nguồn](../code/Maximum%20Xor%20Subarray.cpp)
