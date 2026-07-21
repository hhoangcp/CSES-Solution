# Missing Coin Sum Queries

**CSES ID:** 2184  
**Đề bài gốc:** https://cses.fi/problemset/task/2184  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn có $n$ đồng xu giá trị nguyên dương. Với mỗi truy vấn trên một mảng con liên tiếp, hãy tìm tổng dương nhỏ nhất không thể tạo được từ một tập con các đồng xu đó.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê giá trị đồng xu. $q$ dòng tiếp theo mỗi dòng cho hai chỉ số $a$ và $b$ giới hạn mảng con dùng được.

## Kết quả
In tổng dương nhỏ nhất không thể tạo cho mỗi truy vấn.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le a \le b \le n$
