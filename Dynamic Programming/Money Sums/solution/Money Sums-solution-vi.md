# Money Sums - Lời giải

**ID:** 1745 | **URL:** https://cses.fi/problemset/task/1745

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho $n$ đồng xu có giá trị $x_1, \ldots, x_n$ ($1 \le n \le 100$, $1 \le x_i \le 1000$), tìm tất cả các tổng phân biệt có thể tạo bằng cách chọn một tập con bất kỳ. Xuất số lượng và liệt kê các tổng theo thứ tự tăng dần.

### Ý tưởng cốt lõi

Đây là bài toán **tổng tập con** (subset sum) cổ điển. Gọi $dp[s]$ cho biết tổng $s$ có thể tạo được hay không. Ban đầu chỉ $dp[0]$ đúng (tập rỗng). Với mỗi đồng xu giá trị $x$, cập nhật $dp[s] = dp[s] \lor dp[s-x]$ duyệt ngược $s$ từ $S_{\max}$ xuống $x$ (duyệt ngược để không dùng cùng một đồng xu hai lần). Tổng tối đa đạt được là $S_{\max} = \sum x_i \le 100 \times 1000 = 10^5$.

**Tối ưu bitset:** Biểu diễn cả mảng $dp$ bằng `bitset<100001>`. Cập nhật cho đồng xu $x$ trở thành một phép toán duy nhất:

$$\text{bs} \leftarrow \text{bs} \lor (\text{bs} \ll x)$$

Phép dịch trái $\text{bs} \ll x$ ánh xạ mỗi tổng đạt được $s$ thành $s+x$ (thêm đồng xu $x$ vào các tập con hiện có). Phép OR gộp các tổng không dùng $x$ và dùng $x$. Bitset tận dụng song song 64-bit, tăng tốc khoảng 64 lần so với mảng boolean tuần tự.

**Tính đúng (bất biến):** Sau khi xử lý $k$ đồng xu, bit $s$ được đặt khi và chỉ khi tồn tại tập con của $\{x_1, \ldots, x_k\}$ có tổng bằng $s$. Chứng minh quy nạp: cơ sở chỉ có bit 0 (tập rỗng). Bước quy nạp: $\text{bs} \ll x_{k+1}$ tạo các tổng có chứa $x_{k+1}$; phép OR gộp với các tổng không chứa — nên mọi tập con của $\{x_1, \ldots, x_{k+1}\}$ đều được xét đúng một lần.

### Thuật toán

1. Khởi tạo `bitset<100001> bs` chỉ đặt bit 0.
2. Với mỗi đồng xu $x$: `bs |= (bs << x)`.
3. Xuất `bs.count() - 1` (loại tổng 0), rồi xuất tất cả bit được đặt từ 1 trở đi.

### Ví dụ

Các đồng xu $\{4, 2, 5, 2\}$:

| Bước | Đồng xu $x$ | `bs << x` thêm | Các tổng đạt được (sau OR) |
|------|-------------|-----------------|----------------------------|
| Khởi tạo | — | — | $\{0\}$ |
| 1 | 4 | $\{4\}$ | $\{0, 4\}$ |
| 2 | 2 | $\{2, 6\}$ | $\{0, 2, 4, 6\}$ |
| 3 | 5 | $\{5, 7, 9, 11\}$ | $\{0, 2, 4, 5, 6, 7, 9, 11\}$ |
| 4 | 2 | $\{2, 4, 6, 7, 8, 9, 11, 13\}$ | $\{0, 2, 4, 5, 6, 7, 8, 9, 11, 13\}$ |

Kết quả: 9 tổng: $2, 4, 5, 6, 7, 8, 9, 11, 13$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot S / 64)$ với $S \le 10^5$ là tổng lớn nhất — mỗi phép dịch trái và OR tốn $O(S/64)$
- **Bộ nhớ:** $O(S)$ cho bitset

## Mã nguồn (C++)

[Mã nguồn](../code/Money%20Sums.cpp)
