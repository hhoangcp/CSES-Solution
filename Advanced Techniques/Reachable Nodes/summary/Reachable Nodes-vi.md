# Reachable Nodes

**CSES ID:** 2138  
**Đề bài gốc:** https://cses.fi/problemset/task/2138  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Đồ thị có hướng không chu trình có $n$ đỉnh và $m$ cạnh. Với mỗi đỉnh, tính số đỉnh có thể đến được từ nó theo các cạnh có hướng (tính cả chính nó).

## Đầu vào
Dòng đầu: $n,m$. Sau đó $m$ dòng, mỗi dòng hai số nguyên phân biệt $a,b$ (cạnh $a\to b$).

## Kết quả
In $n$ số nguyên, số đỉnh đến được của từng đỉnh theo thứ tự.

## Ràng buộc
- $1 \le n \le 5 \cdot 10^4$
- $1 \le m \le 10^5$
