# K Subset Sums II

**CSES ID:** 3109  
**Đề bài gốc:** https://cses.fi/problemset/task/3109  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ số nguyên, chỉ xét $\binom{n}{m}$ tập con có đúng $m$ phần tử và tổng của chúng. In ra $k$ tổng nhỏ nhất theo thứ tự tăng dần.

## Đầu vào
Dòng đầu: $n$, $m$ và $k$. Dòng tiếp theo: $n$ số nguyên $x_1,\dots,x_n$.

## Kết quả
In $k$ số nguyên: $k$ tổng tập con $m$ phần tử nhỏ nhất theo thứ tự tăng dần.

## Ràng buộc
- $1 \le m < n \le 2 \cdot 10^5$
- $1 \le k \le \min\left(\binom{n}{m}, 2 \cdot 10^5\right)$
- $-10^9 \le x_i \le 10^9$
