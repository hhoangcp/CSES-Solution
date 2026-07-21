# Subarray Sum Queries II

**CSES ID:** 3226  
**Đề bài gốc:** https://cses.fi/problemset/task/3226  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn được cho mảng và nhiều truy vấn; mỗi truy vấn hỏi tổng mảng con liên tiếp lớn nhất nằm hoàn toàn trong đoạn $[a,b]$. Mảng con rỗng (tổng 0) được phép.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê giá trị mảng. $q$ dòng tiếp theo mỗi dòng cho hai đầu mút $a$ và $b$.

## Kết quả
In tổng mảng con lớn nhất trong $[a,b]$ cho mỗi truy vấn.

## Ràng buộc
- $1 \le n, q\le 2 \cdot 10^5$
- $-10^9 \le x_i \le 10^9$
- $1 \le a \le b \le n$
