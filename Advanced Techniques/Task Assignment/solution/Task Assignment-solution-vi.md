# Task Assignment - Lời giải

**ID:** 2129 | **URL:** https://cses.fi/problemset/task/2129

## Phương pháp

### Tóm tắt bài toán

Cho $n$ nhân viên và $n$ nhiệm vụ, nhân viên $i$ làm nhiệm vụ $j$ với chi phí $c_{ij}$. Phân công mỗi nhân viên đúng 1 nhiệm vụ (song ánh) để tối thiểu tổng chi phí. Xuất phân công tối ưu.

### Ý tưởng chính

Đây là **bài toán phân công** — ghép cặp hoàn hảo hai phía trọng số tối thiểu. Mô hình hóa bằng **luồng chi phí tối thiểu** trên mạng hai phía:

- **Siêu nguồn $S$** (nút 1) → mỗi nhân viên (dung lượng 1, chi phí 0).
- Nhân viên $i$ → nhiệm vụ $j$ (dung lượng 1, chi phí $c_{ij}$).
- Mỗi nhiệm vụ → **siêu hội $T$** (dung lượng 1, chi phí 0).

Gửi $n$ đơn vị luồng từ $S$ đến $T$ với chi phí tối thiểu cho phân công tối ưu: cạnh dung lượng 1 buộc mỗi nhân viên gửi đúng 1 đơn vị đến đúng 1 nhiệm vụ, mỗi nhiệm vụ nhận tối đa 1 đơn vị, tạo thành song ánh hợp lệ. Vì mỗi phân công tương ứng luồng giá trị $n$ và ngược lại, tối thiểu chi phí luồng tương đương tối thiểu chi phí phân công.

Dùng **thuật toán đường tăng ngắn nhất liên tiếp (SSAP)** với Dijkstra + thế vị: mỗi lần lặp tìm đường tăng rẻ nhất và gửi 1 đơn vị. Thế vị `delta[u]` đảm bảo chi phí rút gọn không âm, cho phép dùng Dijkstra ngay cả khi có cạnh ngược chi phí âm.

### Thuật toán

1. Xây mạng luồng hai phía.
2. Chạy luồng chi phí tối thiểu (SSAP với Dijkstra + thế vị) gửi $n$ đơn vị.
3. Trích phân công: với mỗi nút nhân viên, tìm cạnh bão hòa (flow = cap = 1) đến nút nhiệm vụ.
4. Xuất tổng chi phí và các cặp phân công.

### Ví dụ minh họa

$n=4$, ma trận chi phí:

|  | Nhiệm vụ 1 | Nhiệm vụ 2 | Nhiệm vụ 3 | Nhiệm vụ 4 |
|--|------------|------------|------------|------------|
| Nhân viên 1 | 17 | 8 | 16 | 9 |
| Nhân viên 2 | 7 | 15 | 12 | 19 |
| Nhân viên 3 | 6 | 9 | 10 | 11 |
| Nhân viên 4 | 14 | 7 | 13 | 10 |

Phân công tối ưu:

| Nhân viên | Nhiệm vụ | Chi phí |
|-----------|----------|---------|
| 1 | 4 | 9 |
| 2 | 1 | 7 |
| 3 | 3 | 10 |
| 4 | 2 | 7 |

Tổng: $9 + 7 + 10 + 7 = \mathbf{33}$.

## Độ phức tạp

- **Thời gian:** $O(n^3)$
- **Bộ nhớ:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Task%20Assignment.cpp)
