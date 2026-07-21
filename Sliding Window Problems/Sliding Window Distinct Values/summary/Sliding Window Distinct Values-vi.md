# Sliding Window Distinct Values

**CSES ID:** 3222  
**Đề bài gốc:** https://cses.fi/problemset/task/3222  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho mảng $n$ số nguyên, đếm số giá trị phân biệt xuất hiện trong mỗi cửa sổ trượt kích thước $k$ khi dịch từ trái sang phải.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: $n$ phần tử $x_1,\dots,x_n$.

## Kết quả
In ra $n-k+1$ giá trị, số giá trị phân biệt mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
