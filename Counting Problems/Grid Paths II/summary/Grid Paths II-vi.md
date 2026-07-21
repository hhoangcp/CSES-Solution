# Grid Paths II

**CSES ID:** 1078  
**Đề bài gốc:** https://cses.fi/problemset/task/1078  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Từ ô trên cùng bên trái $(1,1)$ của lưới $n \times n$, di chuyển đến ô dưới cùng bên phải $(n,n)$ chỉ bằng bước sang phải hoặc xuống dưới. Có $m$ ô bẫy không được đi vào (ô đầu và ô cuối không bao giờ là bẫy). Hãy đếm số đường đi hợp lệ modulo $10^9+7$.

## Đầu vào
Dòng đầu chứa $n$ và $m$. Tiếp theo là $m$ dòng, mỗi dòng hai số nguyên $y$ và $x$ cho hàng và cột của một bẫy.

## Kết quả
In số đường đi hợp lệ modulo $10^9+7$.

## Ràng buộc
- $1 \le n \le 10^6$
- $1 \le m \le 1000$
- $1 \le y,x \le n$
