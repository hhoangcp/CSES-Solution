# Prefix Sum Queries

**CSES ID:** 2166  
**Đề bài gốc:** https://cses.fi/problemset/task/2166  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn duy trì mảng số nguyên (có thể âm) với cập nhật một phần tử. Mỗi truy vấn trên $[a,b]$ hỏi tổng tiền tố lớn nhất của mảng con $x_a,\dots,x_b$, trong đó tiền tố rỗng (tổng 0) được phép.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê các giá trị mảng. $q$ dòng tiếp theo có dạng "$1$ $k$ $u$" (gán vị trí $k$) hoặc "$2$ $a$ $b$" (tổng tiền tố lớn nhất trong $[a,b]$).

## Kết quả
In kết quả mỗi truy vấn loại 2.

## Ràng buộc
- $1 \le n,q \le 2 \cdot 10^5$
- $-10^9 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
