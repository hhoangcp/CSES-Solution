# Polynomial Queries

**CSES ID:** 1736  
**Đề bài gốc:** https://cses.fi/problemset/task/1736  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn duy trì mảng với hai thao tác: cập nhật đoạn cộng $1,2,3,\dots$ (cấp số cộng công sai 1) vào các vị trí $[a,b]$, và truy vấn tổng đoạn.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê mảng ban đầu. $q$ dòng truy vấn có dạng "1 $a$ $b$" (cộng cấp số) hoặc "2 $a$ $b$" (tổng đoạn).

## Kết quả
In kết quả mỗi truy vấn tính tổng.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le t_i \le 10^6$
- $1 \le a \le b \le n$
