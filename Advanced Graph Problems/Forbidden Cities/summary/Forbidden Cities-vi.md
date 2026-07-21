# Forbidden Cities

**CSES ID:** 1705  
**Đề bài gốc:** https://cses.fi/problemset/task/1705  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong một đồ thị vô hướng liên thông, xử lý $q$ truy vấn, mỗi truy vấn hỏi có thể đi từ thành phố $a$ đến thành phố $b$ mà không đi qua thành phố $c$ hay không.

## Đầu vào
Dòng đầu: $n$, $m$, $q$. Sau đó $m$ đường hai chiều, mỗi đường là $a,b$. Rồi $q$ dòng truy vấn, mỗi dòng $a,b,c$. Đồ thị liên thông.

## Kết quả
Với mỗi truy vấn in ra `YES` nếu tồn tại đường đi như vậy, ngược lại in `NO`.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le q \le 10^5$
- $1 \le a, b, c \le n$
