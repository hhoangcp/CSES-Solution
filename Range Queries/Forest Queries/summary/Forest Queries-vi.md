# Forest Queries

**CSES ID:** 1652  
**Đề bài gốc:** https://cses.fi/problemset/task/1652  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn được cho lưới $n \times n$ biểu diễn khu rừng, mỗi ô trống hoặc có cây. Với mỗi truy vấn hình chữ nhật, hãy báo cáo số cây bên trong hình chữ nhật đó.

## Đầu vào
Dòng đầu chứa kích thước lưới $n$ và số truy vấn $q$. Tiếp theo $n$ dòng mỗi dòng $n$ ký tự (`.` trống, `*` cây) mô tả lưới. Cuối cùng $q$ dòng mỗi dòng cho bốn góc hình chữ nhật $y_1, x_1, y_2, x_2$.

## Kết quả
In số cây trong mỗi hình chữ nhật được truy vấn.

## Ràng buộc
- $1 \le n \le 1000$
- $1 \le q \le 2 \cdot 10^5$
- $1 \le y_1 \le y_2 \le n$
- $1 \le x_1 \le x_2 \le n$
