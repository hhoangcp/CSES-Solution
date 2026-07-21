# Stack Weights - Lời giải

**ID:** 2425 | **URL:** https://cses.fi/problemset/task/2425

## Đề bài

Có $n$ đồng xu trọng lượng tăng ngặt ($w_1 < w_2 < \cdots < w_n$). Hai ngăn xếp ban đầu rỗng. Sau mỗi lượt đặt đồng xu vào ngăn xếp, xác định ngăn xếp nào chắc chắn nặng hơn hay không xác định được.

## Hướng tiếp cận

### Biến đổi Abel và tổng hậu tố

Gán $val_i = +1$ nếu đồng xu $i$ vào ngăn xếp 1, $val_i = -1$ nếu vào ngăn xếp 2. Chênh lệch trọng lượng:

$$D = \sum_{i=1}^{n} val_i \cdot w_i$$

Đặt $suffix_k = \sum_{i=k}^{n} val_i$. Áp dụng phép tổng Abel:

$$D = \sum_{k=1}^{n} suffix_k \cdot (w_k - w_{k-1})$$

với $w_0 = 0$. Vì $w_k - w_{k-1} > 0$ với mọi $k$, mỗi hạng tử là tích của $suffix_k$ với một hệ số dương.

**Kết luận:**
- Ngăn xếp 1 chắc chắn nặng hơn ($D > 0$) $\iff$ mọi $suffix_k \geq 0$ (và ít nhất một $> 0$).
- Ngăn xếp 2 chắc chắn nặng hơn ($D < 0$) $\iff$ mọi $suffix_k \leq 0$ (và ít nhất một $< 0$).
- Còn lại: `?`.

**Chứng minh điều kiện cần:** Nếu $suffix_{k_0} < 0$ với $k_0$ nào đó, chọn $w_{k_0} \gg$ các trọng lượng khác. Hạng tử $suffix_{k_0} \cdot (w_{k_0} - w_{k_0-1})$ áp đảo, làm $D < 0$, nên ngăn xếp 1 không chắc chắn nặng hơn.

### Segment Tree với Lazy Propagation

Khi đồng xu $c$ vào ngăn xếp $s$, mọi $suffix_k$ với $k \leq c$ thay đổi $\pm 1$. Dùng Segment Tree với lazy propagation để cập nhật đoạn và truy vấn min trong $O(\log n)$:

- **Cây Stack_1:** lưu $suffix_k$. Đồng xu $c$ vào ngăn xếp 1: cộng $+1$ đoạn $[1, c]$; ngăn xếp 2: cộng $-1$.
- **Cây Stack_2:** lưu $-suffix_k$. Đồng xu $c$ vào ngăn xếp 1: cộng $-1$ đoạn $[1, c]$; ngăn xếp 2: cộng $+1$.

Sau mỗi lượt:
- Nếu $\min(\text{Stack\_1}) \geq 0$: xuất `>`
- Ngược lại nếu $\min(\text{Stack\_2}) \geq 0$: xuất `<`
- Ngược lại: xuất `?`

### Ví dụ

$n = 3$, $w_1 < w_2 < w_3$.

| Lượt | Hành động | $val$ | $suffix$ | Stack_1 min | Stack_2 min | Kết quả |
|------|-----------|-------|----------|-------------|-------------|---------|
| 1 | Xu 2 → Ngăn 1 | [0,+1,0] | [1,1,0] | 0 | -1 | `>` |
| 2 | Xu 3 → Ngăn 2 | [0,+1,-1] | [0,0,-1] | -1 | 0 | `<` |
| 3 | Xu 1 → Ngăn 1 | [+1,+1,-1] | [1,0,-1] | -1 | -1 | `?` |

Kiểm chứng: Lượt 2, ngăn 1 = {xu 2}, ngăn 2 = {xu 3}. Vì $w_3 > w_2$, ngăn 2 chắc chắn nặng hơn. Lượt 3, ngăn 1 = {1,2}, ngăn 2 = {3}. $w_1 + w_2$ so với $w_3$ chưa biết, nên `?`.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — $n$ lần cập nhật đoạn và truy vấn min trên cây phân đoạn
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Stack%20Weights.cpp)
