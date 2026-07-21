# Tower of Hanoi - Lời giải

**ID:** 2165 | **URL:** https://cses.fi/problemset/task/2165

## Hướng tiếp cận

### Tóm tắt bài toán

Chuyển $n$ đĩa ($1 \le n \le 16$) từ cọc 1 sang cọc 3, mỗi lần chuyển 1 đĩa, không đặt đĩa lớn lên trên đĩa nhỏ. Tối thiểu hóa tổng số bước.

### Ý tưởng chính

Gọi các cọc là **A** (nguồn), **B** (phụ trợ), **C** (đích). Để chuyển $n$ đĩa từ A sang C, ta cần giải phóng đĩa lớn nhất (đĩa $n$) bằng cách chuyển $n-1$ đĩa trên cùng đi nơi khác:

1. Đệ quy chuyển $n-1$ đĩa trên cùng từ A sang B (dùng C làm bộ nhớ tạm).
2. Chuyển đĩa $n$ trực tiếp từ A sang C.
3. Đệ quy chuyển $n-1$ đĩa từ B sang C (dùng A làm bộ nhớ tạm).

**Tính đúng.** Sau bước 1, chỉ còn đĩa $n$ trên A (tự do di chuyển) và cọc C rỗng. Bước 2 đặt đĩa $n$ lên cọc C rỗng — không vi phạm quy tắc. Bước 3 đặt $n-1$ đĩa nhỏ hơn lên trên đĩa $n$ trên cọc C — vì tất cả đều nhỏ hơn, quy tắc thứ tự được giữ, và đây chính là bài toán tương tự với $n-1$ đĩa.

**Tính tối thiểu.** Gọi $T(n)$ là số bước tối thiểu. Bất kỳ lời giải nào cũng phải: (i) chuyển $n-1$ đĩa trên cùng ra khỏi đĩa $n$ (ít nhất $T(n-1)$ bước), (ii) chuyển đĩa $n$ sang C (ít nhất 1 bước), (iii) chuyển $n-1$ đĩa trở lại trên đĩa $n$ (ít nhất $T(n-1)$ bước). Vậy $T(n) \ge 2T(n-1) + 1$ với $T(1) \ge 1$. Chiến lược đạt đúng $T(n) = 2T(n-1) + 1$ với $T(1) = 1$, nên tối ưu.

**Giải phương trình truy hồi:** $T(n) + 1 = 2(T(n-1) + 1)$ cho $S(n) = T(n) + 1 = 2 \cdot S(n-1)$ với $S(1) = 2$. Đây là cấp số nhân: $S(n) = 2^n$, suy ra $T(n) = 2^n - 1$.

### Thuật toán

Gọi `Move(n, 1, 3, 2)` với `Move(k, src, dst, aux)`:
1. Nếu $k = 0$, trả về.
2. Đệ quy gọi `Move(k-1, src, aux, dst)`.
3. In `src dst`.
4. Đệ quy gọi `Move(k-1, aux, dst, src)`.

Tổng số bước: $2^n - 1$.

### Ví dụ minh họa

**Ví dụ đề bài ($n = 2$):** $2^2 - 1 = 3$ bước.

| Bước | Chuyển |
|---|---|
| 1 | 1 → 2 |
| 2 | 1 → 3 |
| 3 | 2 → 3 |

**Ví dụ minh họa ($n = 3$):** $2^3 - 1 = 7$ bước. Đĩa đánh số từ 1 (nhỏ nhất) đến 3 (lớn nhất), cọc A, B, C.

| Bước | Đĩa | Chuyển | Trạng thái |
|---|---|---|---|
| 1 | 1 | A → C | |
| 2 | 2 | A → B | |
| 3 | 1 | C → B | Đĩa 1,2 trên B; đĩa 3 tự do |
| 4 | 3 | A → C | Đĩa 3 đến đích |
| 5 | 1 | B → A | |
| 6 | 2 | B → C | |
| 7 | 1 | A → C | Tháp hoàn thiện trên C |

## Độ phức tạp

- **Thời gian:** $O(2^n)$ — xuất đúng $2^n - 1$ bước
- **Không gian:** $O(n)$ — độ sâu đệ quy tối đa

## Mã nguồn (C++)

[Mã nguồn](../code/Tower%20of%20Hanoi.cpp)
