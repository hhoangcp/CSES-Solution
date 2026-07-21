# Permutation Rounds - Lời giải

**ID:** 3398 | **URL:** https://cses.fi/problemset/task/3398

## Phương pháp

### Tóm tắt bài toán

Cho mảng ban đầu $[1, 2, \ldots, n]$ và hoán vị $p_1, p_2, \ldots, p_n$. Mỗi vòng, phần tử ở vị trí $i$ di chuyển đến vị trí $p_i$. Tìm số vòng nhỏ nhất để mảng trở về trạng thái ban đầu, modulo $10^9+7$.

### Ý tưởng chính

Bất kỳ hoán vị nào cũng phân rã duy nhất thành các **chu trình rời rạc**. Phần tử thuộc chu trình độ dài $L$ trở về vị trí ban đầu sau đúng bội số của $L$ vòng. Để toàn bộ mảng khôi phục trạng thái gốc, mọi phần tử phải đồng thời trở về, nên số vòng phải là bội chung của tất cả độ dài chu trình. Giá trị nhỏ nhất là:

$$\text{Kết quả} = \text{lcm}(L_1, L_2, \ldots, L_t)$$

**Chứng minh:** Tính cần — sau $k$ vòng, phần tử thuộc chu trình $L_i$ trở về iff $L_i \mid k$. Để mọi phần tử trở về, $k$ phải là bội chung. Tối thiểu là LCM. Tính đủ — LCM chia hết mọi $L_i$, nên mọi phần tử trở về sau LCM vòng.

Vì kết quả có thể rất lớn, tính LCM modulo $10^9+7$ thông qua **phân tích thừa số nguyên tố**. Với mỗi độ dài chu trình $L_i$, phân tích ra thừa số và theo dõi số mũ tối đa cho từng số nguyên tố:

$$\text{LCM} = \prod_p p^{\max_i(e_p(L_i))} \pmod{10^9+7}$$

Cách này tránh được phép chia modulo (vốn không khả thi khi LCM vượt quá $10^9+7$ trước khi lấy dư).

### Thuật toán

1. Dùng sàng tuyến tính để tìm ước nguyên tố nhỏ nhất của mỗi số đến $n$.
2. Duyệt hoán vị tìm tất cả độ dài chu trình.
3. Với mỗi độ dài chu trình, phân tích thừa số bằng sàng và cập nhật số mũ tối đa cho từng số nguyên tố.
4. Tính kết quả $\prod_p p^{\max\_e[p]} \pmod{10^9+7}$.

### Ví dụ minh họa

$p = [5, 3, 2, 6, 4, 1, 8, 7]$, $n = 8$.

Chu trình: $1 \to 5 \to 4 \to 6 \to 1$ (độ dài 4), $2 \to 3 \to 2$ (độ dài 2), $7 \to 8 \to 7$ (độ dài 2).

Phân tích: $4 = 2^2$, $2 = 2^1$, $2 = 2^1$. Số mũ tối đa của 2 là 2.

$\text{LCM} = 2^2 = 4$ $\checkmark$.

Sau 4 vòng, mảng trở về $[1, 2, 3, 4, 5, 6, 7, 8]$.

## Độ phức tạp

- **Thời gian:** $O(n)$ tìm chu trình + $O(n \log \log n)$ sàng nguyên tố + $O(\sum \log L_i)$ phân tích thừa số
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Permutation%20Rounds.cpp)
