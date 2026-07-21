# Acyclic Graph Edges

**CSES ID:** 1756  
**Đề bài gốc:** https://cses.fi/problemset/task/1756  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một đồ thị vô hướng, cần định hướng cho mọi cạnh sao cho đồ thị có hướng thu được không chứa chu trình có hướng.

## Đầu vào
Dòng đầu: $n$ và $m$ (số đỉnh, số cạnh). Sau đó $m$ dòng, mỗi dòng hai chỉ số đỉnh phân biệt $a,b$ mô tả một cạnh vô hướng.

## Kết quả
In ra $m$ dòng, mỗi dòng cho hướng chọn $ab$ (cạnh từ $a$ đến $b$); bất kỳ hướng không chu trình nào đều được chấp nhận.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
