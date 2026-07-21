# Critical Cities

**CSES ID:** 1703  
**Đề bài gốc:** https://cses.fi/problemset/task/1703  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho đồ thị có hướng gồm $n$ thành phố và $m$ chuyến bay một chiều, một thành phố là thiết yếu nếu nó nằm trên mọi đường đi từ Syrjälä (thành phố 1) đến Lehmälä (thành phố $n$). Liệt kê các thành phố đó theo thứ tự tăng dần.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng một chuyến bay một chiều $a \to b$. Đảm bảo có đường đi từ 1 đến $n$.

## Kết quả
In ra số lượng $k$ rồi đến $k$ thành phố thiết yếu theo thứ tự tăng dần.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
