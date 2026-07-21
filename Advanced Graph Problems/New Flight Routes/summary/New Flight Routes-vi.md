# New Flight Routes

**CSES ID:** 1685  
**Đề bài gốc:** https://cses.fi/problemset/task/1685  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một đồ thị có hướng gồm $n$ thành phố và $m$ chuyến bay một chiều, thêm số chuyến bay một chiều ít nhất sao cho đồ thị thu được liên thông mạnh.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng một chuyến bay một chiều $a \to b$.

## Kết quả
In ra số chuyến bay mới ít nhất $k$, rồi $k$ dòng mô tả các chuyến bay mới; bất kỳ lời giải hợp lệ nào cũng được.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
