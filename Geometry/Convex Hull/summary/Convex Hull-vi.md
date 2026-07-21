# Convex Hull

**CSES ID:** 2195  
**Đề bài gốc:** https://cses.fi/problemset/task/2195  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ điểm phân biệt trên mặt phẳng, cần tìm tất cả các điểm nằm trên biên của bao lồi của chúng. Diện tích bao lồi được giả sử dương.

## Đầu vào
Dòng đầu là số nguyên $n$, sau đó $n$ dòng mỗi dòng hai số nguyên $x, y$ cho tọa độ một điểm.

## Kết quả
Đầu tiên in số lượng $k$ điểm trên bao lồi, sau đó $k$ dòng liệt kê các điểm đó theo thứ tự bất kỳ.

## Ràng buộc
- $3 \le n \le 2 \cdot 10^5$
- $-10^9 \le x, y \le 10^9$
