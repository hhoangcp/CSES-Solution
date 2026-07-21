# Sliding Window Mex

**CSES ID:** 3219  
**Đề bài gốc:** https://cses.fi/problemset/task/3219  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho mảng, in ra mex của mỗi cửa sổ trượt kích thước $k$, trong đó mex là số nguyên không âm nhỏ nhất không có mặt trong cửa sổ.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: $n$ phần tử $x_1,\dots,x_n$.

## Kết quả
In ra $n-k+1$ giá trị, mex mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 2 \cdot 10^5$
- $0 \le x_i \le 10^9$
