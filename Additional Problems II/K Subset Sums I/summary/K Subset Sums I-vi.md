# K Subset Sums I

**CSES ID:** 3108  
**Đề bài gốc:** https://cses.fi/problemset/task/3108  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ số nguyên, xét tổng của tất cả $2^n$ tập con (gồm tập rỗng tổng 0). In ra $k$ tổng tập con nhỏ nhất theo thứ tự tăng dần.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng tiếp theo: $n$ số nguyên $x_1,\dots,x_n$.

## Kết quả
In $k$ số nguyên: $k$ tổng tập con nhỏ nhất theo thứ tự tăng dần.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le k \le \min(2^n, 2 \cdot 10^5)$
- $-10^9 \le x_i \le 10^9$
