# Range Updates and Sums

**CSES ID:** 1735  
**Đề bài gốc:** https://cses.fi/problemset/task/1735  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn duy trì mảng với ba thao tác: cộng hằng số vào mọi phần tử đoạn, gán hằng số cho mọi phần tử đoạn, và truy vấn tổng đoạn.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê mảng ban đầu. $q$ dòng tiếp theo có dạng "1 $a$ $b$ $x$" (cộng đoạn), "2 $a$ $b$ $x$" (gán đoạn), hoặc "3 $a$ $b$" (tổng đoạn).

## Kết quả
In kết quả mỗi truy vấn tính tổng.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le t_i, x \le 10^6$
- $1 \le a \le b \le n$
