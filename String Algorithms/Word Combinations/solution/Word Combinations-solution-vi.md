# Word Combinations - Lời giải

**ID:** 1731 | **URL:** https://cses.fi/problemset/task/1731

## Đề bài

Cho chuỗi $s$ độ dài $n$ và từ điển $k$ từ. Đếm số cách tạo ra chuỗi $s$ bằng cách nối các từ trong từ điển (mỗi từ dùng được nhiều lần), lấy modulo $10^9+7$.

## Hướng tiếp cận

### Bước 1: Cây Trie

Dùng cây Trie lưu từ điển: mỗi nút có 26 nhánh (theo ký tự 'a'–'z') và một cờ đánh dấu kết thúc từ. Chèn tất cả $k$ từ vào Trie; chi phí $O(\sum |w_i|)$.

### Bước 2: Quy hoạch động từ phải sang trái

Gọi $dp[i]$ = số cách tạo hậu tố $s[i..n{-}1]$ (đánh số từ 0) bằng các từ trong từ điển. Cơ sở $dp[n] = 1$ (hậu tố rỗng có đúng 1 cách: không dùng từ nào).

Duyệt $i$ từ $n{-}1$ về $0$. Tại mỗi $i$, đi trên Trie từ gốc theo các ký tự $s[i], s[i{+}1], \ldots$:

- Nếu nút hiện tại không có nhánh $s[j]$, dừng (không còn từ nào khớp tiếp).
- Nếu có nhánh, đi xuống; nếu nút mới đánh dấu kết thúc từ thì $s[i..j]$ là một từ trong từ điển, cộng:
$$dp[i] = \bigl(dp[i] + dp[j+1]\bigr) \bmod (10^9+7)$$

Tóm gọn: $dp[i] = \sum_{j: s[i..j] \in \text{từ điển}} dp[j+1]$. Đáp án là $dp[0]$.

**Tính đúng (quy nạp):** $dp[n]=1$ đúng. Giả sử $dp[j+1]$ đúng với mọi $j > i$. Mỗi cách tạo $s[i..n{-}1]$ phải bắt đầu bằng một từ $s[i..j]$ thuộc từ điển rồi ghép $s[j{+}1..n{-}1]$ bằng $dp[j+1]$ cách; tổng theo mọi từ khớp tại $i$ cho đúng $dp[i]$. Không trùng lặp vì các cách khác nhau có từ đầu khác nhau (hoặc cùng từ nhưng phần còn lại khác) nên nằm ở các số hạng khác nhau.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"ababc"}$ ($n = 5$), từ điển $\{$`ab`, `abab`, `c`, `cb`$\}$.

Trie (cờ `(hết …)` đánh dấu kết thúc từ):

```
gốc
├ a → b (hết "ab") → a → b (hết "abab")
└ c (hết "c") → b (hết "cb")
```

Bảng $dp$ (duyệt phải sang trái):

| $i$ | $s[i..]$ | từ khớp (→ $dp[j{+}1]$) | $dp[i]$ |
|---|---|---|---|
| 5 | (rỗng) | — (cơ sở) | 1 |
| 4 | `c` | `c` → $dp[5]=1$ | 1 |
| 3 | `bc` | không có (không từ bắt đầu bằng `b`) | 0 |
| 2 | `abc` | `ab` → $dp[4]=1$ | 1 |
| 1 | `babc` | không có | 0 |
| 0 | `ababc` | `ab` → $dp[2]=1$; `abab` → $dp[4]=1$ | 2 |

Đáp án $dp[0] = 2$, ứng với 2 cách: `ab + ab + c` và `abab + c`.

Kết quả:
```
2
```

## Độ phức tạp

- **Thời gian:** $O(n^2 + \sum |w_i|)$ $\textemdash$ xây Trie mất $O(\sum |w_i|)$; QHĐ có hai vòng lồng, trong trường hợp xấu nhất $O(n^2)$. Trie cắt tỉa sớm các nhánh không khớp nên thực tế nhanh hơn nhiều so với duyệt từng từ.
- **Bộ nhớ:** $O(n + \sum |w_i|)$ $\textemdash$ mảng $dp$ kích thước $n$ và các nút của Trie.

## Mã nguồn (C++)

[Mã nguồn](../code/Word%20Combinations.cpp)
