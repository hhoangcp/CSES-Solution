# Nested Ranges Count

**CSES ID:** 2169  
**Đề bài gốc:** https://cses.fi/problemset/task/2169  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ đoạn, với mỗi đoạn đếm số đoạn khác mà nó chứa và số đoạn khác chứa nó. Đoạn $[a,b]$ chứa $[c,d]$ nếu $a\le c$ và $d\le b$.

## Đầu vào
Dòng đầu: số nguyên $n$. Sau đó $n$ dòng, mỗi dòng hai số nguyên $x$ và $y$ xác định $[x,y]$. Không có hai đoạn giống nhau.

## Kết quả
In một dòng $n$ số: số đoạn khác mà đoạn $i$ chứa. Dòng thứ hai: số đoạn khác chứa đoạn $i$.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x < y \le 10^9$
