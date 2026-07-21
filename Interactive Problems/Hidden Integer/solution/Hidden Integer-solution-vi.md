# Số nguyên ẩn - Lời giải

**ID:** 3112 | **URL:** https://cses.fi/problemset/task/3112

## Phương pháp

### Tóm tắt bài toán

Có một số nguyên ẩn $x$ trong khoảng $[1, 10^9]$. Tìm $x$ bằng cách hỏi "$y < x$?", tối đa 30 truy vấn.

### Ý tưởng chính

Mỗi truy vấn chia miền tìm kiếm thành hai nửa: các giá trị $< mid$ và $\ge mid$. Đây chính là tìm kiếm nhị phân trên khoảng đã sắp xếp. Vì $\lceil \log_2(10^9) \rceil = 30$, chặt nhị phân vừa khít giới hạn truy vấn.

**Bất biến:** Sau mỗi bước, $x \in [l, r]$. Ban đầu $l = 1, r = 10^9$. Sau khi hỏi $mid$:
- Nếu `YES` ($mid < x$): vì $x$ là số nguyên và $x > mid$, suy ra $x \ge mid + 1$, nên $l = mid + 1$.
- Nếu `NO` ($mid \ge x$): suy ra $x \le mid$, nên $r = mid$.

Khi $l = r$, miền chỉ còn một giá trị, đó chính là $x$.

### Thuật toán

1. Đặt $l = 1$, $r = 10^9$.
2. Trong khi $l < r$:
   - $mid = \lfloor(l + r) / 2\rfloor$. Hỏi "? $mid$".
   - Nếu `YES`: $l = mid + 1$.
   - Nếu `NO`: $r = mid$.
3. Xuất "! $l$".

### Ví dụ minh họa

Để dễ theo dõi, giả sử miền tìm kiếm là $[1, 16]$ và $x = 7$ (trùng ví dụ đề bài):

| Bước | $l$ | $r$ | $mid$ | Truy vấn | Trả lời | Miền mới |
|------|-----|-----|-------|----------|---------|----------|
| 1 | 1 | 16 | 8 | ? 8 | NO | $[1, 8]$ |
| 2 | 1 | 8 | 4 | ? 4 | YES | $[5, 8]$ |
| 3 | 5 | 8 | 6 | ? 6 | YES | $[7, 8]$ |
| 4 | 7 | 8 | 7 | ? 7 | NO | $[7, 7]$ |

Kết quả: $x = 7$.

## Độ phức tạp

- **Thời gian:** $O(\log(10^9)) = 30$ truy vấn
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Hidden%20Integer.cpp)
