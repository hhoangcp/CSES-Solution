# Coin Grid

**CSES ID:** 1709  
**Đề bài gốc:** https://cses.fi/problemset/task/1709  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Lưới $n \times n$ có ô trống hoặc chứa đồng xu. Mỗi bước có thể dọn sạch đồng xu trên một hàng hoặc một cột. Tìm số bước nhỏ nhất để làm rỗng lưới.

## Đầu vào
Dòng đầu: $n$. Sau đó $n$ dòng mỗi dòng $n$ ký tự `.` (trống) hoặc `o` (đồng xu).

## Kết quả
Đầu tiên in số bước tối thiểu $k$, sau đó $k$ dòng mỗi dòng ghi `1` (hàng) hoặc `2` (cột) rồi đến chỉ số. Bất kỳ lời giải hợp lệ đều được.

## Ràng buộc
- $1 \le n \le 100$
