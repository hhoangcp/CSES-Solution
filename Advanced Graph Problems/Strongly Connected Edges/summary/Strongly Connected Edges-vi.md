# Strongly Connected Edges

**CSES ID:** 2177  
**Đề bài gốc:** https://cses.fi/problemset/task/2177  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Định hướng mỗi cạnh của một đồ thị vô hướng đơn sao cho đồ thị có hướng thu được liên thông mạnh.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng một cạnh vô hướng giữa hai đỉnh phân biệt $a,b$; đồ thị là đơn.

## Kết quả
In ra $m$ dòng cho hướng mỗi cạnh $a \to b$; nếu không khả thi, chỉ in `IMPOSSIBLE`.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
