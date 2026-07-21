# Truy Vấn Hành Tinh II

**CSES ID:** 1160  
**Đề bài gốc:** https://cses.fi/problemset/task/1160  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Mỗi trong $n$ hành tinh dịch chuyển đến $t_i$. Trả lời $q$ truy vấn: từ hành tinh $a$, số lần dịch chuyển tối thiểu để lần đầu đến hành tinh $b$, hoặc $-1$ nếu không đến được.

## Đầu vào
$n$ và $q$, rồi $n$ đích $t_i$, rồi $q$ dòng mỗi dòng $a, b$.

## Kết quả
Số lần dịch chuyển tối thiểu cho mỗi truy vấn, hoặc $-1$.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a,b \le n$
