# Điểm Cao

**CSES ID:** 1673  
**Đề bài gốc:** https://cses.fi/problemset/task/1673  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Đồ thị có hướng có trọng số gồm $n$ phòng và $m$ đường hầm một chiều; mỗi đường hầm cộng trọng số $x$ (có thể âm) vào điểm và có thể đi lại. Đi từ phòng $1$ đến phòng $n$ để tối đa điểm; in $-1$ nếu điểm có thể lớn tùy ý.

## Đầu vào
$n$ và $m$, rồi $m$ dòng cho cạnh $a \to b$ với trọng số $x$.

## Kết quả
Điểm tối đa có thể đạt, hoặc $-1$ nếu không bị chặn.

## Ràng buộc
- $1 \le n \le 2500$
- $1 \le m \le 5000$
- $1 \le a,b \le n$
- $-10^9 \le x \le 10^9$
