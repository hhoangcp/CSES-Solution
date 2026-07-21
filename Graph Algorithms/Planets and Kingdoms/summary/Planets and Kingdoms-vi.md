# Hành Tinh và Vương Quốc

**CSES ID:** 1683  
**Đề bài gốc:** https://cses.fi/problemset/task/1683  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Đồ thị có hướng gồm $n$ hành tinh và $m$ máy dịch chuyển. Hai hành tinh cùng vương quốc iff mỗi đỉnh đến được đỉnh kia. Gán nhãn vương quốc cho mỗi hành tinh.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh có hướng $a \to b$.

## Kết quả
Số vương quốc $k$, rồi $n$ nhãn trong $[1, k]$.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
