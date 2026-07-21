# Path Queries

**CSES ID:** 1138  
**Đề bài gốc:** https://cses.fi/problemset/task/1138  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một cây có gốc, mỗi đỉnh có một giá trị. Hỗ trợ hai loại truy vấn: cập nhật giá trị một đỉnh, và hỏi tổng giá trị trên đường đi từ gốc đến đỉnh.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng tiếp theo là giá trị các đỉnh. Sau đó $n-1$ cạnh. Cuối cùng $q$ truy vấn dạng "1 $s$ $x$" (cập nhật) hoặc "2 $s$" (tổng đường đi từ gốc).

## Kết quả
In ra kết quả cho mỗi truy vấn loại 2.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a,b, s \le n$
- $1 \le v_i, x \le 10^9$
