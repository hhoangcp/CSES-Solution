# Eulerian Subgraphs

**CSES ID:** 2078  
**Đề bài gốc:** https://cses.fi/problemset/task/2078  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho đồ thị vô hướng có $n$ đỉnh và $m$ cạnh, đếm (lấy modulo $10^9+7$) số tập con cạnh mà đồ thị con sinh ra (giữ nguyên toàn bộ đỉnh) có bậc chẵn tại mọi đỉnh. Đó là các đồ thị con Euler.

## Đầu vào
Dòng đầu: $n,m$. Sau đó $m$ dòng, mỗi dòng hai số nguyên $a,b$ (một cạnh). Mỗi cặp nhiều nhất một cạnh, không có khuyên.

## Kết quả
In số đồ thị con Euler lấy modulo $10^9+7$.

## Ràng buộc
- $1 \le n \le 10^5$
- $0 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
