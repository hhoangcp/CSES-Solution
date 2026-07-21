# Network Breakdown

**CSES ID:** 1677  
**Đề bài gốc:** https://cses.fi/problemset/task/1677  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một mạng gồm $n$ máy tính và $m$ liên kết được xử lý qua thời gian khi $k$ liên kết chỉ định bị hỏng lần lượt (không được sửa). Sau mỗi lần hỏng, báo số thành phần liên thông của đồ thị còn lại.

## Đầu vào
Dòng đầu: $n$, $m$, $k$. Sau đó $m$ dòng liên kết ban đầu $a,b$ (đồ thị đơn). Rồi $k$ dòng nêu liên kết bị hỏng tại mỗi bước.

## Kết quả
In ra, sau mỗi lần hỏng, số thành phần (cách nhau bởi khoảng trắng theo thứ tự).

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le k \le m$
- $1 \le a, b \le n$
