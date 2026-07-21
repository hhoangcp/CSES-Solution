# Apartments

**CSES ID:** 1084  
**Đề bài gốc:** https://cses.fi/problemset/task/1084  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho kích thước mong muốn của $n$ người thuê và kích thước thực tế của $m$ căn hộ, cùng sai số $k$. Mỗi người chấp nhận căn hộ có kích thước chênh lệch không quá $k$ so với mong muốn. Mục tiêu là tối đa số người nhận được căn hộ.

## Đầu vào
Dòng đầu: ba số nguyên $n$, $m$, $k$. Dòng tiếp: $n$ kích thước mong muốn $a_1,\ldots,a_n$. Dòng cuối: $m$ kích thước căn hộ $b_1,\ldots,b_m$.

## Kết quả
In một số nguyên: số người nhận được căn hộ nhiều nhất.

## Ràng buộc
- $1 \le n, m \le 2 \cdot 10^5$
- $0 \le k \le 10^9$
- $1 \le a_i, b_i \le 10^9$
