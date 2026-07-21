# Traffic Lights

**CSES ID:** 1163  
**Đề bài gốc:** https://cses.fi/problemset/task/1163  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một con đường dài $x$ (vị trí 0 đến $x$) ban đầu không có đèn. Đèn được thêm lần lượt tại các vị trí phân biệt, sau mỗi lần thêm phải báo đoạn dài nhất không có đèn.

## Đầu vào
Dòng đầu: hai số nguyên $x$ và $n$. Dòng tiếp: $n$ số nguyên $p_1,\ldots,p_n$ (vị trí phân biệt, nghiêm ngặt giữa 0 và $x$).

## Kết quả
In độ dài đoạn không đèn dài nhất sau mỗi lần thêm.

## Ràng buộc
- $1 \le x \le 10^9$
- $1 \le n \le 2 \cdot 10^5$
- $0 < p_i < x$
