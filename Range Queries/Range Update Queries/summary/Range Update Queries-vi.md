# Range Update Queries

**CSES ID:** 1651  
**Đề bài gốc:** https://cses.fi/problemset/task/1651  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn duy trì mảng với cập nhật cộng đoạn (cộng $u$ vào mọi phần tử trong $[a,b]$) và truy vấn điểm (đọc giá trị tại vị trí $k$).

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê giá trị mảng. $q$ dòng tiếp theo có dạng "$1$ $a$ $b$ $u$" (cộng đoạn) hoặc "$2$ $k$" (đọc vị trí $k$).

## Kết quả
In kết quả mỗi truy vấn loại 2.

## Ràng buộc
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
