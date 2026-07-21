# Line Segment Intersection

**CSES ID:** 2190  
**Đề bài gốc:** https://cses.fi/problemset/task/2190  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Với mỗi trong $t$ test, cho hai đoạn thẳng trên mặt phẳng, cần quyết định xem chúng có chung ít nhất một điểm hay không, bao gồm đầu mút và trường hợp chồng nhau thẳng hàng.

## Đầu vào
Dòng đầu là số nguyên $t$, sau đó $t$ dòng mỗi dòng tám số nguyên $x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4$ mô tả hai đoạn.

## Kết quả
Với mỗi test in "YES" nếu hai đoạn cắt nhau và "NO" nếu không.

## Ràng buộc
- $1 \le t \le 10^5$
- $-10^9 \le x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4 \le 10^9$
- $(x_1,y_1) \neq (x_2,y_2)$
- $(x_3,y_3) \neq (x_4,y_4)$
