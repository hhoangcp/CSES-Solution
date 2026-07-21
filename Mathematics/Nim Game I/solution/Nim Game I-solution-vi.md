# Nim Game I - Lời giải

**ID:** 1730 | **URL:** https://cses.fi/problemset/task/1730

## Phương pháp

### Tóm tắt bài toán

Có $n$ đống que, hai người chơi luân phiên đi. Mỗi lượt, người chơi chọn một đống không rỗng và lấy bất kỳ số que dương. Người lấy que cuối cùng thắng. Xác định người thắng khi cả hai chơi tối ưu.

### Ý tưởng chính

**Định lý Bouton (1901):** Người đi trước thắng khi và chỉ khi $S = x_1 \oplus x_2 \oplus \cdots \oplus x_n \neq 0$.

**Chứng minh.** Ta xác minh ba tính chất:

1. **Trạng thái kết thúc:** Mọi đống rỗng → $S = 0$. Đây là vị thế thua (không còn nước đi).

2. **Từ $S = 0$, mọi nước đi dẫn đến $S' \neq 0$:** Giảm $x_i$ xuống $x_i'$ cho $S' = 0 \oplus x_i \oplus x_i' = x_i \oplus x_i'$. Vì $x_i' < x_i$, hai số khác nhau luôn có XOR khác 0.

3. **Từ $S \neq 0$, luôn tồn tại nước đi đến $S' = 0$:** Gọi $d$ là bit cao nhất bằng 1 của $S$. Tồn tại đống $x_i$ có bit $d$ bằng 1 (số đống có bit $d$ bằng 1 là lẻ). Đặt $x_i' = x_i \oplus S$. Vì bit $d$ bằng 1 trong cả $x_i$ và $S$, nó bị triệt tiêu trong $x_i'$, nên $x_i' < x_i$. Khi đó $S' = S \oplus x_i \oplus (x_i \oplus S) = 0$.

Ba tính chất trên xác lập $S = 0$ là tập vị thế thua: từ $S = 0$ chỉ đến được $S \neq 0$, và từ $S \neq 0$ luôn đến được $S = 0$. Vì trò chơi hữu hạn, người đi trước thắng khi và chỉ khi $S \neq 0$.

### Thuật toán

Với mỗi test case, tính XOR tất cả kích thước đống. Nếu khác 0, xuất "first"; ngược lại xuất "second".

### Ví dụ minh họa

| Đống que | XOR | Người thắng |
|----------|-----|-------------|
| $\{5, 7, 2, 5\}$ | $5 \oplus 7 \oplus 2 \oplus 5 = 7 \neq 0$ | first |
| $\{4, 1\}$ | $4 \oplus 1 = 5 \neq 0$ | first |
| $\{3, 5, 6\}$ | $3 \oplus 5 \oplus 6 = 0$ | second |

## Độ phức tạp

- **Thời gian:** $O(n)$ mỗi test case
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Nim%20Game%20I.cpp)
