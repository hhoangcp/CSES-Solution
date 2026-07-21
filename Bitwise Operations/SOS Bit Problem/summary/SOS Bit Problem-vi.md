# SOS Bit Problem

**CSES ID:** 1654  
**Đề bài gốc:** https://cses.fi/problemset/task/1654  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một danh sách số nguyên, với mỗi phần tử $x$ hãy tính ba số lượng: bao nhiêu phần tử $y$ thoả $x \mid y = x$, bao nhiêu thoả $x \wedge y = x$, và bao nhiêu thoả $x \wedge y \neq 0$.

## Đầu vào
Dòng đầu: số nguyên $n$. Dòng sau: $n$ số nguyên $x_1,\dots,x_n$.

## Kết quả
$n$ dòng, mỗi dòng chứa ba số lượng tương ứng với phần tử đó.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^6$
