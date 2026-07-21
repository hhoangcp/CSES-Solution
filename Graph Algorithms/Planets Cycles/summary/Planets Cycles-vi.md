# Chu Trình Hành Tinh

**CSES ID:** 1751  
**Đề bài gốc:** https://cses.fi/problemset/task/1751  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ hành tinh, mỗi hành tinh có một đích dịch chuyển $t_i$. Bắt đầu từ mỗi hành tinh, đếm số lần dịch chuyển trước khi hạ cánh xuống một hành tinh đã ghé.

## Đầu vào
$n$, rồi $n$ số $t_1, \dots, t_n$ (có thể $t_i=i$).

## Kết quả
$n$ số nguyên, số lần dịch chuyển tương ứng với từng hành tinh xuất phát.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le t_i \le n$
