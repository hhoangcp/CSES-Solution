# K Subset Xors

**CSES ID:** 3192  
**Đề bài gốc:** https://cses.fi/problemset/task/3192  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một mảng số nguyên, xét xor của mọi tập con (tập rỗng cho xor $0$). Cần báo cáo $k$ giá trị nhỏ nhất trong các xor tập con này theo thứ tự tăng dần.

## Đầu vào
Dòng đầu: hai số nguyên $n$ và $k$. Dòng sau: $n$ số nguyên $x_1,\dots,x_n$.

## Kết quả
In $k$ số nguyên: $k$ giá trị xor tập con nhỏ nhất theo thứ tự tăng dần.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le k \le \min(2^n, 2 \cdot 10^5)$
- $0 \le x_i \le 10^9$
