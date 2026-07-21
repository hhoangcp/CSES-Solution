# Các Tuyến Đường Trò Chơi

**CSES ID:** 1681  
**Đề bài gốc:** https://cses.fi/problemset/task/1681  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị có hướng không chu trình gồm $n$ cấp và $m$ máy dịch chuyển, đếm số đường đi khác nhau từ cấp $1$ đến cấp $n$, modulo $10^9+7$.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh có hướng $a \to b$ (không có chu trình).

## Kết quả
Một số nguyên: số đường đi modulo $10^9+7$.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
