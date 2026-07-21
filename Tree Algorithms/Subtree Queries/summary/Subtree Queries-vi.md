# Subtree Queries

**CSES ID:** 1137  
**Đề bài gốc:** https://cses.fi/problemset/task/1137  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một cây có gốc, mỗi đỉnh có một giá trị. Truy vấn hoặc cập nhật giá trị một đỉnh, hoặc hỏi tổng giá trị trong cây con của một đỉnh.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng tiếp theo là giá trị các đỉnh. Sau đó $n-1$ cạnh. Cuối cùng $q$ truy vấn dạng "1 $s$ $x$" (cập nhật) hoặc "2 $s$" (tổng cây con).

## Kết quả
In ra kết quả cho mỗi truy vấn loại 2.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a,b, s \le n$
- $1 \le v_i, x \le 10^9$
