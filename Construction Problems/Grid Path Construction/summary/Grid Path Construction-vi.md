# Grid Path Construction

**CSES ID:** 2418  
**Đề bài gốc:** https://cses.fi/problemset/task/2418  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho lưới $n \times m$ và hai ô khác nhau $a=(y_1,x_1)$, $b=(y_2,x_2)$, xác định có tồn tại đường đi từ $a$ đến $b$ đi qua mọi ô đúng một lần (chỉ di chuyển giữa các ô kề nhau) hay không. Nếu có, xuất đường đi dưới dạng chuỗi các bước `U`/`D`/`L`/`R`.

## Đầu vào
Dòng đầu: số nguyên $t$. Sau đó $t$ dòng, mỗi dòng chứa sáu số nguyên $n$, $m$, $y_1$, $x_1$, $y_2$, $x_2$.

## Kết quả
Với mỗi test, in `YES` kèm chuỗi bước đi nếu có đường đi, ngược lại in `NO`.

## Ràng buộc
- $1 \le t \le 100$
- $1 \le n \le 50$
- $1 \le m \le 50$
- $y_1 \neq y_2$ hoặc $x_1 \neq x_2$
