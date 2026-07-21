# Distinct Values Subsequences - Lời giải

**ID:** 3421 | **URL:** https://cses.fi/problemset/task/3421

## Phương pháp

### Tóm tắt bài toán

Cho mảng gồm $n$ số nguyên, đếm số dãy con mà mỗi phần tử đều phân biệt. Kết quả lấy modulo $10^9 + 7$.

### Ý tưởng chính

Trong dãy con phân biệt, mỗi giá trị $v$ xuất hiện nhiều nhất 1 lần. Nếu $v$ xuất hiện $c_v$ lần trong mảng gốc, ta có $c_v + 1$ lựa chọn: không chọn $v$, hoặc chọn đúng một trong $c_v$ lần xuất hiện của $v$. Các giá trị phân biệt chọn độc lập với nhau, nên theo nguyên lý nhân, số dãy con phân biệt (bao gồm rỗng) là $\prod_v (c_v + 1)$. Có song ánh giữa tập dãy con phân biệt và tích Descartes $\prod_v \{0, 1, \dots, c_v\}$: bộ chọn $(s_{v_1}, \dots, s_{v_d})$ xác định duy nhất dãy con (chọn lần xuất hiện thứ $s_{v_i}$ nếu $s_{v_i} > 0$, không chọn nếu $s_{v_i} = 0$), và ngược lại. Trừ 1 cho trường hợp dãy rỗng (tất cả $s_v = 0$).

### Thuật toán

1. Đếm tần suất $c_v$ của từng giá trị bằng map.
2. Khởi tạo `ans = 1`.
3. Duyệt qua map: `ans = ans * (c_v + 1) mod (10^9 + 7)`.
4. Xuất `(ans - 1 + mod) mod (10^9 + 7)`.

### Ví dụ minh họa

Mảng $[1, 2, 1, 3]$, $n = 4$.

| Giá trị $v$ | $c_v$ | $c_v + 1$ |
|-------------|-------|-----------|
| 1 | 2 | 3 |
| 2 | 1 | 2 |
| 3 | 1 | 2 |

Tích: $3 \times 2 \times 2 = 12$. Trừ dãy rỗng: $12 - 1 = \mathbf{11}$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Values%20Subsequences.cpp)
