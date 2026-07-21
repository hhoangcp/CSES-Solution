# Point Location Test

**CSES ID:** 2189  
**Đề bài gốc:** https://cses.fi/problemset/task/2189  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Với mỗi trong $t$ test, cho đường thẳng định hướng đi qua $p_1$ và $p_2$ cùng điểm truy vấn $p_3$. Phân loại $p_3$ nằm bên trái, bên phải hay đúng trên đường thẳng khi nhìn từ $p_1$ về $p_2$.

## Đầu vào
Dòng đầu là số nguyên $t$, sau đó $t$ dòng mỗi dòng sáu số nguyên $x_1, y_1, x_2, y_2, x_3, y_3$.

## Kết quả
Với mỗi test in ra "LEFT", "RIGHT" hoặc "TOUCH".

## Ràng buộc
- $1 \le t \le 10^5$
- $-10^9 \le x_1, y_1, x_2, y_2, x_3, y_3 \le 10^9$
- $x_1 \neq x_2$ hoặc $y_1 \neq y_2$
