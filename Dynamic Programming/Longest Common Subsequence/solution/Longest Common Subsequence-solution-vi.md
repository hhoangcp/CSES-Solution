# Longest Common Subsequence - Lời giải

**ID:** 3403 | **URL:** https://cses.fi/problemset/task/3403

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho hai mảng số nguyên $a_1, \ldots, a_n$ và $b_1, \ldots, b_m$, tìm dãy con chung dài nhất (LCS). In ra độ dài và một dãy con cụ thể.

### Ý tưởng cốt lõi

Gọi $dp[i][j]$ là độ dài LCS của tiền tố $a[1..i]$ và $b[1..j]$. Xét phần tử cuối của mỗi tiền tố:

- **Nếu $a[i] = b[j]$:** Ta có thể ghép chúng làm phần tử chung cuối cùng, phần còn lại giải trên tiền tố ngắn hơn: $dp[i][j] = dp[i-1][j-1] + 1$.
- **Nếu $a[i] \neq b[j]$:** Ít nhất một trong $a[i]$, $b[j]$ không thuộc LCS. Bỏ qua phần tử cho kết quả tốt hơn: $dp[i][j] = \max(dp[i-1][j],\ dp[i][j-1])$.

Trường hợp cơ sở: $dp[0][j] = dp[i][0] = 0$.

**Tính đúng:** Quy nạp theo $i + j$. Nếu $a[i] = b[j]$, mọi LCS hoặc chứa cặp này (được $dp[i-1][j-1] + 1$) hoặc không (nhưng khi đó ta có thể thêm cặp này vào để được dãy dài hơn — mâu thuẫn). Nếu $a[i] \neq b[j]$, mọi LCS loại bỏ ít nhất một trong hai phần tử, nên độ dài không vượt quá $\max(dp[i-1][j], dp[i][j-1])$; ngược lại, giá trị max này đạt được vì nó là dãy con chung của $a[1..i]$ và $b[1..j]$.

**Truy vết:** Ghi lại chuyển trạng thái vào mảng $trace[i][j]$ trong quá trình QHD. Bắt đầu từ $(n, m)$: nếu $a[i] = b[j]$, đưa $a[i]$ vào kết quả và chuyển đến $(i-1, j-1)$; ngược lại, chuyển về phía có $dp$ lớn hơn. Đảo ngược dãy thu được.

### Ví dụ

Đầu vào: $a = [3, 1, 3, 2, 7, 4, 8, 2]$, $b = [6, 5, 1, 2, 3, 4]$.

Bảng $dp$:

| | $\epsilon$ | 6 | 5 | 1 | 2 | 3 | 4 |
|--|-----------|---|---|---|---|---|---|
| $\epsilon$ | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 3 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
| 1 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| 3 | 0 | 0 | 0 | 1 | 1 | 2 | 2 |
| 2 | 0 | 0 | 0 | 1 | 2 | 2 | 2 |
| 7 | 0 | 0 | 0 | 1 | 2 | 2 | 2 |
| 4 | 0 | 0 | 0 | 1 | 2 | 2 | 3 |
| 8 | 0 | 0 | 0 | 1 | 2 | 2 | 3 |
| 2 | 0 | 0 | 0 | 1 | 2 | 2 | 3 |

Độ dài LCS = 3. Truy vết: $(8,6) \to \uparrow \to (7,6) \to \uparrow \to (6,6)$, $a[6]{=}b[6]{=}4$ → lấy 4; $(5,5) \to \leftarrow \to (5,4) \to \uparrow \to (4,4)$, $a[4]{=}b[4]{=}2$ → lấy 2; $(3,3) \to \uparrow \to (2,3)$, $a[2]{=}b[3]{=}1$ → lấy 1. Kết quả: $[1, 2, 4]$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$ — $n \cdot m$ trạng thái, mỗi trạng thái $O(1)$
- **Bộ nhớ:** $O(n \cdot m)$ — cho mảng $dp$ và $trace$

## Mã nguồn (C++)

[Mã nguồn](../code/Longest%20Common%20Subsequence.cpp)
