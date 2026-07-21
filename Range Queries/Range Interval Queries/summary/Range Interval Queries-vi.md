# Range Interval Queries

**CSES ID:** 3163  
**Đề bài gốc:** https://cses.fi/problemset/task/3163  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn được cho mảng $n$ số nguyên và phải trả lời truy vấn đếm số chỉ số $i$ nằm trong đoạn vị trí $[a,b]$ đồng thời có giá trị thuộc đoạn giá trị $[c,d]$.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê giá trị mảng. $q$ dòng tiếp theo mỗi dòng cho bốn số nguyên $a$, $b$, $c$, $d$.

## Kết quả
In số đếm cho mỗi truy vấn.

## Ràng buộc
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le a \le b \le n$
- $1 \le c \le d \le 10^9$
