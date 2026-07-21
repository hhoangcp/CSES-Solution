# Special Substrings - Lời giải

**ID:** 2186 | **URL:** https://cses.fi/problemset/task/2186

## Đề bài

Một xâu con được gọi là *đặc biệt* nếu mọi ký tự xuất hiện trong xâu đều xuất hiện cùng số lần. Đếm tất cả xâu con đặc biệt.

## Hướng tiếp cận

### Vector hiệu

Gọi $cnt[i][c]$ là số lần ký tự $c$ xuất hiện trong tiền tố $s[1 \ldots i]$. Xâu con $s[l \ldots r]$ đặc biệt khi và chỉ khi $cnt[r][c] - cnt[l-1][c]$ bằng nhau cho mọi $c$. Điều này tương đương: vector hiệu liên tiếp tại vị trí $r$ bằng vector hiệu tại vị trí $l-1$.

Định nghĩa vector hiệu tại vị trí $i$ với $k$ ký tự phân biệt (đánh số $0, 1, \ldots, k-1$):

$$cur[j] = cnt[i][j+1] - cnt[i][j], \quad j = 0, 1, \ldots, k-2$$

Nếu hai vị trí có cùng vector $cur$, thì mọi giá trị $cnt$ chênh lệch cùng một hằng số giữa hai vị trí đó, tức mọi ký tự trong xâu con xuất hiện bằng nhau. Vậy chỉ cần đếm số cặp vị trí có cùng vector.

### Thuật toán

1. Quét trước xâu để xác định tất cả ký tự phân biệt và gán chỉ số.
2. Khởi tạo `map<vector<int>, int>` với vector tiền tố rỗng.
3. Tại mỗi vị trí $i$: cập nhật $cnt$, tính lại $cur$, cộng `map[cur]` vào đáp án, rồi tăng `map[cur]`.

### Ví dụ minh họa

$s = \text{abccabab}$, ký tự phân biệt: a(0), b(1), c(2). Vector có 2 phần tử: $[cnt[1]-cnt[0], cnt[2]-cnt[1]]$.

| Vị trí | Ký tự | $cnt$ | $cur$ | map count | Xâu con |
|--------|-------|-------|-------|-----------|---------|
| 0 | - | [0,0,0] | [0,0] | - | - |
| 1 | a | [1,0,0] | [-1,0] | 0 | - |
| 2 | b | [1,1,0] | [0,-1] | 0 | - |
| 3 | c | [1,1,1] | [0,0] | 1 | `abc` |
| 4 | c | [1,1,2] | [0,1] | 0 | - |
| 5 | a | [2,1,2] | [-1,1] | 0 | - |
| 6 | b | [2,2,2] | [0,0] | 2 | `abccab`, `cab` |
| 7 | a | [3,2,2] | [-1,0] | 1 | `bccaba` |
| 8 | b | [3,3,2] | [0,-1] | 1 | `ccabab` |

Tổng: $1 + 2 + 1 + 1 = \mathbf{5}$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot |\Sigma| \log n)$ — mỗi thao tác map mất $O(|\Sigma| \log n)$ (so sánh vector $O(|\Sigma|)$, map $O(\log n)$)
- **Bộ nhớ:** $O(n \cdot |\Sigma|)$

## Mã nguồn (C++)

[Mã nguồn](../code/Special%20Substrings.cpp)
