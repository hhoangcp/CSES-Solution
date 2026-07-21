# Lines and Queries I

**CSES ID:** 3429  
**Đề bài gốc:** https://cses.fi/problemset/task/3429  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Quản lý một tập động các đường thẳng dạng $y = ax + b$ và xử lý hai loại truy vấn: thêm một đường mới, và tại vị trí $x$ cho trước tìm giá trị lớn nhất mà bất kỳ đường đã thêm đạt tới.

## Đầu vào
Dòng đầu là số nguyên $n$, sau đó $n$ dòng dạng "1 $a$ $b$" (thêm đường $ax+b$) hoặc "2 $x$" (hỏi tại $x$). Truy vấn đầu tiên kiểu 1.

## Kết quả
Với mỗi truy vấn kiểu 2 in ra giá trị lớn nhất tại vị trí đó.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $-10^9 \le a, b \le 10^9$
- $0 \le x \le 10^5$
