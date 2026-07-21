# Lines and Queries II

**CSES ID:** 3430  
**Đề bài gốc:** https://cses.fi/problemset/task/3430  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Tương tự bài trước, quản lý các đường $y = ax+b$ và trả lời truy vấn tìm max tại vị trí, nhưng mỗi đường chỉ hoạt động trong một khoảng đã cho $[l,r]$. Truy vấn kiểu 2 trả về giá trị lớn nhất trong các đường đang hoạt động tại $x$, hoặc `NO` nếu không có đường nào.

## Đầu vào
Dòng đầu là số nguyên $n$, sau đó $n$ dòng dạng "1 $a$ $b$ $l$ $r$" (thêm đường hoạt động trên $[l,r]$) hoặc "2 $x$" (hỏi tại $x$).

## Kết quả
Với mỗi truy vấn kiểu 2 in ra giá trị lớn nhất, hoặc `NO` nếu không có đường hoạt động.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $-10^9 \le a, b \le 10^9$
- $0 \le x \le 10^5$
- $0 \le l \le r \le 10^5$
