# Necessary Cities

**CSES ID:** 2077  
**Đề bài gốc:** https://cses.fi/problemset/task/2077  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị vô hướng liên thông có $n$ thành phố và $m$ con đường, một thành phố là cần thiết nếu xóa nó (cùng các đường kề) làm đôi thành phố nào đó mất kết nối. Tìm tất cả thành phố cần thiết.

## Đầu vào
Dòng đầu: $n,m$. Sau đó $m$ dòng, mỗi dòng hai số nguyên $a,b$ (một con đường). Mỗi cặp nhiều nhất một đường, không có khuyên.

## Kết quả
In số $k$ thành phố cần thiết rồi in danh sách $k$ thành phố theo thứ tự bất kỳ.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
