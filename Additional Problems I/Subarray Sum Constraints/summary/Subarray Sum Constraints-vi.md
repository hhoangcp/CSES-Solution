# Subarray Sum Constraints

**CSES ID:** 3294  
**Đề bài gốc:** https://cses.fi/problemset/task/3294  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Xây mảng $x_1,\ldots,x_n$ thỏa $m$ ràng buộc dạng $\sum_{i=l}^{r} x_i = s$, hoặc báo không có.

## Đầu vào
Hai số nguyên $n$ và $m$, rồi $m$ dòng $(l,r,s)$.

## Kết quả
In `YES` và mảng hợp lệ bất kỳ với $|x_i| \le 10^{15}$, hoặc chỉ in `NO`.

## Ràng buộc
- $1 \le n \le 5000$
- $0 \le m \le 2 \cdot 10^5$
- $1 \le l \le r \le n$
- $-10^9 \le s \le 10^9$
