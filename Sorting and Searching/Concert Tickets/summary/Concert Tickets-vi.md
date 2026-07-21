# Concert Tickets

**CSES ID:** 1091  
**Đề bài gốc:** https://cses.fi/problemset/task/1091  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ vé với giá cho trước và $m$ khách đến theo thứ tự, mỗi người đưa ra mức giá tối đa chấp nhận. Khách nhận vé đắt nhất không vượt mức đó, vé sau đó bị loại.

## Đầu vào
Dòng đầu: hai số nguyên $n$ và $m$. Dòng tiếp: $n$ giá vé $h_1,\ldots,h_n$. Dòng cuối: $m$ mức giá tối đa $t_1,\ldots,t_m$.

## Kết quả
Với mỗi khách, in giá vé phải trả, hoặc $-1$ nếu không có vé phù hợp.

## Ràng buộc
- $1 \le n, m \le 2 \cdot 10^5$
- $1 \le h_i, t_i \le 10^9$
