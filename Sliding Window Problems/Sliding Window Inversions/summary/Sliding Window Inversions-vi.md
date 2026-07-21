# Sliding Window Inversions

**CSES ID:** 3223  
**Đề bài gốc:** https://cses.fi/problemset/task/3223  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho mảng, đếm số nghịch đảo trong mỗi cửa sổ trượt kích thước $k$, trong đó nghịch đảo là cặp vị trí $i<j$ cùng cửa sổ mà $x_i > x_j$.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: $n$ phần tử $x_1,\dots,x_n$.

## Kết quả
In ra $n-k+1$ giá trị, số nghịch đảo mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
