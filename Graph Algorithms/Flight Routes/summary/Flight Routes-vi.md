# Các Tuyến Bay

**CSES ID:** 1196  
**Đề bài gốc:** https://cses.fi/problemset/task/1196  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị có hướng có trọng số, liệt kê giá của $k$ tuyến rẻ nhất từ thành phố $1$ đến thành phố $n$, tính cả các tuyến trùng giá. Có thể đi lại thành phố.

## Đầu vào
$n$, $m$ và $k$, rồi $m$ cạnh có hướng $a \to b$ với giá $c$.

## Kết quả
$k$ số nguyên: giá của $k$ tuyến rẻ nhất theo thứ tự không giảm.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
- $1 \le k \le 10$
