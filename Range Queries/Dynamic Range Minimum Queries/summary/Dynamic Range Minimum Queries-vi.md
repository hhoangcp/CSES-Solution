# Dynamic Range Minimum Queries

**CSES ID:** 1649  
**Đề bài gốc:** https://cses.fi/problemset/task/1649  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn duy trì mảng với cập nhật một phần tử và truy vấn giá trị nhỏ nhất đoạn. Mỗi cập nhật gán một vị trí giá trị mới; mỗi truy vấn hỏi giá trị nhỏ nhất trong đoạn liên tiếp.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai chứa $n$ giá trị mảng. $q$ dòng tiếp theo có dạng "$1$ $k$ $u$" (gán vị trí $k$) hoặc "$2$ $a$ $b$" (truy vấn min đoạn).

## Kết quả
In kết quả mỗi truy vấn loại 2.

## Ràng buộc
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
