# Graph Paths I

**CSES ID:** 1723  
**Đề bài gốc:** https://cses.fi/problemset/task/1723  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho đồ thị có hướng $n$ đỉnh, $m$ cạnh, đếm số đường đi đúng $k$ cạnh từ đỉnh 1 đến đỉnh $n$. Kết quả modulo $10^9+7$.

## Đầu vào
Dòng đầu chứa $n$, $m$, $k$. $m$ dòng tiếp theo mỗi dòng mô tả cạnh $a \to b$.

## Kết quả
In số đường đi độ dài $k$ từ 1 đến $n$ modulo $10^9+7$.

## Ràng buộc
- $1 \le n \le 100$
- $1 \le m \le n(n-1)$
- $1 \le k \le 10^9$
- $1 \le a,b \le n$
