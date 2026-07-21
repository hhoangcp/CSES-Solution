# Graph Paths II

**CSES ID:** 1724  
**Đề bài gốc:** https://cses.fi/problemset/task/1724  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho đồ thị có hướng có trọng số, tìm độ dài nhỏ nhất của đường đi từ đỉnh 1 đến đỉnh $n$ dùng đúng $k$ cạnh. In $-1$ nếu không tồn tại.

## Đầu vào
Dòng đầu chứa $n$, $m$, $k$. $m$ dòng tiếp theo cho cạnh $a \to b$ với trọng số $c$.

## Kết quả
In độ dài đường đi nhỏ nhất, hoặc $-1$ nếu không có.

## Ràng buộc
- $1 \le n \le 100$
- $1 \le m \le n(n-1)$
- $1 \le k \le 10^9$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
