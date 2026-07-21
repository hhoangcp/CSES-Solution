# Path Queries II

**CSES ID:** 2134  
**Đề bài gốc:** https://cses.fi/problemset/task/2134  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Mỗi đỉnh của cây mang một giá trị. Truy vấn hoặc gán giá trị mới cho một đỉnh, hoặc hỏi giá trị lớn nhất trên đường đi giữa hai đỉnh.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng tiếp theo là giá trị các đỉnh. Sau đó $n-1$ cạnh. Cuối cùng $q$ truy vấn dạng "1 $s$ $x$" (cập nhật) hoặc "2 $a$ $b$" (giá trị lớn nhất trên đường đi).

## Kết quả
In ra kết quả cho mỗi truy vấn loại 2.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a,b, s \le n$
- $1 \le v_i, x \le 10^9$
