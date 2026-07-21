# Sum of Four Values - Lời giải

**ID:** 1642 | **URL:** https://cses.fi/problemset/task/1642

## Đề bài

Cho mảng gồm $n$ số nguyên $a_1, a_2, \ldots, a_n$ và giá trị mục tiêu $x$. Tìm bốn chỉ số phân biệt $i, j, k, l$ sao cho $a_i + a_j + a_k + a_l = x$. Nếu có nhiều bộ thỏa mãn, xuất bất kỳ; nếu không tồn tại, xuất `IMPOSSIBLE`.

## Hướng tiếp cận

### 1. Ý tưởng cốt lõi: chia bài toán tổng 4 thành 2 + 2

Thay vì duyệt mọi bộ 4 chỉ số với độ phức tạp $O(n^4)$, ta biến đổi bài toán về việc tìm hai cặp phần tử không giao nhau có tổng cộng bằng $x$. Nếu $S_{\text{first}} = a_p + a_q$ và $S_{\text{second}} = a_i + a_j$, ta cần:

$$S_{\text{first}} + S_{\text{second}} = x \iff S_{\text{first}} = x - S_{\text{second}}$$

Ta dùng một map lưu các tổng của các cặp đã xử lý, kèm theo hai chỉ số tạo nên tổng đó.

### 2. Kỹ thuật "kiểm tra trước, chèn sau" đảm bảo chỉ số phân biệt

Để bốn chỉ số hoàn toàn tách biệt mà không cần kiểm tra phức tạp, ta tách rõ hai thao tác khi quét qua từng phần tử làm mốc $i$:

1. Khởi tạo map với cặp đầu tiên: $M[a_1 + a_2] = (1, 2)$.
2. Duyệt mốc $i$ từ $3$ đến $n - 1$:
   - **Kiểm tra trước:** duyệt $j$ từ $i + 1$ đến $n$, tính $X = x - a_i - a_j$. Nếu $X$ đã có trong map dưới dạng cặp $(p, q)$ thì ta tìm được bộ bốn thỏa mãn. Vì mọi cặp trong map đều được chèn ở các bước trước, chắc chắn $p < q < i < j$, nên bốn chỉ số hoàn toàn phân biệt; ta lập tức in kết quả và dừng.
   - **Chèn sau:** trước khi sang mốc $i$ tiếp theo, chèn tất cả các cặp dạng $(a_k + a_i)$ với $k$ từ $1$ đến $i - 1$ vào map.

Tách biệt hai thao tác này đảm bảo các cặp đang kiểm tra luôn có chỉ số $\ge i$ (cụ thể $j > i$), còn các cặp trong map luôn có cả hai chỉ số $< i$; do đó bốn chỉ số thu được chắc chắn khác nhau.

## Ví dụ minh họa

Xét $n = 5$, $x = 10$, mảng $a = [1, 2, 3, 4, 5]$.

- **Khởi tạo:** $M = \{a_1 + a_2 : (1, 2)\} = \{3 : (1, 2)\}$.
- **Mốc $i = 3$ ($a_3 = 3$):**
  - **Kiểm tra với $j = 4$ ($a_4 = 4$):** $X = 10 - a_3 - a_4 = 10 - 3 - 4 = 3$. Giá trị $3$ đã có trong map, ứng với cặp $(1, 2)$.
- **Kết quả:** tìm thấy bộ $(1, 2, 3, 4)$ với tổng $1 + 2 + 3 + 4 = 10$.

## Độ phức tạp

- **Thời gian:** $O(n^2 \log n)$ nếu dùng `std::map`, hoặc $O(n^2)$ nếu dùng `std::unordered_map`. Có hai vòng lặp lồng nhau duyệt qua các cặp chỉ số; mỗi trạng thái thực hiện truy vấn hoặc chèn với chi phí $O(\log n)$ hoặc $O(1)$.
- **Bộ nhớ:** $O(n^2)$ để lưu tối đa $\binom{n}{2}$ cặp phần tử phân biệt.
