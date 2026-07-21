# Nested Ranges Check

**CSES ID:** 2168  
**Đề bài gốc:** https://cses.fi/problemset/task/2168  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ đoạn, với mỗi đoạn báo xem nó có chứa đoạn khác và có bị đoạn khác chứa hay không. Đoạn $[a,b]$ chứa $[c,d]$ nếu $a\le c$ và $d\le b$.

## Đầu vào
Dòng đầu: số nguyên $n$. Sau đó $n$ dòng, mỗi dòng hai số nguyên $x$ và $y$ xác định $[x,y]$. Không có hai đoạn giống nhau.

## Kết quả
In một dòng $n$ giá trị (1/0): đoạn $i$ có chứa đoạn khác không. Dòng thứ hai: đoạn $i$ có bị đoạn khác chứa không.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x < y \le 10^9$
