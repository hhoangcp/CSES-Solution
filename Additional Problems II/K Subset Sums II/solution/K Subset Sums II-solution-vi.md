# K Subset Sums II - Lời giải

**ID:** 3109 | **URL:** https://cses.fi/problemset/task/3109

## Đề bài

Cho $n$ số nguyên, tìm $k$ tổng nhỏ nhất của các tập con có *đúng* $m$ phần tử, theo thứ tự tăng.

## Hướng tiếp cận

### Khác biệt so với K Subset Sums I: Chỉ được "nâng cấp"

Ở bài I, ta tự do thêm hoặc thay phần tử. Ở bài II, phải duy trì đúng $m$ phần tử, nên chỉ có thể **nâng cấp**: thay $a_j$ bằng $a_k$ ($k > j$). Tập cơ sở ban đầu là $m$ phần tử nhỏ nhất $\{a_0, a_1, \ldots, a_{m-1}\}$.

### Trạng thái và hai chuyển tiếp

Mỗi trạng thái trong min-heap là $(s, k, p, \text{limit})$:
- **$s$**: tổng hiện tại.
- **$k$**: vị trí đang được nâng cấp.
- **$p$**: chỉ số phần tử hiện tại tại vị trí $k$.
- **$\text{limit}$**: giới hạn chỉ số để không "dẫm" lên phần tử phía sau.

Hai chuyển tiếp:
1. **Mở rộng:** Thay $a[p]$ bằng $a[p+1]$: $s' = s - a[p] + a[p+1]$, $p' = p+1$. Tiếp tục nâng cấp tại cùng vị trí $k$.
2. **Phân nhánh:** Quay lại nâng cấp vị trí $k-1$: thay $a[k-1]$ bằng $a[k]$, đặt lại $p$ và $\text{limit}$.

**Tính đầy đủ:** Mọi tập $m$ phần tử $S = \{i_1, \ldots, i_m\}$ thu được từ tập cơ sở bằng chuỗi nâng cấp: nâng vị trí $0$ từ $a_0$ đến $a_{i_1}$ (mở rộng lặp), rồi phân nhánh về vị trí $1$, nâng lên $a_{i_2}$, v.v.

**Không trùng lặp:** Quy tắc "nâng cấp vị trí cao nhất trước, chỉ phân nhánh sang vị trí thấp hơn" tạo thứ tự duy nhất cho mỗi tập — tại mỗi bước, biết $k$ và $p$ thì quyết định tiếp theo là duy nhất.

## Thuật toán

1. Sắp xếp mảng tăng dần.
2. Tính `current_sum` = tổng $m$ phần tử đầu tiên.
3. Đẩy trạng thái ban đầu `(current_sum, m-1, m-1, n)` vào min-heap.
4. Lặp $k$ lần:
   - Lấy trạng thái có `sum` nhỏ nhất.
   - Lưu `sum` vào kết quả.
   - Nếu $p + 1 < \text{limit}$, đẩy trạng thái mở rộng.
   - Nếu $k > 0$ và $k < p$, đẩy trạng thái phân nhánh.
5. Xuất kết quả.

## Ví dụ minh họa

$n = 5$, $m = 3$, $k = 9$, mảng $[-3, 1, 5, 2, 0]$.

- Mảng sau sắp xếp: $[-3, 0, 1, 2, 5]$.
- Tổng $m$ phần tử nhỏ nhất: $-3 + 0 + 1 = -2$.

Kết quả: $-2, -1, 0, 2, 3, 3, 4, 6, 7$.

## Độ phức tạp

- **Thời gian:** $O(n \log n + k \log k)$
- **Bộ nhớ:** $O(n + k)$

## Mã nguồn (C++)

[Mã nguồn](../code/K%20Subset%20Sums%20II.cpp)
