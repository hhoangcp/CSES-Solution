# Điều Tra

**CSES ID:** 1202  
**Đề bài gốc:** https://cses.fi/problemset/task/1202  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị có hướng có trọng số, đi từ thành phố $1$ đến thành phố $n$. Báo cáo bốn giá trị: giá tuyến nhỏ nhất, số tuyến có giá đó (mod $10^9+7$), số chuyến ít nhất trong các tuyến đó, và số chuyến nhiều nhất.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh có hướng $a \to b$ với giá $c$.

## Kết quả
Bốn số nguyên: giá nhỏ nhất, số tuyến mod $10^9+7$, số chuyến ít nhất, số chuyến nhiều nhất.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
