# K Subset Sums I - Lời giải

**ID:** 3108 | **URL:** https://cses.fi/problemset/task/3108

## Đề bài

Cho $n$ số nguyên, tìm $k$ tổng tập con nhỏ nhất (bao gồm tập rỗng tổng 0) theo thứ tự tăng.

## Hướng tiếp cận

### Xử lý số âm: Đưa về mảng không âm

Nếu mảng chỉ có số không âm, tổng nhỏ nhất chắc chắn là tập rỗng (0). Nếu có số âm, tập con có tổng nhỏ nhất sẽ chứa **tất cả** các số âm. Gọi `min_sum` = tổng các số âm. Lấy trị tuyệt đối các số âm, ta đưa bài toán về tìm $k$ tổng nhỏ nhất của mảng **không âm**, rồi cộng mỗi tổng với `min_sum` để ra kết quả cuối cùng.

### Sinh tổng tập con bằng Min-Heap

Sau khi có mảng không âm đã sắp xếp tăng $a_0 \le a_1 \le \cdots \le a_{n-1}$, dùng **min-heap** để trích xuất $k$ tổng nhỏ nhất. Mỗi trạng thái trong heap là cặp `(sum, index)`: tổng hiện tại và chỉ số phần tử cuối được xử lý.

Từ trạng thái `(s, i)`, hai hướng chuyển tiếp sinh tổng lớn hơn một cách có hệ thống:
1. **Thêm phần tử kế:** `(s + a[i+1], i+1)` — chọn thêm $a_{i+1}$.
2. **Thay phần tử hiện tại:** `(s - a[i] + a[i+1], i+1)` — loại $a_i$, thay bằng $a_{i+1}$.

**Tính đầy đủ:** Mọi tập con đều sinh được qua hai chuyển tiếp. Tập $S = \{i_1, i_2, \ldots, i_m\}$ được sinh qua chuỗi quyết định: thêm/thay lần lượt tại mỗi chỉ số từ $i_1$ đến $i_m$.

**Tính tối ưu:** Vì mảng đã sắp xếp ($a_i \le a_{i+1}$), chuyển "thêm" chắc chắn tăng tổng, chuyển "thay" không giảm tổng. Min-heap đảm bảo luôn trích tổng nhỏ nhất tiếp theo.

## Thuật toán

1. Tính `min_sum` = tổng các số âm, đổi dấu các số âm thành dương.
2. Sắp xếp mảng không âm tăng dần.
3. Kết quả đầu tiên: `min_sum` (tập chỉ gồm các số âm ban đầu).
4. Đẩy `(a[0], 0)` vào min-heap.
5. Lặp $k-1$ lần:
   - Lấy `(s, i)` nhỏ nhất từ heap.
   - Lưu `s + min_sum` vào kết quả.
   - Nếu `i + 1 < n`, đẩy hai trạng thái chuyển tiếp vào heap.
6. Xuất $k$ kết quả.

## Ví dụ minh họa

Mảng: $[1, 6, 3, -3]$, $k = 9$.

- `min_sum = -3`. Mảng sau xử lý: $[1, 3, 3, 6]$.
- Kết quả đầu: $-3$.
- Heap: `{(1, 0)}`.
- Lấy `(1, 0)` → KQ: $-3 + 1 = -2$. Đẩy `(1+3, 1)` và `(1-1+3, 1)` → Heap: `{(3, 1), (4, 1)}`.
- Lấy `(3, 1)` → KQ: $-3 + 3 = 0$. Tiếp tục cho đến đủ 9 tổng.

Kết quả: $-3, -2, 0, 0, 1, 1, 3, 3, 4$.

## Độ phức tạp

- **Thời gian:** $O(n \log n + k \log k)$
- **Bộ nhớ:** $O(n + k)$

## Mã nguồn (C++)

[Mã nguồn](../code/K%20Subset%20Sums%20I.cpp)
