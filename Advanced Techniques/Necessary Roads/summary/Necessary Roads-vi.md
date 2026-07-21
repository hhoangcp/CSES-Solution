# Necessary Roads

**CSES ID:** 2076  
**Đề bài gốc:** https://cses.fi/problemset/task/2076  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị vô hướng liên thông có $n$ thành phố và $m$ con đường, một con đường là cần thiết nếu xóa nó làm đôi thành phố nào đó mất kết nối. Tìm tất cả con đường cần thiết.

## Đầu vào
Dòng đầu: $n,m$. Sau đó $m$ dòng, mỗi dòng hai số nguyên $a,b$ (một con đường). Mỗi cặp nhiều nhất một đường, không có khuyên.

## Kết quả
In số $k$ con đường cần thiết rồi in $k$ dòng mô tả các con đường đó theo thứ tự bất kỳ.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
