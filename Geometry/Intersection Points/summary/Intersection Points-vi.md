# Intersection Points

**CSES ID:** 1740  
**Đề bài gốc:** https://cses.fi/problemset/task/1740  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ đoạn thẳng, mỗi đoạn chỉ ngang hoặc dọc. Đếm số điểm giao nhau khác nhau giữa các đoạn. Giả sử các đoạn song song không trùng nhau và không có đầu mút nào là điểm giao.

## Đầu vào
Dòng đầu là số nguyên $n$, sau đó $n$ dòng mỗi dòng bốn số nguyên $x_1, y_1, x_2, y_2$ mô tả hai đầu mút của một đoạn.

## Kết quả
In ra tổng số điểm giao nhau.

## Ràng buộc
- $1 \le n \le 10^5$
- $-10^6 \le x_1 \le x_2 \le 10^6$
- $-10^6 \le y_1 \le y_2 \le 10^6$
- $(x_1,y_1) \neq (x_2,y_2)$
