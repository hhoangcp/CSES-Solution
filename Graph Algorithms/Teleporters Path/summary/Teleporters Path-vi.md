# Đường Đi Máy Dịch Chuyển

**CSES ID:** 1693  
**Đề bài gốc:** https://cses.fi/problemset/task/1693  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị có hướng, tìm đường đi từ cấp $1$ đến cấp $n$ đi qua mỗi máy dịch chuyển đúng một lần, hoặc thông báo không khả thi.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh có hướng $a \to b$ (các cặp phân biệt).

## Kết quả
$m+1$ số nguyên: trình tự ghé các cấp, hoặc `IMPOSSIBLE`.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
