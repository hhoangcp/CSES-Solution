# Programmers and Artists - Lời giải

**ID:** 2426 | **URL:** https://cses.fi/problemset/task/2426

## Đề bài

Một công ty muốn thuê $a$ lập trình viên và $b$ họa sĩ. Có $n$ ứng viên, mỗi người có kỹ năng lập trình $x$ và kỹ năng nghệ thuật $y$. Tối đa hóa tổng kỹ năng.

## Hướng tiếp cận

### Sắp xếp theo hiệu số: Lập trình viên ở đầu, họa sĩ ở cuối

Sắp xếp ứng viên theo $x_i - y_i$ giảm dần. Ứng viên có hiệu cao nên làm lập trình viên (nhiều lợi hơn), hiệu thấp nên làm họa sĩ.

**Tồn tại điểm chia tối ưu:** Giả sử ứng viên $i$ (hiệu cao hơn) làm họa sĩ và $j$ (hiệu thấp hơn, $j > i$) làm lập trình viên. Đổi vai trò: thay đổi tổng = $(x_i + y_j) - (y_i + x_j) = (x_i - y_i) - (x_j - y_j) \ge 0$. Đổi không bao giờ giảm tổng, nên luôn tồn tại cấu hình tối ưu mà tất cả lập trình viên nằm trong $p$ ứng viên đầu.

### Quét hai phía: Min-heap cho top $a$ và top $b$

**Quét xuôi (prefix):** Duy trì min-heap kích thước $a$ chứa kỹ năng lập trình. $dp[i]$ = tổng $a$ kỹ năng lập trình tốt nhất trong $i$ ứng viên đầu.

**Quét ngược (suffix):** Duy trì min-heap kích thước $b$ chứa kỹ năng nghệ thuật. Với mỗi điểm chia $i$, tính tổng $b$ kỹ năng nghệ thuật tốt nhất trong ứng viên từ $i$ đến $n$.

**Đáp án:** $\max(dp[i-1] + \text{artist\_sum}_i)$ trên mọi điểm chia $i$ hợp lệ.

## Thuật toán

1. Sắp xếp ứng viên theo $x - y$ giảm dần.
2. Quét xuôi: tính $dp[i]$ cho $i = a \ldots n$.
3. Quét ngược: duy trì `artist_sum`, cập nhật đáp án tại mỗi điểm chia.

## Ví dụ minh họa

$a = 2, b = 1, n = 4$. Ứng viên: $(3,7), (9,8), (1,5), (4,2)$.

Sắp xếp theo $x - y$ giảm: $(4,2) \to 2$, $(9,8) \to 1$, $(3,7) \to -4$, $(1,5) \to -4$.

- Quét xuôi: $dp[2] = 4 + 9 = 13$.
- Quét ngược: tại $i = 3$, họa sĩ tốt nhất = 7.
- Đáp án: $13 + 7 = 20$.

Chọn lập trình viên: ứng viên 1 (kỹ năng 4) và 2 (kỹ năng 9). Họa sĩ: ứng viên 3 (kỹ năng 7).

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp + duyệt với heap
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Programmers%20and%20Artists.cpp)
