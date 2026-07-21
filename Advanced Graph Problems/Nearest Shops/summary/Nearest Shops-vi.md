# Nearest Shops

**CSES ID:** 3303  
**Đề bài gốc:** https://cses.fi/problemset/task/3303  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị vô hướng gồm $n$ thành phố và $m$ đường hai chiều, có $k$ thành phố có cửa hàng anime. Với mỗi thành phố, tìm khoảng cách ngắn nhất đến một thành phố khác cũng có cửa hàng (cửa hàng nội thành nếu có không được tính). In ra $-1$ cho các thành phố không có cửa hàng đạt được.

## Đầu vào
Dòng đầu: $n$, $m$, $k$. Dòng hai: $k$ thành phố có cửa hàng. Sau đó $m$ đường, mỗi đường là $a,b$.

## Kết quả
In ra $n$ số nguyên: với mỗi thành phố khoảng cách nhỏ nhất đến một thành phố cửa hàng khác, hoặc $-1$ nếu không có.

## Ràng buộc
- $1 \le k \le n \le 10^5$
- $0 \le m \le 2 \cdot 10^5$
