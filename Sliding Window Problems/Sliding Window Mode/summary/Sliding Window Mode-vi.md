# Sliding Window Mode

**CSES ID:** 3224  
**Đề bài gốc:** https://cses.fi/problemset/task/3224  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho mảng, in ra mode của mỗi cửa sổ trượt kích thước $k$, tức giá trị xuất hiện nhiều lần nhất trong cửa sổ; nếu hòa thì chọn giá trị nhỏ nhất.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: $n$ phần tử $x_1,\dots,x_n$.

## Kết quả
In ra $n-k+1$ giá trị, mode mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
