# Next Prime - Lời giải

**ID:** 3396 | **URL:** https://cses.fi/problemset/task/3396

## Phương pháp

### Tóm tắt bài toán

Cho số nguyên dương $n$ ($1 \le n \le 10^{12}$), tìm số nguyên tố nhỏ nhất lớn hơn $n$. Có tối đa $t = 20$ truy vấn.

### Ý tưởng chính

Theo Định lý số nguyên tố, khoảng cách trung bình giữa hai số nguyên tố liên tiếp quanh $n$ là khoảng $\ln n$. Với $n \le 10^{12}$, khoảng nguyên tố (prime gap) lớn nhất đã biết nhỏ hơn 1500. Do đó, chiến lược kiểm tra tuần tự từ $n+1$ cho đến khi tìm được số nguyên tố là hiệu quả.

Để kiểm tra tính nguyên tố, dùng phép thử chia tối ưu theo quy tắc $6k \pm 1$: mọi số nguyên $> 3$ đều có dạng $6k, 6k+1, \ldots, 6k+5$. Vì $6k, 6k+2, 6k+4$ chẵn và $6k+3$ chia hết cho 3, nên ước nguyên tố $> 3$ chỉ có dạng $6k \pm 1$. Sau khi loại chia hết cho 2 và 3, chỉ cần thử các ước $i = 5, 7, 11, 13, \ldots$ (bước nhảy xen kẽ $+2, +4$) đến khi $i^2 > m$.

### Thuật toán

Với mỗi truy vấn $n$:
1. Tăng $n$ lên 1.
2. Kiểm tra $n$ có nguyên tố không: loại nếu $n < 2$, chấp nhận nếu $n \in \{2, 3\}$, loại nếu chia hết cho 2 hoặc 3, rồi thử các ước $i = 5, 7, 11, 13, \ldots$ (nhảy xen kẽ $+2, +4$) đến $i^2 > n$.
3. Nếu không nguyên tố, tăng $n$ và lặp lại.

### Ví dụ minh họa

Theo ví dụ đề bài:

| $n$ | Số nguyên tố tiếp | Giải thích |
|-----|-------------------|------------|
| 1 | 2 | 2 nguyên tố |
| 2 | 3 | 3 nguyên tố |
| 3 | 5 | 4 chẵn, 5 nguyên tố |
| 42 | 43 | 43 không chia 2, 3; $43 \bmod 5 \neq 0$, $7^2 = 49 > 43$ → nguyên tố |
| 1337 | 1361 | 1338 chẵn, 1339 $= 13 \times 103$, ..., 1361 vượt mọi kiểm tra |

## Độ phức tạp

- **Thời gian:** $O(g \cdot \sqrt{n})$ mỗi truy vấn, với $g$ là khoảng nguyên tố (thực nghiệm $g < 1500$)
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Next%20Prime.cpp)
