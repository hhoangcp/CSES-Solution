# Minimum Cost Pairs

**CSES ID:** 3402  
**Đề bài gốc:** https://cses.fi/problemset/task/3402  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ số nguyên, lập đúng $k$ cặp không giao nhau; chi phí cặp $(a,b)$ là $|a-b|$. Với mỗi $k=1,\dots,\lfloor n/2\rfloor$ tìm tổng chi phí ghép cặp nhỏ nhất.

## Đầu vào
Dòng đầu: $n$. Dòng tiếp theo: $n$ số nguyên $x_1,\dots,x_n$.

## Kết quả
In $\lfloor n/2 \rfloor$ số nguyên: chi phí nhỏ nhất ứng với $k=1,\dots,\lfloor n/2\rfloor$.

## Ràng buộc
- $2 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
