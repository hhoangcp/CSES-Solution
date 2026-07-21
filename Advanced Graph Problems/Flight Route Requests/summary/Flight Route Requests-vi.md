# Flight Route Requests

**CSES ID:** 1699  
**Đề bài gốc:** https://cses.fi/problemset/task/1699  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ thành phố có sân bay nhưng chưa có chuyến bay nào. Bạn nhận $m$ yêu cầu duy nhất dạng "phải có cách đi từ $a$ đến $b$". Xác định số chuyến bay một chiều ít nhất cần thêm để đáp ứng mọi yêu cầu.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng $a,b$ nghĩa là phải có đường đi từ $a$ đến $b$; các yêu cầu là duy nhất.

## Kết quả
In ra một số nguyên: số chuyến bay một chiều ít nhất cần thêm.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
