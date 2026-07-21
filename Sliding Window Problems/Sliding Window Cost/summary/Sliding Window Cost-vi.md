# Sliding Window Cost

**CSES ID:** 1077  
**Đề bài gốc:** https://cses.fi/problemset/task/1077  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một mảng, với mỗi cửa sổ $k$ phần tử liên tiếp, bạn có thể tăng hoặc giảm mỗi giá trị với chi phí bằng độ lệch, sao cho mọi phần tử trong cửa sổ bằng nhau với tổng chi phí nhỏ nhất.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: $n$ phần tử $x_1,\dots,x_n$.

## Kết quả
In ra $n-k+1$ giá trị, chi phí nhỏ nhất mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
