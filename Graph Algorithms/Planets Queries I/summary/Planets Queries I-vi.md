# Truy Vấn Hành Tinh I

**CSES ID:** 1750  
**Đề bài gốc:** https://cses.fi/problemset/task/1750  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Mỗi trong $n$ hành tinh có máy dịch chuyển đến hành tinh $t_i$. Trả lời $q$ truy vấn: bắt đầu tại hành tinh $x$ và đi $k$ lần dịch chuyển, hạ cánh ở hành tinh nào?

## Đầu vào
$n$ và $q$, rồi $n$ đích $t_i$, rồi $q$ dòng mỗi dòng $x, k$.

## Kết quả
Một chỉ số hành tinh cho mỗi truy vấn.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le t_i \le n$
- $1 \le x \le n$
- $0 \le k \le 10^9$
