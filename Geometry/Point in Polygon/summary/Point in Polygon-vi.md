# Point in Polygon

**CSES ID:** 2192  
**Đề bài gốc:** https://cses.fi/problemset/task/2192  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một đa giác đơn có $n$ đỉnh và danh sách $m$ điểm truy vấn. Với mỗi điểm, phân loại nó nằm trong đa giác, ngoài đa giác hay đúng trên biên.

## Đầu vào
Dòng đầu hai số nguyên $n$ và $m$, sau đó $n$ dòng mỗi dòng cho một đỉnh $(x_i, y_i)$ của đa giác, rồi $m$ dòng mỗi dòng cho một điểm truy vấn $(x, y)$.

## Kết quả
Với mỗi điểm truy vấn in ra "INSIDE", "OUTSIDE" hoặc "BOUNDARY".

## Ràng buộc
- $3 \le n \le 1000$
- $1 \le m \le 1000$
- $-10^9 \le x_i, y_i \le 10^9$
- $-10^9 \le x, y \le 10^9$
