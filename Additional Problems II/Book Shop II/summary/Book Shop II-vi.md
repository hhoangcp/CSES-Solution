# Book Shop II

**CSES ID:** 1159  
**Đề bài gốc:** https://cses.fi/problemset/task/1159  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cửa hàng bán $n$ loại sách; mỗi loại biết giá, số trang và số bản sao. Chi tiêu không quá $x$ để tối đa tổng số trang, có thể mua nhiều bản sao cùng loại.

## Đầu vào
Dòng đầu: $n$ và $x$. Ba dòng tiếp theo lần lượt là giá $h_i$, số trang $s_i$ và số bản sao $k_i$ của $n$ loại sách.

## Kết quả
Một số nguyên: tổng số trang lớn nhất đạt được.

## Ràng buộc
- $1 \le n \le 100$
- $1 \le x \le 10^5$
- $1 \le h_i, s_i, k_i \le 1000$
