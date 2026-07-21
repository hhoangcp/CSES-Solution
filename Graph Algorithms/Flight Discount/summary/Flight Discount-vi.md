# Giảm Giá Chuyến Bay

**CSES ID:** 1195  
**Đề bài gốc:** https://cses.fi/problemset/task/1195  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị có hướng có trọng số, tìm đường rẻ nhất từ thành phố $1$ đến thành phố $n$. Có thể dùng một phiếu giảm một nửa (làm tròn xuống) giá của đúng một cạnh trên đường đi.

## Đầu vào
$n$ và $m$, rồi $m$ dòng mỗi dòng cho chuyến bay có hướng $a \to b$ với giá $c$.

## Kết quả
Một số nguyên: tổng giá nhỏ nhất đạt được khi dùng phiếu một lần.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
