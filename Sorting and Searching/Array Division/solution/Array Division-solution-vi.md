# Array Division - Lời giải

**ID:** 1085 | **URL:** https://cses.fi/problemset/task/1085

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên dương, chia thành $k$ mảng con liên tiếp sao cho tổng lớn nhất của một mảng con là nhỏ nhất. Tìm giá trị tối thiểu đó.

### Ý tưởng chính

Gọi $g(S)$ là số mảng con liên tiếp tối thiểu cần thiết khi giới hạn tổng mỗi mảng con $\le S$. Khi tăng $S$, không gian chứa mỗi đoạn rộng hơn nên $g(S)$ không tăng — tức $g(S)$ là hàm đơn điệu giảm. Ta cần tìm $S$ nhỏ nhất sao cho $g(S) \le k$, đây chính là bài toán tìm kiếm nhị phân trên kết quả.

Để đánh giá $g(S)$, dùng chiến lược tham lam: quét trái sang phải, tích lũy phần tử vào mảng con hiện tại, cắt ngay khi thêm phần tử tiếp theo làm tổng vượt $S$. Tham lam luôn tối ưu vì nó mở rộng mỗi đoạn càng xa càng tốt — bằng quy nạp, mọi điểm cắt tham lam $d_i$ thỏa $d_i \ge c_i$ (với $c_i$ là điểm cắt của một phương án hợp lệ bất kỳ), nên tham lam không bao giờ tạo ra nhiều mảng con hơn phương án đó.

### Thuật toán

1. Đặt $L = \max(a_i)$, $R = \sum a_i$.
2. Tìm nhị phân $S$ trong $[L, R]$:
   - Với mỗi $mid$, đếm số mảng con tham lam có tổng $\le mid$.
   - Nếu số mảng con $\le k$: $S$ khả thi, ghi nhận đáp án, tìm nửa trái.
   - Ngược lại: tìm nửa phải.
3. Lưu ý: tổng có thể đạt $2 \times 10^{14}$, cần dùng kiểu 64-bit.

### Ví dụ minh họa

$n = 5$, $k = 3$, $a = [2, 4, 7, 3, 5]$.

$L = 7$, $R = 21$. Tìm nhị phân trong $[7, 21]$.

Kiểm tra $S = 8$: tham lam cho $[2,4] \mid [7] \mid [3,5]$ → 3 mảng con $\le k = 3$. Khả thi.

Kiểm tra $S = 7$: tham lam cho $[2,4] \mid [7] \mid [3] \mid [5]$ → 4 mảng con $> k = 3$. Không khả thi.

Đáp án: **8**.

## Độ phức tạp

- **Thời gian:** $O(n \log(\sum a_i))$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Array%20Division.cpp)
