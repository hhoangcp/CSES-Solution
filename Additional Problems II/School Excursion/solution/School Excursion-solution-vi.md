# School Excursion - Lời giải

**ID:** 1706 | **URL:** https://cses.fi/problemset/task/1706

## Đề bài

Một nhóm $n$ trẻ em đang đến Helsinki. Có hai điểm tham quan: Korkeasaari (sở thú) hoặc Linnanmäki (công viên giải trí). Có $m$ cặp trẻ em muốn đến cùng một điểm tham quan. Nhiệm vụ của bạn là tìm tất cả các khả năng cho số trẻ em sẽ đến Korkeasaari.

## Hướng tiếp cận

### Bước 1: Xây dựng thành phần liên thông

Các ràng buộc "cùng điểm tham quan" tạo ra các thành phần liên thông trên đồ thị. Nếu $a$ và $b$ trong cùng thành phần, tồn tại đường đi $a = v_0, v_1, \ldots, v_k = b$ với mỗi cặp liên tiếp cùng điểm, nên bằng quy nạp, cả thành phần phải đến cùng một điểm.

Dùng DSU (Union-Find) để tìm tất cả thành phần liên thông. Gọi kích thước các thành phần là $s_1, s_2, \ldots, s_c$.

### Bước 2: Bài toán tổng tập con bằng Bitset

Bài toán quy về: cho các kích thước $s_1, s_2, \ldots, s_c$, tìm mọi tổng có thể đạt được bằng cách chọn một tập con các thành phần đi Korkeasaari.

Giải bằng **bitset**: bắt đầu với $B = 1$ (bit 0 đặt). Với mỗi kích thước $s_i$: $B \leftarrow B \mid (B \ll s_i)$. Sau khi xử lý thành phần $1, \ldots, i$, bit $j$ của $B$ là 1 iff tồn tại tập con của $\{s_1, \ldots, s_i\}$ có tổng $j$ (chứng minh quy nạp: mỗi tổng cũ $j$ và $j + s_{i+1}$ đều trở nên khả thi khi thêm $s_{i+1}$). Kết quả: bit $j$ của $B$ là 1 iff $j$ trẻ có thể đến Korkeasaari.

### Bước 3: Tối ưu nhóm nhị phân (Optional)

Nếu có nhiều thành phần cùng kích thước $s$, thay vì dịch bitset $k$ lần, dùng **nhóm nhị phân**: phân rã $k$ thành $1 + 2 + 4 + \ldots + 2^{\lfloor \log_2 k \rfloor} + r$. Mỗi số từ 0 đến $k$ đều biểu diễn được dưới dạng tổng tập con các nhóm này (tương tự biểu diễn nhị phân), nên phép biểu diễn là đúng. Giảm từ $k$ phép dịch xuống $O(\log k)$ phép.

Với $N = 10^5$, bitset thuần thường đã đủ nhanh, nhưng nhóm nhị phân giúp tối ưu thêm khi có nhiều nhóm cùng kích thước.

### Ví dụ

$n = 5, m = 3$. Cặp: (1,2), (2,3), (1,5).

Thành phần: $\{1, 2, 3, 5\}$ kích thước 4, và $\{4\}$ kích thước 1.

Bitset ban đầu: `000001`. Sau thành phần 4: `010001`. Sau thành phần 1: `110011`.

Kết quả bit 1..5: `10011`, tức 1, 4, 5 trẻ có thể đi Korkeasaari.

## Độ phức tạp

- **Thời gian:** $O(n^2 / 64)$ nếu dịch bitset trực tiếp, hoặc $O(n^2 / 64 \cdot \log n)$ nếu dùng nhóm nhị phân.
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/School%20Excursion.cpp)
