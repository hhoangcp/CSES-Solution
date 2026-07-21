# Inverse Inversions

**CSES ID:** 2214  
**Đề bài gốc:** https://cses.fi/problemset/task/2214  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Xây dựng một hoán vị của $1,2,\dots,n$ có đúng $k$ nghịch đảo, trong đó nghịch đảo là cặp vị trí $a<b$ mà $p_a>p_b$. Cần xuất ra một hoán vị bất kỳ thỏa mãn.

## Đầu vào
Một dòng chứa hai số nguyên $n$ và $k$.

## Kết quả
In một hoán vị của $1,\dots,n$ có đúng $k$ nghịch đảo.

## Ràng buộc
- $1 \le n \le 10^6$
- $0 \le k \le \frac{n(n-1)}{2}$
