# Triangle Number Sums - Lời giải

**ID:** 3406 | **URL:** https://cses.fi/problemset/task/3406

## Phương pháp

### Tóm tắt bài toán

Cho số nguyên dương $n$ (lên đến $10^{12}$), tìm số lượng số tam giác (số dạng $T_k = \frac{k(k+1)}{2}$) nhỏ nhất có tổng bằng $n$. Có tối đa $t = 100$ test case.

### Ý tưởng chính

**Định lý Eureka của Gauss (1796):** Mọi số nguyên dương đều biểu diễn được dưới dạng tổng của nhiều nhất 3 số tam giác. Gauss ghi lại sự kiện này với dòng chữ *"EYPHKA! num = $\Delta$ + $\Delta$ + $\Delta$"*.

Hệ quả: đáp án chỉ có thể là 1, 2, hoặc 3. Ta kiểm tra tuần tự từ thấp lên cao.

**Tiêu chuẩn nhận biết:** $n$ là số tam giác khi và chỉ khi $8n + 1$ là số chính phương. Điều này suy ra từ phương trình $n = \frac{k(k+1)}{2} \Leftrightarrow k^2 + k - 2n = 0$, nghiệm $k = \frac{-1 + \sqrt{1 + 8n}}{2}$; để $k$ nguyên dương, $1 + 8n$ phải là số chính phương.

### Thuật toán

1. **Đáp án 1:** Tính $m = \lfloor\sqrt{8n+1}\rfloor$. Nếu $m^2 = 8n+1$, $n$ là số tam giác → trả về 1.
2. **Đáp án 2:** Duyệt $i$ từ 0 với $T_i \le n/2$, tính $rem = n - T_i$. Nếu $8 \cdot rem + 1$ là chính phương, tồn tại $T_j = rem$ nên $n = T_i + T_j$ → trả về 2. (Do tính đối xứng, chỉ cần duyệt đến $i \approx \sqrt{n}$ vì $T_i \approx i^2/2$.)
3. **Đáp án 3:** Nếu không thỏa hai bước trên, theo định lý Gauss đáp án phải là 3 → trả về 3.

**Tính đúng:** Bước 1 tối ưu vì $n > 0$ không thể dùng 0 số. Bước 2 chỉ đạt đến sau khi Bước 1 thất bại, nên đáp án không thể là 1. Bước 3 được bảo đảm bởi định lý Gauss, khẳng định đáp án không vượt quá 3.

### Ví dụ minh họa

| $n$ | $8n+1$ | Chính phương? | Kiểm tra | Đáp án |
|-----|--------|---------------|----------|--------|
| 1 | 9 | $3^2$ ✓ | — | 1 |
| 2 | 17 | ✗ | $2 - 1 = 1$, $8 \cdot 1 + 1 = 9 = 3^2$ ✓ | 2 |
| 3 | 25 | $5^2$ ✓ | — | 1 |
| 42 | 337 | ✗ | $42 - 21 = 21$, $8 \cdot 21 + 1 = 169 = 13^2$ ✓ | 2 |
| 1337 | 10697 | ✗ | Không tìm được cặp | 3 |

## Độ phức tạp

- **Thời gian:** $O(\sqrt{n})$ mỗi test case
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Triangle%20Number%20Sums.cpp)
