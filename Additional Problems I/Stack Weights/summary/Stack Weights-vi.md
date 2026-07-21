# Stack Weights

**CSES ID:** 2425  
**Đề bài gốc:** https://cses.fi/problemset/task/2425  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ đồng xu với trọng lượng chưa biết nhưng có thứ tự nghiêm ngặt (đồng $i$ nặng hơn đồng $i-1$). Mỗi bước đặt một đồng vào một trong hai chồng, không bao giờ lấy ra. Sau mỗi lần đặt, thông báo chồng chắc chắn nặng hơn (`>` trái, `<` phải), hoặc `?` khi không ép buộc người thắng.

## Đầu vào
Số nguyên $n$, rồi $n$ dòng mỗi dòng có đồng $c$ và chồng $s$ ($1$ trái, $2$ phải).

## Kết quả
Sau mỗi bước in ra `>`, `<`, hoặc `?`.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
